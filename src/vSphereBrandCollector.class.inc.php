<?php
require_once(APPROOT.'collectors/src/vSphereCollector.class.inc.php');

class vSphereBrandCollector extends vSphereCollector
{
	protected $idx;
	protected $aBrands;

	public function Prepare()
	{
		$bRet = parent::Prepare();
		if (!$bRet) return false;
		
		// Collect the different brands of all the hypervisors
		$aData = [];
		if (class_exists('vSphereHypervisorCollector')) {
			$aHypervisors = vSphereHypervisorCollector::GetHypervisors();
			foreach ($aHypervisors as $aHV) {
				$aData[$aHV['brand_id']] = true;
			}
		}
		// Make the list of all different values
		$this->aBrands = array_keys($aData);				
		$this->idx = 0;
		return true;
	}
	
	public function Fetch()
	{
        if (is_null($this->aBrands)) {
            return false;
        }
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