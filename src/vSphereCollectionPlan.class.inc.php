<?php

class vSphereCollectionPlan extends CollectionPlan
{
	public $bTeemIpIsInstalled;
	public $sTeemIpVersion;
	public $bCollectIps;
	public $sDefaultIpStatus;
	public $bManageIpv6;
	public $bManageLogicalInterfaces;
	public $bTeemIpZoneMgmtIsInstalled;
	public $bTeemIpNMEIsInstalled;

	/**
	 * @inheritdoc
	 */
	public function __construct()
	{
		parent::__construct();

		$this->bTeemIpIsInstalled = false;
		$this->sTeemIpVersion = '';
		$this->bCollectIps = false;
		$this->sDefaultIpStatus = 'allocated';
		$this->bManageIpv6 = false;
		$this->bManageLogicalInterfaces = false;
		$this->bTeemIpZoneMgmtIsInstalled = false;
		$this->bTeemIpNMEIsInstalled = false;
	}

	/**
	 * Initialize collection plan
	 *
	 * @return void
	 * @throws \IOException
	 */
	public function Init()
	{
		parent::Init();

		// If TeemIp should be considered, check if it is installed or not
		Utils::Log(LOG_INFO, '---------- Check TeemIp / IPAM for iTop parameters ----------');
		$this->bTeemIpIsInstalled = false;
		$aTeemIpDiscovery = Utils::GetConfigurationValue('teemip_discovery', []);
		if (!empty($aTeemIpDiscovery) && isset($aTeemIpDiscovery['enable']) && ($aTeemIpDiscovery['enable'] == 'yes')) {
			Utils::Log(LOG_INFO, 'TeemIp should be considered. Detecting if it is installed on remote iTop server');
			$oRestClient = new RestClient();
			try {
				$aResult = $oRestClient->Get('IPAddress', 'SELECT IPAddress WHERE id = 0');
				if ($aResult['code'] == 0) {
					$this->bTeemIpIsInstalled = true;
					Utils::Log(LOG_INFO, 'Yes, TeemIp is installed');
				} else {
					Utils::Log(LOG_INFO, $sMessage = 'TeemIp is NOT installed');
				}
			} catch (Exception $e) {
				$sMessage = 'TeemIp is considered as NOT installed due to: '.$e->getMessage();
				if (is_a($e, "IOException")) {
					Utils::Log(LOG_ERR, $sMessage);
					throw $e;
				}
			}

			if ($this->bTeemIpIsInstalled) {
				// Detects TeemIp's version
				$oRestClient = new RestClient();
				try {
					$aResult = $oRestClient->Get('ModuleInstallation', 'SELECT ModuleInstallation WHERE name = \'teemip-ip-mgmt\'', 'version, installed');
					$sInstalledDate = '0000-00-00 00:00:00';
					$this->sTeemIpVersion = '';
					foreach ($aResult['objects'] as $aModuleinstallation) {
						$sInstalled = $aModuleinstallation['fields']['installed'];
						if ($sInstalled >= $sInstalledDate) {
							$sInstalledDate = $sInstalled;
							$this->sTeemIpVersion = $aModuleinstallation['fields']['version'];
						}
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

				// Record discovery parameters
				$this->bCollectIps = $aTeemIpDiscovery['collect_ips'];
				$this->sDefaultIpStatus = $aTeemIpDiscovery['default_ip_status'];
				$this->bManageIpv6 = $aTeemIpDiscovery['manage_ipv6'];
				$this->bManageLogicalInterfaces = $aTeemIpDiscovery['manage_logical_interfaces'];

				// Check if TeemIp Zone Management is installed or not
				Utils::Log(LOG_INFO, 'Detecting if TeemIp Zone Management extension is installed on remote server');
				$this->bTeemIpZoneMgmtIsInstalled = false;
				$oRestClient = new RestClient();
				try {
					$aResult = $oRestClient->Get('Zone', 'SELECT Zone WHERE id = 0');
					if ($aResult['code'] == 0) {
						$this->bTeemIpZoneMgmtIsInstalled = true;
						Utils::Log(LOG_INFO, 'Yes, TeemIp Zone Management extension is installed');
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

				// Check if TeemIp Network Management Extended is installed or not
				Utils::Log(LOG_INFO, 'Detecting if TeemIp Network Management Extended extension is installed on remote server');
				$this->bTeemIpNMEIsInstalled = false;
				$oRestClient = new RestClient();
				try {
					$aResult = $oRestClient->Get('InterfaceSpeed', 'SELECT InterfaceSpeed WHERE id = 0');
					if ($aResult['code'] == 0) {
						$this->bTeemIpNMEIsInstalled = true;
						Utils::Log(LOG_INFO, 'Yes, TeemIp Network Management Extended is installed');
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
			}
		} else {
			Utils::Log(LOG_INFO, 'TeemIp should not be considered.');
		}
	}

	/**
	 * @param $sOption
	 *
	 * @return bool
	 */
	public function IsComponentInstalled($sComponent): bool
	{
		switch ($sComponent) {
			case 'teemip':
				return $this->bTeemIpIsInstalled;
			case 'teemip_zone_mgmt':
				return $this->bTeemIpZoneMgmtIsInstalled;
			case 'teemip_nme':
				return $this->bTeemIpNMEIsInstalled;
			default:
				return false;
		}
	}

	/**
	 * @param $sOption
	 *
	 * @return bool
	 */
	public function GetOption($sOption): bool
	{
		switch ($sOption) {
			case 'collect_ips':
				return $this->bCollectIps;
			case 'manage_ipv6':
				Utils::Log(LOG_WARNING, "IPv6 creation and update is not supported yet due to iTop limitation");

				//return $this->bManageIpv6;
				return false;
			case 'manage_logical_interfaces':
				return $this->bManageLogicalInterfaces;
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
	 * @return string
	 */
	public function GetDefaultIpStatus(): string
	{
		return $this->sDefaultIpStatus;
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
