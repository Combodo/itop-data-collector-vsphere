<?php
Orchestrator::AddCollector(1, 'vSphereServerCollector');
//Orchestrator::AddCollector(1, 'MyCollector');

/*
class MyCollector extends Collector
{
	protected $idx;
	
	public function Prepare()
	{
		$bResult = parent::Prepare();
		$this->idx = 0;
		return $bResult;
	}
	
	public function Fetch()
	{
		if ($this->idx < 15)
		{
			$this->idx++;
			return array('primary_key' => $this->idx, 'name' => 'Server (11th rename) '.$this->idx, 'org_id' => 'Demo', 'description' => 'Test Collector (changed VI)');
		}
		return false;
	}
}
*/

class vSphereServerCollector extends Collector
{
	protected $idx;
	protected $aVMs;
	
	public function Prepare()
	{
		parent::Prepare();
		require_once APPROOT.'collector/library/Vmwarephp/Autoloader.php';
		$autoloader = new \Vmwarephp\Autoloader;
		$autoloader->register();

		$sVSphereServer = Utils::ReadParameter('vsphere_uri', '192.168.10.12:443');
		$sLogin = Utils::ReadParameter('vsphere_login', 'administrateur');;
		$sPassword = Utils::ReadParameter('vsphere_password', 'c8mb0doSARL');	
		
		$fStartTime = microtime(true);
		$this->aVMs = array();
		$this->idx = 0;
		$vhost = new \Vmwarephp\Vhost($sVSphereServer, $sLogin, $sPassword);	
		
		$aVirtualMachines = $vhost->findAllManagedObjects('VirtualMachine', array('config', 'runtime', 'guest', 'network', 'storage'));
		
		foreach($aVirtualMachines as $oVirtualMachine)
		{
			$this->aVMs[] = array(
					'id' => $oVirtualMachine->getReferenceId(),
					'name' => $oVirtualMachine->name,
					'ip' => $oVirtualMachine->guest->ipAddress,
					'num_cpu' => $oVirtualMachine->config->hardware->numCPU,
					'memory' => $oVirtualMachine->config->hardware->memoryMB,
			);
			/*
			echo "======================================\n";
			echo "Virtual Machine: ".$oVirtualMachine->getReferenceId()."\n";
			echo "\tName          : ".$oVirtualMachine->name."\n";
			echo "\tRuntime status: ".$oVirtualMachine->runtime->powerState."\n";
			echo "\tGuest OS name : ".$oVirtualMachine->config->name."\n";
			echo "\tGuest OS info : ".$oVirtualMachine->config->guestFullName."\n";
			echo "\tOS family     : ".$oVirtualMachine->guest->guestFamily."\n";
			echo "\tOS full name  : ".$oVirtualMachine->guest->guestFullName."\n";
			echo "\tOS ID         : ".$oVirtualMachine->guest->guestId."\n";
			echo "\tFiles         :\n";
			echo "\t    vmPathName: ".$oVirtualMachine->config->files->vmPathName."\n";
			echo "\tHardware      :\n";
			echo "\t    # of CPUs : ".$oVirtualMachine->config->hardware->numCPU."\n";
			echo "\t    Memory(MB): ".$oVirtualMachine->config->hardware->memoryMB."\n";
			echo "\tIP address    : ".$oVirtualMachine->guest->ipAddress."\n";
			echo "\tHostname      : ".$oVirtualMachine->guest->hostName."\n";
			$idx = 0;
			if ($oVirtualMachine->guest->disk)
			{
				echo "\tDisks         :\n";
				foreach($oVirtualMachine->guest->disk as $oDiskInfo)
				{
					$idx++;
					echo "\tDisk#$idx\n";
					echo "\t\t Disk Path: ".$oDiskInfo->diskPath."\n";
					echo "\t\t  Capacity: ".HumanReadableSize($oDiskInfo->capacity)."\n";			
					echo "\t\t    % used: ".sprintf('%.2f', 100.0*($oDiskInfo->capacity - $oDiskInfo->freeSpace) / $oDiskInfo->capacity)." %\n";			
					echo "\t\tFree Space: ".HumanReadableSize($oDiskInfo->freeSpace)."\n";			
				}
			}
			if ($oVirtualMachine->storage->perDatastoreUsage)
			{
				echo "\tDatastores\n";
				foreach($oVirtualMachine->storage->perDatastoreUsage as $oVMUsageOnDatastore)
				{
					$idx++;
					echo "\tDatastore: ".$oVMUsageOnDatastore->datastore->name."\n";
					echo "\t\tCommitted: ".HumanReadableSize($oVMUsageOnDatastore->committed)."\n";
					echo "\t\tUncommmitted: ".HumanReadableSize($oVMUsageOnDatastore->uncommitted)."\n";
					echo "\t\tUnshared: ".HumanReadableSize($oVMUsageOnDatastore->unshared)."\n";
				}
			}
			$idx = 0;
			if ($oVirtualMachine->guest->net)
			{
				echo "\tNetwork Interface Cards :\n";
				foreach($oVirtualMachine->guest->net as $oNICInfo)
				{
					echo "\tNIC#$idx\n";
					echo "\t\t  Connected: ".($oNICInfo->connected ? 'Yes' : 'No')."\n";
					echo "\t\tMAC Address: ".$oNICInfo->macAddress."\n";				
					echo "\t\t    Network: ".$oNICInfo->network."\n";
					if ($oNICInfo->ipConfig && $oNICInfo->ipConfig->ipAddress)
					{
						foreach($oNICInfo->ipConfig->ipAddress as $oIPInfo)
						{
							if (strpos($oIPInfo->ipAddress, ':') !== false)
							{
								echo "\t\t       IPv6: ".$oIPInfo->ipAddress."/{$oIPInfo->prefixLength}\n";
							}
							else
							{
								echo "\t\t       IPv4: ".$oIPInfo->ipAddress."/{$oIPInfo->prefixLength}\n";
							}
						}
					}
					$idx++;
				}
			}
			*/
		}		
	}
	
	public function Fetch()
	{
		if ($this->idx < count($this->aVMs))
		{
			$aVM = $this->aVMs[$this->idx++];
			return array('primary_key' => $aVM['id'], 'name' => $aVM['name'], 'org_id' => 'Demo', 'ram' => $aVM['memory'], 'cpu' => $aVM['num_cpu'],  'managementip' => $aVM['ip']);
		}
		return false;
	}
}