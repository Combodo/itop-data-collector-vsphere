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

class vSphereHypervisorCollector extends Collector
{
	protected $idx;
	protected $oOSVersionLookup;
	protected $oModelLookup;
	static protected $aHypervisors = null;

	public function AttributeIsOptional($sAttCode)
	{
		// If the module Service Management for Service Providers is selected during the setup
		// there is no "services_list" attribute on VirtualMachines. Let's safely ignore it.
		if ($sAttCode == 'services_list') return true;
	
		return parent::AttributeIsOptional($sAttCode);
	}
		
	public static function GetHypervisors()
	{
		if (self::$aHypervisors === null)
		{
			$oBrandMappings =  new MappingTable('brand_mapping');
			$oModelMappings =  new MappingTable('model_mapping');
			
			require_once APPROOT.'collectors/library/Vmwarephp/Autoloader.php';
			$autoloader = new \Vmwarephp\Autoloader;
			$autoloader->register();
	
			$sVSphereServer = Utils::GetConfigurationValue('vsphere_uri', '');
			$sLogin = Utils::GetConfigurationValue('vsphere_login', '');
			$sPassword = Utils::GetConfigurationValue('vsphere_password', '');
			$sDefaultOrg = Utils::GetConfigurationValue('default_org_id');
			
			$aFarms = vSphereFarmCollector::GetFarms();
			
			self::$aHypervisors = array();
			$vhost = new \Vmwarephp\Vhost($sVSphereServer, $sLogin, $sPassword);	
			
			$aHypervisors = $vhost->findAllManagedObjects('HostSystem', array('hardware', 'summary'));
			
			foreach($aHypervisors as $oHypervisor)
			{
				$sFarmName = '';
				// Is the hypervisor part of a farm ?
				
				foreach($aFarms as $aFarm)
				{
					if (in_array($oHypervisor->name, $aFarm['hosts']))
					{
						$sFarmName = $aFarm['name'];
						break; // farm found
					}
				}
				
				self::$aHypervisors[] = array(
						'id' => $oHypervisor->getReferenceId(),
						'name' => $oHypervisor->name,
						'org_id' => $sDefaultOrg,
						'brand_id' => $oBrandMappings->MapValue($oHypervisor->hardware->systemInfo->vendor, 'Other'),
						'model_id' => $oModelMappings->MapValue($oHypervisor->hardware->systemInfo->model, ''),
						'cpu' => $oHypervisor->hardware->cpuInfo->numCpuPackages,
						'ram' => (int)($oHypervisor->hardware->memorySize / (1024*1024)),
						'osfamily_id' => $oBrandMappings->MapValue($oHypervisor->config->product->name, 'Other'),
						'osversion_id' => $oModelMappings->MapValue($oHypervisor->config->product->fullName, ''),
						'status' => 'active',
						'farm_id' => $sFarmName,
						'server_id' => $oHypervisor->name,
				);
			}
		}
		return self::$aHypervisors;
	}
	
	public function Prepare()
	{
		$bRet = parent::Prepare();
		if (!$bRet) return false;
		
		self::GetHypervisors();
						
		$this->idx = 0;
		return true;
	}
	
	public function Fetch()
	{
		if ($this->idx < count(self::$aHypervisors))
		{
			$aHV = self::$aHypervisors[$this->idx++];
			return array(
				'primary_key' => $aHV['id'],
				'name' => $aHV['name'],
				'org_id' => $aHV['org_id'],
				'status' => $aHV['status'],
				'server_id' => $aHV['server_id'],
				'farm_id' => $aHV['farm_id'],
			);
		}
		return false;
	}
}