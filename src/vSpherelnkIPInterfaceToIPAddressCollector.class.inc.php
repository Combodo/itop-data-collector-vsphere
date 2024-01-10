<?php
require_once(APPROOT.'collectors/src/vSphereCollector.class.inc.php');

class vSpherelnkIPInterfaceToIPAddressCollector extends vSphereCollector
{
	protected $idx;
	protected $sDefaultOrg;

	/**
	 * @var mixed[][] The collected lnks
	 */
	static protected $aLnks = null;

	/**
	 * @inheritdoc
	 */
	public function CheckToLaunch(array $aOrchestratedCollectors): bool
	{
		if (parent::CheckToLaunch($aOrchestratedCollectors)) {
			// vSphereLogicalInterfaceCollector collector must be registered
			if (!array_key_exists('vSphereLogicalInterfaceCollector', $aOrchestratedCollectors) || ($aOrchestratedCollectors['vSphereLogicalInterfaceCollector'] == false)) {
				Utils::Log(LOG_INFO, '> vSpherelnkIPInterfaceToIPAddressCollector will not be launched as vSphereLogicalInterfaceCollector is not launched');
				return false;
			}
			// TeemIp must be present with correct collection options
			if ($this->oCollectionPlan->IsTeemIpInstalled() && $this->oCollectionPlan->GetTeemIpOption('collect_ips') && $this->oCollectionPlan->GetTeemIpOption('manage_logical_interfaces')) {
				return true;
			} else {
				Utils::Log(LOG_INFO, '> vSpherelnkIPInterfaceToIPAddressCollector will not be launched as TeemIP is not installed, IPs should not be collected or logical interfaces should not be managed');
			}
		}

		return false;
	}

	/**
	 * @inheritdoc
	 */
	static public function GetLnks()
	{
		if (self::$aLnks === null) {
			if (class_exists('vSphereLogicalInterfaceCollector')) {
				self::$aLnks = vSphereLogicalInterfaceCollector::GetLnks();
			} else {
				self::$aLnks = [];
			}
		}

		return self::$aLnks;
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

		$this->sDefaultOrg = Utils::GetConfigurationValue('default_org_id');

		$this->GetLnks();
		$this->idx = 0;

		return true;
	}

	/**
	 * @inheritdoc
	 */
	public function Fetch()
	{
		if ($this->idx < count(self::$aLnks)) {
			$aLnks = self::$aLnks[$this->idx++];

			return array(
				'primary_key' => $aLnks['ipinterface_id'].'-'.$aLnks['ipaddress_id'],
				'ipinterface_id' => $aLnks['ipinterface_id'],
				'ipaddress_id' => $aLnks['ipaddress_id'],
			);
		}

		return false;
	}

}