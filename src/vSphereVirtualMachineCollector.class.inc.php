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
    static protected $oPowerStateMappings = null;

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
            if ($sAttCode == 'power_state') return false;
		} else {
			if ($sAttCode == 'uuid') return true;
            if ($sAttCode == 'power_state') return true;
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
			// The association MACAddress <=> Network is known at the HW level (correspondance between the VirtualINC and its "backing" device)
			foreach ($oVirtualMachine->config->hardware->device as $oVirtualDevice) {
                if ($oVirtualDevice === null) continue;

				utils::Log(LOG_DEBUG, "Start collect for VM ".get_class($oVirtualDevice)."...");
				switch (get_class($oVirtualDevice)) {
					case 'VirtualE1000':
					case 'VirtualE1000e':
					case 'VirtualPCNet32':
					case 'VirtualVmxnet':
					case 'VirtualVmxnet2':
					case 'VirtualVmxnet3':
						if (isset($oVirtualDevice->backing)) {
							$oBacking = $oVirtualDevice->backing;
							$sNetworkName = '';
							if (isset($oBacking->network) && property_exists($oBacking, 'network') && isset($oBacking->network->name)) {
								$sNetworkName = $oBacking->network->name;
								utils::Log(LOG_DEBUG, "Virtual Network Device: Using ->network->name: '$sNetworkName'");
							} else {
								if (isset($oBacking->opaqueNetworkId) && property_exists($oBacking, 'opaqueNetworkId')) {
									$sNetworkName = $oBacking->opaqueNetworkId;
									utils::Log(LOG_DEBUG, "Virtual Network Device: Using ->opaqueNetworkId: '$sNetworkName'");
								} else {
									if (isset($oBacking->deviceName) && property_exists($oBacking, 'deviceName')) {
										$sNetworkName = $oBacking->deviceName;
										utils::Log(LOG_DEBUG, "Virtual Network Device: Using ->deviceName: '$sNetworkName'");
									} else {
										if (isset($oBacking->port) && property_exists($oBacking, 'port')) {
											$oPort = $oBacking->port;
											utils::Log(LOG_DEBUG, "Virtual Network Device '".get_class($oBacking)."': has the following port (".get_class($oPort)."):\n".static::myprint_r($oPort));
											if (array_key_exists($oPort->portgroupKey, $aVLANs)) {
												$sNetworkName = $aVLANs[$oPort->portgroupKey];
											} else {
												utils::Log(LOG_WARNING, "No VirtualPortGroup(key) found for the Virtual Network Device '".get_class($oBacking)."' with the following port (".get_class($oPort)."):\n".static::myprint_r($oPort));
											}
										} else {
											utils::Log(LOG_DEBUG, "Virtual Network Device '".get_class($oBacking)."': has neither 'network', nor 'opaqueNetworkId', nor 'port'. Dumping the whole object:\n".static::myprint_r($oBacking));
										}
									}
								}
							}
						} else {
							utils::Log(LOG_DEBUG, "Skip virtual device of class ".get_class($oVirtualDevice)." as we don't have access to its \"backing\" informations.");
						}

						if (isset($oVirtualDevice->macAddress)) {
							Utils::Log(LOG_DEBUG, "MACAddress: {$oVirtualDevice->macAddress} is connected to the network: '$sNetworkName'");
							$aMACToNetwork[$oVirtualDevice->macAddress] = $sNetworkName;
						}
						break;

					default:
						// Other types of Virtual Devices, skip
				}
				utils::Log(LOG_DEBUG, "End of collect for VM ".get_class($oVirtualDevice).".");
			}

			Utils::Log(LOG_DEBUG, "Collecting IP addresses for this VM...");
			$aNWInterfaces = static::DoCollectVMIPs($aMACToNetwork, $oVirtualMachine);
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

            $aData['power_state'] = static::GetPowerState($oVirtualMachine);

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
						);
					}
				}
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
     * Helper method to extract the power state of the VirtualMachine object
     * according to the 'vm_power_state_mapping' mapping taken from the configuration
     *
     * @param VirtualMachine $oVirtualMachine
     *
     * @return string The mapped power state
     */
    static public function GetPowerState($oVirtualMachine)
    {
        if (self::$oPowerStateMappings === null) {
            self::$oPowerStateMappings = new MappingTable('vm_power_state_mapping');
        }
        utils::Log(LOG_DEBUG, "Reading power_state...");
        $sRawValue = $oVirtualMachine->runtime->powerState;
        $value = self::$oPowerStateMappings->MapValue($sRawValue); // Keep the raw value by default
        utils::Log(LOG_DEBUG, "    Power state: $value");

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
            $aData['power_state'] = $aVM['power_state'];
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
			$this->oIPAddressLookup->Lookup($aLineData, array('org_id', 'managementip_id'), 'managementip_id', $iLineIndex);
		}
	}
}
