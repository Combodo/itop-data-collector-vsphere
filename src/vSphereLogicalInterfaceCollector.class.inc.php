<?php
require_once(APPROOT.'collectors/src/vSphereCollector.class.inc.php');

class vSphereLogicalInterfaceCollector extends vSphereCollector
{
	protected $idx;
	protected $oVMLookup;
	static protected bool $bLogicalInterfacesCollected = false;
	static protected array $aLogicalInterfaces = [];
	static protected bool $bLnkLogicalInterfaceToIPAddressCollected = false;
	static protected array $aLnkLogicalInterfaceToIPAddress = [];

	/**
	 * @inheritdoc
	 */
	public function AttributeIsOptional($sAttCode)
	{
        if ($this->oCollectionPlan->IsTeemIpInstalled()) {
            if ($sAttCode == 'ipaddress') return true;
            if ($sAttCode == 'ipgateway') return true;
            if ($sAttCode == 'ipmask') return true;
            if ($sAttCode == 'speed') return true;
        } else {
            if ($sAttCode == 'interfacespeed_id') return true;
            if ($sAttCode == 'ip_list') return true;
            if ($sAttCode == 'layer2protocol_id') return true;
            if ($sAttCode == 'status') return true;
            if ($sAttCode == 'vlans_list') return true;
            if ($sAttCode == 'vrfs_list') return true;
        }

		return parent::AttributeIsOptional($sAttCode);
	}

	static public function GetLogicalInterfaces()
	{
		if (!self::$bLogicalInterfacesCollected) {
			self::$bLogicalInterfacesCollected = true;
			$aVMs = vSphereVirtualMachineCollector::CollectVMInfos();

			$aLogicalInterfaces = array();
			foreach ($aVMs as $oVM) {
				$aInterfaces = $oVM['interfaces'];
				foreach ($aInterfaces as $oInterface) {
					$sMac = $oInterface['mac'];
					Utils::Log(LOG_DEBUG, 'Reading interface information related to MAC @: '.$sMac);
					$aLogicalInterfaces[] = array(
						'macaddress' => $sMac,
						'name' => $oInterface['network'],
						'virtualmachine_orgid' => $oVM['org_id'],
						'virtualmachine_id' => $oVM['name'],
						'ip' => $oInterface['ip'] ?? '',
					);
				}
			}

			// Change array with correct ip_lists
			$aFinalLogicalInterfaces = array();
			$aLnkLogicalInterfaceToIPAddress = array();
			foreach ($aLogicalInterfaces as $sLogicalInterface => $aValue) {
				$sKey = array_search($aValue['macaddress'], array_column($aFinalLogicalInterfaces, 'macaddress'));
				if ($sKey === false) {
					$aFinalLogicalInterfaces[] = array(
						'macaddress' => $aValue['macaddress'],
						'name' => $aValue['name'],
						'virtualmachine_orgid' => $aValue['virtualmachine_orgid'],
						'virtualmachine_id' => $aValue['virtualmachine_id'],
                        'ip' => $aValue['ip'],
					);
				}

                if (!empty($aValue['ip'])) {
                    $aLnkLogicalInterfaceToIPAddress[] = array(
                        'ipinterface_id' => $aValue['macaddress'],
                        'ipaddress_id' => $aValue['ip'],
                    );
                }
			}

			self::$aLogicalInterfaces = $aFinalLogicalInterfaces;
			self::$aLnkLogicalInterfaceToIPAddress = $aLnkLogicalInterfaceToIPAddress;
		}

		return self::$aLogicalInterfaces;
	}

	static public function GetLnks()
	{
		if (!self::$bLnkLogicalInterfaceToIPAddressCollected) {
			self::$bLnkLogicalInterfaceToIPAddressCollected = true;
			self::GetLogicalInterfaces();
		}

		return self::$aLnkLogicalInterfaceToIPAddress;
	}

	protected function InitProcessBeforeSynchro()
	{
		// Retrieve the identifiers of the VMs since we must do a lookup based on two fields: org_id and name
		// which is not supported by the iTop Data Synchro... so let's do the job of an ETL
		$this->oVMLookup = new LookupTable('SELECT VirtualMachine', array('name'));
	}

	protected function ProcessLineBeforeSynchro(&$aLineData, $iLineIndex)
	{
		// Process each line of the CSV
		$bRet = $this->oVMLookup->Lookup($aLineData, array('virtualmachine_id'), 'virtualmachine_id', $iLineIndex);

		return $bRet;
	}

	public function Prepare()
	{
		$bRet = parent::Prepare();
		if (!$bRet) {
			return false;
		}

		self::GetLogicalInterfaces();

		$this->idx = 0;

		return true;
	}

	public function Fetch()
	{
		if ($this->idx < count(self::$aLogicalInterfaces)) {
			$aLogicalInterfaces = self::$aLogicalInterfaces[$this->idx++];

            if ($this->oCollectionPlan->IsTeemIpInstalled()) {
                return array(
                    'primary_key' => $aLogicalInterfaces['macaddress'],
                    'macaddress' => $aLogicalInterfaces['macaddress'],
                    'name' => $aLogicalInterfaces['name'],
                    'virtualmachine_id' => $aLogicalInterfaces['virtualmachine_id'],
                );

            } else {
                return array(
                    'primary_key' => $aLogicalInterfaces['macaddress'],
                    'ipaddress' => $aLogicalInterfaces['ip'],
                    'macaddress' => $aLogicalInterfaces['macaddress'],
                    'name' => $aLogicalInterfaces['name'],
                    'virtualmachine_id' => $aLogicalInterfaces['virtualmachine_id'],
                );
            }
		}

		return false;
	}
}