<?php
// Copyright (C) 2022 Combodo SARL
//
//   This application is free software; you can redistribute it and/or modify	
//   it under the terms of the GNU Affero General Public License as published by
//   the Free Software Foundation, either version 3 of the License, or
//   (at your option) any later version.
//
//   This application is distributed in the hope that it will be useful,
//   but WITHOUT ANY WARRANTY; without even the implied warranty of
//   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//   GNU Affero General Public License for more details.
//
//   You should have received a copy of the GNU Affero General Public License
//   along with this application. If not, see <http://www.gnu.org/licenses/>

require_once(APPROOT.'collectors/src/ConfigurableCollector.class.inc.php');

class vSphereServerCollector extends ConfigurableCollector
{
	protected $idx;
	protected $oCollectionPlan;
	protected static $aServers;

	/**
	 * @inheritdoc
	 */
	public function Init(): void
	{
		parent::Init();

		$this->oCollectionPlan = vSphereCollectionPlan::GetPlan();
	}

	/**
	 * @inheritdoc
	 */
	public function IsToBeLaunched(): bool
	{
		if (!$this->oCollectionPlan->IsComponentInstalled('teemip')) {
			return true;
		}

		return false;
	}

	/**
	 * @inheritdoc
	 */
	public function AttributeIsOptional($sAttCode)
	{
		// If the module Service Management for Service Providers is selected during the setup
		// there is no "services_list" attribute on VirtualMachines. Let's safely ignore it.
		if ($sAttCode == 'services_list') {
			return true;
		}

		// If the collector is connected to TeemIp standalone, there is no "providercontracts_list"
		// on Servers. Let's safely ignore it.
		if ($sAttCode == 'providercontracts_list') {
			return true;
		}

		return parent::AttributeIsOptional($sAttCode);
	}

	/**
	 * @return mixed
	 * @throws \Exception
	 */
	public static function CollectServerInfos()
	{
		if (static::$aServers === null) {
			$aHypervisors = vSphereHypervisorCollector::GetHypervisors();
			foreach ($aHypervisors as $aHyperV) {
				static::$aServers[] = static::DoCollectServer($aHyperV);
			}
		}
		utils::Log(LOG_DEBUG, "End of collection of Servers information.");

		return static::$aServers;
	}

	/**
	 * @param $aHyperV
	 *
	 * @return array
	 * @throws \Exception
	 */
	protected static function DoCollectServer($aHyperV)
	{
		$sDefaultOrg = Utils::GetConfigurationValue('default_org_id');
		$aData = array(
			'primary_key' => $aHyperV['id'],
			'name' => $aHyperV['name'],
			'org_id' => $sDefaultOrg,
			'status' => 'production',
			'brand_id' => $aHyperV['brand_id'],
			'model_id' => $aHyperV['model_id'],
			'osfamily_id' => $aHyperV['osfamily_id'],
			'osversion_id' => $aHyperV['osversion_id'],
			'cpu' => $aHyperV['cpu'],
			'ram' => $aHyperV['ram'],
		);

		// Add the custom fields (if any)
		foreach (vSphereHypervisorCollector::GetCustomFields(__CLASS__) as $sAttCode => $sFieldDefinition) {
			$aData[$sAttCode] = $aHyperV['server-custom-'.$sAttCode];
		}

		return $aData;
	}

	/**
	 * @inheritdoc
	 */
	public function Prepare()
	{
		$bRet = parent::Prepare();
		if (!$bRet) {
			return false;
		}

		static::CollectServerInfos();

		$this->idx = 0;

		return true;
	}

	/**
	 * @inheritdoc
	 */
	public function Fetch()
	{
		if ($this->idx < count(static::$aServers)) {
			$aServer = static::$aServers[$this->idx++];

			return $this->DoFetch($aServer);
		}

		return false;
	}

	/**
	 * @param $aServer
	 *
	 * @return mixed
	 */
	protected function DoFetch($aServer)
	{
		return $aServer;
	}

	/**
	 * @inheritdoc
	 */
	protected function MustProcessBeforeSynchro()
	{
		// We must reprocess the CSV data obtained from vSphere
		// to lookup the Brand/Model and OSFamily/OSVersion in iTop
		return true;
	}

	/**
	 * @inheritdoc
	 */
	protected function InitProcessBeforeSynchro()
	{
		// Retrieve the identifiers of the OSVersion since we must do a lookup based on two fields: Family + Version
		// which is not supported by the iTop Data Synchro... so let's do the job of an ETL
		$this->oOSVersionLookup = new LookupTable('SELECT OSVersion', array('osfamily_id_friendlyname', 'name'));

		// Retrieve the identifiers of the Model since we must do a lookup based on two fields: Brand + Model
		// which is not supported by the iTop Data Synchro... so let's do the job of an ETL
		$this->oModelLookup = new LookupTable('SELECT Model', array('brand_id_friendlyname', 'name'));
	}

	/**
	 * @inheritdoc
	 */
	protected function ProcessLineBeforeSynchro(&$aLineData, $iLineIndex)
	{
		// Process each line of the CSV
		$this->oOSVersionLookup->Lookup($aLineData, array('osfamily_id', 'osversion_id'), 'osversion_id', $iLineIndex);
		$this->oModelLookup->Lookup($aLineData, array('brand_id', 'model_id'), 'model_id', $iLineIndex);
	}
}
