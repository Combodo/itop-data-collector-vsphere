<?php
// Copyright (C) 2014-2018 Combodo SARL
//
//   This application is free software; you can redistribute it and/or modify	
//   it under the terms of the GNU Affero General Public License as published by
//   the Free Software Foundation, either version 3 of the License, or
//   (at your option) any later version.
//
//   iTop is distributed in the hope that it will be useful,
//   but WITHOUT ANY WARRANTY; without even the implied warranty of
//   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//   GNU Affero General Public License for more details.
//
//   You should have received a copy of the GNU Affero General Public License
//   along with this application. If not, see <http://www.gnu.org/licenses/>
function myprint_r($var)
{
	$s = '';
	foreach($var as $key => $val)
	{
		if (is_object($val))
		{
			$sVal = 'object['.get_class($val).']';
		}
		else
		{
			$sVal = $val;
		}
		$s .= "\t".$key." => ".$sVal."\n";
	}
	return $s;
}
class vSphereVirtualMachineCollector extends Collector
{
	protected $idx;
	/**
	 * @var LookupTable For the OS Family / OS Version lookup
	 */
	protected $oOSVersionLookup;
	
	/**
	 * @var mixed[][] The collected VM infos
	 */
	static protected $aVMInfos = null;
	
	/**
	 * @var MappingTable Mapping table for the OS Families
	 */
	static protected $oOSFamilyMappings = null;
	
	/**
	 * @var MappingTable Mapping table for OS versions
	 */
	static protected $oOSVersionMappings = null;
	
	public function AttributeIsOptional($sAttCode)
	{
		// If the module Service Management for Service Providers is selected during the setup
		// there is no "services_list" attribute on VirtualMachines. Let's safely ignore it.
		if ($sAttCode == 'services_list') return true;

		// If the collector is connected to TeemIp standalone, there is no "providercontracts_list"
		// on VirtualMachines. Let's safely ignore it.
		if ($sAttCode == 'providercontracts_list') return true;

		return parent::AttributeIsOptional($sAttCode);
	}

	public static function GetVMs()
	{
		if (static::$aVMInfos === null)
		{
			static::CollectVMInfos();
		}
		return static::$aVMInfos;
	}

	/**
	 * Helper method to perform the actual collection of VMs and their related information (OSFamily, OSVersion...)
	 * and store the result in a static variable for further processing by the different collectors
	 */
	static public function CollectVMInfos()
	{
		if (self::$aVMInfos === null)
		{
			require_once APPROOT.'collectors/library/Vmwarephp/Autoloader.php';
			$autoloader = new \Vmwarephp\Autoloader;
			$autoloader->register();
	
			$sVSphereServer = Utils::GetConfigurationValue('vsphere_uri', '');
			$sLogin = Utils::GetConfigurationValue('vsphere_login', '');
			$sPassword = Utils::GetConfigurationValue('vsphere_password', '');

			$aFarms = vSphereFarmCollector::GetFarms();
			$vhost = new \Vmwarephp\Vhost($sVSphereServer, $sLogin, $sPassword);
			
			Utils::Log(LOG_DEBUG, "vSphere API type: ".$vhost->getApiType().", version: ".$vhost->getApiVersion());
			
			$aVLANs = array();
			$aDVSwitches = $vhost->findAllManagedObjects('DistributedVirtualSwitch', array('portgroup', 'summary'));
			if (count($aDVSwitches) == 0)
			{
				utils::Log(LOG_DEBUG, "No DVSwitch found in this vSphere instance.");
			}
			else
			{
				foreach($aDVSwitches as $oSwitch)
				{
					utils::Log(LOG_DEBUG, "DVSwitch: {$oSwitch->summary->name}, UUID: {$oSwitch->uuid}");
					if (count($oSwitch->portgroup) == 0)
					{
						utils::Log(LOG_DEBUG, "No DVPortgroup found on this DVSwitch.");
					}
					foreach($oSwitch->portgroup as $oPortGroup)
					{
						$aVLANs[$oPortGroup->key] = $oPortGroup->name;
						utils::Log(LOG_DEBUG, "Portgroup: {$oPortGroup->name}, config:\n".myprint_r($oPortGroup->config));
					}
				}
			}
			
			$aVirtualMachines = $vhost->findAllManagedObjects('VirtualMachine', array('config', 'runtime', 'guest', 'network', 'storage'));

			$idx = 1;
			foreach($aVirtualMachines as $oVirtualMachine)
			{
				utils::Log(LOG_DEBUG, ">>>>>> Starting collection of the VM '".$oVirtualMachine->name."' (VM #$idx)");
				$aVM = static::DoCollectVMInfo($aFarms, $oVirtualMachine, $aVLANs, $idx);
				if ($aVM !== null)
				{
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
		if ($oVirtualMachine->runtime->connectionState != 'connected')
		{
			utils::Log(LOG_INFO, "Cannot retrieve information from VM ".$oVirtualMachine->name." (VM#$idx) (runtime->connectionState='".$oVirtualMachine->runtime->connectionState."'), skipping.");
			return null;
		}

		$sDefaultOrg = Utils::GetConfigurationValue('default_org_id');
		$OSFamily = static::GetOSFamily($oVirtualMachine);
		$OSVersion = static::GetOSVersion($oVirtualMachine);

		utils::Log(LOG_DEBUG, "Collecting network info...");
		$aNWInterfaces = array();
		// Make sure user has access to network information - see bug N°6888
		if (isset($oVirtualMachine->guest) && isset($oVirtualMachine->guest->net)) {
			$aMACToNetwork = array();
			// The association MACAddress <=> Network is known at the HW level (correspondance between the VirtualINC and its "backing" device)
			foreach($oVirtualMachine->config->hardware->device as $oVirtualDevice)
			{
				switch(get_class($oVirtualDevice))
				{
					case 'VirtualE1000':
					case 'VirtualE1000e':
					case 'VirtualPCNet32':
					case 'VirtualVmxnet':
					case 'VirtualVmxnet2':
					case 'VirtualVmxnet3':
						$oBacking = $oVirtualDevice->backing;
						$sNetworkName = '';
						if (property_exists($oBacking, 'network'))
						{
							$sNetworkName = $oBacking->network->name;
							utils::Log(LOG_DEBUG, "Virtual Network Device: Using ->network->name: '$sNetworkName'");
						}
						else if (property_exists($oBacking, 'opaqueNetworkId'))
						{
							$sNetworkName = $oBacking->opaqueNetworkId;
							utils::Log(LOG_DEBUG, "Virtual Network Device: Using ->opaqueNetworkId: '$sNetworkName'");
						}
						else if (property_exists($oBacking, 'deviceName'))
						{
							$sNetworkName = $oBacking->deviceName;
							utils::Log(LOG_DEBUG, "Virtual Network Device: Using ->deviceName: '$sNetworkName'");
						}
						else if (property_exists($oBacking, 'port'))
						{
							$oPort = $oBacking->port;
							utils::Log(LOG_DEBUG, "Virtual Network Device '".get_class($oBacking)."': has the following port (".get_class($oPort)."):\n".myprint_r($oPort));
							if (array_key_exists($oPort->portgroupKey, $aVLANs))
							{
								$sNetworkName = $aVLANs[$oPort->portgroupKey];
							}
							else
							{
								utils::Log(LOG_WARNING, "No VirtualPortGroup(key) found for the Virtual Network Device '".get_class($oBacking)."' with the following port (".get_class($oPort)."):\n".myprint_r($oPort));
							}
						}
						else
						{
							utils::Log(LOG_DEBUG, "Virtual Network Device '".get_class($oBacking)."': has neither 'network', nor 'opaqueNetworkId', nor 'port'. Dumping the whole object:\n".myprint_r($oBacking));
						}
						Utils::Log(LOG_DEBUG, "MACAddress: {$oVirtualDevice->macAddress} is connected to the network: '$sNetworkName'");
						$aMACToNetwork[$oVirtualDevice->macAddress] = $sNetworkName;
						break;

					default:
						// Other types of Virtual Devices, skip
				}
			}

			Utils::Log(LOG_DEBUG, "Collecting IP addresses for this VM...");
			$aNWInterfaces = static::DoCollectVMIPs($aMACToNetwork, $oVirtualMachine);
		} else {
			utils::Log(LOG_DEBUG, "User cannot access to network information of VM ".$oVirtualMachine->name.", skipping.");
		}

		$aDisks = array();
		utils::Log(LOG_DEBUG, "Collecting disk info...");
		if ($oVirtualMachine->guest->disk)
		{
			foreach($oVirtualMachine->guest->disk as $oDiskInfo)
			{
				$aDisks[] = array(
					'path' => $oDiskInfo->diskPath,
					'capacity' => $oDiskInfo->capacity,
					'used' => $oDiskInfo->capacity - $oDiskInfo->freeSpace,
				);
			}
		}

		$sFarmName = '';

		// Is the hypervisor, on which this VM is running, part of a farm ?
		utils::Log(LOG_DEBUG, "Checking if the host is part of a Farm...");
		foreach($aFarms as $aFarm)
		{
			if (in_array($oVirtualMachine->runtime->host->name, $aFarm['hosts']))
			{
				$sFarmName = $aFarm['name'];
				break; // Farm found
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

		return array(
			'id' => $oVirtualMachine->getReferenceId(),
			'name' => $sName,
			'org_id' => $sDefaultOrg,
			// ManagementIP cannot be an IPV6 address, if no IPV4 was found above, let's clear the field
			// Note: some OpenVM clients report IP addresses with a trailing space, so let's trim the field
			'managementip' => (strpos($sGuestIP,':') !== false) ? '' : trim($sGuestIP),
			'cpu' => $iNbCPUs,
			'ram' => $iMemory,
			'osfamily_id' => $OSFamily,
			'osversion_id' => $OSVersion,
			'disks' => $aDisks,
			'interfaces' => $aNWInterfaces,
			'virtualhost_id' => empty($sFarmName) ? $sHostName : $sFarmName,
			'description' => $sAnnotation,
		);
	}

	static protected function DoCollectVMIPs($aMACToNetwork, $oVirtualMachine)
	{
		$aNWInterfaces = array();
		foreach($oVirtualMachine->guest->net as $oNICInfo)
		{
			if ($oNICInfo->ipConfig && $oNICInfo->ipConfig->ipAddress)
			{
				foreach($oNICInfo->ipConfig->ipAddress as $oIPInfo)
				{
					if (strpos($oIPInfo->ipAddress ?? '', ':') !== false)
					{
						// Ignore IP v6
						Utils::Log(LOG_DEBUG, "Ignoring an IP v6 address");
					}
					else
					{
						// If we have a guest IP set to IPv6, replace it with the first IPv4 we find
						if(strpos($oVirtualMachine->guest->ipAddress ?? '', ":") !== false)
						{
							$oVirtualMachine->guest->ipAddress = $oIPInfo->ipAddress;
						}

						Utils::Log(LOG_DEBUG, "Reading VM's IP and MAC address");
						$mask = ip2long('255.255.255.255');
						$subnet_mask = ($mask << (32 - (int)$oIPInfo->prefixLength)) & $mask;
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
	 * @param VirtualMachine $oVirtualMachine
	 * @return string The mapped OS Family or an empty string if nothing matches the extraction rules
	 */
	static public function GetOSFamily($oVirtualMachine)
	{
		if (self::$oOSFamilyMappings === null)
		{
			self::$oOSFamilyMappings =  new MappingTable('os_family_mapping');
		}
		$sRawValue = $oVirtualMachine->config->guestFullName;
		$value = self::$oOSFamilyMappings->MapValue($sRawValue, '');

		return $value;		
	}
	
	/**
	 * Helper method to extract the Version information from the VirtualMachine object
	 * according to the 'os_version_mapping' mapping taken from the configuration
	 * @param VirtualMachine $oVirtualMachine
	 * @return string The mapped OS Version or the original value if nothing matches the extraction rules
	 */
	static public function GetOSVersion($oVirtualMachine)
	{
		if (self::$oOSVersionMappings === null)
		{
			self::$oOSVersionMappings =  new MappingTable('os_version_mapping');
		}
		$sRawValue = $oVirtualMachine->config->guestFullName;
		$value = self::$oOSVersionMappings->MapValue($sRawValue, $sRawValue); // Keep the raw value by default
		
		return $value;
	}
	
	public function Prepare()
	{
		$bRet = parent::Prepare();
		if (!$bRet) return false;

		static::CollectVMInfos();
		
		$this->idx = 0;
		return true;
	}

	public function Fetch()
	{
		if ($this->idx < count(static::$aVMInfos))
		{
			$aVM = static::$aVMInfos[$this->idx++];
			return $this->DoFetch($aVM);
		}
		return false;
	}

	protected function DoFetch($aVM)
	{
		return array(
			'primary_key' => $aVM['id'],
			'name' => $aVM['name'],
			'status' => 'production',
			'org_id' => $aVM['org_id'],
			'ram' => $aVM['ram'],
			'cpu' => ((int)$aVM['cpu']),
			'managementip' => $aVM['managementip'],
			'osfamily_id' => $aVM['osfamily_id'],
			//'logicalvolumes_list' => implode('|', $aDS),
			'osversion_id' => $aVM['osversion_id'],
			'virtualhost_id' => $aVM['virtualhost_id'],
			'description' => str_replace(array("\n", "\r"), ' ', $aVM['description']),
		);
	}

	protected function MustProcessBeforeSynchro()
	{
		// We must reprocess the CSV data obtained from vSphere
		// to lookup the OSFamily/OSVersion in iTop
		return true;
	}

	protected function InitProcessBeforeSynchro()
	{
		// Retrieve the identifiers of the OSVersion since we must do a lookup based on two fields: Family + Version
		// which is not supported by the iTop Data Synchro... so let's do the job of an ETL
		$this->oOSVersionLookup = new LookupTable('SELECT OSVersion', array('osfamily_id_friendlyname', 'name'));
	}

	protected function ProcessLineBeforeSynchro(&$aLineData, $iLineIndex)
	{
		// Process each line of the CSV
		$this->oOSVersionLookup->Lookup($aLineData, array('osfamily_id', 'osversion_id'), 'osversion_id', $iLineIndex);
	}
}
