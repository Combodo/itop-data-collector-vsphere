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

class vSphereServerCollector extends Collector
{
	protected $idx;
	protected $aServers;
	
	public function AttributeIsOptional($sAttCode)
	{
		// If the module Service Management for Service Providers is selected during the setup
		// there is no "services_list" attribute on VirtualMachines. Let's safely ignore it.
		if ($sAttCode == 'services_list') return true;
		
		return parent::AttributeIsOptional($sAttCode);
	}
	
	public function Prepare()
	{
		$bRet = parent::Prepare();
		if (!$bRet) return false;
		
		$sDefaultOrg = Utils::GetConfigurationValue('default_org_id');
		
		//TODO
		$aHypervisors = vSphereHypervisorCollector::GetHypervisors();
		foreach($aHypervisors as $aHyperV)
		{
			$this->aServers[] = array(
				'id' => $aHyperV['id'],
				'name' => $aHyperV['name'],
				'org_id' => $sDefaultOrg,
				'serial_number' => '', //$aHyperV['other_info'][2]->identifierValue,
				'status' => 'production',
				'brand_id' => $aHyperV['brand_id'],
				'model_id' => $aHyperV['model_id'],
				'osfamily_id' => $aHyperV['osfamily_id'],
				'osversion_id' => $aHyperV['osversion_id'],
				'cpu' => $aHyperV['cpu'],
				'ram' => $aHyperV['ram'],
			);
		}
				
		$this->idx = 0;
		return true;
	}
	
	public function Fetch()
	{
		if ($this->idx < count($this->aServers))
		{
			$aServer = $this->aServers[$this->idx++];

			return array(
					'primary_key' => $aServer['id'],
					'name' => $aServer['name'],
					'org_id' => $aServer['org_id'],
					'serialnumber' => '', //$aServer['serialnumber'],
					'status' => $aServer['status'],
					'brand_id' => $aServer['brand_id'],
					'model_id' => $aServer['model_id'],
					'osfamily_id' => $aServer['osfamily_id'],
					'osversion_id' => $aServer['osversion_id'],
					'cpu' => $aServer['cpu'],
					'ram' => $aServer['ram'],
					'managementip' => '', //$aServer[''],
			);
		}
		return false;
	}
	
	protected function MustProcessBeforeSynchro()
	{
		// We must reprocess the CSV data obtained from vSphere
		// to lookup the Brand/Model and OSFamily/OSVersion in iTop
		return true;
	}
	
	protected function InitProcessBeforeSynchro()
	{
		// Retrieve the identifiers of the OSVersion since we must do a lookup based on two fields: Family + Version
		// which is not supported by the iTop Data Synchro... so let's do the job of an ETL
		$this->oOSVersionLookup = new LookupTable('SELECT OSVersion', array('osfamily_id_friendlyname', 'name'));		

		// Retrieve the identifiers of the Model since we must do a lookup based on two fields: Brand + Model
		// which is not supported by the iTop Data Synchro... so let's do the job of an ETL
		$this->oModelLookup = new LookupTable('SELECT Model', array('brand_id_friendlyname', 'name'));		
	}
	
	protected function ProcessLineBeforeSynchro(&$aLineData, $iLineIndex)
	{
		// Process each line of the CSV
		$this->oOSVersionLookup->Lookup($aLineData, array('osfamily_id', 'osversion_id'), 'osversion_id', $iLineIndex);
		$this->oModelLookup->Lookup($aLineData, array('brand_id', 'model_id'), 'model_id', $iLineIndex);
	}
}