<?php
require_once(APPROOT.'collectors/src/ConfigurableCollector.class.inc.php');

class vSphereCollector extends ConfigurableCollector
{
	protected $oCollectionPlan;

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
		// Store information that vSphereFarmCollector is activated or not
		if (array_key_exists('vSphereFarmCollector', $aOrchestratedCollectors) && ($aOrchestratedCollectors['vSphereFarmCollector'] == true)) {
			$this->oCollectionPlan->SetFarmToBeCollected(true);
		} else {
			$this->oCollectionPlan->SetFarmToBeCollected(false);
		}

		// Check if Virtualization mgmt module is installed
		if ($this->oCollectionPlan->IsVirtualizationMgmtInstalled()) {
			return true;
		} else {
			Utils::Log(LOG_INFO, '> '.get_class($this).' will not be launched as Virtualization Management Module is not installed on iTop !');
		}

		return false;
	}

	protected static function myprint_r($var)
	{
		$s = '';
		foreach ($var as $key => $val) {
			if (is_object($val)) {
				$sVal = 'object['.get_class($val).']';
			} else {
				$sVal = $val;
			}
			$s .= "\t".$key." => ".$sVal."\n";
		}

		return $s;
	}

	/**
	 * Check the SSL connection to the given host
	 *
	 * @param string $sHost The host/uri to connect to (e.g. 192.168.10.12:443)
	 *
	 * @return boolean
	 */
	protected static function CheckSSLConnection($sHost)
	{
		$errno = 0;
		$errstr = 'No error';
		$fp = @stream_socket_client('ssl://'.$sHost, $errno, $errstr, 5);
		if (($fp === false) && ($errno === 0)) {
			// Failed to connect, check for SSL certificate problems
			$aStreamContextOptions = array(
				'ssl' => array(
					'verify_peer' => 0,
					'verify_peer_name' => 0,
					'allow_self_signed' => 1,
				),
			);
			$context = stream_context_create($aStreamContextOptions);
			$fp = @stream_socket_client('ssl://'.$sHost, $errno, $errstr, 5, STREAM_CLIENT_CONNECT, $context);
			if ($fp === false) {
				Utils::Log(LOG_CRIT, "Failed to connect to https://$sHost (Error $errno: $errstr)");

				return false;
			} else {
				Utils::Log(LOG_CRIT,
					"Failed to connect to https://$sHost - Invalid SSL certificate.\nYou can add the following 'vsphere_connection_options' to your configuration file (conf/params.local.xml) to bypass this check:\n<vsphere_connection_options>\n\t<ssl>\n\t\t<verify_peer>0</verify_peer>\n\t\t<verify_peer_name>0</verify_peer_name>\n\t\t<allow_self_signed>1</allow_self_signed>\n\t</ssl>\n</vsphere_connection_options>\n");

				return false;
			}
		} else {
			if ($fp === false) {
				Utils::Log(LOG_CRIT, "Failed to connect to https://$sHost (Error $errno: $errstr)");

				return false;
			}
		}
		Utils::Log(LOG_DEBUG, "Connection to https://$sHost Ok.");

		return true; // Ok this works
	}

	protected static function InitVmwarephp()
	{
		require_once APPROOT.'collectors/library/Vmwarephp/Autoloader.php';
		$autoloader = new \Vmwarephp\Autoloader();
		$autoloader->register();

		// Set default stream context options, see http://php.net/manual/en/context.php for the possible options
		$aStreamContextOptions = Utils::GetConfigurationValue('vsphere_connection_options', array());

		Utils::Log(LOG_DEBUG, "vSphere connection options: ".print_r($aStreamContextOptions, true));

		$default = stream_context_set_default($aStreamContextOptions);
	}

	public static function GetCustomFields($sClass)
	{
		$aCustomFields = array();
		$aCustomSynchro = Utils::GetConfigurationValue('custom_synchro', array());
		if (array_key_exists($sClass, $aCustomSynchro)) {
			foreach ($aCustomSynchro[$sClass]['fields'] as $sAttCode => $aFieldsDef) {
				// Check if the configuration contains an alteration of the JSON
				if (array_key_exists('source', $aFieldsDef)) {
					$aCustomFields[$sAttCode] = $aFieldsDef['source'];
				}
			}
		}

		return $aCustomFields;
	}


}
