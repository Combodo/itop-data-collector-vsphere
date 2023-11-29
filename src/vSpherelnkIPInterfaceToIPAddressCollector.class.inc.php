<?php

class vSpherelnkIPInterfaceToIPAddressCollector extends Collector
{
	protected $idx;
	protected $oCollectionPlan;
	protected $sDefaultOrg;

	/**
	 * @var mixed[][] The collected lnks
	 */
	static protected $aLnks = null;

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
		// vSphereLogicalInterfaceCollector collector must be registered
		if (!array_key_exists('vSphereLogicalInterfaceCollector', $aOrchestratedCollectors) || ($aOrchestratedCollectors['vSphereLogicalInterfaceCollector'] == false)) {
			return false;
		}
		// TeemIp must be present with correct collection options
		if ($this->oCollectionPlan->IsTeemIpInstalled() && $this->oCollectionPlan->GetTeemIpOption('collect_ips') && $this->oCollectionPlan->GetTeemIpOption('manage_logical_interfaces')) {
			return true;
		}

		return false;
	}

	/**
	 * @inheritdoc
	 */
	static public function GetLnks()
	{
		if (self::$aLnks === null) {
			self::$aLnks = vSphereLogicalInterfaceCollector::GetLnks();
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