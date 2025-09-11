<?php

class vSphereCollectionPlan extends CollectionPlan
{
	private $bVirtualizationMgmtIsInstalled;
	private $sVirtualizationMgmtVersion;
    private $bDatacenterMgmtIsInstalled;
    private $sDatacenterMgmtVersion;
    private $bAdvanceStorageMgmtIsInstalled;
    private $sAdvanceStorageMgmtVersion;
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

		// Check if Virtualization Management Module is installed
		Utils::Log(LOG_INFO, '---------- Check Virtualization Management Module installation ----------');
		$this->bVirtualizationMgmtIsInstalled = Utils::CheckModuleInstallation('itop-virtualization-mgmt', false, $oRestClient);
		$this->sVirtualizationMgmtVersion = $this->bVirtualizationMgmtIsInstalled ? Utils::GetModuleVersion('itop-virtualization-mgmt') : 'unknown';

        // Check if Datacenter Management Module is installed
        Utils::Log(LOG_INFO, '---------- Check Datacenter Management Module installation ----------');
        $this->bDatacenterMgmtIsInstalled = Utils::CheckModuleInstallation('itop-datacenter-mgmt', false, $oRestClient);
		$this->sDatacenterMgmtVersion = $this->bDatacenterMgmtIsInstalled ? Utils::GetModuleVersion('itop-datacenter-mgmt') : 'unknown';

        // Check if Advanced Storage Management Module is installed
        Utils::Log(LOG_INFO, '---------- Check Advanced Storage Management Module installation ----------');
        $this->bAdvanceStorageMgmtIsInstalled = Utils::CheckModuleInstallation('itop-storage-mgmt', false, $oRestClient);
		$this->sAdvanceStorageMgmtVersion = $this->bAdvanceStorageMgmtIsInstalled ? Utils::GetModuleVersion('itop-storage-mgmt') : 'unknown';

        // Check if Data model for vSphere  is installed
		Utils::Log(LOG_INFO, '---------- Check Data model for vSphere installation ----------');
		$this->bCbdVMwareDMIsInstalled = Utils::CheckModuleInstallation('combodo-vsphere-datamodel', false, $oRestClient);
		$this->sCbdVMwareDMVersion = $this->bCbdVMwareDMIsInstalled ? Utils::GetModuleVersion('combodo-vsphere-datamodel') : 'unknown';

		// Check if TeemIP is installed or not
		Utils::Log(LOG_INFO, '---------- Check TeemIP installation ----------');
		$this->bTeemIpIsInstalled = Utils::CheckModuleInstallation('teemip-ip-mgmt', false, $oRestClient);
		$this->sTeemIpVersion = $this->bTeemIpIsInstalled ? Utils::GetModuleVersion('teemip-ip-mgmt') : 'unknown';

		// If TeemIp should be considered,
		$this->bTeemIpIpDiscoveryIsInstalled = false;
		$this->bTeemIpNMEIsInstalled = false;
		$this->bTeemIpZoneMgmtIsInstalled = false;
		$aTeemIpDiscovery = Utils::GetConfigurationValue('teemip_discovery', []);
		if ($this->bTeemIpIsInstalled && !empty($aTeemIpDiscovery) && array_key_exists('enable', $aTeemIpDiscovery) && ($aTeemIpDiscovery['enable'] == 'yes')) {
			Utils::Log(LOG_INFO, 'TeemIP should be considered.');
			// Record discovery parameters
			$this->bCollectIps = array_key_exists('collect_ips', $aTeemIpDiscovery) ? $aTeemIpDiscovery['collect_ips'] : 'no';
			$this->sDefaultIpStatus = array_key_exists('default_ip_status', $aTeemIpDiscovery) ? $aTeemIpDiscovery['default_ip_status'] : 'allocated';
			$this->bManageIpv6 = array_key_exists('manage_ipv6', $aTeemIpDiscovery) ? $aTeemIpDiscovery['manage_ipv6'] : 'no';
			$this->bManageLogicalInterfaces = array_key_exists('manage_logical_interfaces', $aTeemIpDiscovery) ? $aTeemIpDiscovery['manage_logical_interfaces'] : 'no';

			// Check if TeemIP modules are installed
			$this->bTeemIpIpDiscoveryIsInstalled = Utils::CheckModuleInstallation('teemip-ip-discovery', false, $oRestClient);
			$this->bTeemIpNMEIsInstalled = Utils::CheckModuleInstallation('teemip-network-mgmt-extended', false, $oRestClient);
			$this->bTeemIpZoneMgmtIsInstalled = Utils::CheckModuleInstallation('teemip-zone-mgmt', false, $oRestClient);
		} else {
			Utils::Log(LOG_INFO, 'As requested, TeemIP will not be considered.');
		}
	}

	/**
	 * Check if Virtualization Management Module is installed
	 *
	 * @return bool
	 */
	public function IsVirtualizationMgmtInstalled(): bool
	{
		return $this->bVirtualizationMgmtIsInstalled;
	}

    /**
     * Check if Advanced Storage Management Module is installed
     *
     * @return bool
     */
    public function IsDatacenterMgmtInstalled(): bool
    {
        return $this->bDatacenterMgmtIsInstalled;
    }

    /**
     * Check if Advanced Storage Management Module is installed
     *
     * @return bool
     */
    public function IsAdvanceStorageMgmtInstalled(): bool
    {
        return $this->bAdvanceStorageMgmtIsInstalled;
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
