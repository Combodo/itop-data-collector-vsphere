<?php
require_once(APPROOT.'collectors/src/vSphereCollector.class.inc.php');

class vSphereIPv6AddressCollector extends vSphereCollector
{
	protected $idx;
	protected $aIPv6Addresses;

	/**
	 * @inheritdoc
	 */
	public function Init(): void
	{
		parent::Init();

		$this->aIPv6Addresses = [];
	}

	/**
	 * @inheritdoc
	 */
	public function CheckToLaunch(array $aOrchestratedCollectors): bool
	{
		if ($this->oCollectionPlan->IsTeemIpInstalled() && $this->oCollectionPlan->GetTeemIpOption('collect_ips') && $this->oCollectionPlan->GetTeemIpOption('manage_ipv6')) {
			return true;
		} else {
			Utils::Log(LOG_INFO, '> vSphereIPv6AddressCollector will not be launched as TeemIP is not installed, IPs should not be collected or IPv6 should not be managed');
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
	public function GetIPv6Addresses()
	{
		$sDefaultOrg = Utils::GetConfigurationValue('default_org_id');

		$sDefaulIpStatus = $this->oCollectionPlan->GetTeemIpOption('default_ip_status');
		$aVMs = vSphereVirtualMachineCollector::CollectVMInfos();
		foreach ($aVMs as $oVM) {
			$sIP = $oVM['managementip_id'] ?? '';
			if ($sIP != '') {
				if (strpos($sIP, ':') !== false) {
					Utils::Log(LOG_DEBUG, 'IPv6 Address: '.$sIP);
					if (in_array('short_name', $oVM)) {
						$sShortName = explode('.', $oVM['short_name'])[0];  // Remove chars after '.', if any
					} else {
						$sShortName = '';
					}
					$this->aIPv6Addresses[] = array(
						'id' => $sIP,
						'ip' => $sIP,
						'org_id' => $sDefaultOrg,
						'short_name' => $sShortName,
						'status' => $sDefaulIpStatus,
					);
				}
			}
		}

		$aServers = vSphereServerTeemIpCollector::CollectServerInfos();
		foreach ($aServers as $oServer) {
			$sIP = $oServer['managementip_id'] ?? '';
			if ($sIP != '') {
				if (strpos($sIP, ':') !== false) {
					Utils::Log(LOG_DEBUG, 'IPv4 Address: '.$sIP);
					$this->aIPv6Addresses[] = array(
						'id' => $sIP,
						'ip' => $sIP,
						'org_id' => $sDefaultOrg,
						'short_name' => '',
						'status' => $sDefaulIpStatus,
					);
				}
			}
		}

		if ($this->oCollectionPlan->GetTeemIpOption('manage_logical_interfaces')) {
			$aLnkInterfaceIPAddressses = vSpherelnkIPInterfaceToIPAddressCollector::GetLnks();
			foreach ($aLnkInterfaceIPAddressses as $oLnkInterfaceIPAddresss) {
				$sIP = $oLnkInterfaceIPAddresss['ipaddress_id'] ?? '';
				if ($sIP != '') {
					if (strpos($sIP, ':') !== false) {
						// Check if address is already listed as it may be that vSphere reported it as management IP too
						// Don't register duplicates otherwise
						$sKey = false;
						if (!empty($this->aIPv6Addresses)) {
							$sKey = array_search($sIP, array_column($this->aIPv6Addresses, 'ip'));
						}
						if ($sKey === false) {
							Utils::Log(LOG_DEBUG, 'IPv6 Address: '.$sIP);
							$this->aIPv6Addresses[] = array(
								'id' => $sIP,
								'ip' => $sIP,
								'org_id' => $sDefaultOrg,
								'short_name' => '',
								'status' => $sDefaulIpStatus,
							);
						}
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
		if (!$bRet) return false;

		$this->GetIPv6Addresses();
		$this->idx = 0;

		return true;
	}

	/**
	 * @inheritdoc
	 */
	public function Fetch()
	{
		if ($this->idx < count($this->aIPv6Addresses)) {
			$aIPv6Addresses = $this->aIPv6Addresses[$this->idx++];

			$aAttributesToReturn = [
				'primary_key' => $aIPv6Addresses['id'],
				'ip_text' => $aIPv6Addresses['ip'],
				'org_id' => $aIPv6Addresses['org_id'],
				'short_name' => $aIPv6Addresses['short_name'],
				'status' => $aIPv6Addresses['status'],
			];
			if (!$this->AttributeIsOptional('ipconfig_id')) {
				$aAttributesToReturn['ipconfig_id'] = $aIPv6Addresses['ipconfig_id'];
			}

			return $aAttributesToReturn;
		}

		return false;
	}
}