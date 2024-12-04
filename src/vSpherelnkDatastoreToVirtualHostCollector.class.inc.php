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

class vSpherelnkDatastoreToVirtualHostCollector extends vSphereCollector
{
	protected int $idx;
    static protected bool $bLnksCollected = false;
    static protected array $aLnks = [];

    /**
     * @inheritdoc
     */
    public function CheckToLaunch(array $aOrchestratedCollectors): bool
    {
        if (!parent::CheckToLaunch($aOrchestratedCollectors)) {
            return false;
        }
        // Extension vSphere Datamodel must be installed
        if (!$this->oCollectionPlan->IsCbdVMwareDMInstalled()) {
            Utils::Log(LOG_INFO, '> vSpherelnkDatastoreToVirtualHostCollector will not be launched as Data model for vSphere is not installed');
            return false;
        }
        // VM discovery should be made first
        if (!array_key_exists('vSphereHypervisorCollector', $aOrchestratedCollectors) || (!$aOrchestratedCollectors['vSphereHypervisorCollector'])) {
            Utils::Log(LOG_INFO, '> vSpherelnkDatastoreToVirtualHostCollector will not be launched as vSphereHypervisorCollector is not launched');
            return false;
        }

        return true;
    }

    /**
     * Get the Datastore / Virtual Hosts links reported by the vSphereHypervisorCollector collector
     *
     * @return array
     */
    static public function GetLnks(): array
    {
        if (!self::$bLnksCollected) {
            self::$bLnksCollected = true;
            if (class_exists('vSphereHypervisorCollector')) {
                self::$aLnks = vSphereHypervisorCollector::GetDatastoreLnks();
            } else {
                self::$aLnks = [];
            }
        }

        return self::$aLnks;
    }


    /**
     * @inheritdoc
     */
	public function Prepare(): bool
	{
		if (!parent::Prepare()) {
			return false;
		}

		static::GetLnks();
		$this->idx = 0;

		return true;
	}

    /**
     * @inheritdoc
     */
    public function Fetch(): bool|array
    {
        if ($this->idx < count(self::$aLnks)) {
            $aLnk = self::$aLnks[$this->idx++];

            return array(
                'primary_key' => $aLnk['datastore_id'].'-'.$aLnk['virtualhost_id'],
                'datastore_id' => $aLnk['datastore_id'],
                'virtualhost_id' => $aLnk['virtualhost_id'],
            );
        }

        return false;
    }

}
