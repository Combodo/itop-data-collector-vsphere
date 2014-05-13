<?php
function HumanReadableSize($fBytes)
{
	$aSizes = array('bytes', 'Kb', 'Mb', 'Gb', 'Tb', 'Pb', 'Hb');
	$index = 0;
	while (($fBytes > 1000) && ($index < count($aSizes)))
	{
		$index++;
		$fBytes = $fBytes / 1000;
	}
	
	return sprintf('%.2f %s', $fBytes, $aSizes[$index]);
}

/**
 * Simple test script for the vSphere webservices
 */
if ($argc != 4)
{
	echo "\nTest script to retrieve information from a vSphere server.\n\n";
	echo "Usage:\n";
	echo "php test.php <vsphere_server:port> <login> <password>\n\n";
	echo "Example:\n";
	echo "php test.php 192.168.10.12:443 administrateur s3cr3t\n\n";
	exit -1;
}
else
{
	$sVSphereServer = $argv[1];
	$sLogin = $argv[2];
	$sPassword = $argv[3];
}


/**
 *
 * Useful VMWare reference: http://www.vmware.com/support/developer/vc-sdk/visdk41pubs/ApiReference/
 *
 */
try
{
	require_once './library/Vmwarephp/Autoloader.php';
	$autoloader = new \Vmwarephp\Autoloader;
	$autoloader->register();
	
	$fStartTime = microtime(true);
	$vhost = new \Vmwarephp\Vhost($sVSphereServer, $sLogin, $sPassword);	
	$aHosts = $vhost->findAllManagedObjects('HostSystem', array('hardware', 'summary'));
	
	echo "\n";
	echo "**************************************\n";
	echo "*             H O S T S              *\n";
	echo "**************************************\n";
	
	foreach($aHosts as $oHost)
	{
		echo "======================================\n";
		echo "Name           : ".$oHost->name."\n";
		echo "ID             : ".$oHost->getReferenceId()."\n";
		echo "Vendor         : ".$oHost->hardware->systemInfo->vendor."\n";
		echo "Model          : ".$oHost->hardware->systemInfo->model."\n";
		echo "Number of CPUs : ".$oHost->hardware->cpuInfo->numCpuPackages."\n";
		echo "Frequency      : ".$oHost->hardware->cpuInfo->hz." (Hz)\n";
		echo "Nb of Threads  : ".$oHost->hardware->cpuInfo->numCpuThreads."\n";
		echo "Nb of Cores    : ".$oHost->hardware->cpuInfo->numCpuCores."\n";
		echo "Total Memory   : ".$oHost->hardware->memorySize." (bytes)\n";
		echo "OS Family      : ".$oHost->config->product->name."\n";
		echo "OS Version     : ".$oHost->config->product->fullName."\n";
		$aVMs = array();
		foreach($oHost->vm as $oVM)
		{
			$aVMs[] = $oVM->name;
		}
		echo "Virtual Machines: ".implode(', ', $aVMs)."\n";		
	}
	echo "======================================\n\n";
	
	
	$aDataStores = $vhost->findAllManagedObjects('Datastore', array('summary'));
	
	echo "\n";
	echo "**************************************\n";
	echo "*       D A T A S T O R E S          *\n";
	echo "**************************************\n";
	
	foreach($aDataStores as $oDataStore)
	{
		$oSummary = $oDataStore->summary;
		echo "======================================\n";
		echo "Name           : ".$oSummary->name."\n";
		echo "ID             : ".$oDataStore->getReferenceId()."\n";
		echo "Capacity       : ".$oSummary->capacity."\n";
		echo "Accessible     : ".$oSummary->accessible."\n";
		echo "Free space     : ".$oSummary->freeSpace."\n";
		echo "Type           : ".$oSummary->type."\n";
	
		$aHosts = $oDataStore->getConnectedHosts();
		echo "Used by (Hosts): ";
		$aUsedByHosts = array();
		foreach($aHosts as $oHost)
		{
			$aUsedByHosts[] = $oHost->name.' ('.$oHost->getReferenceId().')';
		}
		echo implode(', ', $aUsedByHosts)."\n";
		$aVMs = $oDataStore->getVirtualMachinesInstalledOnThisDatastore();
		$aUsedByVMs = array();
		echo "Used by (VMs)  : ";
		foreach($aVMs as $oVirtualMachine)
		{
			$aUsedByVMs[] = $oVirtualMachine->name.' ('.$oVirtualMachine->getReferenceId().')';
		}
		echo implode(', ', $aUsedByVMs)."\n";
	}
	echo "======================================\n\n";
	
	$aVirtualMachines = $vhost->findAllManagedObjects('VirtualMachine', array('config', 'runtime', 'guest', 'network', 'storage'));
	
	echo "**************************************\n";
	echo "*  V I R T U A L   M A C H I N E S   *\n";
	echo "**************************************\n";
	
	foreach($aVirtualMachines as $oVirtualMachine)
	{
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
	}
	echo "======================================\n";
	$aClusters = $vhost->findAllManagedObjects('ClusterComputeResource', array('configurationEx'));

        echo "*******************************************\n";
        echo "*  C L U S T E R  *\n";
        echo "*******************************************\n";

        foreach($aClusters as $oCluster)
        {
                echo "======================================\n";
                echo "{$oCluster->name}\n";
		$aHosts = array();
		foreach($oCluster->host as $oHost)
		{
			$aHosts[] = $oHost->name;
		}
		echo "Hosts: ".implode(', ', $aHosts)."\n";		
	}
        echo "*******************************************\n";
	echo "Total execution time: ".sprintf('%.3f s', microtime(true) - $fStartTime)."\n";
}
catch(Exception $e)
{
	echo "Error: ".$e->getMessage()."\n\n";
}
