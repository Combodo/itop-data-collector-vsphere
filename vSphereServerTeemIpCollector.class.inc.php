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

class vSphereServerTeemIpCollector extends vSphereServerCollector
{
	protected $oIPAddressLookup;

	protected static function DoCollectServer($aHyperV)
	{
		$aResult = parent::DoCollectServer($aHyperV);

		$aTeemIpOptions = Utils::GetConfigurationValue('teemip_options', array());
		$bCollectIps = ($aTeemIpOptions['collect_ips'] == 'yes') ? true :false;
		$bCollectIPv6Addresses = ($aTeemIpOptions['manage_ipv6'] == 'yes') ? true :false;

		$sName = $aHyperV['name'];
		$sIP = '';
		if ($bCollectIps == 'yes')
		{
			// Check if name has IPv4 or "IPv6" format
			$sNum = '(\d|[1-9]\d|1\d\d|2[0-4]\d|25[0-5])';
			$sPattern = "($sNum\.$sNum\.$sNum\.$sNum)";
			if (preg_match($sPattern, $sName) || (($bCollectIPv6Addresses == 'yes') && (strpos($sName, ":") !== false)))
			{
				$sIP = $sName;
			}
		}

		unset($aResult['managementip']);
		$aResult['managementip_id'] = $sIP;

		return $aResult;
	}

	protected function DoFetch($aServer)
	{
		$aResult = parent::DoFetch($aServer);

		unset($aResult['managementip']);
		$aResult['managementip_id'] = $aServer['managementip_id'];

		return $aResult;
	}

	protected function InitProcessBeforeSynchro()
	{
		parent::InitProcessBeforeSynchro();

		$this->oIPAddressLookup = new LookupTable('SELECT IPAddress', array('org_name', 'friendlyname'));
	}

	protected function ProcessLineBeforeSynchro(&$aLineData, $iLineIndex)
	{
		// Process each line of the CSV
		parent::ProcessLineBeforeSynchro($aLineData, $iLineIndex);

		$this->oIPAddressLookup->Lookup($aLineData, array('org_id', 'managementip_id'), 'managementip_id', $iLineIndex);
	}

}