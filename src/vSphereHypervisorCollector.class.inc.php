<?php
require_once(APPROOT.'collectors/src/vSphereCollector.class.inc.php');

class vSphereHypervisorCollector extends vSphereCollector
{
	protected $idx;
	protected $aHypervisorFields;
	static protected $aHypervisors = null;

	public function __construct()
	{
		parent::__construct();
		$aDefaultFields = array('primary_key', 'name', 'org_id', 'status', 'server_id', 'farm_id', 'uuid', 'hostid');
		$aCustomFields = array_keys(static::GetCustomFields(__CLASS__));
		$this->aHypervisorFields = array_merge($aDefaultFields, $aCustomFields);

	}

	/**
	 * @inheritdoc
	 */
	public function CheckToLaunch(array $aOrchestratedCollectors): bool
	{
		if (array_key_exists('vSphereFarmCollector',$aOrchestratedCollectors) && ($aOrchestratedCollectors['vSphereFarmCollector'] == true)) {
			return true;
		} else {
			Utils::Log(LOG_INFO, '> vSphereHypervisorCollector will not be launched as vSphereFarmCollector is required but is not launched');
		}

		return false;
	}

	public function AttributeIsOptional($sAttCode)
	{
		if ($sAttCode == 'services_list') return true;
		if ($sAttCode == 'providercontracts_list') return true;
		if ($this->oCollectionPlan->IsCbdVMwareDMInstalled()) {
			if ($sAttCode == 'uuid') return false;
			if ($sAttCode == 'hostid') return false;
		} else {
			if ($sAttCode == 'uuid') return true;
			if ($sAttCode == 'hostid') return true;
		}

		return parent::AttributeIsOptional($sAttCode);
	}

	public static function GetHypervisors()
	{
		if (self::$aHypervisors === null) {
			$oBrandMappings = new MappingTable('brand_mapping');
			$oModelMappings = new MappingTable('model_mapping');
			$oOSFamilyMappings = new MappingTable('os_family_mapping');
			$oOSVersionMappings = new MappingTable('os_version_mapping');

			$sVSphereServer = Utils::GetConfigurationValue('vsphere_uri', '');
			$sLogin = Utils::GetConfigurationValue('vsphere_login', '');
			$sPassword = Utils::GetConfigurationValue('vsphere_password', '');
			$sDefaultOrg = Utils::GetConfigurationValue('default_org_id');
			$sVMCPUAttribute = 'numCpuCores';
			$aVMParams = Utils::GetConfigurationValue('virtual_machine', []);
			if (!empty($aVMParams) && array_key_exists('cpu_attribute', $aVMParams) && ($aVMParams['cpu_attribute'] != '')) {
				$sVMCPUAttribute = $aVMParams['cpu_attribute'];
			}

			static::InitVmwarephp();
			if (!static::CheckSSLConnection($sVSphereServer)) {
				throw new Exception("Cannot connect to https://$sVSphereServer. Aborting.");
			}

			$aFarms = vSphereFarmCollector::GetFarms();

			self::$aHypervisors = array();
			$vhost = new \Vmwarephp\Vhost($sVSphereServer, $sLogin, $sPassword);

			$aHypervisors = $vhost->findAllManagedObjects('HostSystem', array('hardware', 'summary'));

			foreach ($aHypervisors as $oHypervisor) {
				if ($oHypervisor->runtime->connectionState !== 'connected') {
					// The documentation says that 'config' ".. might not be available for a disconnected host"
					// A customer reported that trying to access ->config->... causes a segfault !!
					// So let's skip such hypervisors for now
					Utils::Log(LOG_INFO, "Skipping Hypervisor {$oHypervisor->name} which is NOT connected (runtime->connectionState = '{$oHypervisor->runtime->connectionState}')");
					continue;
				}

				$sFarmName = '';
				// Is the hypervisor part of a farm ?

				foreach ($aFarms as $aFarm) {
					if (in_array($oHypervisor->name, $aFarm['hosts'])) {
						$sFarmName = $aFarm['name'];
						break; // farm found
					}
				}

				Utils::Log(LOG_DEBUG, "Server {$oHypervisor->name}: {$oHypervisor->hardware->systemInfo->vendor} {$oHypervisor->hardware->systemInfo->model}");
				Utils::Log(LOG_DEBUG, "Server software: {$oHypervisor->config->product->fullName} - API Version: {$oHypervisor->config->product->apiVersion}");

				$aHypervisorData = array(
					'id' => $oHypervisor->getReferenceId(),
					'primary_key' => $oHypervisor->getReferenceId(),
					'name' => $oHypervisor->name,
					'org_id' => $sDefaultOrg,
					'brand_id' => $oBrandMappings->MapValue($oHypervisor->hardware->systemInfo->vendor, 'Other'),
					'model_id' => $oModelMappings->MapValue($oHypervisor->hardware->systemInfo->model, ''),
					'cpu' => ($oHypervisor->hardware->cpuInfo->$sVMCPUAttribute) ?? '',
					'ram' => (int)($oHypervisor->hardware->memorySize / (1024*1024)),
					'osfamily_id' => $oOSFamilyMappings->MapValue($oHypervisor->config->product->name, 'Other'),
					'osversion_id' => $oOSVersionMappings->MapValue($oHypervisor->config->product->fullName, ''),
					'status' => 'production',
					'farm_id' => $sFarmName,
					'server_id' => $oHypervisor->name,
				);

				$oCollectionPlan = vSphereCollectionPlan::GetPlan();
				if ($oCollectionPlan->IsCbdVMwareDMInstalled()) {
					$aHypervisorData['uuid'] = ($oHypervisor->hardware->systemInfo->uuid) ?? '';
					$aHypervisorData['hostid'] = $oHypervisor->getReferenceId();
				}

				foreach (static::GetCustomFields(__CLASS__) as $sAttCode => $sFieldDefinition) {
					$aHypervisorData[$sAttCode] = static::GetCustomFieldValue($oHypervisor, $sFieldDefinition);
				}

				// Hypervisors and Servers actually share the same collector mechanism
				foreach (static::GetCustomFields('vSphereServerCollector') as $sAttCode => $sFieldDefinition) {
					$aHypervisorData['server-custom-'.$sAttCode] = static::GetCustomFieldValue($oHypervisor, $sFieldDefinition);
				}

				self::$aHypervisors[] = $aHypervisorData;
			}
		}

		return self::$aHypervisors;
	}

	protected static function GetCustomFieldValue($oHypervisor, $sFieldDefinition)
	{
		$value = '';
		$aMatches = array();
		if (preg_match('/^hardware->systemInfo->otherIdentifyingInfo\\[(.+)\\]$/', $sFieldDefinition, $aMatches)) {
			$bFound = false;
			// Special case for HostSystemIdentificationInfo object
			foreach ($oHypervisor->hardware->systemInfo->otherIdentifyingInfo as $oValue) {
				if ($oValue->identifierType->key == $aMatches[1]) {
					$value = $oValue->identifierValue;
					$bFound = true;
					break;
				}
			}
			// Item not found
			if (!$bFound) {
				Utils::Log(LOG_WARNING, "Field $sFieldDefinition not found for Hypervisor '{$oHypervisor->name}'");
			}
		} else {
			eval('$value = $oHypervisor->'.$sFieldDefinition.';');
		}

		return $value;
	}

	public function Prepare()
	{
		$bRet = parent::Prepare();
		if (!$bRet) {
			return false;
		}

		self::GetHypervisors();

		$this->idx = 0;

		return true;
	}

	public function Fetch()
	{
		if ($this->idx < count(self::$aHypervisors)) {
			$aHV = self::$aHypervisors[$this->idx++];
			$aResult = array();
			foreach ($this->aHypervisorFields as $sAttCode) {
				$aResult[$sAttCode] = $aHV[$sAttCode];
			}

			return $aResult;
		}

		return false;
	}

}
