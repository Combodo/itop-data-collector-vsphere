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

class vSphereBrandCollector extends Collector
{
	protected $idx;
	protected $aBrands;
	
	public function Prepare()
	{
		$bRet = parent::Prepare();
		if (!$bRet) return false;
		
		// Collect the different brands of all the hypervisors
		$aData = array();
		$aHypervisors = vSphereHypervisorCollector::GetHypervisors();
		foreach($aHypervisors as $aHV)
		{
			$aData[$aHV['brand_id']] = true;
		}
		// Make the list of all different values
		$this->aBrands = array_keys($aData);				
		$this->idx = 0;
		return true;
	}
	
	public function Fetch()
	{
		if ($this->idx < count($this->aBrands))
		{
			$sBrand = $this->aBrands[$this->idx++];
			return array(
					'primary_key' => $sBrand,
					'name' => $sBrand,
			);
		}
		return false;
	}
}