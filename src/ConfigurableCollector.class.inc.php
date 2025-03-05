<?php

/**
 * A Collector which definition (the JSON file) can be modified
 * via configuration parameters to change the behavior of certain fields
 *
 * Note: inheriting from this class makes the Synchro Data Source configurable
 *       but does not "magically" extend the collection mechanism to collect new/different data
 */
abstract class ConfigurableCollector extends Collector
{
	/**
	 * Alters the definition of the synchro data source with the parameters (if any)
	 * The syntax for the parameters is the following (the applicable part is under the <json> tag):
	 * <custom_synchro>
	 *   <vSphereHypervisorCollector>
	 *     <fields>
	 *       <server_id>
	 *         <source>hardware->systemInfo->otherIdentifyingInfo[ServiceTag]</source>
	 *         <json>
	 *           <reconciliation_attcode>serialnumber</reconciliation_attcode>
	 *         </json>
	 *       </server_id>
	 *     </fields>
	 *   </vSphereHypervisorCollector>
	 * </custom_synchro>
	 * {@inheritDoc}
	 *
	 * @see Collector::GetSynchroDataSourceDefinition()
	 */
	public function GetSynchroDataSourceDefinition($aPlaceHolders = array())
	{
		$this->sSynchroDataSourceDefinitionFile = $this->GetSynchroDataSourceDefinitionFile();
		if (file_exists($this->sSynchroDataSourceDefinitionFile)) {
			$sSynchroDataSourceDefinition = file_get_contents($this->sSynchroDataSourceDefinitionFile);

			$aCustomSynchro = Utils::GetConfigurationValue('custom_synchro', array());
			if (array_key_exists(get_class($this), $aCustomSynchro)) {
				// Decode the JSON for an easier edition
				$aSynchroDefinition = json_decode($sSynchroDataSourceDefinition, true);
				$aAttCodeIndex = array();
				foreach ($aSynchroDefinition['attribute_list'] as $idx => $aDef) {
					$aAttCodeIndex[$aDef['attcode']] = $idx;
				}
				if (isset($aCustomSynchro[get_class($this)]['fields']) && is_array($aCustomSynchro[get_class($this)]['fields'])) {
					foreach ($aCustomSynchro[get_class($this)]['fields'] as $sAttCode => $aFieldsDef) {
						// Check if the configuration contains an alteration of the JSON
						if (array_key_exists('json', $aFieldsDef)) {
							Utils::Log(LOG_INFO, get_class($this)." uses a custom definition for the field $sAttCode of the Synchro Data Source.");
							// Override the definitions from the JSON by the ones given in the configuration
							foreach ($aFieldsDef['json'] as $sKey => $sValue) {
								$idx = $aAttCodeIndex[$sAttCode];
								$aSynchroDefinition['attribute_list'][$idx][$sKey] = $sValue;
							}
						}
						if (array_key_exists('source', $aFieldsDef)) {
							Utils::Log(LOG_INFO, get_class($this)." uses a custom collection for the field $sAttCode ({$aFieldsDef['source']}).");
						}
					}
				}  else {
					// warn if there is no 'fields' in the class configuration
					// is this warning necessary?
					Utils::Log(LOG_DEBUG, "No valid 'fields' array found for class ".get_class($this)." in the custom_synchro configuration.");
				}

				// general options for this collector
				// found in my version of the 1.0.16 collector, don't know if this came upstream or if this is
				// already a custom addition (Schirrms 2025-03-05)
				// user_delete_policy
				if (array_key_exists('user_delete_policy', $aCustomSynchro[get_class($this)])) {
					$sUserDelete = $aCustomSynchro[get_class($this)]['user_delete_policy'];
					Utils::Log(LOG_INFO, get_class($this)." has a specific user_delete_policy as '$sUserDelete'.");
					// only possible values : nobody|administrators|everybody
					if (strpos('nobody|administrators|everybody', $sUserDelete) !== false) {
						$aSynchroDefinition['user_delete_policy'] = $sUserDelete;
					}
				}
				// delete_policy
				if (array_key_exists('delete_policy', $aCustomSynchro[get_class($this)])) {
					$sDelete = $aCustomSynchro[get_class($this)]['delete_policy'];
					Utils::Log(LOG_INFO, get_class($this)." has a specific delete_policy as '$sDelete'.");
					// only possible values : ignore|delete|update|update_then_delete
					if (strpos('ignore|delete|update|update_then_delete', $sDelete) !== false) {
						$aSynchroDefinition['delete_policy'] = $sDelete;
					}
				}
				// delete_policy_update
				if (array_key_exists('delete_policy_update', $aCustomSynchro[get_class($this)])) {
					$sDeleteUpdate = $aCustomSynchro[get_class($this)]['delete_policy_update'];
					Utils::Log(LOG_INFO, get_class($this)." has a specific delete_policy_update as '$sDeleteUpdate'.");
					// No real test possible here, but we can check if the value is not empty
					if (!empty($sDeleteUpdate)) {
						$aSynchroDefinition['delete_policy_update'] = $sDeleteUpdate;
					}
				}
				// full_load_periodicity (integer value in seconds)
				if (array_key_exists('full_load_periodicity', $aCustomSynchro[get_class($this)]))	{
					$sFullLoadPeriodicity = $aCustomSynchro[get_class($this)]['full_load_periodicity'];
					Utils::Log(LOG_INFO, get_class($this)." has a specific delete_policy_retention as '$sFullLoadPeriodicity'.");
					// the value must be an integer value (no decimal part)
					if (is_numeric($sFullLoadPeriodicity) && intval($sFullLoadPeriodicity) == $sFullLoadPeriodicity) {
						$aSynchroDefinition['full_load_periodicity'] = $sFullLoadPeriodicity;
					}
				}
				// delete_policy_retention (integer value in seconds)
				if (array_key_exists('delete_policy_retention', $aCustomSynchro[get_class($this)])) {
					$sDeleteRetention = $aCustomSynchro[get_class($this)]['delete_policy_retention'];
					Utils::Log(LOG_INFO, get_class($this)." has a specific delete_policy_retention as '$sDeleteRetention'.");
					// the value must be an integer value (no decimal part)
					if (is_numeric($sDeleteRetention) && intval($sDeleteRetention) == $sDeleteRetention) {
						$aSynchroDefinition['delete_policy_retention'] = $sDeleteRetention;
					}
				}
				// Placeholder for custom configuration not yet held by the collector
				// We have to read all keys in $aCustomSynchro[get_class($this)], and if not in one of the previous cases
				// we set a warning with the key, the value, and explaining that this key is not yet managed
				foreach ($aCustomSynchro[get_class($this)] as $sKey => $sValue) {
					if (!in_array($sKey, array('fields', 'user_delete_policy', 'delete_policy', 'delete_policy_update', 'full_load_periodicity', 'delete_policy_retention'))) {
						Utils::Log(LOG_WARNING, "The custom value '$sKey' with value '$sValue' is not yet managed for the collector ".get_class($this).".");
					}
				}

				// Re-encode back to JSON since we are expected to return the JSON as a string
				$sSynchroDataSourceDefinition = json_encode($aSynchroDefinition);
				Utils::Log(LOG_DEBUG, "Custom definition for the Synchro Data Source:\n$sSynchroDataSourceDefinition");
			}

			// Now process placeholders
			$aPlaceHolders['$version$'] = $this->GetVersion();
			$sSynchroDataSourceDefinition = str_replace(array_keys($aPlaceHolders), array_values($aPlaceHolders), $sSynchroDataSourceDefinition);
		} else {
			$sSynchroDataSourceDefinition = false;
		}

		return $sSynchroDataSourceDefinition;
	}
}
