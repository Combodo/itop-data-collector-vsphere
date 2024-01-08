<?php
require_once(APPROOT.'collectors/src/vSphereCollector.class.inc.php');

class vSphereBrandCollector extends vSphereCollector
{
	protected $idx;
	protected $aBrands;

	/**
	 * @inheritdoc
	 */
	public function CheckToLaunch(array $aOrchestratedCollectors): bool
	{
		if (parent::CheckToLaunch($aOrchestratedCollectors)) {
			if (array_key_exists('vSphereHypervisorCollector', $aOrchestratedCollectors) && ($aOrchestratedCollectors['vSphereHypervisorCollector'] == true)) {
				return true;
			} else {
				Utils::Log(LOG_INFO, '> vSphereBrandCollector will not be launched as vSphereHypervisorCollector is required but is not launched');
			}
		}

		return false;
	}

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