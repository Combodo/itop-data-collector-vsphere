<?php
require_once(APPROOT.'collectors/src/vSphereCollector.class.inc.php');

class vSphereVirtualMachineCollector extends vSphereCollector
{
	protected $idx;
	protected $oOSVersionLookup;
	protected $oIPAddressLookup;
	static protected $oOSFamilyMappings = null;
	static protected bool $bVMInfosCollected = false;
	static protected array $aVMInfos = [];
	static protected $oOSVersionMappings = null;
	static protected array $aLnkDatastoreToVM;

	/**
	 * @inheritdoc
	 */
	public function Init(): void
	{
		parent::Init();

		self::$aLnkDatastoreToVM = [];
	}

	/**
	 * @inheritdoc
	 */
	public function AttributeIsOptional($sAttCode)
	{
		if ($sAttCode == 'services_list') return true;
		if ($sAttCode == 'providercontracts_list') return true;
		if ($this->oCollectionPlan->IsCbdVMwareDMInstalled()) {
			if ($sAttCode == 'uuid') return false;
		} else {
			if ($sAttCode == 'uuid') return true;
		}

		if ($this->oCollectionPlan->IsTeemIpInstalled()) {
			if ($sAttCode == 'managementip') return true;
			if ($sAttCode == 'managementip_id') return false;
		} else {
			if ($sAttCode == 'managementip') return false;
			if ($sAttCode == 'managementip_id') return true;
		}

		return parent::AttributeIsOptional($sAttCode);
	}

	/**
	 * Helper method to perform the actual collection of VMs and their related information (OSFamily, OSVersion...)
	 * and store the result in a static variable for further processing by the different collectors
	 */
	static public function CollectVMInfos()
	{
		if (!static::$bVMInfosCollected) {
			static::$bVMInfosCollected = true;
			require_once APPROOT.'collectors/library/Vmwarephp/Autoloader.php';
			$autoloader = new \Vmwarephp\Autoloader;
			$autoloader->register();

			$sVSphereServer = Utils::GetConfigurationValue('vsphere_uri', '');
			$sLogin = Utils::GetConfigurationValue('vsphere_login', '');
			$sPassword = Utils::GetConfigurationValue('vsphere_password', '');

			if (class_exists('vSphereFarmCollector')) {
				$aFarms = vSphereFarmCollector::GetFarms();
			} else {
				$aFarms = [];
			}

			$vhost = new \Vmwarephp\Vhost($sVSphereServer, $sLogin, $sPassword);

			Utils::Log(LOG_DEBUG, "vSphere API type: ".$vhost->getApiType().", version: ".$vhost->getApiVersion());

			$aVLANs = array();
			$aDVSwitches = $vhost->findAllManagedObjects('DistributedVirtualSwitch', array('portgroup', 'summary'));
			if (count($aDVSwitches) == 0) {
				utils::Log(LOG_DEBUG, "No DVSwitch found in this vSphere instance.");
			} else {
				foreach ($aDVSwitches as $oSwitch) {
					utils::Log(LOG_DEBUG, "DVSwitch: {$oSwitch->summary->name}, UUID: {$oSwitch->uuid}");
					if (count($oSwitch->portgroup) == 0) {
						utils::Log(LOG_DEBUG, "No DVPortgroup found on this DVSwitch.");
					}
					foreach ($oSwitch->portgroup as $oPortGroup) {
						$aVLANs[$oPortGroup->key] = $oPortGroup->name;
						utils::Log(LOG_DEBUG, "Portgroup: {$oPortGroup->name}, config:\n".static::myprint_r($oPortGroup->config));
					}
				}
			}

			$aVirtualMachines = $vhost->findAllManagedObjects('VirtualMachine', array('config', 'runtime', 'guest', 'network', 'storage'));

			$idx = 1;
			foreach ($aVirtualMachines as $oVirtualMachine) {
				utils::Log(LOG_DEBUG, ">>>>>> Starting collection of the VM '".$oVirtualMachine->name."' (VM #$idx)");
				$aVM = static::DoCollectVMInfo($aFarms, $oVirtualMachine, $aVLANs, $idx);
				if ($aVM !== null) {
					static::$aVMInfos[] = $aVM;
				}
				utils::Log(LOG_DEBUG, "<<<<<< End of collection of the VM #$idx");
				$idx++;
			}
		}
		utils::Log(LOG_DEBUG, "End of collection of VMs information.");

		return static::$aVMInfos;
	}

	static protected function DoCollectVMInfo($aFarms, $oVirtualMachine, $aVLANs, $idx)
	{
		utils::Log(LOG_DEBUG, "Runtime->connectionState: ".$oVirtualMachine->runtime->connectionState);
		utils::Log(LOG_DEBUG, "Runtime->powerState: ".$oVirtualMachine->runtime->powerState);
		if ($oVirtualMachine->runtime->connectionState != 'connected') {
			utils::Log(LOG_INFO, "Cannot retrieve information from VM ".$oVirtualMachine->name." (VM#$idx) (runtime->connectionState='".$oVirtualMachine->runtime->connectionState."'), skipping.");

			return null;
		}

		$sDefaultOrg = Utils::GetConfigurationValue('default_org_id');
		$aVMParams = Utils::GetConfigurationValue('virtual_machine', []);
		$sVirtualHostType = 'farm';
		if (array_key_exists('virtual_host', $aVMParams) && $aVMParams['virtual_host'] != '') {
			$sVirtualHostType = $aVMParams['virtual_host'];
		}
		$OSFamily = static::GetOSFamily($oVirtualMachine);
		$OSVersion = static::GetOSVersion($oVirtualMachine);

		utils::Log(LOG_DEBUG, "Collecting network info...");
		$aNWInterfaces = array();
		// Make sure user has access to network information
		if (isset($oVirtualMachine->guest->net)) {
			$aMACToNetwork = array();
			// Very very light new code to get the network interfaces
			$iVirtualInterface = 0;
			foreach($oVirtualMachine->guest->net as $oNICInfo) {
				Utils::Log(LOG_DEBUG, "Searching interface $iVirtualInterface...");
				// Utils::Log(LOG_DEBUG, "oNICInfo: ".print_r($oNICInfo, true));
				// check if the network is set and not empty, set the networkName to '-Internal' if not set
				$sNetworkName = (isset($oNICInfo->network) && $oNICInfo->network != '') ? $oNICInfo->network : '-Internal';
				Utils::Log(LOG_DEBUG, "oNICInfo->deviceConfigId: ".$oNICInfo->deviceConfigId);
				Utils::Log(LOG_DEBUG, "oNICInfo->macAddress: ".$oNICInfo->macAddress);
				Utils::Log(LOG_DEBUG, "oNICInfo->network: ".$sNetworkName);
				// If possible, deduct the interface number from the deviceConfigId :
				// Interface number is deviceConfigId - 4000
				// If deviceConfigId is not numeric, or less than 4000, we use iVirtualInterface
				$iInterfaceNumber = (is_numeric($oNICInfo->deviceConfigId) && $oNICInfo->deviceConfigId >= 4000) ? $oNICInfo->deviceConfigId - 4000 : $iVirtualInterface;
				// Personal Add (Schirrms): Sometimes, a VM can have more than one interfaces linked to the same network
				// hence the addition of the VMware interface number after the network name
				// This is probably a breaking change if used on older collections
				$aMACToNetwork[$oNICInfo->macAddress] = $sNetworkName . '-[' . $iInterfaceNumber . ']';
				$iVirtualInterface++;
			}

			Utils::Log(LOG_DEBUG, "Collecting IP addresses for this VM...");
			$aNWInterfaces = static::DoCollectVMIPs($aMACToNetwork, $oVirtualMachine);
			utils::Log(LOG_DEBUG, "Collected ".count($aNWInterfaces)." network interfaces for this VM.");
			// utils::Log(LOG_DEBUG, "Network interfaces: ".print_r($aNWInterfaces, true));
		} else {
			utils::Log(LOG_DEBUG, "User cannot access to network information of VM ".$oVirtualMachine->name.", skipping.");
		}

		$aDisks = array();
		utils::Log(LOG_DEBUG, "Collecting disk info...");
		if ($oVirtualMachine->guest->disk) {
			foreach ($oVirtualMachine->guest->disk as $oDiskInfo) {
				$aDisks[] = array(
					'path' => $oDiskInfo->diskPath,
					'capacity' => $oDiskInfo->capacity,
					'used' => $oDiskInfo->capacity - $oDiskInfo->freeSpace,
				);
			}
		}

		utils::Log(LOG_DEBUG, "Building VM record...");

		utils::Log(LOG_DEBUG, "Reading Name...");
		$sName = $oVirtualMachine->name;
		utils::Log(LOG_DEBUG, "    Name: $sName");

		utils::Log(LOG_DEBUG, "Reading Number of CPUs...");
		$iNbCPUs = $oVirtualMachine->config->hardware->numCPU;
		utils::Log(LOG_DEBUG, "    CPUs: $iNbCPUs");

		utils::Log(LOG_DEBUG, "Reading Memory...");
		$iMemory = $oVirtualMachine->config->hardware->memoryMB;
		utils::Log(LOG_DEBUG, "    Memory: $iMemory");

		utils::Log(LOG_DEBUG, "Reading Annotation...");
		$sAnnotation = $oVirtualMachine->config->annotation;
		utils::Log(LOG_DEBUG, "    Annotation: $sAnnotation");

		utils::Log(LOG_DEBUG, "Reading management IP (guest->ipAddress)...");
		$sGuestIP = $oVirtualMachine->guest->ipAddress ?? '';
		utils::Log(LOG_DEBUG, "    Management IP: $sGuestIP");

		utils::Log(LOG_DEBUG, "Reading host name...");
		$sHostName = $oVirtualMachine->runtime->host->name;
		utils::Log(LOG_DEBUG, "    Host name: $sHostName");

		if ($sVirtualHostType == 'hypervisor') {
			$sVirtualHost = $sHostName;
		} else {
			// Get the farm that the hypervisor, on which this VM is running, is part of, if any
			utils::Log(LOG_DEBUG, "Checking if the host is part of a Farm...");
			$sFarmName = '';
			foreach($aFarms as $aFarm)
			{
				if (in_array($oVirtualMachine->runtime->host->name, $aFarm['hosts']))
				{
					$sFarmName = $aFarm['name'];
					break; // Farm found
				}
			}
			$sVirtualHost = empty($sFarmName) ? $sHostName : $sFarmName;
		}

		$aData = array(
			'id' => $oVirtualMachine->getReferenceId(),
			'name' => $sName,
			'org_id' => $sDefaultOrg,
			'cpu' => $iNbCPUs,
			'ram' => $iMemory,
			'osfamily_id' => $OSFamily,
			'osversion_id' => $OSVersion,
			'disks' => $aDisks,
			'interfaces' => $aNWInterfaces,
			'virtualhost_id' => $sVirtualHost,
			'description' => $sAnnotation,
		);

		$oCollectionPlan = vSphereCollectionPlan::GetPlan();
		if ($oCollectionPlan->IsCbdVMwareDMInstalled()) {
			utils::Log(LOG_DEBUG, "Reading uuid...");
			$sUUID = $oVirtualMachine->config->uuid;
			utils::Log(LOG_DEBUG, "    UUID: $sUUID");

			$aData['uuid'] = $sUUID;

			utils::Log(LOG_DEBUG, "Reading datastores...");
			$aPerDatastoreUsage = $oVirtualMachine->storage->perDatastoreUsage;
			foreach ($aPerDatastoreUsage as $aDatastoreUsage) {
				self::$aLnkDatastoreToVM[] = [
					'datastore_id' => $aDatastoreUsage->datastore->getReferenceId(),
					'virtualmachine_id' => $sUUID
				];
			}

		}

		if ($oCollectionPlan->IsTeemIpInstalled()) {
			$aTeemIpOptions = Utils::GetConfigurationValue('teemip_discovery', array());
			$bCollectIps = ($aTeemIpOptions['collect_ips'] == 'yes') ? true : false;
			$bCollectIPv6Addresses = ($aTeemIpOptions['manage_ipv6'] == 'yes') ? true : false;

			utils::Log(LOG_DEBUG, "Reading DNS short name (guest->hostName)...");
			$sGuestShortName = $oVirtualMachine->guest->hostName;
			utils::Log(LOG_DEBUG, "    DNS short name: $sGuestShortName");

			// Trim IP address if necessary
			$sGuestIP = $oVirtualMachine->guest->ipAddress ?? '';
			// Trim IP address if necessary
			if (!$bCollectIps) {
				$sGuestIP = '';
			} else {
				if (!$bCollectIPv6Addresses) {
					$sGuestIP = filter_var($sGuestIP, FILTER_VALIDATE_IP, FILTER_FLAG_IPV4) ?: '';
				}
			}

			$aData['managementip_id'] = $sGuestIP;
			utils::Log(LOG_DEBUG, "Setting managementip_id: ".$sGuestIP);
			$aData['short_name'] = $sGuestShortName;
		} else {
			// ManagementIP cannot be an IPV6 address, if no IPV4 was found above, let's clear the field
			// Note: some OpenVM clients report IP addresses with a trailing space, so let's trim the field
			$aData['managementip'] = filter_var(trim($sGuestIP), FILTER_VALIDATE_IP, FILTER_FLAG_IPV4) ?: '';
		}

		return $aData;

	}

	static protected function DoCollectVMIPs($aMACToNetwork, $oVirtualMachine)
	{
		$aTeemIpOptions = Utils::GetConfigurationValue('teemip_discovery', array());
		$bCollectIPv6Addresses = ($aTeemIpOptions['manage_ipv6'] == 'yes') ? true : false;
		$oCollectionPlan = vSphereCollectionPlan::GetPlan();
		$aNWInterfaces = array();

		foreach ($oVirtualMachine->guest->net as $oNICInfo) {
			if ($oNICInfo->ipConfig && $oNICInfo->ipConfig->ipAddress) {
				foreach ($oNICInfo->ipConfig->ipAddress as $oIPInfo) {
					Utils::Log(LOG_DEBUG, "Reading VM's IP and MAC address");
					if (filter_var($oIPInfo->ipAddress ?? '', FILTER_VALIDATE_IP, FILTER_FLAG_IPV6)) {
						// It's an IPv6 address
						if ($oCollectionPlan->IsTeemIpInstalled() && $bCollectIPv6Addresses) {
							$aNWInterfaces[] = array(
								'ip' => $oIPInfo->ipAddress,
								'mac' => $oNICInfo->macAddress,
								'network' => array_key_exists($oNICInfo->macAddress, $aMACToNetwork) ? $aMACToNetwork[$oNICInfo->macAddress] : '',
								'subnet_mask' => (int)$oIPInfo->prefixLength,
								'id' => $oNICInfo->deviceConfigId,
							);
						} else {
							Utils::Log(LOG_DEBUG, "Ignoring an IP v6 address");
						}
					} else {
						// If we have a guest IP set to IPv6, replace it with the first IPv4 we find
						if (filter_var($oVirtualMachine->guest->ipAddress ?? '', FILTER_VALIDATE_IP, FILTER_FLAG_IPV6)) {
							$oVirtualMachine->guest->ipAddress = $oIPInfo->ipAddress;
						}

						Utils::Log(LOG_DEBUG, "Reading VM's IP and MAC address");
						$mask = ip2long('255.255.255.255');
						$subnet_mask = ($mask << (32 - (int) $oIPInfo->prefixLength)) & $mask;
						$sSubnetMask = long2ip($subnet_mask);
						// IP v4
						$aNWInterfaces[] = array(
							'ip' => trim($oIPInfo->ipAddress ?? ''), // Some OpenVM clients report IP addresses with a trailing space, let's trim it
							'mac' => $oNICInfo->macAddress,
							'network' => array_key_exists($oNICInfo->macAddress, $aMACToNetwork) ? $aMACToNetwork[$oNICInfo->macAddress] : '',
							'subnet_mask' => $sSubnetMask,
							'id' => $oNICInfo->deviceConfigId,
						);
					}
				}
			}

			// Seems useful to set also the informations for interfaces without an IP address
			else {
				Utils::Log(LOG_DEBUG, "No IP address found for interface ".$oNICInfo->macAddress." on network ".(array_key_exists($oNICInfo->macAddress, $aMACToNetwork) ? $aMACToNetwork[$oNICInfo->macAddress] : ''));
				$aNWInterfaces[] = array(
					'ip' => '',
					'mac' => $oNICInfo->macAddress,
					'subnet_mask' => '',
					'network' => array_key_exists($oNICInfo->macAddress, $aMACToNetwork) ? $aMACToNetwork[$oNICInfo->macAddress] : '',
					'id' => $oNICInfo->deviceConfigId,
				);
			}
		}

		return $aNWInterfaces;
	}

	/**
	 * Helper method to extract the OSFamily information from the VirtualMachine object
	 * according to the 'os_family_mapping' mapping taken from the configuration
	 *
	 * @param VirtualMachine $oVirtualMachine
	 *
	 * @return string The mapped OS Family or an empty string if nothing matches the extraction rules
	 */
	static public function GetOSFamily($oVirtualMachine)
	{
		if (self::$oOSFamilyMappings === null) {
			self::$oOSFamilyMappings = new MappingTable('os_family_mapping');
		}
		// Read the "real time" name. Take the one defined by config if it is not available.
		$sRawValue = $oVirtualMachine->guest->guestFullName;
		if (is_null($sRawValue)) {
			$sRawValue = $oVirtualMachine->config->guestFullName;
		}
		$value = self::$oOSFamilyMappings->MapValue($sRawValue, '');

		return $value;
	}

	/**
	 * Helper method to extract the Version information from the VirtualMachine object
	 * according to the 'os_version_mapping' mapping taken from the configuration
	 *
	 * @param VirtualMachine $oVirtualMachine
	 *
	 * @return string The mapped OS Version or the original value if nothing matches the extraction rules
	 */
	static public function GetOSVersion($oVirtualMachine)
	{
		if (self::$oOSVersionMappings === null) {
			self::$oOSVersionMappings = new MappingTable('os_version_mapping');
		}
		// Read the "real time" name. Take the one defined by config if it is not available.
		$sRawValue = $oVirtualMachine->guest->guestFullName;
		if (is_null($sRawValue)) {
			$sRawValue = $oVirtualMachine->config->guestFullName;
		}
		$value = self::$oOSVersionMappings->MapValue($sRawValue, $sRawValue); // Keep the raw value by default

		return $value;
	}

	/**
	 * Get the datastores attached to the VMs
	 *
	 * @return array
	 */
	static public function GetDatastoreLnks()
	{
		return self::$aLnkDatastoreToVM;
	}

	/**
	 * @inheritdoc
	 */
	public function Prepare()
	{
		$bRet = parent::Prepare();
		if (!$bRet) {
			return false;
		}

		static::CollectVMInfos();

		$this->idx = 0;

		return true;
	}

	/**
	 * @inheritdoc
	 */
	public function Fetch()
	{
		if ($this->idx < count(static::$aVMInfos)) {
			$aVM = static::$aVMInfos[$this->idx++];

			return $this->DoFetch($aVM);
		}

		return false;
	}

	protected function DoFetch($aVM)
	{
		$aData = array(
			'primary_key' => $aVM['id'],
			'name' => $aVM['name'],
			'status' => 'production',
			'org_id' => $aVM['org_id'],
			'ram' => $aVM['ram'],
			'cpu' => ((int)$aVM['cpu']),
			'osfamily_id' => $aVM['osfamily_id'],
			//'logicalvolumes_list' => implode('|', $aDS),
			'osversion_id' => $aVM['osversion_id'],
			'virtualhost_id' => $aVM['virtualhost_id'],
			'description' => str_replace(array("\n", "\r"), ' ', $aVM['description']),
		);

		if ($this->oCollectionPlan->IsCbdVMwareDMInstalled()) {
			$aData['uuid'] = $aVM['uuid'];
		}

		if ($this->oCollectionPlan->IsTeemIpInstalled()) {
			$aData['managementip_id'] = $aVM['managementip_id'];
		} else {
			$aData['managementip'] = $aVM['managementip'];
		}

		return $aData;
	}

	/**
	 * @inheritdoc
	 */
	protected function MustProcessBeforeSynchro()
	{
		// We must reprocess the CSV data obtained from vSphere
		// to lookup the OSFamily/OSVersion in iTop
		return true;
	}

	/**
	 * @inheritdoc
	 */
	protected function InitProcessBeforeSynchro()
	{
		// Retrieve the identifiers of the OSVersion since we must do a lookup based on two fields: Family + Version
		// which is not supported by the iTop Data Synchro... so let's do the job of an ETL
		$this->oOSVersionLookup = new LookupTable('SELECT OSVersion', array('osfamily_id_friendlyname', 'name'));

		if ($this->oCollectionPlan->IsTeemIpInstalled()) {
			$this->oIPAddressLookup = new LookupTable('SELECT IPAddress', array('org_name', 'friendlyname'));
		}
	}

	/**
	 * @inheritdoc
	 */
	protected function ProcessLineBeforeSynchro(&$aLineData, $iLineIndex)
	{
		// Process each line of the CSV
		$this->oOSVersionLookup->Lookup($aLineData, array('osfamily_id', 'osversion_id'), 'osversion_id', $iLineIndex);
		if ($this->oCollectionPlan->IsTeemIpInstalled()) {
			// Empty IP address should not produce a Warning nor an attempt to lookup
			// To be fair, this should be a choice in the configuration file, but I'm too lazy to do it now (Schirrms 2025-03-04)
			// Original line (send this kind of messages): [Warning] No mapping found with key: '{ORG_NAME}_', 'managementip_id' will be set to zero.
			$this->oIPAddressLookup->Lookup($aLineData, array('org_id', 'managementip_id'), 'managementip_id', $iLineIndex, true);
		}
	}
}
