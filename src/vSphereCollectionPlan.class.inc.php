<?php

class vSphereCollectionPlan extends CollectionPlan
{
	private $bVirtualizationMgtIsInstalled;
	private $sVirtualizationMgtVersion;
	private $bCbdVMwareDMIsInstalled;
	private $sCbdVMwareDMVersion;
	private $bTeemIpIsInstalled;
	private $bTeemIpIpDiscoveryIsInstalled;
	private $bTeemIpNMEIsInstalled;
	private $bTeemIpZoneMgmtIsInstalled;
	private $sTeemIpVersion;
	private $bCollectIps;
	private $sDefaultIpStatus;
	private $bManageIpv6;
	private $bManageLogicalInterfaces;

	/**
	 * @inheritdoc
	 */
	public function Init(): void
	{
		parent::Init();

		$oRestClient = new RestClient();

		// Get last installation date
		$sLastInstallDate = '0000-00-00 00:00:00';
		try {
			$aDatamodelResults = $oRestClient->Get('ModuleInstallation', ['name' => 'datamodel'], 'installed', 1);
			if ($aDatamodelResults['code'] != 0 || empty($aDatamodelResults['objects'])) {
				throw new Exception($aDatamodelResults['message'], $aDatamodelResults['code']);
			}
			$aDatamodel = current($aDatamodelResults['objects']);
			$sLastInstallDate = $aDatamodel['fields']['installed'];
		} catch (Exception $e) {
			$sMessage = sprintf('Last Datamodel installation date is considered as not defined due to %s', $e->getMessage());
			Utils::Log(LOG_ERR, $sMessage);
		}

		// Check if Virtualization Management Module is installed
		Utils::Log(LOG_INFO, '---------- Check Virtualization Management Module installation ----------');
		$this->bVirtualizationMgtIsInstalled = false;
		try {
            $aResult = $oRestClient->Get('ModuleInstallation', "SELECT ModuleInstallation WHERE name = 'iTop-virtualization-mgmt' AND installed >= '$sLastInstallDate'", 'version, installed', 1);
			if (array_key_exists('objects', $aResult) && isset($aResult['objects'])) {
				$this->bVirtualizationMgtIsInstalled = true;
				$aObject = current($aResult['objects']);
				$this->sVirtualizationMgtVersion = $aObject['fields']['version'];
				$sVirtualizationMgmtMessage = 'Virtualization Management Module version '.$this->sVirtualizationMgtVersion.' is installed';
			} else {
				$this->sVirtualizationMgtVersion = 'unknown';
				$sVirtualizationMgmtMessage = 'Virtualization Management Module is not installed';
			}
		} catch (Exception $e) {
			$sMessage = 'Virtualization Management Module\'s installed version cannot be fetched: '.$e->getMessage();
			if (is_a($e, "IOException")) {
				Utils::Log(LOG_ERR, $sMessage);
				throw $e;
			}
		}
		Utils::Log(LOG_INFO, $sVirtualizationMgmtMessage);

		// Check if Data model for vSphere  is installed
		Utils::Log(LOG_INFO, '---------- Check Data model for vSphere installation ----------');
		$this->bCbdVMwareDMIsInstalled = false;
		try {
            $aResult = $oRestClient->Get('ModuleInstallation', "SELECT ModuleInstallation WHERE name = 'combodo-vsphere-datamodel' AND installed >= '$sLastInstallDate'", 'version, installed', 1);
			if (array_key_exists('objects', $aResult) && isset($aResult['objects'])) {
				$this->bCbdVMwareDMIsInstalled = true;
				$aObject = current($aResult['objects']);
				$this->sCbdVMwareDMVersion = $aObject['fields']['version'];
				$sCbdVMwareDMMessage = 'Data model for vSphere extension version '.$this->sCbdVMwareDMVersion.' is installed';
			} else {
				$this->sCbdVMwareDMVersion = 'unknown';
				$sCbdVMwareDMMessage = 'Data model for vSphere extension is not installed';
			}
		} catch (Exception $e) {
			$sMessage = 'Data model for vSphere extension\'s installed version cannot be fetched: '.$e->getMessage();
			if (is_a($e, "IOException")) {
				Utils::Log(LOG_ERR, $sMessage);
				throw $e;
			}
		}
		Utils::Log(LOG_INFO, $sCbdVMwareDMMessage);

		// Check if TeemIp is installed or not
		Utils::Log(LOG_INFO, '---------- Check TeemIp installation ----------');
		$this->bTeemIpIsInstalled = false;
		try {
            $aResult = $oRestClient->Get('ModuleInstallation', "SELECT ModuleInstallation WHERE name = 'teemip-ip-mgmt' AND installed >= '$sLastInstallDate'", 'version, installed', 1);
			if (array_key_exists('objects', $aResult) && isset($aResult['objects'])) {
				$this->bTeemIpIsInstalled = true;
				$aObject = current($aResult['objects']);
				$this->sTeemIpVersion = $aObject['fields']['version'];
				$sTeemIpMessage = 'TeemIp version ' . $this->sTeemIpVersion . ' is installed';
			} else {
				$this->sTeemIpVersion = 'unknown';
				$sTeemIpMessage = 'TeemIp is NOT installed';
			}
		} catch (Exception $e) {
			$sMessage = 'TeemIp is considered as NOT installed due to: ' . $e->getMessage();
			if (is_a($e, "IOException")) {
				Utils::Log(LOG_ERR, $sMessage);
				throw $e;
			}
		}
		Utils::Log(LOG_INFO, $sTeemIpMessage);

		// If TeemIp should be considered,
		$this->bTeemIpIpDiscoveryIsInstalled = false;
		$this->bTeemIpNMEIsInstalled = false;
		$this->bTeemIpZoneMgmtIsInstalled = false;
		$aTeemIpDiscovery = Utils::GetConfigurationValue('teemip_discovery', []);
		if ($this->bTeemIpIsInstalled && !empty($aTeemIpDiscovery) && array_key_exists('enable', $aTeemIpDiscovery) && ($aTeemIpDiscovery['enable'] == 'yes')) {
			Utils::Log(LOG_INFO, 'TeemIp should be considered.');
			// Record discovery parameters
			$this->bCollectIps = array_key_exists('collect_ips', $aTeemIpDiscovery) ? $aTeemIpDiscovery['collect_ips'] : 'no';
			$this->sDefaultIpStatus = array_key_exists('default_ip_status', $aTeemIpDiscovery) ? $aTeemIpDiscovery['default_ip_status'] : 'allocated';
			$this->bManageIpv6 = array_key_exists('manage_ipv6', $aTeemIpDiscovery) ? $aTeemIpDiscovery['manage_ipv6'] : 'no';
			$this->bManageLogicalInterfaces = array_key_exists('manage_logical_interfaces', $aTeemIpDiscovery) ? $aTeemIpDiscovery['manage_logical_interfaces'] : 'no';

			// Check if TeemIp IpDiscovery is installed or not
			$oRestClient = new RestClient();
			try {
                $aResult = $oRestClient->Get('ModuleInstallation', "SELECT ModuleInstallation WHERE name = 'teemip-ip-discovery' AND installed >= '$sLastInstallDate'", 'version, installed', 1);
				if (array_key_exists('objects', $aResult) && isset($aResult['objects'])) {
					$this->bTeemIpIpDiscoveryIsInstalled = true;
					Utils::Log(LOG_INFO, 'TeemIp IP Discovery is installed');
				} else {
					Utils::Log(LOG_INFO, 'TeemIp IP Discovery is NOT installed');
				}
			} catch (Exception $e) {
				$sMessage = 'TeemIp IP Discovery is considered as NOT installed due to: ' . $e->getMessage();
				if (is_a($e, "IOException")) {
					Utils::Log(LOG_ERR, $sMessage);
					throw $e;
				}
			}

			// Check if TeemIp Network Management Extended is installed or not
			$oRestClient = new RestClient();
			try {
                $aResult = $oRestClient->Get('ModuleInstallation', "SELECT ModuleInstallation WHERE name = 'teemip-network-mgmt-extended' AND installed >= '$sLastInstallDate'", 'version, installed', 1);
				if (array_key_exists('objects', $aResult) && isset($aResult['objects'])) {
					$this->bTeemIpNMEIsInstalled = true;
					Utils::Log(LOG_INFO, 'TeemIp Network Management Extended is installed');
				} else {
					Utils::Log(LOG_INFO, 'TeemIp Network Management Extended is NOT installed');
				}
			} catch (Exception $e) {
				$sMessage = 'TeemIp Network Management Extended is considered as NOT installed due to: ' . $e->getMessage();
				if (is_a($e, "IOException")) {
					Utils::Log(LOG_ERR, $sMessage);
					throw $e;
				}
			}

			// Check if TeemIp Zone Management is installed or not
			$oRestClient = new RestClient();
			try {
                $aResult = $oRestClient->Get('ModuleInstallation', "SELECT ModuleInstallation WHERE name = 'teemip-zone-mgmt' AND installed >= '$sLastInstallDate'", 'version, installed', 1);
				if (array_key_exists('objects', $aResult) && isset($aResult['objects'])) {
					$this->bTeemIpZoneMgmtIsInstalled = true;
					Utils::Log(LOG_INFO, 'TeemIp Zone Management extension is installed');
				} else {
					Utils::Log(LOG_INFO, 'TeemIp Zone Management extension is NOT installed');
				}
			} catch (Exception $e) {
				$sMessage = 'TeemIp Zone Management extension is considered as NOT installed due to: ' . $e->getMessage();
				if (is_a($e, "IOException")) {
					Utils::Log(LOG_ERR, $sMessage);
					throw $e;
				}
			}
		} else {
			Utils::Log(LOG_INFO, 'As requested, TeemIp will not be considered.');
		}
	}

	/**
	 * Check if Virtualization Management Module is installed
	 *
	 * @return bool
	 */
	public function IsVirtualizationMgmtInstalled(): bool
	{
		return $this->bVirtualizationMgtIsInstalled;
	}

	/**
	 * Check if Combodo VMware Datamodel is installed
	 *
	 * @return bool
	 */
	public function IsCbdVMwareDMInstalled(): bool
	{
		return $this->bCbdVMwareDMIsInstalled;
	}

	/**
	 * Get Combodo VMware Datamodel version
	 *
	 * @return string
	 */
	public function GetCbdVMwareDMVersion(): string
	{
		return $this->sCbdVMwareDMVersion;
	}

	/**
	 * Check if TeemIp is installed
	 *
	 * @return bool
	 */
	public function IsTeemIpInstalled(): bool
	{
		return $this->bTeemIpIsInstalled;
	}

	/**
	 * Check if TeemIp IP Discovey extension is installed
	 *
	 * @return bool
	 */
	public function IsTeemIpIpDiscoveryinstalled(): bool
	{
		return $this->bTeemIpIpDiscoveryIsInstalled;
	}

	/**
	 * Check if TeemIp Network Management Extended extension is installed
	 *
	 * @return bool
	 */
	public function IsTeemIpNMEInstalled(): bool
	{
		return $this->bTeemIpNMEIsInstalled;
	}

	/**
	 * Check if TeemIp Zone Management is installed
	 *
	 * @return bool
	 */
	public function IsTeemIpZoneMgmtInstalled(): bool
	{
		return $this->bTeemIpZoneMgmtIsInstalled;
	}

	/**
	 * @param $sOption
	 *
	 * @return bool
	 */
	public function GetTeemIpOption($sOption): bool
	{
		switch ($sOption) {
			case 'collect_ips':
				return ($this->bCollectIps == 'yes') ? true : false;
			case 'default_ip_status':
				return $this->sDefaultIpStatus;
			case 'manage_ipv6':
				return ($this->bManageIpv6 == 'yes') ? true : false;
			case 'manage_logical_interfaces':
				return ($this->bManageLogicalInterfaces == 'yes') ? true : false;
			default:
				return false;
		}
	}

	/**
	 * @return string
	 */
	public function GetTeemIpVersion(): string
	{
		return $this->sTeemIpVersion;
	}

	/**
	 * @inheritdoc
	 */
	public function AddCollectorsToOrchestrator(): bool
	{
		Utils::Log(LOG_INFO, "---------- vSphere Collectors to launched ----------");

		return parent::AddCollectorsToOrchestrator();
	}
}
