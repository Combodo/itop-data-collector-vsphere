<?php
require_once(APPROOT.'collectors/src/vSphereCollector.class.inc.php');

class vSphereModelCollector extends vSphereCollector
{
	protected $idx;
	protected $aModels;

	public function Prepare()
	{
		$bRet = parent::Prepare();
		if (!$bRet) return false;
		
		// Collect the different brands/models of all the hypervisors
		$aData = [];
		if (class_exists('vSphereHypervisorCollector')) {
			$aHypervisors = vSphereHypervisorCollector::GetHypervisors();
			foreach ($aHypervisors as $aHV) {
				$aData[$aHV['brand_id'].'_'.$aHV['model_id']] = array('brand' => $aHV['brand_id'], 'name' => $aHV['model_id']);
			}
			// Make the list of all different values models (per brand)
			foreach ($aData as $sKey => $aModel) {
				$this->aModels[] = array('id' => $sKey, 'name' => $aModel['name'], 'brand' => $aModel['brand']);
			}
		} else {
			$this->aModels = [];
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