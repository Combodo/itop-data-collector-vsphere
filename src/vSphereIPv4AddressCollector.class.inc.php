<?php
require_once(APPROOT.'collectors/src/vSphereCollector.class.inc.php');

class vSphereIPv4AddressCollector extends vSphereCollector
{
	protected $idx;
	protected $aIPv4Addresses;

	/**
	 * @inheritdoc
	 */
	public function Init(): void
	{
		parent::Init();

		$this->aIPv4Addresses = [];
	}

	/**
	 * @inheritdoc
	 */
	public function CheckToLaunch(array $aOrchestratedCollectors): bool
	{
		if (parent::CheckToLaunch($aOrchestratedCollectors)) {
			if ($this->oCollectionPlan->IsTeemIpInstalled() && $this->oCollectionPlan->GetTeemIpOption('collect_ips')) {
				return true;
			} else {
				Utils::Log(LOG_INFO, '> vSphereIPv4AddressCollector will not be launched as TeemIP is not installed or IPs should not be collected');
			}
		}

		return false;
	}

	/**
	 * @inheritdoc
	 */
	public function AttributeIsOptional($sAttCode)
	{
		if ($sAttCode == 'azureip') return true;
		if ($sAttCode == 'fqdn_from_iplookup') return true;
		if ($sAttCode == 'last_discovery_date') return true;
		if ($sAttCode == 'ping_before_assign') return true;
		if ($sAttCode == 'responds_to_iplookup') return true;
		if ($sAttCode == 'responds_to_ping') return true;
		if ($sAttCode == 'responds_to_scan') return true;
		if ($sAttCode == 'services_list') return true;
		if ($sAttCode == 'view_id') return true;
		if ($sAttCode == 'ipconfig_id') {
			if (strstr($this->oCollectionPlan->GetTeemIpVersion(), '.', true) < '3') {
				return true;
			}
		}

		return parent::AttributeIsOptional($sAttCode);
	}

	/**
	 * @return void
	 * @throws Exception
	 */
	public function GetIPv4Addresses()
	{
		$sDefaultOrg = Utils::GetConfigurationValue('default_org_id');

		$sDefaulIpStatus = $this->oCollectionPlan->GetTeemIpOption('default_ip_status');
		if (class_exists('vSphereVirtualMachineCollector')) {
			$aVMs = vSphereVirtualMachineCollector::CollectVMInfos();
			foreach ($aVMs as $oVM) {
				$sIP = filter_var($oVM['managementip_id'] ?? '', FILTER_VALIDATE_IP, FILTER_FLAG_IPV4) ?: '';
				if ($sIP != '') {
					Utils::Log(LOG_DEBUG, 'IPv4 Address: ' . $sIP);
					if (isset($oVM['short_name'])) {
						$sShortName = explode('.', $oVM['short_name'])[0];  // Remove chars after '.', if any
						Utils::Log(LOG_DEBUG, ' `- Short Name: ' . $sShortName);
					} else {
						$sShortName = '';
					}
					$this->aIPv4Addresses[] = array(
						'id' => $sIP,
						'ip' => $sIP,
						'org_id' => $sDefaultOrg,
						'ipconfig_id' => $sDefaultOrg,
						'short_name' => $sShortName,
						'status' => $this->oCollectionPlan->GetTeemIpOption('default_ip_status'),
					);
				}
			}
		}

		if (class_exists('vSphereServerCollector')) {
			$aServers = vSphereServerCollector::CollectServerInfos();
			foreach ($aServers as $oServer) {
				$sIP = filter_var($oServer['managementip_id'] ?? '', FILTER_VALIDATE_IP, FILTER_FLAG_IPV4) ?: '';
				if ($sIP != '') {
					Utils::Log(LOG_DEBUG, 'IPv4 Address: ' . $sIP);
					$this->aIPv4Addresses[] = array(
						'id' => $sIP,
						'ip' => $sIP,
						'org_id' => $sDefaultOrg,
						'ipconfig_id' => $sDefaultOrg,
						'short_name' => '',
						'status' => $sDefaulIpStatus,
					);
				}
			}
		}

		if ($this->oCollectionPlan->GetTeemIpOption('manage_logical_interfaces') && class_exists('vSpherelnkIPInterfaceToIPAddressCollector')) {
			$aLnkInterfaceIPAddressses = vSpherelnkIPInterfaceToIPAddressCollector::GetLnks();
			foreach ($aLnkInterfaceIPAddressses as $oLnkInterfaceIPAddresss) {
				$sIP = filter_var($oLnkInterfaceIPAddresss['ipaddress_id'] ?? '', FILTER_VALIDATE_IP, FILTER_FLAG_IPV4) ?: '';
				if ($sIP != '') {
					// Check if address is already listed as it may be that vSphere reported it as management IP too
					// Don't register duplicates otherwise
					$sKey = false;
					if (!empty($this->aIPv4Addresses)) {
						$sKey = array_search($sIP, array_column($this->aIPv4Addresses, 'ip'));
					}
					if ($sKey === false) {
						Utils::Log(LOG_DEBUG, 'IPv4 Address: ' . $sIP);
						$this->aIPv4Addresses[] = array(
							'id' => $sIP,
							'ip' => $sIP,
							'org_id' => $sDefaultOrg,
							'ipconfig_id' => $sDefaultOrg,
							'short_name' => '',
							'status' => $sDefaulIpStatus,
						);
					}
				}
			}
		}
	}

	/**
	 * @inheritdoc
	 */
	public function Prepare()
	{
		$bRet = parent::Prepare();
		if (!$bRet) {
			return false;
		}

		$this->GetIPv4Addresses();
		$this->idx = 0;

		return true;
	}

	/**
	 * @inheritdoc
	 */
	public function Fetch()
	{
		if ($this->idx < count($this->aIPv4Addresses)) {
			$aIPv4Addresses = $this->aIPv4Addresses[$this->idx++];

			$aAttributesToReturn = [
				'primary_key' => $aIPv4Addresses['id'],
				'ip' => $aIPv4Addresses['ip'],
				'org_id' => $aIPv4Addresses['org_id'],
				'short_name' => $aIPv4Addresses['short_name'],
				'status' => $aIPv4Addresses['status'],
			];
			if (!$this->AttributeIsOptional('ipconfig_id')) {
				$aAttributesToReturn['ipconfig_id'] = $aIPv4Addresses['ipconfig_id'];
			}

			return $aAttributesToReturn;
		}

		return false;
	}
}
