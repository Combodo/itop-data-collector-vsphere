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

class vSphereModelCollector extends Collector
{
	protected $idx;
	protected $aModels;
	
	public function Prepare()
	{
		$bRet = parent::Prepare();
		if (!$bRet) return false;
		
		// Collect the different brands/models of all the hypervisors
		$aData = array();
		$aHypervisors = vSphereHypervisorCollector::GetHypervisors();
		foreach($aHypervisors as $aHV)
		{
			$aData[$aHV['brand_id'].'_'.$aHV['model_id']] = array('brand' => $aHV['brand_id'], 'name' => $aHV['model_id']);
		}
		// Make the list of all different values models (per brand)
		foreach($aData as $sKey => $aModel)
		{
			$this->aModels[] = array('id' => $sKey, 'name' => $aModel['name'], 'brand' => $aModel['brand']);
		}				
		$this->idx = 0;
		return true;
	}
	
	public function Fetch()
	{
		if ($this->idx < count($this->aModels))
		{
			$aModel = $this->aModels[$this->idx++];
			return array(
					'primary_key' => $aModel['id'],
					'name' => $aModel['name'],
					'type' => 'Server',
					'brand_id' => $aModel['brand'],
			);
		}
		return false;
	}
}