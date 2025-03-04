<?php
require_once(APPROOT.'collectors/src/vSphereCollector.class.inc.php');

class vSphereServerCollector extends vSphereCollector
{
	protected $idx;
	protected $oOSVersionLookup;
	protected $oModelLookup;
	protected $oIPAddressLookup;
	protected static $aServers;

	/**
	 * @inheritdoc
	 */
	public function CheckToLaunch(array $aOrchestratedCollectors): bool
	{
		if (parent::CheckToLaunch($aOrchestratedCollectors)) {
			if (array_key_exists('vSphereHypervisorCollector', $aOrchestratedCollectors) && ($aOrchestratedCollectors['vSphereHypervisorCollector'] == true)) {
				return true;
			} else {
				Utils::Log(LOG_INFO, '> vSphereServerCollector will not be launched as vSphereHypervisorCollector is required but is not launched');
			}
		}

		return false;
	}

	/**
	 * @inheritdoc
	 */
	public function AttributeIsOptional($sAttCode)
	{
		if ($sAttCode == 'services_list') return true;
		if ($sAttCode == 'providercontracts_list') return true;

		if ($this->oCollectionPlan->IsTeemIpInstalled()) {
			if ($sAttCode == 'managementip') return true;
			if ($sAttCode == 'managementip_id') return false;
		} else {
			if ($sAttCode == 'managementip') return false;
			if ($sAttCode == 'managementip_id') return true;
		}

		if ($this->oCollectionPlan->IsCbdVMwareDMInstalled()) {
			if ($sAttCode == 'hostid') return false;
		} else {
			if ($sAttCode == 'hostid') return true;
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
			if (class_exists('vSphereHypervisorCollector')) {
				$aHypervisors = vSphereHypervisorCollector::GetHypervisors();
				foreach ($aHypervisors as $aHyperV) {
					static::$aServers[] = static::DoCollectServer($aHyperV);
				}
			} else {
				static::$aServers = [];
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

		$oCollectionPlan = vSphereCollectionPlan::GetPlan();
		if ($oCollectionPlan->IsCbdVMwareDMInstalled()) {
			$aData['hostid'] = $aHyperV['id'];
		}
		if ($oCollectionPlan->IsTeemIpInstalled()) {
			$aTeemIpOptions = Utils::GetConfigurationValue('teemip_discovery', array());
			$bCollectIps = ($aTeemIpOptions['collect_ips'] == 'yes') ? true : false;
			$bCollectIPv6Addresses = ($aTeemIpOptions['manage_ipv6'] == 'yes') ? true : false;

			$sName = $aHyperV['name'] ?? '';
			$sIP = '';
			if ($bCollectIps == 'yes') {
				// Check if name has IPv4 or "IPv6" format
				if (filter_var($sName, FILTER_VALIDATE_IP, FILTER_FLAG_IPV4) || (($bCollectIPv6Addresses == 'yes') && filter_var($sName, FILTER_VALIDATE_IP, FILTER_FLAG_IPV6))) {
					$sIP = $sName;
				}
			}

			unset($aData['managementip']);
			$aData['managementip_id'] = $sIP;
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

		if ($this->oCollectionPlan->IsTeemIpInstalled()) {
			$this->oIPAddressLookup = new LookupTable('SELECT IPAddress', array('org_name', 'friendlyname'));
		}
	}

	/**
	 * @inheritdoc
	 */
	protected function ProcessLineBeforeSynchro(&$aLineData, $iLineIndex)
	{
		// Process each line of the CSV
		$this->oOSVersionLookup->Lookup($aLineData, array('osfamily_id', 'osversion_id'), 'osversion_id', $iLineIndex);
		$this->oModelLookup->Lookup($aLineData, array('brand_id', 'model_id'), 'model_id', $iLineIndex);
		if ($this->oCollectionPlan->IsTeemIpInstalled()) {
			// Empty IP address should not produce a Warning nor an attempt to lookup
			// To be fair, this should be a choice in the configuration file, but I'm too lazy to do it now (Schirrms 2025-03-04)
			// Original line (send this kind of messages): [Warning] No mapping found with key: '{ORG_NAME}_', 'managementip_id' will be set to zero.
			// $this->oIPAddressLookup->Lookup($aLineData, array('org_id', 'managementip_id'), 'managementip_id', $iLineIndex);
			$bSkipIfEmpty = true;
			$this->oIPAddressLookup->Lookup($aLineData, array('org_id', 'managementip_id'), 'managementip_id', $iLineIndex, $bSkipIfEmpty);
		}
	}
}
