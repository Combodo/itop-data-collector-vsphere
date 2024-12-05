<?php

class vSphereCollectionPlan extends CollectionPlan
{
	private $bVirtualizationMgtIsInstalled;
	private $sVirtualizationMgtVersion;
	private $bCbdVMwareDMIsInstalled;
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

		// Check if Virtualization Management Module is installed
		Utils::Log(LOG_INFO, '---------- Check Virtualization Management Module installation ----------');
		$this->bVirtualizationMgtIsInstalled = false;
		$oRestClient = new RestClient();
		try {
			$aResult = $oRestClient->Get('ModuleInstallation', 'SELECT ModuleInstallation WHERE name = \'itop-virtualization-mgmt\'', 'version, installed');
			$sInstalledDate = '0000-00-00 00:00:00';
			if (array_key_exists('objects', $aResult) && isset($aResult['objects'])) {
				$this->bVirtualizationMgtIsInstalled = true;
				foreach ($aResult['objects'] as $aModuleinstallation) {
					$sInstalled = $aModuleinstallation['fields']['installed'];
					if ($sInstalled >= $sInstalledDate) {
						$sInstalledDate = $sInstalled;
						$this->sVirtualizationMgtVersion = $aModuleinstallation['fields']['version'];
					}
				}
			} else {
				$this->sVirtualizationMgtVersion = 'unknown';
			}
			$sVirtualizationMgmtMessage = 'Virtualization Management Module version '.$this->sVirtualizationMgtVersion.' is installed';
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
		$oRestClient = new RestClient();
		try {
			$aResult = $oRestClient->Get('Datastore', 'SELECT Datastore WHERE id = 0');
			if ($aResult['code'] == 0) {
				$this->bCbdVMwareDMIsInstalled = true;
				Utils::Log(LOG_INFO, 'Data model for vSphere is installed');
			} else {
				Utils::Log(LOG_INFO, 'Data model for vSphere is NOT installed');
			}
		} catch (Exception $e) {
			$sMessage = 'Data model for vSphere is considered as NOT installed due to: '.$e->getMessage();
			if (is_a($e, "IOException")) {
				Utils::Log(LOG_ERR, $sMessage);
				throw $e;
			}
		}

		// If TeemIp should be considered, check if it is installed or not
		Utils::Log(LOG_INFO, '---------- Check TeemIp installation ----------');
		$this->bTeemIpIsInstalled = false;
		$this->bTeemIpIpDiscoveryIsInstalled = false;
		$this->bTeemIpNMEIsInstalled = false;
		$this->bTeemIpZoneMgmtIsInstalled = false;
		$aTeemIpDiscovery = Utils::GetConfigurationValue('teemip_discovery', []);
		if (!empty($aTeemIpDiscovery) && array_key_exists('enable', $aTeemIpDiscovery) && ($aTeemIpDiscovery['enable'] == 'yes')) {
			Utils::Log(LOG_INFO, 'TeemIp should be considered. Detecting if it is installed on remote iTop server...');
			$oRestClient = new RestClient();
			try {
				$aResult = $oRestClient->Get('IPAddress', 'SELECT IPAddress WHERE id = 0');
				if ($aResult['code'] == 0) {
					$this->bTeemIpIsInstalled = true;
					Utils::Log(LOG_INFO, 'TeemIp is installed');
				} else {
					Utils::Log(LOG_INFO, 'TeemIp is NOT installed');
				}
			} catch (Exception $e) {
				$sMessage = 'TeemIp is considered as NOT installed due to: '.$e->getMessage();
				if (is_a($e, "IOException")) {
					Utils::Log(LOG_ERR, $sMessage);
					throw $e;
				}
			}

			if ($this->bTeemIpIsInstalled) {
				// Record discovery parameters
				$this->bCollectIps = array_key_exists('collect_ips', $aTeemIpDiscovery) ? $aTeemIpDiscovery['collect_ips'] : 'no';
				$this->sDefaultIpStatus = array_key_exists('default_ip_status', $aTeemIpDiscovery) ? $aTeemIpDiscovery['default_ip_status'] : 'allocated';
				$this->bManageIpv6 = array_key_exists('manage_ipv6', $aTeemIpDiscovery) ? $aTeemIpDiscovery['manage_ipv6'] : 'no';
				$this->bManageLogicalInterfaces = array_key_exists('manage_logical_interfaces', $aTeemIpDiscovery) ? $aTeemIpDiscovery['manage_logical_interfaces'] : 'no';

				// Detects TeemIp's version
				$oRestClient = new RestClient();
				try {
					$aResult = $oRestClient->Get('ModuleInstallation', 'SELECT ModuleInstallation WHERE name = \'teemip-ip-mgmt\'', 'version, installed');
					$sInstalledDate = '0000-00-00 00:00:00';
					if (array_key_exists('objects', $aResult) && isset($aResult['objects'])) {
						foreach ($aResult['objects'] as $aModuleinstallation) {
							$sInstalled = $aModuleinstallation['fields']['installed'];
							if ($sInstalled >= $sInstalledDate) {
								$sInstalledDate = $sInstalled;
								$this->sTeemIpVersion = $aModuleinstallation['fields']['version'];
							}
						}
					} else {
						$this->sTeemIpVersion = 'unknown';
					}
					$sTeemIpMessage = 'TeemIp version '.$this->sTeemIpVersion.' is installed';
				} catch (Exception $e) {
					$sMessage = 'TeemIp\'s installed version cannot be fetched: '.$e->getMessage();
					if (is_a($e, "IOException")) {
						Utils::Log(LOG_ERR, $sMessage);
						throw $e;
					}
				}
				Utils::Log(LOG_INFO, $sTeemIpMessage);

				// Check if TeemIp IpDiscovery is installed or not
				$oRestClient = new RestClient();
				try {
					$aResult = $oRestClient->Get('IPDiscovery', 'SELECT IPDiscovery WHERE id = 0');
					if ($aResult['code']==0) {
						$this->bTeemIpIpDiscoveryIsInstalled = true;
						Utils::Log(LOG_INFO, 'TeemIp IP Discovery is installed');
					} else {
						Utils::Log(LOG_INFO, 'TeemIp IP Discovery is NOT installed');
					}
				} catch (Exception $e) {
					$sMessage = 'TeemIp IP Discovery is considered as NOT installed due to: '.$e->getMessage();
					if (is_a($e, "IOException")) {
						Utils::Log(LOG_ERR, $sMessage);
						throw $e;
					}
				}

				// Check if TeemIp Network Management Extended is installed or not
				$oRestClient = new RestClient();
				try {
					$aResult = $oRestClient->Get('InterfaceSpeed', 'SELECT InterfaceSpeed WHERE id = 0');
					if ($aResult['code']==0) {
						$this->bTeemIpNMEIsInstalled = true;
						Utils::Log(LOG_INFO, 'TeemIp Network Management Extended is installed');
					} else {
						Utils::Log(LOG_INFO, 'TeemIp Network Management Extended is NOT installed');
					}
				} catch (Exception $e) {
					$sMessage = 'TeemIp Network Management Extended is considered as NOT installed due to: '.$e->getMessage();
					if (is_a($e, "IOException")) {
						Utils::Log(LOG_ERR, $sMessage);
						throw $e;
					}
				}

				// Check if TeemIp Zone Management is installed or not
				$oRestClient = new RestClient();
				try {
					$aResult = $oRestClient->Get('Zone', 'SELECT Zone WHERE id = 0');
					if ($aResult['code']==0) {
						$this->bTeemIpZoneMgmtIsInstalled = true;
						Utils::Log(LOG_INFO, 'TeemIp Zone Management extension is installed');
					} else {
						Utils::Log(LOG_INFO, 'TeemIp Zone Management extension is NOT installed');
					}
				} catch (Exception $e) {
					$sMessage = 'TeemIp Zone Management extension is considered as NOT installed due to: '.$e->getMessage();
					if (is_a($e, "IOException")) {
						Utils::Log(LOG_ERR, $sMessage);
						throw $e;
					}
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
