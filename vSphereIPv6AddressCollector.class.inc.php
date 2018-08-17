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

class vSphereIPv6AddressCollector extends Collector
{
	protected $idx;
	static protected $aIPv6Addresses = null;

	static public function GetIPv6Addresses()
	{
		if (self::$aIPv6Addresses === null)
		{
			$sDefaultOrg = Utils::GetConfigurationValue('default_org_id');
			$aTeemIpOptions = Utils::GetConfigurationValue('teemip_options', array('no'));

			if ($aTeemIpOptions['collect_ips'] == 'no')
			{
				self::$aIPv6Addresses = array();
			}
			else
			{
				$sDefaulIpStatus = $aTeemIpOptions['default_ip_status'];
				$aVMs = vSphereVirtualMachineTeemIpCollector::CollectVMInfos();
				foreach($aVMs as $oVM)
				{
					$sIP = $oVM['managementip_id'];
					if ($sIP != '')
					{
						if (strpos($sIP, ':') !== false)
						{
							Utils::Log(LOG_DEBUG, 'IPv6 Address: '.$sIP);
							$sShortName = explode('.', $oVM['short_name'])[0];  // Remove chars after '.', if any
							self::$aIPv6Addresses[] = array(
								'id' => $sIP,
								'ip' => $sIP,
								'org_id' => $sDefaultOrg,
								'short_name' => $oVM['short_name'],
								'status' => $sDefaulIpStatus,
							);
						}
					}
				}

				$aServers = vSphereServerTeemIpCollector::CollectServerInfos();
				foreach($aServers as $oServer)
				{
					$sIP = $oServer['managementip_id'];
					if ($sIP != '')
					{
						if (strpos($sIP, ':') !== false)
						{
							Utils::Log(LOG_DEBUG, 'IPv4 Address: '.$sIP);
							self::$aIPv6Addresses[] = array(
								'id' => $sIP,
								'ip' => $sIP,
								'org_id' => $sDefaultOrg,
								'short_name' => '',
								'status' => $sDefaulIpStatus,
							);
						}
					}
				}

				if ($aTeemIpOptions['manage_logical_interfaces'] == 'yes')
				{
					$aLnkInterfaceIPAddressses = vSpherelnkIPInterfaceToIPAddressCollector::GetLnks();
					foreach($aLnkInterfaceIPAddressses as $oLnkInterfaceIPAddresss)
					{
						$sIP = $oLnkInterfaceIPAddresss['ipaddress_id'];
						if ($sIP != '')
						{
							if (strpos($sIP, ':') !== false)
							{
								// Check if address is already listed as it may be that vSphere reported it as management IP too
								// Don't register duplicates otherwise
								$sKey = false;
								if (!empty(self::$aIPv6Addresses))
								{
									$sKey = array_search($sIP, array_column(self::$aIPv6Addresses, 'ip'));
								}
								if ($sKey === false)
								{
									Utils::Log(LOG_DEBUG, 'IPv6 Address: '.$sIP);
									self::$aIPv6Addresses[] = array(
										'id' => $sIP,
										'ip' => $sIP,
										'org_id' => $sDefaultOrg,
										'short_name' => '',
										'status' => $sDefaulIpStatus,
									);
								}
							}
						}
					}
				}
			}
		}
		return self::$aIPv6Addresses;
	}

	public function Prepare()
	{
		$bRet = parent::Prepare();
		if (!$bRet) return false;

		self::GetIPv6Addresses();

		$this->idx = 0;
		return true;
	}

	public function Fetch()
	{
		if ($this->idx < count(self::$aIPv6Addresses))
		{
			$aIPv6Addresses = self::$aIPv6Addresses[$this->idx++];
			return array(
				'primary_key' => $aIPv6Addresses['id'],
				'ip_text' => $aIPv6Addresses['ip'],
				'org_id' => $aIPv6Addresses['org_id'],
				'short_name' => $aIPv6Addresses['short_name'],
				'status' => $aIPv6Addresses['status'],
			);
		}
		return false;
	}
}