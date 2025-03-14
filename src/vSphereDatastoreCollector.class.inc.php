<?php
// Copyright (C) 2024 Combodo SARL
//
//   This program is free software; you can redistribute it and/or modify
//   it under the terms of the GNU General Public License as published by
//   the Free Software Foundation; version 3 of the License.
//
//   This program is distributed in the hope that it will be useful,
//   but WITHOUT ANY WARRANTY; without even the implied warranty of
//   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//   GNU General Public License for more details.
//
//   You should have received a copy of the GNU General Public License
//   along with this program; if not, write to the Free Software
//   Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

require_once(APPROOT.'collectors/src/vSphereCollector.class.inc.php');

class vSphereDatastoreCollector extends vSphereCollector
{
	protected int $idx;
	protected array $aDatastoreFields;
	protected array $aDatastores;

	public function __construct()
	{
		parent::__construct();

		$this->aDatastoreFields = array('primary_key', 'capacity', 'hypervisor_id', 'location_id', 'mountingpoint', 'name', 'org_id', 'storagesystem_id', 'type', 'uuid');
		$this->aDatastores = array();
	}

	/**
	 * @inheritdoc
	 */
	public function CheckToLaunch(array $aOrchestratedCollectors): bool
	{
		if (parent::CheckToLaunch($aOrchestratedCollectors)) {
            // Extension vSphere Datamodel must be installed
			if ($this->oCollectionPlan->IsCbdVMwareDMInstalled()) {
				return true;
			} else {
				Utils::Log(LOG_INFO, '> vSphereDatastoreCollector will not be launched as Data model for vSphere is not installed');
			}
		}

		return false;
	}

    /**
     * Get the datastores from Vmware
     * @return void
     * @throws Exception
     */
    private function GetDatastores(): void
	{
		$sVSphereServer = Utils::GetConfigurationValue('vsphere_uri');
		$sLogin = Utils::GetConfigurationValue('vsphere_login');
		$sPassword = Utils::GetConfigurationValue('vsphere_password');
		$sDefaultOrg = Utils::GetConfigurationValue('default_org_id');

		self::InitVmwarephp();
		if (!self::CheckSSLConnection($sVSphereServer)) {
			throw new Exception("Cannot connect to https://$sVSphereServer. Aborting.");
		}

		$vhost = new \Vmwarephp\Vhost($sVSphereServer, $sLogin, $sPassword);

		$aDatastores = $vhost->findAllManagedObjects('Datastore', array('summary', 'vm'));
		foreach ($aDatastores as $oDatastore) {
			Utils::Log(LOG_DEBUG, "Datastore $oDatastore->name");

			$aDatastoreData = array(
				'id' => $oDatastore->getReferenceId(),
				'primary_key' => $oDatastore->getReferenceId(),
				'name' => $oDatastore->name,
				'uuid' => $oDatastore->getReferenceId(),
				'org_id' => $sDefaultOrg,
				'type' => strtolower($oDatastore->summary->type),
				'capacity' => (int)($oDatastore->summary->capacity / (1024 * 1024 * 1024)),
				'status' => 'production',
				'mountingpoint' => $oDatastore->summary->url,
			);

			$this->aDatastores[] = $aDatastoreData;
		}
	}

    /**
     * @inheritdoc
     */
	public function Prepare(): bool
	{
		$bRet = parent::Prepare();
		if (!$bRet) {
			return false;
		}

		$this->GetDatastores();
		$this->idx = 0;

		return true;
	}

    /**
     * @inheritdoc
     */
	public function Fetch(): bool|array
	{
        if (is_null($this->aDatastores)) {
            return false;
        }
		if ($this->idx < count($this->aDatastores)) {
			$aDS = $this->aDatastores[$this->idx++];
			$aResult = array();
			foreach ($this->aDatastoreFields as $sAttCode) {
				$aResult[$sAttCode] = array_key_exists($sAttCode, $aDS) ? $aDS[$sAttCode] : '';
			}

			return $aResult;
		}

		return false;
	}
}
