<?php
require_once(APPROOT.'collectors/src/vSphereServerCollector.class.inc.php');

class vSphereServerTeemIpCollector extends vSphereServerCollector
{
	protected $oCollectionPlan;
	protected $oIPAddressLookup;

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
	public function CheckToLaunch(array $aOrchestratedCollectors): bool
	{
		if ($this->oCollectionPlan->IsTeemIpInstalled()) {
			return true;
		}

		return false;
	}

	/**
	 * @inheritdoc
	 */

	protected static function DoCollectServer($aHyperV)
	{
		$aResult = parent::DoCollectServer($aHyperV);

		$aTeemIpOptions = Utils::GetConfigurationValue('teemip_discovery', array());
		$bCollectIps = ($aTeemIpOptions['collect_ips'] == 'yes') ? true : false;
		$bCollectIPv6Addresses = ($aTeemIpOptions['manage_ipv6'] == 'yes') ? true : false;

		$sName = $aHyperV['name'] ?? '';
		$sIP = '';
		if ($bCollectIps == 'yes') {
			// Check if name has IPv4 or "IPv6" format
			$sNum = '(\d|[1-9]\d|1\d\d|2[0-4]\d|25[0-5])';
			$sPattern = "($sNum\.$sNum\.$sNum\.$sNum)";
			if (preg_match($sPattern, $sName) || (($bCollectIPv6Addresses == 'yes') && (strpos($sName, ":") !== false))) {
				$sIP = $sName;
			}
		}

		unset($aResult['managementip']);
		$aResult['managementip_id'] = $sIP;

		return $aResult;
	}

	/**
	 * @inheritdoc
	 */
	protected function DoFetch($aServer)
	{
		$aResult = parent::DoFetch($aServer);

		unset($aResult['managementip']);
		$aResult['managementip_id'] = $aServer['managementip_id'];

		return $aResult;
	}

	/**
	 * @inheritdoc
	 */
	protected function InitProcessBeforeSynchro()
	{
		parent::InitProcessBeforeSynchro();

		$this->oIPAddressLookup = new LookupTable('SELECT IPAddress', array('org_name', 'friendlyname'));
	}

	/**
	 * @inheritdoc
	 */
	protected function ProcessLineBeforeSynchro(&$aLineData, $iLineIndex)
	{
		// Process each line of the CSV
		parent::ProcessLineBeforeSynchro($aLineData, $iLineIndex);

		$this->oIPAddressLookup->Lookup($aLineData, array('org_id', 'managementip_id'), 'managementip_id', $iLineIndex);
	}

}