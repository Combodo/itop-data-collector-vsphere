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

class vSphereLogicalInterfaceCollector extends Collector
{
	protected $idx;

	/**
	 * @var LookupTable For the VMs
	 */
	protected $oVMLookup;

	static protected $aLogicalInterfaces = null;
	static protected $aLnkLogicalInterfaceToIPAddress = null;

	static public function GetLogicalInterfaces()
	{
		if (self::$aLogicalInterfaces === null)
		{
			$aTeemIpOptions = Utils::GetConfigurationValue('teemip_options', array());
			$bCollectIPv6Addresses = ($aTeemIpOptions['manage_ipv6'] == 'yes') ? true :false;

			$aVMs = vSphereVirtualMachineTeemIpCollector::GetVMs();

			$aLogicalInterfaces = array();
			foreach($aVMs as $oVM)
			{
				$aInterfaces = $oVM['interfaces'];
				foreach ($aInterfaces AS $oInterface)
				{
					$sMac = $oInterface['mac'];
					Utils::Log(LOG_DEBUG, 'Reading interface information related to MAC @: '.$sMac);
					$aLogicalInterfaces[] = array(
						'macaddress' => $sMac,
						'name' => $oInterface['network'],
						'virtualmachine_orgid' => $oVM['org_id'],
						'virtualmachine_id' => $oVM['name'],
						'ip' => $oInterface['ip'],
					);
				}
			}

			// Change array with correct ip_lists
			$aFinalLogicalInterfaces = array();
			$aLnkLogicalInterfaceToIPAddress = array();
			foreach($aLogicalInterfaces as $sLogicalInterface => $aValue)
			{
				$sKey = array_search($aValue['macaddress'], array_column($aFinalLogicalInterfaces, 'macaddress'));
				if ($sKey === false)
				{
					$aFinalLogicalInterfaces[] = array(
						'macaddress' => $aValue['macaddress'],
						'name' => $aValue['name'],
						'virtualmachine_orgid' => $aValue['virtualmachine_orgid'],
						'virtualmachine_id' => $aValue['virtualmachine_id']
					);
				}

				$aLnkLogicalInterfaceToIPAddress[] = array (
					'ipinterface_id' => $aValue['macaddress'],
					'ipaddress_id' => $aValue['ip']
				);
			}

			self::$aLogicalInterfaces = $aFinalLogicalInterfaces;
			self::$aLnkLogicalInterfaceToIPAddress = $aLnkLogicalInterfaceToIPAddress;
		}
		return self::$aLogicalInterfaces;
	}

	static public function GetLnks()
	{
		if (self::$aLnkLogicalInterfaceToIPAddress === null)
		{
			self::GetLogicalInterfaces();
		}
		return self::$aLnkLogicalInterfaceToIPAddress;
	}

	protected function InitProcessBeforeSynchro()
	{
		// Retrieve the identifiers of the VMs since we must do a lookup based on two fields: org_id and name
		// which is not supported by the iTop Data Synchro... so let's do the job of an ETL
		$this->oVMLookup = new LookupTable('SELECT VirtualMachine', array('name'));
	}

	protected function ProcessLineBeforeSynchro(&$aLineData, $iLineIndex)
	{
		// Process each line of the CSV
		$bRet = $this->oVMLookup->Lookup($aLineData, array('virtualmachine_id'), 'virtualmachine_id', $iLineIndex);
		return $bRet;
	}

	public function Prepare()
	{
		$bRet = parent::Prepare();
		if (!$bRet) return false;

		self::GetLogicalInterfaces();

		$this->idx = 0;
		return true;
	}

	public function Fetch()
	{
		if ($this->idx < count(self::$aLogicalInterfaces))
		{
			$aLogicalInterfaces = self::$aLogicalInterfaces[$this->idx++];
			return array(
				'primary_key' => $aLogicalInterfaces['macaddress'],
				'macaddress' => $aLogicalInterfaces['macaddress'],
				'name' => $aLogicalInterfaces['name'],
				'virtualmachine_id' => $aLogicalInterfaces['virtualmachine_id'],
			);
		}
		return false;
	}
}