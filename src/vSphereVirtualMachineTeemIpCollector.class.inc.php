<?php
require_once(APPROOT.'collectors/src/vSphereVirtualMachineCollector.class.inc.php');

class vSphereVirtualMachineTeemIpCollector extends vSphereVirtualMachineCollector
{
	protected $oCollectionPlan;
	protected $oIPAddressLookup;

	/**
	 * @inheritdoc
	 */
	public function Init(): void
	{
		parent::Init();

		$this->oCollectionPlan = vSphereCollectionPlan::GetPlan();
	}

	/**
	 * @inheritdoc
	 */
	public function CheckToLaunch(array $aOrchestratedCollectors): bool
	{
		if ($this->oCollectionPlan->IsTeemIpInstalled()) {
			return true;
		}

		return false;
	}

	/**
	 * @param $aFarms
	 * @param $oVirtualMachine
	 * @param $aVLANs
	 * @param $idx
	 *
	 * @return array|null
	 * @throws \Exception
	 */
	static protected function DoCollectVMInfo($aFarms, $oVirtualMachine, $aVLANs, $idx)
	{
		$aResult = parent::DoCollectVMInfo($aFarms, $oVirtualMachine, $aVLANs, $idx);

		if ($aResult !== null) {
			$aTeemIpOptions = Utils::GetConfigurationValue('teemip_discovery', array());
			$bCollectIps = ($aTeemIpOptions['collect_ips'] == 'yes') ? true : false;
			$bCollectIPv6Addresses = ($aTeemIpOptions['manage_ipv6'] == 'yes') ? true : false;

			utils::Log(LOG_DEBUG, "Reading DNS short name (guest->hostName)...");
			$sGuestShortName = $oVirtualMachine->guest->hostName;
			utils::Log(LOG_DEBUG, "    DNS short name: $sGuestShortName");

			// Trim IP address if necessary
			$sGuestIP = $oVirtualMachine->guest->ipAddress ?? '';
			// Trim IP address if necessary
			if (!$bCollectIps) {
				$sGuestIP = '';
			} else {
				if (!$bCollectIPv6Addresses) {
					$sGuestIP = (strpos($sGuestIP, ':') !== false) ? '' : $sGuestIP;
				}
			}

			//unset($aResult['managementip']);
			$aResult['managementip_id'] = $sGuestIP;
			utils::Log(LOG_DEBUG, "Setting managementip_id: ".$sGuestIP);
			$aResult['short_name'] = $sGuestShortName;
		}

		return $aResult;
	}

	/**
	 * @param $aMACToNetwork
	 * @param $oVirtualMachine
	 *
	 * @return array
	 * @throws \Exception
	 */
	static protected function DoCollectVMIPs($aMACToNetwork, $oVirtualMachine)
	{
		$aTeemIpOptions = Utils::GetConfigurationValue('teemip_discovery', array());
		$bCollectIPv6Addresses = ($aTeemIpOptions['manage_ipv6'] == 'yes') ? true : false;

		$aNWInterfaces = array();
		foreach ($oVirtualMachine->guest->net as $oNICInfo) {
			if ($oNICInfo->ipConfig && $oNICInfo->ipConfig->ipAddress) {
				foreach ($oNICInfo->ipConfig->ipAddress as $oIPInfo) {
					Utils::Log(LOG_DEBUG, "Reading VM's IP and MAC address");
					if (strpos($oIPInfo->ipAddress ?? '', ':') !== false) {
						// It's an IPv6 address
						if ($bCollectIPv6Addresses) {
							$aNWInterfaces[] = array(
								'ip' => $oIPInfo->ipAddress,
								'mac' => $oNICInfo->macAddress,
								'network' => array_key_exists($oNICInfo->macAddress, $aMACToNetwork) ? $aMACToNetwork[$oNICInfo->macAddress] : '',
								'subnet_mask' => (int)$oIPInfo->prefixLength,
							);
						} else {
							Utils::Log(LOG_DEBUG, "Ignoring an IP v6 address");
						}
					} else {
						// If we have a guest IP set to IPv6, replace it with the first IPv4 we find
						if (strpos($oVirtualMachine->guest->ipAddress ?? '', ":") !== false) {
							$oVirtualMachine->guest->ipAddress = $oIPInfo->ipAddress;
						}

						Utils::Log(LOG_DEBUG, "Reading VM's IP and MAC address");
						$mask = ip2long('255.255.255.255');
						$subnet_mask = ($mask << (32 - (int)$oIPInfo->prefixLength)) & $mask;
						$sSubnetMask = long2ip($subnet_mask);
						// IP v4
						$aNWInterfaces[] = array(
							'ip' => $oIPInfo->ipAddress,
							'mac' => $oNICInfo->macAddress,
							'network' => array_key_exists($oNICInfo->macAddress, $aMACToNetwork) ? $aMACToNetwork[$oNICInfo->macAddress] : '',
							'subnet_mask' => $sSubnetMask,
						);
					}
				}
			}
		}

		return $aNWInterfaces;
	}

	/**
	 * @inheritdoc
	 */
	protected function DoFetch($aVM)
	{
		$aResult = parent::DoFetch($aVM);

		unset($aResult['managementip']);
		$aResult['managementip_id'] = $aVM['managementip'];

		return $aResult;
	}

	/**
	 * @inheritdoc
	 */
	protected function InitProcessBeforeSynchro()
	{
		parent::InitProcessBeforeSynchro();

		$this->oIPAddressLookup = new LookupTable('SELECT IPAddress', array('org_name', 'friendlyname'));
		//$this->oIPv6AddressLookup = new LookupTable('SELECT IPv6Address', array('org_name', 'ip'));
	}

	/**
	 * @inheritdoc
	 */
	protected function ProcessLineBeforeSynchro(&$aLineData, $iLineIndex)
	{
		// Process each line of the CSV
		parent::ProcessLineBeforeSynchro($aLineData, $iLineIndex);

		$this->oIPAddressLookup->Lookup($aLineData, array('org_id', 'managementip_id'), 'managementip_id', $iLineIndex);
		//$this->oIPv6AddressLookup->Lookup($aLineData, array('org_id', 'managementip_id'),'managementip_id', $iLineIndex);
	}
}