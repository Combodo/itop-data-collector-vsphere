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

class vSphereFarmCollector extends Collector
{
	protected $idx;
	static protected $aFarms = null;
	
	public function AttributeIsOptional($sAttCode)
	{
		// If the module Service Management for Service Providers is selected during the setup
		// there is no "services_list" attribute on VirtualMachines. Let's safely ignore it.
		if ($sAttCode == 'services_list') return true;

		// If the collector is connected to TeemIp standalone, there is no "providercontracts_list"
		// on Servers. Let's safely ignore it.
		if ($sAttCode == 'providercontracts_list') return true;

		return parent::AttributeIsOptional($sAttCode);
	}
	
	static public function GetFarms()
	{
		if (self::$aFarms === null)
		{
			$sVSphereServer = Utils::GetConfigurationValue('vsphere_uri', '');
			$sLogin = Utils::GetConfigurationValue('vsphere_login', '');
			$sPassword = Utils::GetConfigurationValue('vsphere_password', '');
			$sDefaultOrg = Utils::GetConfigurationValue('default_org_id');
	
			$vhost = new \Vmwarephp\Vhost($sVSphereServer, $sLogin, $sPassword);
	
			$aFarms = $vhost->findAllManagedObjects('ClusterComputeResource', array('configurationEx'));
			self::$aFarms = array();
			
			foreach($aFarms as $oFarm)
			{
				Utils::Log(LOG_DEBUG, 'Farm->name: '.$oFarm->name);
				$aHosts = array();
				foreach($oFarm->host as $oHost)
				{
					if (is_object($oHost))
					{
						$aHosts[] = $oHost->name;
					}
				}
				
				self::$aFarms[] = array(
					'id' => $oFarm->name,
					'name' => $oFarm->name,
					'org_id' => $sDefaultOrg,
					'hosts' => $aHosts,
				);

			}			
		}
		return self::$aFarms;
	}
	
	public function Prepare()
	{
		$bRet = parent::Prepare();
		if (!$bRet) return false;

		self::GetFarms();

		$this->idx = 0;
		return true;
	}

	public function Fetch()
	{
		if ($this->idx < count(self::$aFarms))
		{
			$aFarm = self::$aFarms[$this->idx++];
			return array(
					'primary_key' => $aFarm['id'],
					'name' => $aFarm['name'],
					'org_id' => $aFarm['org_id'],
			);
		}
		return false;
	}
}