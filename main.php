<?php
// Copyright (C) 2022 Combodo SARL
//
//   This application is free software; you can redistribute it and/or modify	
//   it under the terms of the GNU Affero General Public License as published by
//   the Free Software Foundation, either version 3 of the License, or
//   (at your option) any later version.
//
//   iTop is distributed in the hope that it will be useful,
//   but WITHOUT ANY WARRANTY; without even the implied warranty of
//   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//   GNU Affero General Public License for more details.
//
//   You should have received a copy of the GNU Affero General Public License
//   along with this application. If not, see <http://www.gnu.org/licenses/>

require_once(APPROOT.'collectors/ConfigurableCollector.class.inc.php');
require_once(APPROOT.'collectors/vSphereOSFamilyCollector.class.inc.php');
require_once(APPROOT.'collectors/vSphereOSVersionCollector.class.inc.php');
require_once(APPROOT.'collectors/vSphereFarmCollector.class.inc.php');
require_once(APPROOT.'collectors/vSphereHypervisorCollector.class.inc.php');
require_once(APPROOT.'collectors/vSphereBrandCollector.class.inc.php');
require_once(APPROOT.'collectors/vSphereModelCollector.class.inc.php');
require_once(APPROOT.'collectors/vSphereServerCollector.class.inc.php');
require_once(APPROOT.'collectors/vSphereVirtualMachineCollector.class.inc.php');

// TeemIp specific classes
require_once(APPROOT.'collectors/vSphereServerTeemIpCollector.class.inc.php');
require_once(APPROOT.'collectors/vSphereVirtualMachineTeemIpCollector.class.inc.php');
require_once(APPROOT.'collectors/vSphereIPv4AddressCollector.class.inc.php');
require_once(APPROOT.'collectors/vSphereIPv6AddressCollector.class.inc.php');
require_once(APPROOT.'collectors/vSphereLogicalInterfaceCollector.class.inc.php');
require_once(APPROOT.'collectors/vSpherelnkIPInterfaceToIPAddressCollector.class.inc.php');


// Register the collectors (one collector class per data synchro task to run)
// and tell the orchestrator in which order to run them

$iRank = 1;
Orchestrator::AddCollector($iRank++, 'vSphereBrandCollector');
Orchestrator::AddCollector($iRank++, 'vSphereModelCollector');
Orchestrator::AddCollector($iRank++, 'vSphereOSFamilyCollector');
Orchestrator::AddCollector($iRank++, 'vSphereOSVersionCollector');
Orchestrator::AddCollector($iRank++, 'vSphereFarmCollector');

// Detects if TeemIp is installed or not
Utils::Log(LOG_INFO, 'Detecting if TeemIp is installed on remote iTop server');
$bTeemIpIsInstalled = false;
$oRestClient = new RestClient();
try {
	$aResult = $oRestClient->Get('IPAddress', 'SELECT IPAddress WHERE id = 0');
	if ($aResult['code'] == 0) {
		$bTeemIpIsInstalled = true;
	} else {
		$sTeemIpMessage = 'TeemIp is NOT installed';
	}
} catch (Exception $e) {
	$sMessage = 'TeemIp is considered as NOT installed due to: '.$e->getMessage();
	if (is_a($e, "IOException")) {
		Utils::Log(LOG_ERR, $sMessage);
		throw $e;
	}
}
vSphereOSFamilyCollector::UseTeemIP($bTeemIpIsInstalled);

if ($bTeemIpIsInstalled) {
	// Detects TeemIp's version
	$oRestClient = new RestClient();
	try {
		$aResult = $oRestClient->Get('ModuleInstallation', 'SELECT ModuleInstallation WHERE name = \'teemip-ip-mgmt\'', 'version, installed');
		$sInstalledDate = '0000-00-00 00:00:00';
		$sTeemIpVersion = '';
		foreach ($aResult['objects'] as $aModuleinstallation) {
			$sInstalled = $aModuleinstallation['fields']['installed'];
			if ($sInstalled >= $sInstalledDate) {
				$sInstalledDate = $sInstalled;
				$sTeemIpVersion = $aModuleinstallation['fields']['version'];
			}
		}
		$sTeemIpMessage = 'TeemIp version '.$sTeemIpVersion.' is installed';
	} catch (Exception $e) {
		$sMessage = 'TeemIp\'s installed version cannot be fetched: '.$e->getMessage();
		if (is_a($e, "IOException")) {
			Utils::Log(LOG_ERR, $sMessage);
			throw $e;
		}
	}
	Utils::Log(LOG_INFO, $sTeemIpMessage);

	$aTeemIpOptions = Utils::GetConfigurationValue('teemip_options', array());
	$bCollectIps = $aTeemIpOptions['collect_ips'];

	if ($bCollectIps == 'yes') {
		Utils::Log(LOG_INFO, 'IPs will be collected');
		Orchestrator::AddCollector($iRank++, 'vSphereIPv4AddressCollector');
		vSphereIPv4AddressCollector::SetTeemIpVersion($sTeemIpVersion);
		if ($aTeemIpOptions['manage_ipv6'] == 'yes') {
			Utils::Log(LOG_WARNING, "IPv6 creation and update is not supported yet due to iTop limitation");
			Orchestrator::AddCollector($iRank++, 'vSphereIPv6AddressCollector');
			vSphereIPv6AddressCollector::SetTeemIpVersion($sTeemIpVersion);
		}
	} else {
		Utils::Log(LOG_INFO, 'IPs will NOT be collected');
	}
	Orchestrator::AddCollector($iRank++, 'vSphereServerTeemIpCollector');
	Orchestrator::AddCollector($iRank++, 'vSphereHypervisorCollector');
	Orchestrator::AddCollector($iRank++, 'vSphereVirtualMachineTeemIpCollector');

	if (($bCollectIps == 'yes') && ($aTeemIpOptions['manage_logical_interfaces'] == 'yes')) {
		Utils::Log(LOG_INFO, 'Logical interfaces will be collected');
		Orchestrator::AddCollector($iRank++, 'vSphereLogicalInterfaceCollector');
		Orchestrator::AddCollector($iRank++, 'vSpherelnkIPInterfaceToIPAddressCollector');

		// Detects if TeemIp Network Management Extended is installed
		$bTeemIpNMEIsInstalled = false;
		$oRestClient = new RestClient();
		try {
			$aResult = $oRestClient->Get('InterfaceSpeed', 'SELECT InterfaceSpeed WHERE id = 0');
			if ($aResult['code'] == 0) {
				$sMessage = 'Yes, TeemIp Network Management Extended is installed';
				$bTeemIpNMEIsInstalled = true;
			} else {
				$sMessage = 'TeemIp Network Management Extended is NOT installed';
			}
		} catch (Exception $e) {
			$sMessage = 'TeemIp Network Management Extended is considered as NOT installed due to: '.$e->getMessage();
			if (is_a($e, "IOException")) {
				Utils::Log(LOG_ERR, $sMessage);
				throw $e;
			}
		}
		Utils::Log(LOG_INFO, $sMessage);
		vSphereLogicalInterfaceCollector::UseTeemIpNME($bTeemIpNMEIsInstalled);
	} else {
		Utils::Log(LOG_INFO, 'Logical interfaces will NOT be collected');
	}
} else {
	Utils::Log(LOG_INFO, $sTeemIpMessage);
	Orchestrator::AddCollector($iRank++, 'vSphereServerCollector');
	Orchestrator::AddCollector($iRank++, 'vSphereHypervisorCollector');
	Orchestrator::AddCollector($iRank++, 'vSphereVirtualMachineCollector');
}

