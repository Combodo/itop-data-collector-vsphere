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

class vSpherelnkIPInterfaceToIPAddressCollector extends Collector
{
	protected $idx;
	protected $sDefaultOrg;

	/**
	 * @var mixed[][] The collected lnks
	 */
	static protected $aLnks = null;

	static public function GetLnks()
	{
		if (self::$aLnks === null)
		{
			self::$aLnks = vSphereLogicalInterfaceCollector::GetLnks();
		}
		return self::$aLnks;
	}

	public function Prepare()
	{
		$bRet = parent::Prepare();
		if (!$bRet) return false;

		$this->sDefaultOrg = Utils::GetConfigurationValue('default_org_id');

		$this->GetLnks();
		$this->idx = 0;
		return true;
	}

	public function Fetch()
	{
		if ($this->idx < count(self::$aLnks))
		{
			$aLnks = self::$aLnks[$this->idx++];
			return array(
				'primary_key' => $aLnks['ipinterface_id'].'-'.$aLnks['ipaddress_id'],
				'ipinterface_id' => $aLnks['ipinterface_id'],
				'ipaddress_id' => $aLnks['ipaddress_id']
			);
		}
		return false;
	}

}