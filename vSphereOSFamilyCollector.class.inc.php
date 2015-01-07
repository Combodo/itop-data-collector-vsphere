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

class vSphereOSFamilyCollector extends Collector
{
	protected $idx;
	protected $aOSFamily;

	
	public function Prepare()
	{
		$bRet = parent::Prepare();
		$this->idx = 0;
		// Get the different OS Family values from the Virtual Machines
		$aVMInfos = vSphereVirtualMachineCollector::CollectVMInfos();
		$aTmp = array();
		foreach($aVMInfos as $aVM)
		{
			if (array_key_exists('osfamily_id', $aVM) && ($aVM['osfamily_id'] != null))
			{
				$aTmp[$aVM['osfamily_id']] = true;
			}
		}
		// Add the different OS Family values from the Hypervisors
		$aHypervisors = vSphereHypervisorCollector::GetHypervisors();
		foreach($aHypervisors as $aHV)
		{
			$aTmp[$aHV['osfamily_id']] = true;
		}
		$this->aOSFamily = array_keys($aTmp);
		return $bRet;
	}
	
	public function Fetch()
	{
		if ($this->idx < count($this->aOSFamily))
		{
			$sOSFamily = $this->aOSFamily[$this->idx++];
			return array('primary_key' => $sOSFamily, 'name' => $sOSFamily);
		}
		return false;
	}
}