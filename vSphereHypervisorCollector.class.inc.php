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
			$oOSFamilyMappings =  new MappingTable('os_family_mapping');
			$oOSVersionMappings =  new MappingTable('os_version_mapping');
				
			$sVSphereServer = Utils::GetConfigurationValue('vsphere_uri', '');
			$sLogin = Utils::GetConfigurationValue('vsphere_login', '');
			$sPassword = Utils::GetConfigurationValue('vsphere_password', '');
			$sDefaultOrg = Utils::GetConfigurationValue('default_org_id');

			static::InitVmwarephp();
			if (!static::CheckSSLConnection($sVSphereServer))
			{
				throw new Exception("Cannot connect to https://$sVSphereServer. Aborting.");
			}
			
			$aFarms = vSphereFarmCollector::GetFarms();
			
			self::$aHypervisors = array();
			$vhost = new \Vmwarephp\Vhost($sVSphereServer, $sLogin, $sPassword);	
			
			$aHypervisors = $vhost->findAllManagedObjects('HostSystem', array('hardware', 'summary'));
			
			foreach($aHypervisors as $oHypervisor)
			{
				if ($oHypervisor->runtime->connectionState !== 'connected')
				{
					// The documentation says that 'config' ".. might not be available for a disconnected host"
					// A customer reported that trying to access ->config->... causes a segfault !!
					// So let's skip such hypervisors for now
					Utils::Log(LOG_INFO, "Skipping Hypervisor {$oHypervisor->name} which is NOT connected (runtime->connectionState = '{$oHypervisor->runtime->connectionState}')");
					continue;
				}
				
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
						'osfamily_id' => $oOSFamilyMappings->MapValue($oHypervisor->config->product->name, 'Other'),
						'osversion_id' => $oOSVersionMappings->MapValue($oHypervisor->config->product->fullName, ''),
						'status' => 'production',
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

	/**
	 * Check the SSL connection to the given host
	 * @param string $sHost The host/uri to connect to (e.g. 192.168.10.12:443)
	 * @return boolean
	 */
	protected static function CheckSSLConnection($sHost)
	{
		$errno = 0;
		$errstr = 'No error';
		$fp = @stream_socket_client('ssl://'.$sHost, $errno, $errstr, 5);
		if (($fp === false) && ($errno === 0))
		{
			// Failed to connect, check for SSL certificate problems
			$aStreamContextOptions = array(
					'ssl' => array(
							'verify_peer' => 0,
							'verify_peer_name' => 0,
							'allow_self_signed' => 1,
					)
			);
			$context = stream_context_create($aStreamContextOptions);
			$fp = @stream_socket_client('ssl://'.$sHost, $errno, $errstr, 5, STREAM_CLIENT_CONNECT, $context);
			if ($fp === false)
			{
				Utils::Log(LOG_CRIT, "Failed to connect to https://$sHost (Error $errno: $errstr)");
				return false;
			}
			else
			{
				Utils::Log(LOG_CRIT, "Failed to connect to https://$sHost - Invalid SSL certificate.\nYou can add the following 'vsphere_connection_options' to your configuration file (conf/params.local.xml) to bypass this check:\n<vsphere_connection_options>\n\t<ssl>\n\t\t<verify_peer>0</verify_peer>\n\t\t<verify_peer_name>0</verify_peer_name>\n\t\t<allow_self_signed>1</allow_self_signed>\n\t</ssl>\n</vsphere_connection_options>\n");
				return false;
			}
		}
		else if ($fp === false)
		{
			Utils::Log(LOG_CRIT, "Failed to connect to https://$sHost (Error $errno: $errstr)");
			return false;
		}
		Utils::Log(LOG_DEBUG, "Connection to https://$sHost Ok.");
		return true; // Ok this works
	}
	
	protected static function InitVmwarephp()
	{
		require_once APPROOT.'collectors/library/Vmwarephp/Autoloader.php';
		$autoloader = new \Vmwarephp\Autoloader();
		$autoloader->register();
		
		// Set default stream context options, see http://php.net/manual/en/context.php for the possible options
		$aStreamContextOptions = Utils::GetConfigurationValue('vsphere_connection_options', array());
		
		Utils::Log(LOG_DEBUG, "vSphere connection options: ".print_r($aStreamContextOptions, true));
		
		$default = stream_context_set_default($aStreamContextOptions);
	}
}