<?php
require_once(APPROOT.'collectors/src/vSphereCollector.class.inc.php');

class vSphereFarmCollector extends vSphereCollector
{
	protected $idx;
    static protected bool $bFarmsCollected = false;
	static protected array $aFarms = [];
	
	public function AttributeIsOptional($sAttCode)
	{
		if ($sAttCode == 'services_list') return true;
		if ($sAttCode == 'providercontracts_list') return true;

        if ($this->oCollectionPlan->IsAdvanceStorageMgmtInstalled()) {
            if ($sAttCode == 'logicalvolumes_list') return false;
        } else {
            if ($sAttCode == 'logicalvolumes_list') return true;
        }

		return parent::AttributeIsOptional($sAttCode);
	}
	
	static public function GetFarms()
	{
		if (!self::$bFarmsCollected)
		{
            self::$bFarmsCollected = true;
			$sVSphereServer = Utils::GetConfigurationValue('vsphere_uri', '');
			$sLogin = Utils::GetConfigurationValue('vsphere_login', '');
			$sPassword = Utils::GetConfigurationValue('vsphere_password', '');
			$sDefaultOrg = Utils::GetConfigurationValue('default_org_id');

			// Init VMware library and connection to VMware
			static::InitVmwarephp();
			if (!static::CheckSSLConnection($sVSphereServer)) {
				throw new Exception("Cannot connect to https://$sVSphereServer. Aborting.");
			}

			// Get farms
			$vhost = new \Vmwarephp\Vhost($sVSphereServer, $sLogin, $sPassword);
			$aFarms = $vhost->findAllManagedObjects('ClusterComputeResource', array('configurationEx'));
			self::$aFarms = array();
			
			foreach($aFarms as $oFarm)
			{
				Utils::Log(LOG_DEBUG, 'Farm->name: '.$oFarm->name);
				$aHosts = array();
				foreach($oFarm->host as $oHost)
				{
					if (is_object($oHost))
					{
						$aHosts[] = $oHost->name;
					}
				}
				
				self::$aFarms[] = array(
					'id' => $oFarm->name,
					'name' => $oFarm->name,
					'org_id' => $sDefaultOrg,
					'hosts' => $aHosts,
				);

			}			
		}
		return self::$aFarms;
	}
	
	public function Prepare()
	{
		$bRet = parent::Prepare();
		if (!$bRet) return false;

		self::GetFarms();

		$this->idx = 0;
		return true;
	}

	public function Fetch()
	{
        if (is_null(self::$aFarms)) {
            return false;
        }
		if ($this->idx < count(self::$aFarms))
		{
			$aFarm = self::$aFarms[$this->idx++];
			return array(
					'primary_key' => $aFarm['id'],
					'name' => $aFarm['name'],
					'org_id' => $aFarm['org_id'],
			);
		}
		return false;
	}
}