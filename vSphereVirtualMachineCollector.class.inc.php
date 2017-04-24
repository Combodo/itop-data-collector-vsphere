<?php
// Copyright (C) 2014-2015 Combodo SARL
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
	protected $oOSVersionLookup;
	static protected $aVMInfos = null;
	static protected $oOSFamilyMappings = null;
	
	public function AttributeIsOptional($sAttCode)
	{
		// If the module Service Management for Service Providers is selected during the setup
		// there is no "services_list" attribute on VirtualMachines. Let's safely ignore it.
		if ($sAttCode == 'services_list') return true;
		
		return parent::AttributeIsOptional($sAttCode);
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
			$sDefaultOrg = Utils::GetConfigurationValue('default_org_id');	
			
			$aFarms = vSphereFarmCollector::GetFarms();
			
			self::$aVMInfos = array();
			$aFamilies = array();
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
			
			foreach($aVirtualMachines as $oVirtualMachine)
			{
				$OSFamily = self::GetOSFamily($oVirtualMachine);
				$OSVersion = $oVirtualMachine->config->guestFullName;
				$aDSUsage = array();
				if ($oVirtualMachine->storage->perDatastoreUsage)
				{
					foreach($oVirtualMachine->storage->perDatastoreUsage as $oVMUsageOnDatastore)
					{
						$aDSUsage[] = $oVMUsageOnDatastore->datastore->name;
					}
				}
				$aDisks = array();
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
				$aNWInterfaces = array();
				if ($oVirtualMachine->guest->net)
				{
					$aMACToNetwork = array();
					// The association MACAddress <=> Network is known at the HW level (correspondance between the VirtualINC and its "backing" device)
					foreach($oVirtualMachine->config->hardware->device as $oVirtualDevice)
					{
						switch(get_class($oVirtualDevice))
						{
							case 'VirtualE1000':
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
					
					foreach($oVirtualMachine->guest->net as $oNICInfo)
					{						
						if ($oNICInfo->ipConfig && $oNICInfo->ipConfig->ipAddress)
						{
							foreach($oNICInfo->ipConfig->ipAddress as $oIPInfo)
							{
								if (strpos($oIPInfo->ipAddress, ':') !== false)
								{
									// Ignore IP v6
								}
								else
								{
									// If we have a guest IP set to IPv6, replace it with the first IPv4 we find
									if(strpos($oVirtualMachine->guest->ipAddress, ":") !== false)
									{
										$oVirtualMachine->guest->ipAddress = $oIPInfo->ipAddress;
									}
									
									$mask = ip2long('255.255.255.255');
									$subnet_mask = ($mask << (32 - (int)$oIPInfo->prefixLength)) & $mask;
									$sSubnetMask = long2ip($subnet_mask);
									// IP v4
									$aNWInterfaces[] = array(
										'ip' => $oIPInfo->ipAddress,
										'mac' => $oNICInfo->macAddress,
										'network' => array_key_exists($oNICInfo->macAddress, $aMACToNetwork) ? $aMACToNetwork[$oNICInfo->macAddress] : '',
										'subnet_mask' => $sSubnetMask,
									);
								}
							}
						}
					}
				}
				
				$sFarmName = '';
				
				// Is the hypervisor, on which this VM is running, part of a farm ?
				foreach($aFarms as $aFarm)
				{
					if (in_array($oVirtualMachine->runtime->host->name, $aFarm['hosts']))
					{
						$sFarmName = $aFarm['name'];
						break; // Farm found
					}
				}
				
				self::$aVMInfos[] = array(
						'id' => $oVirtualMachine->getReferenceId(),
						'name' => $oVirtualMachine->name,
						'org_id' => $sDefaultOrg,
						// ManagementIP cannot be an IPV6 address, if no IPV4 was found above, let's clear the field
						'managementip' => (strpos($oVirtualMachine->guest->ipAddress, ':') !== false) ? '' : $oVirtualMachine->guest->ipAddress,
						'cpu' => $oVirtualMachine->config->hardware->numCPU,
						'ram' => $oVirtualMachine->config->hardware->memoryMB,
						'osfamily_id' => $OSFamily,
						'osversion_id' => $OSVersion,
						'datastores' => $aDSUsage,
						'disks' => $aDisks,
						'interfaces' => $aNWInterfaces,
						'virtualhost_id' => empty($sFarmName) ? $oVirtualMachine->runtime->host->name : $sFarmName,
						'description' => $oVirtualMachine->config->annotation,
				);
			}
		}
		return self::$aVMInfos;	
	}

	/**
	 * Helper method to extract the OSFamily information from the VirtualMachine object
	 * according to the mapping taken from the configuration
	 * @param VirtualMachine $oVirtualMachine
	 * @return mixed String or null if nothing matches the extraction rules
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

	public function Prepare()
	{
		$bRet = parent::Prepare();
		if (!$bRet) return false;
		
		self::CollectVMInfos();
		
		$this->idx = 0;
		return true;
	}
	
	public function Fetch()
	{
		if ($this->idx < count(self::$aVMInfos))
		{
			$aVM = self::$aVMInfos[$this->idx++];
			$aDS = array();
			foreach($aVM['datastores'] as $sDSName)
			{
				$aDS[] =  'datastore_id->name:'.$sDSName;
			}
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
		return false;
	}
}