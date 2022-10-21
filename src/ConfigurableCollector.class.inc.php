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
