<?php

class PhpDynamicProperties {
    private array $aProperties = [];

    public function __set(string $name, mixed $value): void {
        $this->aProperties[$name] = $value;
    }

    public function __get(string $name): mixed {
        return (array_key_exists($name, $this->aProperties) ? $this->aProperties[$name]: null);
    }
}

class DynamicArray extends phpDynamicProperties {
	public $dynamicType; //string
	public $val; //anyType

	function __construct($dynamicType = null, $val = null) {
		$this->dynamicType = $dynamicType;
		$this->val = $val;
	}
}

class DynamicData extends phpDynamicProperties {
	public $dynamicType; //string
	public $dynamicProperty; //DynamicProperty

	function __construct($dynamicType = null, $dynamicProperty = null) {
		$this->dynamicType = $dynamicType;
		$this->dynamicProperty = $dynamicProperty;
	}
}

class DynamicProperty extends phpDynamicProperties {
	public $name; //string
	public $val; //anyType

	function __construct($name = null, $val = null) {
		$this->name = $name;
		$this->val = $val;
	}
}

class ArrayOfDynamicProperty extends phpDynamicProperties {
	public $DynamicProperty; //DynamicProperty

	function __construct($DynamicProperty = null) {
		$this->DynamicProperty = $DynamicProperty;
	}
}

class KeyAnyValue extends phpDynamicProperties {
	public $key; //string
	public $value; //anyType

	function __construct($key = null, $value = null) {
		$this->key = $key;
		$this->value = $value;
	}
}

class ArrayOfKeyAnyValue extends phpDynamicProperties {
	public $KeyAnyValue; //KeyAnyValue

	function __construct($KeyAnyValue = null) {
		$this->KeyAnyValue = $KeyAnyValue;
	}
}

class LocalizableMessage extends phpDynamicProperties {
	public $key; //string
	public $arg; //KeyAnyValue
	public $message; //string

	function __construct($key = null, $arg = null, $message = null) {
		$this->key = $key;
		$this->arg = $arg;
		$this->message = $message;
	}
}

class ArrayOfLocalizableMessage extends phpDynamicProperties {
	public $LocalizableMessage; //LocalizableMessage

	function __construct($LocalizableMessage = null) {
		$this->LocalizableMessage = $LocalizableMessage;
	}
}

class HostCommunication extends phpDynamicProperties {
}

class HostNotConnected extends phpDynamicProperties {
}

class HostNotReachable extends phpDynamicProperties {
}

class InvalidArgument extends phpDynamicProperties {
	public $invalidProperty; //string

	function __construct($invalidProperty = null) {
		$this->invalidProperty = $invalidProperty;
	}
}

class InvalidRequest extends phpDynamicProperties {
}

class InvalidType extends phpDynamicProperties {
	public $argument; //string

	function __construct($argument = null) {
		$this->argument = $argument;
	}
}

class ManagedObjectNotFound extends phpDynamicProperties {
	public $obj; //ManagedObjectReference

	function __construct($obj = null) {
		$this->obj = $obj;
	}
}

class MethodNotFound extends phpDynamicProperties {
	public $receiver; //ManagedObjectReference
	public $method; //string

	function __construct($receiver = null, $method = null) {
		$this->receiver = $receiver;
		$this->method = $method;
	}
}

class NotEnoughLicenses extends phpDynamicProperties {
}

class NotImplemented extends phpDynamicProperties {
}

class NotSupported extends phpDynamicProperties {
}

class RequestCanceled extends phpDynamicProperties {
}

class SecurityError extends phpDynamicProperties {
}

class SystemError extends phpDynamicProperties {
	public $reason; //string

	function __construct($reason = null) {
		$this->reason = $reason;
	}
}

class UnexpectedFault extends phpDynamicProperties {
	public $faultName; //string
	public $fault; //LocalizedMethodFault

	function __construct($faultName = null, $fault = null) {
		$this->faultName = $faultName;
		$this->fault = $fault;
	}
}

class LocalizedMethodFault extends phpDynamicProperties {
	public $fault; //MethodFault
	public $localizedMessage; //string

	function __construct($fault = null, $localizedMessage = null) {
		$this->fault = $fault;
		$this->localizedMessage = $localizedMessage;
	}
}

class MethodFault extends phpDynamicProperties {
	public $dynamicType; //string
	public $dynamicProperty; //DynamicProperty
	public $faultCause; //LocalizedMethodFault
	public $faultMessage; //LocalizableMessage

	function __construct($dynamicType = null, $dynamicProperty = null, $faultCause = null, $faultMessage = null) {
		$this->dynamicType = $dynamicType;
		$this->dynamicProperty = $dynamicProperty;
		$this->faultCause = $faultCause;
		$this->faultMessage = $faultMessage;
	}
}

class ArrayOfMethodFault extends phpDynamicProperties {
	public $MethodFault; //MethodFault

	function __construct($MethodFault = null) {
		$this->MethodFault = $MethodFault;
	}
}

class RuntimeFault extends phpDynamicProperties {
}

class ManagedObjectReference extends phpDynamicProperties {
	public $_; //string
	public $type; //string

	function __construct($_ = null, $type = null) {
		$this->_ = $_;
		$this->type = $type;
	}
}

class ArrayOfString extends phpDynamicProperties {
	public $string; //string

	function __construct($string = null) {
		$this->string = $string;
	}
}

class ArrayOfAnyType extends phpDynamicProperties {
	public $anyType; //anyType

	function __construct($anyType = null) {
		$this->anyType = $anyType;
	}
}

class ArrayOfManagedObjectReference extends phpDynamicProperties {
	public $ManagedObjectReference; //ManagedObjectReference

	function __construct($ManagedObjectReference = null) {
		$this->ManagedObjectReference = $ManagedObjectReference;
	}
}

class ArrayOfBoolean extends phpDynamicProperties {
	public $boolean; //boolean

	function __construct($boolean = null) {
		$this->boolean = $boolean;
	}
}

class ArrayOfByte extends phpDynamicProperties {
	public $byte; //byte

	function __construct($byte = null) {
		$this->byte = $byte;
	}
}

class ArrayOfInt extends phpDynamicProperties {
	public $int; //int

	function __construct($int = null) {
		$this->int = $int;
	}
}

class ArrayOfLong extends phpDynamicProperties {
	public $long; //long

	function __construct($long = null) {
		$this->long = $long;
	}
}

class ArrayOfShort extends phpDynamicProperties {
	public $short; //short

	function __construct($short = null) {
		$this->short = $short;
	}
}

class InvalidCollectorVersion extends phpDynamicProperties {
}

class InvalidProperty extends phpDynamicProperties {
	public $name; //string

	function __construct($name = null) {
		$this->name = $name;
	}
}

class PropertyFilterSpec extends phpDynamicProperties {
	public $propSet; //PropertySpec
	public $objectSet; //ObjectSpec
	public $reportMissingObjectsInResults; //boolean

	function __construct($propSet = null, $objectSet = null, $reportMissingObjectsInResults = null) {
		$this->propSet = $propSet;
		$this->objectSet = $objectSet;
		$this->reportMissingObjectsInResults = $reportMissingObjectsInResults;
	}
}

class ArrayOfPropertyFilterSpec extends phpDynamicProperties {
	public $PropertyFilterSpec; //PropertyFilterSpec

	function __construct($PropertyFilterSpec = null) {
		$this->PropertyFilterSpec = $PropertyFilterSpec;
	}
}

class PropertySpec extends phpDynamicProperties {
	public $type; //string
	public $all; //boolean
	public $pathSet; //string

	function __construct($type = null, $all = null, $pathSet = null) {
		$this->type = $type;
		$this->all = $all;
		$this->pathSet = $pathSet;
	}
}

class ArrayOfPropertySpec extends phpDynamicProperties {
	public $PropertySpec; //PropertySpec

	function __construct($PropertySpec = null) {
		$this->PropertySpec = $PropertySpec;
	}
}

class ObjectSpec extends phpDynamicProperties {
	public $obj; //ManagedObjectReference
	public $skip; //boolean
	public $selectSet; //SelectionSpec

	function __construct($obj = null, $skip = null, $selectSet = null) {
		$this->obj = $obj;
		$this->skip = $skip;
		$this->selectSet = $selectSet;
	}
}

class ArrayOfObjectSpec extends phpDynamicProperties {
	public $ObjectSpec; //ObjectSpec

	function __construct($ObjectSpec = null) {
		$this->ObjectSpec = $ObjectSpec;
	}
}

class SelectionSpec extends phpDynamicProperties {
	public $name; //string

	function __construct($name = null) {
		$this->name = $name;
	}
}

class ArrayOfSelectionSpec extends phpDynamicProperties {
	public $SelectionSpec; //SelectionSpec

	function __construct($SelectionSpec = null) {
		$this->SelectionSpec = $SelectionSpec;
	}
}

class TraversalSpec extends SelectionSpec {
	public $type; //string
	public $path; //string
	public $skip; //boolean
	public $selectSet; //SelectionSpec

	function __construct($name = null, $type = null, $path = null, $skip = null, $selectSet = null) {
		parent::__construct($name);
		$this->type = $type;
		$this->path = $path;
		$this->skip = $skip;
		$this->selectSet = $selectSet;
	}
}

class ObjectContent extends phpDynamicProperties {
	public $obj; //ManagedObjectReference
	public $propSet; //DynamicProperty
	public $missingSet; //MissingProperty

	function __construct($obj = null, $propSet = null, $missingSet = null) {
		$this->obj = $obj;
		$this->propSet = $propSet;
		$this->missingSet = $missingSet;
	}
}

class ArrayOfObjectContent extends phpDynamicProperties {
	public $ObjectContent; //ObjectContent

	function __construct($ObjectContent = null) {
		$this->ObjectContent = $ObjectContent;
	}
}

class UpdateSet extends phpDynamicProperties {
	public $version; //string
	public $filterSet; //PropertyFilterUpdate
	public $truncated; //boolean

	function __construct($version = null, $filterSet = null, $truncated = null) {
		$this->version = $version;
		$this->filterSet = $filterSet;
		$this->truncated = $truncated;
	}
}

class PropertyFilterUpdate extends phpDynamicProperties {
	public $filter; //ManagedObjectReference
	public $objectSet; //ObjectUpdate
	public $missingSet; //MissingObject

	function __construct($filter = null, $objectSet = null, $missingSet = null) {
		$this->filter = $filter;
		$this->objectSet = $objectSet;
		$this->missingSet = $missingSet;
	}
}

class ArrayOfPropertyFilterUpdate extends phpDynamicProperties {
	public $PropertyFilterUpdate; //PropertyFilterUpdate

	function __construct($PropertyFilterUpdate = null) {
		$this->PropertyFilterUpdate = $PropertyFilterUpdate;
	}
}

class ObjectUpdate extends phpDynamicProperties {
	public $kind; //ObjectUpdateKind
	public $obj; //ManagedObjectReference
	public $changeSet; //PropertyChange
	public $missingSet; //MissingProperty

	function __construct($kind = null, $obj = null, $changeSet = null, $missingSet = null) {
		$this->kind = $kind;
		$this->obj = $obj;
		$this->changeSet = $changeSet;
		$this->missingSet = $missingSet;
	}
}

class ArrayOfObjectUpdate extends phpDynamicProperties {
	public $ObjectUpdate; //ObjectUpdate

	function __construct($ObjectUpdate = null) {
		$this->ObjectUpdate = $ObjectUpdate;
	}
}

class PropertyChange extends phpDynamicProperties {
	public $name; //string
	public $op; //PropertyChangeOp
	public $val; //anyType

	function __construct($name = null, $op = null, $val = null) {
		$this->name = $name;
		$this->op = $op;
		$this->val = $val;
	}
}

class ArrayOfPropertyChange extends phpDynamicProperties {
	public $PropertyChange; //PropertyChange

	function __construct($PropertyChange = null) {
		$this->PropertyChange = $PropertyChange;
	}
}

class MissingProperty extends phpDynamicProperties {
	public $path; //string
	public $fault; //LocalizedMethodFault

	function __construct($path = null, $fault = null) {
		$this->path = $path;
		$this->fault = $fault;
	}
}

class ArrayOfMissingProperty extends phpDynamicProperties {
	public $MissingProperty; //MissingProperty

	function __construct($MissingProperty = null) {
		$this->MissingProperty = $MissingProperty;
	}
}

class MissingObject extends phpDynamicProperties {
	public $obj; //ManagedObjectReference
	public $fault; //LocalizedMethodFault

	function __construct($obj = null, $fault = null) {
		$this->obj = $obj;
		$this->fault = $fault;
	}
}

class ArrayOfMissingObject extends phpDynamicProperties {
	public $MissingObject; //MissingObject

	function __construct($MissingObject = null) {
		$this->MissingObject = $MissingObject;
	}
}

class WaitOptions extends phpDynamicProperties {
	public $maxWaitSeconds; //int
	public $maxObjectUpdates; //int

	function __construct($maxWaitSeconds = null, $maxObjectUpdates = null) {
		$this->maxWaitSeconds = $maxWaitSeconds;
		$this->maxObjectUpdates = $maxObjectUpdates;
	}
}

class RetrieveOptions extends phpDynamicProperties {
	public $maxObjects; //int

	function __construct($maxObjects = null) {
		$this->maxObjects = $maxObjects;
	}
}

class RetrieveResult extends phpDynamicProperties {
	public $token; //string
	public $objects; //ObjectContent

	function __construct($token = null, $objects = null) {
		$this->token = $token;
		$this->objects = $objects;
	}
}

class DestroyPropertyFilterRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference

	function __construct($_this = null) {
		$this->_this = $_this;
	}
}

class CreateFilterRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $spec; //PropertyFilterSpec
	public $partialUpdates; //boolean

	function __construct($_this = null, $spec = null, $partialUpdates = null) {
		$this->_this = $_this;
		$this->spec = $spec;
		$this->partialUpdates = $partialUpdates;
	}
}

class RetrievePropertiesRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $specSet; //PropertyFilterSpec

	function __construct($_this = null, $specSet = null) {
		$this->_this = $_this;
		$this->specSet = $specSet;
	}
}

class CheckForUpdatesRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $version; //string

	function __construct($_this = null, $version = null) {
		$this->_this = $_this;
		$this->version = $version;
	}
}

class WaitForUpdatesRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $version; //string

	function __construct($_this = null, $version = null) {
		$this->_this = $_this;
		$this->version = $version;
	}
}

class CancelWaitForUpdatesRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference

	function __construct($_this = null) {
		$this->_this = $_this;
	}
}

class WaitForUpdatesExRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $version; //string
	public $options; //WaitOptions

	function __construct($_this = null, $version = null, $options = null) {
		$this->_this = $_this;
		$this->version = $version;
		$this->options = $options;
	}
}

class RetrievePropertiesExRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $specSet; //PropertyFilterSpec
	public $options; //RetrieveOptions

	function __construct($_this = null, $specSet = null, $options = null) {
		$this->_this = $_this;
		$this->specSet = $specSet;
		$this->options = $options;
	}
}

class ContinueRetrievePropertiesExRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $token; //string

	function __construct($_this = null, $token = null) {
		$this->_this = $_this;
		$this->token = $token;
	}
}

class CancelRetrievePropertiesExRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $token; //string

	function __construct($_this = null, $token = null) {
		$this->_this = $_this;
		$this->token = $token;
	}
}

class CreatePropertyCollectorRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference

	function __construct($_this = null) {
		$this->_this = $_this;
	}
}

class DestroyPropertyCollectorRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference

	function __construct($_this = null) {
		$this->_this = $_this;
	}
}

class AboutInfo extends phpDynamicProperties {
	public $name; //string
	public $fullName; //string
	public $vendor; //string
	public $version; //string
	public $build; //string
	public $localeVersion; //string
	public $localeBuild; //string
	public $osType; //string
	public $productLineId; //string
	public $apiType; //string
	public $apiVersion; //string
	public $instanceUuid; //string
	public $licenseProductName; //string
	public $licenseProductVersion; //string

	function __construct($name = null, $fullName = null, $vendor = null, $version = null, $build = null, $localeVersion = null, $localeBuild = null, $osType = null, $productLineId = null, $apiType = null, $apiVersion = null, $instanceUuid = null, $licenseProductName = null, $licenseProductVersion = null) {
		$this->name = $name;
		$this->fullName = $fullName;
		$this->vendor = $vendor;
		$this->version = $version;
		$this->build = $build;
		$this->localeVersion = $localeVersion;
		$this->localeBuild = $localeBuild;
		$this->osType = $osType;
		$this->productLineId = $productLineId;
		$this->apiType = $apiType;
		$this->apiVersion = $apiVersion;
		$this->instanceUuid = $instanceUuid;
		$this->licenseProductName = $licenseProductName;
		$this->licenseProductVersion = $licenseProductVersion;
	}
}

class AuthorizationDescription extends phpDynamicProperties {
	public $privilege; //ElementDescription
	public $privilegeGroup; //ElementDescription

	function __construct($privilege = null, $privilegeGroup = null) {
		$this->privilege = $privilege;
		$this->privilegeGroup = $privilegeGroup;
	}
}

class Permission extends phpDynamicProperties {
	public $entity; //ManagedObjectReference
	public $principal; //string
	public $group; //boolean
	public $roleId; //int
	public $propagate; //boolean

	function __construct($entity = null, $principal = null, $group = null, $roleId = null, $propagate = null) {
		$this->entity = $entity;
		$this->principal = $principal;
		$this->group = $group;
		$this->roleId = $roleId;
		$this->propagate = $propagate;
	}
}

class ArrayOfPermission extends phpDynamicProperties {
	public $Permission; //Permission

	function __construct($Permission = null) {
		$this->Permission = $Permission;
	}
}

class AuthorizationRole extends phpDynamicProperties {
	public $roleId; //int
	public $system; //boolean
	public $name; //string
	public $info; //Description
	public $privilege; //string

	function __construct($roleId = null, $system = null, $name = null, $info = null, $privilege = null) {
		$this->roleId = $roleId;
		$this->system = $system;
		$this->name = $name;
		$this->info = $info;
		$this->privilege = $privilege;
	}
}

class ArrayOfAuthorizationRole extends phpDynamicProperties {
	public $AuthorizationRole; //AuthorizationRole

	function __construct($AuthorizationRole = null) {
		$this->AuthorizationRole = $AuthorizationRole;
	}
}

class AuthorizationPrivilege extends phpDynamicProperties {
	public $privId; //string
	public $onParent; //boolean
	public $name; //string
	public $privGroupName; //string

	function __construct($privId = null, $onParent = null, $name = null, $privGroupName = null) {
		$this->privId = $privId;
		$this->onParent = $onParent;
		$this->name = $name;
		$this->privGroupName = $privGroupName;
	}
}

class ArrayOfAuthorizationPrivilege extends phpDynamicProperties {
	public $AuthorizationPrivilege; //AuthorizationPrivilege

	function __construct($AuthorizationPrivilege = null) {
		$this->AuthorizationPrivilege = $AuthorizationPrivilege;
	}
}

class BoolPolicy extends phpDynamicProperties {
	public $value; //boolean

	function __construct($value = null) {
		$this->value = $value;
	}
}

class Capability extends phpDynamicProperties {
	public $provisioningSupported; //boolean
	public $multiHostSupported; //boolean
	public $userShellAccessSupported; //boolean
	public $supportedEVCMode; //EVCMode

	function __construct($provisioningSupported = null, $multiHostSupported = null, $userShellAccessSupported = null, $supportedEVCMode = null) {
		$this->provisioningSupported = $provisioningSupported;
		$this->multiHostSupported = $multiHostSupported;
		$this->userShellAccessSupported = $userShellAccessSupported;
		$this->supportedEVCMode = $supportedEVCMode;
	}
}

class ClusterComputeResourceSummary extends phpDynamicProperties {
	public $currentFailoverLevel; //int
	public $admissionControlInfo; //ClusterDasAdmissionControlInfo
	public $numVmotions; //int
	public $targetBalance; //int
	public $currentBalance; //int
	public $currentEVCModeKey; //string
	public $dasData; //ClusterDasData

	function __construct($currentFailoverLevel = null, $admissionControlInfo = null, $numVmotions = null, $targetBalance = null, $currentBalance = null, $currentEVCModeKey = null, $dasData = null) {
		$this->currentFailoverLevel = $currentFailoverLevel;
		$this->admissionControlInfo = $admissionControlInfo;
		$this->numVmotions = $numVmotions;
		$this->targetBalance = $targetBalance;
		$this->currentBalance = $currentBalance;
		$this->currentEVCModeKey = $currentEVCModeKey;
		$this->dasData = $dasData;
	}
}

class ComputeResourceSummary extends phpDynamicProperties {
	public $totalCpu; //int
	public $totalMemory; //long
	public $numCpuCores; //short
	public $numCpuThreads; //short
	public $effectiveCpu; //int
	public $effectiveMemory; //long
	public $numHosts; //int
	public $numEffectiveHosts; //int
	public $overallStatus; //ManagedEntityStatus

	function __construct($totalCpu = null, $totalMemory = null, $numCpuCores = null, $numCpuThreads = null, $effectiveCpu = null, $effectiveMemory = null, $numHosts = null, $numEffectiveHosts = null, $overallStatus = null) {
		$this->totalCpu = $totalCpu;
		$this->totalMemory = $totalMemory;
		$this->numCpuCores = $numCpuCores;
		$this->numCpuThreads = $numCpuThreads;
		$this->effectiveCpu = $effectiveCpu;
		$this->effectiveMemory = $effectiveMemory;
		$this->numHosts = $numHosts;
		$this->numEffectiveHosts = $numEffectiveHosts;
		$this->overallStatus = $overallStatus;
	}
}

class ComputeResourceConfigInfo extends phpDynamicProperties {
	public $vmSwapPlacement; //string
	public $spbmEnabled; //boolean

	function __construct($vmSwapPlacement = null, $spbmEnabled = null) {
		$this->vmSwapPlacement = $vmSwapPlacement;
		$this->spbmEnabled = $spbmEnabled;
	}
}

class ComputeResourceHostSPBMLicenseInfo extends phpDynamicProperties {
	public $host; //ManagedObjectReference
	public $licenseState; //ComputeResourceHostSPBMLicenseInfoHostSPBMLicenseState

	function __construct($host = null, $licenseState = null) {
		$this->host = $host;
		$this->licenseState = $licenseState;
	}
}

class ArrayOfComputeResourceHostSPBMLicenseInfo extends phpDynamicProperties {
	public $ComputeResourceHostSPBMLicenseInfo; //ComputeResourceHostSPBMLicenseInfo

	function __construct($ComputeResourceHostSPBMLicenseInfo = null) {
		$this->ComputeResourceHostSPBMLicenseInfo = $ComputeResourceHostSPBMLicenseInfo;
	}
}

class ComputeResourceConfigSpec extends phpDynamicProperties {
	public $vmSwapPlacement; //string
	public $spbmEnabled; //boolean

	function __construct($vmSwapPlacement = null, $spbmEnabled = null) {
		$this->vmSwapPlacement = $vmSwapPlacement;
		$this->spbmEnabled = $spbmEnabled;
	}
}

class CustomFieldDef extends phpDynamicProperties {
	public $key; //int
	public $name; //string
	public $type; //string
	public $managedObjectType; //string
	public $fieldDefPrivileges; //PrivilegePolicyDef
	public $fieldInstancePrivileges; //PrivilegePolicyDef

	function __construct($key = null, $name = null, $type = null, $managedObjectType = null, $fieldDefPrivileges = null, $fieldInstancePrivileges = null) {
		$this->key = $key;
		$this->name = $name;
		$this->type = $type;
		$this->managedObjectType = $managedObjectType;
		$this->fieldDefPrivileges = $fieldDefPrivileges;
		$this->fieldInstancePrivileges = $fieldInstancePrivileges;
	}
}

class ArrayOfCustomFieldDef extends phpDynamicProperties {
	public $CustomFieldDef; //CustomFieldDef

	function __construct($CustomFieldDef = null) {
		$this->CustomFieldDef = $CustomFieldDef;
	}
}

class CustomFieldValue extends phpDynamicProperties {
	public $key; //int

	function __construct($key = null) {
		$this->key = $key;
	}
}

class ArrayOfCustomFieldValue extends phpDynamicProperties {
	public $CustomFieldValue; //CustomFieldValue

	function __construct($CustomFieldValue = null) {
		$this->CustomFieldValue = $CustomFieldValue;
	}
}

class CustomFieldStringValue extends phpDynamicProperties {
	public $value; //string

	function __construct($value = null) {
		$this->value = $value;
	}
}

class CustomizationSpecInfo extends phpDynamicProperties {
	public $name; //string
	public $description; //string
	public $type; //string
	public $changeVersion; //string
	public $lastUpdateTime; //dateTime

	function __construct($name = null, $description = null, $type = null, $changeVersion = null, $lastUpdateTime = null) {
		$this->name = $name;
		$this->description = $description;
		$this->type = $type;
		$this->changeVersion = $changeVersion;
		$this->lastUpdateTime = $lastUpdateTime;
	}
}

class ArrayOfCustomizationSpecInfo extends phpDynamicProperties {
	public $CustomizationSpecInfo; //CustomizationSpecInfo

	function __construct($CustomizationSpecInfo = null) {
		$this->CustomizationSpecInfo = $CustomizationSpecInfo;
	}
}

class CustomizationSpecItem extends phpDynamicProperties {
	public $info; //CustomizationSpecInfo
	public $spec; //CustomizationSpec

	function __construct($info = null, $spec = null) {
		$this->info = $info;
		$this->spec = $spec;
	}
}

class DatastoreSummary extends phpDynamicProperties {
	public $datastore; //ManagedObjectReference
	public $name; //string
	public $url; //string
	public $capacity; //long
	public $freeSpace; //long
	public $uncommitted; //long
	public $accessible; //boolean
	public $multipleHostAccess; //boolean
	public $type; //string
	public $maintenanceMode; //string

	function __construct($datastore = null, $name = null, $url = null, $capacity = null, $freeSpace = null, $uncommitted = null, $accessible = null, $multipleHostAccess = null, $type = null, $maintenanceMode = null) {
		$this->datastore = $datastore;
		$this->name = $name;
		$this->url = $url;
		$this->capacity = $capacity;
		$this->freeSpace = $freeSpace;
		$this->uncommitted = $uncommitted;
		$this->accessible = $accessible;
		$this->multipleHostAccess = $multipleHostAccess;
		$this->type = $type;
		$this->maintenanceMode = $maintenanceMode;
	}
}

class DatastoreInfo extends phpDynamicProperties {
	public $name; //string
	public $url; //string
	public $freeSpace; //long
	public $maxFileSize; //long
	public $timestamp; //dateTime

	function __construct($name = null, $url = null, $freeSpace = null, $maxFileSize = null, $timestamp = null) {
		$this->name = $name;
		$this->url = $url;
		$this->freeSpace = $freeSpace;
		$this->maxFileSize = $maxFileSize;
		$this->timestamp = $timestamp;
	}
}

class DatastoreCapability extends phpDynamicProperties {
	public $directoryHierarchySupported; //boolean
	public $rawDiskMappingsSupported; //boolean
	public $perFileThinProvisioningSupported; //boolean
	public $storageIORMSupported; //boolean

	function __construct($directoryHierarchySupported = null, $rawDiskMappingsSupported = null, $perFileThinProvisioningSupported = null, $storageIORMSupported = null) {
		$this->directoryHierarchySupported = $directoryHierarchySupported;
		$this->rawDiskMappingsSupported = $rawDiskMappingsSupported;
		$this->perFileThinProvisioningSupported = $perFileThinProvisioningSupported;
		$this->storageIORMSupported = $storageIORMSupported;
	}
}

class DatastoreHostMount extends phpDynamicProperties {
	public $key; //ManagedObjectReference
	public $mountInfo; //HostMountInfo

	function __construct($key = null, $mountInfo = null) {
		$this->key = $key;
		$this->mountInfo = $mountInfo;
	}
}

class ArrayOfDatastoreHostMount extends phpDynamicProperties {
	public $DatastoreHostMount; //DatastoreHostMount

	function __construct($DatastoreHostMount = null) {
		$this->DatastoreHostMount = $DatastoreHostMount;
	}
}

class DatastoreMountPathDatastorePair extends phpDynamicProperties {
	public $oldMountPath; //string
	public $datastore; //ManagedObjectReference

	function __construct($oldMountPath = null, $datastore = null) {
		$this->oldMountPath = $oldMountPath;
		$this->datastore = $datastore;
	}
}

class ArrayOfDatastoreMountPathDatastorePair extends phpDynamicProperties {
	public $DatastoreMountPathDatastorePair; //DatastoreMountPathDatastorePair

	function __construct($DatastoreMountPathDatastorePair = null) {
		$this->DatastoreMountPathDatastorePair = $DatastoreMountPathDatastorePair;
	}
}

class Description extends phpDynamicProperties {
	public $label; //string
	public $summary; //string

	function __construct($label = null, $summary = null) {
		$this->label = $label;
		$this->summary = $summary;
	}
}

class DiagnosticManagerLogDescriptor extends phpDynamicProperties {
	public $key; //string
	public $fileName; //string
	public $creator; //string
	public $format; //string
	public $mimeType; //string
	public $info; //Description

	function __construct($key = null, $fileName = null, $creator = null, $format = null, $mimeType = null, $info = null) {
		$this->key = $key;
		$this->fileName = $fileName;
		$this->creator = $creator;
		$this->format = $format;
		$this->mimeType = $mimeType;
		$this->info = $info;
	}
}

class ArrayOfDiagnosticManagerLogDescriptor extends phpDynamicProperties {
	public $DiagnosticManagerLogDescriptor; //DiagnosticManagerLogDescriptor

	function __construct($DiagnosticManagerLogDescriptor = null) {
		$this->DiagnosticManagerLogDescriptor = $DiagnosticManagerLogDescriptor;
	}
}

class DiagnosticManagerLogHeader extends phpDynamicProperties {
	public $lineStart; //int
	public $lineEnd; //int
	public $lineText; //string

	function __construct($lineStart = null, $lineEnd = null, $lineText = null) {
		$this->lineStart = $lineStart;
		$this->lineEnd = $lineEnd;
		$this->lineText = $lineText;
	}
}

class DiagnosticManagerBundleInfo extends phpDynamicProperties {
	public $system; //ManagedObjectReference
	public $url; //string

	function __construct($system = null, $url = null) {
		$this->system = $system;
		$this->url = $url;
	}
}

class ArrayOfDiagnosticManagerBundleInfo extends phpDynamicProperties {
	public $DiagnosticManagerBundleInfo; //DiagnosticManagerBundleInfo

	function __construct($DiagnosticManagerBundleInfo = null) {
		$this->DiagnosticManagerBundleInfo = $DiagnosticManagerBundleInfo;
	}
}

class DVSContactInfo extends phpDynamicProperties {
	public $name; //string
	public $contact; //string

	function __construct($name = null, $contact = null) {
		$this->name = $name;
		$this->contact = $contact;
	}
}

class DVSNetworkResourceManagementCapability extends phpDynamicProperties {
	public $networkResourceManagementSupported; //boolean
	public $networkResourcePoolHighShareValue; //int
	public $qosSupported; //boolean
	public $userDefinedNetworkResourcePoolsSupported; //boolean

	function __construct($networkResourceManagementSupported = null, $networkResourcePoolHighShareValue = null, $qosSupported = null, $userDefinedNetworkResourcePoolsSupported = null) {
		$this->networkResourceManagementSupported = $networkResourceManagementSupported;
		$this->networkResourcePoolHighShareValue = $networkResourcePoolHighShareValue;
		$this->qosSupported = $qosSupported;
		$this->userDefinedNetworkResourcePoolsSupported = $userDefinedNetworkResourcePoolsSupported;
	}
}

class DVSFeatureCapability extends phpDynamicProperties {
	public $networkResourceManagementSupported; //boolean
	public $vmDirectPathGen2Supported; //boolean
	public $nicTeamingPolicy; //string
	public $networkResourcePoolHighShareValue; //int
	public $networkResourceManagementCapability; //DVSNetworkResourceManagementCapability

	function __construct($networkResourceManagementSupported = null, $vmDirectPathGen2Supported = null, $nicTeamingPolicy = null, $networkResourcePoolHighShareValue = null, $networkResourceManagementCapability = null) {
		$this->networkResourceManagementSupported = $networkResourceManagementSupported;
		$this->vmDirectPathGen2Supported = $vmDirectPathGen2Supported;
		$this->nicTeamingPolicy = $nicTeamingPolicy;
		$this->networkResourcePoolHighShareValue = $networkResourcePoolHighShareValue;
		$this->networkResourceManagementCapability = $networkResourceManagementCapability;
	}
}

class DVSCapability extends phpDynamicProperties {
	public $dvsOperationSupported; //boolean
	public $dvPortGroupOperationSupported; //boolean
	public $dvPortOperationSupported; //boolean
	public $compatibleHostComponentProductInfo; //DistributedVirtualSwitchHostProductSpec
	public $featuresSupported; //DVSFeatureCapability

	function __construct($dvsOperationSupported = null, $dvPortGroupOperationSupported = null, $dvPortOperationSupported = null, $compatibleHostComponentProductInfo = null, $featuresSupported = null) {
		$this->dvsOperationSupported = $dvsOperationSupported;
		$this->dvPortGroupOperationSupported = $dvPortGroupOperationSupported;
		$this->dvPortOperationSupported = $dvPortOperationSupported;
		$this->compatibleHostComponentProductInfo = $compatibleHostComponentProductInfo;
		$this->featuresSupported = $featuresSupported;
	}
}

class DVSSummary extends phpDynamicProperties {
	public $name; //string
	public $uuid; //string
	public $numPorts; //int
	public $productInfo; //DistributedVirtualSwitchProductSpec
	public $hostMember; //ManagedObjectReference
	public $vm; //ManagedObjectReference
	public $host; //ManagedObjectReference
	public $portgroupName; //string
	public $description; //string
	public $contact; //DVSContactInfo

	function __construct($name = null, $uuid = null, $numPorts = null, $productInfo = null, $hostMember = null, $vm = null, $host = null, $portgroupName = null, $description = null, $contact = null) {
		$this->name = $name;
		$this->uuid = $uuid;
		$this->numPorts = $numPorts;
		$this->productInfo = $productInfo;
		$this->hostMember = $hostMember;
		$this->vm = $vm;
		$this->host = $host;
		$this->portgroupName = $portgroupName;
		$this->description = $description;
		$this->contact = $contact;
	}
}

class DVSPolicy extends phpDynamicProperties {
	public $autoPreInstallAllowed; //boolean
	public $autoUpgradeAllowed; //boolean
	public $partialUpgradeAllowed; //boolean

	function __construct($autoPreInstallAllowed = null, $autoUpgradeAllowed = null, $partialUpgradeAllowed = null) {
		$this->autoPreInstallAllowed = $autoPreInstallAllowed;
		$this->autoUpgradeAllowed = $autoUpgradeAllowed;
		$this->partialUpgradeAllowed = $partialUpgradeAllowed;
	}
}

class DVSUplinkPortPolicy extends phpDynamicProperties {
}

class DVSNameArrayUplinkPortPolicy extends phpDynamicProperties {
	public $uplinkPortName; //string

	function __construct($uplinkPortName = null) {
		$this->uplinkPortName = $uplinkPortName;
	}
}

class DVSConfigSpec extends phpDynamicProperties {
	public $configVersion; //string
	public $name; //string
	public $numStandalonePorts; //int
	public $maxPorts; //int
	public $uplinkPortPolicy; //DVSUplinkPortPolicy
	public $uplinkPortgroup; //ManagedObjectReference
	public $defaultPortConfig; //DVPortSetting
	public $host; //DistributedVirtualSwitchHostMemberConfigSpec
	public $extensionKey; //string
	public $description; //string
	public $policy; //DVSPolicy
	public $vendorSpecificConfig; //DistributedVirtualSwitchKeyedOpaqueBlob
	public $contact; //DVSContactInfo
	public $switchIpAddress; //string

	function __construct($configVersion = null, $name = null, $numStandalonePorts = null, $maxPorts = null, $uplinkPortPolicy = null, $uplinkPortgroup = null, $defaultPortConfig = null, $host = null, $extensionKey = null, $description = null, $policy = null, $vendorSpecificConfig = null, $contact = null, $switchIpAddress = null) {
		$this->configVersion = $configVersion;
		$this->name = $name;
		$this->numStandalonePorts = $numStandalonePorts;
		$this->maxPorts = $maxPorts;
		$this->uplinkPortPolicy = $uplinkPortPolicy;
		$this->uplinkPortgroup = $uplinkPortgroup;
		$this->defaultPortConfig = $defaultPortConfig;
		$this->host = $host;
		$this->extensionKey = $extensionKey;
		$this->description = $description;
		$this->policy = $policy;
		$this->vendorSpecificConfig = $vendorSpecificConfig;
		$this->contact = $contact;
		$this->switchIpAddress = $switchIpAddress;
	}
}

class DVSCreateSpec extends phpDynamicProperties {
	public $configSpec; //DVSConfigSpec
	public $productInfo; //DistributedVirtualSwitchProductSpec
	public $capability; //DVSCapability

	function __construct($configSpec = null, $productInfo = null, $capability = null) {
		$this->configSpec = $configSpec;
		$this->productInfo = $productInfo;
		$this->capability = $capability;
	}
}

class DVSConfigInfo extends phpDynamicProperties {
	public $uuid; //string
	public $name; //string
	public $numStandalonePorts; //int
	public $numPorts; //int
	public $maxPorts; //int
	public $uplinkPortPolicy; //DVSUplinkPortPolicy
	public $uplinkPortgroup; //ManagedObjectReference
	public $defaultPortConfig; //DVPortSetting
	public $host; //DistributedVirtualSwitchHostMember
	public $productInfo; //DistributedVirtualSwitchProductSpec
	public $targetInfo; //DistributedVirtualSwitchProductSpec
	public $extensionKey; //string
	public $vendorSpecificConfig; //DistributedVirtualSwitchKeyedOpaqueBlob
	public $policy; //DVSPolicy
	public $description; //string
	public $configVersion; //string
	public $contact; //DVSContactInfo
	public $switchIpAddress; //string
	public $createTime; //dateTime
	public $networkResourceManagementEnabled; //boolean

	function __construct($uuid = null, $name = null, $numStandalonePorts = null, $numPorts = null, $maxPorts = null, $uplinkPortPolicy = null, $uplinkPortgroup = null, $defaultPortConfig = null, $host = null, $productInfo = null, $targetInfo = null, $extensionKey = null, $vendorSpecificConfig = null, $policy = null, $description = null, $configVersion = null, $contact = null, $switchIpAddress = null, $createTime = null, $networkResourceManagementEnabled = null) {
		$this->uuid = $uuid;
		$this->name = $name;
		$this->numStandalonePorts = $numStandalonePorts;
		$this->numPorts = $numPorts;
		$this->maxPorts = $maxPorts;
		$this->uplinkPortPolicy = $uplinkPortPolicy;
		$this->uplinkPortgroup = $uplinkPortgroup;
		$this->defaultPortConfig = $defaultPortConfig;
		$this->host = $host;
		$this->productInfo = $productInfo;
		$this->targetInfo = $targetInfo;
		$this->extensionKey = $extensionKey;
		$this->vendorSpecificConfig = $vendorSpecificConfig;
		$this->policy = $policy;
		$this->description = $description;
		$this->configVersion = $configVersion;
		$this->contact = $contact;
		$this->switchIpAddress = $switchIpAddress;
		$this->createTime = $createTime;
		$this->networkResourceManagementEnabled = $networkResourceManagementEnabled;
	}
}

class EVCMode extends phpDynamicProperties {
	public $guaranteedCPUFeatures; //HostCpuIdInfo
	public $vendor; //string
	public $track; //string
	public $vendorTier; //int

	function __construct($guaranteedCPUFeatures = null, $vendor = null, $track = null, $vendorTier = null) {
		$this->guaranteedCPUFeatures = $guaranteedCPUFeatures;
		$this->vendor = $vendor;
		$this->track = $track;
		$this->vendorTier = $vendorTier;
	}
}

class ArrayOfEVCMode extends phpDynamicProperties {
	public $EVCMode; //EVCMode

	function __construct($EVCMode = null) {
		$this->EVCMode = $EVCMode;
	}
}

class ElementDescription extends phpDynamicProperties {
	public $key; //string

	function __construct($key = null) {
		$this->key = $key;
	}
}

class ArrayOfElementDescription extends phpDynamicProperties {
	public $ElementDescription; //ElementDescription

	function __construct($ElementDescription = null) {
		$this->ElementDescription = $ElementDescription;
	}
}

class EnumDescription extends phpDynamicProperties {
	public $key; //string
	public $tags; //ElementDescription

	function __construct($key = null, $tags = null) {
		$this->key = $key;
		$this->tags = $tags;
	}
}

class ArrayOfEnumDescription extends phpDynamicProperties {
	public $EnumDescription; //EnumDescription

	function __construct($EnumDescription = null) {
		$this->EnumDescription = $EnumDescription;
	}
}

class ExtendedDescription extends phpDynamicProperties {
	public $messageCatalogKeyPrefix; //string
	public $messageArg; //KeyAnyValue

	function __construct($messageCatalogKeyPrefix = null, $messageArg = null) {
		$this->messageCatalogKeyPrefix = $messageCatalogKeyPrefix;
		$this->messageArg = $messageArg;
	}
}

class ExtendedElementDescription extends phpDynamicProperties {
	public $messageCatalogKeyPrefix; //string
	public $messageArg; //KeyAnyValue

	function __construct($messageCatalogKeyPrefix = null, $messageArg = null) {
		$this->messageCatalogKeyPrefix = $messageCatalogKeyPrefix;
		$this->messageArg = $messageArg;
	}
}

class ExtensionServerInfo extends phpDynamicProperties {
	public $url; //string
	public $description; //Description
	public $company; //string
	public $type; //string
	public $adminEmail; //string
	public $serverThumbprint; //string

	function __construct($url = null, $description = null, $company = null, $type = null, $adminEmail = null, $serverThumbprint = null) {
		$this->url = $url;
		$this->description = $description;
		$this->company = $company;
		$this->type = $type;
		$this->adminEmail = $adminEmail;
		$this->serverThumbprint = $serverThumbprint;
	}
}

class ArrayOfExtensionServerInfo extends phpDynamicProperties {
	public $ExtensionServerInfo; //ExtensionServerInfo

	function __construct($ExtensionServerInfo = null) {
		$this->ExtensionServerInfo = $ExtensionServerInfo;
	}
}

class ExtensionClientInfo extends phpDynamicProperties {
	public $version; //string
	public $description; //Description
	public $company; //string
	public $type; //string
	public $url; //string

	function __construct($version = null, $description = null, $company = null, $type = null, $url = null) {
		$this->version = $version;
		$this->description = $description;
		$this->company = $company;
		$this->type = $type;
		$this->url = $url;
	}
}

class ArrayOfExtensionClientInfo extends phpDynamicProperties {
	public $ExtensionClientInfo; //ExtensionClientInfo

	function __construct($ExtensionClientInfo = null) {
		$this->ExtensionClientInfo = $ExtensionClientInfo;
	}
}

class ExtensionTaskTypeInfo extends phpDynamicProperties {
	public $taskID; //string

	function __construct($taskID = null) {
		$this->taskID = $taskID;
	}
}

class ArrayOfExtensionTaskTypeInfo extends phpDynamicProperties {
	public $ExtensionTaskTypeInfo; //ExtensionTaskTypeInfo

	function __construct($ExtensionTaskTypeInfo = null) {
		$this->ExtensionTaskTypeInfo = $ExtensionTaskTypeInfo;
	}
}

class ExtensionEventTypeInfo extends phpDynamicProperties {
	public $eventID; //string
	public $eventTypeSchema; //string

	function __construct($eventID = null, $eventTypeSchema = null) {
		$this->eventID = $eventID;
		$this->eventTypeSchema = $eventTypeSchema;
	}
}

class ArrayOfExtensionEventTypeInfo extends phpDynamicProperties {
	public $ExtensionEventTypeInfo; //ExtensionEventTypeInfo

	function __construct($ExtensionEventTypeInfo = null) {
		$this->ExtensionEventTypeInfo = $ExtensionEventTypeInfo;
	}
}

class ExtensionFaultTypeInfo extends phpDynamicProperties {
	public $faultID; //string

	function __construct($faultID = null) {
		$this->faultID = $faultID;
	}
}

class ArrayOfExtensionFaultTypeInfo extends phpDynamicProperties {
	public $ExtensionFaultTypeInfo; //ExtensionFaultTypeInfo

	function __construct($ExtensionFaultTypeInfo = null) {
		$this->ExtensionFaultTypeInfo = $ExtensionFaultTypeInfo;
	}
}

class ExtensionPrivilegeInfo extends phpDynamicProperties {
	public $privID; //string
	public $privGroupName; //string

	function __construct($privID = null, $privGroupName = null) {
		$this->privID = $privID;
		$this->privGroupName = $privGroupName;
	}
}

class ArrayOfExtensionPrivilegeInfo extends phpDynamicProperties {
	public $ExtensionPrivilegeInfo; //ExtensionPrivilegeInfo

	function __construct($ExtensionPrivilegeInfo = null) {
		$this->ExtensionPrivilegeInfo = $ExtensionPrivilegeInfo;
	}
}

class ExtensionResourceInfo extends phpDynamicProperties {
	public $locale; //string
	public $module; //string
	public $data; //KeyValue

	function __construct($locale = null, $module = null, $data = null) {
		$this->locale = $locale;
		$this->module = $module;
		$this->data = $data;
	}
}

class ArrayOfExtensionResourceInfo extends phpDynamicProperties {
	public $ExtensionResourceInfo; //ExtensionResourceInfo

	function __construct($ExtensionResourceInfo = null) {
		$this->ExtensionResourceInfo = $ExtensionResourceInfo;
	}
}

class ExtensionHealthInfo extends phpDynamicProperties {
	public $url; //string

	function __construct($url = null) {
		$this->url = $url;
	}
}

class ExtensionOvfConsumerInfo extends phpDynamicProperties {
	public $callbackUrl; //string
	public $sectionType; //string

	function __construct($callbackUrl = null, $sectionType = null) {
		$this->callbackUrl = $callbackUrl;
		$this->sectionType = $sectionType;
	}
}

class Extension extends phpDynamicProperties {
	public $description; //Description
	public $key; //string
	public $company; //string
	public $type; //string
	public $version; //string
	public $subjectName; //string
	public $server; //ExtensionServerInfo
	public $client; //ExtensionClientInfo
	public $taskList; //ExtensionTaskTypeInfo
	public $eventList; //ExtensionEventTypeInfo
	public $faultList; //ExtensionFaultTypeInfo
	public $privilegeList; //ExtensionPrivilegeInfo
	public $resourceList; //ExtensionResourceInfo
	public $lastHeartbeatTime; //dateTime
	public $healthInfo; //ExtensionHealthInfo
	public $ovfConsumerInfo; //ExtensionOvfConsumerInfo
	public $extendedProductInfo; //ExtExtendedProductInfo
	public $managedEntityInfo; //ExtManagedEntityInfo
	public $shownInSolutionManager; //boolean
	public $solutionManagerInfo; //ExtSolutionManagerInfo

	function __construct($description = null, $key = null, $company = null, $type = null, $version = null, $subjectName = null, $server = null, $client = null, $taskList = null, $eventList = null, $faultList = null, $privilegeList = null, $resourceList = null, $lastHeartbeatTime = null, $healthInfo = null, $ovfConsumerInfo = null, $extendedProductInfo = null, $managedEntityInfo = null, $shownInSolutionManager = null, $solutionManagerInfo = null) {
		$this->description = $description;
		$this->key = $key;
		$this->company = $company;
		$this->type = $type;
		$this->version = $version;
		$this->subjectName = $subjectName;
		$this->server = $server;
		$this->client = $client;
		$this->taskList = $taskList;
		$this->eventList = $eventList;
		$this->faultList = $faultList;
		$this->privilegeList = $privilegeList;
		$this->resourceList = $resourceList;
		$this->lastHeartbeatTime = $lastHeartbeatTime;
		$this->healthInfo = $healthInfo;
		$this->ovfConsumerInfo = $ovfConsumerInfo;
		$this->extendedProductInfo = $extendedProductInfo;
		$this->managedEntityInfo = $managedEntityInfo;
		$this->shownInSolutionManager = $shownInSolutionManager;
		$this->solutionManagerInfo = $solutionManagerInfo;
	}
}

class ArrayOfExtension extends phpDynamicProperties {
	public $Extension; //Extension

	function __construct($Extension = null) {
		$this->Extension = $Extension;
	}
}

class ReplicationVmProgressInfo extends phpDynamicProperties {
	public $progress; //int
	public $bytesTransferred; //long
	public $bytesToTransfer; //long
	public $checksumTotalBytes; //long
	public $checksumComparedBytes; //long

	function __construct($progress = null, $bytesTransferred = null, $bytesToTransfer = null, $checksumTotalBytes = null, $checksumComparedBytes = null) {
		$this->progress = $progress;
		$this->bytesTransferred = $bytesTransferred;
		$this->bytesToTransfer = $bytesToTransfer;
		$this->checksumTotalBytes = $checksumTotalBytes;
		$this->checksumComparedBytes = $checksumComparedBytes;
	}
}

class HbrManagerReplicationVmInfo extends phpDynamicProperties {
	public $state; //string
	public $progressInfo; //ReplicationVmProgressInfo
	public $imageId; //string
	public $lastError; //LocalizedMethodFault

	function __construct($state = null, $progressInfo = null, $imageId = null, $lastError = null) {
		$this->state = $state;
		$this->progressInfo = $progressInfo;
		$this->imageId = $imageId;
		$this->lastError = $lastError;
	}
}

class HostServiceTicket extends phpDynamicProperties {
	public $host; //string
	public $port; //int
	public $sslThumbprint; //string
	public $service; //string
	public $serviceVersion; //string
	public $sessionId; //string

	function __construct($host = null, $port = null, $sslThumbprint = null, $service = null, $serviceVersion = null, $sessionId = null) {
		$this->host = $host;
		$this->port = $port;
		$this->sslThumbprint = $sslThumbprint;
		$this->service = $service;
		$this->serviceVersion = $serviceVersion;
		$this->sessionId = $sessionId;
	}
}

class HostSystemReconnectSpec extends phpDynamicProperties {
	public $syncState; //boolean

	function __construct($syncState = null) {
		$this->syncState = $syncState;
	}
}

class HttpNfcLeaseDatastoreLeaseInfo extends phpDynamicProperties {
	public $datastoreKey; //string
	public $hosts; //HttpNfcLeaseHostInfo

	function __construct($datastoreKey = null, $hosts = null) {
		$this->datastoreKey = $datastoreKey;
		$this->hosts = $hosts;
	}
}

class ArrayOfHttpNfcLeaseDatastoreLeaseInfo extends phpDynamicProperties {
	public $HttpNfcLeaseDatastoreLeaseInfo; //HttpNfcLeaseDatastoreLeaseInfo

	function __construct($HttpNfcLeaseDatastoreLeaseInfo = null) {
		$this->HttpNfcLeaseDatastoreLeaseInfo = $HttpNfcLeaseDatastoreLeaseInfo;
	}
}

class HttpNfcLeaseHostInfo extends phpDynamicProperties {
	public $url; //string
	public $sslThumbprint; //string

	function __construct($url = null, $sslThumbprint = null) {
		$this->url = $url;
		$this->sslThumbprint = $sslThumbprint;
	}
}

class ArrayOfHttpNfcLeaseHostInfo extends phpDynamicProperties {
	public $HttpNfcLeaseHostInfo; //HttpNfcLeaseHostInfo

	function __construct($HttpNfcLeaseHostInfo = null) {
		$this->HttpNfcLeaseHostInfo = $HttpNfcLeaseHostInfo;
	}
}

class HttpNfcLeaseInfo extends phpDynamicProperties {
	public $lease; //ManagedObjectReference
	public $entity; //ManagedObjectReference
	public $deviceUrl; //HttpNfcLeaseDeviceUrl
	public $totalDiskCapacityInKB; //long
	public $leaseTimeout; //int
	public $hostMap; //HttpNfcLeaseDatastoreLeaseInfo

	function __construct($lease = null, $entity = null, $deviceUrl = null, $totalDiskCapacityInKB = null, $leaseTimeout = null, $hostMap = null) {
		$this->lease = $lease;
		$this->entity = $entity;
		$this->deviceUrl = $deviceUrl;
		$this->totalDiskCapacityInKB = $totalDiskCapacityInKB;
		$this->leaseTimeout = $leaseTimeout;
		$this->hostMap = $hostMap;
	}
}

class HttpNfcLeaseDeviceUrl extends phpDynamicProperties {
	public $key; //string
	public $importKey; //string
	public $url; //string
	public $sslThumbprint; //string
	public $disk; //boolean
	public $targetId; //string
	public $datastoreKey; //string
	public $fileSize; //long

	function __construct($key = null, $importKey = null, $url = null, $sslThumbprint = null, $disk = null, $targetId = null, $datastoreKey = null, $fileSize = null) {
		$this->key = $key;
		$this->importKey = $importKey;
		$this->url = $url;
		$this->sslThumbprint = $sslThumbprint;
		$this->disk = $disk;
		$this->targetId = $targetId;
		$this->datastoreKey = $datastoreKey;
		$this->fileSize = $fileSize;
	}
}

class ArrayOfHttpNfcLeaseDeviceUrl extends phpDynamicProperties {
	public $HttpNfcLeaseDeviceUrl; //HttpNfcLeaseDeviceUrl

	function __construct($HttpNfcLeaseDeviceUrl = null) {
		$this->HttpNfcLeaseDeviceUrl = $HttpNfcLeaseDeviceUrl;
	}
}

class HttpNfcLeaseManifestEntry extends phpDynamicProperties {
	public $key; //string
	public $sha1; //string
	public $size; //long
	public $disk; //boolean
	public $capacity; //long
	public $populatedSize; //long

	function __construct($key = null, $sha1 = null, $size = null, $disk = null, $capacity = null, $populatedSize = null) {
		$this->key = $key;
		$this->sha1 = $sha1;
		$this->size = $size;
		$this->disk = $disk;
		$this->capacity = $capacity;
		$this->populatedSize = $populatedSize;
	}
}

class ArrayOfHttpNfcLeaseManifestEntry extends phpDynamicProperties {
	public $HttpNfcLeaseManifestEntry; //HttpNfcLeaseManifestEntry

	function __construct($HttpNfcLeaseManifestEntry = null) {
		$this->HttpNfcLeaseManifestEntry = $HttpNfcLeaseManifestEntry;
	}
}

class ImportSpec extends phpDynamicProperties {
	public $entityConfig; //VAppEntityConfigInfo
	public $instantiationOst; //OvfConsumerOstNode

	function __construct($entityConfig = null, $instantiationOst = null) {
		$this->entityConfig = $entityConfig;
		$this->instantiationOst = $instantiationOst;
	}
}

class ArrayOfImportSpec extends phpDynamicProperties {
	public $ImportSpec; //ImportSpec

	function __construct($ImportSpec = null) {
		$this->ImportSpec = $ImportSpec;
	}
}

class InheritablePolicy extends phpDynamicProperties {
	public $inherited; //boolean

	function __construct($inherited = null) {
		$this->inherited = $inherited;
	}
}

class IntPolicy extends phpDynamicProperties {
	public $value; //int

	function __construct($value = null) {
		$this->value = $value;
	}
}

class KeyValue extends phpDynamicProperties {
	public $key; //string
	public $value; //string

	function __construct($key = null, $value = null) {
		$this->key = $key;
		$this->value = $value;
	}
}

class ArrayOfKeyValue extends phpDynamicProperties {
	public $KeyValue; //KeyValue

	function __construct($KeyValue = null) {
		$this->KeyValue = $KeyValue;
	}
}

class LicenseAssignmentManagerLicenseAssignment extends phpDynamicProperties {
	public $entityId; //string
	public $scope; //string
	public $entityDisplayName; //string
	public $assignedLicense; //LicenseManagerLicenseInfo
	public $properties; //KeyAnyValue

	function __construct($entityId = null, $scope = null, $entityDisplayName = null, $assignedLicense = null, $properties = null) {
		$this->entityId = $entityId;
		$this->scope = $scope;
		$this->entityDisplayName = $entityDisplayName;
		$this->assignedLicense = $assignedLicense;
		$this->properties = $properties;
	}
}

class ArrayOfLicenseAssignmentManagerLicenseAssignment extends phpDynamicProperties {
	public $LicenseAssignmentManagerLicenseAssignment; //LicenseAssignmentManagerLicenseAssignment

	function __construct($LicenseAssignmentManagerLicenseAssignment = null) {
		$this->LicenseAssignmentManagerLicenseAssignment = $LicenseAssignmentManagerLicenseAssignment;
	}
}

class LicenseSource extends phpDynamicProperties {
}

class LicenseServerSource extends phpDynamicProperties {
	public $licenseServer; //string

	function __construct($licenseServer = null) {
		$this->licenseServer = $licenseServer;
	}
}

class LocalLicenseSource extends phpDynamicProperties {
	public $licenseKeys; //string

	function __construct($licenseKeys = null) {
		$this->licenseKeys = $licenseKeys;
	}
}

class EvaluationLicenseSource extends phpDynamicProperties {
	public $remainingHours; //long

	function __construct($remainingHours = null) {
		$this->remainingHours = $remainingHours;
	}
}

class LicenseFeatureInfo extends phpDynamicProperties {
	public $key; //string
	public $featureName; //string
	public $featureDescription; //string
	public $state; //LicenseFeatureInfoState
	public $costUnit; //string
	public $sourceRestriction; //string
	public $dependentKey; //string
	public $edition; //boolean
	public $expiresOn; //dateTime

	function __construct($key = null, $featureName = null, $featureDescription = null, $state = null, $costUnit = null, $sourceRestriction = null, $dependentKey = null, $edition = null, $expiresOn = null) {
		$this->key = $key;
		$this->featureName = $featureName;
		$this->featureDescription = $featureDescription;
		$this->state = $state;
		$this->costUnit = $costUnit;
		$this->sourceRestriction = $sourceRestriction;
		$this->dependentKey = $dependentKey;
		$this->edition = $edition;
		$this->expiresOn = $expiresOn;
	}
}

class ArrayOfLicenseFeatureInfo extends phpDynamicProperties {
	public $LicenseFeatureInfo; //LicenseFeatureInfo

	function __construct($LicenseFeatureInfo = null) {
		$this->LicenseFeatureInfo = $LicenseFeatureInfo;
	}
}

class LicenseReservationInfo extends phpDynamicProperties {
	public $key; //string
	public $state; //LicenseReservationInfoState
	public $required; //int

	function __construct($key = null, $state = null, $required = null) {
		$this->key = $key;
		$this->state = $state;
		$this->required = $required;
	}
}

class ArrayOfLicenseReservationInfo extends phpDynamicProperties {
	public $LicenseReservationInfo; //LicenseReservationInfo

	function __construct($LicenseReservationInfo = null) {
		$this->LicenseReservationInfo = $LicenseReservationInfo;
	}
}

class LicenseAvailabilityInfo extends phpDynamicProperties {
	public $feature; //LicenseFeatureInfo
	public $total; //int
	public $available; //int

	function __construct($feature = null, $total = null, $available = null) {
		$this->feature = $feature;
		$this->total = $total;
		$this->available = $available;
	}
}

class ArrayOfLicenseAvailabilityInfo extends phpDynamicProperties {
	public $LicenseAvailabilityInfo; //LicenseAvailabilityInfo

	function __construct($LicenseAvailabilityInfo = null) {
		$this->LicenseAvailabilityInfo = $LicenseAvailabilityInfo;
	}
}

class LicenseDiagnostics extends phpDynamicProperties {
	public $sourceLastChanged; //dateTime
	public $sourceLost; //string
	public $sourceLatency; //float
	public $licenseRequests; //string
	public $licenseRequestFailures; //string
	public $licenseFeatureUnknowns; //string
	public $opState; //LicenseManagerState
	public $lastStatusUpdate; //dateTime
	public $opFailureMessage; //string

	function __construct($sourceLastChanged = null, $sourceLost = null, $sourceLatency = null, $licenseRequests = null, $licenseRequestFailures = null, $licenseFeatureUnknowns = null, $opState = null, $lastStatusUpdate = null, $opFailureMessage = null) {
		$this->sourceLastChanged = $sourceLastChanged;
		$this->sourceLost = $sourceLost;
		$this->sourceLatency = $sourceLatency;
		$this->licenseRequests = $licenseRequests;
		$this->licenseRequestFailures = $licenseRequestFailures;
		$this->licenseFeatureUnknowns = $licenseFeatureUnknowns;
		$this->opState = $opState;
		$this->lastStatusUpdate = $lastStatusUpdate;
		$this->opFailureMessage = $opFailureMessage;
	}
}

class LicenseUsageInfo extends phpDynamicProperties {
	public $source; //LicenseSource
	public $sourceAvailable; //boolean
	public $reservationInfo; //LicenseReservationInfo
	public $featureInfo; //LicenseFeatureInfo

	function __construct($source = null, $sourceAvailable = null, $reservationInfo = null, $featureInfo = null) {
		$this->source = $source;
		$this->sourceAvailable = $sourceAvailable;
		$this->reservationInfo = $reservationInfo;
		$this->featureInfo = $featureInfo;
	}
}

class LicenseManagerEvaluationInfo extends phpDynamicProperties {
	public $properties; //KeyAnyValue

	function __construct($properties = null) {
		$this->properties = $properties;
	}
}

class HostLicensableResourceInfo extends phpDynamicProperties {
	public $resource; //KeyAnyValue

	function __construct($resource = null) {
		$this->resource = $resource;
	}
}

class LicenseManagerLicenseInfo extends phpDynamicProperties {
	public $licenseKey; //string
	public $editionKey; //string
	public $name; //string
	public $total; //int
	public $used; //int
	public $costUnit; //string
	public $properties; //KeyAnyValue
	public $labels; //KeyValue

	function __construct($licenseKey = null, $editionKey = null, $name = null, $total = null, $used = null, $costUnit = null, $properties = null, $labels = null) {
		$this->licenseKey = $licenseKey;
		$this->editionKey = $editionKey;
		$this->name = $name;
		$this->total = $total;
		$this->used = $used;
		$this->costUnit = $costUnit;
		$this->properties = $properties;
		$this->labels = $labels;
	}
}

class ArrayOfLicenseManagerLicenseInfo extends phpDynamicProperties {
	public $LicenseManagerLicenseInfo; //LicenseManagerLicenseInfo

	function __construct($LicenseManagerLicenseInfo = null) {
		$this->LicenseManagerLicenseInfo = $LicenseManagerLicenseInfo;
	}
}

class LocalizationManagerMessageCatalog extends phpDynamicProperties {
	public $moduleName; //string
	public $catalogName; //string
	public $locale; //string
	public $catalogUri; //string
	public $lastModified; //dateTime
	public $md5sum; //string
	public $version; //string

	function __construct($moduleName = null, $catalogName = null, $locale = null, $catalogUri = null, $lastModified = null, $md5sum = null, $version = null) {
		$this->moduleName = $moduleName;
		$this->catalogName = $catalogName;
		$this->locale = $locale;
		$this->catalogUri = $catalogUri;
		$this->lastModified = $lastModified;
		$this->md5sum = $md5sum;
		$this->version = $version;
	}
}

class ArrayOfLocalizationManagerMessageCatalog extends phpDynamicProperties {
	public $LocalizationManagerMessageCatalog; //LocalizationManagerMessageCatalog

	function __construct($LocalizationManagerMessageCatalog = null) {
		$this->LocalizationManagerMessageCatalog = $LocalizationManagerMessageCatalog;
	}
}

class LongPolicy extends phpDynamicProperties {
	public $value; //long

	function __construct($value = null) {
		$this->value = $value;
	}
}

class MethodDescription extends phpDynamicProperties {
	public $key; //string

	function __construct($key = null) {
		$this->key = $key;
	}
}

class NetworkSummary extends phpDynamicProperties {
	public $network; //ManagedObjectReference
	public $name; //string
	public $accessible; //boolean
	public $ipPoolName; //string

	function __construct($network = null, $name = null, $accessible = null, $ipPoolName = null) {
		$this->network = $network;
		$this->name = $name;
		$this->accessible = $accessible;
		$this->ipPoolName = $ipPoolName;
	}
}

class NumericRange extends phpDynamicProperties {
	public $start; //int
	public $end; //int

	function __construct($start = null, $end = null) {
		$this->start = $start;
		$this->end = $end;
	}
}

class ArrayOfNumericRange extends phpDynamicProperties {
	public $NumericRange; //NumericRange

	function __construct($NumericRange = null) {
		$this->NumericRange = $NumericRange;
	}
}

class OvfConsumerOvfSection extends phpDynamicProperties {
	public $lineNumber; //int
	public $xml; //string

	function __construct($lineNumber = null, $xml = null) {
		$this->lineNumber = $lineNumber;
		$this->xml = $xml;
	}
}

class ArrayOfOvfConsumerOvfSection extends phpDynamicProperties {
	public $OvfConsumerOvfSection; //OvfConsumerOvfSection

	function __construct($OvfConsumerOvfSection = null) {
		$this->OvfConsumerOvfSection = $OvfConsumerOvfSection;
	}
}

class OvfConsumerOstNode extends phpDynamicProperties {
	public $id; //string
	public $type; //string
	public $section; //OvfConsumerOvfSection
	public $child; //OvfConsumerOstNode
	public $entity; //ManagedObjectReference

	function __construct($id = null, $type = null, $section = null, $child = null, $entity = null) {
		$this->id = $id;
		$this->type = $type;
		$this->section = $section;
		$this->child = $child;
		$this->entity = $entity;
	}
}

class ArrayOfOvfConsumerOstNode extends phpDynamicProperties {
	public $OvfConsumerOstNode; //OvfConsumerOstNode

	function __construct($OvfConsumerOstNode = null) {
		$this->OvfConsumerOstNode = $OvfConsumerOstNode;
	}
}

class OvfDeploymentOption extends phpDynamicProperties {
	public $key; //string
	public $label; //string
	public $description; //string

	function __construct($key = null, $label = null, $description = null) {
		$this->key = $key;
		$this->label = $label;
		$this->description = $description;
	}
}

class ArrayOfOvfDeploymentOption extends phpDynamicProperties {
	public $OvfDeploymentOption; //OvfDeploymentOption

	function __construct($OvfDeploymentOption = null) {
		$this->OvfDeploymentOption = $OvfDeploymentOption;
	}
}

class OvfManagerCommonParams extends phpDynamicProperties {
	public $locale; //string
	public $deploymentOption; //string
	public $msgBundle; //KeyValue

	function __construct($locale = null, $deploymentOption = null, $msgBundle = null) {
		$this->locale = $locale;
		$this->deploymentOption = $deploymentOption;
		$this->msgBundle = $msgBundle;
	}
}

class OvfValidateHostParams extends phpDynamicProperties {
}

class OvfValidateHostResult extends phpDynamicProperties {
	public $downloadSize; //long
	public $flatDeploymentSize; //long
	public $sparseDeploymentSize; //long
	public $error; //LocalizedMethodFault
	public $warning; //LocalizedMethodFault
	public $supportedDiskProvisioning; //string

	function __construct($downloadSize = null, $flatDeploymentSize = null, $sparseDeploymentSize = null, $error = null, $warning = null, $supportedDiskProvisioning = null) {
		$this->downloadSize = $downloadSize;
		$this->flatDeploymentSize = $flatDeploymentSize;
		$this->sparseDeploymentSize = $sparseDeploymentSize;
		$this->error = $error;
		$this->warning = $warning;
		$this->supportedDiskProvisioning = $supportedDiskProvisioning;
	}
}

class OvfParseDescriptorParams extends phpDynamicProperties {
}

class OvfParseDescriptorResult extends phpDynamicProperties {
	public $eula; //string
	public $network; //OvfNetworkInfo
	public $ipAllocationScheme; //string
	public $ipProtocols; //string
	public $property; //VAppPropertyInfo
	public $productInfo; //VAppProductInfo
	public $annotation; //string
	public $approximateDownloadSize; //long
	public $approximateFlatDeploymentSize; //long
	public $approximateSparseDeploymentSize; //long
	public $defaultEntityName; //string
	public $virtualApp; //boolean
	public $deploymentOption; //OvfDeploymentOption
	public $defaultDeploymentOption; //string
	public $entityName; //KeyValue
	public $annotatedOst; //OvfConsumerOstNode
	public $error; //LocalizedMethodFault
	public $warning; //LocalizedMethodFault

	function __construct($eula = null, $network = null, $ipAllocationScheme = null, $ipProtocols = null, $property = null, $productInfo = null, $annotation = null, $approximateDownloadSize = null, $approximateFlatDeploymentSize = null, $approximateSparseDeploymentSize = null, $defaultEntityName = null, $virtualApp = null, $deploymentOption = null, $defaultDeploymentOption = null, $entityName = null, $annotatedOst = null, $error = null, $warning = null) {
		$this->eula = $eula;
		$this->network = $network;
		$this->ipAllocationScheme = $ipAllocationScheme;
		$this->ipProtocols = $ipProtocols;
		$this->property = $property;
		$this->productInfo = $productInfo;
		$this->annotation = $annotation;
		$this->approximateDownloadSize = $approximateDownloadSize;
		$this->approximateFlatDeploymentSize = $approximateFlatDeploymentSize;
		$this->approximateSparseDeploymentSize = $approximateSparseDeploymentSize;
		$this->defaultEntityName = $defaultEntityName;
		$this->virtualApp = $virtualApp;
		$this->deploymentOption = $deploymentOption;
		$this->defaultDeploymentOption = $defaultDeploymentOption;
		$this->entityName = $entityName;
		$this->annotatedOst = $annotatedOst;
		$this->error = $error;
		$this->warning = $warning;
	}
}

class OvfNetworkInfo extends phpDynamicProperties {
	public $name; //string
	public $description; //string

	function __construct($name = null, $description = null) {
		$this->name = $name;
		$this->description = $description;
	}
}

class ArrayOfOvfNetworkInfo extends phpDynamicProperties {
	public $OvfNetworkInfo; //OvfNetworkInfo

	function __construct($OvfNetworkInfo = null) {
		$this->OvfNetworkInfo = $OvfNetworkInfo;
	}
}

class OvfCreateImportSpecParams extends phpDynamicProperties {
	public $entityName; //string
	public $hostSystem; //ManagedObjectReference
	public $networkMapping; //OvfNetworkMapping
	public $ipAllocationPolicy; //string
	public $ipProtocol; //string
	public $propertyMapping; //KeyValue
	public $resourceMapping; //OvfResourceMap
	public $diskProvisioning; //string
	public $instantiationOst; //OvfConsumerOstNode

	function __construct($entityName = null, $hostSystem = null, $networkMapping = null, $ipAllocationPolicy = null, $ipProtocol = null, $propertyMapping = null, $resourceMapping = null, $diskProvisioning = null, $instantiationOst = null) {
		$this->entityName = $entityName;
		$this->hostSystem = $hostSystem;
		$this->networkMapping = $networkMapping;
		$this->ipAllocationPolicy = $ipAllocationPolicy;
		$this->ipProtocol = $ipProtocol;
		$this->propertyMapping = $propertyMapping;
		$this->resourceMapping = $resourceMapping;
		$this->diskProvisioning = $diskProvisioning;
		$this->instantiationOst = $instantiationOst;
	}
}

class OvfResourceMap extends phpDynamicProperties {
	public $source; //string
	public $parent; //ManagedObjectReference
	public $resourceSpec; //ResourceConfigSpec
	public $datastore; //ManagedObjectReference

	function __construct($source = null, $parent = null, $resourceSpec = null, $datastore = null) {
		$this->source = $source;
		$this->parent = $parent;
		$this->resourceSpec = $resourceSpec;
		$this->datastore = $datastore;
	}
}

class ArrayOfOvfResourceMap extends phpDynamicProperties {
	public $OvfResourceMap; //OvfResourceMap

	function __construct($OvfResourceMap = null) {
		$this->OvfResourceMap = $OvfResourceMap;
	}
}

class OvfNetworkMapping extends phpDynamicProperties {
	public $name; //string
	public $network; //ManagedObjectReference

	function __construct($name = null, $network = null) {
		$this->name = $name;
		$this->network = $network;
	}
}

class ArrayOfOvfNetworkMapping extends phpDynamicProperties {
	public $OvfNetworkMapping; //OvfNetworkMapping

	function __construct($OvfNetworkMapping = null) {
		$this->OvfNetworkMapping = $OvfNetworkMapping;
	}
}

class OvfCreateImportSpecResult extends phpDynamicProperties {
	public $importSpec; //ImportSpec
	public $fileItem; //OvfFileItem
	public $warning; //LocalizedMethodFault
	public $error; //LocalizedMethodFault

	function __construct($importSpec = null, $fileItem = null, $warning = null, $error = null) {
		$this->importSpec = $importSpec;
		$this->fileItem = $fileItem;
		$this->warning = $warning;
		$this->error = $error;
	}
}

class OvfFileItem extends phpDynamicProperties {
	public $deviceId; //string
	public $path; //string
	public $compressionMethod; //string
	public $chunkSize; //long
	public $size; //long
	public $cimType; //int
	public $create; //boolean

	function __construct($deviceId = null, $path = null, $compressionMethod = null, $chunkSize = null, $size = null, $cimType = null, $create = null) {
		$this->deviceId = $deviceId;
		$this->path = $path;
		$this->compressionMethod = $compressionMethod;
		$this->chunkSize = $chunkSize;
		$this->size = $size;
		$this->cimType = $cimType;
		$this->create = $create;
	}
}

class ArrayOfOvfFileItem extends phpDynamicProperties {
	public $OvfFileItem; //OvfFileItem

	function __construct($OvfFileItem = null) {
		$this->OvfFileItem = $OvfFileItem;
	}
}

class OvfCreateDescriptorParams extends phpDynamicProperties {
	public $ovfFiles; //OvfFile
	public $name; //string
	public $description; //string
	public $includeImageFiles; //boolean

	function __construct($ovfFiles = null, $name = null, $description = null, $includeImageFiles = null) {
		$this->ovfFiles = $ovfFiles;
		$this->name = $name;
		$this->description = $description;
		$this->includeImageFiles = $includeImageFiles;
	}
}

class OvfCreateDescriptorResult extends phpDynamicProperties {
	public $ovfDescriptor; //string
	public $error; //LocalizedMethodFault
	public $warning; //LocalizedMethodFault
	public $includeImageFiles; //boolean

	function __construct($ovfDescriptor = null, $error = null, $warning = null, $includeImageFiles = null) {
		$this->ovfDescriptor = $ovfDescriptor;
		$this->error = $error;
		$this->warning = $warning;
		$this->includeImageFiles = $includeImageFiles;
	}
}

class OvfFile extends phpDynamicProperties {
	public $deviceId; //string
	public $path; //string
	public $compressionMethod; //string
	public $chunkSize; //long
	public $size; //long
	public $capacity; //long
	public $populatedSize; //long

	function __construct($deviceId = null, $path = null, $compressionMethod = null, $chunkSize = null, $size = null, $capacity = null, $populatedSize = null) {
		$this->deviceId = $deviceId;
		$this->path = $path;
		$this->compressionMethod = $compressionMethod;
		$this->chunkSize = $chunkSize;
		$this->size = $size;
		$this->capacity = $capacity;
		$this->populatedSize = $populatedSize;
	}
}

class ArrayOfOvfFile extends phpDynamicProperties {
	public $OvfFile; //OvfFile

	function __construct($OvfFile = null) {
		$this->OvfFile = $OvfFile;
	}
}

class PasswordField extends phpDynamicProperties {
	public $value; //string

	function __construct($value = null) {
		$this->value = $value;
	}
}

class PerformanceDescription extends phpDynamicProperties {
	public $counterType; //ElementDescription
	public $statsType; //ElementDescription

	function __construct($counterType = null, $statsType = null) {
		$this->counterType = $counterType;
		$this->statsType = $statsType;
	}
}

class PerfProviderSummary extends phpDynamicProperties {
	public $entity; //ManagedObjectReference
	public $currentSupported; //boolean
	public $summarySupported; //boolean
	public $refreshRate; //int

	function __construct($entity = null, $currentSupported = null, $summarySupported = null, $refreshRate = null) {
		$this->entity = $entity;
		$this->currentSupported = $currentSupported;
		$this->summarySupported = $summarySupported;
		$this->refreshRate = $refreshRate;
	}
}

class PerfCounterInfo extends phpDynamicProperties {
	public $key; //int
	public $nameInfo; //ElementDescription
	public $groupInfo; //ElementDescription
	public $unitInfo; //ElementDescription
	public $rollupType; //PerfSummaryType
	public $statsType; //PerfStatsType
	public $level; //int
	public $perDeviceLevel; //int
	public $associatedCounterId; //int

	function __construct($key = null, $nameInfo = null, $groupInfo = null, $unitInfo = null, $rollupType = null, $statsType = null, $level = null, $perDeviceLevel = null, $associatedCounterId = null) {
		$this->key = $key;
		$this->nameInfo = $nameInfo;
		$this->groupInfo = $groupInfo;
		$this->unitInfo = $unitInfo;
		$this->rollupType = $rollupType;
		$this->statsType = $statsType;
		$this->level = $level;
		$this->perDeviceLevel = $perDeviceLevel;
		$this->associatedCounterId = $associatedCounterId;
	}
}

class ArrayOfPerfCounterInfo extends phpDynamicProperties {
	public $PerfCounterInfo; //PerfCounterInfo

	function __construct($PerfCounterInfo = null) {
		$this->PerfCounterInfo = $PerfCounterInfo;
	}
}

class PerfMetricId extends phpDynamicProperties {
	public $counterId; //int
	public $instance; //string

	function __construct($counterId = null, $instance = null) {
		$this->counterId = $counterId;
		$this->instance = $instance;
	}
}

class ArrayOfPerfMetricId extends phpDynamicProperties {
	public $PerfMetricId; //PerfMetricId

	function __construct($PerfMetricId = null) {
		$this->PerfMetricId = $PerfMetricId;
	}
}

class PerfQuerySpec extends phpDynamicProperties {
	public $entity; //ManagedObjectReference
	public $startTime; //dateTime
	public $endTime; //dateTime
	public $maxSample; //int
	public $metricId; //PerfMetricId
	public $intervalId; //int
	public $format; //string

	function __construct($entity = null, $startTime = null, $endTime = null, $maxSample = null, $metricId = null, $intervalId = null, $format = null) {
		$this->entity = $entity;
		$this->startTime = $startTime;
		$this->endTime = $endTime;
		$this->maxSample = $maxSample;
		$this->metricId = $metricId;
		$this->intervalId = $intervalId;
		$this->format = $format;
	}
}

class ArrayOfPerfQuerySpec extends phpDynamicProperties {
	public $PerfQuerySpec; //PerfQuerySpec

	function __construct($PerfQuerySpec = null) {
		$this->PerfQuerySpec = $PerfQuerySpec;
	}
}

class PerfSampleInfo extends phpDynamicProperties {
	public $timestamp; //dateTime
	public $interval; //int

	function __construct($timestamp = null, $interval = null) {
		$this->timestamp = $timestamp;
		$this->interval = $interval;
	}
}

class ArrayOfPerfSampleInfo extends phpDynamicProperties {
	public $PerfSampleInfo; //PerfSampleInfo

	function __construct($PerfSampleInfo = null) {
		$this->PerfSampleInfo = $PerfSampleInfo;
	}
}

class PerfMetricSeries extends phpDynamicProperties {
	public $id; //PerfMetricId

	function __construct($id = null) {
		$this->id = $id;
	}
}

class ArrayOfPerfMetricSeries extends phpDynamicProperties {
	public $PerfMetricSeries; //PerfMetricSeries

	function __construct($PerfMetricSeries = null) {
		$this->PerfMetricSeries = $PerfMetricSeries;
	}
}

class PerfMetricIntSeries extends phpDynamicProperties {
	public $value; //long

	function __construct($value = null) {
		$this->value = $value;
	}
}

class PerfMetricSeriesCSV extends phpDynamicProperties {
	public $value; //string

	function __construct($value = null) {
		$this->value = $value;
	}
}

class ArrayOfPerfMetricSeriesCSV extends phpDynamicProperties {
	public $PerfMetricSeriesCSV; //PerfMetricSeriesCSV

	function __construct($PerfMetricSeriesCSV = null) {
		$this->PerfMetricSeriesCSV = $PerfMetricSeriesCSV;
	}
}

class PerfEntityMetricBase extends phpDynamicProperties {
	public $entity; //ManagedObjectReference

	function __construct($entity = null) {
		$this->entity = $entity;
	}
}

class ArrayOfPerfEntityMetricBase extends phpDynamicProperties {
	public $PerfEntityMetricBase; //PerfEntityMetricBase

	function __construct($PerfEntityMetricBase = null) {
		$this->PerfEntityMetricBase = $PerfEntityMetricBase;
	}
}

class PerfEntityMetric extends phpDynamicProperties {
	public $sampleInfo; //PerfSampleInfo
	public $value; //PerfMetricSeries

	function __construct($sampleInfo = null, $value = null) {
		$this->sampleInfo = $sampleInfo;
		$this->value = $value;
	}
}

class PerfEntityMetricCSV extends phpDynamicProperties {
	public $sampleInfoCSV; //string
	public $value; //PerfMetricSeriesCSV

	function __construct($sampleInfoCSV = null, $value = null) {
		$this->sampleInfoCSV = $sampleInfoCSV;
		$this->value = $value;
	}
}

class PerfCompositeMetric extends phpDynamicProperties {
	public $entity; //PerfEntityMetricBase
	public $childEntity; //PerfEntityMetricBase

	function __construct($entity = null, $childEntity = null) {
		$this->entity = $entity;
		$this->childEntity = $childEntity;
	}
}

class PerformanceManagerCounterLevelMapping extends phpDynamicProperties {
	public $counterId; //int
	public $aggregateLevel; //int
	public $perDeviceLevel; //int

	function __construct($counterId = null, $aggregateLevel = null, $perDeviceLevel = null) {
		$this->counterId = $counterId;
		$this->aggregateLevel = $aggregateLevel;
		$this->perDeviceLevel = $perDeviceLevel;
	}
}

class ArrayOfPerformanceManagerCounterLevelMapping extends phpDynamicProperties {
	public $PerformanceManagerCounterLevelMapping; //PerformanceManagerCounterLevelMapping

	function __construct($PerformanceManagerCounterLevelMapping = null) {
		$this->PerformanceManagerCounterLevelMapping = $PerformanceManagerCounterLevelMapping;
	}
}

class PerfInterval extends phpDynamicProperties {
	public $key; //int
	public $samplingPeriod; //int
	public $name; //string
	public $length; //int
	public $level; //int
	public $enabled; //boolean

	function __construct($key = null, $samplingPeriod = null, $name = null, $length = null, $level = null, $enabled = null) {
		$this->key = $key;
		$this->samplingPeriod = $samplingPeriod;
		$this->name = $name;
		$this->length = $length;
		$this->level = $level;
		$this->enabled = $enabled;
	}
}

class ArrayOfPerfInterval extends phpDynamicProperties {
	public $PerfInterval; //PerfInterval

	function __construct($PerfInterval = null) {
		$this->PerfInterval = $PerfInterval;
	}
}

class PosixUserSearchResult extends phpDynamicProperties {
	public $id; //int
	public $shellAccess; //boolean

	function __construct($id = null, $shellAccess = null) {
		$this->id = $id;
		$this->shellAccess = $shellAccess;
	}
}

class PrivilegePolicyDef extends phpDynamicProperties {
	public $createPrivilege; //string
	public $readPrivilege; //string
	public $updatePrivilege; //string
	public $deletePrivilege; //string

	function __construct($createPrivilege = null, $readPrivilege = null, $updatePrivilege = null, $deletePrivilege = null) {
		$this->createPrivilege = $createPrivilege;
		$this->readPrivilege = $readPrivilege;
		$this->updatePrivilege = $updatePrivilege;
		$this->deletePrivilege = $deletePrivilege;
	}
}

class ResourceAllocationInfo extends phpDynamicProperties {
	public $reservation; //long
	public $expandableReservation; //boolean
	public $limit; //long
	public $shares; //SharesInfo
	public $overheadLimit; //long

	function __construct($reservation = null, $expandableReservation = null, $limit = null, $shares = null, $overheadLimit = null) {
		$this->reservation = $reservation;
		$this->expandableReservation = $expandableReservation;
		$this->limit = $limit;
		$this->shares = $shares;
		$this->overheadLimit = $overheadLimit;
	}
}

class ResourceAllocationOption extends phpDynamicProperties {
	public $sharesOption; //SharesOption

	function __construct($sharesOption = null) {
		$this->sharesOption = $sharesOption;
	}
}

class ResourceConfigOption extends phpDynamicProperties {
	public $cpuAllocationOption; //ResourceAllocationOption
	public $memoryAllocationOption; //ResourceAllocationOption

	function __construct($cpuAllocationOption = null, $memoryAllocationOption = null) {
		$this->cpuAllocationOption = $cpuAllocationOption;
		$this->memoryAllocationOption = $memoryAllocationOption;
	}
}

class ResourceConfigSpec extends phpDynamicProperties {
	public $entity; //ManagedObjectReference
	public $changeVersion; //string
	public $lastModified; //dateTime
	public $cpuAllocation; //ResourceAllocationInfo
	public $memoryAllocation; //ResourceAllocationInfo

	function __construct($entity = null, $changeVersion = null, $lastModified = null, $cpuAllocation = null, $memoryAllocation = null) {
		$this->entity = $entity;
		$this->changeVersion = $changeVersion;
		$this->lastModified = $lastModified;
		$this->cpuAllocation = $cpuAllocation;
		$this->memoryAllocation = $memoryAllocation;
	}
}

class ArrayOfResourceConfigSpec extends phpDynamicProperties {
	public $ResourceConfigSpec; //ResourceConfigSpec

	function __construct($ResourceConfigSpec = null) {
		$this->ResourceConfigSpec = $ResourceConfigSpec;
	}
}

class DatabaseSizeParam extends phpDynamicProperties {
	public $inventoryDesc; //InventoryDescription
	public $perfStatsDesc; //PerformanceStatisticsDescription

	function __construct($inventoryDesc = null, $perfStatsDesc = null) {
		$this->inventoryDesc = $inventoryDesc;
		$this->perfStatsDesc = $perfStatsDesc;
	}
}

class InventoryDescription extends phpDynamicProperties {
	public $numHosts; //int
	public $numVirtualMachines; //int
	public $numResourcePools; //int
	public $numClusters; //int
	public $numCpuDev; //int
	public $numNetDev; //int
	public $numDiskDev; //int
	public $numvCpuDev; //int
	public $numvNetDev; //int
	public $numvDiskDev; //int

	function __construct($numHosts = null, $numVirtualMachines = null, $numResourcePools = null, $numClusters = null, $numCpuDev = null, $numNetDev = null, $numDiskDev = null, $numvCpuDev = null, $numvNetDev = null, $numvDiskDev = null) {
		$this->numHosts = $numHosts;
		$this->numVirtualMachines = $numVirtualMachines;
		$this->numResourcePools = $numResourcePools;
		$this->numClusters = $numClusters;
		$this->numCpuDev = $numCpuDev;
		$this->numNetDev = $numNetDev;
		$this->numDiskDev = $numDiskDev;
		$this->numvCpuDev = $numvCpuDev;
		$this->numvNetDev = $numvNetDev;
		$this->numvDiskDev = $numvDiskDev;
	}
}

class PerformanceStatisticsDescription extends phpDynamicProperties {
	public $intervals; //PerfInterval

	function __construct($intervals = null) {
		$this->intervals = $intervals;
	}
}

class DatabaseSizeEstimate extends phpDynamicProperties {
	public $size; //long

	function __construct($size = null) {
		$this->size = $size;
	}
}

class ResourcePoolResourceUsage extends phpDynamicProperties {
	public $reservationUsed; //long
	public $reservationUsedForVm; //long
	public $unreservedForPool; //long
	public $unreservedForVm; //long
	public $overallUsage; //long
	public $maxUsage; //long

	function __construct($reservationUsed = null, $reservationUsedForVm = null, $unreservedForPool = null, $unreservedForVm = null, $overallUsage = null, $maxUsage = null) {
		$this->reservationUsed = $reservationUsed;
		$this->reservationUsedForVm = $reservationUsedForVm;
		$this->unreservedForPool = $unreservedForPool;
		$this->unreservedForVm = $unreservedForVm;
		$this->overallUsage = $overallUsage;
		$this->maxUsage = $maxUsage;
	}
}

class ResourcePoolRuntimeInfo extends phpDynamicProperties {
	public $memory; //ResourcePoolResourceUsage
	public $cpu; //ResourcePoolResourceUsage
	public $overallStatus; //ManagedEntityStatus

	function __construct($memory = null, $cpu = null, $overallStatus = null) {
		$this->memory = $memory;
		$this->cpu = $cpu;
		$this->overallStatus = $overallStatus;
	}
}

class ResourcePoolQuickStats extends phpDynamicProperties {
	public $overallCpuUsage; //long
	public $overallCpuDemand; //long
	public $guestMemoryUsage; //long
	public $hostMemoryUsage; //long
	public $distributedCpuEntitlement; //long
	public $distributedMemoryEntitlement; //long
	public $staticCpuEntitlement; //int
	public $staticMemoryEntitlement; //int
	public $privateMemory; //long
	public $sharedMemory; //long
	public $swappedMemory; //long
	public $balloonedMemory; //long
	public $overheadMemory; //long
	public $consumedOverheadMemory; //long
	public $compressedMemory; //long

	function __construct($overallCpuUsage = null, $overallCpuDemand = null, $guestMemoryUsage = null, $hostMemoryUsage = null, $distributedCpuEntitlement = null, $distributedMemoryEntitlement = null, $staticCpuEntitlement = null, $staticMemoryEntitlement = null, $privateMemory = null, $sharedMemory = null, $swappedMemory = null, $balloonedMemory = null, $overheadMemory = null, $consumedOverheadMemory = null, $compressedMemory = null) {
		$this->overallCpuUsage = $overallCpuUsage;
		$this->overallCpuDemand = $overallCpuDemand;
		$this->guestMemoryUsage = $guestMemoryUsage;
		$this->hostMemoryUsage = $hostMemoryUsage;
		$this->distributedCpuEntitlement = $distributedCpuEntitlement;
		$this->distributedMemoryEntitlement = $distributedMemoryEntitlement;
		$this->staticCpuEntitlement = $staticCpuEntitlement;
		$this->staticMemoryEntitlement = $staticMemoryEntitlement;
		$this->privateMemory = $privateMemory;
		$this->sharedMemory = $sharedMemory;
		$this->swappedMemory = $swappedMemory;
		$this->balloonedMemory = $balloonedMemory;
		$this->overheadMemory = $overheadMemory;
		$this->consumedOverheadMemory = $consumedOverheadMemory;
		$this->compressedMemory = $compressedMemory;
	}
}

class ResourcePoolSummary extends phpDynamicProperties {
	public $name; //string
	public $config; //ResourceConfigSpec
	public $runtime; //ResourcePoolRuntimeInfo
	public $quickStats; //ResourcePoolQuickStats
	public $configuredMemoryMB; //int

	function __construct($name = null, $config = null, $runtime = null, $quickStats = null, $configuredMemoryMB = null) {
		$this->name = $name;
		$this->config = $config;
		$this->runtime = $runtime;
		$this->quickStats = $quickStats;
		$this->configuredMemoryMB = $configuredMemoryMB;
	}
}

class HostVMotionCompatibility extends phpDynamicProperties {
	public $host; //ManagedObjectReference
	public $compatibility; //string

	function __construct($host = null, $compatibility = null) {
		$this->host = $host;
		$this->compatibility = $compatibility;
	}
}

class ArrayOfHostVMotionCompatibility extends phpDynamicProperties {
	public $HostVMotionCompatibility; //HostVMotionCompatibility

	function __construct($HostVMotionCompatibility = null) {
		$this->HostVMotionCompatibility = $HostVMotionCompatibility;
	}
}

class ProductComponentInfo extends phpDynamicProperties {
	public $id; //string
	public $name; //string
	public $version; //string
	public $release; //int

	function __construct($id = null, $name = null, $version = null, $release = null) {
		$this->id = $id;
		$this->name = $name;
		$this->version = $version;
		$this->release = $release;
	}
}

class ArrayOfProductComponentInfo extends phpDynamicProperties {
	public $ProductComponentInfo; //ProductComponentInfo

	function __construct($ProductComponentInfo = null) {
		$this->ProductComponentInfo = $ProductComponentInfo;
	}
}

class ServiceContent extends phpDynamicProperties {
	public $rootFolder; //ManagedObjectReference
	public $propertyCollector; //ManagedObjectReference
	public $viewManager; //ManagedObjectReference
	public $about; //AboutInfo
	public $setting; //ManagedObjectReference
	public $userDirectory; //ManagedObjectReference
	public $sessionManager; //ManagedObjectReference
	public $authorizationManager; //ManagedObjectReference
	public $perfManager; //ManagedObjectReference
	public $scheduledTaskManager; //ManagedObjectReference
	public $alarmManager; //ManagedObjectReference
	public $eventManager; //ManagedObjectReference
	public $taskManager; //ManagedObjectReference
	public $extensionManager; //ManagedObjectReference
	public $customizationSpecManager; //ManagedObjectReference
	public $customFieldsManager; //ManagedObjectReference
	public $accountManager; //ManagedObjectReference
	public $diagnosticManager; //ManagedObjectReference
	public $licenseManager; //ManagedObjectReference
	public $searchIndex; //ManagedObjectReference
	public $fileManager; //ManagedObjectReference
	public $virtualDiskManager; //ManagedObjectReference
	public $virtualizationManager; //ManagedObjectReference
	public $snmpSystem; //ManagedObjectReference
	public $vmProvisioningChecker; //ManagedObjectReference
	public $vmCompatibilityChecker; //ManagedObjectReference
	public $ovfManager; //ManagedObjectReference
	public $ipPoolManager; //ManagedObjectReference
	public $dvSwitchManager; //ManagedObjectReference
	public $hostProfileManager; //ManagedObjectReference
	public $clusterProfileManager; //ManagedObjectReference
	public $complianceManager; //ManagedObjectReference
	public $localizationManager; //ManagedObjectReference
	public $storageResourceManager; //ManagedObjectReference
	public $guestOperationsManager; //ManagedObjectReference

	function __construct($rootFolder = null, $propertyCollector = null, $viewManager = null, $about = null, $setting = null, $userDirectory = null, $sessionManager = null, $authorizationManager = null, $perfManager = null, $scheduledTaskManager = null, $alarmManager = null, $eventManager = null, $taskManager = null, $extensionManager = null, $customizationSpecManager = null, $customFieldsManager = null, $accountManager = null, $diagnosticManager = null, $licenseManager = null, $searchIndex = null, $fileManager = null, $virtualDiskManager = null, $virtualizationManager = null, $snmpSystem = null, $vmProvisioningChecker = null, $vmCompatibilityChecker = null, $ovfManager = null, $ipPoolManager = null, $dvSwitchManager = null, $hostProfileManager = null, $clusterProfileManager = null, $complianceManager = null, $localizationManager = null, $storageResourceManager = null, $guestOperationsManager = null) {
		$this->rootFolder = $rootFolder;
		$this->propertyCollector = $propertyCollector;
		$this->viewManager = $viewManager;
		$this->about = $about;
		$this->setting = $setting;
		$this->userDirectory = $userDirectory;
		$this->sessionManager = $sessionManager;
		$this->authorizationManager = $authorizationManager;
		$this->perfManager = $perfManager;
		$this->scheduledTaskManager = $scheduledTaskManager;
		$this->alarmManager = $alarmManager;
		$this->eventManager = $eventManager;
		$this->taskManager = $taskManager;
		$this->extensionManager = $extensionManager;
		$this->customizationSpecManager = $customizationSpecManager;
		$this->customFieldsManager = $customFieldsManager;
		$this->accountManager = $accountManager;
		$this->diagnosticManager = $diagnosticManager;
		$this->licenseManager = $licenseManager;
		$this->searchIndex = $searchIndex;
		$this->fileManager = $fileManager;
		$this->virtualDiskManager = $virtualDiskManager;
		$this->virtualizationManager = $virtualizationManager;
		$this->snmpSystem = $snmpSystem;
		$this->vmProvisioningChecker = $vmProvisioningChecker;
		$this->vmCompatibilityChecker = $vmCompatibilityChecker;
		$this->ovfManager = $ovfManager;
		$this->ipPoolManager = $ipPoolManager;
		$this->dvSwitchManager = $dvSwitchManager;
		$this->hostProfileManager = $hostProfileManager;
		$this->clusterProfileManager = $clusterProfileManager;
		$this->complianceManager = $complianceManager;
		$this->localizationManager = $localizationManager;
		$this->storageResourceManager = $storageResourceManager;
		$this->guestOperationsManager = $guestOperationsManager;
	}
}

class SessionManagerLocalTicket extends phpDynamicProperties {
	public $userName; //string
	public $passwordFilePath; //string

	function __construct($userName = null, $passwordFilePath = null) {
		$this->userName = $userName;
		$this->passwordFilePath = $passwordFilePath;
	}
}

class SessionManagerGenericServiceTicket extends phpDynamicProperties {
	public $id; //string

	function __construct($id = null) {
		$this->id = $id;
	}
}

class SessionManagerServiceRequestSpec extends phpDynamicProperties {
}

class SessionManagerHttpServiceRequestSpec extends phpDynamicProperties {
	public $method; //string
	public $url; //string

	function __construct($method = null, $url = null) {
		$this->method = $method;
		$this->url = $url;
	}
}

class UserSession extends phpDynamicProperties {
	public $key; //string
	public $userName; //string
	public $fullName; //string
	public $loginTime; //dateTime
	public $lastActiveTime; //dateTime
	public $locale; //string
	public $messageLocale; //string
	public $extensionSession; //boolean

	function __construct($key = null, $userName = null, $fullName = null, $loginTime = null, $lastActiveTime = null, $locale = null, $messageLocale = null, $extensionSession = null) {
		$this->key = $key;
		$this->userName = $userName;
		$this->fullName = $fullName;
		$this->loginTime = $loginTime;
		$this->lastActiveTime = $lastActiveTime;
		$this->locale = $locale;
		$this->messageLocale = $messageLocale;
		$this->extensionSession = $extensionSession;
	}
}

class ArrayOfUserSession extends phpDynamicProperties {
	public $UserSession; //UserSession

	function __construct($UserSession = null) {
		$this->UserSession = $UserSession;
	}
}

class SharesInfo extends phpDynamicProperties {
	public $shares; //int
	public $level; //SharesLevel

	function __construct($shares = null, $level = null) {
		$this->shares = $shares;
		$this->level = $level;
	}
}

class SharesOption extends phpDynamicProperties {
	public $sharesOption; //IntOption
	public $defaultLevel; //SharesLevel

	function __construct($sharesOption = null, $defaultLevel = null) {
		$this->sharesOption = $sharesOption;
		$this->defaultLevel = $defaultLevel;
	}
}

class StoragePodSummary extends phpDynamicProperties {
	public $name; //string
	public $capacity; //long
	public $freeSpace; //long

	function __construct($name = null, $capacity = null, $freeSpace = null) {
		$this->name = $name;
		$this->capacity = $capacity;
		$this->freeSpace = $freeSpace;
	}
}

class StorageIOAllocationInfo extends phpDynamicProperties {
	public $limit; //long
	public $shares; //SharesInfo

	function __construct($limit = null, $shares = null) {
		$this->limit = $limit;
		$this->shares = $shares;
	}
}

class StorageIOAllocationOption extends phpDynamicProperties {
	public $limitOption; //LongOption
	public $sharesOption; //SharesOption

	function __construct($limitOption = null, $sharesOption = null) {
		$this->limitOption = $limitOption;
		$this->sharesOption = $sharesOption;
	}
}

class StorageIORMInfo extends phpDynamicProperties {
	public $enabled; //boolean
	public $congestionThreshold; //int
	public $statsCollectionEnabled; //boolean
	public $statsAggregationDisabled; //boolean

	function __construct($enabled = null, $congestionThreshold = null, $statsCollectionEnabled = null, $statsAggregationDisabled = null) {
		$this->enabled = $enabled;
		$this->congestionThreshold = $congestionThreshold;
		$this->statsCollectionEnabled = $statsCollectionEnabled;
		$this->statsAggregationDisabled = $statsAggregationDisabled;
	}
}

class StorageIORMConfigSpec extends phpDynamicProperties {
	public $enabled; //boolean
	public $congestionThreshold; //int
	public $statsCollectionEnabled; //boolean
	public $statsAggregationDisabled; //boolean

	function __construct($enabled = null, $congestionThreshold = null, $statsCollectionEnabled = null, $statsAggregationDisabled = null) {
		$this->enabled = $enabled;
		$this->congestionThreshold = $congestionThreshold;
		$this->statsCollectionEnabled = $statsCollectionEnabled;
		$this->statsAggregationDisabled = $statsAggregationDisabled;
	}
}

class StorageIORMConfigOption extends phpDynamicProperties {
	public $enabledOption; //BoolOption
	public $congestionThresholdOption; //IntOption
	public $statsCollectionEnabledOption; //BoolOption

	function __construct($enabledOption = null, $congestionThresholdOption = null, $statsCollectionEnabledOption = null) {
		$this->enabledOption = $enabledOption;
		$this->congestionThresholdOption = $congestionThresholdOption;
		$this->statsCollectionEnabledOption = $statsCollectionEnabledOption;
	}
}

class PodStorageDrsEntry extends phpDynamicProperties {
	public $storageDrsConfig; //StorageDrsConfigInfo
	public $recommendation; //ClusterRecommendation
	public $drsFault; //ClusterDrsFaults
	public $actionHistory; //ClusterActionHistory

	function __construct($storageDrsConfig = null, $recommendation = null, $drsFault = null, $actionHistory = null) {
		$this->storageDrsConfig = $storageDrsConfig;
		$this->recommendation = $recommendation;
		$this->drsFault = $drsFault;
		$this->actionHistory = $actionHistory;
	}
}

class StringPolicy extends phpDynamicProperties {
	public $value; //string

	function __construct($value = null) {
		$this->value = $value;
	}
}

class Tag extends phpDynamicProperties {
	public $key; //string

	function __construct($key = null) {
		$this->key = $key;
	}
}

class ArrayOfTag extends phpDynamicProperties {
	public $Tag; //Tag

	function __construct($Tag = null) {
		$this->Tag = $Tag;
	}
}

class TaskDescription extends phpDynamicProperties {
	public $methodInfo; //ElementDescription
	public $state; //ElementDescription
	public $reason; //TypeDescription

	function __construct($methodInfo = null, $state = null, $reason = null) {
		$this->methodInfo = $methodInfo;
		$this->state = $state;
		$this->reason = $reason;
	}
}

class TaskFilterSpecByEntity extends phpDynamicProperties {
	public $entity; //ManagedObjectReference
	public $recursion; //TaskFilterSpecRecursionOption

	function __construct($entity = null, $recursion = null) {
		$this->entity = $entity;
		$this->recursion = $recursion;
	}
}

class TaskFilterSpecByTime extends phpDynamicProperties {
	public $timeType; //TaskFilterSpecTimeOption
	public $beginTime; //dateTime
	public $endTime; //dateTime

	function __construct($timeType = null, $beginTime = null, $endTime = null) {
		$this->timeType = $timeType;
		$this->beginTime = $beginTime;
		$this->endTime = $endTime;
	}
}

class TaskFilterSpecByUsername extends phpDynamicProperties {
	public $systemUser; //boolean
	public $userList; //string

	function __construct($systemUser = null, $userList = null) {
		$this->systemUser = $systemUser;
		$this->userList = $userList;
	}
}

class TaskFilterSpec extends phpDynamicProperties {
	public $entity; //TaskFilterSpecByEntity
	public $time; //TaskFilterSpecByTime
	public $userName; //TaskFilterSpecByUsername
	public $state; //TaskInfoState
	public $alarm; //ManagedObjectReference
	public $scheduledTask; //ManagedObjectReference
	public $eventChainId; //int
	public $tag; //string
	public $parentTaskKey; //string
	public $rootTaskKey; //string

	function __construct($entity = null, $time = null, $userName = null, $state = null, $alarm = null, $scheduledTask = null, $eventChainId = null, $tag = null, $parentTaskKey = null, $rootTaskKey = null) {
		$this->entity = $entity;
		$this->time = $time;
		$this->userName = $userName;
		$this->state = $state;
		$this->alarm = $alarm;
		$this->scheduledTask = $scheduledTask;
		$this->eventChainId = $eventChainId;
		$this->tag = $tag;
		$this->parentTaskKey = $parentTaskKey;
		$this->rootTaskKey = $rootTaskKey;
	}
}

class ArrayOfTaskInfoState extends phpDynamicProperties {
	public $TaskInfoState; //TaskInfoState

	function __construct($TaskInfoState = null) {
		$this->TaskInfoState = $TaskInfoState;
	}
}

class TaskInfo extends phpDynamicProperties {
	public $key; //string
	public $task; //ManagedObjectReference
	public $description; //LocalizableMessage
	public $name; //string
	public $descriptionId; //string
	public $entity; //ManagedObjectReference
	public $entityName; //string
	public $locked; //ManagedObjectReference
	public $state; //TaskInfoState
	public $cancelled; //boolean
	public $cancelable; //boolean
	public $error; //LocalizedMethodFault
	public $result; //anyType
	public $progress; //int
	public $reason; //TaskReason
	public $queueTime; //dateTime
	public $startTime; //dateTime
	public $completeTime; //dateTime
	public $eventChainId; //int
	public $changeTag; //string
	public $parentTaskKey; //string
	public $rootTaskKey; //string

	function __construct($key = null, $task = null, $description = null, $name = null, $descriptionId = null, $entity = null, $entityName = null, $locked = null, $state = null, $cancelled = null, $cancelable = null, $error = null, $result = null, $progress = null, $reason = null, $queueTime = null, $startTime = null, $completeTime = null, $eventChainId = null, $changeTag = null, $parentTaskKey = null, $rootTaskKey = null) {
		$this->key = $key;
		$this->task = $task;
		$this->description = $description;
		$this->name = $name;
		$this->descriptionId = $descriptionId;
		$this->entity = $entity;
		$this->entityName = $entityName;
		$this->locked = $locked;
		$this->state = $state;
		$this->cancelled = $cancelled;
		$this->cancelable = $cancelable;
		$this->error = $error;
		$this->result = $result;
		$this->progress = $progress;
		$this->reason = $reason;
		$this->queueTime = $queueTime;
		$this->startTime = $startTime;
		$this->completeTime = $completeTime;
		$this->eventChainId = $eventChainId;
		$this->changeTag = $changeTag;
		$this->parentTaskKey = $parentTaskKey;
		$this->rootTaskKey = $rootTaskKey;
	}
}

class ArrayOfTaskInfo extends phpDynamicProperties {
	public $TaskInfo; //TaskInfo

	function __construct($TaskInfo = null) {
		$this->TaskInfo = $TaskInfo;
	}
}

class TaskReason extends phpDynamicProperties {
}

class TaskReasonSystem extends phpDynamicProperties {
}

class TaskReasonUser extends phpDynamicProperties {
	public $userName; //string

	function __construct($userName = null) {
		$this->userName = $userName;
	}
}

class TaskReasonAlarm extends phpDynamicProperties {
	public $alarmName; //string
	public $alarm; //ManagedObjectReference
	public $entityName; //string
	public $entity; //ManagedObjectReference

	function __construct($alarmName = null, $alarm = null, $entityName = null, $entity = null) {
		$this->alarmName = $alarmName;
		$this->alarm = $alarm;
		$this->entityName = $entityName;
		$this->entity = $entity;
	}
}

class TaskReasonSchedule extends phpDynamicProperties {
	public $name; //string
	public $scheduledTask; //ManagedObjectReference

	function __construct($name = null, $scheduledTask = null) {
		$this->name = $name;
		$this->scheduledTask = $scheduledTask;
	}
}

class TypeDescription extends phpDynamicProperties {
	public $key; //string

	function __construct($key = null) {
		$this->key = $key;
	}
}

class ArrayOfTypeDescription extends phpDynamicProperties {
	public $TypeDescription; //TypeDescription

	function __construct($TypeDescription = null) {
		$this->TypeDescription = $TypeDescription;
	}
}

class UpdateVirtualMachineFilesResultFailedVmFileInfo extends phpDynamicProperties {
	public $vmFile; //string
	public $fault; //LocalizedMethodFault

	function __construct($vmFile = null, $fault = null) {
		$this->vmFile = $vmFile;
		$this->fault = $fault;
	}
}

class ArrayOfUpdateVirtualMachineFilesResultFailedVmFileInfo extends phpDynamicProperties {
	public $UpdateVirtualMachineFilesResultFailedVmFileInfo; //UpdateVirtualMachineFilesResultFailedVmFileInfo

	function __construct($UpdateVirtualMachineFilesResultFailedVmFileInfo = null) {
		$this->UpdateVirtualMachineFilesResultFailedVmFileInfo = $UpdateVirtualMachineFilesResultFailedVmFileInfo;
	}
}

class UpdateVirtualMachineFilesResult extends phpDynamicProperties {
	public $failedVmFile; //UpdateVirtualMachineFilesResultFailedVmFileInfo

	function __construct($failedVmFile = null) {
		$this->failedVmFile = $failedVmFile;
	}
}

class UserSearchResult extends phpDynamicProperties {
	public $principal; //string
	public $fullName; //string
	public $group; //boolean

	function __construct($principal = null, $fullName = null, $group = null) {
		$this->principal = $principal;
		$this->fullName = $fullName;
		$this->group = $group;
	}
}

class ArrayOfUserSearchResult extends phpDynamicProperties {
	public $UserSearchResult; //UserSearchResult

	function __construct($UserSearchResult = null) {
		$this->UserSearchResult = $UserSearchResult;
	}
}

class VirtualAppSummary extends phpDynamicProperties {
	public $product; //VAppProductInfo
	public $vAppState; //VirtualAppVAppState
	public $suspended; //boolean
	public $installBootRequired; //boolean
	public $instanceUuid; //string

	function __construct($product = null, $vAppState = null, $suspended = null, $installBootRequired = null, $instanceUuid = null) {
		$this->product = $product;
		$this->vAppState = $vAppState;
		$this->suspended = $suspended;
		$this->installBootRequired = $installBootRequired;
		$this->instanceUuid = $instanceUuid;
	}
}

class VirtualAppLinkInfo extends phpDynamicProperties {
	public $key; //ManagedObjectReference
	public $destroyWithParent; //boolean

	function __construct($key = null, $destroyWithParent = null) {
		$this->key = $key;
		$this->destroyWithParent = $destroyWithParent;
	}
}

class ArrayOfVirtualAppLinkInfo extends phpDynamicProperties {
	public $VirtualAppLinkInfo; //VirtualAppLinkInfo

	function __construct($VirtualAppLinkInfo = null) {
		$this->VirtualAppLinkInfo = $VirtualAppLinkInfo;
	}
}

class VirtualDiskSpec extends phpDynamicProperties {
	public $diskType; //string
	public $adapterType; //string

	function __construct($diskType = null, $adapterType = null) {
		$this->diskType = $diskType;
		$this->adapterType = $adapterType;
	}
}

class FileBackedVirtualDiskSpec extends phpDynamicProperties {
	public $capacityKb; //long

	function __construct($capacityKb = null) {
		$this->capacityKb = $capacityKb;
	}
}

class DeviceBackedVirtualDiskSpec extends phpDynamicProperties {
	public $device; //string

	function __construct($device = null) {
		$this->device = $device;
	}
}

class StorageRequirement extends phpDynamicProperties {
	public $datastore; //ManagedObjectReference
	public $freeSpaceRequiredInKb; //long

	function __construct($datastore = null, $freeSpaceRequiredInKb = null) {
		$this->datastore = $datastore;
		$this->freeSpaceRequiredInKb = $freeSpaceRequiredInKb;
	}
}

class ArrayOfStorageRequirement extends phpDynamicProperties {
	public $StorageRequirement; //StorageRequirement

	function __construct($StorageRequirement = null) {
		$this->StorageRequirement = $StorageRequirement;
	}
}

class VirtualMachineTicket extends phpDynamicProperties {
	public $ticket; //string
	public $cfgFile; //string
	public $host; //string
	public $port; //int
	public $sslThumbprint; //string

	function __construct($ticket = null, $cfgFile = null, $host = null, $port = null, $sslThumbprint = null) {
		$this->ticket = $ticket;
		$this->cfgFile = $cfgFile;
		$this->host = $host;
		$this->port = $port;
		$this->sslThumbprint = $sslThumbprint;
	}
}

class VirtualMachineMksTicket extends phpDynamicProperties {
	public $ticket; //string
	public $cfgFile; //string
	public $host; //string
	public $port; //int
	public $sslThumbprint; //string

	function __construct($ticket = null, $cfgFile = null, $host = null, $port = null, $sslThumbprint = null) {
		$this->ticket = $ticket;
		$this->cfgFile = $cfgFile;
		$this->host = $host;
		$this->port = $port;
		$this->sslThumbprint = $sslThumbprint;
	}
}

class VirtualMachineDisplayTopology extends phpDynamicProperties {
	public $x; //int
	public $y; //int
	public $width; //int
	public $height; //int

	function __construct($x = null, $y = null, $width = null, $height = null) {
		$this->x = $x;
		$this->y = $y;
		$this->width = $width;
		$this->height = $height;
	}
}

class ArrayOfVirtualMachineDisplayTopology extends phpDynamicProperties {
	public $VirtualMachineDisplayTopology; //VirtualMachineDisplayTopology

	function __construct($VirtualMachineDisplayTopology = null) {
		$this->VirtualMachineDisplayTopology = $VirtualMachineDisplayTopology;
	}
}

class DiskChangeExtent extends phpDynamicProperties {
	public $start; //long
	public $length; //long

	function __construct($start = null, $length = null) {
		$this->start = $start;
		$this->length = $length;
	}
}

class ArrayOfDiskChangeExtent extends phpDynamicProperties {
	public $DiskChangeExtent; //DiskChangeExtent

	function __construct($DiskChangeExtent = null) {
		$this->DiskChangeExtent = $DiskChangeExtent;
	}
}

class DiskChangeInfo extends phpDynamicProperties {
	public $startOffset; //long
	public $length; //long
	public $changedArea; //DiskChangeExtent

	function __construct($startOffset = null, $length = null, $changedArea = null) {
		$this->startOffset = $startOffset;
		$this->length = $length;
		$this->changedArea = $changedArea;
	}
}

class Action extends phpDynamicProperties {
}

class MethodActionArgument extends phpDynamicProperties {
	public $value; //anyType

	function __construct($value = null) {
		$this->value = $value;
	}
}

class ArrayOfMethodActionArgument extends phpDynamicProperties {
	public $MethodActionArgument; //MethodActionArgument

	function __construct($MethodActionArgument = null) {
		$this->MethodActionArgument = $MethodActionArgument;
	}
}

class MethodAction extends phpDynamicProperties {
	public $name; //string
	public $argument; //MethodActionArgument

	function __construct($name = null, $argument = null) {
		$this->name = $name;
		$this->argument = $argument;
	}
}

class SendEmailAction extends phpDynamicProperties {
	public $toList; //string
	public $ccList; //string
	public $subject; //string
	public $body; //string

	function __construct($toList = null, $ccList = null, $subject = null, $body = null) {
		$this->toList = $toList;
		$this->ccList = $ccList;
		$this->subject = $subject;
		$this->body = $body;
	}
}

class SendSNMPAction extends phpDynamicProperties {
}

class RunScriptAction extends phpDynamicProperties {
	public $script; //string

	function __construct($script = null) {
		$this->script = $script;
	}
}

class CreateTaskAction extends phpDynamicProperties {
	public $taskTypeId; //string
	public $cancelable; //boolean

	function __construct($taskTypeId = null, $cancelable = null) {
		$this->taskTypeId = $taskTypeId;
		$this->cancelable = $cancelable;
	}
}

class AlarmAction extends phpDynamicProperties {
}

class ArrayOfAlarmAction extends phpDynamicProperties {
	public $AlarmAction; //AlarmAction

	function __construct($AlarmAction = null) {
		$this->AlarmAction = $AlarmAction;
	}
}

class AlarmTriggeringActionTransitionSpec extends phpDynamicProperties {
	public $startState; //ManagedEntityStatus
	public $finalState; //ManagedEntityStatus
	public $repeats; //boolean

	function __construct($startState = null, $finalState = null, $repeats = null) {
		$this->startState = $startState;
		$this->finalState = $finalState;
		$this->repeats = $repeats;
	}
}

class ArrayOfAlarmTriggeringActionTransitionSpec extends phpDynamicProperties {
	public $AlarmTriggeringActionTransitionSpec; //AlarmTriggeringActionTransitionSpec

	function __construct($AlarmTriggeringActionTransitionSpec = null) {
		$this->AlarmTriggeringActionTransitionSpec = $AlarmTriggeringActionTransitionSpec;
	}
}

class AlarmTriggeringAction extends phpDynamicProperties {
	public $action; //Action
	public $transitionSpecs; //AlarmTriggeringActionTransitionSpec
	public $green2yellow; //boolean
	public $yellow2red; //boolean
	public $red2yellow; //boolean
	public $yellow2green; //boolean

	function __construct($action = null, $transitionSpecs = null, $green2yellow = null, $yellow2red = null, $red2yellow = null, $yellow2green = null) {
		$this->action = $action;
		$this->transitionSpecs = $transitionSpecs;
		$this->green2yellow = $green2yellow;
		$this->yellow2red = $yellow2red;
		$this->red2yellow = $red2yellow;
		$this->yellow2green = $yellow2green;
	}
}

class GroupAlarmAction extends phpDynamicProperties {
	public $action; //AlarmAction

	function __construct($action = null) {
		$this->action = $action;
	}
}

class AlarmDescription extends phpDynamicProperties {
	public $expr; //TypeDescription
	public $stateOperator; //ElementDescription
	public $metricOperator; //ElementDescription
	public $hostSystemConnectionState; //ElementDescription
	public $virtualMachinePowerState; //ElementDescription
	public $datastoreConnectionState; //ElementDescription
	public $hostSystemPowerState; //ElementDescription
	public $virtualMachineGuestHeartbeatStatus; //ElementDescription
	public $entityStatus; //ElementDescription
	public $action; //TypeDescription

	function __construct($expr = null, $stateOperator = null, $metricOperator = null, $hostSystemConnectionState = null, $virtualMachinePowerState = null, $datastoreConnectionState = null, $hostSystemPowerState = null, $virtualMachineGuestHeartbeatStatus = null, $entityStatus = null, $action = null) {
		$this->expr = $expr;
		$this->stateOperator = $stateOperator;
		$this->metricOperator = $metricOperator;
		$this->hostSystemConnectionState = $hostSystemConnectionState;
		$this->virtualMachinePowerState = $virtualMachinePowerState;
		$this->datastoreConnectionState = $datastoreConnectionState;
		$this->hostSystemPowerState = $hostSystemPowerState;
		$this->virtualMachineGuestHeartbeatStatus = $virtualMachineGuestHeartbeatStatus;
		$this->entityStatus = $entityStatus;
		$this->action = $action;
	}
}

class AlarmExpression extends phpDynamicProperties {
}

class ArrayOfAlarmExpression extends phpDynamicProperties {
	public $AlarmExpression; //AlarmExpression

	function __construct($AlarmExpression = null) {
		$this->AlarmExpression = $AlarmExpression;
	}
}

class AndAlarmExpression extends phpDynamicProperties {
	public $expression; //AlarmExpression

	function __construct($expression = null) {
		$this->expression = $expression;
	}
}

class OrAlarmExpression extends phpDynamicProperties {
	public $expression; //AlarmExpression

	function __construct($expression = null) {
		$this->expression = $expression;
	}
}

class StateAlarmExpression extends phpDynamicProperties {
	public $operator; //StateAlarmOperator
	public $type; //string
	public $statePath; //string
	public $yellow; //string
	public $red; //string

	function __construct($operator = null, $type = null, $statePath = null, $yellow = null, $red = null) {
		$this->operator = $operator;
		$this->type = $type;
		$this->statePath = $statePath;
		$this->yellow = $yellow;
		$this->red = $red;
	}
}

class EventAlarmExpressionComparison extends phpDynamicProperties {
	public $attributeName; //string
	public $operator; //string
	public $value; //string

	function __construct($attributeName = null, $operator = null, $value = null) {
		$this->attributeName = $attributeName;
		$this->operator = $operator;
		$this->value = $value;
	}
}

class ArrayOfEventAlarmExpressionComparison extends phpDynamicProperties {
	public $EventAlarmExpressionComparison; //EventAlarmExpressionComparison

	function __construct($EventAlarmExpressionComparison = null) {
		$this->EventAlarmExpressionComparison = $EventAlarmExpressionComparison;
	}
}

class EventAlarmExpression extends phpDynamicProperties {
	public $comparisons; //EventAlarmExpressionComparison
	public $eventType; //string
	public $eventTypeId; //string
	public $objectType; //string
	public $status; //ManagedEntityStatus

	function __construct($comparisons = null, $eventType = null, $eventTypeId = null, $objectType = null, $status = null) {
		$this->comparisons = $comparisons;
		$this->eventType = $eventType;
		$this->eventTypeId = $eventTypeId;
		$this->objectType = $objectType;
		$this->status = $status;
	}
}

class MetricAlarmExpression extends phpDynamicProperties {
	public $operator; //MetricAlarmOperator
	public $type; //string
	public $metric; //PerfMetricId
	public $yellow; //int
	public $yellowInterval; //int
	public $red; //int
	public $redInterval; //int

	function __construct($operator = null, $type = null, $metric = null, $yellow = null, $yellowInterval = null, $red = null, $redInterval = null) {
		$this->operator = $operator;
		$this->type = $type;
		$this->metric = $metric;
		$this->yellow = $yellow;
		$this->yellowInterval = $yellowInterval;
		$this->red = $red;
		$this->redInterval = $redInterval;
	}
}

class AlarmInfo extends phpDynamicProperties {
	public $key; //string
	public $alarm; //ManagedObjectReference
	public $entity; //ManagedObjectReference
	public $lastModifiedTime; //dateTime
	public $lastModifiedUser; //string
	public $creationEventId; //int

	function __construct($key = null, $alarm = null, $entity = null, $lastModifiedTime = null, $lastModifiedUser = null, $creationEventId = null) {
		$this->key = $key;
		$this->alarm = $alarm;
		$this->entity = $entity;
		$this->lastModifiedTime = $lastModifiedTime;
		$this->lastModifiedUser = $lastModifiedUser;
		$this->creationEventId = $creationEventId;
	}
}

class AlarmSetting extends phpDynamicProperties {
	public $toleranceRange; //int
	public $reportingFrequency; //int

	function __construct($toleranceRange = null, $reportingFrequency = null) {
		$this->toleranceRange = $toleranceRange;
		$this->reportingFrequency = $reportingFrequency;
	}
}

class AlarmSpec extends phpDynamicProperties {
	public $name; //string
	public $systemName; //string
	public $description; //string
	public $enabled; //boolean
	public $expression; //AlarmExpression
	public $action; //AlarmAction
	public $actionFrequency; //int
	public $setting; //AlarmSetting

	function __construct($name = null, $systemName = null, $description = null, $enabled = null, $expression = null, $action = null, $actionFrequency = null, $setting = null) {
		$this->name = $name;
		$this->systemName = $systemName;
		$this->description = $description;
		$this->enabled = $enabled;
		$this->expression = $expression;
		$this->action = $action;
		$this->actionFrequency = $actionFrequency;
		$this->setting = $setting;
	}
}

class AlarmState extends phpDynamicProperties {
	public $key; //string
	public $entity; //ManagedObjectReference
	public $alarm; //ManagedObjectReference
	public $overallStatus; //ManagedEntityStatus
	public $time; //dateTime
	public $acknowledged; //boolean
	public $acknowledgedByUser; //string
	public $acknowledgedTime; //dateTime

	function __construct($key = null, $entity = null, $alarm = null, $overallStatus = null, $time = null, $acknowledged = null, $acknowledgedByUser = null, $acknowledgedTime = null) {
		$this->key = $key;
		$this->entity = $entity;
		$this->alarm = $alarm;
		$this->overallStatus = $overallStatus;
		$this->time = $time;
		$this->acknowledged = $acknowledged;
		$this->acknowledgedByUser = $acknowledgedByUser;
		$this->acknowledgedTime = $acknowledgedTime;
	}
}

class ArrayOfAlarmState extends phpDynamicProperties {
	public $AlarmState; //AlarmState

	function __construct($AlarmState = null) {
		$this->AlarmState = $AlarmState;
	}
}

class ClusterAction extends phpDynamicProperties {
	public $type; //string
	public $target; //ManagedObjectReference

	function __construct($type = null, $target = null) {
		$this->type = $type;
		$this->target = $target;
	}
}

class ArrayOfClusterAction extends phpDynamicProperties {
	public $ClusterAction; //ClusterAction

	function __construct($ClusterAction = null) {
		$this->ClusterAction = $ClusterAction;
	}
}

class ClusterActionHistory extends phpDynamicProperties {
	public $action; //ClusterAction
	public $time; //dateTime

	function __construct($action = null, $time = null) {
		$this->action = $action;
		$this->time = $time;
	}
}

class ArrayOfClusterActionHistory extends phpDynamicProperties {
	public $ClusterActionHistory; //ClusterActionHistory

	function __construct($ClusterActionHistory = null) {
		$this->ClusterActionHistory = $ClusterActionHistory;
	}
}

class ClusterAffinityRuleSpec extends phpDynamicProperties {
	public $vm; //ManagedObjectReference

	function __construct($vm = null) {
		$this->vm = $vm;
	}
}

class ClusterAntiAffinityRuleSpec extends phpDynamicProperties {
	public $vm; //ManagedObjectReference

	function __construct($vm = null) {
		$this->vm = $vm;
	}
}

class ClusterAttemptedVmInfo extends phpDynamicProperties {
	public $vm; //ManagedObjectReference
	public $task; //ManagedObjectReference

	function __construct($vm = null, $task = null) {
		$this->vm = $vm;
		$this->task = $task;
	}
}

class ArrayOfClusterAttemptedVmInfo extends phpDynamicProperties {
	public $ClusterAttemptedVmInfo; //ClusterAttemptedVmInfo

	function __construct($ClusterAttemptedVmInfo = null) {
		$this->ClusterAttemptedVmInfo = $ClusterAttemptedVmInfo;
	}
}

class ClusterConfigInfo extends phpDynamicProperties {
	public $dasConfig; //ClusterDasConfigInfo
	public $dasVmConfig; //ClusterDasVmConfigInfo
	public $drsConfig; //ClusterDrsConfigInfo
	public $drsVmConfig; //ClusterDrsVmConfigInfo
	public $rule; //ClusterRuleInfo

	function __construct($dasConfig = null, $dasVmConfig = null, $drsConfig = null, $drsVmConfig = null, $rule = null) {
		$this->dasConfig = $dasConfig;
		$this->dasVmConfig = $dasVmConfig;
		$this->drsConfig = $drsConfig;
		$this->drsVmConfig = $drsVmConfig;
		$this->rule = $rule;
	}
}

class ClusterDrsConfigInfo extends phpDynamicProperties {
	public $enabled; //boolean
	public $enableVmBehaviorOverrides; //boolean
	public $defaultVmBehavior; //DrsBehavior
	public $vmotionRate; //int
	public $option; //OptionValue

	function __construct($enabled = null, $enableVmBehaviorOverrides = null, $defaultVmBehavior = null, $vmotionRate = null, $option = null) {
		$this->enabled = $enabled;
		$this->enableVmBehaviorOverrides = $enableVmBehaviorOverrides;
		$this->defaultVmBehavior = $defaultVmBehavior;
		$this->vmotionRate = $vmotionRate;
		$this->option = $option;
	}
}

class ClusterDrsVmConfigInfo extends phpDynamicProperties {
	public $key; //ManagedObjectReference
	public $enabled; //boolean
	public $behavior; //DrsBehavior

	function __construct($key = null, $enabled = null, $behavior = null) {
		$this->key = $key;
		$this->enabled = $enabled;
		$this->behavior = $behavior;
	}
}

class ArrayOfClusterDrsVmConfigInfo extends phpDynamicProperties {
	public $ClusterDrsVmConfigInfo; //ClusterDrsVmConfigInfo

	function __construct($ClusterDrsVmConfigInfo = null) {
		$this->ClusterDrsVmConfigInfo = $ClusterDrsVmConfigInfo;
	}
}

class ClusterConfigInfoEx extends phpDynamicProperties {
	public $dasConfig; //ClusterDasConfigInfo
	public $dasVmConfig; //ClusterDasVmConfigInfo
	public $drsConfig; //ClusterDrsConfigInfo
	public $drsVmConfig; //ClusterDrsVmConfigInfo
	public $rule; //ClusterRuleInfo
	public $dpmConfigInfo; //ClusterDpmConfigInfo
	public $dpmHostConfig; //ClusterDpmHostConfigInfo
	public $group; //ClusterGroupInfo

	function __construct($dasConfig = null, $dasVmConfig = null, $drsConfig = null, $drsVmConfig = null, $rule = null, $dpmConfigInfo = null, $dpmHostConfig = null, $group = null) {
		$this->dasConfig = $dasConfig;
		$this->dasVmConfig = $dasVmConfig;
		$this->drsConfig = $drsConfig;
		$this->drsVmConfig = $drsVmConfig;
		$this->rule = $rule;
		$this->dpmConfigInfo = $dpmConfigInfo;
		$this->dpmHostConfig = $dpmHostConfig;
		$this->group = $group;
	}
}

class ClusterDpmConfigInfo extends phpDynamicProperties {
	public $enabled; //boolean
	public $defaultDpmBehavior; //DpmBehavior
	public $hostPowerActionRate; //int
	public $option; //OptionValue

	function __construct($enabled = null, $defaultDpmBehavior = null, $hostPowerActionRate = null, $option = null) {
		$this->enabled = $enabled;
		$this->defaultDpmBehavior = $defaultDpmBehavior;
		$this->hostPowerActionRate = $hostPowerActionRate;
		$this->option = $option;
	}
}

class ClusterDpmHostConfigInfo extends phpDynamicProperties {
	public $key; //ManagedObjectReference
	public $enabled; //boolean
	public $behavior; //DpmBehavior

	function __construct($key = null, $enabled = null, $behavior = null) {
		$this->key = $key;
		$this->enabled = $enabled;
		$this->behavior = $behavior;
	}
}

class ArrayOfClusterDpmHostConfigInfo extends phpDynamicProperties {
	public $ClusterDpmHostConfigInfo; //ClusterDpmHostConfigInfo

	function __construct($ClusterDpmHostConfigInfo = null) {
		$this->ClusterDpmHostConfigInfo = $ClusterDpmHostConfigInfo;
	}
}

class ClusterConfigSpec extends phpDynamicProperties {
	public $dasConfig; //ClusterDasConfigInfo
	public $dasVmConfigSpec; //ClusterDasVmConfigSpec
	public $drsConfig; //ClusterDrsConfigInfo
	public $drsVmConfigSpec; //ClusterDrsVmConfigSpec
	public $rulesSpec; //ClusterRuleSpec

	function __construct($dasConfig = null, $dasVmConfigSpec = null, $drsConfig = null, $drsVmConfigSpec = null, $rulesSpec = null) {
		$this->dasConfig = $dasConfig;
		$this->dasVmConfigSpec = $dasVmConfigSpec;
		$this->drsConfig = $drsConfig;
		$this->drsVmConfigSpec = $drsVmConfigSpec;
		$this->rulesSpec = $rulesSpec;
	}
}

class ClusterDasVmConfigSpec extends phpDynamicProperties {
	public $info; //ClusterDasVmConfigInfo

	function __construct($info = null) {
		$this->info = $info;
	}
}

class ArrayOfClusterDasVmConfigSpec extends phpDynamicProperties {
	public $ClusterDasVmConfigSpec; //ClusterDasVmConfigSpec

	function __construct($ClusterDasVmConfigSpec = null) {
		$this->ClusterDasVmConfigSpec = $ClusterDasVmConfigSpec;
	}
}

class ClusterDrsVmConfigSpec extends phpDynamicProperties {
	public $info; //ClusterDrsVmConfigInfo

	function __construct($info = null) {
		$this->info = $info;
	}
}

class ArrayOfClusterDrsVmConfigSpec extends phpDynamicProperties {
	public $ClusterDrsVmConfigSpec; //ClusterDrsVmConfigSpec

	function __construct($ClusterDrsVmConfigSpec = null) {
		$this->ClusterDrsVmConfigSpec = $ClusterDrsVmConfigSpec;
	}
}

class ClusterConfigSpecEx extends phpDynamicProperties {
	public $dasConfig; //ClusterDasConfigInfo
	public $dasVmConfigSpec; //ClusterDasVmConfigSpec
	public $drsConfig; //ClusterDrsConfigInfo
	public $drsVmConfigSpec; //ClusterDrsVmConfigSpec
	public $rulesSpec; //ClusterRuleSpec
	public $dpmConfig; //ClusterDpmConfigInfo
	public $dpmHostConfigSpec; //ClusterDpmHostConfigSpec
	public $groupSpec; //ClusterGroupSpec

	function __construct($dasConfig = null, $dasVmConfigSpec = null, $drsConfig = null, $drsVmConfigSpec = null, $rulesSpec = null, $dpmConfig = null, $dpmHostConfigSpec = null, $groupSpec = null) {
		$this->dasConfig = $dasConfig;
		$this->dasVmConfigSpec = $dasVmConfigSpec;
		$this->drsConfig = $drsConfig;
		$this->drsVmConfigSpec = $drsVmConfigSpec;
		$this->rulesSpec = $rulesSpec;
		$this->dpmConfig = $dpmConfig;
		$this->dpmHostConfigSpec = $dpmHostConfigSpec;
		$this->groupSpec = $groupSpec;
	}
}

class ClusterDpmHostConfigSpec extends phpDynamicProperties {
	public $info; //ClusterDpmHostConfigInfo

	function __construct($info = null) {
		$this->info = $info;
	}
}

class ArrayOfClusterDpmHostConfigSpec extends phpDynamicProperties {
	public $ClusterDpmHostConfigSpec; //ClusterDpmHostConfigSpec

	function __construct($ClusterDpmHostConfigSpec = null) {
		$this->ClusterDpmHostConfigSpec = $ClusterDpmHostConfigSpec;
	}
}

class ClusterGroupSpec extends phpDynamicProperties {
	public $info; //ClusterGroupInfo

	function __construct($info = null) {
		$this->info = $info;
	}
}

class ArrayOfClusterGroupSpec extends phpDynamicProperties {
	public $ClusterGroupSpec; //ClusterGroupSpec

	function __construct($ClusterGroupSpec = null) {
		$this->ClusterGroupSpec = $ClusterGroupSpec;
	}
}

class ClusterDasAamHostInfo extends phpDynamicProperties {
	public $hostDasState; //ClusterDasAamNodeState
	public $primaryHosts; //string

	function __construct($hostDasState = null, $primaryHosts = null) {
		$this->hostDasState = $hostDasState;
		$this->primaryHosts = $primaryHosts;
	}
}

class ClusterDasAamNodeState extends phpDynamicProperties {
	public $host; //ManagedObjectReference
	public $name; //string
	public $configState; //string
	public $runtimeState; //string

	function __construct($host = null, $name = null, $configState = null, $runtimeState = null) {
		$this->host = $host;
		$this->name = $name;
		$this->configState = $configState;
		$this->runtimeState = $runtimeState;
	}
}

class ArrayOfClusterDasAamNodeState extends phpDynamicProperties {
	public $ClusterDasAamNodeState; //ClusterDasAamNodeState

	function __construct($ClusterDasAamNodeState = null) {
		$this->ClusterDasAamNodeState = $ClusterDasAamNodeState;
	}
}

class ClusterDasAdmissionControlInfo extends phpDynamicProperties {
}

class ClusterDasAdmissionControlPolicy extends phpDynamicProperties {
}

class DasHeartbeatDatastoreInfo extends phpDynamicProperties {
	public $datastore; //ManagedObjectReference
	public $hosts; //ManagedObjectReference

	function __construct($datastore = null, $hosts = null) {
		$this->datastore = $datastore;
		$this->hosts = $hosts;
	}
}

class ArrayOfDasHeartbeatDatastoreInfo extends phpDynamicProperties {
	public $DasHeartbeatDatastoreInfo; //DasHeartbeatDatastoreInfo

	function __construct($DasHeartbeatDatastoreInfo = null) {
		$this->DasHeartbeatDatastoreInfo = $DasHeartbeatDatastoreInfo;
	}
}

class ClusterDasAdvancedRuntimeInfo extends phpDynamicProperties {
	public $dasHostInfo; //ClusterDasHostInfo
	public $heartbeatDatastoreInfo; //DasHeartbeatDatastoreInfo

	function __construct($dasHostInfo = null, $heartbeatDatastoreInfo = null) {
		$this->dasHostInfo = $dasHostInfo;
		$this->heartbeatDatastoreInfo = $heartbeatDatastoreInfo;
	}
}

class ClusterDasConfigInfo extends phpDynamicProperties {
	public $enabled; //boolean
	public $vmMonitoring; //string
	public $hostMonitoring; //string
	public $failoverLevel; //int
	public $admissionControlPolicy; //ClusterDasAdmissionControlPolicy
	public $admissionControlEnabled; //boolean
	public $defaultVmSettings; //ClusterDasVmSettings
	public $option; //OptionValue
	public $heartbeatDatastore; //ManagedObjectReference
	public $hBDatastoreCandidatePolicy; //string

	function __construct($enabled = null, $vmMonitoring = null, $hostMonitoring = null, $failoverLevel = null, $admissionControlPolicy = null, $admissionControlEnabled = null, $defaultVmSettings = null, $option = null, $heartbeatDatastore = null, $hBDatastoreCandidatePolicy = null) {
		$this->enabled = $enabled;
		$this->vmMonitoring = $vmMonitoring;
		$this->hostMonitoring = $hostMonitoring;
		$this->failoverLevel = $failoverLevel;
		$this->admissionControlPolicy = $admissionControlPolicy;
		$this->admissionControlEnabled = $admissionControlEnabled;
		$this->defaultVmSettings = $defaultVmSettings;
		$this->option = $option;
		$this->heartbeatDatastore = $heartbeatDatastore;
		$this->hBDatastoreCandidatePolicy = $hBDatastoreCandidatePolicy;
	}
}

class ClusterDasData extends phpDynamicProperties {
}

class ClusterDasDataSummary extends phpDynamicProperties {
	public $hostListVersion; //long
	public $clusterConfigVersion; //long
	public $compatListVersion; //long

	function __construct($hostListVersion = null, $clusterConfigVersion = null, $compatListVersion = null) {
		$this->hostListVersion = $hostListVersion;
		$this->clusterConfigVersion = $clusterConfigVersion;
		$this->compatListVersion = $compatListVersion;
	}
}

class ClusterDasFailoverLevelAdvancedRuntimeInfoSlotInfo extends phpDynamicProperties {
	public $numVcpus; //int
	public $cpuMHz; //int
	public $memoryMB; //int

	function __construct($numVcpus = null, $cpuMHz = null, $memoryMB = null) {
		$this->numVcpus = $numVcpus;
		$this->cpuMHz = $cpuMHz;
		$this->memoryMB = $memoryMB;
	}
}

class ClusterDasFailoverLevelAdvancedRuntimeInfoHostSlots extends phpDynamicProperties {
	public $host; //ManagedObjectReference
	public $slots; //int

	function __construct($host = null, $slots = null) {
		$this->host = $host;
		$this->slots = $slots;
	}
}

class ArrayOfClusterDasFailoverLevelAdvancedRuntimeInfoHostSlots extends phpDynamicProperties {
	public $ClusterDasFailoverLevelAdvancedRuntimeInfoHostSlots; //ClusterDasFailoverLevelAdvancedRuntimeInfoHostSlots

	function __construct($ClusterDasFailoverLevelAdvancedRuntimeInfoHostSlots = null) {
		$this->ClusterDasFailoverLevelAdvancedRuntimeInfoHostSlots = $ClusterDasFailoverLevelAdvancedRuntimeInfoHostSlots;
	}
}

class ClusterDasFailoverLevelAdvancedRuntimeInfo extends phpDynamicProperties {
	public $slotInfo; //ClusterDasFailoverLevelAdvancedRuntimeInfoSlotInfo
	public $totalSlots; //int
	public $usedSlots; //int
	public $unreservedSlots; //int
	public $totalVms; //int
	public $totalHosts; //int
	public $totalGoodHosts; //int
	public $hostSlots; //ClusterDasFailoverLevelAdvancedRuntimeInfoHostSlots

	function __construct($slotInfo = null, $totalSlots = null, $usedSlots = null, $unreservedSlots = null, $totalVms = null, $totalHosts = null, $totalGoodHosts = null, $hostSlots = null) {
		$this->slotInfo = $slotInfo;
		$this->totalSlots = $totalSlots;
		$this->usedSlots = $usedSlots;
		$this->unreservedSlots = $unreservedSlots;
		$this->totalVms = $totalVms;
		$this->totalHosts = $totalHosts;
		$this->totalGoodHosts = $totalGoodHosts;
		$this->hostSlots = $hostSlots;
	}
}

class ClusterDasFdmHostState extends phpDynamicProperties {
	public $state; //string
	public $stateReporter; //ManagedObjectReference

	function __construct($state = null, $stateReporter = null) {
		$this->state = $state;
		$this->stateReporter = $stateReporter;
	}
}

class ClusterDasHostInfo extends phpDynamicProperties {
}

class ClusterDasHostRecommendation extends phpDynamicProperties {
	public $host; //ManagedObjectReference
	public $drsRating; //int

	function __construct($host = null, $drsRating = null) {
		$this->host = $host;
		$this->drsRating = $drsRating;
	}
}

class ClusterDasVmConfigInfo extends phpDynamicProperties {
	public $key; //ManagedObjectReference
	public $restartPriority; //DasVmPriority
	public $powerOffOnIsolation; //boolean
	public $dasSettings; //ClusterDasVmSettings

	function __construct($key = null, $restartPriority = null, $powerOffOnIsolation = null, $dasSettings = null) {
		$this->key = $key;
		$this->restartPriority = $restartPriority;
		$this->powerOffOnIsolation = $powerOffOnIsolation;
		$this->dasSettings = $dasSettings;
	}
}

class ArrayOfClusterDasVmConfigInfo extends phpDynamicProperties {
	public $ClusterDasVmConfigInfo; //ClusterDasVmConfigInfo

	function __construct($ClusterDasVmConfigInfo = null) {
		$this->ClusterDasVmConfigInfo = $ClusterDasVmConfigInfo;
	}
}

class ClusterDasVmSettings extends phpDynamicProperties {
	public $restartPriority; //string
	public $isolationResponse; //string
	public $vmToolsMonitoringSettings; //ClusterVmToolsMonitoringSettings

	function __construct($restartPriority = null, $isolationResponse = null, $vmToolsMonitoringSettings = null) {
		$this->restartPriority = $restartPriority;
		$this->isolationResponse = $isolationResponse;
		$this->vmToolsMonitoringSettings = $vmToolsMonitoringSettings;
	}
}

class ClusterDrsFaultsFaultsByVm extends phpDynamicProperties {
	public $vm; //ManagedObjectReference
	public $fault; //LocalizedMethodFault

	function __construct($vm = null, $fault = null) {
		$this->vm = $vm;
		$this->fault = $fault;
	}
}

class ArrayOfClusterDrsFaultsFaultsByVm extends phpDynamicProperties {
	public $ClusterDrsFaultsFaultsByVm; //ClusterDrsFaultsFaultsByVm

	function __construct($ClusterDrsFaultsFaultsByVm = null) {
		$this->ClusterDrsFaultsFaultsByVm = $ClusterDrsFaultsFaultsByVm;
	}
}

class ClusterDrsFaultsFaultsByVirtualDisk extends phpDynamicProperties {
	public $disk; //VirtualDiskId

	function __construct($disk = null) {
		$this->disk = $disk;
	}
}

class ClusterDrsFaults extends phpDynamicProperties {
	public $reason; //string
	public $faultsByVm; //ClusterDrsFaultsFaultsByVm

	function __construct($reason = null, $faultsByVm = null) {
		$this->reason = $reason;
		$this->faultsByVm = $faultsByVm;
	}
}

class ArrayOfClusterDrsFaults extends phpDynamicProperties {
	public $ClusterDrsFaults; //ClusterDrsFaults

	function __construct($ClusterDrsFaults = null) {
		$this->ClusterDrsFaults = $ClusterDrsFaults;
	}
}

class ClusterDrsMigration extends phpDynamicProperties {
	public $key; //string
	public $time; //dateTime
	public $vm; //ManagedObjectReference
	public $cpuLoad; //int
	public $memoryLoad; //long
	public $source; //ManagedObjectReference
	public $sourceCpuLoad; //int
	public $sourceMemoryLoad; //long
	public $destination; //ManagedObjectReference
	public $destinationCpuLoad; //int
	public $destinationMemoryLoad; //long

	function __construct($key = null, $time = null, $vm = null, $cpuLoad = null, $memoryLoad = null, $source = null, $sourceCpuLoad = null, $sourceMemoryLoad = null, $destination = null, $destinationCpuLoad = null, $destinationMemoryLoad = null) {
		$this->key = $key;
		$this->time = $time;
		$this->vm = $vm;
		$this->cpuLoad = $cpuLoad;
		$this->memoryLoad = $memoryLoad;
		$this->source = $source;
		$this->sourceCpuLoad = $sourceCpuLoad;
		$this->sourceMemoryLoad = $sourceMemoryLoad;
		$this->destination = $destination;
		$this->destinationCpuLoad = $destinationCpuLoad;
		$this->destinationMemoryLoad = $destinationMemoryLoad;
	}
}

class ArrayOfClusterDrsMigration extends phpDynamicProperties {
	public $ClusterDrsMigration; //ClusterDrsMigration

	function __construct($ClusterDrsMigration = null) {
		$this->ClusterDrsMigration = $ClusterDrsMigration;
	}
}

class ClusterDrsRecommendation extends phpDynamicProperties {
	public $key; //string
	public $rating; //int
	public $reason; //string
	public $reasonText; //string
	public $migrationList; //ClusterDrsMigration

	function __construct($key = null, $rating = null, $reason = null, $reasonText = null, $migrationList = null) {
		$this->key = $key;
		$this->rating = $rating;
		$this->reason = $reason;
		$this->reasonText = $reasonText;
		$this->migrationList = $migrationList;
	}
}

class ArrayOfClusterDrsRecommendation extends phpDynamicProperties {
	public $ClusterDrsRecommendation; //ClusterDrsRecommendation

	function __construct($ClusterDrsRecommendation = null) {
		$this->ClusterDrsRecommendation = $ClusterDrsRecommendation;
	}
}

class ClusterEnterMaintenanceResult extends phpDynamicProperties {
	public $recommendations; //ClusterRecommendation
	public $fault; //ClusterDrsFaults

	function __construct($recommendations = null, $fault = null) {
		$this->recommendations = $recommendations;
		$this->fault = $fault;
	}
}

class ClusterFailoverHostAdmissionControlInfoHostStatus extends phpDynamicProperties {
	public $host; //ManagedObjectReference
	public $status; //ManagedEntityStatus

	function __construct($host = null, $status = null) {
		$this->host = $host;
		$this->status = $status;
	}
}

class ArrayOfClusterFailoverHostAdmissionControlInfoHostStatus extends phpDynamicProperties {
	public $ClusterFailoverHostAdmissionControlInfoHostStatus; //ClusterFailoverHostAdmissionControlInfoHostStatus

	function __construct($ClusterFailoverHostAdmissionControlInfoHostStatus = null) {
		$this->ClusterFailoverHostAdmissionControlInfoHostStatus = $ClusterFailoverHostAdmissionControlInfoHostStatus;
	}
}

class ClusterFailoverHostAdmissionControlInfo extends phpDynamicProperties {
	public $hostStatus; //ClusterFailoverHostAdmissionControlInfoHostStatus

	function __construct($hostStatus = null) {
		$this->hostStatus = $hostStatus;
	}
}

class ClusterFailoverHostAdmissionControlPolicy extends phpDynamicProperties {
	public $failoverHosts; //ManagedObjectReference

	function __construct($failoverHosts = null) {
		$this->failoverHosts = $failoverHosts;
	}
}

class ClusterFailoverLevelAdmissionControlInfo extends phpDynamicProperties {
	public $currentFailoverLevel; //int

	function __construct($currentFailoverLevel = null) {
		$this->currentFailoverLevel = $currentFailoverLevel;
	}
}

class ClusterFailoverLevelAdmissionControlPolicy extends phpDynamicProperties {
	public $failoverLevel; //int

	function __construct($failoverLevel = null) {
		$this->failoverLevel = $failoverLevel;
	}
}

class ClusterFailoverResourcesAdmissionControlInfo extends phpDynamicProperties {
	public $currentCpuFailoverResourcesPercent; //int
	public $currentMemoryFailoverResourcesPercent; //int

	function __construct($currentCpuFailoverResourcesPercent = null, $currentMemoryFailoverResourcesPercent = null) {
		$this->currentCpuFailoverResourcesPercent = $currentCpuFailoverResourcesPercent;
		$this->currentMemoryFailoverResourcesPercent = $currentMemoryFailoverResourcesPercent;
	}
}

class ClusterFailoverResourcesAdmissionControlPolicy extends phpDynamicProperties {
	public $cpuFailoverResourcesPercent; //int
	public $memoryFailoverResourcesPercent; //int

	function __construct($cpuFailoverResourcesPercent = null, $memoryFailoverResourcesPercent = null) {
		$this->cpuFailoverResourcesPercent = $cpuFailoverResourcesPercent;
		$this->memoryFailoverResourcesPercent = $memoryFailoverResourcesPercent;
	}
}

class ClusterGroupInfo extends phpDynamicProperties {
	public $name; //string
	public $userCreated; //boolean

	function __construct($name = null, $userCreated = null) {
		$this->name = $name;
		$this->userCreated = $userCreated;
	}
}

class ArrayOfClusterGroupInfo extends phpDynamicProperties {
	public $ClusterGroupInfo; //ClusterGroupInfo

	function __construct($ClusterGroupInfo = null) {
		$this->ClusterGroupInfo = $ClusterGroupInfo;
	}
}

class ClusterHostGroup extends phpDynamicProperties {
	public $host; //ManagedObjectReference

	function __construct($host = null) {
		$this->host = $host;
	}
}

class ClusterHostPowerAction extends phpDynamicProperties {
	public $operationType; //HostPowerOperationType
	public $powerConsumptionWatt; //int
	public $cpuCapacityMHz; //int
	public $memCapacityMB; //int

	function __construct($operationType = null, $powerConsumptionWatt = null, $cpuCapacityMHz = null, $memCapacityMB = null) {
		$this->operationType = $operationType;
		$this->powerConsumptionWatt = $powerConsumptionWatt;
		$this->cpuCapacityMHz = $cpuCapacityMHz;
		$this->memCapacityMB = $memCapacityMB;
	}
}

class ClusterHostRecommendation extends phpDynamicProperties {
	public $host; //ManagedObjectReference
	public $rating; //int

	function __construct($host = null, $rating = null) {
		$this->host = $host;
		$this->rating = $rating;
	}
}

class ArrayOfClusterHostRecommendation extends phpDynamicProperties {
	public $ClusterHostRecommendation; //ClusterHostRecommendation

	function __construct($ClusterHostRecommendation = null) {
		$this->ClusterHostRecommendation = $ClusterHostRecommendation;
	}
}

class ClusterInitialPlacementAction extends phpDynamicProperties {
	public $targetHost; //ManagedObjectReference
	public $pool; //ManagedObjectReference

	function __construct($targetHost = null, $pool = null) {
		$this->targetHost = $targetHost;
		$this->pool = $pool;
	}
}

class ClusterMigrationAction extends phpDynamicProperties {
	public $drsMigration; //ClusterDrsMigration

	function __construct($drsMigration = null) {
		$this->drsMigration = $drsMigration;
	}
}

class ClusterNotAttemptedVmInfo extends phpDynamicProperties {
	public $vm; //ManagedObjectReference
	public $fault; //LocalizedMethodFault

	function __construct($vm = null, $fault = null) {
		$this->vm = $vm;
		$this->fault = $fault;
	}
}

class ArrayOfClusterNotAttemptedVmInfo extends phpDynamicProperties {
	public $ClusterNotAttemptedVmInfo; //ClusterNotAttemptedVmInfo

	function __construct($ClusterNotAttemptedVmInfo = null) {
		$this->ClusterNotAttemptedVmInfo = $ClusterNotAttemptedVmInfo;
	}
}

class ClusterPowerOnVmResult extends phpDynamicProperties {
	public $attempted; //ClusterAttemptedVmInfo
	public $notAttempted; //ClusterNotAttemptedVmInfo
	public $recommendations; //ClusterRecommendation

	function __construct($attempted = null, $notAttempted = null, $recommendations = null) {
		$this->attempted = $attempted;
		$this->notAttempted = $notAttempted;
		$this->recommendations = $recommendations;
	}
}

class ClusterRecommendation extends phpDynamicProperties {
	public $key; //string
	public $type; //string
	public $time; //dateTime
	public $rating; //int
	public $reason; //string
	public $reasonText; //string
	public $prerequisite; //string
	public $action; //ClusterAction
	public $target; //ManagedObjectReference

	function __construct($key = null, $type = null, $time = null, $rating = null, $reason = null, $reasonText = null, $prerequisite = null, $action = null, $target = null) {
		$this->key = $key;
		$this->type = $type;
		$this->time = $time;
		$this->rating = $rating;
		$this->reason = $reason;
		$this->reasonText = $reasonText;
		$this->prerequisite = $prerequisite;
		$this->action = $action;
		$this->target = $target;
	}
}

class ArrayOfClusterRecommendation extends phpDynamicProperties {
	public $ClusterRecommendation; //ClusterRecommendation

	function __construct($ClusterRecommendation = null) {
		$this->ClusterRecommendation = $ClusterRecommendation;
	}
}

class ClusterRuleInfo extends phpDynamicProperties {
	public $key; //int
	public $status; //ManagedEntityStatus
	public $enabled; //boolean
	public $name; //string
	public $mandatory; //boolean
	public $userCreated; //boolean
	public $inCompliance; //boolean

	function __construct($key = null, $status = null, $enabled = null, $name = null, $mandatory = null, $userCreated = null, $inCompliance = null) {
		$this->key = $key;
		$this->status = $status;
		$this->enabled = $enabled;
		$this->name = $name;
		$this->mandatory = $mandatory;
		$this->userCreated = $userCreated;
		$this->inCompliance = $inCompliance;
	}
}

class ArrayOfClusterRuleInfo extends phpDynamicProperties {
	public $ClusterRuleInfo; //ClusterRuleInfo

	function __construct($ClusterRuleInfo = null) {
		$this->ClusterRuleInfo = $ClusterRuleInfo;
	}
}

class ClusterRuleSpec extends phpDynamicProperties {
	public $info; //ClusterRuleInfo

	function __construct($info = null) {
		$this->info = $info;
	}
}

class ArrayOfClusterRuleSpec extends phpDynamicProperties {
	public $ClusterRuleSpec; //ClusterRuleSpec

	function __construct($ClusterRuleSpec = null) {
		$this->ClusterRuleSpec = $ClusterRuleSpec;
	}
}

class ClusterVmGroup extends phpDynamicProperties {
	public $vm; //ManagedObjectReference

	function __construct($vm = null) {
		$this->vm = $vm;
	}
}

class ClusterVmHostRuleInfo extends phpDynamicProperties {
	public $vmGroupName; //string
	public $affineHostGroupName; //string
	public $antiAffineHostGroupName; //string

	function __construct($vmGroupName = null, $affineHostGroupName = null, $antiAffineHostGroupName = null) {
		$this->vmGroupName = $vmGroupName;
		$this->affineHostGroupName = $affineHostGroupName;
		$this->antiAffineHostGroupName = $antiAffineHostGroupName;
	}
}

class ClusterVmToolsMonitoringSettings extends phpDynamicProperties {
	public $enabled; //boolean
	public $vmMonitoring; //string
	public $clusterSettings; //boolean
	public $failureInterval; //int
	public $minUpTime; //int
	public $maxFailures; //int
	public $maxFailureWindow; //int

	function __construct($enabled = null, $vmMonitoring = null, $clusterSettings = null, $failureInterval = null, $minUpTime = null, $maxFailures = null, $maxFailureWindow = null) {
		$this->enabled = $enabled;
		$this->vmMonitoring = $vmMonitoring;
		$this->clusterSettings = $clusterSettings;
		$this->failureInterval = $failureInterval;
		$this->minUpTime = $minUpTime;
		$this->maxFailures = $maxFailures;
		$this->maxFailureWindow = $maxFailureWindow;
	}
}

class DVPortConfigSpec extends phpDynamicProperties {
	public $operation; //string
	public $key; //string
	public $name; //string
	public $scope; //ManagedObjectReference
	public $description; //string
	public $setting; //DVPortSetting
	public $configVersion; //string

	function __construct($operation = null, $key = null, $name = null, $scope = null, $description = null, $setting = null, $configVersion = null) {
		$this->operation = $operation;
		$this->key = $key;
		$this->name = $name;
		$this->scope = $scope;
		$this->description = $description;
		$this->setting = $setting;
		$this->configVersion = $configVersion;
	}
}

class ArrayOfDVPortConfigSpec extends phpDynamicProperties {
	public $DVPortConfigSpec; //DVPortConfigSpec

	function __construct($DVPortConfigSpec = null) {
		$this->DVPortConfigSpec = $DVPortConfigSpec;
	}
}

class DVPortConfigInfo extends phpDynamicProperties {
	public $name; //string
	public $scope; //ManagedObjectReference
	public $description; //string
	public $setting; //DVPortSetting
	public $configVersion; //string

	function __construct($name = null, $scope = null, $description = null, $setting = null, $configVersion = null) {
		$this->name = $name;
		$this->scope = $scope;
		$this->description = $description;
		$this->setting = $setting;
		$this->configVersion = $configVersion;
	}
}

class DVSTrafficShapingPolicy extends phpDynamicProperties {
	public $enabled; //BoolPolicy
	public $averageBandwidth; //LongPolicy
	public $peakBandwidth; //LongPolicy
	public $burstSize; //LongPolicy

	function __construct($enabled = null, $averageBandwidth = null, $peakBandwidth = null, $burstSize = null) {
		$this->enabled = $enabled;
		$this->averageBandwidth = $averageBandwidth;
		$this->peakBandwidth = $peakBandwidth;
		$this->burstSize = $burstSize;
	}
}

class DVSVendorSpecificConfig extends phpDynamicProperties {
	public $keyValue; //DistributedVirtualSwitchKeyedOpaqueBlob

	function __construct($keyValue = null) {
		$this->keyValue = $keyValue;
	}
}

class DVPortSetting extends phpDynamicProperties {
	public $blocked; //BoolPolicy
	public $vmDirectPathGen2Allowed; //BoolPolicy
	public $inShapingPolicy; //DVSTrafficShapingPolicy
	public $outShapingPolicy; //DVSTrafficShapingPolicy
	public $vendorSpecificConfig; //DVSVendorSpecificConfig
	public $networkResourcePoolKey; //StringPolicy

	function __construct($blocked = null, $vmDirectPathGen2Allowed = null, $inShapingPolicy = null, $outShapingPolicy = null, $vendorSpecificConfig = null, $networkResourcePoolKey = null) {
		$this->blocked = $blocked;
		$this->vmDirectPathGen2Allowed = $vmDirectPathGen2Allowed;
		$this->inShapingPolicy = $inShapingPolicy;
		$this->outShapingPolicy = $outShapingPolicy;
		$this->vendorSpecificConfig = $vendorSpecificConfig;
		$this->networkResourcePoolKey = $networkResourcePoolKey;
	}
}

class DVPortStatus extends phpDynamicProperties {
	public $linkUp; //boolean
	public $blocked; //boolean
	public $vlanIds; //NumericRange
	public $trunkingMode; //boolean
	public $mtu; //int
	public $linkPeer; //string
	public $macAddress; //string
	public $statusDetail; //string
	public $vmDirectPathGen2Active; //boolean
	public $vmDirectPathGen2InactiveReasonNetwork; //string
	public $vmDirectPathGen2InactiveReasonOther; //string
	public $vmDirectPathGen2InactiveReasonExtended; //string

	function __construct($linkUp = null, $blocked = null, $vlanIds = null, $trunkingMode = null, $mtu = null, $linkPeer = null, $macAddress = null, $statusDetail = null, $vmDirectPathGen2Active = null, $vmDirectPathGen2InactiveReasonNetwork = null, $vmDirectPathGen2InactiveReasonOther = null, $vmDirectPathGen2InactiveReasonExtended = null) {
		$this->linkUp = $linkUp;
		$this->blocked = $blocked;
		$this->vlanIds = $vlanIds;
		$this->trunkingMode = $trunkingMode;
		$this->mtu = $mtu;
		$this->linkPeer = $linkPeer;
		$this->macAddress = $macAddress;
		$this->statusDetail = $statusDetail;
		$this->vmDirectPathGen2Active = $vmDirectPathGen2Active;
		$this->vmDirectPathGen2InactiveReasonNetwork = $vmDirectPathGen2InactiveReasonNetwork;
		$this->vmDirectPathGen2InactiveReasonOther = $vmDirectPathGen2InactiveReasonOther;
		$this->vmDirectPathGen2InactiveReasonExtended = $vmDirectPathGen2InactiveReasonExtended;
	}
}

class DVPortState extends phpDynamicProperties {
	public $runtimeInfo; //DVPortStatus
	public $stats; //DistributedVirtualSwitchPortStatistics
	public $vendorSpecificState; //DistributedVirtualSwitchKeyedOpaqueBlob

	function __construct($runtimeInfo = null, $stats = null, $vendorSpecificState = null) {
		$this->runtimeInfo = $runtimeInfo;
		$this->stats = $stats;
		$this->vendorSpecificState = $vendorSpecificState;
	}
}

class DistributedVirtualPort extends phpDynamicProperties {
	public $key; //string
	public $config; //DVPortConfigInfo
	public $dvsUuid; //string
	public $portgroupKey; //string
	public $proxyHost; //ManagedObjectReference
	public $connectee; //DistributedVirtualSwitchPortConnectee
	public $conflict; //boolean
	public $conflictPortKey; //string
	public $state; //DVPortState
	public $connectionCookie; //int
	public $lastStatusChange; //dateTime

	function __construct($key = null, $config = null, $dvsUuid = null, $portgroupKey = null, $proxyHost = null, $connectee = null, $conflict = null, $conflictPortKey = null, $state = null, $connectionCookie = null, $lastStatusChange = null) {
		$this->key = $key;
		$this->config = $config;
		$this->dvsUuid = $dvsUuid;
		$this->portgroupKey = $portgroupKey;
		$this->proxyHost = $proxyHost;
		$this->connectee = $connectee;
		$this->conflict = $conflict;
		$this->conflictPortKey = $conflictPortKey;
		$this->state = $state;
		$this->connectionCookie = $connectionCookie;
		$this->lastStatusChange = $lastStatusChange;
	}
}

class ArrayOfDistributedVirtualPort extends phpDynamicProperties {
	public $DistributedVirtualPort; //DistributedVirtualPort

	function __construct($DistributedVirtualPort = null) {
		$this->DistributedVirtualPort = $DistributedVirtualPort;
	}
}

class DVPortgroupPolicy extends phpDynamicProperties {
	public $blockOverrideAllowed; //boolean
	public $shapingOverrideAllowed; //boolean
	public $vendorConfigOverrideAllowed; //boolean
	public $livePortMovingAllowed; //boolean
	public $portConfigResetAtDisconnect; //boolean
	public $networkResourcePoolOverrideAllowed; //boolean

	function __construct($blockOverrideAllowed = null, $shapingOverrideAllowed = null, $vendorConfigOverrideAllowed = null, $livePortMovingAllowed = null, $portConfigResetAtDisconnect = null, $networkResourcePoolOverrideAllowed = null) {
		$this->blockOverrideAllowed = $blockOverrideAllowed;
		$this->shapingOverrideAllowed = $shapingOverrideAllowed;
		$this->vendorConfigOverrideAllowed = $vendorConfigOverrideAllowed;
		$this->livePortMovingAllowed = $livePortMovingAllowed;
		$this->portConfigResetAtDisconnect = $portConfigResetAtDisconnect;
		$this->networkResourcePoolOverrideAllowed = $networkResourcePoolOverrideAllowed;
	}
}

class DVPortgroupConfigSpec extends phpDynamicProperties {
	public $configVersion; //string
	public $name; //string
	public $numPorts; //int
	public $portNameFormat; //string
	public $defaultPortConfig; //DVPortSetting
	public $description; //string
	public $type; //string
	public $scope; //ManagedObjectReference
	public $policy; //DVPortgroupPolicy
	public $vendorSpecificConfig; //DistributedVirtualSwitchKeyedOpaqueBlob
	public $autoExpand; //boolean

	function __construct($configVersion = null, $name = null, $numPorts = null, $portNameFormat = null, $defaultPortConfig = null, $description = null, $type = null, $scope = null, $policy = null, $vendorSpecificConfig = null, $autoExpand = null) {
		$this->configVersion = $configVersion;
		$this->name = $name;
		$this->numPorts = $numPorts;
		$this->portNameFormat = $portNameFormat;
		$this->defaultPortConfig = $defaultPortConfig;
		$this->description = $description;
		$this->type = $type;
		$this->scope = $scope;
		$this->policy = $policy;
		$this->vendorSpecificConfig = $vendorSpecificConfig;
		$this->autoExpand = $autoExpand;
	}
}

class ArrayOfDVPortgroupConfigSpec extends phpDynamicProperties {
	public $DVPortgroupConfigSpec; //DVPortgroupConfigSpec

	function __construct($DVPortgroupConfigSpec = null) {
		$this->DVPortgroupConfigSpec = $DVPortgroupConfigSpec;
	}
}

class DVPortgroupConfigInfo extends phpDynamicProperties {
	public $key; //string
	public $name; //string
	public $numPorts; //int
	public $distributedVirtualSwitch; //ManagedObjectReference
	public $defaultPortConfig; //DVPortSetting
	public $description; //string
	public $type; //string
	public $policy; //DVPortgroupPolicy
	public $portNameFormat; //string
	public $scope; //ManagedObjectReference
	public $vendorSpecificConfig; //DistributedVirtualSwitchKeyedOpaqueBlob
	public $configVersion; //string
	public $autoExpand; //boolean

	function __construct($key = null, $name = null, $numPorts = null, $distributedVirtualSwitch = null, $defaultPortConfig = null, $description = null, $type = null, $policy = null, $portNameFormat = null, $scope = null, $vendorSpecificConfig = null, $configVersion = null, $autoExpand = null) {
		$this->key = $key;
		$this->name = $name;
		$this->numPorts = $numPorts;
		$this->distributedVirtualSwitch = $distributedVirtualSwitch;
		$this->defaultPortConfig = $defaultPortConfig;
		$this->description = $description;
		$this->type = $type;
		$this->policy = $policy;
		$this->portNameFormat = $portNameFormat;
		$this->scope = $scope;
		$this->vendorSpecificConfig = $vendorSpecificConfig;
		$this->configVersion = $configVersion;
		$this->autoExpand = $autoExpand;
	}
}

class DistributedVirtualPortgroupInfo extends phpDynamicProperties {
	public $switchName; //string
	public $switchUuid; //string
	public $portgroupName; //string
	public $portgroupKey; //string
	public $portgroupType; //string
	public $uplinkPortgroup; //boolean
	public $portgroup; //ManagedObjectReference

	function __construct($switchName = null, $switchUuid = null, $portgroupName = null, $portgroupKey = null, $portgroupType = null, $uplinkPortgroup = null, $portgroup = null) {
		$this->switchName = $switchName;
		$this->switchUuid = $switchUuid;
		$this->portgroupName = $portgroupName;
		$this->portgroupKey = $portgroupKey;
		$this->portgroupType = $portgroupType;
		$this->uplinkPortgroup = $uplinkPortgroup;
		$this->portgroup = $portgroup;
	}
}

class ArrayOfDistributedVirtualPortgroupInfo extends phpDynamicProperties {
	public $DistributedVirtualPortgroupInfo; //DistributedVirtualPortgroupInfo

	function __construct($DistributedVirtualPortgroupInfo = null) {
		$this->DistributedVirtualPortgroupInfo = $DistributedVirtualPortgroupInfo;
	}
}

class DistributedVirtualSwitchInfo extends phpDynamicProperties {
	public $switchName; //string
	public $switchUuid; //string
	public $distributedVirtualSwitch; //ManagedObjectReference

	function __construct($switchName = null, $switchUuid = null, $distributedVirtualSwitch = null) {
		$this->switchName = $switchName;
		$this->switchUuid = $switchUuid;
		$this->distributedVirtualSwitch = $distributedVirtualSwitch;
	}
}

class ArrayOfDistributedVirtualSwitchInfo extends phpDynamicProperties {
	public $DistributedVirtualSwitchInfo; //DistributedVirtualSwitchInfo

	function __construct($DistributedVirtualSwitchInfo = null) {
		$this->DistributedVirtualSwitchInfo = $DistributedVirtualSwitchInfo;
	}
}

class DVSManagerDvsConfigTarget extends phpDynamicProperties {
	public $distributedVirtualPortgroup; //DistributedVirtualPortgroupInfo
	public $distributedVirtualSwitch; //DistributedVirtualSwitchInfo

	function __construct($distributedVirtualPortgroup = null, $distributedVirtualSwitch = null) {
		$this->distributedVirtualPortgroup = $distributedVirtualPortgroup;
		$this->distributedVirtualSwitch = $distributedVirtualSwitch;
	}
}

class DistributedVirtualSwitchManagerCompatibilityResult extends phpDynamicProperties {
	public $host; //ManagedObjectReference
	public $error; //LocalizedMethodFault

	function __construct($host = null, $error = null) {
		$this->host = $host;
		$this->error = $error;
	}
}

class ArrayOfDistributedVirtualSwitchManagerCompatibilityResult extends phpDynamicProperties {
	public $DistributedVirtualSwitchManagerCompatibilityResult; //DistributedVirtualSwitchManagerCompatibilityResult

	function __construct($DistributedVirtualSwitchManagerCompatibilityResult = null) {
		$this->DistributedVirtualSwitchManagerCompatibilityResult = $DistributedVirtualSwitchManagerCompatibilityResult;
	}
}

class DistributedVirtualSwitchManagerHostContainer extends phpDynamicProperties {
	public $container; //ManagedObjectReference
	public $recursive; //boolean

	function __construct($container = null, $recursive = null) {
		$this->container = $container;
		$this->recursive = $recursive;
	}
}

class DistributedVirtualSwitchManagerHostDvsFilterSpec extends phpDynamicProperties {
	public $inclusive; //boolean

	function __construct($inclusive = null) {
		$this->inclusive = $inclusive;
	}
}

class ArrayOfDistributedVirtualSwitchManagerHostDvsFilterSpec extends phpDynamicProperties {
	public $DistributedVirtualSwitchManagerHostDvsFilterSpec; //DistributedVirtualSwitchManagerHostDvsFilterSpec

	function __construct($DistributedVirtualSwitchManagerHostDvsFilterSpec = null) {
		$this->DistributedVirtualSwitchManagerHostDvsFilterSpec = $DistributedVirtualSwitchManagerHostDvsFilterSpec;
	}
}

class DistributedVirtualSwitchManagerHostArrayFilter extends phpDynamicProperties {
	public $host; //ManagedObjectReference

	function __construct($host = null) {
		$this->host = $host;
	}
}

class DistributedVirtualSwitchManagerHostContainerFilter extends phpDynamicProperties {
	public $hostContainer; //DistributedVirtualSwitchManagerHostContainer

	function __construct($hostContainer = null) {
		$this->hostContainer = $hostContainer;
	}
}

class DistributedVirtualSwitchManagerHostDvsMembershipFilter extends phpDynamicProperties {
	public $distributedVirtualSwitch; //ManagedObjectReference

	function __construct($distributedVirtualSwitch = null) {
		$this->distributedVirtualSwitch = $distributedVirtualSwitch;
	}
}

class DistributedVirtualSwitchManagerDvsProductSpec extends phpDynamicProperties {
	public $newSwitchProductSpec; //DistributedVirtualSwitchProductSpec
	public $distributedVirtualSwitch; //ManagedObjectReference

	function __construct($newSwitchProductSpec = null, $distributedVirtualSwitch = null) {
		$this->newSwitchProductSpec = $newSwitchProductSpec;
		$this->distributedVirtualSwitch = $distributedVirtualSwitch;
	}
}

class DistributedVirtualSwitchHostMemberConfigSpec extends phpDynamicProperties {
	public $operation; //string
	public $host; //ManagedObjectReference
	public $backing; //DistributedVirtualSwitchHostMemberBacking
	public $maxProxySwitchPorts; //int
	public $vendorSpecificConfig; //DistributedVirtualSwitchKeyedOpaqueBlob

	function __construct($operation = null, $host = null, $backing = null, $maxProxySwitchPorts = null, $vendorSpecificConfig = null) {
		$this->operation = $operation;
		$this->host = $host;
		$this->backing = $backing;
		$this->maxProxySwitchPorts = $maxProxySwitchPorts;
		$this->vendorSpecificConfig = $vendorSpecificConfig;
	}
}

class ArrayOfDistributedVirtualSwitchHostMemberConfigSpec extends phpDynamicProperties {
	public $DistributedVirtualSwitchHostMemberConfigSpec; //DistributedVirtualSwitchHostMemberConfigSpec

	function __construct($DistributedVirtualSwitchHostMemberConfigSpec = null) {
		$this->DistributedVirtualSwitchHostMemberConfigSpec = $DistributedVirtualSwitchHostMemberConfigSpec;
	}
}

class DistributedVirtualSwitchHostMemberPnicSpec extends phpDynamicProperties {
	public $pnicDevice; //string
	public $uplinkPortKey; //string
	public $uplinkPortgroupKey; //string
	public $connectionCookie; //int

	function __construct($pnicDevice = null, $uplinkPortKey = null, $uplinkPortgroupKey = null, $connectionCookie = null) {
		$this->pnicDevice = $pnicDevice;
		$this->uplinkPortKey = $uplinkPortKey;
		$this->uplinkPortgroupKey = $uplinkPortgroupKey;
		$this->connectionCookie = $connectionCookie;
	}
}

class ArrayOfDistributedVirtualSwitchHostMemberPnicSpec extends phpDynamicProperties {
	public $DistributedVirtualSwitchHostMemberPnicSpec; //DistributedVirtualSwitchHostMemberPnicSpec

	function __construct($DistributedVirtualSwitchHostMemberPnicSpec = null) {
		$this->DistributedVirtualSwitchHostMemberPnicSpec = $DistributedVirtualSwitchHostMemberPnicSpec;
	}
}

class DistributedVirtualSwitchHostMemberBacking extends phpDynamicProperties {
}

class DistributedVirtualSwitchHostMemberPnicBacking extends phpDynamicProperties {
	public $pnicSpec; //DistributedVirtualSwitchHostMemberPnicSpec

	function __construct($pnicSpec = null) {
		$this->pnicSpec = $pnicSpec;
	}
}

class DistributedVirtualSwitchHostMemberRuntimeState extends phpDynamicProperties {
	public $currentMaxProxySwitchPorts; //int

	function __construct($currentMaxProxySwitchPorts = null) {
		$this->currentMaxProxySwitchPorts = $currentMaxProxySwitchPorts;
	}
}

class DistributedVirtualSwitchHostMemberConfigInfo extends phpDynamicProperties {
	public $host; //ManagedObjectReference
	public $maxProxySwitchPorts; //int
	public $vendorSpecificConfig; //DistributedVirtualSwitchKeyedOpaqueBlob
	public $backing; //DistributedVirtualSwitchHostMemberBacking

	function __construct($host = null, $maxProxySwitchPorts = null, $vendorSpecificConfig = null, $backing = null) {
		$this->host = $host;
		$this->maxProxySwitchPorts = $maxProxySwitchPorts;
		$this->vendorSpecificConfig = $vendorSpecificConfig;
		$this->backing = $backing;
	}
}

class DistributedVirtualSwitchHostMember extends phpDynamicProperties {
	public $runtimeState; //DistributedVirtualSwitchHostMemberRuntimeState
	public $config; //DistributedVirtualSwitchHostMemberConfigInfo
	public $productInfo; //DistributedVirtualSwitchProductSpec
	public $uplinkPortKey; //string
	public $status; //string
	public $statusDetail; //string

	function __construct($runtimeState = null, $config = null, $productInfo = null, $uplinkPortKey = null, $status = null, $statusDetail = null) {
		$this->runtimeState = $runtimeState;
		$this->config = $config;
		$this->productInfo = $productInfo;
		$this->uplinkPortKey = $uplinkPortKey;
		$this->status = $status;
		$this->statusDetail = $statusDetail;
	}
}

class ArrayOfDistributedVirtualSwitchHostMember extends phpDynamicProperties {
	public $DistributedVirtualSwitchHostMember; //DistributedVirtualSwitchHostMember

	function __construct($DistributedVirtualSwitchHostMember = null) {
		$this->DistributedVirtualSwitchHostMember = $DistributedVirtualSwitchHostMember;
	}
}

class DistributedVirtualSwitchHostProductSpec extends phpDynamicProperties {
	public $productLineId; //string
	public $version; //string

	function __construct($productLineId = null, $version = null) {
		$this->productLineId = $productLineId;
		$this->version = $version;
	}
}

class ArrayOfDistributedVirtualSwitchHostProductSpec extends phpDynamicProperties {
	public $DistributedVirtualSwitchHostProductSpec; //DistributedVirtualSwitchHostProductSpec

	function __construct($DistributedVirtualSwitchHostProductSpec = null) {
		$this->DistributedVirtualSwitchHostProductSpec = $DistributedVirtualSwitchHostProductSpec;
	}
}

class DistributedVirtualSwitchKeyedOpaqueBlob extends phpDynamicProperties {
	public $key; //string
	public $opaqueData; //string

	function __construct($key = null, $opaqueData = null) {
		$this->key = $key;
		$this->opaqueData = $opaqueData;
	}
}

class ArrayOfDistributedVirtualSwitchKeyedOpaqueBlob extends phpDynamicProperties {
	public $DistributedVirtualSwitchKeyedOpaqueBlob; //DistributedVirtualSwitchKeyedOpaqueBlob

	function __construct($DistributedVirtualSwitchKeyedOpaqueBlob = null) {
		$this->DistributedVirtualSwitchKeyedOpaqueBlob = $DistributedVirtualSwitchKeyedOpaqueBlob;
	}
}

class DVSNetworkResourcePoolAllocationInfo extends phpDynamicProperties {
	public $limit; //long
	public $shares; //SharesInfo
	public $priorityTag; //int

	function __construct($limit = null, $shares = null, $priorityTag = null) {
		$this->limit = $limit;
		$this->shares = $shares;
		$this->priorityTag = $priorityTag;
	}
}

class DVSNetworkResourcePoolConfigSpec extends phpDynamicProperties {
	public $key; //string
	public $configVersion; //string
	public $allocationInfo; //DVSNetworkResourcePoolAllocationInfo
	public $name; //string
	public $description; //string

	function __construct($key = null, $configVersion = null, $allocationInfo = null, $name = null, $description = null) {
		$this->key = $key;
		$this->configVersion = $configVersion;
		$this->allocationInfo = $allocationInfo;
		$this->name = $name;
		$this->description = $description;
	}
}

class ArrayOfDVSNetworkResourcePoolConfigSpec extends phpDynamicProperties {
	public $DVSNetworkResourcePoolConfigSpec; //DVSNetworkResourcePoolConfigSpec

	function __construct($DVSNetworkResourcePoolConfigSpec = null) {
		$this->DVSNetworkResourcePoolConfigSpec = $DVSNetworkResourcePoolConfigSpec;
	}
}

class DVSNetworkResourcePool extends phpDynamicProperties {
	public $key; //string
	public $name; //string
	public $description; //string
	public $configVersion; //string
	public $allocationInfo; //DVSNetworkResourcePoolAllocationInfo

	function __construct($key = null, $name = null, $description = null, $configVersion = null, $allocationInfo = null) {
		$this->key = $key;
		$this->name = $name;
		$this->description = $description;
		$this->configVersion = $configVersion;
		$this->allocationInfo = $allocationInfo;
	}
}

class ArrayOfDVSNetworkResourcePool extends phpDynamicProperties {
	public $DVSNetworkResourcePool; //DVSNetworkResourcePool

	function __construct($DVSNetworkResourcePool = null) {
		$this->DVSNetworkResourcePool = $DVSNetworkResourcePool;
	}
}

class DistributedVirtualSwitchPortConnectee extends phpDynamicProperties {
	public $connectedEntity; //ManagedObjectReference
	public $nicKey; //string
	public $type; //string
	public $addressHint; //string

	function __construct($connectedEntity = null, $nicKey = null, $type = null, $addressHint = null) {
		$this->connectedEntity = $connectedEntity;
		$this->nicKey = $nicKey;
		$this->type = $type;
		$this->addressHint = $addressHint;
	}
}

class DistributedVirtualSwitchPortConnection extends phpDynamicProperties {
	public $switchUuid; //string
	public $portgroupKey; //string
	public $portKey; //string
	public $connectionCookie; //int

	function __construct($switchUuid = null, $portgroupKey = null, $portKey = null, $connectionCookie = null) {
		$this->switchUuid = $switchUuid;
		$this->portgroupKey = $portgroupKey;
		$this->portKey = $portKey;
		$this->connectionCookie = $connectionCookie;
	}
}

class DistributedVirtualSwitchPortCriteria extends phpDynamicProperties {
	public $connected; //boolean
	public $active; //boolean
	public $uplinkPort; //boolean
	public $scope; //ManagedObjectReference
	public $portgroupKey; //string
	public $inside; //boolean
	public $portKey; //string

	function __construct($connected = null, $active = null, $uplinkPort = null, $scope = null, $portgroupKey = null, $inside = null, $portKey = null) {
		$this->connected = $connected;
		$this->active = $active;
		$this->uplinkPort = $uplinkPort;
		$this->scope = $scope;
		$this->portgroupKey = $portgroupKey;
		$this->inside = $inside;
		$this->portKey = $portKey;
	}
}

class DistributedVirtualSwitchPortStatistics extends phpDynamicProperties {
	public $packetsInMulticast; //long
	public $packetsOutMulticast; //long
	public $bytesInMulticast; //long
	public $bytesOutMulticast; //long
	public $packetsInUnicast; //long
	public $packetsOutUnicast; //long
	public $bytesInUnicast; //long
	public $bytesOutUnicast; //long
	public $packetsInBroadcast; //long
	public $packetsOutBroadcast; //long
	public $bytesInBroadcast; //long
	public $bytesOutBroadcast; //long
	public $packetsInDropped; //long
	public $packetsOutDropped; //long
	public $packetsInException; //long
	public $packetsOutException; //long

	function __construct($packetsInMulticast = null, $packetsOutMulticast = null, $bytesInMulticast = null, $bytesOutMulticast = null, $packetsInUnicast = null, $packetsOutUnicast = null, $bytesInUnicast = null, $bytesOutUnicast = null, $packetsInBroadcast = null, $packetsOutBroadcast = null, $bytesInBroadcast = null, $bytesOutBroadcast = null, $packetsInDropped = null, $packetsOutDropped = null, $packetsInException = null, $packetsOutException = null) {
		$this->packetsInMulticast = $packetsInMulticast;
		$this->packetsOutMulticast = $packetsOutMulticast;
		$this->bytesInMulticast = $bytesInMulticast;
		$this->bytesOutMulticast = $bytesOutMulticast;
		$this->packetsInUnicast = $packetsInUnicast;
		$this->packetsOutUnicast = $packetsOutUnicast;
		$this->bytesInUnicast = $bytesInUnicast;
		$this->bytesOutUnicast = $bytesOutUnicast;
		$this->packetsInBroadcast = $packetsInBroadcast;
		$this->packetsOutBroadcast = $packetsOutBroadcast;
		$this->bytesInBroadcast = $bytesInBroadcast;
		$this->bytesOutBroadcast = $bytesOutBroadcast;
		$this->packetsInDropped = $packetsInDropped;
		$this->packetsOutDropped = $packetsOutDropped;
		$this->packetsInException = $packetsInException;
		$this->packetsOutException = $packetsOutException;
	}
}

class DistributedVirtualSwitchProductSpec extends phpDynamicProperties {
	public $name; //string
	public $vendor; //string
	public $version; //string
	public $build; //string
	public $forwardingClass; //string
	public $bundleId; //string
	public $bundleUrl; //string

	function __construct($name = null, $vendor = null, $version = null, $build = null, $forwardingClass = null, $bundleId = null, $bundleUrl = null) {
		$this->name = $name;
		$this->vendor = $vendor;
		$this->version = $version;
		$this->build = $build;
		$this->forwardingClass = $forwardingClass;
		$this->bundleId = $bundleId;
		$this->bundleUrl = $bundleUrl;
	}
}

class ArrayOfDistributedVirtualSwitchProductSpec extends phpDynamicProperties {
	public $DistributedVirtualSwitchProductSpec; //DistributedVirtualSwitchProductSpec

	function __construct($DistributedVirtualSwitchProductSpec = null) {
		$this->DistributedVirtualSwitchProductSpec = $DistributedVirtualSwitchProductSpec;
	}
}

class VMwareDVSFeatureCapability extends phpDynamicProperties {
	public $vspanSupported; //boolean
	public $lldpSupported; //boolean
	public $ipfixSupported; //boolean

	function __construct($vspanSupported = null, $lldpSupported = null, $ipfixSupported = null) {
		$this->vspanSupported = $vspanSupported;
		$this->lldpSupported = $lldpSupported;
		$this->ipfixSupported = $ipfixSupported;
	}
}

class VMwareVspanPort extends phpDynamicProperties {
	public $portKey; //string
	public $uplinkPortName; //string
	public $wildcardPortConnecteeType; //string

	function __construct($portKey = null, $uplinkPortName = null, $wildcardPortConnecteeType = null) {
		$this->portKey = $portKey;
		$this->uplinkPortName = $uplinkPortName;
		$this->wildcardPortConnecteeType = $wildcardPortConnecteeType;
	}
}

class VMwareVspanSession extends phpDynamicProperties {
	public $key; //string
	public $name; //string
	public $description; //string
	public $enabled; //boolean
	public $sourcePortTransmitted; //VMwareVspanPort
	public $sourcePortReceived; //VMwareVspanPort
	public $destinationPort; //VMwareVspanPort
	public $encapsulationVlanId; //int
	public $stripOriginalVlan; //boolean
	public $mirroredPacketLength; //int
	public $normalTrafficAllowed; //boolean

	function __construct($key = null, $name = null, $description = null, $enabled = null, $sourcePortTransmitted = null, $sourcePortReceived = null, $destinationPort = null, $encapsulationVlanId = null, $stripOriginalVlan = null, $mirroredPacketLength = null, $normalTrafficAllowed = null) {
		$this->key = $key;
		$this->name = $name;
		$this->description = $description;
		$this->enabled = $enabled;
		$this->sourcePortTransmitted = $sourcePortTransmitted;
		$this->sourcePortReceived = $sourcePortReceived;
		$this->destinationPort = $destinationPort;
		$this->encapsulationVlanId = $encapsulationVlanId;
		$this->stripOriginalVlan = $stripOriginalVlan;
		$this->mirroredPacketLength = $mirroredPacketLength;
		$this->normalTrafficAllowed = $normalTrafficAllowed;
	}
}

class ArrayOfVMwareVspanSession extends phpDynamicProperties {
	public $VMwareVspanSession; //VMwareVspanSession

	function __construct($VMwareVspanSession = null) {
		$this->VMwareVspanSession = $VMwareVspanSession;
	}
}

class VMwareIpfixConfig extends phpDynamicProperties {
	public $collectorIpAddress; //string
	public $collectorPort; //int
	public $activeFlowTimeout; //int
	public $idleFlowTimeout; //int
	public $samplingRate; //int
	public $internalFlowsOnly; //boolean

	function __construct($collectorIpAddress = null, $collectorPort = null, $activeFlowTimeout = null, $idleFlowTimeout = null, $samplingRate = null, $internalFlowsOnly = null) {
		$this->collectorIpAddress = $collectorIpAddress;
		$this->collectorPort = $collectorPort;
		$this->activeFlowTimeout = $activeFlowTimeout;
		$this->idleFlowTimeout = $idleFlowTimeout;
		$this->samplingRate = $samplingRate;
		$this->internalFlowsOnly = $internalFlowsOnly;
	}
}

class VMwareDVSConfigInfo extends phpDynamicProperties {
	public $vspanSession; //VMwareVspanSession
	public $pvlanConfig; //VMwareDVSPvlanMapEntry
	public $maxMtu; //int
	public $linkDiscoveryProtocolConfig; //LinkDiscoveryProtocolConfig
	public $ipfixConfig; //VMwareIpfixConfig

	function __construct($vspanSession = null, $pvlanConfig = null, $maxMtu = null, $linkDiscoveryProtocolConfig = null, $ipfixConfig = null) {
		$this->vspanSession = $vspanSession;
		$this->pvlanConfig = $pvlanConfig;
		$this->maxMtu = $maxMtu;
		$this->linkDiscoveryProtocolConfig = $linkDiscoveryProtocolConfig;
		$this->ipfixConfig = $ipfixConfig;
	}
}

class VMwareDVSConfigSpec extends phpDynamicProperties {
	public $pvlanConfigSpec; //VMwareDVSPvlanConfigSpec
	public $vspanConfigSpec; //VMwareDVSVspanConfigSpec
	public $maxMtu; //int
	public $linkDiscoveryProtocolConfig; //LinkDiscoveryProtocolConfig
	public $ipfixConfig; //VMwareIpfixConfig

	function __construct($pvlanConfigSpec = null, $vspanConfigSpec = null, $maxMtu = null, $linkDiscoveryProtocolConfig = null, $ipfixConfig = null) {
		$this->pvlanConfigSpec = $pvlanConfigSpec;
		$this->vspanConfigSpec = $vspanConfigSpec;
		$this->maxMtu = $maxMtu;
		$this->linkDiscoveryProtocolConfig = $linkDiscoveryProtocolConfig;
		$this->ipfixConfig = $ipfixConfig;
	}
}

class VMwareUplinkPortOrderPolicy extends phpDynamicProperties {
	public $activeUplinkPort; //string
	public $standbyUplinkPort; //string

	function __construct($activeUplinkPort = null, $standbyUplinkPort = null) {
		$this->activeUplinkPort = $activeUplinkPort;
		$this->standbyUplinkPort = $standbyUplinkPort;
	}
}

class DVSFailureCriteria extends phpDynamicProperties {
	public $checkSpeed; //StringPolicy
	public $speed; //IntPolicy
	public $checkDuplex; //BoolPolicy
	public $fullDuplex; //BoolPolicy
	public $checkErrorPercent; //BoolPolicy
	public $percentage; //IntPolicy
	public $checkBeacon; //BoolPolicy

	function __construct($checkSpeed = null, $speed = null, $checkDuplex = null, $fullDuplex = null, $checkErrorPercent = null, $percentage = null, $checkBeacon = null) {
		$this->checkSpeed = $checkSpeed;
		$this->speed = $speed;
		$this->checkDuplex = $checkDuplex;
		$this->fullDuplex = $fullDuplex;
		$this->checkErrorPercent = $checkErrorPercent;
		$this->percentage = $percentage;
		$this->checkBeacon = $checkBeacon;
	}
}

class VmwareUplinkPortTeamingPolicy extends phpDynamicProperties {
	public $policy; //StringPolicy
	public $reversePolicy; //BoolPolicy
	public $notifySwitches; //BoolPolicy
	public $rollingOrder; //BoolPolicy
	public $failureCriteria; //DVSFailureCriteria
	public $uplinkPortOrder; //VMwareUplinkPortOrderPolicy

	function __construct($policy = null, $reversePolicy = null, $notifySwitches = null, $rollingOrder = null, $failureCriteria = null, $uplinkPortOrder = null) {
		$this->policy = $policy;
		$this->reversePolicy = $reversePolicy;
		$this->notifySwitches = $notifySwitches;
		$this->rollingOrder = $rollingOrder;
		$this->failureCriteria = $failureCriteria;
		$this->uplinkPortOrder = $uplinkPortOrder;
	}
}

class VmwareDistributedVirtualSwitchVlanSpec extends phpDynamicProperties {
}

class VmwareDistributedVirtualSwitchPvlanSpec extends phpDynamicProperties {
	public $pvlanId; //int

	function __construct($pvlanId = null) {
		$this->pvlanId = $pvlanId;
	}
}

class VmwareDistributedVirtualSwitchVlanIdSpec extends phpDynamicProperties {
	public $vlanId; //int

	function __construct($vlanId = null) {
		$this->vlanId = $vlanId;
	}
}

class VmwareDistributedVirtualSwitchTrunkVlanSpec extends phpDynamicProperties {
	public $vlanId; //NumericRange

	function __construct($vlanId = null) {
		$this->vlanId = $vlanId;
	}
}

class DVSSecurityPolicy extends phpDynamicProperties {
	public $allowPromiscuous; //BoolPolicy
	public $macChanges; //BoolPolicy
	public $forgedTransmits; //BoolPolicy

	function __construct($allowPromiscuous = null, $macChanges = null, $forgedTransmits = null) {
		$this->allowPromiscuous = $allowPromiscuous;
		$this->macChanges = $macChanges;
		$this->forgedTransmits = $forgedTransmits;
	}
}

class VMwareDVSPortSetting extends phpDynamicProperties {
	public $vlan; //VmwareDistributedVirtualSwitchVlanSpec
	public $qosTag; //IntPolicy
	public $uplinkTeamingPolicy; //VmwareUplinkPortTeamingPolicy
	public $securityPolicy; //DVSSecurityPolicy
	public $ipfixEnabled; //BoolPolicy
	public $txUplink; //BoolPolicy

	function __construct($vlan = null, $qosTag = null, $uplinkTeamingPolicy = null, $securityPolicy = null, $ipfixEnabled = null, $txUplink = null) {
		$this->vlan = $vlan;
		$this->qosTag = $qosTag;
		$this->uplinkTeamingPolicy = $uplinkTeamingPolicy;
		$this->securityPolicy = $securityPolicy;
		$this->ipfixEnabled = $ipfixEnabled;
		$this->txUplink = $txUplink;
	}
}

class VMwareDVSPortgroupPolicy extends phpDynamicProperties {
	public $vlanOverrideAllowed; //boolean
	public $uplinkTeamingOverrideAllowed; //boolean
	public $securityPolicyOverrideAllowed; //boolean
	public $ipfixOverrideAllowed; //boolean

	function __construct($vlanOverrideAllowed = null, $uplinkTeamingOverrideAllowed = null, $securityPolicyOverrideAllowed = null, $ipfixOverrideAllowed = null) {
		$this->vlanOverrideAllowed = $vlanOverrideAllowed;
		$this->uplinkTeamingOverrideAllowed = $uplinkTeamingOverrideAllowed;
		$this->securityPolicyOverrideAllowed = $securityPolicyOverrideAllowed;
		$this->ipfixOverrideAllowed = $ipfixOverrideAllowed;
	}
}

class VMwareDVSPvlanConfigSpec extends phpDynamicProperties {
	public $pvlanEntry; //VMwareDVSPvlanMapEntry
	public $operation; //string

	function __construct($pvlanEntry = null, $operation = null) {
		$this->pvlanEntry = $pvlanEntry;
		$this->operation = $operation;
	}
}

class ArrayOfVMwareDVSPvlanConfigSpec extends phpDynamicProperties {
	public $VMwareDVSPvlanConfigSpec; //VMwareDVSPvlanConfigSpec

	function __construct($VMwareDVSPvlanConfigSpec = null) {
		$this->VMwareDVSPvlanConfigSpec = $VMwareDVSPvlanConfigSpec;
	}
}

class VMwareDVSPvlanMapEntry extends phpDynamicProperties {
	public $primaryVlanId; //int
	public $secondaryVlanId; //int
	public $pvlanType; //string

	function __construct($primaryVlanId = null, $secondaryVlanId = null, $pvlanType = null) {
		$this->primaryVlanId = $primaryVlanId;
		$this->secondaryVlanId = $secondaryVlanId;
		$this->pvlanType = $pvlanType;
	}
}

class ArrayOfVMwareDVSPvlanMapEntry extends phpDynamicProperties {
	public $VMwareDVSPvlanMapEntry; //VMwareDVSPvlanMapEntry

	function __construct($VMwareDVSPvlanMapEntry = null) {
		$this->VMwareDVSPvlanMapEntry = $VMwareDVSPvlanMapEntry;
	}
}

class VMwareDVSVspanConfigSpec extends phpDynamicProperties {
	public $vspanSession; //VMwareVspanSession
	public $operation; //string

	function __construct($vspanSession = null, $operation = null) {
		$this->vspanSession = $vspanSession;
		$this->operation = $operation;
	}
}

class ArrayOfVMwareDVSVspanConfigSpec extends phpDynamicProperties {
	public $VMwareDVSVspanConfigSpec; //VMwareDVSVspanConfigSpec

	function __construct($VMwareDVSVspanConfigSpec = null) {
		$this->VMwareDVSVspanConfigSpec = $VMwareDVSVspanConfigSpec;
	}
}

class Event extends phpDynamicProperties {
	public $key; //int
	public $chainId; //int
	public $createdTime; //dateTime
	public $userName; //string
	public $datacenter; //DatacenterEventArgument
	public $computeResource; //ComputeResourceEventArgument
	public $host; //HostEventArgument
	public $vm; //VmEventArgument
	public $ds; //DatastoreEventArgument
	public $net; //NetworkEventArgument
	public $dvs; //DvsEventArgument
	public $fullFormattedMessage; //string
	public $changeTag; //string

	function __construct($key = null, $chainId = null, $createdTime = null, $userName = null, $datacenter = null, $computeResource = null, $host = null, $vm = null, $ds = null, $net = null, $dvs = null, $fullFormattedMessage = null, $changeTag = null) {
		$this->key = $key;
		$this->chainId = $chainId;
		$this->createdTime = $createdTime;
		$this->userName = $userName;
		$this->datacenter = $datacenter;
		$this->computeResource = $computeResource;
		$this->host = $host;
		$this->vm = $vm;
		$this->ds = $ds;
		$this->net = $net;
		$this->dvs = $dvs;
		$this->fullFormattedMessage = $fullFormattedMessage;
		$this->changeTag = $changeTag;
	}
}

class ArrayOfEvent extends phpDynamicProperties {
	public $Event; //Event

	function __construct($Event = null) {
		$this->Event = $Event;
	}
}

class GeneralEvent extends phpDynamicProperties {
	public $message; //string

	function __construct($message = null) {
		$this->message = $message;
	}
}

class GeneralHostInfoEvent extends phpDynamicProperties {
}

class GeneralHostWarningEvent extends phpDynamicProperties {
}

class GeneralHostErrorEvent extends phpDynamicProperties {
}

class GeneralVmInfoEvent extends phpDynamicProperties {
}

class GeneralVmWarningEvent extends phpDynamicProperties {
}

class GeneralVmErrorEvent extends phpDynamicProperties {
}

class GeneralUserEvent extends phpDynamicProperties {
	public $entity; //ManagedEntityEventArgument

	function __construct($entity = null) {
		$this->entity = $entity;
	}
}

class ExtendedEventPair extends phpDynamicProperties {
	public $key; //string
	public $value; //string

	function __construct($key = null, $value = null) {
		$this->key = $key;
		$this->value = $value;
	}
}

class ArrayOfExtendedEventPair extends phpDynamicProperties {
	public $ExtendedEventPair; //ExtendedEventPair

	function __construct($ExtendedEventPair = null) {
		$this->ExtendedEventPair = $ExtendedEventPair;
	}
}

class ExtendedEvent extends phpDynamicProperties {
	public $eventTypeId; //string
	public $managedObject; //ManagedObjectReference
	public $data; //ExtendedEventPair

	function __construct($eventTypeId = null, $managedObject = null, $data = null) {
		$this->eventTypeId = $eventTypeId;
		$this->managedObject = $managedObject;
		$this->data = $data;
	}
}

class HealthStatusChangedEvent extends phpDynamicProperties {
	public $componentId; //string
	public $oldStatus; //string
	public $newStatus; //string
	public $componentName; //string

	function __construct($componentId = null, $oldStatus = null, $newStatus = null, $componentName = null) {
		$this->componentId = $componentId;
		$this->oldStatus = $oldStatus;
		$this->newStatus = $newStatus;
		$this->componentName = $componentName;
	}
}

class HostInventoryUnreadableEvent extends phpDynamicProperties {
}

class DatacenterEvent extends phpDynamicProperties {
}

class DatacenterCreatedEvent extends phpDynamicProperties {
	public $parent; //FolderEventArgument

	function __construct($parent = null) {
		$this->parent = $parent;
	}
}

class DatacenterRenamedEvent extends phpDynamicProperties {
	public $oldName; //string
	public $newName; //string

	function __construct($oldName = null, $newName = null) {
		$this->oldName = $oldName;
		$this->newName = $newName;
	}
}

class SessionEvent extends phpDynamicProperties {
}

class ServerStartedSessionEvent extends phpDynamicProperties {
}

class UserLoginSessionEvent extends phpDynamicProperties {
	public $ipAddress; //string
	public $locale; //string
	public $sessionId; //string

	function __construct($ipAddress = null, $locale = null, $sessionId = null) {
		$this->ipAddress = $ipAddress;
		$this->locale = $locale;
		$this->sessionId = $sessionId;
	}
}

class UserLogoutSessionEvent extends phpDynamicProperties {
}

class BadUsernameSessionEvent extends phpDynamicProperties {
	public $ipAddress; //string

	function __construct($ipAddress = null) {
		$this->ipAddress = $ipAddress;
	}
}

class AlreadyAuthenticatedSessionEvent extends phpDynamicProperties {
}

class NoAccessUserEvent extends phpDynamicProperties {
	public $ipAddress; //string

	function __construct($ipAddress = null) {
		$this->ipAddress = $ipAddress;
	}
}

class SessionTerminatedEvent extends phpDynamicProperties {
	public $sessionId; //string
	public $terminatedUsername; //string

	function __construct($sessionId = null, $terminatedUsername = null) {
		$this->sessionId = $sessionId;
		$this->terminatedUsername = $terminatedUsername;
	}
}

class GlobalMessageChangedEvent extends phpDynamicProperties {
	public $message; //string

	function __construct($message = null) {
		$this->message = $message;
	}
}

class UpgradeEvent extends phpDynamicProperties {
	public $message; //string

	function __construct($message = null) {
		$this->message = $message;
	}
}

class InfoUpgradeEvent extends phpDynamicProperties {
}

class WarningUpgradeEvent extends phpDynamicProperties {
}

class ErrorUpgradeEvent extends phpDynamicProperties {
}

class UserUpgradeEvent extends phpDynamicProperties {
}

class HostEvent extends phpDynamicProperties {
}

class HostDasEvent extends phpDynamicProperties {
}

class HostConnectedEvent extends phpDynamicProperties {
}

class HostDisconnectedEvent extends phpDynamicProperties {
	public $reason; //string

	function __construct($reason = null) {
		$this->reason = $reason;
	}
}

class HostSyncFailedEvent extends phpDynamicProperties {
	public $reason; //LocalizedMethodFault

	function __construct($reason = null) {
		$this->reason = $reason;
	}
}

class HostConnectionLostEvent extends phpDynamicProperties {
}

class HostReconnectionFailedEvent extends phpDynamicProperties {
}

class HostCnxFailedNoConnectionEvent extends phpDynamicProperties {
}

class HostCnxFailedBadUsernameEvent extends phpDynamicProperties {
}

class HostCnxFailedBadVersionEvent extends phpDynamicProperties {
}

class HostCnxFailedAlreadyManagedEvent extends phpDynamicProperties {
	public $serverName; //string

	function __construct($serverName = null) {
		$this->serverName = $serverName;
	}
}

class HostCnxFailedNoLicenseEvent extends phpDynamicProperties {
}

class HostCnxFailedNetworkErrorEvent extends phpDynamicProperties {
}

class HostRemovedEvent extends phpDynamicProperties {
}

class HostCnxFailedCcagentUpgradeEvent extends phpDynamicProperties {
}

class HostCnxFailedBadCcagentEvent extends phpDynamicProperties {
}

class HostCnxFailedEvent extends phpDynamicProperties {
}

class HostCnxFailedAccountFailedEvent extends phpDynamicProperties {
}

class HostCnxFailedNoAccessEvent extends phpDynamicProperties {
}

class HostShutdownEvent extends phpDynamicProperties {
	public $reason; //string

	function __construct($reason = null) {
		$this->reason = $reason;
	}
}

class HostCnxFailedNotFoundEvent extends phpDynamicProperties {
}

class HostCnxFailedTimeoutEvent extends phpDynamicProperties {
}

class HostUpgradeFailedEvent extends phpDynamicProperties {
}

class EnteringMaintenanceModeEvent extends phpDynamicProperties {
}

class EnteredMaintenanceModeEvent extends phpDynamicProperties {
}

class ExitMaintenanceModeEvent extends phpDynamicProperties {
}

class CanceledHostOperationEvent extends phpDynamicProperties {
}

class TimedOutHostOperationEvent extends phpDynamicProperties {
}

class HostDasEnabledEvent extends phpDynamicProperties {
}

class HostDasDisabledEvent extends phpDynamicProperties {
}

class HostDasEnablingEvent extends phpDynamicProperties {
}

class HostDasDisablingEvent extends phpDynamicProperties {
}

class HostDasErrorEvent extends phpDynamicProperties {
	public $message; //string
	public $reason; //string

	function __construct($message = null, $reason = null) {
		$this->message = $message;
		$this->reason = $reason;
	}
}

class HostDasOkEvent extends phpDynamicProperties {
}

class VcAgentUpgradedEvent extends phpDynamicProperties {
}

class VcAgentUninstalledEvent extends phpDynamicProperties {
}

class VcAgentUpgradeFailedEvent extends phpDynamicProperties {
	public $reason; //string

	function __construct($reason = null) {
		$this->reason = $reason;
	}
}

class VcAgentUninstallFailedEvent extends phpDynamicProperties {
	public $reason; //string

	function __construct($reason = null) {
		$this->reason = $reason;
	}
}

class HostAddedEvent extends phpDynamicProperties {
}

class HostAddFailedEvent extends phpDynamicProperties {
	public $hostname; //string

	function __construct($hostname = null) {
		$this->hostname = $hostname;
	}
}

class HostIpChangedEvent extends phpDynamicProperties {
	public $oldIP; //string
	public $newIP; //string

	function __construct($oldIP = null, $newIP = null) {
		$this->oldIP = $oldIP;
		$this->newIP = $newIP;
	}
}

class EnteringStandbyModeEvent extends phpDynamicProperties {
}

class DrsEnteringStandbyModeEvent extends phpDynamicProperties {
}

class EnteredStandbyModeEvent extends phpDynamicProperties {
}

class DrsEnteredStandbyModeEvent extends phpDynamicProperties {
}

class ExitingStandbyModeEvent extends phpDynamicProperties {
}

class DrsExitingStandbyModeEvent extends phpDynamicProperties {
}

class ExitedStandbyModeEvent extends phpDynamicProperties {
}

class DrsExitedStandbyModeEvent extends phpDynamicProperties {
}

class ExitStandbyModeFailedEvent extends phpDynamicProperties {
}

class DrsExitStandbyModeFailedEvent extends phpDynamicProperties {
}

class UpdatedAgentBeingRestartedEvent extends phpDynamicProperties {
}

class AccountCreatedEvent extends phpDynamicProperties {
	public $spec; //HostAccountSpec
	public $group; //boolean

	function __construct($spec = null, $group = null) {
		$this->spec = $spec;
		$this->group = $group;
	}
}

class AccountRemovedEvent extends phpDynamicProperties {
	public $account; //string
	public $group; //boolean

	function __construct($account = null, $group = null) {
		$this->account = $account;
		$this->group = $group;
	}
}

class UserPasswordChanged extends phpDynamicProperties {
	public $userLogin; //string

	function __construct($userLogin = null) {
		$this->userLogin = $userLogin;
	}
}

class AccountUpdatedEvent extends phpDynamicProperties {
	public $spec; //HostAccountSpec
	public $group; //boolean

	function __construct($spec = null, $group = null) {
		$this->spec = $spec;
		$this->group = $group;
	}
}

class UserAssignedToGroup extends phpDynamicProperties {
	public $userLogin; //string
	public $group; //string

	function __construct($userLogin = null, $group = null) {
		$this->userLogin = $userLogin;
		$this->group = $group;
	}
}

class UserUnassignedFromGroup extends phpDynamicProperties {
	public $userLogin; //string
	public $group; //string

	function __construct($userLogin = null, $group = null) {
		$this->userLogin = $userLogin;
		$this->group = $group;
	}
}

class DatastorePrincipalConfigured extends phpDynamicProperties {
	public $datastorePrincipal; //string

	function __construct($datastorePrincipal = null) {
		$this->datastorePrincipal = $datastorePrincipal;
	}
}

class VMFSDatastoreCreatedEvent extends phpDynamicProperties {
	public $datastore; //DatastoreEventArgument

	function __construct($datastore = null) {
		$this->datastore = $datastore;
	}
}

class NASDatastoreCreatedEvent extends phpDynamicProperties {
	public $datastore; //DatastoreEventArgument

	function __construct($datastore = null) {
		$this->datastore = $datastore;
	}
}

class LocalDatastoreCreatedEvent extends phpDynamicProperties {
	public $datastore; //DatastoreEventArgument

	function __construct($datastore = null) {
		$this->datastore = $datastore;
	}
}

class VMFSDatastoreExtendedEvent extends phpDynamicProperties {
	public $datastore; //DatastoreEventArgument

	function __construct($datastore = null) {
		$this->datastore = $datastore;
	}
}

class VMFSDatastoreExpandedEvent extends phpDynamicProperties {
	public $datastore; //DatastoreEventArgument

	function __construct($datastore = null) {
		$this->datastore = $datastore;
	}
}

class DatastoreRemovedOnHostEvent extends phpDynamicProperties {
	public $datastore; //DatastoreEventArgument

	function __construct($datastore = null) {
		$this->datastore = $datastore;
	}
}

class DatastoreRenamedOnHostEvent extends phpDynamicProperties {
	public $oldName; //string
	public $newName; //string

	function __construct($oldName = null, $newName = null) {
		$this->oldName = $oldName;
		$this->newName = $newName;
	}
}

class DuplicateIpDetectedEvent extends phpDynamicProperties {
	public $duplicateIP; //string
	public $macAddress; //string

	function __construct($duplicateIP = null, $macAddress = null) {
		$this->duplicateIP = $duplicateIP;
		$this->macAddress = $macAddress;
	}
}

class DatastoreDiscoveredEvent extends phpDynamicProperties {
	public $datastore; //DatastoreEventArgument

	function __construct($datastore = null) {
		$this->datastore = $datastore;
	}
}

class DrsResourceConfigureFailedEvent extends phpDynamicProperties {
	public $reason; //LocalizedMethodFault

	function __construct($reason = null) {
		$this->reason = $reason;
	}
}

class DrsResourceConfigureSyncedEvent extends phpDynamicProperties {
}

class HostGetShortNameFailedEvent extends phpDynamicProperties {
}

class HostShortNameToIpFailedEvent extends phpDynamicProperties {
	public $shortName; //string

	function __construct($shortName = null) {
		$this->shortName = $shortName;
	}
}

class HostIpToShortNameFailedEvent extends phpDynamicProperties {
}

class HostPrimaryAgentNotShortNameEvent extends phpDynamicProperties {
	public $primaryAgent; //string

	function __construct($primaryAgent = null) {
		$this->primaryAgent = $primaryAgent;
	}
}

class HostNotInClusterEvent extends phpDynamicProperties {
}

class HostIsolationIpPingFailedEvent extends phpDynamicProperties {
	public $isolationIp; //string

	function __construct($isolationIp = null) {
		$this->isolationIp = $isolationIp;
	}
}

class HostIpInconsistentEvent extends phpDynamicProperties {
	public $ipAddress; //string
	public $ipAddress2; //string

	function __construct($ipAddress = null, $ipAddress2 = null) {
		$this->ipAddress = $ipAddress;
		$this->ipAddress2 = $ipAddress2;
	}
}

class HostUserWorldSwapNotEnabledEvent extends phpDynamicProperties {
}

class HostNonCompliantEvent extends phpDynamicProperties {
}

class HostCompliantEvent extends phpDynamicProperties {
}

class HostComplianceCheckedEvent extends phpDynamicProperties {
	public $profile; //ProfileEventArgument

	function __construct($profile = null) {
		$this->profile = $profile;
	}
}

class ClusterComplianceCheckedEvent extends phpDynamicProperties {
	public $profile; //ProfileEventArgument

	function __construct($profile = null) {
		$this->profile = $profile;
	}
}

class ProfileEvent extends phpDynamicProperties {
	public $profile; //ProfileEventArgument

	function __construct($profile = null) {
		$this->profile = $profile;
	}
}

class ProfileCreatedEvent extends phpDynamicProperties {
}

class ProfileRemovedEvent extends phpDynamicProperties {
}

class ProfileAssociatedEvent extends phpDynamicProperties {
}

class ProfileDissociatedEvent extends phpDynamicProperties {
}

class HostConfigAppliedEvent extends phpDynamicProperties {
}

class ProfileReferenceHostChangedEvent extends phpDynamicProperties {
	public $referenceHost; //ManagedObjectReference

	function __construct($referenceHost = null) {
		$this->referenceHost = $referenceHost;
	}
}

class ProfileChangedEvent extends phpDynamicProperties {
}

class HostProfileAppliedEvent extends phpDynamicProperties {
	public $profile; //ProfileEventArgument

	function __construct($profile = null) {
		$this->profile = $profile;
	}
}

class HostShortNameInconsistentEvent extends phpDynamicProperties {
	public $shortName; //string
	public $shortName2; //string

	function __construct($shortName = null, $shortName2 = null) {
		$this->shortName = $shortName;
		$this->shortName2 = $shortName2;
	}
}

class HostNoRedundantManagementNetworkEvent extends phpDynamicProperties {
}

class HostNoAvailableNetworksEvent extends phpDynamicProperties {
	public $ips; //string

	function __construct($ips = null) {
		$this->ips = $ips;
	}
}

class HostExtraNetworksEvent extends phpDynamicProperties {
	public $ips; //string

	function __construct($ips = null) {
		$this->ips = $ips;
	}
}

class HostNoHAEnabledPortGroupsEvent extends phpDynamicProperties {
}

class HostMissingNetworksEvent extends phpDynamicProperties {
	public $ips; //string

	function __construct($ips = null) {
		$this->ips = $ips;
	}
}

class VnicPortArgument extends phpDynamicProperties {
	public $vnic; //string
	public $port; //DistributedVirtualSwitchPortConnection

	function __construct($vnic = null, $port = null) {
		$this->vnic = $vnic;
		$this->port = $port;
	}
}

class ArrayOfVnicPortArgument extends phpDynamicProperties {
	public $VnicPortArgument; //VnicPortArgument

	function __construct($VnicPortArgument = null) {
		$this->VnicPortArgument = $VnicPortArgument;
	}
}

class HostVnicConnectedToCustomizedDVPortEvent extends phpDynamicProperties {
	public $vnic; //VnicPortArgument

	function __construct($vnic = null) {
		$this->vnic = $vnic;
	}
}

class GhostDvsProxySwitchDetectedEvent extends phpDynamicProperties {
	public $switchUuid; //string

	function __construct($switchUuid = null) {
		$this->switchUuid = $switchUuid;
	}
}

class GhostDvsProxySwitchRemovedEvent extends phpDynamicProperties {
	public $switchUuid; //string

	function __construct($switchUuid = null) {
		$this->switchUuid = $switchUuid;
	}
}

class VmEvent extends phpDynamicProperties {
	public $template; //boolean

	function __construct($template = null) {
		$this->template = $template;
	}
}

class VmPoweredOffEvent extends phpDynamicProperties {
}

class VmPoweredOnEvent extends phpDynamicProperties {
}

class VmSuspendedEvent extends phpDynamicProperties {
}

class VmStartingEvent extends phpDynamicProperties {
}

class VmStoppingEvent extends phpDynamicProperties {
}

class VmSuspendingEvent extends phpDynamicProperties {
}

class VmResumingEvent extends phpDynamicProperties {
}

class VmDisconnectedEvent extends phpDynamicProperties {
}

class VmRemoteConsoleConnectedEvent extends phpDynamicProperties {
}

class VmRemoteConsoleDisconnectedEvent extends phpDynamicProperties {
}

class VmDiscoveredEvent extends phpDynamicProperties {
}

class VmOrphanedEvent extends phpDynamicProperties {
}

class VmBeingCreatedEvent extends phpDynamicProperties {
	public $configSpec; //VirtualMachineConfigSpec

	function __construct($configSpec = null) {
		$this->configSpec = $configSpec;
	}
}

class VmCreatedEvent extends phpDynamicProperties {
}

class VmStartRecordingEvent extends phpDynamicProperties {
}

class VmEndRecordingEvent extends phpDynamicProperties {
}

class VmStartReplayingEvent extends phpDynamicProperties {
}

class VmEndReplayingEvent extends phpDynamicProperties {
}

class VmRegisteredEvent extends phpDynamicProperties {
}

class VmAutoRenameEvent extends phpDynamicProperties {
	public $oldName; //string
	public $newName; //string

	function __construct($oldName = null, $newName = null) {
		$this->oldName = $oldName;
		$this->newName = $newName;
	}
}

class VmBeingHotMigratedEvent extends phpDynamicProperties {
	public $destHost; //HostEventArgument
	public $destDatacenter; //DatacenterEventArgument
	public $destDatastore; //DatastoreEventArgument

	function __construct($destHost = null, $destDatacenter = null, $destDatastore = null) {
		$this->destHost = $destHost;
		$this->destDatacenter = $destDatacenter;
		$this->destDatastore = $destDatastore;
	}
}

class VmResettingEvent extends phpDynamicProperties {
}

class VmStaticMacConflictEvent extends phpDynamicProperties {
	public $conflictedVm; //VmEventArgument
	public $mac; //string

	function __construct($conflictedVm = null, $mac = null) {
		$this->conflictedVm = $conflictedVm;
		$this->mac = $mac;
	}
}

class VmMacConflictEvent extends phpDynamicProperties {
	public $conflictedVm; //VmEventArgument
	public $mac; //string

	function __construct($conflictedVm = null, $mac = null) {
		$this->conflictedVm = $conflictedVm;
		$this->mac = $mac;
	}
}

class VmBeingDeployedEvent extends phpDynamicProperties {
	public $srcTemplate; //VmEventArgument

	function __construct($srcTemplate = null) {
		$this->srcTemplate = $srcTemplate;
	}
}

class VmDeployFailedEvent extends phpDynamicProperties {
	public $destDatastore; //EntityEventArgument
	public $reason; //LocalizedMethodFault

	function __construct($destDatastore = null, $reason = null) {
		$this->destDatastore = $destDatastore;
		$this->reason = $reason;
	}
}

class VmDeployedEvent extends phpDynamicProperties {
	public $srcTemplate; //VmEventArgument

	function __construct($srcTemplate = null) {
		$this->srcTemplate = $srcTemplate;
	}
}

class VmMacChangedEvent extends phpDynamicProperties {
	public $adapter; //string
	public $oldMac; //string
	public $newMac; //string

	function __construct($adapter = null, $oldMac = null, $newMac = null) {
		$this->adapter = $adapter;
		$this->oldMac = $oldMac;
		$this->newMac = $newMac;
	}
}

class VmMacAssignedEvent extends phpDynamicProperties {
	public $adapter; //string
	public $mac; //string

	function __construct($adapter = null, $mac = null) {
		$this->adapter = $adapter;
		$this->mac = $mac;
	}
}

class VmUuidConflictEvent extends phpDynamicProperties {
	public $conflictedVm; //VmEventArgument
	public $uuid; //string

	function __construct($conflictedVm = null, $uuid = null) {
		$this->conflictedVm = $conflictedVm;
		$this->uuid = $uuid;
	}
}

class VmInstanceUuidConflictEvent extends phpDynamicProperties {
	public $conflictedVm; //VmEventArgument
	public $instanceUuid; //string

	function __construct($conflictedVm = null, $instanceUuid = null) {
		$this->conflictedVm = $conflictedVm;
		$this->instanceUuid = $instanceUuid;
	}
}

class VmBeingMigratedEvent extends phpDynamicProperties {
	public $destHost; //HostEventArgument
	public $destDatacenter; //DatacenterEventArgument
	public $destDatastore; //DatastoreEventArgument

	function __construct($destHost = null, $destDatacenter = null, $destDatastore = null) {
		$this->destHost = $destHost;
		$this->destDatacenter = $destDatacenter;
		$this->destDatastore = $destDatastore;
	}
}

class VmFailedMigrateEvent extends phpDynamicProperties {
	public $destHost; //HostEventArgument
	public $reason; //LocalizedMethodFault
	public $destDatacenter; //DatacenterEventArgument
	public $destDatastore; //DatastoreEventArgument

	function __construct($destHost = null, $reason = null, $destDatacenter = null, $destDatastore = null) {
		$this->destHost = $destHost;
		$this->reason = $reason;
		$this->destDatacenter = $destDatacenter;
		$this->destDatastore = $destDatastore;
	}
}

class VmMigratedEvent extends phpDynamicProperties {
	public $sourceHost; //HostEventArgument
	public $sourceDatacenter; //DatacenterEventArgument
	public $sourceDatastore; //DatastoreEventArgument

	function __construct($sourceHost = null, $sourceDatacenter = null, $sourceDatastore = null) {
		$this->sourceHost = $sourceHost;
		$this->sourceDatacenter = $sourceDatacenter;
		$this->sourceDatastore = $sourceDatastore;
	}
}

class VmUnsupportedStartingEvent extends phpDynamicProperties {
	public $guestId; //string

	function __construct($guestId = null) {
		$this->guestId = $guestId;
	}
}

class DrsVmMigratedEvent extends phpDynamicProperties {
}

class DrsVmPoweredOnEvent extends phpDynamicProperties {
}

class DrsRuleViolationEvent extends phpDynamicProperties {
}

class DrsRuleComplianceEvent extends phpDynamicProperties {
}

class VmRelocateSpecEvent extends phpDynamicProperties {
}

class VmBeingRelocatedEvent extends phpDynamicProperties {
	public $destHost; //HostEventArgument
	public $destDatacenter; //DatacenterEventArgument
	public $destDatastore; //DatastoreEventArgument

	function __construct($destHost = null, $destDatacenter = null, $destDatastore = null) {
		$this->destHost = $destHost;
		$this->destDatacenter = $destDatacenter;
		$this->destDatastore = $destDatastore;
	}
}

class VmRelocatedEvent extends phpDynamicProperties {
	public $sourceHost; //HostEventArgument
	public $sourceDatacenter; //DatacenterEventArgument
	public $sourceDatastore; //DatastoreEventArgument

	function __construct($sourceHost = null, $sourceDatacenter = null, $sourceDatastore = null) {
		$this->sourceHost = $sourceHost;
		$this->sourceDatacenter = $sourceDatacenter;
		$this->sourceDatastore = $sourceDatastore;
	}
}

class VmRelocateFailedEvent extends phpDynamicProperties {
	public $destHost; //HostEventArgument
	public $reason; //LocalizedMethodFault
	public $destDatacenter; //DatacenterEventArgument
	public $destDatastore; //DatastoreEventArgument

	function __construct($destHost = null, $reason = null, $destDatacenter = null, $destDatastore = null) {
		$this->destHost = $destHost;
		$this->reason = $reason;
		$this->destDatacenter = $destDatacenter;
		$this->destDatastore = $destDatastore;
	}
}

class VmEmigratingEvent extends phpDynamicProperties {
}

class VmCloneEvent extends phpDynamicProperties {
}

class VmBeingClonedEvent extends phpDynamicProperties {
	public $destFolder; //FolderEventArgument
	public $destName; //string
	public $destHost; //HostEventArgument

	function __construct($destFolder = null, $destName = null, $destHost = null) {
		$this->destFolder = $destFolder;
		$this->destName = $destName;
		$this->destHost = $destHost;
	}
}

class VmBeingClonedNoFolderEvent extends phpDynamicProperties {
	public $destName; //string
	public $destHost; //HostEventArgument

	function __construct($destName = null, $destHost = null) {
		$this->destName = $destName;
		$this->destHost = $destHost;
	}
}

class VmCloneFailedEvent extends phpDynamicProperties {
	public $destFolder; //FolderEventArgument
	public $destName; //string
	public $destHost; //HostEventArgument
	public $reason; //LocalizedMethodFault

	function __construct($destFolder = null, $destName = null, $destHost = null, $reason = null) {
		$this->destFolder = $destFolder;
		$this->destName = $destName;
		$this->destHost = $destHost;
		$this->reason = $reason;
	}
}

class VmClonedEvent extends phpDynamicProperties {
	public $sourceVm; //VmEventArgument

	function __construct($sourceVm = null) {
		$this->sourceVm = $sourceVm;
	}
}

class VmResourceReallocatedEvent extends phpDynamicProperties {
}

class VmRenamedEvent extends phpDynamicProperties {
	public $oldName; //string
	public $newName; //string

	function __construct($oldName = null, $newName = null) {
		$this->oldName = $oldName;
		$this->newName = $newName;
	}
}

class VmDateRolledBackEvent extends phpDynamicProperties {
}

class VmNoNetworkAccessEvent extends phpDynamicProperties {
	public $destHost; //HostEventArgument

	function __construct($destHost = null) {
		$this->destHost = $destHost;
	}
}

class VmDiskFailedEvent extends phpDynamicProperties {
	public $disk; //string
	public $reason; //LocalizedMethodFault

	function __construct($disk = null, $reason = null) {
		$this->disk = $disk;
		$this->reason = $reason;
	}
}

class VmFailedToPowerOnEvent extends phpDynamicProperties {
	public $reason; //LocalizedMethodFault

	function __construct($reason = null) {
		$this->reason = $reason;
	}
}

class VmFailedToPowerOffEvent extends phpDynamicProperties {
	public $reason; //LocalizedMethodFault

	function __construct($reason = null) {
		$this->reason = $reason;
	}
}

class VmFailedToSuspendEvent extends phpDynamicProperties {
	public $reason; //LocalizedMethodFault

	function __construct($reason = null) {
		$this->reason = $reason;
	}
}

class VmFailedToResetEvent extends phpDynamicProperties {
	public $reason; //LocalizedMethodFault

	function __construct($reason = null) {
		$this->reason = $reason;
	}
}

class VmFailedToShutdownGuestEvent extends phpDynamicProperties {
	public $reason; //LocalizedMethodFault

	function __construct($reason = null) {
		$this->reason = $reason;
	}
}

class VmFailedToRebootGuestEvent extends phpDynamicProperties {
	public $reason; //LocalizedMethodFault

	function __construct($reason = null) {
		$this->reason = $reason;
	}
}

class VmFailedToStandbyGuestEvent extends phpDynamicProperties {
	public $reason; //LocalizedMethodFault

	function __construct($reason = null) {
		$this->reason = $reason;
	}
}

class VmRemovedEvent extends phpDynamicProperties {
}

class VmGuestShutdownEvent extends phpDynamicProperties {
}

class VmGuestRebootEvent extends phpDynamicProperties {
}

class VmGuestStandbyEvent extends phpDynamicProperties {
}

class VmUpgradingEvent extends phpDynamicProperties {
	public $version; //string

	function __construct($version = null) {
		$this->version = $version;
	}
}

class VmUpgradeCompleteEvent extends phpDynamicProperties {
	public $version; //string

	function __construct($version = null) {
		$this->version = $version;
	}
}

class VmUpgradeFailedEvent extends phpDynamicProperties {
}

class VmRestartedOnAlternateHostEvent extends phpDynamicProperties {
	public $sourceHost; //HostEventArgument

	function __construct($sourceHost = null) {
		$this->sourceHost = $sourceHost;
	}
}

class VmReconfiguredEvent extends phpDynamicProperties {
	public $configSpec; //VirtualMachineConfigSpec

	function __construct($configSpec = null) {
		$this->configSpec = $configSpec;
	}
}

class VmMessageEvent extends phpDynamicProperties {
	public $message; //string
	public $messageInfo; //VirtualMachineMessage

	function __construct($message = null, $messageInfo = null) {
		$this->message = $message;
		$this->messageInfo = $messageInfo;
	}
}

class VmMessageWarningEvent extends phpDynamicProperties {
	public $message; //string
	public $messageInfo; //VirtualMachineMessage

	function __construct($message = null, $messageInfo = null) {
		$this->message = $message;
		$this->messageInfo = $messageInfo;
	}
}

class VmMessageErrorEvent extends phpDynamicProperties {
	public $message; //string
	public $messageInfo; //VirtualMachineMessage

	function __construct($message = null, $messageInfo = null) {
		$this->message = $message;
		$this->messageInfo = $messageInfo;
	}
}

class VmConfigMissingEvent extends phpDynamicProperties {
}

class VmPowerOffOnIsolationEvent extends phpDynamicProperties {
	public $isolatedHost; //HostEventArgument

	function __construct($isolatedHost = null) {
		$this->isolatedHost = $isolatedHost;
	}
}

class VmShutdownOnIsolationEvent extends phpDynamicProperties {
	public $isolatedHost; //HostEventArgument
	public $shutdownResult; //string

	function __construct($isolatedHost = null, $shutdownResult = null) {
		$this->isolatedHost = $isolatedHost;
		$this->shutdownResult = $shutdownResult;
	}
}

class VmFailoverFailed extends phpDynamicProperties {
	public $reason; //LocalizedMethodFault

	function __construct($reason = null) {
		$this->reason = $reason;
	}
}

class VmDasBeingResetEvent extends phpDynamicProperties {
	public $reason; //string

	function __construct($reason = null) {
		$this->reason = $reason;
	}
}

class VmDasResetFailedEvent extends phpDynamicProperties {
}

class VmMaxRestartCountReached extends phpDynamicProperties {
}

class VmMaxFTRestartCountReached extends phpDynamicProperties {
}

class VmDasBeingResetWithScreenshotEvent extends phpDynamicProperties {
	public $screenshotFilePath; //string

	function __construct($screenshotFilePath = null) {
		$this->screenshotFilePath = $screenshotFilePath;
	}
}

class NotEnoughResourcesToStartVmEvent extends phpDynamicProperties {
}

class VmUuidAssignedEvent extends phpDynamicProperties {
	public $uuid; //string

	function __construct($uuid = null) {
		$this->uuid = $uuid;
	}
}

class VmInstanceUuidAssignedEvent extends phpDynamicProperties {
	public $instanceUuid; //string

	function __construct($instanceUuid = null) {
		$this->instanceUuid = $instanceUuid;
	}
}

class VmUuidChangedEvent extends phpDynamicProperties {
	public $oldUuid; //string
	public $newUuid; //string

	function __construct($oldUuid = null, $newUuid = null) {
		$this->oldUuid = $oldUuid;
		$this->newUuid = $newUuid;
	}
}

class VmInstanceUuidChangedEvent extends phpDynamicProperties {
	public $oldInstanceUuid; //string
	public $newInstanceUuid; //string

	function __construct($oldInstanceUuid = null, $newInstanceUuid = null) {
		$this->oldInstanceUuid = $oldInstanceUuid;
		$this->newInstanceUuid = $newInstanceUuid;
	}
}

class VmWwnConflictEvent extends phpDynamicProperties {
	public $conflictedVms; //VmEventArgument
	public $conflictedHosts; //HostEventArgument
	public $wwn; //long

	function __construct($conflictedVms = null, $conflictedHosts = null, $wwn = null) {
		$this->conflictedVms = $conflictedVms;
		$this->conflictedHosts = $conflictedHosts;
		$this->wwn = $wwn;
	}
}

class VmAcquiredMksTicketEvent extends phpDynamicProperties {
}

class VmAcquiredTicketEvent extends phpDynamicProperties {
	public $ticketType; //string

	function __construct($ticketType = null) {
		$this->ticketType = $ticketType;
	}
}

class HostWwnConflictEvent extends phpDynamicProperties {
	public $conflictedVms; //VmEventArgument
	public $conflictedHosts; //HostEventArgument
	public $wwn; //long

	function __construct($conflictedVms = null, $conflictedHosts = null, $wwn = null) {
		$this->conflictedVms = $conflictedVms;
		$this->conflictedHosts = $conflictedHosts;
		$this->wwn = $wwn;
	}
}

class VmWwnAssignedEvent extends phpDynamicProperties {
	public $nodeWwns; //long
	public $portWwns; //long

	function __construct($nodeWwns = null, $portWwns = null) {
		$this->nodeWwns = $nodeWwns;
		$this->portWwns = $portWwns;
	}
}

class VmWwnChangedEvent extends phpDynamicProperties {
	public $oldNodeWwns; //long
	public $oldPortWwns; //long
	public $newNodeWwns; //long
	public $newPortWwns; //long

	function __construct($oldNodeWwns = null, $oldPortWwns = null, $newNodeWwns = null, $newPortWwns = null) {
		$this->oldNodeWwns = $oldNodeWwns;
		$this->oldPortWwns = $oldPortWwns;
		$this->newNodeWwns = $newNodeWwns;
		$this->newPortWwns = $newPortWwns;
	}
}

class VmSecondaryAddedEvent extends phpDynamicProperties {
}

class VmFaultToleranceTurnedOffEvent extends phpDynamicProperties {
}

class VmFaultToleranceStateChangedEvent extends phpDynamicProperties {
	public $oldState; //VirtualMachineFaultToleranceState
	public $newState; //VirtualMachineFaultToleranceState

	function __construct($oldState = null, $newState = null) {
		$this->oldState = $oldState;
		$this->newState = $newState;
	}
}

class VmSecondaryDisabledEvent extends phpDynamicProperties {
}

class VmSecondaryDisabledBySystemEvent extends phpDynamicProperties {
	public $reason; //LocalizedMethodFault

	function __construct($reason = null) {
		$this->reason = $reason;
	}
}

class VmSecondaryEnabledEvent extends phpDynamicProperties {
}

class VmStartingSecondaryEvent extends phpDynamicProperties {
}

class VmSecondaryStartedEvent extends phpDynamicProperties {
}

class VmFailedUpdatingSecondaryConfig extends phpDynamicProperties {
}

class VmFailedStartingSecondaryEvent extends phpDynamicProperties {
	public $reason; //string

	function __construct($reason = null) {
		$this->reason = $reason;
	}
}

class VmTimedoutStartingSecondaryEvent extends phpDynamicProperties {
	public $timeout; //long

	function __construct($timeout = null) {
		$this->timeout = $timeout;
	}
}

class VmNoCompatibleHostForSecondaryEvent extends phpDynamicProperties {
}

class VmPrimaryFailoverEvent extends phpDynamicProperties {
	public $reason; //string

	function __construct($reason = null) {
		$this->reason = $reason;
	}
}

class VmFaultToleranceVmTerminatedEvent extends phpDynamicProperties {
	public $reason; //string

	function __construct($reason = null) {
		$this->reason = $reason;
	}
}

class HostWwnChangedEvent extends phpDynamicProperties {
	public $oldNodeWwns; //long
	public $oldPortWwns; //long
	public $newNodeWwns; //long
	public $newPortWwns; //long

	function __construct($oldNodeWwns = null, $oldPortWwns = null, $newNodeWwns = null, $newPortWwns = null) {
		$this->oldNodeWwns = $oldNodeWwns;
		$this->oldPortWwns = $oldPortWwns;
		$this->newNodeWwns = $newNodeWwns;
		$this->newPortWwns = $newPortWwns;
	}
}

class HostAdminDisableEvent extends phpDynamicProperties {
}

class HostAdminEnableEvent extends phpDynamicProperties {
}

class HostEnableAdminFailedEvent extends phpDynamicProperties {
	public $permissions; //Permission

	function __construct($permissions = null) {
		$this->permissions = $permissions;
	}
}

class VmFailedRelayoutOnVmfs2DatastoreEvent extends phpDynamicProperties {
}

class VmFailedRelayoutEvent extends phpDynamicProperties {
	public $reason; //LocalizedMethodFault

	function __construct($reason = null) {
		$this->reason = $reason;
	}
}

class VmRelayoutSuccessfulEvent extends phpDynamicProperties {
}

class VmRelayoutUpToDateEvent extends phpDynamicProperties {
}

class VmConnectedEvent extends phpDynamicProperties {
}

class VmPoweringOnWithCustomizedDVPortEvent extends phpDynamicProperties {
	public $vnic; //VnicPortArgument

	function __construct($vnic = null) {
		$this->vnic = $vnic;
	}
}

class VmDasUpdateErrorEvent extends phpDynamicProperties {
}

class NoMaintenanceModeDrsRecommendationForVM extends phpDynamicProperties {
}

class VmDasUpdateOkEvent extends phpDynamicProperties {
}

class ScheduledTaskEvent extends phpDynamicProperties {
	public $scheduledTask; //ScheduledTaskEventArgument
	public $entity; //ManagedEntityEventArgument

	function __construct($scheduledTask = null, $entity = null) {
		$this->scheduledTask = $scheduledTask;
		$this->entity = $entity;
	}
}

class ScheduledTaskCreatedEvent extends phpDynamicProperties {
}

class ScheduledTaskStartedEvent extends phpDynamicProperties {
}

class ScheduledTaskRemovedEvent extends phpDynamicProperties {
}

class ScheduledTaskReconfiguredEvent extends phpDynamicProperties {
}

class ScheduledTaskCompletedEvent extends phpDynamicProperties {
}

class ScheduledTaskFailedEvent extends phpDynamicProperties {
	public $reason; //LocalizedMethodFault

	function __construct($reason = null) {
		$this->reason = $reason;
	}
}

class ScheduledTaskEmailCompletedEvent extends phpDynamicProperties {
	public $to; //string

	function __construct($to = null) {
		$this->to = $to;
	}
}

class ScheduledTaskEmailFailedEvent extends phpDynamicProperties {
	public $to; //string
	public $reason; //LocalizedMethodFault

	function __construct($to = null, $reason = null) {
		$this->to = $to;
		$this->reason = $reason;
	}
}

class AlarmEvent extends phpDynamicProperties {
	public $alarm; //AlarmEventArgument

	function __construct($alarm = null) {
		$this->alarm = $alarm;
	}
}

class AlarmCreatedEvent extends phpDynamicProperties {
	public $entity; //ManagedEntityEventArgument

	function __construct($entity = null) {
		$this->entity = $entity;
	}
}

class AlarmStatusChangedEvent extends phpDynamicProperties {
	public $source; //ManagedEntityEventArgument
	public $entity; //ManagedEntityEventArgument
	public $from; //string
	public $to; //string

	function __construct($source = null, $entity = null, $from = null, $to = null) {
		$this->source = $source;
		$this->entity = $entity;
		$this->from = $from;
		$this->to = $to;
	}
}

class AlarmActionTriggeredEvent extends phpDynamicProperties {
	public $source; //ManagedEntityEventArgument
	public $entity; //ManagedEntityEventArgument

	function __construct($source = null, $entity = null) {
		$this->source = $source;
		$this->entity = $entity;
	}
}

class AlarmEmailCompletedEvent extends phpDynamicProperties {
	public $entity; //ManagedEntityEventArgument
	public $to; //string

	function __construct($entity = null, $to = null) {
		$this->entity = $entity;
		$this->to = $to;
	}
}

class AlarmEmailFailedEvent extends phpDynamicProperties {
	public $entity; //ManagedEntityEventArgument
	public $to; //string
	public $reason; //LocalizedMethodFault

	function __construct($entity = null, $to = null, $reason = null) {
		$this->entity = $entity;
		$this->to = $to;
		$this->reason = $reason;
	}
}

class AlarmSnmpCompletedEvent extends phpDynamicProperties {
	public $entity; //ManagedEntityEventArgument

	function __construct($entity = null) {
		$this->entity = $entity;
	}
}

class AlarmSnmpFailedEvent extends phpDynamicProperties {
	public $entity; //ManagedEntityEventArgument
	public $reason; //LocalizedMethodFault

	function __construct($entity = null, $reason = null) {
		$this->entity = $entity;
		$this->reason = $reason;
	}
}

class AlarmScriptCompleteEvent extends phpDynamicProperties {
	public $entity; //ManagedEntityEventArgument
	public $script; //string

	function __construct($entity = null, $script = null) {
		$this->entity = $entity;
		$this->script = $script;
	}
}

class AlarmScriptFailedEvent extends phpDynamicProperties {
	public $entity; //ManagedEntityEventArgument
	public $script; //string
	public $reason; //LocalizedMethodFault

	function __construct($entity = null, $script = null, $reason = null) {
		$this->entity = $entity;
		$this->script = $script;
		$this->reason = $reason;
	}
}

class AlarmRemovedEvent extends phpDynamicProperties {
	public $entity; //ManagedEntityEventArgument

	function __construct($entity = null) {
		$this->entity = $entity;
	}
}

class AlarmReconfiguredEvent extends phpDynamicProperties {
	public $entity; //ManagedEntityEventArgument

	function __construct($entity = null) {
		$this->entity = $entity;
	}
}

class AlarmAcknowledgedEvent extends phpDynamicProperties {
	public $source; //ManagedEntityEventArgument
	public $entity; //ManagedEntityEventArgument

	function __construct($source = null, $entity = null) {
		$this->source = $source;
		$this->entity = $entity;
	}
}

class AlarmClearedEvent extends phpDynamicProperties {
	public $source; //ManagedEntityEventArgument
	public $entity; //ManagedEntityEventArgument
	public $from; //string

	function __construct($source = null, $entity = null, $from = null) {
		$this->source = $source;
		$this->entity = $entity;
		$this->from = $from;
	}
}

class CustomFieldEvent extends phpDynamicProperties {
}

class CustomFieldDefEvent extends phpDynamicProperties {
	public $fieldKey; //int
	public $name; //string

	function __construct($fieldKey = null, $name = null) {
		$this->fieldKey = $fieldKey;
		$this->name = $name;
	}
}

class CustomFieldDefAddedEvent extends phpDynamicProperties {
}

class CustomFieldDefRemovedEvent extends phpDynamicProperties {
}

class CustomFieldDefRenamedEvent extends phpDynamicProperties {
	public $newName; //string

	function __construct($newName = null) {
		$this->newName = $newName;
	}
}

class CustomFieldValueChangedEvent extends phpDynamicProperties {
	public $entity; //ManagedEntityEventArgument
	public $fieldKey; //int
	public $name; //string
	public $value; //string

	function __construct($entity = null, $fieldKey = null, $name = null, $value = null) {
		$this->entity = $entity;
		$this->fieldKey = $fieldKey;
		$this->name = $name;
		$this->value = $value;
	}
}

class AuthorizationEvent extends phpDynamicProperties {
}

class PermissionEvent extends phpDynamicProperties {
	public $entity; //ManagedEntityEventArgument
	public $principal; //string
	public $group; //boolean

	function __construct($entity = null, $principal = null, $group = null) {
		$this->entity = $entity;
		$this->principal = $principal;
		$this->group = $group;
	}
}

class PermissionAddedEvent extends phpDynamicProperties {
	public $role; //RoleEventArgument
	public $propagate; //boolean

	function __construct($role = null, $propagate = null) {
		$this->role = $role;
		$this->propagate = $propagate;
	}
}

class PermissionUpdatedEvent extends phpDynamicProperties {
	public $role; //RoleEventArgument
	public $propagate; //boolean

	function __construct($role = null, $propagate = null) {
		$this->role = $role;
		$this->propagate = $propagate;
	}
}

class PermissionRemovedEvent extends phpDynamicProperties {
}

class RoleEvent extends phpDynamicProperties {
	public $role; //RoleEventArgument

	function __construct($role = null) {
		$this->role = $role;
	}
}

class RoleAddedEvent extends phpDynamicProperties {
	public $privilegeList; //string

	function __construct($privilegeList = null) {
		$this->privilegeList = $privilegeList;
	}
}

class RoleUpdatedEvent extends phpDynamicProperties {
	public $privilegeList; //string

	function __construct($privilegeList = null) {
		$this->privilegeList = $privilegeList;
	}
}

class RoleRemovedEvent extends phpDynamicProperties {
}

class DatastoreEvent extends phpDynamicProperties {
	public $datastore; //DatastoreEventArgument

	function __construct($datastore = null) {
		$this->datastore = $datastore;
	}
}

class DatastoreDestroyedEvent extends phpDynamicProperties {
}

class DatastoreRenamedEvent extends phpDynamicProperties {
	public $oldName; //string
	public $newName; //string

	function __construct($oldName = null, $newName = null) {
		$this->oldName = $oldName;
		$this->newName = $newName;
	}
}

class DatastoreCapacityIncreasedEvent extends phpDynamicProperties {
	public $oldCapacity; //long
	public $newCapacity; //long

	function __construct($oldCapacity = null, $newCapacity = null) {
		$this->oldCapacity = $oldCapacity;
		$this->newCapacity = $newCapacity;
	}
}

class DatastoreDuplicatedEvent extends phpDynamicProperties {
}

class DatastoreFileEvent extends phpDynamicProperties {
	public $targetFile; //string

	function __construct($targetFile = null) {
		$this->targetFile = $targetFile;
	}
}

class DatastoreFileCopiedEvent extends phpDynamicProperties {
	public $sourceDatastore; //DatastoreEventArgument
	public $sourceFile; //string

	function __construct($sourceDatastore = null, $sourceFile = null) {
		$this->sourceDatastore = $sourceDatastore;
		$this->sourceFile = $sourceFile;
	}
}

class DatastoreFileMovedEvent extends phpDynamicProperties {
	public $sourceDatastore; //DatastoreEventArgument
	public $sourceFile; //string

	function __construct($sourceDatastore = null, $sourceFile = null) {
		$this->sourceDatastore = $sourceDatastore;
		$this->sourceFile = $sourceFile;
	}
}

class DatastoreFileDeletedEvent extends phpDynamicProperties {
}

class NonVIWorkloadDetectedOnDatastoreEvent extends phpDynamicProperties {
}

class DatastoreIORMReconfiguredEvent extends phpDynamicProperties {
}

class TaskEvent extends phpDynamicProperties {
	public $info; //TaskInfo

	function __construct($info = null) {
		$this->info = $info;
	}
}

class TaskTimeoutEvent extends phpDynamicProperties {
}

class LicenseEvent extends phpDynamicProperties {
}

class ServerLicenseExpiredEvent extends phpDynamicProperties {
	public $product; //string

	function __construct($product = null) {
		$this->product = $product;
	}
}

class HostLicenseExpiredEvent extends phpDynamicProperties {
}

class VMotionLicenseExpiredEvent extends phpDynamicProperties {
}

class NoLicenseEvent extends phpDynamicProperties {
	public $feature; //LicenseFeatureInfo

	function __construct($feature = null) {
		$this->feature = $feature;
	}
}

class LicenseServerUnavailableEvent extends phpDynamicProperties {
	public $licenseServer; //string

	function __construct($licenseServer = null) {
		$this->licenseServer = $licenseServer;
	}
}

class LicenseServerAvailableEvent extends phpDynamicProperties {
	public $licenseServer; //string

	function __construct($licenseServer = null) {
		$this->licenseServer = $licenseServer;
	}
}

class LicenseExpiredEvent extends phpDynamicProperties {
	public $feature; //LicenseFeatureInfo

	function __construct($feature = null) {
		$this->feature = $feature;
	}
}

class InvalidEditionEvent extends phpDynamicProperties {
	public $feature; //string

	function __construct($feature = null) {
		$this->feature = $feature;
	}
}

class HostInventoryFullEvent extends phpDynamicProperties {
	public $capacity; //int

	function __construct($capacity = null) {
		$this->capacity = $capacity;
	}
}

class LicenseRestrictedEvent extends phpDynamicProperties {
}

class IncorrectHostInformationEvent extends phpDynamicProperties {
}

class UnlicensedVirtualMachinesEvent extends phpDynamicProperties {
	public $unlicensed; //int
	public $available; //int

	function __construct($unlicensed = null, $available = null) {
		$this->unlicensed = $unlicensed;
		$this->available = $available;
	}
}

class UnlicensedVirtualMachinesFoundEvent extends phpDynamicProperties {
	public $available; //int

	function __construct($available = null) {
		$this->available = $available;
	}
}

class AllVirtualMachinesLicensedEvent extends phpDynamicProperties {
}

class LicenseNonComplianceEvent extends phpDynamicProperties {
	public $url; //string

	function __construct($url = null) {
		$this->url = $url;
	}
}

class MigrationEvent extends phpDynamicProperties {
	public $fault; //LocalizedMethodFault

	function __construct($fault = null) {
		$this->fault = $fault;
	}
}

class MigrationWarningEvent extends phpDynamicProperties {
}

class MigrationErrorEvent extends phpDynamicProperties {
}

class MigrationHostWarningEvent extends phpDynamicProperties {
	public $dstHost; //HostEventArgument

	function __construct($dstHost = null) {
		$this->dstHost = $dstHost;
	}
}

class MigrationHostErrorEvent extends phpDynamicProperties {
	public $dstHost; //HostEventArgument

	function __construct($dstHost = null) {
		$this->dstHost = $dstHost;
	}
}

class MigrationResourceWarningEvent extends phpDynamicProperties {
	public $dstPool; //ResourcePoolEventArgument
	public $dstHost; //HostEventArgument

	function __construct($dstPool = null, $dstHost = null) {
		$this->dstPool = $dstPool;
		$this->dstHost = $dstHost;
	}
}

class MigrationResourceErrorEvent extends phpDynamicProperties {
	public $dstPool; //ResourcePoolEventArgument
	public $dstHost; //HostEventArgument

	function __construct($dstPool = null, $dstHost = null) {
		$this->dstPool = $dstPool;
		$this->dstHost = $dstHost;
	}
}

class ClusterEvent extends phpDynamicProperties {
}

class DasEnabledEvent extends phpDynamicProperties {
}

class DasDisabledEvent extends phpDynamicProperties {
}

class DasAdmissionControlDisabledEvent extends phpDynamicProperties {
}

class DasAdmissionControlEnabledEvent extends phpDynamicProperties {
}

class DasHostFailedEvent extends phpDynamicProperties {
	public $failedHost; //HostEventArgument

	function __construct($failedHost = null) {
		$this->failedHost = $failedHost;
	}
}

class DasHostIsolatedEvent extends phpDynamicProperties {
	public $isolatedHost; //HostEventArgument

	function __construct($isolatedHost = null) {
		$this->isolatedHost = $isolatedHost;
	}
}

class DasClusterIsolatedEvent extends phpDynamicProperties {
}

class DasAgentUnavailableEvent extends phpDynamicProperties {
}

class DasAgentFoundEvent extends phpDynamicProperties {
}

class InsufficientFailoverResourcesEvent extends phpDynamicProperties {
}

class FailoverLevelRestored extends phpDynamicProperties {
}

class ClusterOvercommittedEvent extends phpDynamicProperties {
}

class HostOvercommittedEvent extends phpDynamicProperties {
}

class ClusterStatusChangedEvent extends phpDynamicProperties {
	public $oldStatus; //string
	public $newStatus; //string

	function __construct($oldStatus = null, $newStatus = null) {
		$this->oldStatus = $oldStatus;
		$this->newStatus = $newStatus;
	}
}

class HostStatusChangedEvent extends phpDynamicProperties {
}

class ClusterCreatedEvent extends phpDynamicProperties {
	public $parent; //FolderEventArgument

	function __construct($parent = null) {
		$this->parent = $parent;
	}
}

class ClusterDestroyedEvent extends phpDynamicProperties {
}

class DrsEnabledEvent extends phpDynamicProperties {
	public $behavior; //string

	function __construct($behavior = null) {
		$this->behavior = $behavior;
	}
}

class DrsDisabledEvent extends phpDynamicProperties {
}

class ClusterReconfiguredEvent extends phpDynamicProperties {
}

class HostMonitoringStateChangedEvent extends phpDynamicProperties {
	public $state; //string

	function __construct($state = null) {
		$this->state = $state;
	}
}

class VmHealthMonitoringStateChangedEvent extends phpDynamicProperties {
	public $state; //string

	function __construct($state = null) {
		$this->state = $state;
	}
}

class ResourcePoolEvent extends phpDynamicProperties {
	public $resourcePool; //ResourcePoolEventArgument

	function __construct($resourcePool = null) {
		$this->resourcePool = $resourcePool;
	}
}

class ResourcePoolCreatedEvent extends phpDynamicProperties {
	public $parent; //ResourcePoolEventArgument

	function __construct($parent = null) {
		$this->parent = $parent;
	}
}

class ResourcePoolDestroyedEvent extends phpDynamicProperties {
}

class ResourcePoolMovedEvent extends phpDynamicProperties {
	public $oldParent; //ResourcePoolEventArgument
	public $newParent; //ResourcePoolEventArgument

	function __construct($oldParent = null, $newParent = null) {
		$this->oldParent = $oldParent;
		$this->newParent = $newParent;
	}
}

class ResourcePoolReconfiguredEvent extends phpDynamicProperties {
}

class ResourceViolatedEvent extends phpDynamicProperties {
}

class VmResourcePoolMovedEvent extends phpDynamicProperties {
	public $oldParent; //ResourcePoolEventArgument
	public $newParent; //ResourcePoolEventArgument

	function __construct($oldParent = null, $newParent = null) {
		$this->oldParent = $oldParent;
		$this->newParent = $newParent;
	}
}

class TemplateUpgradeEvent extends phpDynamicProperties {
	public $legacyTemplate; //string

	function __construct($legacyTemplate = null) {
		$this->legacyTemplate = $legacyTemplate;
	}
}

class TemplateBeingUpgradedEvent extends phpDynamicProperties {
}

class TemplateUpgradeFailedEvent extends phpDynamicProperties {
	public $reason; //LocalizedMethodFault

	function __construct($reason = null) {
		$this->reason = $reason;
	}
}

class TemplateUpgradedEvent extends phpDynamicProperties {
}

class CustomizationEvent extends phpDynamicProperties {
	public $logLocation; //string

	function __construct($logLocation = null) {
		$this->logLocation = $logLocation;
	}
}

class CustomizationStartedEvent extends phpDynamicProperties {
}

class CustomizationSucceeded extends phpDynamicProperties {
}

class CustomizationFailed extends phpDynamicProperties {
}

class CustomizationUnknownFailure extends phpDynamicProperties {
}

class CustomizationSysprepFailed extends phpDynamicProperties {
	public $sysprepVersion; //string
	public $systemVersion; //string

	function __construct($sysprepVersion = null, $systemVersion = null) {
		$this->sysprepVersion = $sysprepVersion;
		$this->systemVersion = $systemVersion;
	}
}

class CustomizationLinuxIdentityFailed extends phpDynamicProperties {
}

class CustomizationNetworkSetupFailed extends phpDynamicProperties {
}

class LockerMisconfiguredEvent extends phpDynamicProperties {
	public $datastore; //DatastoreEventArgument

	function __construct($datastore = null) {
		$this->datastore = $datastore;
	}
}

class LockerReconfiguredEvent extends phpDynamicProperties {
	public $oldDatastore; //DatastoreEventArgument
	public $newDatastore; //DatastoreEventArgument

	function __construct($oldDatastore = null, $newDatastore = null) {
		$this->oldDatastore = $oldDatastore;
		$this->newDatastore = $newDatastore;
	}
}

class NoDatastoresConfiguredEvent extends phpDynamicProperties {
}

class AdminPasswordNotChangedEvent extends phpDynamicProperties {
}

class HostInAuditModeEvent extends phpDynamicProperties {
}

class LocalTSMEnabledEvent extends phpDynamicProperties {
}

class RemoteTSMEnabledEvent extends phpDynamicProperties {
}

class VimAccountPasswordChangedEvent extends phpDynamicProperties {
}

class IScsiBootFailureEvent extends phpDynamicProperties {
}

class DvsEvent extends phpDynamicProperties {
}

class DvsCreatedEvent extends phpDynamicProperties {
	public $parent; //FolderEventArgument

	function __construct($parent = null) {
		$this->parent = $parent;
	}
}

class DvsRenamedEvent extends phpDynamicProperties {
	public $oldName; //string
	public $newName; //string

	function __construct($oldName = null, $newName = null) {
		$this->oldName = $oldName;
		$this->newName = $newName;
	}
}

class DvsReconfiguredEvent extends phpDynamicProperties {
	public $configSpec; //DVSConfigSpec

	function __construct($configSpec = null) {
		$this->configSpec = $configSpec;
	}
}

class DvsUpgradeAvailableEvent extends phpDynamicProperties {
	public $productInfo; //DistributedVirtualSwitchProductSpec

	function __construct($productInfo = null) {
		$this->productInfo = $productInfo;
	}
}

class DvsUpgradeInProgressEvent extends phpDynamicProperties {
	public $productInfo; //DistributedVirtualSwitchProductSpec

	function __construct($productInfo = null) {
		$this->productInfo = $productInfo;
	}
}

class DvsUpgradeRejectedEvent extends phpDynamicProperties {
	public $productInfo; //DistributedVirtualSwitchProductSpec

	function __construct($productInfo = null) {
		$this->productInfo = $productInfo;
	}
}

class DvsUpgradedEvent extends phpDynamicProperties {
	public $productInfo; //DistributedVirtualSwitchProductSpec

	function __construct($productInfo = null) {
		$this->productInfo = $productInfo;
	}
}

class DvsHostJoinedEvent extends phpDynamicProperties {
	public $hostJoined; //HostEventArgument

	function __construct($hostJoined = null) {
		$this->hostJoined = $hostJoined;
	}
}

class DvsHostLeftEvent extends phpDynamicProperties {
	public $hostLeft; //HostEventArgument

	function __construct($hostLeft = null) {
		$this->hostLeft = $hostLeft;
	}
}

class DvsOutOfSyncHostArgument extends phpDynamicProperties {
	public $outOfSyncHost; //HostEventArgument
	public $configParamters; //string

	function __construct($outOfSyncHost = null, $configParamters = null) {
		$this->outOfSyncHost = $outOfSyncHost;
		$this->configParamters = $configParamters;
	}
}

class ArrayOfDvsOutOfSyncHostArgument extends phpDynamicProperties {
	public $DvsOutOfSyncHostArgument; //DvsOutOfSyncHostArgument

	function __construct($DvsOutOfSyncHostArgument = null) {
		$this->DvsOutOfSyncHostArgument = $DvsOutOfSyncHostArgument;
	}
}

class OutOfSyncDvsHost extends phpDynamicProperties {
	public $hostOutOfSync; //DvsOutOfSyncHostArgument

	function __construct($hostOutOfSync = null) {
		$this->hostOutOfSync = $hostOutOfSync;
	}
}

class DvsHostWentOutOfSyncEvent extends phpDynamicProperties {
	public $hostOutOfSync; //DvsOutOfSyncHostArgument

	function __construct($hostOutOfSync = null) {
		$this->hostOutOfSync = $hostOutOfSync;
	}
}

class DvsHostBackInSyncEvent extends phpDynamicProperties {
	public $hostBackInSync; //HostEventArgument

	function __construct($hostBackInSync = null) {
		$this->hostBackInSync = $hostBackInSync;
	}
}

class DvsHostStatusUpdated extends phpDynamicProperties {
	public $hostMember; //HostEventArgument
	public $oldStatus; //string
	public $newStatus; //string
	public $oldStatusDetail; //string
	public $newStatusDetail; //string

	function __construct($hostMember = null, $oldStatus = null, $newStatus = null, $oldStatusDetail = null, $newStatusDetail = null) {
		$this->hostMember = $hostMember;
		$this->oldStatus = $oldStatus;
		$this->newStatus = $newStatus;
		$this->oldStatusDetail = $oldStatusDetail;
		$this->newStatusDetail = $newStatusDetail;
	}
}

class DvsPortCreatedEvent extends phpDynamicProperties {
	public $portKey; //string

	function __construct($portKey = null) {
		$this->portKey = $portKey;
	}
}

class DvsPortReconfiguredEvent extends phpDynamicProperties {
	public $portKey; //string

	function __construct($portKey = null) {
		$this->portKey = $portKey;
	}
}

class DvsPortDeletedEvent extends phpDynamicProperties {
	public $portKey; //string

	function __construct($portKey = null) {
		$this->portKey = $portKey;
	}
}

class DvsPortConnectedEvent extends phpDynamicProperties {
	public $portKey; //string
	public $connectee; //DistributedVirtualSwitchPortConnectee

	function __construct($portKey = null, $connectee = null) {
		$this->portKey = $portKey;
		$this->connectee = $connectee;
	}
}

class DvsPortDisconnectedEvent extends phpDynamicProperties {
	public $portKey; //string
	public $connectee; //DistributedVirtualSwitchPortConnectee

	function __construct($portKey = null, $connectee = null) {
		$this->portKey = $portKey;
		$this->connectee = $connectee;
	}
}

class DvsPortLinkUpEvent extends phpDynamicProperties {
	public $portKey; //string

	function __construct($portKey = null) {
		$this->portKey = $portKey;
	}
}

class DvsPortLinkDownEvent extends phpDynamicProperties {
	public $portKey; //string

	function __construct($portKey = null) {
		$this->portKey = $portKey;
	}
}

class DvsPortJoinPortgroupEvent extends phpDynamicProperties {
	public $portKey; //string
	public $portgroupKey; //string
	public $portgroupName; //string

	function __construct($portKey = null, $portgroupKey = null, $portgroupName = null) {
		$this->portKey = $portKey;
		$this->portgroupKey = $portgroupKey;
		$this->portgroupName = $portgroupName;
	}
}

class DvsPortLeavePortgroupEvent extends phpDynamicProperties {
	public $portKey; //string
	public $portgroupKey; //string
	public $portgroupName; //string

	function __construct($portKey = null, $portgroupKey = null, $portgroupName = null) {
		$this->portKey = $portKey;
		$this->portgroupKey = $portgroupKey;
		$this->portgroupName = $portgroupName;
	}
}

class DvsPortBlockedEvent extends phpDynamicProperties {
	public $portKey; //string
	public $statusDetail; //string

	function __construct($portKey = null, $statusDetail = null) {
		$this->portKey = $portKey;
		$this->statusDetail = $statusDetail;
	}
}

class DvsPortUnblockedEvent extends phpDynamicProperties {
	public $portKey; //string

	function __construct($portKey = null) {
		$this->portKey = $portKey;
	}
}

class DvsPortEnteredPassthruEvent extends phpDynamicProperties {
	public $portKey; //string

	function __construct($portKey = null) {
		$this->portKey = $portKey;
	}
}

class DvsPortExitedPassthruEvent extends phpDynamicProperties {
	public $portKey; //string

	function __construct($portKey = null) {
		$this->portKey = $portKey;
	}
}

class DvsDestroyedEvent extends phpDynamicProperties {
}

class DvsMergedEvent extends phpDynamicProperties {
	public $sourceDvs; //DvsEventArgument
	public $destinationDvs; //DvsEventArgument

	function __construct($sourceDvs = null, $destinationDvs = null) {
		$this->sourceDvs = $sourceDvs;
		$this->destinationDvs = $destinationDvs;
	}
}

class DVPortgroupEvent extends phpDynamicProperties {
}

class DVPortgroupCreatedEvent extends phpDynamicProperties {
}

class DVPortgroupRenamedEvent extends phpDynamicProperties {
	public $oldName; //string
	public $newName; //string

	function __construct($oldName = null, $newName = null) {
		$this->oldName = $oldName;
		$this->newName = $newName;
	}
}

class DVPortgroupReconfiguredEvent extends phpDynamicProperties {
	public $configSpec; //DVPortgroupConfigSpec

	function __construct($configSpec = null) {
		$this->configSpec = $configSpec;
	}
}

class DVPortgroupDestroyedEvent extends phpDynamicProperties {
}

class DrsInvocationFailedEvent extends phpDynamicProperties {
}

class DrsRecoveredFromFailureEvent extends phpDynamicProperties {
}

class VmReloadFromPathEvent extends phpDynamicProperties {
	public $configPath; //string

	function __construct($configPath = null) {
		$this->configPath = $configPath;
	}
}

class VmReloadFromPathFailedEvent extends phpDynamicProperties {
	public $configPath; //string

	function __construct($configPath = null) {
		$this->configPath = $configPath;
	}
}

class EventArgument extends phpDynamicProperties {
}

class RoleEventArgument extends phpDynamicProperties {
	public $roleId; //int
	public $name; //string

	function __construct($roleId = null, $name = null) {
		$this->roleId = $roleId;
		$this->name = $name;
	}
}

class EntityEventArgument extends phpDynamicProperties {
	public $name; //string

	function __construct($name = null) {
		$this->name = $name;
	}
}

class ManagedEntityEventArgument extends phpDynamicProperties {
	public $entity; //ManagedObjectReference

	function __construct($entity = null) {
		$this->entity = $entity;
	}
}

class FolderEventArgument extends phpDynamicProperties {
	public $folder; //ManagedObjectReference

	function __construct($folder = null) {
		$this->folder = $folder;
	}
}

class DatacenterEventArgument extends phpDynamicProperties {
	public $datacenter; //ManagedObjectReference

	function __construct($datacenter = null) {
		$this->datacenter = $datacenter;
	}
}

class ComputeResourceEventArgument extends phpDynamicProperties {
	public $computeResource; //ManagedObjectReference

	function __construct($computeResource = null) {
		$this->computeResource = $computeResource;
	}
}

class ResourcePoolEventArgument extends phpDynamicProperties {
	public $resourcePool; //ManagedObjectReference

	function __construct($resourcePool = null) {
		$this->resourcePool = $resourcePool;
	}
}

class HostEventArgument extends phpDynamicProperties {
	public $host; //ManagedObjectReference

	function __construct($host = null) {
		$this->host = $host;
	}
}

class ArrayOfHostEventArgument extends phpDynamicProperties {
	public $HostEventArgument; //HostEventArgument

	function __construct($HostEventArgument = null) {
		$this->HostEventArgument = $HostEventArgument;
	}
}

class VmEventArgument extends phpDynamicProperties {
	public $vm; //ManagedObjectReference

	function __construct($vm = null) {
		$this->vm = $vm;
	}
}

class ArrayOfVmEventArgument extends phpDynamicProperties {
	public $VmEventArgument; //VmEventArgument

	function __construct($VmEventArgument = null) {
		$this->VmEventArgument = $VmEventArgument;
	}
}

class DatastoreEventArgument extends phpDynamicProperties {
	public $datastore; //ManagedObjectReference

	function __construct($datastore = null) {
		$this->datastore = $datastore;
	}
}

class NetworkEventArgument extends phpDynamicProperties {
	public $network; //ManagedObjectReference

	function __construct($network = null) {
		$this->network = $network;
	}
}

class AlarmEventArgument extends phpDynamicProperties {
	public $alarm; //ManagedObjectReference

	function __construct($alarm = null) {
		$this->alarm = $alarm;
	}
}

class ScheduledTaskEventArgument extends phpDynamicProperties {
	public $scheduledTask; //ManagedObjectReference

	function __construct($scheduledTask = null) {
		$this->scheduledTask = $scheduledTask;
	}
}

class ProfileEventArgument extends phpDynamicProperties {
	public $profile; //ManagedObjectReference
	public $name; //string

	function __construct($profile = null, $name = null) {
		$this->profile = $profile;
		$this->name = $name;
	}
}

class DvsEventArgument extends phpDynamicProperties {
	public $dvs; //ManagedObjectReference

	function __construct($dvs = null) {
		$this->dvs = $dvs;
	}
}

class EventArgDesc extends phpDynamicProperties {
	public $name; //string
	public $type; //string
	public $description; //ElementDescription

	function __construct($name = null, $type = null, $description = null) {
		$this->name = $name;
		$this->type = $type;
		$this->description = $description;
	}
}

class ArrayOfEventArgDesc extends phpDynamicProperties {
	public $EventArgDesc; //EventArgDesc

	function __construct($EventArgDesc = null) {
		$this->EventArgDesc = $EventArgDesc;
	}
}

class EventDescriptionEventDetail extends phpDynamicProperties {
	public $key; //string
	public $description; //string
	public $category; //string
	public $formatOnDatacenter; //string
	public $formatOnComputeResource; //string
	public $formatOnHost; //string
	public $formatOnVm; //string
	public $fullFormat; //string
	public $longDescription; //string

	function __construct($key = null, $description = null, $category = null, $formatOnDatacenter = null, $formatOnComputeResource = null, $formatOnHost = null, $formatOnVm = null, $fullFormat = null, $longDescription = null) {
		$this->key = $key;
		$this->description = $description;
		$this->category = $category;
		$this->formatOnDatacenter = $formatOnDatacenter;
		$this->formatOnComputeResource = $formatOnComputeResource;
		$this->formatOnHost = $formatOnHost;
		$this->formatOnVm = $formatOnVm;
		$this->fullFormat = $fullFormat;
		$this->longDescription = $longDescription;
	}
}

class ArrayOfEventDescriptionEventDetail extends phpDynamicProperties {
	public $EventDescriptionEventDetail; //EventDescriptionEventDetail

	function __construct($EventDescriptionEventDetail = null) {
		$this->EventDescriptionEventDetail = $EventDescriptionEventDetail;
	}
}

class EventDescription extends phpDynamicProperties {
	public $category; //ElementDescription
	public $eventInfo; //EventDescriptionEventDetail
	public $enumeratedTypes; //EnumDescription

	function __construct($category = null, $eventInfo = null, $enumeratedTypes = null) {
		$this->category = $category;
		$this->eventInfo = $eventInfo;
		$this->enumeratedTypes = $enumeratedTypes;
	}
}

class EventEx extends phpDynamicProperties {
	public $eventTypeId; //string
	public $severity; //string
	public $message; //string
	public $arguments; //KeyAnyValue
	public $objectId; //string
	public $objectType; //string
	public $objectName; //string
	public $fault; //LocalizedMethodFault

	function __construct($eventTypeId = null, $severity = null, $message = null, $arguments = null, $objectId = null, $objectType = null, $objectName = null, $fault = null) {
		$this->eventTypeId = $eventTypeId;
		$this->severity = $severity;
		$this->message = $message;
		$this->arguments = $arguments;
		$this->objectId = $objectId;
		$this->objectType = $objectType;
		$this->objectName = $objectName;
		$this->fault = $fault;
	}
}

class EventFilterSpecByEntity extends phpDynamicProperties {
	public $entity; //ManagedObjectReference
	public $recursion; //EventFilterSpecRecursionOption

	function __construct($entity = null, $recursion = null) {
		$this->entity = $entity;
		$this->recursion = $recursion;
	}
}

class EventFilterSpecByTime extends phpDynamicProperties {
	public $beginTime; //dateTime
	public $endTime; //dateTime

	function __construct($beginTime = null, $endTime = null) {
		$this->beginTime = $beginTime;
		$this->endTime = $endTime;
	}
}

class EventFilterSpecByUsername extends phpDynamicProperties {
	public $systemUser; //boolean
	public $userList; //string

	function __construct($systemUser = null, $userList = null) {
		$this->systemUser = $systemUser;
		$this->userList = $userList;
	}
}

class EventFilterSpec extends phpDynamicProperties {
	public $entity; //EventFilterSpecByEntity
	public $time; //EventFilterSpecByTime
	public $userName; //EventFilterSpecByUsername
	public $eventChainId; //int
	public $alarm; //ManagedObjectReference
	public $scheduledTask; //ManagedObjectReference
	public $disableFullMessage; //boolean
	public $category; //string
	public $type; //string
	public $tag; //string
	public $eventTypeId; //string

	function __construct($entity = null, $time = null, $userName = null, $eventChainId = null, $alarm = null, $scheduledTask = null, $disableFullMessage = null, $category = null, $type = null, $tag = null, $eventTypeId = null) {
		$this->entity = $entity;
		$this->time = $time;
		$this->userName = $userName;
		$this->eventChainId = $eventChainId;
		$this->alarm = $alarm;
		$this->scheduledTask = $scheduledTask;
		$this->disableFullMessage = $disableFullMessage;
		$this->category = $category;
		$this->type = $type;
		$this->tag = $tag;
		$this->eventTypeId = $eventTypeId;
	}
}

class ExtExtendedProductInfo extends phpDynamicProperties {
	public $companyUrl; //string
	public $productUrl; //string
	public $managementUrl; //string
	public $self; //ManagedObjectReference

	function __construct($companyUrl = null, $productUrl = null, $managementUrl = null, $self = null) {
		$this->companyUrl = $companyUrl;
		$this->productUrl = $productUrl;
		$this->managementUrl = $managementUrl;
		$this->self = $self;
	}
}

class ManagedByInfo extends phpDynamicProperties {
	public $extensionKey; //string
	public $type; //string

	function __construct($extensionKey = null, $type = null) {
		$this->extensionKey = $extensionKey;
		$this->type = $type;
	}
}

class ExtManagedEntityInfo extends phpDynamicProperties {
	public $type; //string
	public $smallIconUrl; //string
	public $description; //string

	function __construct($type = null, $smallIconUrl = null, $description = null) {
		$this->type = $type;
		$this->smallIconUrl = $smallIconUrl;
		$this->description = $description;
	}
}

class ArrayOfExtManagedEntityInfo extends phpDynamicProperties {
	public $ExtManagedEntityInfo; //ExtManagedEntityInfo

	function __construct($ExtManagedEntityInfo = null) {
		$this->ExtManagedEntityInfo = $ExtManagedEntityInfo;
	}
}

class ExtSolutionManagerInfoTabInfo extends phpDynamicProperties {
	public $label; //string
	public $url; //string

	function __construct($label = null, $url = null) {
		$this->label = $label;
		$this->url = $url;
	}
}

class ArrayOfExtSolutionManagerInfoTabInfo extends phpDynamicProperties {
	public $ExtSolutionManagerInfoTabInfo; //ExtSolutionManagerInfoTabInfo

	function __construct($ExtSolutionManagerInfoTabInfo = null) {
		$this->ExtSolutionManagerInfoTabInfo = $ExtSolutionManagerInfoTabInfo;
	}
}

class ExtSolutionManagerInfo extends phpDynamicProperties {
	public $tab; //ExtSolutionManagerInfoTabInfo
	public $smallIconUrl; //string

	function __construct($tab = null, $smallIconUrl = null) {
		$this->tab = $tab;
		$this->smallIconUrl = $smallIconUrl;
	}
}

class ActiveDirectoryFault extends phpDynamicProperties {
	public $errorCode; //int

	function __construct($errorCode = null) {
		$this->errorCode = $errorCode;
	}
}

class AdminDisabled extends phpDynamicProperties {
}

class AdminNotDisabled extends phpDynamicProperties {
}

class AffinityConfigured extends phpDynamicProperties {
	public $configuredAffinity; //string

	function __construct($configuredAffinity = null) {
		$this->configuredAffinity = $configuredAffinity;
	}
}

class AgentInstallFailed extends phpDynamicProperties {
	public $reason; //string
	public $statusCode; //int
	public $installerOutput; //string

	function __construct($reason = null, $statusCode = null, $installerOutput = null) {
		$this->reason = $reason;
		$this->statusCode = $statusCode;
		$this->installerOutput = $installerOutput;
	}
}

class AlreadyBeingManaged extends phpDynamicProperties {
	public $ipAddress; //string

	function __construct($ipAddress = null) {
		$this->ipAddress = $ipAddress;
	}
}

class AlreadyConnected extends phpDynamicProperties {
	public $name; //string

	function __construct($name = null) {
		$this->name = $name;
	}
}

class AlreadyExists extends phpDynamicProperties {
	public $name; //string

	function __construct($name = null) {
		$this->name = $name;
	}
}

class AlreadyUpgraded extends phpDynamicProperties {
}

class AnswerFileUpdateFailure extends phpDynamicProperties {
	public $userInputPath; //ProfilePropertyPath
	public $errMsg; //LocalizableMessage

	function __construct($userInputPath = null, $errMsg = null) {
		$this->userInputPath = $userInputPath;
		$this->errMsg = $errMsg;
	}
}

class ArrayOfAnswerFileUpdateFailure extends phpDynamicProperties {
	public $AnswerFileUpdateFailure; //AnswerFileUpdateFailure

	function __construct($AnswerFileUpdateFailure = null) {
		$this->AnswerFileUpdateFailure = $AnswerFileUpdateFailure;
	}
}

class AnswerFileUpdateFailed extends phpDynamicProperties {
	public $failure; //AnswerFileUpdateFailure

	function __construct($failure = null) {
		$this->failure = $failure;
	}
}

class ApplicationQuiesceFault extends phpDynamicProperties {
}

class AuthMinimumAdminPermission extends phpDynamicProperties {
}

class BlockedByFirewall extends phpDynamicProperties {
}

class CAMServerRefusedConnection extends phpDynamicProperties {
}

class CannotAccessFile extends phpDynamicProperties {
}

class CannotAccessLocalSource extends phpDynamicProperties {
}

class CannotAccessNetwork extends phpDynamicProperties {
}

class CannotAccessVmComponent extends phpDynamicProperties {
}

class CannotAccessVmConfig extends phpDynamicProperties {
	public $reason; //LocalizedMethodFault

	function __construct($reason = null) {
		$this->reason = $reason;
	}
}

class CannotAccessVmDevice extends phpDynamicProperties {
	public $device; //string
	public $backing; //string
	public $connected; //boolean

	function __construct($device = null, $backing = null, $connected = null) {
		$this->device = $device;
		$this->backing = $backing;
		$this->connected = $connected;
	}
}

class CannotAccessVmDisk extends phpDynamicProperties {
	public $fault; //LocalizedMethodFault

	function __construct($fault = null) {
		$this->fault = $fault;
	}
}

class CannotAddHostWithFTVmAsStandalone extends phpDynamicProperties {
}

class CannotAddHostWithFTVmToDifferentCluster extends phpDynamicProperties {
}

class CannotAddHostWithFTVmToNonHACluster extends phpDynamicProperties {
}

class CannotChangeDrsBehaviorForFtSecondary extends phpDynamicProperties {
	public $vm; //ManagedObjectReference
	public $vmName; //string

	function __construct($vm = null, $vmName = null) {
		$this->vm = $vm;
		$this->vmName = $vmName;
	}
}

class CannotChangeHaSettingsForFtSecondary extends phpDynamicProperties {
	public $vm; //ManagedObjectReference
	public $vmName; //string

	function __construct($vm = null, $vmName = null) {
		$this->vm = $vm;
		$this->vmName = $vmName;
	}
}

class CannotCreateFile extends phpDynamicProperties {
}

class CannotDecryptPasswords extends phpDynamicProperties {
}

class CannotDeleteFile extends phpDynamicProperties {
}

class CannotDisableDrsOnClustersWithVApps extends phpDynamicProperties {
}

class CannotDisableSnapshot extends phpDynamicProperties {
}

class CannotDisconnectHostWithFaultToleranceVm extends phpDynamicProperties {
	public $hostName; //string

	function __construct($hostName = null) {
		$this->hostName = $hostName;
	}
}

class CannotModifyConfigCpuRequirements extends phpDynamicProperties {
}

class CannotMoveFaultToleranceVm extends phpDynamicProperties {
	public $moveType; //string
	public $vmName; //string

	function __construct($moveType = null, $vmName = null) {
		$this->moveType = $moveType;
		$this->vmName = $vmName;
	}
}

class CannotMoveHostWithFaultToleranceVm extends phpDynamicProperties {
}

class CannotMoveVmWithDeltaDisk extends phpDynamicProperties {
	public $device; //string

	function __construct($device = null) {
		$this->device = $device;
	}
}

class CannotMoveVmWithNativeDeltaDisk extends phpDynamicProperties {
}

class CannotPowerOffVmInCluster extends phpDynamicProperties {
	public $operation; //string
	public $vm; //ManagedObjectReference
	public $vmName; //string

	function __construct($operation = null, $vm = null, $vmName = null) {
		$this->operation = $operation;
		$this->vm = $vm;
		$this->vmName = $vmName;
	}
}

class ClockSkew extends phpDynamicProperties {
}

class CloneFromSnapshotNotSupported extends phpDynamicProperties {
}

class ConcurrentAccess extends phpDynamicProperties {
}

class ConnectedIso extends phpDynamicProperties {
	public $cdrom; //VirtualCdrom
	public $filename; //string

	function __construct($cdrom = null, $filename = null) {
		$this->cdrom = $cdrom;
		$this->filename = $filename;
	}
}

class CpuCompatibilityUnknown extends phpDynamicProperties {
}

class CpuHotPlugNotSupported extends phpDynamicProperties {
}

class CpuIncompatible extends phpDynamicProperties {
	public $level; //int
	public $registerName; //string
	public $registerBits; //string
	public $desiredBits; //string
	public $host; //ManagedObjectReference

	function __construct($level = null, $registerName = null, $registerBits = null, $desiredBits = null, $host = null) {
		$this->level = $level;
		$this->registerName = $registerName;
		$this->registerBits = $registerBits;
		$this->desiredBits = $desiredBits;
		$this->host = $host;
	}
}

class CpuIncompatible1ECX extends phpDynamicProperties {
	public $sse3; //boolean
	public $pclmulqdq; //boolean
	public $ssse3; //boolean
	public $sse41; //boolean
	public $sse42; //boolean
	public $aes; //boolean
	public $other; //boolean
	public $otherOnly; //boolean

	function __construct($sse3 = null, $pclmulqdq = null, $ssse3 = null, $sse41 = null, $sse42 = null, $aes = null, $other = null, $otherOnly = null) {
		$this->sse3 = $sse3;
		$this->pclmulqdq = $pclmulqdq;
		$this->ssse3 = $ssse3;
		$this->sse41 = $sse41;
		$this->sse42 = $sse42;
		$this->aes = $aes;
		$this->other = $other;
		$this->otherOnly = $otherOnly;
	}
}

class CpuIncompatible81EDX extends phpDynamicProperties {
	public $nx; //boolean
	public $ffxsr; //boolean
	public $rdtscp; //boolean
	public $lm; //boolean
	public $other; //boolean
	public $otherOnly; //boolean

	function __construct($nx = null, $ffxsr = null, $rdtscp = null, $lm = null, $other = null, $otherOnly = null) {
		$this->nx = $nx;
		$this->ffxsr = $ffxsr;
		$this->rdtscp = $rdtscp;
		$this->lm = $lm;
		$this->other = $other;
		$this->otherOnly = $otherOnly;
	}
}

class CustomizationFault extends phpDynamicProperties {
}

class CustomizationPending extends phpDynamicProperties {
}

class DVPortNotSupported extends phpDynamicProperties {
}

class DasConfigFault extends phpDynamicProperties {
	public $reason; //string
	public $output; //string
	public $event; //Event

	function __construct($reason = null, $output = null, $event = null) {
		$this->reason = $reason;
		$this->output = $output;
		$this->event = $event;
	}
}

class DatabaseError extends phpDynamicProperties {
}

class DatacenterMismatchArgument extends phpDynamicProperties {
	public $entity; //ManagedObjectReference
	public $inputDatacenter; //ManagedObjectReference

	function __construct($entity = null, $inputDatacenter = null) {
		$this->entity = $entity;
		$this->inputDatacenter = $inputDatacenter;
	}
}

class ArrayOfDatacenterMismatchArgument extends phpDynamicProperties {
	public $DatacenterMismatchArgument; //DatacenterMismatchArgument

	function __construct($DatacenterMismatchArgument = null) {
		$this->DatacenterMismatchArgument = $DatacenterMismatchArgument;
	}
}

class DatacenterMismatch extends phpDynamicProperties {
	public $invalidArgument; //DatacenterMismatchArgument
	public $expectedDatacenter; //ManagedObjectReference

	function __construct($invalidArgument = null, $expectedDatacenter = null) {
		$this->invalidArgument = $invalidArgument;
		$this->expectedDatacenter = $expectedDatacenter;
	}
}

class DatastoreNotWritableOnHost extends phpDynamicProperties {
	public $host; //ManagedObjectReference

	function __construct($host = null) {
		$this->host = $host;
	}
}

class DeltaDiskFormatNotSupported extends phpDynamicProperties {
	public $datastore; //ManagedObjectReference
	public $deltaDiskFormat; //string

	function __construct($datastore = null, $deltaDiskFormat = null) {
		$this->datastore = $datastore;
		$this->deltaDiskFormat = $deltaDiskFormat;
	}
}

class DestinationSwitchFull extends phpDynamicProperties {
}

class DeviceBackingNotSupported extends phpDynamicProperties {
	public $backing; //string

	function __construct($backing = null) {
		$this->backing = $backing;
	}
}

class DeviceControllerNotSupported extends phpDynamicProperties {
	public $controller; //string

	function __construct($controller = null) {
		$this->controller = $controller;
	}
}

class DeviceHotPlugNotSupported extends phpDynamicProperties {
}

class DeviceNotFound extends phpDynamicProperties {
}

class DeviceNotSupported extends phpDynamicProperties {
	public $device; //string
	public $reason; //string

	function __construct($device = null, $reason = null) {
		$this->device = $device;
		$this->reason = $reason;
	}
}

class DeviceUnsupportedForVmPlatform extends phpDynamicProperties {
}

class DeviceUnsupportedForVmVersion extends phpDynamicProperties {
	public $currentVersion; //string
	public $expectedVersion; //string

	function __construct($currentVersion = null, $expectedVersion = null) {
		$this->currentVersion = $currentVersion;
		$this->expectedVersion = $expectedVersion;
	}
}

class DirectoryNotEmpty extends phpDynamicProperties {
}

class DisableAdminNotSupported extends phpDynamicProperties {
}

class DisallowedChangeByService extends phpDynamicProperties {
	public $serviceName; //string
	public $disallowedChange; //string

	function __construct($serviceName = null, $disallowedChange = null) {
		$this->serviceName = $serviceName;
		$this->disallowedChange = $disallowedChange;
	}
}

class DisallowedDiskModeChange extends phpDynamicProperties {
}

class DisallowedMigrationDeviceAttached extends phpDynamicProperties {
	public $fault; //LocalizedMethodFault

	function __construct($fault = null) {
		$this->fault = $fault;
	}
}

class DisallowedOperationOnFailoverHost extends phpDynamicProperties {
	public $host; //ManagedObjectReference
	public $hostname; //string

	function __construct($host = null, $hostname = null) {
		$this->host = $host;
		$this->hostname = $hostname;
	}
}

class DiskMoveTypeNotSupported extends phpDynamicProperties {
}

class DiskNotSupported extends phpDynamicProperties {
	public $disk; //int

	function __construct($disk = null) {
		$this->disk = $disk;
	}
}

class DomainNotFound extends phpDynamicProperties {
	public $domainName; //string

	function __construct($domainName = null) {
		$this->domainName = $domainName;
	}
}

class DrsDisabledOnVm extends phpDynamicProperties {
}

class DrsVmotionIncompatibleFault extends phpDynamicProperties {
	public $host; //ManagedObjectReference

	function __construct($host = null) {
		$this->host = $host;
	}
}

class DuplicateName extends phpDynamicProperties {
	public $name; //string
	public $object; //ManagedObjectReference

	function __construct($name = null, $object = null) {
		$this->name = $name;
		$this->object = $object;
	}
}

class DvsFault extends phpDynamicProperties {
}

class DvsNotAuthorized extends phpDynamicProperties {
	public $sessionExtensionKey; //string
	public $dvsExtensionKey; //string

	function __construct($sessionExtensionKey = null, $dvsExtensionKey = null) {
		$this->sessionExtensionKey = $sessionExtensionKey;
		$this->dvsExtensionKey = $dvsExtensionKey;
	}
}

class DvsOperationBulkFaultFaultOnHost extends phpDynamicProperties {
	public $host; //ManagedObjectReference
	public $fault; //LocalizedMethodFault

	function __construct($host = null, $fault = null) {
		$this->host = $host;
		$this->fault = $fault;
	}
}

class ArrayOfDvsOperationBulkFaultFaultOnHost extends phpDynamicProperties {
	public $DvsOperationBulkFaultFaultOnHost; //DvsOperationBulkFaultFaultOnHost

	function __construct($DvsOperationBulkFaultFaultOnHost = null) {
		$this->DvsOperationBulkFaultFaultOnHost = $DvsOperationBulkFaultFaultOnHost;
	}
}

class DvsOperationBulkFault extends phpDynamicProperties {
	public $hostFault; //DvsOperationBulkFaultFaultOnHost

	function __construct($hostFault = null) {
		$this->hostFault = $hostFault;
	}
}

class DvsScopeViolated extends phpDynamicProperties {
	public $scope; //ManagedObjectReference
	public $entity; //ManagedObjectReference

	function __construct($scope = null, $entity = null) {
		$this->scope = $scope;
		$this->entity = $entity;
	}
}

class EVCAdmissionFailed extends phpDynamicProperties {
}

class EVCAdmissionFailedCPUFeaturesForMode extends phpDynamicProperties {
	public $currentEVCModeKey; //string

	function __construct($currentEVCModeKey = null) {
		$this->currentEVCModeKey = $currentEVCModeKey;
	}
}

class EVCAdmissionFailedCPUModel extends phpDynamicProperties {
}

class EVCAdmissionFailedCPUModelForMode extends phpDynamicProperties {
	public $currentEVCModeKey; //string

	function __construct($currentEVCModeKey = null) {
		$this->currentEVCModeKey = $currentEVCModeKey;
	}
}

class EVCAdmissionFailedCPUVendor extends phpDynamicProperties {
	public $clusterCPUVendor; //string
	public $hostCPUVendor; //string

	function __construct($clusterCPUVendor = null, $hostCPUVendor = null) {
		$this->clusterCPUVendor = $clusterCPUVendor;
		$this->hostCPUVendor = $hostCPUVendor;
	}
}

class EVCAdmissionFailedCPUVendorUnknown extends phpDynamicProperties {
}

class EVCAdmissionFailedHostDisconnected extends phpDynamicProperties {
}

class EVCAdmissionFailedHostSoftware extends phpDynamicProperties {
}

class EVCAdmissionFailedHostSoftwareForMode extends phpDynamicProperties {
}

class EVCAdmissionFailedVmActive extends phpDynamicProperties {
}

class EightHostLimitViolated extends phpDynamicProperties {
}

class ExpiredAddonLicense extends phpDynamicProperties {
}

class ExpiredEditionLicense extends phpDynamicProperties {
}

class ExpiredFeatureLicense extends phpDynamicProperties {
	public $feature; //string
	public $count; //int
	public $expirationDate; //dateTime

	function __construct($feature = null, $count = null, $expirationDate = null) {
		$this->feature = $feature;
		$this->count = $count;
		$this->expirationDate = $expirationDate;
	}
}

class ExtendedFault extends phpDynamicProperties {
	public $faultTypeId; //string
	public $data; //KeyValue

	function __construct($faultTypeId = null, $data = null) {
		$this->faultTypeId = $faultTypeId;
		$this->data = $data;
	}
}

class FailToEnableSPBM extends phpDynamicProperties {
	public $cs; //ManagedObjectReference
	public $csName; //string
	public $hostLicenseStates; //ComputeResourceHostSPBMLicenseInfo

	function __construct($cs = null, $csName = null, $hostLicenseStates = null) {
		$this->cs = $cs;
		$this->csName = $csName;
		$this->hostLicenseStates = $hostLicenseStates;
	}
}

class FailToLockFaultToleranceVMs extends phpDynamicProperties {
	public $vmName; //string
	public $vm; //ManagedObjectReference
	public $alreadyLockedVm; //ManagedObjectReference

	function __construct($vmName = null, $vm = null, $alreadyLockedVm = null) {
		$this->vmName = $vmName;
		$this->vm = $vm;
		$this->alreadyLockedVm = $alreadyLockedVm;
	}
}

class FaultToleranceAntiAffinityViolated extends phpDynamicProperties {
	public $hostName; //string
	public $host; //ManagedObjectReference

	function __construct($hostName = null, $host = null) {
		$this->hostName = $hostName;
		$this->host = $host;
	}
}

class FaultToleranceCannotEditMem extends phpDynamicProperties {
	public $vmName; //string
	public $vm; //ManagedObjectReference

	function __construct($vmName = null, $vm = null) {
		$this->vmName = $vmName;
		$this->vm = $vm;
	}
}

class FaultToleranceCpuIncompatible extends phpDynamicProperties {
	public $model; //boolean
	public $family; //boolean
	public $stepping; //boolean

	function __construct($model = null, $family = null, $stepping = null) {
		$this->model = $model;
		$this->family = $family;
		$this->stepping = $stepping;
	}
}

class FaultToleranceNeedsThickDisk extends phpDynamicProperties {
	public $vmName; //string

	function __construct($vmName = null) {
		$this->vmName = $vmName;
	}
}

class FaultToleranceNotLicensed extends phpDynamicProperties {
	public $hostName; //string

	function __construct($hostName = null) {
		$this->hostName = $hostName;
	}
}

class FaultToleranceNotSameBuild extends phpDynamicProperties {
	public $build; //string

	function __construct($build = null) {
		$this->build = $build;
	}
}

class FaultTolerancePrimaryPowerOnNotAttempted extends phpDynamicProperties {
	public $secondaryVm; //ManagedObjectReference
	public $primaryVm; //ManagedObjectReference

	function __construct($secondaryVm = null, $primaryVm = null) {
		$this->secondaryVm = $secondaryVm;
		$this->primaryVm = $primaryVm;
	}
}

class FaultToleranceVmNotDasProtected extends phpDynamicProperties {
	public $vm; //ManagedObjectReference
	public $vmName; //string

	function __construct($vm = null, $vmName = null) {
		$this->vm = $vm;
		$this->vmName = $vmName;
	}
}

class FcoeFault extends phpDynamicProperties {
}

class FcoeFaultPnicHasNoPortSet extends phpDynamicProperties {
	public $nicDevice; //string

	function __construct($nicDevice = null) {
		$this->nicDevice = $nicDevice;
	}
}

class FileAlreadyExists extends phpDynamicProperties {
}

class FileBackedPortNotSupported extends phpDynamicProperties {
}

class FileFault extends phpDynamicProperties {
	public $file; //string

	function __construct($file = null) {
		$this->file = $file;
	}
}

class FileLocked extends phpDynamicProperties {
}

class FileNameTooLong extends phpDynamicProperties {
}

class FileNotFound extends phpDynamicProperties {
}

class FileNotWritable extends phpDynamicProperties {
}

class FileTooLarge extends phpDynamicProperties {
	public $datastore; //string
	public $fileSize; //long
	public $maxFileSize; //long

	function __construct($datastore = null, $fileSize = null, $maxFileSize = null) {
		$this->datastore = $datastore;
		$this->fileSize = $fileSize;
		$this->maxFileSize = $maxFileSize;
	}
}

class FilesystemQuiesceFault extends phpDynamicProperties {
}

class FtIssuesOnHost extends phpDynamicProperties {
	public $host; //ManagedObjectReference
	public $hostName; //string
	public $errors; //LocalizedMethodFault

	function __construct($host = null, $hostName = null, $errors = null) {
		$this->host = $host;
		$this->hostName = $hostName;
		$this->errors = $errors;
	}
}

class FullStorageVMotionNotSupported extends phpDynamicProperties {
}

class GenericDrsFault extends phpDynamicProperties {
	public $hostFaults; //LocalizedMethodFault

	function __construct($hostFaults = null) {
		$this->hostFaults = $hostFaults;
	}
}

class GenericVmConfigFault extends phpDynamicProperties {
	public $reason; //string

	function __construct($reason = null) {
		$this->reason = $reason;
	}
}

class GuestAuthenticationChallenge extends phpDynamicProperties {
	public $serverChallenge; //GuestAuthentication
	public $sessionID; //long

	function __construct($serverChallenge = null, $sessionID = null) {
		$this->serverChallenge = $serverChallenge;
		$this->sessionID = $sessionID;
	}
}

class GuestComponentsOutOfDate extends phpDynamicProperties {
}

class GuestOperationsFault extends phpDynamicProperties {
}

class GuestOperationsUnavailable extends phpDynamicProperties {
}

class GuestPermissionDenied extends phpDynamicProperties {
}

class GuestProcessNotFound extends phpDynamicProperties {
	public $pid; //long

	function __construct($pid = null) {
		$this->pid = $pid;
	}
}

class HAErrorsAtDest extends phpDynamicProperties {
}

class HostAccessRestrictedToManagementServer extends phpDynamicProperties {
	public $managementServer; //string

	function __construct($managementServer = null) {
		$this->managementServer = $managementServer;
	}
}

class HostConfigFailed extends phpDynamicProperties {
	public $failure; //LocalizedMethodFault

	function __construct($failure = null) {
		$this->failure = $failure;
	}
}

class HostConfigFault extends phpDynamicProperties {
}

class HostConnectFault extends phpDynamicProperties {
}

class HostInDomain extends phpDynamicProperties {
}

class HostIncompatibleForFaultTolerance extends phpDynamicProperties {
	public $hostName; //string
	public $reason; //string

	function __construct($hostName = null, $reason = null) {
		$this->hostName = $hostName;
		$this->reason = $reason;
	}
}

class HostIncompatibleForRecordReplay extends phpDynamicProperties {
	public $hostName; //string
	public $reason; //string

	function __construct($hostName = null, $reason = null) {
		$this->hostName = $hostName;
		$this->reason = $reason;
	}
}

class HostInventoryFull extends phpDynamicProperties {
	public $capacity; //int

	function __construct($capacity = null) {
		$this->capacity = $capacity;
	}
}

class HostPowerOpFailed extends phpDynamicProperties {
}

class HotSnapshotMoveNotSupported extends phpDynamicProperties {
}

class IDEDiskNotSupported extends phpDynamicProperties {
}

class IORMNotSupportedHostOnDatastore extends phpDynamicProperties {
	public $datastore; //ManagedObjectReference
	public $datastoreName; //string
	public $host; //ManagedObjectReference

	function __construct($datastore = null, $datastoreName = null, $host = null) {
		$this->datastore = $datastore;
		$this->datastoreName = $datastoreName;
		$this->host = $host;
	}
}

class InUseFeatureManipulationDisallowed extends phpDynamicProperties {
}

class InaccessibleDatastore extends phpDynamicProperties {
	public $detail; //string

	function __construct($detail = null) {
		$this->detail = $detail;
	}
}

class IncompatibleDefaultDevice extends phpDynamicProperties {
	public $device; //string

	function __construct($device = null) {
		$this->device = $device;
	}
}

class IncompatibleHostForFtSecondary extends phpDynamicProperties {
	public $host; //ManagedObjectReference
	public $error; //LocalizedMethodFault

	function __construct($host = null, $error = null) {
		$this->host = $host;
		$this->error = $error;
	}
}

class IncompatibleSetting extends phpDynamicProperties {
	public $conflictingProperty; //string

	function __construct($conflictingProperty = null) {
		$this->conflictingProperty = $conflictingProperty;
	}
}

class IncorrectFileType extends phpDynamicProperties {
}

class IncorrectHostInformation extends phpDynamicProperties {
}

class IndependentDiskVMotionNotSupported extends phpDynamicProperties {
}

class InsufficientAgentVmsDeployed extends phpDynamicProperties {
	public $hostName; //string
	public $requiredNumAgentVms; //int
	public $currentNumAgentVms; //int

	function __construct($hostName = null, $requiredNumAgentVms = null, $currentNumAgentVms = null) {
		$this->hostName = $hostName;
		$this->requiredNumAgentVms = $requiredNumAgentVms;
		$this->currentNumAgentVms = $currentNumAgentVms;
	}
}

class InsufficientCpuResourcesFault extends phpDynamicProperties {
	public $unreserved; //long
	public $requested; //long

	function __construct($unreserved = null, $requested = null) {
		$this->unreserved = $unreserved;
		$this->requested = $requested;
	}
}

class InsufficientFailoverResourcesFault extends phpDynamicProperties {
}

class InsufficientHostCapacityFault extends phpDynamicProperties {
	public $host; //ManagedObjectReference

	function __construct($host = null) {
		$this->host = $host;
	}
}

class InsufficientHostCpuCapacityFault extends phpDynamicProperties {
	public $unreserved; //long
	public $requested; //long

	function __construct($unreserved = null, $requested = null) {
		$this->unreserved = $unreserved;
		$this->requested = $requested;
	}
}

class InsufficientHostMemoryCapacityFault extends phpDynamicProperties {
	public $unreserved; //long
	public $requested; //long

	function __construct($unreserved = null, $requested = null) {
		$this->unreserved = $unreserved;
		$this->requested = $requested;
	}
}

class InsufficientMemoryResourcesFault extends phpDynamicProperties {
	public $unreserved; //long
	public $requested; //long

	function __construct($unreserved = null, $requested = null) {
		$this->unreserved = $unreserved;
		$this->requested = $requested;
	}
}

class InsufficientPerCpuCapacity extends phpDynamicProperties {
}

class InsufficientResourcesFault extends phpDynamicProperties {
}

class InsufficientStandbyCpuResource extends phpDynamicProperties {
	public $available; //long
	public $requested; //long

	function __construct($available = null, $requested = null) {
		$this->available = $available;
		$this->requested = $requested;
	}
}

class InsufficientStandbyMemoryResource extends phpDynamicProperties {
	public $available; //long
	public $requested; //long

	function __construct($available = null, $requested = null) {
		$this->available = $available;
		$this->requested = $requested;
	}
}

class InsufficientStandbyResource extends phpDynamicProperties {
}

class InsufficientStorageSpace extends phpDynamicProperties {
}

class InvalidAffinitySettingFault extends phpDynamicProperties {
}

class InvalidBmcRole extends phpDynamicProperties {
}

class InvalidBundle extends phpDynamicProperties {
}

class InvalidCAMCertificate extends phpDynamicProperties {
}

class InvalidCAMServer extends phpDynamicProperties {
	public $camServer; //string

	function __construct($camServer = null) {
		$this->camServer = $camServer;
	}
}

class InvalidClientCertificate extends phpDynamicProperties {
}

class InvalidController extends phpDynamicProperties {
	public $controllerKey; //int

	function __construct($controllerKey = null) {
		$this->controllerKey = $controllerKey;
	}
}

class InvalidDasRestartPriorityForFtVm extends phpDynamicProperties {
	public $vm; //ManagedObjectReference
	public $vmName; //string

	function __construct($vm = null, $vmName = null) {
		$this->vm = $vm;
		$this->vmName = $vmName;
	}
}

class InvalidDatastore extends phpDynamicProperties {
	public $datastore; //ManagedObjectReference
	public $name; //string

	function __construct($datastore = null, $name = null) {
		$this->datastore = $datastore;
		$this->name = $name;
	}
}

class InvalidDatastorePath extends phpDynamicProperties {
	public $datastorePath; //string

	function __construct($datastorePath = null) {
		$this->datastorePath = $datastorePath;
	}
}

class InvalidDatastoreState extends phpDynamicProperties {
	public $datastoreName; //string

	function __construct($datastoreName = null) {
		$this->datastoreName = $datastoreName;
	}
}

class InvalidDeviceBacking extends phpDynamicProperties {
}

class InvalidDeviceOperation extends phpDynamicProperties {
	public $badOp; //VirtualDeviceConfigSpecOperation
	public $badFileOp; //VirtualDeviceConfigSpecFileOperation

	function __construct($badOp = null, $badFileOp = null) {
		$this->badOp = $badOp;
		$this->badFileOp = $badFileOp;
	}
}

class InvalidDeviceSpec extends phpDynamicProperties {
	public $deviceIndex; //int

	function __construct($deviceIndex = null) {
		$this->deviceIndex = $deviceIndex;
	}
}

class InvalidDiskFormat extends phpDynamicProperties {
}

class InvalidDrsBehaviorForFtVm extends phpDynamicProperties {
	public $vm; //ManagedObjectReference
	public $vmName; //string

	function __construct($vm = null, $vmName = null) {
		$this->vm = $vm;
		$this->vmName = $vmName;
	}
}

class InvalidEditionLicense extends phpDynamicProperties {
	public $feature; //string

	function __construct($feature = null) {
		$this->feature = $feature;
	}
}

class InvalidEvent extends phpDynamicProperties {
}

class InvalidFolder extends phpDynamicProperties {
	public $target; //ManagedObjectReference

	function __construct($target = null) {
		$this->target = $target;
	}
}

class InvalidFormat extends phpDynamicProperties {
}

class InvalidGuestLogin extends phpDynamicProperties {
}

class InvalidHostName extends phpDynamicProperties {
}

class InvalidHostState extends phpDynamicProperties {
	public $host; //ManagedObjectReference

	function __construct($host = null) {
		$this->host = $host;
	}
}

class InvalidIndexArgument extends phpDynamicProperties {
	public $key; //string

	function __construct($key = null) {
		$this->key = $key;
	}
}

class InvalidIpmiLoginInfo extends phpDynamicProperties {
}

class InvalidIpmiMacAddress extends phpDynamicProperties {
	public $userProvidedMacAddress; //string
	public $observedMacAddress; //string

	function __construct($userProvidedMacAddress = null, $observedMacAddress = null) {
		$this->userProvidedMacAddress = $userProvidedMacAddress;
		$this->observedMacAddress = $observedMacAddress;
	}
}

class InvalidLicense extends phpDynamicProperties {
	public $licenseContent; //string

	function __construct($licenseContent = null) {
		$this->licenseContent = $licenseContent;
	}
}

class InvalidLocale extends phpDynamicProperties {
}

class InvalidLogin extends phpDynamicProperties {
}

class InvalidName extends phpDynamicProperties {
	public $name; //string
	public $entity; //ManagedObjectReference

	function __construct($name = null, $entity = null) {
		$this->name = $name;
		$this->entity = $entity;
	}
}

class InvalidNasCredentials extends phpDynamicProperties {
	public $userName; //string

	function __construct($userName = null) {
		$this->userName = $userName;
	}
}

class InvalidNetworkInType extends phpDynamicProperties {
}

class InvalidNetworkResource extends phpDynamicProperties {
	public $remoteHost; //string
	public $remotePath; //string

	function __construct($remoteHost = null, $remotePath = null) {
		$this->remoteHost = $remoteHost;
		$this->remotePath = $remotePath;
	}
}

class InvalidOperationOnSecondaryVm extends phpDynamicProperties {
	public $instanceUuid; //string

	function __construct($instanceUuid = null) {
		$this->instanceUuid = $instanceUuid;
	}
}

class InvalidPowerState extends phpDynamicProperties {
	public $requestedState; //VirtualMachinePowerState
	public $existingState; //VirtualMachinePowerState

	function __construct($requestedState = null, $existingState = null) {
		$this->requestedState = $requestedState;
		$this->existingState = $existingState;
	}
}

class InvalidPrivilege extends phpDynamicProperties {
	public $privilege; //string

	function __construct($privilege = null) {
		$this->privilege = $privilege;
	}
}

class InvalidProfileReferenceHost extends phpDynamicProperties {
	public $reason; //string
	public $host; //ManagedObjectReference
	public $profile; //ManagedObjectReference

	function __construct($reason = null, $host = null, $profile = null) {
		$this->reason = $reason;
		$this->host = $host;
		$this->profile = $profile;
	}
}

class InvalidPropertyType extends phpDynamicProperties {
}

class InvalidPropertyValue extends phpDynamicProperties {
}

class InvalidResourcePoolStructureFault extends phpDynamicProperties {
}

class InvalidSnapshotFormat extends phpDynamicProperties {
}

class InvalidState extends phpDynamicProperties {
}

class InvalidVmConfig extends phpDynamicProperties {
	public $property; //string

	function __construct($property = null) {
		$this->property = $property;
	}
}

class InventoryHasStandardAloneHosts extends phpDynamicProperties {
	public $hosts; //string

	function __construct($hosts = null) {
		$this->hosts = $hosts;
	}
}

class IpHostnameGeneratorError extends phpDynamicProperties {
}

class IscsiFault extends phpDynamicProperties {
}

class IscsiFaultInvalidVnic extends phpDynamicProperties {
	public $vnicDevice; //string

	function __construct($vnicDevice = null) {
		$this->vnicDevice = $vnicDevice;
	}
}

class IscsiFaultPnicInUse extends phpDynamicProperties {
	public $pnicDevice; //string

	function __construct($pnicDevice = null) {
		$this->pnicDevice = $pnicDevice;
	}
}

class IscsiFaultVnicAlreadyBound extends phpDynamicProperties {
	public $vnicDevice; //string

	function __construct($vnicDevice = null) {
		$this->vnicDevice = $vnicDevice;
	}
}

class IscsiFaultVnicHasActivePaths extends phpDynamicProperties {
	public $vnicDevice; //string

	function __construct($vnicDevice = null) {
		$this->vnicDevice = $vnicDevice;
	}
}

class IscsiFaultVnicHasMultipleUplinks extends phpDynamicProperties {
	public $vnicDevice; //string

	function __construct($vnicDevice = null) {
		$this->vnicDevice = $vnicDevice;
	}
}

class IscsiFaultVnicHasNoUplinks extends phpDynamicProperties {
	public $vnicDevice; //string

	function __construct($vnicDevice = null) {
		$this->vnicDevice = $vnicDevice;
	}
}

class IscsiFaultVnicHasWrongUplink extends phpDynamicProperties {
	public $vnicDevice; //string

	function __construct($vnicDevice = null) {
		$this->vnicDevice = $vnicDevice;
	}
}

class IscsiFaultVnicInUse extends phpDynamicProperties {
	public $vnicDevice; //string

	function __construct($vnicDevice = null) {
		$this->vnicDevice = $vnicDevice;
	}
}

class IscsiFaultVnicIsLastPath extends phpDynamicProperties {
	public $vnicDevice; //string

	function __construct($vnicDevice = null) {
		$this->vnicDevice = $vnicDevice;
	}
}

class IscsiFaultVnicNotBound extends phpDynamicProperties {
	public $vnicDevice; //string

	function __construct($vnicDevice = null) {
		$this->vnicDevice = $vnicDevice;
	}
}

class IscsiFaultVnicNotFound extends phpDynamicProperties {
	public $vnicDevice; //string

	function __construct($vnicDevice = null) {
		$this->vnicDevice = $vnicDevice;
	}
}

class LargeRDMConversionNotSupported extends phpDynamicProperties {
	public $device; //string

	function __construct($device = null) {
		$this->device = $device;
	}
}

class LargeRDMNotSupportedOnDatastore extends phpDynamicProperties {
	public $device; //string
	public $datastore; //ManagedObjectReference
	public $datastoreName; //string

	function __construct($device = null, $datastore = null, $datastoreName = null) {
		$this->device = $device;
		$this->datastore = $datastore;
		$this->datastoreName = $datastoreName;
	}
}

class LegacyNetworkInterfaceInUse extends phpDynamicProperties {
}

class LicenseAssignmentFailed extends phpDynamicProperties {
	public $reason; //string

	function __construct($reason = null) {
		$this->reason = $reason;
	}
}

class LicenseDowngradeDisallowed extends phpDynamicProperties {
	public $edition; //string
	public $entityId; //string
	public $features; //KeyAnyValue

	function __construct($edition = null, $entityId = null, $features = null) {
		$this->edition = $edition;
		$this->entityId = $entityId;
		$this->features = $features;
	}
}

class LicenseEntityNotFound extends phpDynamicProperties {
	public $entityId; //string

	function __construct($entityId = null) {
		$this->entityId = $entityId;
	}
}

class LicenseExpired extends phpDynamicProperties {
	public $licenseKey; //string

	function __construct($licenseKey = null) {
		$this->licenseKey = $licenseKey;
	}
}

class LicenseKeyEntityMismatch extends phpDynamicProperties {
}

class LicenseRestricted extends phpDynamicProperties {
}

class LicenseServerUnavailable extends phpDynamicProperties {
	public $licenseServer; //string

	function __construct($licenseServer = null) {
		$this->licenseServer = $licenseServer;
	}
}

class LicenseSourceUnavailable extends phpDynamicProperties {
	public $licenseSource; //LicenseSource

	function __construct($licenseSource = null) {
		$this->licenseSource = $licenseSource;
	}
}

class LimitExceeded extends phpDynamicProperties {
	public $property; //string
	public $limit; //int

	function __construct($property = null, $limit = null) {
		$this->property = $property;
		$this->limit = $limit;
	}
}

class LinuxVolumeNotClean extends phpDynamicProperties {
}

class LogBundlingFailed extends phpDynamicProperties {
}

class MaintenanceModeFileMove extends phpDynamicProperties {
}

class MemoryHotPlugNotSupported extends phpDynamicProperties {
}

class MemorySizeNotRecommended extends phpDynamicProperties {
	public $memorySizeMB; //int
	public $minMemorySizeMB; //int
	public $maxMemorySizeMB; //int

	function __construct($memorySizeMB = null, $minMemorySizeMB = null, $maxMemorySizeMB = null) {
		$this->memorySizeMB = $memorySizeMB;
		$this->minMemorySizeMB = $minMemorySizeMB;
		$this->maxMemorySizeMB = $maxMemorySizeMB;
	}
}

class MemorySizeNotSupported extends phpDynamicProperties {
	public $memorySizeMB; //int
	public $minMemorySizeMB; //int
	public $maxMemorySizeMB; //int

	function __construct($memorySizeMB = null, $minMemorySizeMB = null, $maxMemorySizeMB = null) {
		$this->memorySizeMB = $memorySizeMB;
		$this->minMemorySizeMB = $minMemorySizeMB;
		$this->maxMemorySizeMB = $maxMemorySizeMB;
	}
}

class MemorySizeNotSupportedByDatastore extends phpDynamicProperties {
	public $datastore; //ManagedObjectReference
	public $memorySizeMB; //int
	public $maxMemorySizeMB; //int

	function __construct($datastore = null, $memorySizeMB = null, $maxMemorySizeMB = null) {
		$this->datastore = $datastore;
		$this->memorySizeMB = $memorySizeMB;
		$this->maxMemorySizeMB = $maxMemorySizeMB;
	}
}

class MemorySnapshotOnIndependentDisk extends phpDynamicProperties {
}

class MethodAlreadyDisabledFault extends phpDynamicProperties {
	public $sourceId; //string

	function __construct($sourceId = null) {
		$this->sourceId = $sourceId;
	}
}

class MethodDisabled extends phpDynamicProperties {
	public $source; //string

	function __construct($source = null) {
		$this->source = $source;
	}
}

class MigrationDisabled extends phpDynamicProperties {
}

class MigrationFault extends phpDynamicProperties {
}

class MigrationFeatureNotSupported extends phpDynamicProperties {
	public $atSourceHost; //boolean
	public $failedHostName; //string
	public $failedHost; //ManagedObjectReference

	function __construct($atSourceHost = null, $failedHostName = null, $failedHost = null) {
		$this->atSourceHost = $atSourceHost;
		$this->failedHostName = $failedHostName;
		$this->failedHost = $failedHost;
	}
}

class MigrationNotReady extends phpDynamicProperties {
	public $reason; //string

	function __construct($reason = null) {
		$this->reason = $reason;
	}
}

class MismatchedBundle extends phpDynamicProperties {
	public $bundleUuid; //string
	public $hostUuid; //string
	public $bundleBuildNumber; //int
	public $hostBuildNumber; //int

	function __construct($bundleUuid = null, $hostUuid = null, $bundleBuildNumber = null, $hostBuildNumber = null) {
		$this->bundleUuid = $bundleUuid;
		$this->hostUuid = $hostUuid;
		$this->bundleBuildNumber = $bundleBuildNumber;
		$this->hostBuildNumber = $hostBuildNumber;
	}
}

class MismatchedNetworkPolicies extends phpDynamicProperties {
	public $device; //string
	public $backing; //string
	public $connected; //boolean

	function __construct($device = null, $backing = null, $connected = null) {
		$this->device = $device;
		$this->backing = $backing;
		$this->connected = $connected;
	}
}

class MismatchedVMotionNetworkNames extends phpDynamicProperties {
	public $sourceNetwork; //string
	public $destNetwork; //string

	function __construct($sourceNetwork = null, $destNetwork = null) {
		$this->sourceNetwork = $sourceNetwork;
		$this->destNetwork = $destNetwork;
	}
}

class MissingBmcSupport extends phpDynamicProperties {
}

class MissingController extends phpDynamicProperties {
}

class MissingIpPool extends phpDynamicProperties {
}

class MissingLinuxCustResources extends phpDynamicProperties {
}

class MissingNetworkIpConfig extends phpDynamicProperties {
}

class MissingPowerOffConfiguration extends phpDynamicProperties {
}

class MissingPowerOnConfiguration extends phpDynamicProperties {
}

class MissingWindowsCustResources extends phpDynamicProperties {
}

class MksConnectionLimitReached extends phpDynamicProperties {
	public $connectionLimit; //int

	function __construct($connectionLimit = null) {
		$this->connectionLimit = $connectionLimit;
	}
}

class MountError extends phpDynamicProperties {
	public $vm; //ManagedObjectReference
	public $diskIndex; //int

	function __construct($vm = null, $diskIndex = null) {
		$this->vm = $vm;
		$this->diskIndex = $diskIndex;
	}
}

class MultipleCertificatesVerifyFaultThumbprintData extends phpDynamicProperties {
	public $port; //int
	public $thumbprint; //string

	function __construct($port = null, $thumbprint = null) {
		$this->port = $port;
		$this->thumbprint = $thumbprint;
	}
}

class ArrayOfMultipleCertificatesVerifyFaultThumbprintData extends phpDynamicProperties {
	public $MultipleCertificatesVerifyFaultThumbprintData; //MultipleCertificatesVerifyFaultThumbprintData

	function __construct($MultipleCertificatesVerifyFaultThumbprintData = null) {
		$this->MultipleCertificatesVerifyFaultThumbprintData = $MultipleCertificatesVerifyFaultThumbprintData;
	}
}

class MultipleCertificatesVerifyFault extends phpDynamicProperties {
	public $thumbprintData; //MultipleCertificatesVerifyFaultThumbprintData

	function __construct($thumbprintData = null) {
		$this->thumbprintData = $thumbprintData;
	}
}

class MultipleSnapshotsNotSupported extends phpDynamicProperties {
}

class NasConfigFault extends phpDynamicProperties {
	public $name; //string

	function __construct($name = null) {
		$this->name = $name;
	}
}

class NasConnectionLimitReached extends phpDynamicProperties {
	public $remoteHost; //string
	public $remotePath; //string

	function __construct($remoteHost = null, $remotePath = null) {
		$this->remoteHost = $remoteHost;
		$this->remotePath = $remotePath;
	}
}

class NasSessionCredentialConflict extends phpDynamicProperties {
	public $remoteHost; //string
	public $remotePath; //string
	public $userName; //string

	function __construct($remoteHost = null, $remotePath = null, $userName = null) {
		$this->remoteHost = $remoteHost;
		$this->remotePath = $remotePath;
		$this->userName = $userName;
	}
}

class NasVolumeNotMounted extends phpDynamicProperties {
	public $remoteHost; //string
	public $remotePath; //string

	function __construct($remoteHost = null, $remotePath = null) {
		$this->remoteHost = $remoteHost;
		$this->remotePath = $remotePath;
	}
}

class NetworkCopyFault extends phpDynamicProperties {
}

class NetworkInaccessible extends phpDynamicProperties {
}

class NetworksMayNotBeTheSame extends phpDynamicProperties {
	public $name; //string

	function __construct($name = null) {
		$this->name = $name;
	}
}

class NicSettingMismatch extends phpDynamicProperties {
	public $numberOfNicsInSpec; //int
	public $numberOfNicsInVM; //int

	function __construct($numberOfNicsInSpec = null, $numberOfNicsInVM = null) {
		$this->numberOfNicsInSpec = $numberOfNicsInSpec;
		$this->numberOfNicsInVM = $numberOfNicsInVM;
	}
}

class NoActiveHostInCluster extends phpDynamicProperties {
	public $computeResource; //ManagedObjectReference

	function __construct($computeResource = null) {
		$this->computeResource = $computeResource;
	}
}

class NoAvailableIp extends phpDynamicProperties {
	public $network; //ManagedObjectReference

	function __construct($network = null) {
		$this->network = $network;
	}
}

class NoClientCertificate extends phpDynamicProperties {
}

class NoCompatibleDatastore extends phpDynamicProperties {
}

class NoCompatibleHardAffinityHost extends phpDynamicProperties {
	public $vmName; //string

	function __construct($vmName = null) {
		$this->vmName = $vmName;
	}
}

class NoCompatibleHost extends phpDynamicProperties {
	public $host; //ManagedObjectReference
	public $error; //LocalizedMethodFault

	function __construct($host = null, $error = null) {
		$this->host = $host;
		$this->error = $error;
	}
}

class NoCompatibleHostWithAccessToDevice extends phpDynamicProperties {
}

class NoCompatibleSoftAffinityHost extends phpDynamicProperties {
	public $vmName; //string

	function __construct($vmName = null) {
		$this->vmName = $vmName;
	}
}

class NoConnectedDatastore extends phpDynamicProperties {
}

class NoDiskFound extends phpDynamicProperties {
}

class NoDiskSpace extends phpDynamicProperties {
	public $datastore; //string

	function __construct($datastore = null) {
		$this->datastore = $datastore;
	}
}

class NoDisksToCustomize extends phpDynamicProperties {
}

class NoGateway extends phpDynamicProperties {
}

class NoGuestHeartbeat extends phpDynamicProperties {
}

class NoHost extends phpDynamicProperties {
	public $name; //string

	function __construct($name = null) {
		$this->name = $name;
	}
}

class NoHostSuitableForFtSecondary extends phpDynamicProperties {
	public $vm; //ManagedObjectReference
	public $vmName; //string

	function __construct($vm = null, $vmName = null) {
		$this->vm = $vm;
		$this->vmName = $vmName;
	}
}

class NoLicenseServerConfigured extends phpDynamicProperties {
}

class NoPeerHostFound extends phpDynamicProperties {
}

class NoPermission extends phpDynamicProperties {
	public $object; //ManagedObjectReference
	public $privilegeId; //string

	function __construct($object = null, $privilegeId = null) {
		$this->object = $object;
		$this->privilegeId = $privilegeId;
	}
}

class NoPermissionOnAD extends phpDynamicProperties {
}

class NoPermissionOnHost extends phpDynamicProperties {
}

class NoPermissionOnNasVolume extends phpDynamicProperties {
	public $userName; //string

	function __construct($userName = null) {
		$this->userName = $userName;
	}
}

class NoSubjectName extends phpDynamicProperties {
}

class NoVcManagedIpConfigured extends phpDynamicProperties {
}

class NoVirtualNic extends phpDynamicProperties {
}

class NoVmInVApp extends phpDynamicProperties {
}

class NonADUserRequired extends phpDynamicProperties {
}

class NonHomeRDMVMotionNotSupported extends phpDynamicProperties {
	public $device; //string

	function __construct($device = null) {
		$this->device = $device;
	}
}

class NonPersistentDisksNotSupported extends phpDynamicProperties {
}

class NotADirectory extends phpDynamicProperties {
}

class NotAFile extends phpDynamicProperties {
}

class NotAuthenticated extends phpDynamicProperties {
}

class NotEnoughCpus extends phpDynamicProperties {
	public $numCpuDest; //int
	public $numCpuVm; //int

	function __construct($numCpuDest = null, $numCpuVm = null) {
		$this->numCpuDest = $numCpuDest;
		$this->numCpuVm = $numCpuVm;
	}
}

class NotEnoughLogicalCpus extends phpDynamicProperties {
	public $host; //ManagedObjectReference

	function __construct($host = null) {
		$this->host = $host;
	}
}

class NotFound extends phpDynamicProperties {
}

class NotSupportedDeviceForFT extends phpDynamicProperties {
	public $host; //ManagedObjectReference
	public $hostName; //string
	public $vm; //ManagedObjectReference
	public $vmName; //string
	public $deviceType; //string
	public $deviceLabel; //string

	function __construct($host = null, $hostName = null, $vm = null, $vmName = null, $deviceType = null, $deviceLabel = null) {
		$this->host = $host;
		$this->hostName = $hostName;
		$this->vm = $vm;
		$this->vmName = $vmName;
		$this->deviceType = $deviceType;
		$this->deviceLabel = $deviceLabel;
	}
}

class NotSupportedHost extends phpDynamicProperties {
	public $productName; //string
	public $productVersion; //string

	function __construct($productName = null, $productVersion = null) {
		$this->productName = $productName;
		$this->productVersion = $productVersion;
	}
}

class NotSupportedHostInCluster extends phpDynamicProperties {
}

class NotSupportedHostInDvs extends phpDynamicProperties {
	public $switchProductSpec; //DistributedVirtualSwitchProductSpec

	function __construct($switchProductSpec = null) {
		$this->switchProductSpec = $switchProductSpec;
	}
}

class NotSupportedHostInHACluster extends phpDynamicProperties {
	public $hostName; //string
	public $build; //string

	function __construct($hostName = null, $build = null) {
		$this->hostName = $hostName;
		$this->build = $build;
	}
}

class NotUserConfigurableProperty extends phpDynamicProperties {
}

class NumVirtualCoresPerSocketNotSupported extends phpDynamicProperties {
	public $maxSupportedCoresPerSocketDest; //int
	public $numCoresPerSocketVm; //int

	function __construct($maxSupportedCoresPerSocketDest = null, $numCoresPerSocketVm = null) {
		$this->maxSupportedCoresPerSocketDest = $maxSupportedCoresPerSocketDest;
		$this->numCoresPerSocketVm = $numCoresPerSocketVm;
	}
}

class NumVirtualCpusExceedsLimit extends phpDynamicProperties {
	public $maxSupportedVcpus; //int

	function __construct($maxSupportedVcpus = null) {
		$this->maxSupportedVcpus = $maxSupportedVcpus;
	}
}

class NumVirtualCpusIncompatible extends phpDynamicProperties {
	public $reason; //string
	public $numCpu; //int

	function __construct($reason = null, $numCpu = null) {
		$this->reason = $reason;
		$this->numCpu = $numCpu;
	}
}

class NumVirtualCpusNotSupported extends phpDynamicProperties {
	public $maxSupportedVcpusDest; //int
	public $numCpuVm; //int

	function __construct($maxSupportedVcpusDest = null, $numCpuVm = null) {
		$this->maxSupportedVcpusDest = $maxSupportedVcpusDest;
		$this->numCpuVm = $numCpuVm;
	}
}

class OperationDisabledByGuest extends phpDynamicProperties {
}

class OperationDisallowedOnHost extends phpDynamicProperties {
}

class OperationNotSupportedByGuest extends phpDynamicProperties {
}

class OutOfBounds extends phpDynamicProperties {
	public $argumentName; //string

	function __construct($argumentName = null) {
		$this->argumentName = $argumentName;
	}
}

class OvfAttribute extends phpDynamicProperties {
	public $elementName; //string
	public $attributeName; //string

	function __construct($elementName = null, $attributeName = null) {
		$this->elementName = $elementName;
		$this->attributeName = $attributeName;
	}
}

class OvfConnectedDevice extends phpDynamicProperties {
}

class OvfConnectedDeviceFloppy extends phpDynamicProperties {
	public $filename; //string

	function __construct($filename = null) {
		$this->filename = $filename;
	}
}

class OvfConnectedDeviceIso extends phpDynamicProperties {
	public $filename; //string

	function __construct($filename = null) {
		$this->filename = $filename;
	}
}

class OvfConstraint extends phpDynamicProperties {
	public $name; //string

	function __construct($name = null) {
		$this->name = $name;
	}
}

class OvfConsumerCallbackFault extends phpDynamicProperties {
	public $extensionKey; //string
	public $extensionName; //string

	function __construct($extensionKey = null, $extensionName = null) {
		$this->extensionKey = $extensionKey;
		$this->extensionName = $extensionName;
	}
}

class OvfConsumerCommunicationError extends phpDynamicProperties {
	public $description; //string

	function __construct($description = null) {
		$this->description = $description;
	}
}

class OvfConsumerFault extends phpDynamicProperties {
	public $errorKey; //string
	public $message; //string
	public $params; //KeyValue

	function __construct($errorKey = null, $message = null, $params = null) {
		$this->errorKey = $errorKey;
		$this->message = $message;
		$this->params = $params;
	}
}

class OvfConsumerInvalidSection extends phpDynamicProperties {
	public $lineNumber; //int
	public $description; //string

	function __construct($lineNumber = null, $description = null) {
		$this->lineNumber = $lineNumber;
		$this->description = $description;
	}
}

class OvfConsumerPowerOnFault extends phpDynamicProperties {
	public $extensionKey; //string
	public $extensionName; //string
	public $description; //string

	function __construct($extensionKey = null, $extensionName = null, $description = null) {
		$this->extensionKey = $extensionKey;
		$this->extensionName = $extensionName;
		$this->description = $description;
	}
}

class OvfConsumerUndeclaredSection extends phpDynamicProperties {
	public $qualifiedSectionType; //string

	function __construct($qualifiedSectionType = null) {
		$this->qualifiedSectionType = $qualifiedSectionType;
	}
}

class OvfConsumerUndefinedPrefix extends phpDynamicProperties {
	public $prefix; //string

	function __construct($prefix = null) {
		$this->prefix = $prefix;
	}
}

class OvfConsumerValidationFault extends phpDynamicProperties {
	public $extensionKey; //string
	public $extensionName; //string
	public $message; //string

	function __construct($extensionKey = null, $extensionName = null, $message = null) {
		$this->extensionKey = $extensionKey;
		$this->extensionName = $extensionName;
		$this->message = $message;
	}
}

class OvfCpuCompatibility extends phpDynamicProperties {
	public $registerName; //string
	public $level; //int
	public $registerValue; //string
	public $desiredRegisterValue; //string

	function __construct($registerName = null, $level = null, $registerValue = null, $desiredRegisterValue = null) {
		$this->registerName = $registerName;
		$this->level = $level;
		$this->registerValue = $registerValue;
		$this->desiredRegisterValue = $desiredRegisterValue;
	}
}

class OvfCpuCompatibilityCheckNotSupported extends phpDynamicProperties {
}

class OvfDiskMappingNotFound extends phpDynamicProperties {
	public $diskName; //string
	public $vmName; //string

	function __construct($diskName = null, $vmName = null) {
		$this->diskName = $diskName;
		$this->vmName = $vmName;
	}
}

class OvfDiskOrderConstraint extends phpDynamicProperties {
}

class OvfDuplicateElement extends phpDynamicProperties {
}

class OvfDuplicatedElementBoundary extends phpDynamicProperties {
	public $boundary; //string

	function __construct($boundary = null) {
		$this->boundary = $boundary;
	}
}

class OvfDuplicatedPropertyIdExport extends phpDynamicProperties {
	public $fqid; //string

	function __construct($fqid = null) {
		$this->fqid = $fqid;
	}
}

class OvfDuplicatedPropertyIdImport extends phpDynamicProperties {
}

class OvfElement extends phpDynamicProperties {
	public $name; //string

	function __construct($name = null) {
		$this->name = $name;
	}
}

class OvfElementInvalidValue extends phpDynamicProperties {
	public $value; //string

	function __construct($value = null) {
		$this->value = $value;
	}
}

class OvfExport extends phpDynamicProperties {
}

class OvfExportFailed extends phpDynamicProperties {
}

class OvfFault extends phpDynamicProperties {
}

class OvfHardwareCheck extends phpDynamicProperties {
}

class OvfHardwareExport extends phpDynamicProperties {
	public $device; //VirtualDevice
	public $vmPath; //string

	function __construct($device = null, $vmPath = null) {
		$this->device = $device;
		$this->vmPath = $vmPath;
	}
}

class OvfHostResourceConstraint extends phpDynamicProperties {
	public $value; //string

	function __construct($value = null) {
		$this->value = $value;
	}
}

class OvfHostValueNotParsed extends phpDynamicProperties {
	public $property; //string
	public $value; //string

	function __construct($property = null, $value = null) {
		$this->property = $property;
		$this->value = $value;
	}
}

class OvfImport extends phpDynamicProperties {
}

class OvfImportFailed extends phpDynamicProperties {
}

class OvfInternalError extends phpDynamicProperties {
}

class OvfInvalidPackage extends phpDynamicProperties {
	public $lineNumber; //int

	function __construct($lineNumber = null) {
		$this->lineNumber = $lineNumber;
	}
}

class OvfInvalidValue extends phpDynamicProperties {
	public $value; //string

	function __construct($value = null) {
		$this->value = $value;
	}
}

class OvfInvalidValueConfiguration extends phpDynamicProperties {
}

class OvfInvalidValueEmpty extends phpDynamicProperties {
}

class OvfInvalidValueFormatMalformed extends phpDynamicProperties {
}

class OvfInvalidValueReference extends phpDynamicProperties {
}

class OvfInvalidVmName extends phpDynamicProperties {
	public $name; //string

	function __construct($name = null) {
		$this->name = $name;
	}
}

class OvfMappedOsId extends phpDynamicProperties {
	public $ovfId; //int
	public $ovfDescription; //string
	public $targetDescription; //string

	function __construct($ovfId = null, $ovfDescription = null, $targetDescription = null) {
		$this->ovfId = $ovfId;
		$this->ovfDescription = $ovfDescription;
		$this->targetDescription = $targetDescription;
	}
}

class OvfMissingAttribute extends phpDynamicProperties {
}

class OvfMissingElement extends phpDynamicProperties {
}

class OvfMissingElementNormalBoundary extends phpDynamicProperties {
	public $boundary; //string

	function __construct($boundary = null) {
		$this->boundary = $boundary;
	}
}

class OvfMissingHardware extends phpDynamicProperties {
	public $name; //string
	public $resourceType; //int

	function __construct($name = null, $resourceType = null) {
		$this->name = $name;
		$this->resourceType = $resourceType;
	}
}

class OvfNoHostNic extends phpDynamicProperties {
}

class OvfNoSpaceOnController extends phpDynamicProperties {
	public $parent; //string

	function __construct($parent = null) {
		$this->parent = $parent;
	}
}

class OvfNoSupportedHardwareFamily extends phpDynamicProperties {
	public $version; //string

	function __construct($version = null) {
		$this->version = $version;
	}
}

class OvfProperty extends phpDynamicProperties {
	public $type; //string
	public $value; //string

	function __construct($type = null, $value = null) {
		$this->type = $type;
		$this->value = $value;
	}
}

class OvfPropertyExport extends phpDynamicProperties {
	public $type; //string
	public $value; //string

	function __construct($type = null, $value = null) {
		$this->type = $type;
		$this->value = $value;
	}
}

class OvfPropertyNetwork extends phpDynamicProperties {
}

class OvfPropertyNetworkExport extends phpDynamicProperties {
	public $network; //string

	function __construct($network = null) {
		$this->network = $network;
	}
}

class OvfPropertyQualifier extends phpDynamicProperties {
	public $qualifier; //string

	function __construct($qualifier = null) {
		$this->qualifier = $qualifier;
	}
}

class OvfPropertyQualifierDuplicate extends phpDynamicProperties {
	public $qualifier; //string

	function __construct($qualifier = null) {
		$this->qualifier = $qualifier;
	}
}

class OvfPropertyQualifierIgnored extends phpDynamicProperties {
	public $qualifier; //string

	function __construct($qualifier = null) {
		$this->qualifier = $qualifier;
	}
}

class OvfPropertyType extends phpDynamicProperties {
}

class OvfPropertyValue extends phpDynamicProperties {
}

class OvfSystemFault extends phpDynamicProperties {
}

class OvfToXmlUnsupportedElement extends phpDynamicProperties {
	public $name; //string

	function __construct($name = null) {
		$this->name = $name;
	}
}

class OvfUnableToExportDisk extends phpDynamicProperties {
	public $diskName; //string

	function __construct($diskName = null) {
		$this->diskName = $diskName;
	}
}

class OvfUnexpectedElement extends phpDynamicProperties {
}

class OvfUnknownDevice extends phpDynamicProperties {
	public $device; //VirtualDevice
	public $vmName; //string

	function __construct($device = null, $vmName = null) {
		$this->device = $device;
		$this->vmName = $vmName;
	}
}

class OvfUnknownDeviceBacking extends phpDynamicProperties {
	public $backing; //VirtualDeviceBackingInfo

	function __construct($backing = null) {
		$this->backing = $backing;
	}
}

class OvfUnknownEntity extends phpDynamicProperties {
	public $lineNumber; //int

	function __construct($lineNumber = null) {
		$this->lineNumber = $lineNumber;
	}
}

class OvfUnsupportedAttribute extends phpDynamicProperties {
	public $elementName; //string
	public $attributeName; //string

	function __construct($elementName = null, $attributeName = null) {
		$this->elementName = $elementName;
		$this->attributeName = $attributeName;
	}
}

class OvfUnsupportedAttributeValue extends phpDynamicProperties {
	public $value; //string

	function __construct($value = null) {
		$this->value = $value;
	}
}

class OvfUnsupportedDeviceBackingInfo extends phpDynamicProperties {
	public $elementName; //string
	public $instanceId; //string
	public $deviceName; //string
	public $backingName; //string

	function __construct($elementName = null, $instanceId = null, $deviceName = null, $backingName = null) {
		$this->elementName = $elementName;
		$this->instanceId = $instanceId;
		$this->deviceName = $deviceName;
		$this->backingName = $backingName;
	}
}

class OvfUnsupportedDeviceBackingOption extends phpDynamicProperties {
	public $elementName; //string
	public $instanceId; //string
	public $deviceName; //string
	public $backingName; //string

	function __construct($elementName = null, $instanceId = null, $deviceName = null, $backingName = null) {
		$this->elementName = $elementName;
		$this->instanceId = $instanceId;
		$this->deviceName = $deviceName;
		$this->backingName = $backingName;
	}
}

class OvfUnsupportedDeviceExport extends phpDynamicProperties {
}

class OvfUnsupportedDiskProvisioning extends phpDynamicProperties {
	public $diskProvisioning; //string
	public $supportedDiskProvisioning; //string

	function __construct($diskProvisioning = null, $supportedDiskProvisioning = null) {
		$this->diskProvisioning = $diskProvisioning;
		$this->supportedDiskProvisioning = $supportedDiskProvisioning;
	}
}

class OvfUnsupportedElement extends phpDynamicProperties {
	public $name; //string

	function __construct($name = null) {
		$this->name = $name;
	}
}

class OvfUnsupportedElementValue extends phpDynamicProperties {
	public $value; //string

	function __construct($value = null) {
		$this->value = $value;
	}
}

class OvfUnsupportedPackage extends phpDynamicProperties {
	public $lineNumber; //int

	function __construct($lineNumber = null) {
		$this->lineNumber = $lineNumber;
	}
}

class OvfUnsupportedSection extends phpDynamicProperties {
	public $info; //string

	function __construct($info = null) {
		$this->info = $info;
	}
}

class OvfUnsupportedSubType extends phpDynamicProperties {
	public $elementName; //string
	public $instanceId; //string
	public $deviceType; //int
	public $deviceSubType; //string

	function __construct($elementName = null, $instanceId = null, $deviceType = null, $deviceSubType = null) {
		$this->elementName = $elementName;
		$this->instanceId = $instanceId;
		$this->deviceType = $deviceType;
		$this->deviceSubType = $deviceSubType;
	}
}

class OvfUnsupportedType extends phpDynamicProperties {
	public $name; //string
	public $instanceId; //string
	public $deviceType; //int

	function __construct($name = null, $instanceId = null, $deviceType = null) {
		$this->name = $name;
		$this->instanceId = $instanceId;
		$this->deviceType = $deviceType;
	}
}

class OvfWrongElement extends phpDynamicProperties {
}

class OvfWrongNamespace extends phpDynamicProperties {
	public $namespaceName; //string

	function __construct($namespaceName = null) {
		$this->namespaceName = $namespaceName;
	}
}

class OvfXmlFormat extends phpDynamicProperties {
	public $description; //string

	function __construct($description = null) {
		$this->description = $description;
	}
}

class PatchAlreadyInstalled extends phpDynamicProperties {
}

class PatchBinariesNotFound extends phpDynamicProperties {
	public $patchID; //string
	public $binary; //string

	function __construct($patchID = null, $binary = null) {
		$this->patchID = $patchID;
		$this->binary = $binary;
	}
}

class PatchInstallFailed extends phpDynamicProperties {
	public $rolledBack; //boolean

	function __construct($rolledBack = null) {
		$this->rolledBack = $rolledBack;
	}
}

class PatchIntegrityError extends phpDynamicProperties {
}

class PatchMetadataCorrupted extends phpDynamicProperties {
}

class PatchMetadataInvalid extends phpDynamicProperties {
	public $patchID; //string
	public $metaData; //string

	function __construct($patchID = null, $metaData = null) {
		$this->patchID = $patchID;
		$this->metaData = $metaData;
	}
}

class PatchMetadataNotFound extends phpDynamicProperties {
}

class PatchMissingDependencies extends phpDynamicProperties {
	public $prerequisitePatch; //string
	public $prerequisiteLib; //string

	function __construct($prerequisitePatch = null, $prerequisiteLib = null) {
		$this->prerequisitePatch = $prerequisitePatch;
		$this->prerequisiteLib = $prerequisiteLib;
	}
}

class PatchNotApplicable extends phpDynamicProperties {
	public $patchID; //string

	function __construct($patchID = null) {
		$this->patchID = $patchID;
	}
}

class PatchSuperseded extends phpDynamicProperties {
	public $supersede; //string

	function __construct($supersede = null) {
		$this->supersede = $supersede;
	}
}

class PhysCompatRDMNotSupported extends phpDynamicProperties {
}

class PlatformConfigFault extends phpDynamicProperties {
	public $text; //string

	function __construct($text = null) {
		$this->text = $text;
	}
}

class PowerOnFtSecondaryFailed extends phpDynamicProperties {
	public $vm; //ManagedObjectReference
	public $vmName; //string
	public $hostSelectionBy; //FtIssuesOnHostHostSelectionType
	public $hostErrors; //LocalizedMethodFault
	public $rootCause; //LocalizedMethodFault

	function __construct($vm = null, $vmName = null, $hostSelectionBy = null, $hostErrors = null, $rootCause = null) {
		$this->vm = $vm;
		$this->vmName = $vmName;
		$this->hostSelectionBy = $hostSelectionBy;
		$this->hostErrors = $hostErrors;
		$this->rootCause = $rootCause;
	}
}

class PowerOnFtSecondaryTimedout extends phpDynamicProperties {
	public $vm; //ManagedObjectReference
	public $vmName; //string
	public $timeout; //int

	function __construct($vm = null, $vmName = null, $timeout = null) {
		$this->vm = $vm;
		$this->vmName = $vmName;
		$this->timeout = $timeout;
	}
}

class ProfileUpdateFailedUpdateFailure extends phpDynamicProperties {
	public $profilePath; //ProfilePropertyPath
	public $errMsg; //LocalizableMessage

	function __construct($profilePath = null, $errMsg = null) {
		$this->profilePath = $profilePath;
		$this->errMsg = $errMsg;
	}
}

class ArrayOfProfileUpdateFailedUpdateFailure extends phpDynamicProperties {
	public $ProfileUpdateFailedUpdateFailure; //ProfileUpdateFailedUpdateFailure

	function __construct($ProfileUpdateFailedUpdateFailure = null) {
		$this->ProfileUpdateFailedUpdateFailure = $ProfileUpdateFailedUpdateFailure;
	}
}

class ProfileUpdateFailed extends phpDynamicProperties {
	public $failure; //ProfileUpdateFailedUpdateFailure

	function __construct($failure = null) {
		$this->failure = $failure;
	}
}

class QuestionPending extends phpDynamicProperties {
	public $text; //string

	function __construct($text = null) {
		$this->text = $text;
	}
}

class QuiesceDatastoreIOForHAFailed extends phpDynamicProperties {
	public $host; //ManagedObjectReference
	public $hostName; //string
	public $ds; //ManagedObjectReference
	public $dsName; //string

	function __construct($host = null, $hostName = null, $ds = null, $dsName = null) {
		$this->host = $host;
		$this->hostName = $hostName;
		$this->ds = $ds;
		$this->dsName = $dsName;
	}
}

class RDMConversionNotSupported extends phpDynamicProperties {
	public $device; //string

	function __construct($device = null) {
		$this->device = $device;
	}
}

class RDMNotPreserved extends phpDynamicProperties {
	public $device; //string

	function __construct($device = null) {
		$this->device = $device;
	}
}

class RDMNotSupported extends phpDynamicProperties {
}

class RDMNotSupportedOnDatastore extends phpDynamicProperties {
	public $device; //string
	public $datastore; //ManagedObjectReference
	public $datastoreName; //string

	function __construct($device = null, $datastore = null, $datastoreName = null) {
		$this->device = $device;
		$this->datastore = $datastore;
		$this->datastoreName = $datastoreName;
	}
}

class RDMPointsToInaccessibleDisk extends phpDynamicProperties {
}

class RawDiskNotSupported extends phpDynamicProperties {
}

class ReadHostResourcePoolTreeFailed extends phpDynamicProperties {
}

class ReadOnlyDisksWithLegacyDestination extends phpDynamicProperties {
	public $roDiskCount; //int
	public $timeoutDanger; //boolean

	function __construct($roDiskCount = null, $timeoutDanger = null) {
		$this->roDiskCount = $roDiskCount;
		$this->timeoutDanger = $timeoutDanger;
	}
}

class RebootRequired extends phpDynamicProperties {
	public $patch; //string

	function __construct($patch = null) {
		$this->patch = $patch;
	}
}

class RecordReplayDisabled extends phpDynamicProperties {
}

class RemoteDeviceNotSupported extends phpDynamicProperties {
}

class RemoveFailed extends phpDynamicProperties {
}

class ReplicationConfigFault extends phpDynamicProperties {
}

class ReplicationDiskConfigFault extends phpDynamicProperties {
	public $reason; //string
	public $vmRef; //ManagedObjectReference
	public $key; //int

	function __construct($reason = null, $vmRef = null, $key = null) {
		$this->reason = $reason;
		$this->vmRef = $vmRef;
		$this->key = $key;
	}
}

class ReplicationFault extends phpDynamicProperties {
}

class ReplicationIncompatibleWithFT extends phpDynamicProperties {
}

class ReplicationInvalidOptions extends phpDynamicProperties {
	public $options; //string
	public $entity; //ManagedObjectReference

	function __construct($options = null, $entity = null) {
		$this->options = $options;
		$this->entity = $entity;
	}
}

class ReplicationNotSupportedOnHost extends phpDynamicProperties {
}

class ReplicationVmConfigFault extends phpDynamicProperties {
	public $reason; //string
	public $vmRef; //ManagedObjectReference

	function __construct($reason = null, $vmRef = null) {
		$this->reason = $reason;
		$this->vmRef = $vmRef;
	}
}

class ReplicationVmFault extends phpDynamicProperties {
	public $reason; //string
	public $state; //string
	public $instanceId; //string
	public $vm; //ManagedObjectReference

	function __construct($reason = null, $state = null, $instanceId = null, $vm = null) {
		$this->reason = $reason;
		$this->state = $state;
		$this->instanceId = $instanceId;
		$this->vm = $vm;
	}
}

class ResourceInUse extends phpDynamicProperties {
	public $type; //string
	public $name; //string

	function __construct($type = null, $name = null) {
		$this->type = $type;
		$this->name = $name;
	}
}

class ResourceNotAvailable extends phpDynamicProperties {
	public $containerType; //string
	public $containerName; //string
	public $type; //string

	function __construct($containerType = null, $containerName = null, $type = null) {
		$this->containerType = $containerType;
		$this->containerName = $containerName;
		$this->type = $type;
	}
}

class RestrictedVersion extends phpDynamicProperties {
}

class RuleViolation extends phpDynamicProperties {
	public $host; //ManagedObjectReference
	public $rule; //ClusterRuleInfo

	function __construct($host = null, $rule = null) {
		$this->host = $host;
		$this->rule = $rule;
	}
}

class SSLDisabledFault extends phpDynamicProperties {
}

class SSLVerifyFault extends phpDynamicProperties {
	public $selfSigned; //boolean
	public $thumbprint; //string

	function __construct($selfSigned = null, $thumbprint = null) {
		$this->selfSigned = $selfSigned;
		$this->thumbprint = $thumbprint;
	}
}

class SSPIChallenge extends phpDynamicProperties {
	public $base64Token; //string

	function __construct($base64Token = null) {
		$this->base64Token = $base64Token;
	}
}

class SecondaryVmAlreadyDisabled extends phpDynamicProperties {
	public $instanceUuid; //string

	function __construct($instanceUuid = null) {
		$this->instanceUuid = $instanceUuid;
	}
}

class SecondaryVmAlreadyEnabled extends phpDynamicProperties {
	public $instanceUuid; //string

	function __construct($instanceUuid = null) {
		$this->instanceUuid = $instanceUuid;
	}
}

class SecondaryVmAlreadyRegistered extends phpDynamicProperties {
	public $instanceUuid; //string

	function __construct($instanceUuid = null) {
		$this->instanceUuid = $instanceUuid;
	}
}

class SecondaryVmNotRegistered extends phpDynamicProperties {
	public $instanceUuid; //string

	function __construct($instanceUuid = null) {
		$this->instanceUuid = $instanceUuid;
	}
}

class SharedBusControllerNotSupported extends phpDynamicProperties {
}

class SnapshotCloneNotSupported extends phpDynamicProperties {
}

class SnapshotCopyNotSupported extends phpDynamicProperties {
}

class SnapshotDisabled extends phpDynamicProperties {
}

class SnapshotFault extends phpDynamicProperties {
}

class SnapshotIncompatibleDeviceInVm extends phpDynamicProperties {
	public $fault; //LocalizedMethodFault

	function __construct($fault = null) {
		$this->fault = $fault;
	}
}

class SnapshotLocked extends phpDynamicProperties {
}

class SnapshotMoveFromNonHomeNotSupported extends phpDynamicProperties {
}

class SnapshotMoveNotSupported extends phpDynamicProperties {
}

class SnapshotMoveToNonHomeNotSupported extends phpDynamicProperties {
}

class SnapshotNoChange extends phpDynamicProperties {
}

class SnapshotRevertIssue extends phpDynamicProperties {
	public $snapshotName; //string
	public $event; //Event
	public $errors; //boolean

	function __construct($snapshotName = null, $event = null, $errors = null) {
		$this->snapshotName = $snapshotName;
		$this->event = $event;
		$this->errors = $errors;
	}
}

class SoftRuleVioCorrectionDisallowed extends phpDynamicProperties {
	public $vmName; //string

	function __construct($vmName = null) {
		$this->vmName = $vmName;
	}
}

class SoftRuleVioCorrectionImpact extends phpDynamicProperties {
	public $vmName; //string

	function __construct($vmName = null) {
		$this->vmName = $vmName;
	}
}

class StorageDrsDisabledOnVm extends phpDynamicProperties {
}

class StorageDrsIolbDisabledInternally extends phpDynamicProperties {
}

class StorageVMotionNotSupported extends phpDynamicProperties {
}

class StorageVmotionIncompatible extends phpDynamicProperties {
	public $datastore; //ManagedObjectReference

	function __construct($datastore = null) {
		$this->datastore = $datastore;
	}
}

class SuspendedRelocateNotSupported extends phpDynamicProperties {
}

class SwapDatastoreNotWritableOnHost extends phpDynamicProperties {
}

class SwapDatastoreUnset extends phpDynamicProperties {
}

class SwapPlacementOverrideNotSupported extends phpDynamicProperties {
}

class SwitchNotInUpgradeMode extends phpDynamicProperties {
}

class TaskInProgress extends phpDynamicProperties {
	public $task; //ManagedObjectReference

	function __construct($task = null) {
		$this->task = $task;
	}
}

class ThirdPartyLicenseAssignmentFailed extends phpDynamicProperties {
	public $host; //ManagedObjectReference
	public $module; //string
	public $reason; //string

	function __construct($host = null, $module = null, $reason = null) {
		$this->host = $host;
		$this->module = $module;
		$this->reason = $reason;
	}
}

class Timedout extends phpDynamicProperties {
}

class TooManyConcurrentNativeClones extends phpDynamicProperties {
}

class TooManyConsecutiveOverrides extends phpDynamicProperties {
}

class TooManyDevices extends phpDynamicProperties {
}

class TooManyDisksOnLegacyHost extends phpDynamicProperties {
	public $diskCount; //int
	public $timeoutDanger; //boolean

	function __construct($diskCount = null, $timeoutDanger = null) {
		$this->diskCount = $diskCount;
		$this->timeoutDanger = $timeoutDanger;
	}
}

class TooManyGuestLogons extends phpDynamicProperties {
}

class TooManyHosts extends phpDynamicProperties {
}

class TooManyNativeCloneLevels extends phpDynamicProperties {
}

class TooManyNativeClonesOnFile extends phpDynamicProperties {
}

class TooManySnapshotLevels extends phpDynamicProperties {
}

class ToolsAlreadyUpgraded extends phpDynamicProperties {
}

class ToolsAutoUpgradeNotSupported extends phpDynamicProperties {
}

class ToolsImageNotAvailable extends phpDynamicProperties {
}

class ToolsImageSignatureCheckFailed extends phpDynamicProperties {
}

class ToolsInstallationInProgress extends phpDynamicProperties {
}

class ToolsUnavailable extends phpDynamicProperties {
}

class ToolsUpgradeCancelled extends phpDynamicProperties {
}

class UncommittedUndoableDisk extends phpDynamicProperties {
}

class UnconfiguredPropertyValue extends phpDynamicProperties {
}

class UncustomizableGuest extends phpDynamicProperties {
	public $uncustomizableGuestOS; //string

	function __construct($uncustomizableGuestOS = null) {
		$this->uncustomizableGuestOS = $uncustomizableGuestOS;
	}
}

class UnexpectedCustomizationFault extends phpDynamicProperties {
}

class UnrecognizedHost extends phpDynamicProperties {
	public $hostName; //string

	function __construct($hostName = null) {
		$this->hostName = $hostName;
	}
}

class UnsharedSwapVMotionNotSupported extends phpDynamicProperties {
}

class UnsupportedDatastore extends phpDynamicProperties {
	public $datastore; //ManagedObjectReference

	function __construct($datastore = null) {
		$this->datastore = $datastore;
	}
}

class UnsupportedGuest extends phpDynamicProperties {
	public $unsupportedGuestOS; //string

	function __construct($unsupportedGuestOS = null) {
		$this->unsupportedGuestOS = $unsupportedGuestOS;
	}
}

class UnsupportedVimApiVersion extends phpDynamicProperties {
	public $version; //string

	function __construct($version = null) {
		$this->version = $version;
	}
}

class UnsupportedVmxLocation extends phpDynamicProperties {
}

class UnusedVirtualDiskBlocksNotScrubbed extends phpDynamicProperties {
}

class UserNotFound extends phpDynamicProperties {
	public $principal; //string
	public $unresolved; //boolean

	function __construct($principal = null, $unresolved = null) {
		$this->principal = $principal;
		$this->unresolved = $unresolved;
	}
}

class VAppConfigFault extends phpDynamicProperties {
}

class VAppNotRunning extends phpDynamicProperties {
}

class VAppOperationInProgress extends phpDynamicProperties {
}

class VAppPropertyFault extends phpDynamicProperties {
	public $id; //string
	public $category; //string
	public $label; //string
	public $type; //string
	public $value; //string

	function __construct($id = null, $category = null, $label = null, $type = null, $value = null) {
		$this->id = $id;
		$this->category = $category;
		$this->label = $label;
		$this->type = $type;
		$this->value = $value;
	}
}

class VAppTaskInProgress extends phpDynamicProperties {
}

class VMINotSupported extends phpDynamicProperties {
}

class VMOnConflictDVPort extends phpDynamicProperties {
}

class VMOnVirtualIntranet extends phpDynamicProperties {
}

class VMotionInterfaceIssue extends phpDynamicProperties {
	public $atSourceHost; //boolean
	public $failedHost; //string
	public $failedHostEntity; //ManagedObjectReference

	function __construct($atSourceHost = null, $failedHost = null, $failedHostEntity = null) {
		$this->atSourceHost = $atSourceHost;
		$this->failedHost = $failedHost;
		$this->failedHostEntity = $failedHostEntity;
	}
}

class VMotionLinkCapacityLow extends phpDynamicProperties {
	public $network; //string

	function __construct($network = null) {
		$this->network = $network;
	}
}

class VMotionLinkDown extends phpDynamicProperties {
	public $network; //string

	function __construct($network = null) {
		$this->network = $network;
	}
}

class VMotionNotConfigured extends phpDynamicProperties {
}

class VMotionNotLicensed extends phpDynamicProperties {
}

class VMotionNotSupported extends phpDynamicProperties {
}

class VMotionProtocolIncompatible extends phpDynamicProperties {
}

class VimFault extends phpDynamicProperties {
}

class VirtualDiskBlocksNotFullyProvisioned extends phpDynamicProperties {
}

class VirtualDiskModeNotSupported extends phpDynamicProperties {
	public $mode; //string

	function __construct($mode = null) {
		$this->mode = $mode;
	}
}

class VirtualEthernetCardNotSupported extends phpDynamicProperties {
}

class VirtualHardwareCompatibilityIssue extends phpDynamicProperties {
}

class VirtualHardwareVersionNotSupported extends phpDynamicProperties {
	public $hostName; //string
	public $host; //ManagedObjectReference

	function __construct($hostName = null, $host = null) {
		$this->hostName = $hostName;
		$this->host = $host;
	}
}

class VmAlreadyExistsInDatacenter extends phpDynamicProperties {
	public $host; //ManagedObjectReference
	public $hostname; //string
	public $vm; //ManagedObjectReference

	function __construct($host = null, $hostname = null, $vm = null) {
		$this->host = $host;
		$this->hostname = $hostname;
		$this->vm = $vm;
	}
}

class VmConfigFault extends phpDynamicProperties {
}

class VmConfigIncompatibleForFaultTolerance extends phpDynamicProperties {
	public $fault; //LocalizedMethodFault

	function __construct($fault = null) {
		$this->fault = $fault;
	}
}

class VmConfigIncompatibleForRecordReplay extends phpDynamicProperties {
	public $fault; //LocalizedMethodFault

	function __construct($fault = null) {
		$this->fault = $fault;
	}
}

class VmFaultToleranceConfigIssue extends phpDynamicProperties {
	public $reason; //string
	public $entityName; //string
	public $entity; //ManagedObjectReference

	function __construct($reason = null, $entityName = null, $entity = null) {
		$this->reason = $reason;
		$this->entityName = $entityName;
		$this->entity = $entity;
	}
}

class VmFaultToleranceConfigIssueWrapper extends phpDynamicProperties {
	public $entityName; //string
	public $entity; //ManagedObjectReference
	public $error; //LocalizedMethodFault

	function __construct($entityName = null, $entity = null, $error = null) {
		$this->entityName = $entityName;
		$this->entity = $entity;
		$this->error = $error;
	}
}

class VmFaultToleranceInvalidFileBacking extends phpDynamicProperties {
	public $backingType; //string
	public $backingFilename; //string

	function __construct($backingType = null, $backingFilename = null) {
		$this->backingType = $backingType;
		$this->backingFilename = $backingFilename;
	}
}

class VmFaultToleranceIssue extends phpDynamicProperties {
}

class VmFaultToleranceOpIssuesList extends phpDynamicProperties {
	public $errors; //LocalizedMethodFault
	public $warnings; //LocalizedMethodFault

	function __construct($errors = null, $warnings = null) {
		$this->errors = $errors;
		$this->warnings = $warnings;
	}
}

class VmFaultToleranceTooManyVMsOnHost extends phpDynamicProperties {
	public $hostName; //string
	public $maxNumFtVms; //int

	function __construct($hostName = null, $maxNumFtVms = null) {
		$this->hostName = $hostName;
		$this->maxNumFtVms = $maxNumFtVms;
	}
}

class VmHostAffinityRuleViolation extends phpDynamicProperties {
	public $vmName; //string
	public $hostName; //string

	function __construct($vmName = null, $hostName = null) {
		$this->vmName = $vmName;
		$this->hostName = $hostName;
	}
}

class VmLimitLicense extends phpDynamicProperties {
	public $limit; //int

	function __construct($limit = null) {
		$this->limit = $limit;
	}
}

class VmMonitorIncompatibleForFaultTolerance extends phpDynamicProperties {
}

class VmPowerOnDisabled extends phpDynamicProperties {
}

class VmToolsUpgradeFault extends phpDynamicProperties {
}

class VmValidateMaxDevice extends phpDynamicProperties {
	public $device; //string
	public $max; //int
	public $count; //int

	function __construct($device = null, $max = null, $count = null) {
		$this->device = $device;
		$this->max = $max;
		$this->count = $count;
	}
}

class VmWwnConflict extends phpDynamicProperties {
	public $vm; //ManagedObjectReference
	public $host; //ManagedObjectReference
	public $name; //string
	public $wwn; //long

	function __construct($vm = null, $host = null, $name = null, $wwn = null) {
		$this->vm = $vm;
		$this->host = $host;
		$this->name = $name;
		$this->wwn = $wwn;
	}
}

class VmfsAlreadyMounted extends phpDynamicProperties {
}

class VmfsAmbiguousMount extends phpDynamicProperties {
}

class VmfsMountFault extends phpDynamicProperties {
	public $uuid; //string

	function __construct($uuid = null) {
		$this->uuid = $uuid;
	}
}

class VmotionInterfaceNotEnabled extends phpDynamicProperties {
}

class VolumeEditorError extends phpDynamicProperties {
}

class VramLimitLicense extends phpDynamicProperties {
	public $limit; //int

	function __construct($limit = null) {
		$this->limit = $limit;
	}
}

class VspanDestPortConflict extends phpDynamicProperties {
	public $vspanSessionKey1; //string
	public $vspanSessionKey2; //string
	public $portKey; //string

	function __construct($vspanSessionKey1 = null, $vspanSessionKey2 = null, $portKey = null) {
		$this->vspanSessionKey1 = $vspanSessionKey1;
		$this->vspanSessionKey2 = $vspanSessionKey2;
		$this->portKey = $portKey;
	}
}

class VspanPortConflict extends phpDynamicProperties {
	public $vspanSessionKey1; //string
	public $vspanSessionKey2; //string
	public $portKey; //string

	function __construct($vspanSessionKey1 = null, $vspanSessionKey2 = null, $portKey = null) {
		$this->vspanSessionKey1 = $vspanSessionKey1;
		$this->vspanSessionKey2 = $vspanSessionKey2;
		$this->portKey = $portKey;
	}
}

class VspanPortMoveFault extends phpDynamicProperties {
	public $srcPortgroupName; //string
	public $destPortgroupName; //string
	public $portKey; //string

	function __construct($srcPortgroupName = null, $destPortgroupName = null, $portKey = null) {
		$this->srcPortgroupName = $srcPortgroupName;
		$this->destPortgroupName = $destPortgroupName;
		$this->portKey = $portKey;
	}
}

class VspanPortPromiscChangeFault extends phpDynamicProperties {
	public $portKey; //string

	function __construct($portKey = null) {
		$this->portKey = $portKey;
	}
}

class VspanPortgroupPromiscChangeFault extends phpDynamicProperties {
	public $portgroupName; //string

	function __construct($portgroupName = null) {
		$this->portgroupName = $portgroupName;
	}
}

class VspanPortgroupTypeChangeFault extends phpDynamicProperties {
	public $portgroupName; //string

	function __construct($portgroupName = null) {
		$this->portgroupName = $portgroupName;
	}
}

class VspanPromiscuousPortNotSupported extends phpDynamicProperties {
	public $vspanSessionKey; //string
	public $portKey; //string

	function __construct($vspanSessionKey = null, $portKey = null) {
		$this->vspanSessionKey = $vspanSessionKey;
		$this->portKey = $portKey;
	}
}

class VspanSameSessionPortConflict extends phpDynamicProperties {
	public $vspanSessionKey; //string
	public $portKey; //string

	function __construct($vspanSessionKey = null, $portKey = null) {
		$this->vspanSessionKey = $vspanSessionKey;
		$this->portKey = $portKey;
	}
}

class WakeOnLanNotSupported extends phpDynamicProperties {
}

class WakeOnLanNotSupportedByVmotionNIC extends phpDynamicProperties {
}

class WillLoseHAProtection extends phpDynamicProperties {
	public $resolution; //string

	function __construct($resolution = null) {
		$this->resolution = $resolution;
	}
}

class WillModifyConfigCpuRequirements extends phpDynamicProperties {
}

class WillResetSnapshotDirectory extends phpDynamicProperties {
}

class HostActiveDirectoryInfo extends phpDynamicProperties {
	public $joinedDomain; //string
	public $trustedDomain; //string
	public $domainMembershipStatus; //string

	function __construct($joinedDomain = null, $trustedDomain = null, $domainMembershipStatus = null) {
		$this->joinedDomain = $joinedDomain;
		$this->trustedDomain = $trustedDomain;
		$this->domainMembershipStatus = $domainMembershipStatus;
	}
}

class HostActiveDirectorySpec extends phpDynamicProperties {
	public $domainName; //string
	public $userName; //string
	public $password; //string
	public $camServer; //string
	public $thumbprint; //string

	function __construct($domainName = null, $userName = null, $password = null, $camServer = null, $thumbprint = null) {
		$this->domainName = $domainName;
		$this->userName = $userName;
		$this->password = $password;
		$this->camServer = $camServer;
		$this->thumbprint = $thumbprint;
	}
}

class HostActiveDirectory extends phpDynamicProperties {
	public $changeOperation; //string
	public $spec; //HostActiveDirectorySpec

	function __construct($changeOperation = null, $spec = null) {
		$this->changeOperation = $changeOperation;
		$this->spec = $spec;
	}
}

class ArrayOfHostActiveDirectory extends phpDynamicProperties {
	public $HostActiveDirectory; //HostActiveDirectory

	function __construct($HostActiveDirectory = null) {
		$this->HostActiveDirectory = $HostActiveDirectory;
	}
}

class HostAuthenticationManagerInfo extends phpDynamicProperties {
	public $authConfig; //HostAuthenticationStoreInfo

	function __construct($authConfig = null) {
		$this->authConfig = $authConfig;
	}
}

class HostAuthenticationStoreInfo extends phpDynamicProperties {
	public $enabled; //boolean

	function __construct($enabled = null) {
		$this->enabled = $enabled;
	}
}

class ArrayOfHostAuthenticationStoreInfo extends phpDynamicProperties {
	public $HostAuthenticationStoreInfo; //HostAuthenticationStoreInfo

	function __construct($HostAuthenticationStoreInfo = null) {
		$this->HostAuthenticationStoreInfo = $HostAuthenticationStoreInfo;
	}
}

class AutoStartDefaults extends phpDynamicProperties {
	public $enabled; //boolean
	public $startDelay; //int
	public $stopDelay; //int
	public $waitForHeartbeat; //boolean
	public $stopAction; //string

	function __construct($enabled = null, $startDelay = null, $stopDelay = null, $waitForHeartbeat = null, $stopAction = null) {
		$this->enabled = $enabled;
		$this->startDelay = $startDelay;
		$this->stopDelay = $stopDelay;
		$this->waitForHeartbeat = $waitForHeartbeat;
		$this->stopAction = $stopAction;
	}
}

class AutoStartPowerInfo extends phpDynamicProperties {
	public $key; //ManagedObjectReference
	public $startOrder; //int
	public $startDelay; //int
	public $waitForHeartbeat; //AutoStartWaitHeartbeatSetting
	public $startAction; //string
	public $stopDelay; //int
	public $stopAction; //string

	function __construct($key = null, $startOrder = null, $startDelay = null, $waitForHeartbeat = null, $startAction = null, $stopDelay = null, $stopAction = null) {
		$this->key = $key;
		$this->startOrder = $startOrder;
		$this->startDelay = $startDelay;
		$this->waitForHeartbeat = $waitForHeartbeat;
		$this->startAction = $startAction;
		$this->stopDelay = $stopDelay;
		$this->stopAction = $stopAction;
	}
}

class ArrayOfAutoStartPowerInfo extends phpDynamicProperties {
	public $AutoStartPowerInfo; //AutoStartPowerInfo

	function __construct($AutoStartPowerInfo = null) {
		$this->AutoStartPowerInfo = $AutoStartPowerInfo;
	}
}

class HostAutoStartManagerConfig extends phpDynamicProperties {
	public $defaults; //AutoStartDefaults
	public $powerInfo; //AutoStartPowerInfo

	function __construct($defaults = null, $powerInfo = null) {
		$this->defaults = $defaults;
		$this->powerInfo = $powerInfo;
	}
}

class HostBootDeviceInfo extends phpDynamicProperties {
	public $bootDevices; //HostBootDevice
	public $currentBootDeviceKey; //string

	function __construct($bootDevices = null, $currentBootDeviceKey = null) {
		$this->bootDevices = $bootDevices;
		$this->currentBootDeviceKey = $currentBootDeviceKey;
	}
}

class HostBootDevice extends phpDynamicProperties {
	public $key; //string
	public $description; //string

	function __construct($key = null, $description = null) {
		$this->key = $key;
		$this->description = $description;
	}
}

class ArrayOfHostBootDevice extends phpDynamicProperties {
	public $HostBootDevice; //HostBootDevice

	function __construct($HostBootDevice = null) {
		$this->HostBootDevice = $HostBootDevice;
	}
}

class HostCacheConfigurationSpec extends phpDynamicProperties {
	public $datastore; //ManagedObjectReference
	public $swapSize; //long

	function __construct($datastore = null, $swapSize = null) {
		$this->datastore = $datastore;
		$this->swapSize = $swapSize;
	}
}

class HostCacheConfigurationInfo extends phpDynamicProperties {
	public $key; //ManagedObjectReference
	public $swapSize; //long

	function __construct($key = null, $swapSize = null) {
		$this->key = $key;
		$this->swapSize = $swapSize;
	}
}

class ArrayOfHostCacheConfigurationInfo extends phpDynamicProperties {
	public $HostCacheConfigurationInfo; //HostCacheConfigurationInfo

	function __construct($HostCacheConfigurationInfo = null) {
		$this->HostCacheConfigurationInfo = $HostCacheConfigurationInfo;
	}
}

class HostCapability extends phpDynamicProperties {
	public $recursiveResourcePoolsSupported; //boolean
	public $cpuMemoryResourceConfigurationSupported; //boolean
	public $rebootSupported; //boolean
	public $shutdownSupported; //boolean
	public $vmotionSupported; //boolean
	public $standbySupported; //boolean
	public $ipmiSupported; //boolean
	public $maxSupportedVMs; //int
	public $maxRunningVMs; //int
	public $maxSupportedVcpus; //int
	public $datastorePrincipalSupported; //boolean
	public $sanSupported; //boolean
	public $nfsSupported; //boolean
	public $iscsiSupported; //boolean
	public $vlanTaggingSupported; //boolean
	public $nicTeamingSupported; //boolean
	public $highGuestMemSupported; //boolean
	public $maintenanceModeSupported; //boolean
	public $suspendedRelocateSupported; //boolean
	public $restrictedSnapshotRelocateSupported; //boolean
	public $perVmSwapFiles; //boolean
	public $localSwapDatastoreSupported; //boolean
	public $unsharedSwapVMotionSupported; //boolean
	public $backgroundSnapshotsSupported; //boolean
	public $preAssignedPCIUnitNumbersSupported; //boolean
	public $screenshotSupported; //boolean
	public $scaledScreenshotSupported; //boolean
	public $storageVMotionSupported; //boolean
	public $vmotionWithStorageVMotionSupported; //boolean
	public $recordReplaySupported; //boolean
	public $ftSupported; //boolean
	public $replayUnsupportedReason; //string
	public $replayCompatibilityIssues; //string
	public $ftCompatibilityIssues; //string
	public $loginBySSLThumbprintSupported; //boolean
	public $cloneFromSnapshotSupported; //boolean
	public $deltaDiskBackingsSupported; //boolean
	public $perVMNetworkTrafficShapingSupported; //boolean
	public $tpmSupported; //boolean
	public $supportedCpuFeature; //HostCpuIdInfo
	public $virtualExecUsageSupported; //boolean
	public $storageIORMSupported; //boolean
	public $vmDirectPathGen2Supported; //boolean
	public $vmDirectPathGen2UnsupportedReason; //string
	public $vmDirectPathGen2UnsupportedReasonExtended; //string
	public $supportedVmfsMajorVersion; //int
	public $vStorageCapable; //boolean
	public $snapshotRelayoutSupported; //boolean
	public $firewallIpRulesSupported; //boolean
	public $servicePackageInfoSupported; //boolean
	public $maxHostRunningVms; //int
	public $maxHostSupportedVcpus; //int
	public $vmfsDatastoreMountCapable; //boolean

	function __construct($recursiveResourcePoolsSupported = null, $cpuMemoryResourceConfigurationSupported = null, $rebootSupported = null, $shutdownSupported = null, $vmotionSupported = null, $standbySupported = null, $ipmiSupported = null, $maxSupportedVMs = null, $maxRunningVMs = null, $maxSupportedVcpus = null, $datastorePrincipalSupported = null, $sanSupported = null, $nfsSupported = null, $iscsiSupported = null, $vlanTaggingSupported = null, $nicTeamingSupported = null, $highGuestMemSupported = null, $maintenanceModeSupported = null, $suspendedRelocateSupported = null, $restrictedSnapshotRelocateSupported = null, $perVmSwapFiles = null, $localSwapDatastoreSupported = null, $unsharedSwapVMotionSupported = null, $backgroundSnapshotsSupported = null, $preAssignedPCIUnitNumbersSupported = null, $screenshotSupported = null, $scaledScreenshotSupported = null, $storageVMotionSupported = null, $vmotionWithStorageVMotionSupported = null, $recordReplaySupported = null, $ftSupported = null, $replayUnsupportedReason = null, $replayCompatibilityIssues = null, $ftCompatibilityIssues = null, $loginBySSLThumbprintSupported = null, $cloneFromSnapshotSupported = null, $deltaDiskBackingsSupported = null, $perVMNetworkTrafficShapingSupported = null, $tpmSupported = null, $supportedCpuFeature = null, $virtualExecUsageSupported = null, $storageIORMSupported = null, $vmDirectPathGen2Supported = null, $vmDirectPathGen2UnsupportedReason = null, $vmDirectPathGen2UnsupportedReasonExtended = null, $supportedVmfsMajorVersion = null, $vStorageCapable = null, $snapshotRelayoutSupported = null, $firewallIpRulesSupported = null, $servicePackageInfoSupported = null, $maxHostRunningVms = null, $maxHostSupportedVcpus = null, $vmfsDatastoreMountCapable = null) {
		$this->recursiveResourcePoolsSupported = $recursiveResourcePoolsSupported;
		$this->cpuMemoryResourceConfigurationSupported = $cpuMemoryResourceConfigurationSupported;
		$this->rebootSupported = $rebootSupported;
		$this->shutdownSupported = $shutdownSupported;
		$this->vmotionSupported = $vmotionSupported;
		$this->standbySupported = $standbySupported;
		$this->ipmiSupported = $ipmiSupported;
		$this->maxSupportedVMs = $maxSupportedVMs;
		$this->maxRunningVMs = $maxRunningVMs;
		$this->maxSupportedVcpus = $maxSupportedVcpus;
		$this->datastorePrincipalSupported = $datastorePrincipalSupported;
		$this->sanSupported = $sanSupported;
		$this->nfsSupported = $nfsSupported;
		$this->iscsiSupported = $iscsiSupported;
		$this->vlanTaggingSupported = $vlanTaggingSupported;
		$this->nicTeamingSupported = $nicTeamingSupported;
		$this->highGuestMemSupported = $highGuestMemSupported;
		$this->maintenanceModeSupported = $maintenanceModeSupported;
		$this->suspendedRelocateSupported = $suspendedRelocateSupported;
		$this->restrictedSnapshotRelocateSupported = $restrictedSnapshotRelocateSupported;
		$this->perVmSwapFiles = $perVmSwapFiles;
		$this->localSwapDatastoreSupported = $localSwapDatastoreSupported;
		$this->unsharedSwapVMotionSupported = $unsharedSwapVMotionSupported;
		$this->backgroundSnapshotsSupported = $backgroundSnapshotsSupported;
		$this->preAssignedPCIUnitNumbersSupported = $preAssignedPCIUnitNumbersSupported;
		$this->screenshotSupported = $screenshotSupported;
		$this->scaledScreenshotSupported = $scaledScreenshotSupported;
		$this->storageVMotionSupported = $storageVMotionSupported;
		$this->vmotionWithStorageVMotionSupported = $vmotionWithStorageVMotionSupported;
		$this->recordReplaySupported = $recordReplaySupported;
		$this->ftSupported = $ftSupported;
		$this->replayUnsupportedReason = $replayUnsupportedReason;
		$this->replayCompatibilityIssues = $replayCompatibilityIssues;
		$this->ftCompatibilityIssues = $ftCompatibilityIssues;
		$this->loginBySSLThumbprintSupported = $loginBySSLThumbprintSupported;
		$this->cloneFromSnapshotSupported = $cloneFromSnapshotSupported;
		$this->deltaDiskBackingsSupported = $deltaDiskBackingsSupported;
		$this->perVMNetworkTrafficShapingSupported = $perVMNetworkTrafficShapingSupported;
		$this->tpmSupported = $tpmSupported;
		$this->supportedCpuFeature = $supportedCpuFeature;
		$this->virtualExecUsageSupported = $virtualExecUsageSupported;
		$this->storageIORMSupported = $storageIORMSupported;
		$this->vmDirectPathGen2Supported = $vmDirectPathGen2Supported;
		$this->vmDirectPathGen2UnsupportedReason = $vmDirectPathGen2UnsupportedReason;
		$this->vmDirectPathGen2UnsupportedReasonExtended = $vmDirectPathGen2UnsupportedReasonExtended;
		$this->supportedVmfsMajorVersion = $supportedVmfsMajorVersion;
		$this->vStorageCapable = $vStorageCapable;
		$this->snapshotRelayoutSupported = $snapshotRelayoutSupported;
		$this->firewallIpRulesSupported = $firewallIpRulesSupported;
		$this->servicePackageInfoSupported = $servicePackageInfoSupported;
		$this->maxHostRunningVms = $maxHostRunningVms;
		$this->maxHostSupportedVcpus = $maxHostSupportedVcpus;
		$this->vmfsDatastoreMountCapable = $vmfsDatastoreMountCapable;
	}
}

class HostConfigChange extends phpDynamicProperties {
}

class HostConfigInfo extends phpDynamicProperties {
	public $host; //ManagedObjectReference
	public $product; //AboutInfo
	public $hyperThread; //HostHyperThreadScheduleInfo
	public $consoleReservation; //ServiceConsoleReservationInfo
	public $virtualMachineReservation; //VirtualMachineMemoryReservationInfo
	public $storageDevice; //HostStorageDeviceInfo
	public $multipathState; //HostMultipathStateInfo
	public $fileSystemVolume; //HostFileSystemVolumeInfo
	public $systemFile; //string
	public $network; //HostNetworkInfo
	public $vmotion; //HostVMotionInfo
	public $virtualNicManagerInfo; //HostVirtualNicManagerInfo
	public $capabilities; //HostNetCapabilities
	public $datastoreCapabilities; //HostDatastoreSystemCapabilities
	public $offloadCapabilities; //HostNetOffloadCapabilities
	public $service; //HostServiceInfo
	public $firewall; //HostFirewallInfo
	public $autoStart; //HostAutoStartManagerConfig
	public $activeDiagnosticPartition; //HostDiagnosticPartition
	public $option; //OptionValue
	public $optionDef; //OptionDef
	public $datastorePrincipal; //string
	public $localSwapDatastore; //ManagedObjectReference
	public $systemResources; //HostSystemResourceInfo
	public $dateTimeInfo; //HostDateTimeInfo
	public $flags; //HostFlagInfo
	public $adminDisabled; //boolean
	public $ipmi; //HostIpmiInfo
	public $sslThumbprintInfo; //HostSslThumbprintInfo
	public $sslThumbprintData; //HostSslThumbprintInfo
	public $certificate; //byte
	public $pciPassthruInfo; //HostPciPassthruInfo
	public $authenticationManagerInfo; //HostAuthenticationManagerInfo
	public $featureVersion; //HostFeatureVersionInfo
	public $powerSystemCapability; //PowerSystemCapability
	public $powerSystemInfo; //PowerSystemInfo
	public $cacheConfigurationInfo; //HostCacheConfigurationInfo
	public $wakeOnLanCapable; //boolean

	function __construct($host = null, $product = null, $hyperThread = null, $consoleReservation = null, $virtualMachineReservation = null, $storageDevice = null, $multipathState = null, $fileSystemVolume = null, $systemFile = null, $network = null, $vmotion = null, $virtualNicManagerInfo = null, $capabilities = null, $datastoreCapabilities = null, $offloadCapabilities = null, $service = null, $firewall = null, $autoStart = null, $activeDiagnosticPartition = null, $option = null, $optionDef = null, $datastorePrincipal = null, $localSwapDatastore = null, $systemResources = null, $dateTimeInfo = null, $flags = null, $adminDisabled = null, $ipmi = null, $sslThumbprintInfo = null, $sslThumbprintData = null, $certificate = null, $pciPassthruInfo = null, $authenticationManagerInfo = null, $featureVersion = null, $powerSystemCapability = null, $powerSystemInfo = null, $cacheConfigurationInfo = null, $wakeOnLanCapable = null) {
		$this->host = $host;
		$this->product = $product;
		$this->hyperThread = $hyperThread;
		$this->consoleReservation = $consoleReservation;
		$this->virtualMachineReservation = $virtualMachineReservation;
		$this->storageDevice = $storageDevice;
		$this->multipathState = $multipathState;
		$this->fileSystemVolume = $fileSystemVolume;
		$this->systemFile = $systemFile;
		$this->network = $network;
		$this->vmotion = $vmotion;
		$this->virtualNicManagerInfo = $virtualNicManagerInfo;
		$this->capabilities = $capabilities;
		$this->datastoreCapabilities = $datastoreCapabilities;
		$this->offloadCapabilities = $offloadCapabilities;
		$this->service = $service;
		$this->firewall = $firewall;
		$this->autoStart = $autoStart;
		$this->activeDiagnosticPartition = $activeDiagnosticPartition;
		$this->option = $option;
		$this->optionDef = $optionDef;
		$this->datastorePrincipal = $datastorePrincipal;
		$this->localSwapDatastore = $localSwapDatastore;
		$this->systemResources = $systemResources;
		$this->dateTimeInfo = $dateTimeInfo;
		$this->flags = $flags;
		$this->adminDisabled = $adminDisabled;
		$this->ipmi = $ipmi;
		$this->sslThumbprintInfo = $sslThumbprintInfo;
		$this->sslThumbprintData = $sslThumbprintData;
		$this->certificate = $certificate;
		$this->pciPassthruInfo = $pciPassthruInfo;
		$this->authenticationManagerInfo = $authenticationManagerInfo;
		$this->featureVersion = $featureVersion;
		$this->powerSystemCapability = $powerSystemCapability;
		$this->powerSystemInfo = $powerSystemInfo;
		$this->cacheConfigurationInfo = $cacheConfigurationInfo;
		$this->wakeOnLanCapable = $wakeOnLanCapable;
	}
}

class HostConfigManager extends phpDynamicProperties {
	public $cpuScheduler; //ManagedObjectReference
	public $datastoreSystem; //ManagedObjectReference
	public $memoryManager; //ManagedObjectReference
	public $storageSystem; //ManagedObjectReference
	public $networkSystem; //ManagedObjectReference
	public $vmotionSystem; //ManagedObjectReference
	public $virtualNicManager; //ManagedObjectReference
	public $serviceSystem; //ManagedObjectReference
	public $firewallSystem; //ManagedObjectReference
	public $advancedOption; //ManagedObjectReference
	public $diagnosticSystem; //ManagedObjectReference
	public $autoStartManager; //ManagedObjectReference
	public $snmpSystem; //ManagedObjectReference
	public $dateTimeSystem; //ManagedObjectReference
	public $patchManager; //ManagedObjectReference
	public $imageConfigManager; //ManagedObjectReference
	public $bootDeviceSystem; //ManagedObjectReference
	public $firmwareSystem; //ManagedObjectReference
	public $healthStatusSystem; //ManagedObjectReference
	public $pciPassthruSystem; //ManagedObjectReference
	public $licenseManager; //ManagedObjectReference
	public $kernelModuleSystem; //ManagedObjectReference
	public $authenticationManager; //ManagedObjectReference
	public $powerSystem; //ManagedObjectReference
	public $cacheConfigurationManager; //ManagedObjectReference
	public $esxAgentHostManager; //ManagedObjectReference
	public $iscsiManager; //ManagedObjectReference

	function __construct($cpuScheduler = null, $datastoreSystem = null, $memoryManager = null, $storageSystem = null, $networkSystem = null, $vmotionSystem = null, $virtualNicManager = null, $serviceSystem = null, $firewallSystem = null, $advancedOption = null, $diagnosticSystem = null, $autoStartManager = null, $snmpSystem = null, $dateTimeSystem = null, $patchManager = null, $imageConfigManager = null, $bootDeviceSystem = null, $firmwareSystem = null, $healthStatusSystem = null, $pciPassthruSystem = null, $licenseManager = null, $kernelModuleSystem = null, $authenticationManager = null, $powerSystem = null, $cacheConfigurationManager = null, $esxAgentHostManager = null, $iscsiManager = null) {
		$this->cpuScheduler = $cpuScheduler;
		$this->datastoreSystem = $datastoreSystem;
		$this->memoryManager = $memoryManager;
		$this->storageSystem = $storageSystem;
		$this->networkSystem = $networkSystem;
		$this->vmotionSystem = $vmotionSystem;
		$this->virtualNicManager = $virtualNicManager;
		$this->serviceSystem = $serviceSystem;
		$this->firewallSystem = $firewallSystem;
		$this->advancedOption = $advancedOption;
		$this->diagnosticSystem = $diagnosticSystem;
		$this->autoStartManager = $autoStartManager;
		$this->snmpSystem = $snmpSystem;
		$this->dateTimeSystem = $dateTimeSystem;
		$this->patchManager = $patchManager;
		$this->imageConfigManager = $imageConfigManager;
		$this->bootDeviceSystem = $bootDeviceSystem;
		$this->firmwareSystem = $firmwareSystem;
		$this->healthStatusSystem = $healthStatusSystem;
		$this->pciPassthruSystem = $pciPassthruSystem;
		$this->licenseManager = $licenseManager;
		$this->kernelModuleSystem = $kernelModuleSystem;
		$this->authenticationManager = $authenticationManager;
		$this->powerSystem = $powerSystem;
		$this->cacheConfigurationManager = $cacheConfigurationManager;
		$this->esxAgentHostManager = $esxAgentHostManager;
		$this->iscsiManager = $iscsiManager;
	}
}

class HostConfigSpec extends phpDynamicProperties {
	public $nasDatastore; //HostNasVolumeConfig
	public $network; //HostNetworkConfig
	public $nicTypeSelection; //HostVirtualNicManagerNicTypeSelection
	public $service; //HostServiceConfig
	public $firewall; //HostFirewallConfig
	public $option; //OptionValue
	public $datastorePrincipal; //string
	public $datastorePrincipalPasswd; //string
	public $datetime; //HostDateTimeConfig
	public $storageDevice; //HostStorageDeviceInfo
	public $license; //HostLicenseSpec
	public $security; //HostSecuritySpec
	public $userAccount; //HostAccountSpec
	public $usergroupAccount; //HostAccountSpec
	public $memory; //HostMemorySpec
	public $activeDirectory; //HostActiveDirectory
	public $genericConfig; //KeyAnyValue

	function __construct($nasDatastore = null, $network = null, $nicTypeSelection = null, $service = null, $firewall = null, $option = null, $datastorePrincipal = null, $datastorePrincipalPasswd = null, $datetime = null, $storageDevice = null, $license = null, $security = null, $userAccount = null, $usergroupAccount = null, $memory = null, $activeDirectory = null, $genericConfig = null) {
		$this->nasDatastore = $nasDatastore;
		$this->network = $network;
		$this->nicTypeSelection = $nicTypeSelection;
		$this->service = $service;
		$this->firewall = $firewall;
		$this->option = $option;
		$this->datastorePrincipal = $datastorePrincipal;
		$this->datastorePrincipalPasswd = $datastorePrincipalPasswd;
		$this->datetime = $datetime;
		$this->storageDevice = $storageDevice;
		$this->license = $license;
		$this->security = $security;
		$this->userAccount = $userAccount;
		$this->usergroupAccount = $usergroupAccount;
		$this->memory = $memory;
		$this->activeDirectory = $activeDirectory;
		$this->genericConfig = $genericConfig;
	}
}

class HostConnectInfoNetworkInfo extends phpDynamicProperties {
	public $summary; //NetworkSummary

	function __construct($summary = null) {
		$this->summary = $summary;
	}
}

class ArrayOfHostConnectInfoNetworkInfo extends phpDynamicProperties {
	public $HostConnectInfoNetworkInfo; //HostConnectInfoNetworkInfo

	function __construct($HostConnectInfoNetworkInfo = null) {
		$this->HostConnectInfoNetworkInfo = $HostConnectInfoNetworkInfo;
	}
}

class HostNewNetworkConnectInfo extends phpDynamicProperties {
}

class HostDatastoreConnectInfo extends phpDynamicProperties {
	public $summary; //DatastoreSummary

	function __construct($summary = null) {
		$this->summary = $summary;
	}
}

class ArrayOfHostDatastoreConnectInfo extends phpDynamicProperties {
	public $HostDatastoreConnectInfo; //HostDatastoreConnectInfo

	function __construct($HostDatastoreConnectInfo = null) {
		$this->HostDatastoreConnectInfo = $HostDatastoreConnectInfo;
	}
}

class HostDatastoreExistsConnectInfo extends phpDynamicProperties {
	public $newDatastoreName; //string

	function __construct($newDatastoreName = null) {
		$this->newDatastoreName = $newDatastoreName;
	}
}

class HostDatastoreNameConflictConnectInfo extends phpDynamicProperties {
	public $newDatastoreName; //string

	function __construct($newDatastoreName = null) {
		$this->newDatastoreName = $newDatastoreName;
	}
}

class HostLicenseConnectInfo extends phpDynamicProperties {
	public $license; //LicenseManagerLicenseInfo
	public $evaluation; //LicenseManagerEvaluationInfo
	public $resource; //HostLicensableResourceInfo

	function __construct($license = null, $evaluation = null, $resource = null) {
		$this->license = $license;
		$this->evaluation = $evaluation;
		$this->resource = $resource;
	}
}

class HostConnectInfo extends phpDynamicProperties {
	public $serverIp; //string
	public $inDasCluster; //boolean
	public $host; //HostListSummary
	public $vm; //VirtualMachineSummary
	public $vimAccountNameRequired; //boolean
	public $clusterSupported; //boolean
	public $network; //HostConnectInfoNetworkInfo
	public $datastore; //HostDatastoreConnectInfo
	public $license; //HostLicenseConnectInfo

	function __construct($serverIp = null, $inDasCluster = null, $host = null, $vm = null, $vimAccountNameRequired = null, $clusterSupported = null, $network = null, $datastore = null, $license = null) {
		$this->serverIp = $serverIp;
		$this->inDasCluster = $inDasCluster;
		$this->host = $host;
		$this->vm = $vm;
		$this->vimAccountNameRequired = $vimAccountNameRequired;
		$this->clusterSupported = $clusterSupported;
		$this->network = $network;
		$this->datastore = $datastore;
		$this->license = $license;
	}
}

class HostConnectSpec extends phpDynamicProperties {
	public $hostName; //string
	public $port; //int
	public $sslThumbprint; //string
	public $userName; //string
	public $password; //string
	public $vmFolder; //ManagedObjectReference
	public $force; //boolean
	public $vimAccountName; //string
	public $vimAccountPassword; //string
	public $managementIp; //string

	function __construct($hostName = null, $port = null, $sslThumbprint = null, $userName = null, $password = null, $vmFolder = null, $force = null, $vimAccountName = null, $vimAccountPassword = null, $managementIp = null) {
		$this->hostName = $hostName;
		$this->port = $port;
		$this->sslThumbprint = $sslThumbprint;
		$this->userName = $userName;
		$this->password = $password;
		$this->vmFolder = $vmFolder;
		$this->force = $force;
		$this->vimAccountName = $vimAccountName;
		$this->vimAccountPassword = $vimAccountPassword;
		$this->managementIp = $managementIp;
	}
}

class HostCpuIdInfo extends phpDynamicProperties {
	public $level; //int
	public $vendor; //string
	public $eax; //string
	public $ebx; //string
	public $ecx; //string
	public $edx; //string

	function __construct($level = null, $vendor = null, $eax = null, $ebx = null, $ecx = null, $edx = null) {
		$this->level = $level;
		$this->vendor = $vendor;
		$this->eax = $eax;
		$this->ebx = $ebx;
		$this->ecx = $ecx;
		$this->edx = $edx;
	}
}

class ArrayOfHostCpuIdInfo extends phpDynamicProperties {
	public $HostCpuIdInfo; //HostCpuIdInfo

	function __construct($HostCpuIdInfo = null) {
		$this->HostCpuIdInfo = $HostCpuIdInfo;
	}
}

class HostHyperThreadScheduleInfo extends phpDynamicProperties {
	public $available; //boolean
	public $active; //boolean
	public $config; //boolean

	function __construct($available = null, $active = null, $config = null) {
		$this->available = $available;
		$this->active = $active;
		$this->config = $config;
	}
}

class FileQueryFlags extends phpDynamicProperties {
	public $fileType; //boolean
	public $fileSize; //boolean
	public $modification; //boolean
	public $fileOwner; //boolean

	function __construct($fileType = null, $fileSize = null, $modification = null, $fileOwner = null) {
		$this->fileType = $fileType;
		$this->fileSize = $fileSize;
		$this->modification = $modification;
		$this->fileOwner = $fileOwner;
	}
}

class FileInfo extends phpDynamicProperties {
	public $path; //string
	public $fileSize; //long
	public $modification; //dateTime
	public $owner; //string

	function __construct($path = null, $fileSize = null, $modification = null, $owner = null) {
		$this->path = $path;
		$this->fileSize = $fileSize;
		$this->modification = $modification;
		$this->owner = $owner;
	}
}

class ArrayOfFileInfo extends phpDynamicProperties {
	public $FileInfo; //FileInfo

	function __construct($FileInfo = null) {
		$this->FileInfo = $FileInfo;
	}
}

class FileQuery extends phpDynamicProperties {
}

class ArrayOfFileQuery extends phpDynamicProperties {
	public $FileQuery; //FileQuery

	function __construct($FileQuery = null) {
		$this->FileQuery = $FileQuery;
	}
}

class VmConfigFileQueryFilter extends phpDynamicProperties {
	public $matchConfigVersion; //int

	function __construct($matchConfigVersion = null) {
		$this->matchConfigVersion = $matchConfigVersion;
	}
}

class VmConfigFileQueryFlags extends phpDynamicProperties {
	public $configVersion; //boolean

	function __construct($configVersion = null) {
		$this->configVersion = $configVersion;
	}
}

class VmConfigFileQuery extends phpDynamicProperties {
	public $filter; //VmConfigFileQueryFilter
	public $details; //VmConfigFileQueryFlags

	function __construct($filter = null, $details = null) {
		$this->filter = $filter;
		$this->details = $details;
	}
}

class TemplateConfigFileQuery extends phpDynamicProperties {
}

class VmDiskFileQueryFilter extends phpDynamicProperties {
	public $diskType; //string
	public $matchHardwareVersion; //int
	public $controllerType; //string
	public $thin; //boolean

	function __construct($diskType = null, $matchHardwareVersion = null, $controllerType = null, $thin = null) {
		$this->diskType = $diskType;
		$this->matchHardwareVersion = $matchHardwareVersion;
		$this->controllerType = $controllerType;
		$this->thin = $thin;
	}
}

class VmDiskFileQueryFlags extends phpDynamicProperties {
	public $diskType; //boolean
	public $capacityKb; //boolean
	public $hardwareVersion; //boolean
	public $controllerType; //boolean
	public $diskExtents; //boolean
	public $thin; //boolean

	function __construct($diskType = null, $capacityKb = null, $hardwareVersion = null, $controllerType = null, $diskExtents = null, $thin = null) {
		$this->diskType = $diskType;
		$this->capacityKb = $capacityKb;
		$this->hardwareVersion = $hardwareVersion;
		$this->controllerType = $controllerType;
		$this->diskExtents = $diskExtents;
		$this->thin = $thin;
	}
}

class VmDiskFileQuery extends phpDynamicProperties {
	public $filter; //VmDiskFileQueryFilter
	public $details; //VmDiskFileQueryFlags

	function __construct($filter = null, $details = null) {
		$this->filter = $filter;
		$this->details = $details;
	}
}

class FolderFileQuery extends phpDynamicProperties {
}

class VmSnapshotFileQuery extends phpDynamicProperties {
}

class IsoImageFileQuery extends phpDynamicProperties {
}

class FloppyImageFileQuery extends phpDynamicProperties {
}

class VmNvramFileQuery extends phpDynamicProperties {
}

class VmLogFileQuery extends phpDynamicProperties {
}

class VmConfigFileInfo extends phpDynamicProperties {
	public $configVersion; //int

	function __construct($configVersion = null) {
		$this->configVersion = $configVersion;
	}
}

class TemplateConfigFileInfo extends phpDynamicProperties {
}

class VmDiskFileInfo extends phpDynamicProperties {
	public $diskType; //string
	public $capacityKb; //long
	public $hardwareVersion; //int
	public $controllerType; //string
	public $diskExtents; //string
	public $thin; //boolean

	function __construct($diskType = null, $capacityKb = null, $hardwareVersion = null, $controllerType = null, $diskExtents = null, $thin = null) {
		$this->diskType = $diskType;
		$this->capacityKb = $capacityKb;
		$this->hardwareVersion = $hardwareVersion;
		$this->controllerType = $controllerType;
		$this->diskExtents = $diskExtents;
		$this->thin = $thin;
	}
}

class FolderFileInfo extends phpDynamicProperties {
}

class VmSnapshotFileInfo extends phpDynamicProperties {
}

class IsoImageFileInfo extends phpDynamicProperties {
}

class FloppyImageFileInfo extends phpDynamicProperties {
}

class VmNvramFileInfo extends phpDynamicProperties {
}

class VmLogFileInfo extends phpDynamicProperties {
}

class HostDatastoreBrowserSearchSpec extends phpDynamicProperties {
	public $query; //FileQuery
	public $details; //FileQueryFlags
	public $searchCaseInsensitive; //boolean
	public $matchPattern; //string
	public $sortFoldersFirst; //boolean

	function __construct($query = null, $details = null, $searchCaseInsensitive = null, $matchPattern = null, $sortFoldersFirst = null) {
		$this->query = $query;
		$this->details = $details;
		$this->searchCaseInsensitive = $searchCaseInsensitive;
		$this->matchPattern = $matchPattern;
		$this->sortFoldersFirst = $sortFoldersFirst;
	}
}

class HostDatastoreBrowserSearchResults extends phpDynamicProperties {
	public $datastore; //ManagedObjectReference
	public $folderPath; //string
	public $file; //FileInfo

	function __construct($datastore = null, $folderPath = null, $file = null) {
		$this->datastore = $datastore;
		$this->folderPath = $folderPath;
		$this->file = $file;
	}
}

class ArrayOfHostDatastoreBrowserSearchResults extends phpDynamicProperties {
	public $HostDatastoreBrowserSearchResults; //HostDatastoreBrowserSearchResults

	function __construct($HostDatastoreBrowserSearchResults = null) {
		$this->HostDatastoreBrowserSearchResults = $HostDatastoreBrowserSearchResults;
	}
}

class HostDatastoreSystemCapabilities extends phpDynamicProperties {
	public $nfsMountCreationRequired; //boolean
	public $nfsMountCreationSupported; //boolean
	public $localDatastoreSupported; //boolean
	public $vmfsExtentExpansionSupported; //boolean

	function __construct($nfsMountCreationRequired = null, $nfsMountCreationSupported = null, $localDatastoreSupported = null, $vmfsExtentExpansionSupported = null) {
		$this->nfsMountCreationRequired = $nfsMountCreationRequired;
		$this->nfsMountCreationSupported = $nfsMountCreationSupported;
		$this->localDatastoreSupported = $localDatastoreSupported;
		$this->vmfsExtentExpansionSupported = $vmfsExtentExpansionSupported;
	}
}

class VmfsDatastoreInfo extends phpDynamicProperties {
	public $vmfs; //HostVmfsVolume

	function __construct($vmfs = null) {
		$this->vmfs = $vmfs;
	}
}

class NasDatastoreInfo extends phpDynamicProperties {
	public $nas; //HostNasVolume

	function __construct($nas = null) {
		$this->nas = $nas;
	}
}

class LocalDatastoreInfo extends phpDynamicProperties {
	public $path; //string

	function __construct($path = null) {
		$this->path = $path;
	}
}

class VmfsDatastoreSpec extends phpDynamicProperties {
	public $diskUuid; //string

	function __construct($diskUuid = null) {
		$this->diskUuid = $diskUuid;
	}
}

class VmfsDatastoreCreateSpec extends phpDynamicProperties {
	public $partition; //HostDiskPartitionSpec
	public $vmfs; //HostVmfsSpec
	public $extent; //HostScsiDiskPartition

	function __construct($partition = null, $vmfs = null, $extent = null) {
		$this->partition = $partition;
		$this->vmfs = $vmfs;
		$this->extent = $extent;
	}
}

class VmfsDatastoreExtendSpec extends phpDynamicProperties {
	public $partition; //HostDiskPartitionSpec
	public $extent; //HostScsiDiskPartition

	function __construct($partition = null, $extent = null) {
		$this->partition = $partition;
		$this->extent = $extent;
	}
}

class VmfsDatastoreExpandSpec extends phpDynamicProperties {
	public $partition; //HostDiskPartitionSpec
	public $extent; //HostScsiDiskPartition

	function __construct($partition = null, $extent = null) {
		$this->partition = $partition;
		$this->extent = $extent;
	}
}

class VmfsDatastoreBaseOption extends phpDynamicProperties {
	public $layout; //HostDiskPartitionLayout
	public $partitionFormatChange; //boolean

	function __construct($layout = null, $partitionFormatChange = null) {
		$this->layout = $layout;
		$this->partitionFormatChange = $partitionFormatChange;
	}
}

class VmfsDatastoreSingleExtentOption extends phpDynamicProperties {
	public $vmfsExtent; //HostDiskPartitionBlockRange

	function __construct($vmfsExtent = null) {
		$this->vmfsExtent = $vmfsExtent;
	}
}

class VmfsDatastoreAllExtentOption extends phpDynamicProperties {
}

class VmfsDatastoreMultipleExtentOption extends phpDynamicProperties {
	public $vmfsExtent; //HostDiskPartitionBlockRange

	function __construct($vmfsExtent = null) {
		$this->vmfsExtent = $vmfsExtent;
	}
}

class VmfsDatastoreOption extends phpDynamicProperties {
	public $info; //VmfsDatastoreBaseOption
	public $spec; //VmfsDatastoreSpec

	function __construct($info = null, $spec = null) {
		$this->info = $info;
		$this->spec = $spec;
	}
}

class ArrayOfVmfsDatastoreOption extends phpDynamicProperties {
	public $VmfsDatastoreOption; //VmfsDatastoreOption

	function __construct($VmfsDatastoreOption = null) {
		$this->VmfsDatastoreOption = $VmfsDatastoreOption;
	}
}

class HostDateTimeConfig extends phpDynamicProperties {
	public $timeZone; //string
	public $ntpConfig; //HostNtpConfig

	function __construct($timeZone = null, $ntpConfig = null) {
		$this->timeZone = $timeZone;
		$this->ntpConfig = $ntpConfig;
	}
}

class HostDateTimeInfo extends phpDynamicProperties {
	public $timeZone; //HostDateTimeSystemTimeZone
	public $ntpConfig; //HostNtpConfig

	function __construct($timeZone = null, $ntpConfig = null) {
		$this->timeZone = $timeZone;
		$this->ntpConfig = $ntpConfig;
	}
}

class HostDateTimeSystemTimeZone extends phpDynamicProperties {
	public $key; //string
	public $name; //string
	public $description; //string
	public $gmtOffset; //int

	function __construct($key = null, $name = null, $description = null, $gmtOffset = null) {
		$this->key = $key;
		$this->name = $name;
		$this->description = $description;
		$this->gmtOffset = $gmtOffset;
	}
}

class ArrayOfHostDateTimeSystemTimeZone extends phpDynamicProperties {
	public $HostDateTimeSystemTimeZone; //HostDateTimeSystemTimeZone

	function __construct($HostDateTimeSystemTimeZone = null) {
		$this->HostDateTimeSystemTimeZone = $HostDateTimeSystemTimeZone;
	}
}

class HostDevice extends phpDynamicProperties {
	public $deviceName; //string
	public $deviceType; //string

	function __construct($deviceName = null, $deviceType = null) {
		$this->deviceName = $deviceName;
		$this->deviceType = $deviceType;
	}
}

class HostDhcpServiceSpec extends phpDynamicProperties {
	public $virtualSwitch; //string
	public $defaultLeaseDuration; //int
	public $leaseBeginIp; //string
	public $leaseEndIp; //string
	public $maxLeaseDuration; //int
	public $unlimitedLease; //boolean
	public $ipSubnetAddr; //string
	public $ipSubnetMask; //string

	function __construct($virtualSwitch = null, $defaultLeaseDuration = null, $leaseBeginIp = null, $leaseEndIp = null, $maxLeaseDuration = null, $unlimitedLease = null, $ipSubnetAddr = null, $ipSubnetMask = null) {
		$this->virtualSwitch = $virtualSwitch;
		$this->defaultLeaseDuration = $defaultLeaseDuration;
		$this->leaseBeginIp = $leaseBeginIp;
		$this->leaseEndIp = $leaseEndIp;
		$this->maxLeaseDuration = $maxLeaseDuration;
		$this->unlimitedLease = $unlimitedLease;
		$this->ipSubnetAddr = $ipSubnetAddr;
		$this->ipSubnetMask = $ipSubnetMask;
	}
}

class HostDhcpServiceConfig extends phpDynamicProperties {
	public $changeOperation; //string
	public $key; //string
	public $spec; //HostDhcpServiceSpec

	function __construct($changeOperation = null, $key = null, $spec = null) {
		$this->changeOperation = $changeOperation;
		$this->key = $key;
		$this->spec = $spec;
	}
}

class ArrayOfHostDhcpServiceConfig extends phpDynamicProperties {
	public $HostDhcpServiceConfig; //HostDhcpServiceConfig

	function __construct($HostDhcpServiceConfig = null) {
		$this->HostDhcpServiceConfig = $HostDhcpServiceConfig;
	}
}

class HostDhcpService extends phpDynamicProperties {
	public $key; //string
	public $spec; //HostDhcpServiceSpec

	function __construct($key = null, $spec = null) {
		$this->key = $key;
		$this->spec = $spec;
	}
}

class ArrayOfHostDhcpService extends phpDynamicProperties {
	public $HostDhcpService; //HostDhcpService

	function __construct($HostDhcpService = null) {
		$this->HostDhcpService = $HostDhcpService;
	}
}

class HostDiagnosticPartitionCreateOption extends phpDynamicProperties {
	public $storageType; //string
	public $diagnosticType; //string
	public $disk; //HostScsiDisk

	function __construct($storageType = null, $diagnosticType = null, $disk = null) {
		$this->storageType = $storageType;
		$this->diagnosticType = $diagnosticType;
		$this->disk = $disk;
	}
}

class ArrayOfHostDiagnosticPartitionCreateOption extends phpDynamicProperties {
	public $HostDiagnosticPartitionCreateOption; //HostDiagnosticPartitionCreateOption

	function __construct($HostDiagnosticPartitionCreateOption = null) {
		$this->HostDiagnosticPartitionCreateOption = $HostDiagnosticPartitionCreateOption;
	}
}

class HostDiagnosticPartitionCreateSpec extends phpDynamicProperties {
	public $storageType; //string
	public $diagnosticType; //string
	public $id; //HostScsiDiskPartition
	public $partition; //HostDiskPartitionSpec
	public $active; //boolean

	function __construct($storageType = null, $diagnosticType = null, $id = null, $partition = null, $active = null) {
		$this->storageType = $storageType;
		$this->diagnosticType = $diagnosticType;
		$this->id = $id;
		$this->partition = $partition;
		$this->active = $active;
	}
}

class HostDiagnosticPartitionCreateDescription extends phpDynamicProperties {
	public $layout; //HostDiskPartitionLayout
	public $diskUuid; //string
	public $spec; //HostDiagnosticPartitionCreateSpec

	function __construct($layout = null, $diskUuid = null, $spec = null) {
		$this->layout = $layout;
		$this->diskUuid = $diskUuid;
		$this->spec = $spec;
	}
}

class HostDiagnosticPartition extends phpDynamicProperties {
	public $storageType; //string
	public $diagnosticType; //string
	public $slots; //int
	public $id; //HostScsiDiskPartition

	function __construct($storageType = null, $diagnosticType = null, $slots = null, $id = null) {
		$this->storageType = $storageType;
		$this->diagnosticType = $diagnosticType;
		$this->slots = $slots;
		$this->id = $id;
	}
}

class ArrayOfHostDiagnosticPartition extends phpDynamicProperties {
	public $HostDiagnosticPartition; //HostDiagnosticPartition

	function __construct($HostDiagnosticPartition = null) {
		$this->HostDiagnosticPartition = $HostDiagnosticPartition;
	}
}

class HostDirectoryStoreInfo extends phpDynamicProperties {
}

class HostDiskDimensionsChs extends phpDynamicProperties {
	public $cylinder; //long
	public $head; //int
	public $sector; //int

	function __construct($cylinder = null, $head = null, $sector = null) {
		$this->cylinder = $cylinder;
		$this->head = $head;
		$this->sector = $sector;
	}
}

class HostDiskDimensionsLba extends phpDynamicProperties {
	public $blockSize; //int
	public $block; //long

	function __construct($blockSize = null, $block = null) {
		$this->blockSize = $blockSize;
		$this->block = $block;
	}
}

class HostDiskDimensions extends phpDynamicProperties {
}

class HostDiskPartitionAttributes extends phpDynamicProperties {
	public $partition; //int
	public $startSector; //long
	public $endSector; //long
	public $type; //string
	public $guid; //string
	public $logical; //boolean
	public $attributes; //byte
	public $partitionAlignment; //long

	function __construct($partition = null, $startSector = null, $endSector = null, $type = null, $guid = null, $logical = null, $attributes = null, $partitionAlignment = null) {
		$this->partition = $partition;
		$this->startSector = $startSector;
		$this->endSector = $endSector;
		$this->type = $type;
		$this->guid = $guid;
		$this->logical = $logical;
		$this->attributes = $attributes;
		$this->partitionAlignment = $partitionAlignment;
	}
}

class ArrayOfHostDiskPartitionAttributes extends phpDynamicProperties {
	public $HostDiskPartitionAttributes; //HostDiskPartitionAttributes

	function __construct($HostDiskPartitionAttributes = null) {
		$this->HostDiskPartitionAttributes = $HostDiskPartitionAttributes;
	}
}

class HostDiskPartitionBlockRange extends phpDynamicProperties {
	public $partition; //int
	public $type; //string
	public $start; //HostDiskDimensionsLba
	public $end; //HostDiskDimensionsLba

	function __construct($partition = null, $type = null, $start = null, $end = null) {
		$this->partition = $partition;
		$this->type = $type;
		$this->start = $start;
		$this->end = $end;
	}
}

class ArrayOfHostDiskPartitionBlockRange extends phpDynamicProperties {
	public $HostDiskPartitionBlockRange; //HostDiskPartitionBlockRange

	function __construct($HostDiskPartitionBlockRange = null) {
		$this->HostDiskPartitionBlockRange = $HostDiskPartitionBlockRange;
	}
}

class HostDiskPartitionSpec extends phpDynamicProperties {
	public $partitionFormat; //string
	public $chs; //HostDiskDimensionsChs
	public $totalSectors; //long
	public $partition; //HostDiskPartitionAttributes

	function __construct($partitionFormat = null, $chs = null, $totalSectors = null, $partition = null) {
		$this->partitionFormat = $partitionFormat;
		$this->chs = $chs;
		$this->totalSectors = $totalSectors;
		$this->partition = $partition;
	}
}

class HostDiskPartitionLayout extends phpDynamicProperties {
	public $total; //HostDiskDimensionsLba
	public $partition; //HostDiskPartitionBlockRange

	function __construct($total = null, $partition = null) {
		$this->total = $total;
		$this->partition = $partition;
	}
}

class HostDiskPartitionInfo extends phpDynamicProperties {
	public $deviceName; //string
	public $spec; //HostDiskPartitionSpec
	public $layout; //HostDiskPartitionLayout

	function __construct($deviceName = null, $spec = null, $layout = null) {
		$this->deviceName = $deviceName;
		$this->spec = $spec;
		$this->layout = $layout;
	}
}

class ArrayOfHostDiskPartitionInfo extends phpDynamicProperties {
	public $HostDiskPartitionInfo; //HostDiskPartitionInfo

	function __construct($HostDiskPartitionInfo = null) {
		$this->HostDiskPartitionInfo = $HostDiskPartitionInfo;
	}
}

class HostDnsConfig extends phpDynamicProperties {
	public $dhcp; //boolean
	public $virtualNicDevice; //string
	public $hostName; //string
	public $domainName; //string
	public $address; //string
	public $searchDomain; //string

	function __construct($dhcp = null, $virtualNicDevice = null, $hostName = null, $domainName = null, $address = null, $searchDomain = null) {
		$this->dhcp = $dhcp;
		$this->virtualNicDevice = $virtualNicDevice;
		$this->hostName = $hostName;
		$this->domainName = $domainName;
		$this->address = $address;
		$this->searchDomain = $searchDomain;
	}
}

class HostDnsConfigSpec extends phpDynamicProperties {
	public $virtualNicConnection; //HostVirtualNicConnection

	function __construct($virtualNicConnection = null) {
		$this->virtualNicConnection = $virtualNicConnection;
	}
}

class HostEsxAgentHostManagerConfigInfo extends phpDynamicProperties {
	public $agentVmDatastore; //ManagedObjectReference
	public $agentVmNetwork; //ManagedObjectReference

	function __construct($agentVmDatastore = null, $agentVmNetwork = null) {
		$this->agentVmDatastore = $agentVmDatastore;
		$this->agentVmNetwork = $agentVmNetwork;
	}
}

class FcoeConfigVlanRange extends phpDynamicProperties {
	public $vlanLow; //int
	public $vlanHigh; //int

	function __construct($vlanLow = null, $vlanHigh = null) {
		$this->vlanLow = $vlanLow;
		$this->vlanHigh = $vlanHigh;
	}
}

class ArrayOfFcoeConfigVlanRange extends phpDynamicProperties {
	public $FcoeConfigVlanRange; //FcoeConfigVlanRange

	function __construct($FcoeConfigVlanRange = null) {
		$this->FcoeConfigVlanRange = $FcoeConfigVlanRange;
	}
}

class FcoeConfigFcoeCapabilities extends phpDynamicProperties {
	public $priorityClass; //boolean
	public $sourceMacAddress; //boolean
	public $vlanRange; //boolean

	function __construct($priorityClass = null, $sourceMacAddress = null, $vlanRange = null) {
		$this->priorityClass = $priorityClass;
		$this->sourceMacAddress = $sourceMacAddress;
		$this->vlanRange = $vlanRange;
	}
}

class FcoeConfigFcoeSpecification extends phpDynamicProperties {
	public $underlyingPnic; //string
	public $priorityClass; //int
	public $sourceMac; //string
	public $vlanRange; //FcoeConfigVlanRange

	function __construct($underlyingPnic = null, $priorityClass = null, $sourceMac = null, $vlanRange = null) {
		$this->underlyingPnic = $underlyingPnic;
		$this->priorityClass = $priorityClass;
		$this->sourceMac = $sourceMac;
		$this->vlanRange = $vlanRange;
	}
}

class FcoeConfig extends phpDynamicProperties {
	public $priorityClass; //int
	public $sourceMac; //string
	public $vlanRange; //FcoeConfigVlanRange
	public $capabilities; //FcoeConfigFcoeCapabilities
	public $fcoeActive; //boolean

	function __construct($priorityClass = null, $sourceMac = null, $vlanRange = null, $capabilities = null, $fcoeActive = null) {
		$this->priorityClass = $priorityClass;
		$this->sourceMac = $sourceMac;
		$this->vlanRange = $vlanRange;
		$this->capabilities = $capabilities;
		$this->fcoeActive = $fcoeActive;
	}
}

class HostFeatureVersionInfo extends phpDynamicProperties {
	public $key; //string
	public $value; //string

	function __construct($key = null, $value = null) {
		$this->key = $key;
		$this->value = $value;
	}
}

class ArrayOfHostFeatureVersionInfo extends phpDynamicProperties {
	public $HostFeatureVersionInfo; //HostFeatureVersionInfo

	function __construct($HostFeatureVersionInfo = null) {
		$this->HostFeatureVersionInfo = $HostFeatureVersionInfo;
	}
}

class ModeInfo extends phpDynamicProperties {
	public $browse; //string
	public $read; //string
	public $modify; //string
	public $use; //string
	public $admin; //string
	public $full; //string

	function __construct($browse = null, $read = null, $modify = null, $use = null, $admin = null, $full = null) {
		$this->browse = $browse;
		$this->read = $read;
		$this->modify = $modify;
		$this->use = $use;
		$this->admin = $admin;
		$this->full = $full;
	}
}

class HostFileAccess extends phpDynamicProperties {
	public $who; //string
	public $what; //string

	function __construct($who = null, $what = null) {
		$this->who = $who;
		$this->what = $what;
	}
}

class HostFileSystemVolumeInfo extends phpDynamicProperties {
	public $volumeTypeList; //string
	public $mountInfo; //HostFileSystemMountInfo

	function __construct($volumeTypeList = null, $mountInfo = null) {
		$this->volumeTypeList = $volumeTypeList;
		$this->mountInfo = $mountInfo;
	}
}

class HostFileSystemMountInfo extends phpDynamicProperties {
	public $mountInfo; //HostMountInfo
	public $volume; //HostFileSystemVolume
	public $vStorageSupport; //string

	function __construct($mountInfo = null, $volume = null, $vStorageSupport = null) {
		$this->mountInfo = $mountInfo;
		$this->volume = $volume;
		$this->vStorageSupport = $vStorageSupport;
	}
}

class ArrayOfHostFileSystemMountInfo extends phpDynamicProperties {
	public $HostFileSystemMountInfo; //HostFileSystemMountInfo

	function __construct($HostFileSystemMountInfo = null) {
		$this->HostFileSystemMountInfo = $HostFileSystemMountInfo;
	}
}

class HostFileSystemVolume extends phpDynamicProperties {
	public $type; //string
	public $name; //string
	public $capacity; //long

	function __construct($type = null, $name = null, $capacity = null) {
		$this->type = $type;
		$this->name = $name;
		$this->capacity = $capacity;
	}
}

class HostNasVolumeSpec extends phpDynamicProperties {
	public $remoteHost; //string
	public $remotePath; //string
	public $localPath; //string
	public $accessMode; //string
	public $type; //string
	public $userName; //string
	public $password; //string

	function __construct($remoteHost = null, $remotePath = null, $localPath = null, $accessMode = null, $type = null, $userName = null, $password = null) {
		$this->remoteHost = $remoteHost;
		$this->remotePath = $remotePath;
		$this->localPath = $localPath;
		$this->accessMode = $accessMode;
		$this->type = $type;
		$this->userName = $userName;
		$this->password = $password;
	}
}

class HostNasVolumeConfig extends phpDynamicProperties {
	public $changeOperation; //string
	public $spec; //HostNasVolumeSpec

	function __construct($changeOperation = null, $spec = null) {
		$this->changeOperation = $changeOperation;
		$this->spec = $spec;
	}
}

class ArrayOfHostNasVolumeConfig extends phpDynamicProperties {
	public $HostNasVolumeConfig; //HostNasVolumeConfig

	function __construct($HostNasVolumeConfig = null) {
		$this->HostNasVolumeConfig = $HostNasVolumeConfig;
	}
}

class HostNasVolume extends phpDynamicProperties {
	public $remoteHost; //string
	public $remotePath; //string
	public $userName; //string

	function __construct($remoteHost = null, $remotePath = null, $userName = null) {
		$this->remoteHost = $remoteHost;
		$this->remotePath = $remotePath;
		$this->userName = $userName;
	}
}

class HostLocalFileSystemVolumeSpec extends phpDynamicProperties {
	public $device; //string
	public $localPath; //string

	function __construct($device = null, $localPath = null) {
		$this->device = $device;
		$this->localPath = $localPath;
	}
}

class HostLocalFileSystemVolume extends phpDynamicProperties {
	public $device; //string

	function __construct($device = null) {
		$this->device = $device;
	}
}

class HostVfatVolume extends phpDynamicProperties {
}

class HostFirewallConfigRuleSetConfig extends phpDynamicProperties {
	public $rulesetId; //string
	public $enabled; //boolean
	public $allowedHosts; //HostFirewallRulesetIpList

	function __construct($rulesetId = null, $enabled = null, $allowedHosts = null) {
		$this->rulesetId = $rulesetId;
		$this->enabled = $enabled;
		$this->allowedHosts = $allowedHosts;
	}
}

class ArrayOfHostFirewallConfigRuleSetConfig extends phpDynamicProperties {
	public $HostFirewallConfigRuleSetConfig; //HostFirewallConfigRuleSetConfig

	function __construct($HostFirewallConfigRuleSetConfig = null) {
		$this->HostFirewallConfigRuleSetConfig = $HostFirewallConfigRuleSetConfig;
	}
}

class HostFirewallConfig extends phpDynamicProperties {
	public $rule; //HostFirewallConfigRuleSetConfig
	public $defaultBlockingPolicy; //HostFirewallDefaultPolicy

	function __construct($rule = null, $defaultBlockingPolicy = null) {
		$this->rule = $rule;
		$this->defaultBlockingPolicy = $defaultBlockingPolicy;
	}
}

class HostFirewallDefaultPolicy extends phpDynamicProperties {
	public $incomingBlocked; //boolean
	public $outgoingBlocked; //boolean

	function __construct($incomingBlocked = null, $outgoingBlocked = null) {
		$this->incomingBlocked = $incomingBlocked;
		$this->outgoingBlocked = $outgoingBlocked;
	}
}

class HostFirewallInfo extends phpDynamicProperties {
	public $defaultPolicy; //HostFirewallDefaultPolicy
	public $ruleset; //HostFirewallRuleset

	function __construct($defaultPolicy = null, $ruleset = null) {
		$this->defaultPolicy = $defaultPolicy;
		$this->ruleset = $ruleset;
	}
}

class HostFlagInfo extends phpDynamicProperties {
	public $backgroundSnapshotsEnabled; //boolean

	function __construct($backgroundSnapshotsEnabled = null) {
		$this->backgroundSnapshotsEnabled = $backgroundSnapshotsEnabled;
	}
}

class HostForceMountedInfo extends phpDynamicProperties {
	public $persist; //boolean
	public $mounted; //boolean

	function __construct($persist = null, $mounted = null) {
		$this->persist = $persist;
		$this->mounted = $mounted;
	}
}

class HostHardwareInfo extends phpDynamicProperties {
	public $systemInfo; //HostSystemInfo
	public $cpuPowerManagementInfo; //HostCpuPowerManagementInfo
	public $cpuInfo; //HostCpuInfo
	public $cpuPkg; //HostCpuPackage
	public $memorySize; //long
	public $numaInfo; //HostNumaInfo
	public $smcPresent; //boolean
	public $pciDevice; //HostPciDevice
	public $cpuFeature; //HostCpuIdInfo
	public $biosInfo; //HostBIOSInfo

	function __construct($systemInfo = null, $cpuPowerManagementInfo = null, $cpuInfo = null, $cpuPkg = null, $memorySize = null, $numaInfo = null, $smcPresent = null, $pciDevice = null, $cpuFeature = null, $biosInfo = null) {
		$this->systemInfo = $systemInfo;
		$this->cpuPowerManagementInfo = $cpuPowerManagementInfo;
		$this->cpuInfo = $cpuInfo;
		$this->cpuPkg = $cpuPkg;
		$this->memorySize = $memorySize;
		$this->numaInfo = $numaInfo;
		$this->smcPresent = $smcPresent;
		$this->pciDevice = $pciDevice;
		$this->cpuFeature = $cpuFeature;
		$this->biosInfo = $biosInfo;
	}
}

class HostSystemInfo extends phpDynamicProperties {
	public $vendor; //string
	public $model; //string
	public $uuid; //string
	public $otherIdentifyingInfo; //HostSystemIdentificationInfo

	function __construct($vendor = null, $model = null, $uuid = null, $otherIdentifyingInfo = null) {
		$this->vendor = $vendor;
		$this->model = $model;
		$this->uuid = $uuid;
		$this->otherIdentifyingInfo = $otherIdentifyingInfo;
	}
}

class HostCpuPowerManagementInfo extends phpDynamicProperties {
	public $currentPolicy; //string
	public $hardwareSupport; //string

	function __construct($currentPolicy = null, $hardwareSupport = null) {
		$this->currentPolicy = $currentPolicy;
		$this->hardwareSupport = $hardwareSupport;
	}
}

class HostCpuInfo extends phpDynamicProperties {
	public $numCpuPackages; //short
	public $numCpuCores; //short
	public $numCpuThreads; //short
	public $hz; //long

	function __construct($numCpuPackages = null, $numCpuCores = null, $numCpuThreads = null, $hz = null) {
		$this->numCpuPackages = $numCpuPackages;
		$this->numCpuCores = $numCpuCores;
		$this->numCpuThreads = $numCpuThreads;
		$this->hz = $hz;
	}
}

class HostCpuPackage extends phpDynamicProperties {
	public $index; //short
	public $vendor; //string
	public $hz; //long
	public $busHz; //long
	public $description; //string
	public $threadId; //short
	public $cpuFeature; //HostCpuIdInfo

	function __construct($index = null, $vendor = null, $hz = null, $busHz = null, $description = null, $threadId = null, $cpuFeature = null) {
		$this->index = $index;
		$this->vendor = $vendor;
		$this->hz = $hz;
		$this->busHz = $busHz;
		$this->description = $description;
		$this->threadId = $threadId;
		$this->cpuFeature = $cpuFeature;
	}
}

class ArrayOfHostCpuPackage extends phpDynamicProperties {
	public $HostCpuPackage; //HostCpuPackage

	function __construct($HostCpuPackage = null) {
		$this->HostCpuPackage = $HostCpuPackage;
	}
}

class HostNumaInfo extends phpDynamicProperties {
	public $type; //string
	public $numNodes; //int
	public $numaNode; //HostNumaNode

	function __construct($type = null, $numNodes = null, $numaNode = null) {
		$this->type = $type;
		$this->numNodes = $numNodes;
		$this->numaNode = $numaNode;
	}
}

class HostNumaNode extends phpDynamicProperties {
	public $typeId; //byte
	public $cpuID; //short
	public $memoryRangeBegin; //long
	public $memoryRangeLength; //long

	function __construct($typeId = null, $cpuID = null, $memoryRangeBegin = null, $memoryRangeLength = null) {
		$this->typeId = $typeId;
		$this->cpuID = $cpuID;
		$this->memoryRangeBegin = $memoryRangeBegin;
		$this->memoryRangeLength = $memoryRangeLength;
	}
}

class ArrayOfHostNumaNode extends phpDynamicProperties {
	public $HostNumaNode; //HostNumaNode

	function __construct($HostNumaNode = null) {
		$this->HostNumaNode = $HostNumaNode;
	}
}

class HostBIOSInfo extends phpDynamicProperties {
	public $biosVersion; //string
	public $releaseDate; //dateTime

	function __construct($biosVersion = null, $releaseDate = null) {
		$this->biosVersion = $biosVersion;
		$this->releaseDate = $releaseDate;
	}
}

class HostHardwareElementInfo extends phpDynamicProperties {
	public $name; //string
	public $status; //ElementDescription

	function __construct($name = null, $status = null) {
		$this->name = $name;
		$this->status = $status;
	}
}

class ArrayOfHostHardwareElementInfo extends phpDynamicProperties {
	public $HostHardwareElementInfo; //HostHardwareElementInfo

	function __construct($HostHardwareElementInfo = null) {
		$this->HostHardwareElementInfo = $HostHardwareElementInfo;
	}
}

class HostStorageOperationalInfo extends phpDynamicProperties {
	public $property; //string
	public $value; //string

	function __construct($property = null, $value = null) {
		$this->property = $property;
		$this->value = $value;
	}
}

class ArrayOfHostStorageOperationalInfo extends phpDynamicProperties {
	public $HostStorageOperationalInfo; //HostStorageOperationalInfo

	function __construct($HostStorageOperationalInfo = null) {
		$this->HostStorageOperationalInfo = $HostStorageOperationalInfo;
	}
}

class HostStorageElementInfo extends phpDynamicProperties {
	public $operationalInfo; //HostStorageOperationalInfo

	function __construct($operationalInfo = null) {
		$this->operationalInfo = $operationalInfo;
	}
}

class ArrayOfHostStorageElementInfo extends phpDynamicProperties {
	public $HostStorageElementInfo; //HostStorageElementInfo

	function __construct($HostStorageElementInfo = null) {
		$this->HostStorageElementInfo = $HostStorageElementInfo;
	}
}

class HostHardwareStatusInfo extends phpDynamicProperties {
	public $memoryStatusInfo; //HostHardwareElementInfo
	public $cpuStatusInfo; //HostHardwareElementInfo
	public $storageStatusInfo; //HostStorageElementInfo

	function __construct($memoryStatusInfo = null, $cpuStatusInfo = null, $storageStatusInfo = null) {
		$this->memoryStatusInfo = $memoryStatusInfo;
		$this->cpuStatusInfo = $cpuStatusInfo;
		$this->storageStatusInfo = $storageStatusInfo;
	}
}

class HealthSystemRuntime extends phpDynamicProperties {
	public $systemHealthInfo; //HostSystemHealthInfo
	public $hardwareStatusInfo; //HostHardwareStatusInfo

	function __construct($systemHealthInfo = null, $hardwareStatusInfo = null) {
		$this->systemHealthInfo = $systemHealthInfo;
		$this->hardwareStatusInfo = $hardwareStatusInfo;
	}
}

class HostHostBusAdapter extends phpDynamicProperties {
	public $key; //string
	public $device; //string
	public $bus; //int
	public $status; //string
	public $model; //string
	public $driver; //string
	public $pci; //string

	function __construct($key = null, $device = null, $bus = null, $status = null, $model = null, $driver = null, $pci = null) {
		$this->key = $key;
		$this->device = $device;
		$this->bus = $bus;
		$this->status = $status;
		$this->model = $model;
		$this->driver = $driver;
		$this->pci = $pci;
	}
}

class ArrayOfHostHostBusAdapter extends phpDynamicProperties {
	public $HostHostBusAdapter; //HostHostBusAdapter

	function __construct($HostHostBusAdapter = null) {
		$this->HostHostBusAdapter = $HostHostBusAdapter;
	}
}

class HostParallelScsiHba extends phpDynamicProperties {
}

class HostBlockHba extends phpDynamicProperties {
}

class HostFibreChannelHba extends phpDynamicProperties {
	public $portWorldWideName; //long
	public $nodeWorldWideName; //long
	public $portType; //FibreChannelPortType
	public $speed; //long

	function __construct($portWorldWideName = null, $nodeWorldWideName = null, $portType = null, $speed = null) {
		$this->portWorldWideName = $portWorldWideName;
		$this->nodeWorldWideName = $nodeWorldWideName;
		$this->portType = $portType;
		$this->speed = $speed;
	}
}

class HostInternetScsiHbaParamValue extends phpDynamicProperties {
	public $isInherited; //boolean

	function __construct($isInherited = null) {
		$this->isInherited = $isInherited;
	}
}

class ArrayOfHostInternetScsiHbaParamValue extends phpDynamicProperties {
	public $HostInternetScsiHbaParamValue; //HostInternetScsiHbaParamValue

	function __construct($HostInternetScsiHbaParamValue = null) {
		$this->HostInternetScsiHbaParamValue = $HostInternetScsiHbaParamValue;
	}
}

class HostInternetScsiHbaDiscoveryCapabilities extends phpDynamicProperties {
	public $iSnsDiscoverySettable; //boolean
	public $slpDiscoverySettable; //boolean
	public $staticTargetDiscoverySettable; //boolean
	public $sendTargetsDiscoverySettable; //boolean

	function __construct($iSnsDiscoverySettable = null, $slpDiscoverySettable = null, $staticTargetDiscoverySettable = null, $sendTargetsDiscoverySettable = null) {
		$this->iSnsDiscoverySettable = $iSnsDiscoverySettable;
		$this->slpDiscoverySettable = $slpDiscoverySettable;
		$this->staticTargetDiscoverySettable = $staticTargetDiscoverySettable;
		$this->sendTargetsDiscoverySettable = $sendTargetsDiscoverySettable;
	}
}

class HostInternetScsiHbaDiscoveryProperties extends phpDynamicProperties {
	public $iSnsDiscoveryEnabled; //boolean
	public $iSnsDiscoveryMethod; //string
	public $iSnsHost; //string
	public $slpDiscoveryEnabled; //boolean
	public $slpDiscoveryMethod; //string
	public $slpHost; //string
	public $staticTargetDiscoveryEnabled; //boolean
	public $sendTargetsDiscoveryEnabled; //boolean

	function __construct($iSnsDiscoveryEnabled = null, $iSnsDiscoveryMethod = null, $iSnsHost = null, $slpDiscoveryEnabled = null, $slpDiscoveryMethod = null, $slpHost = null, $staticTargetDiscoveryEnabled = null, $sendTargetsDiscoveryEnabled = null) {
		$this->iSnsDiscoveryEnabled = $iSnsDiscoveryEnabled;
		$this->iSnsDiscoveryMethod = $iSnsDiscoveryMethod;
		$this->iSnsHost = $iSnsHost;
		$this->slpDiscoveryEnabled = $slpDiscoveryEnabled;
		$this->slpDiscoveryMethod = $slpDiscoveryMethod;
		$this->slpHost = $slpHost;
		$this->staticTargetDiscoveryEnabled = $staticTargetDiscoveryEnabled;
		$this->sendTargetsDiscoveryEnabled = $sendTargetsDiscoveryEnabled;
	}
}

class HostInternetScsiHbaAuthenticationCapabilities extends phpDynamicProperties {
	public $chapAuthSettable; //boolean
	public $krb5AuthSettable; //boolean
	public $srpAuthSettable; //boolean
	public $spkmAuthSettable; //boolean
	public $mutualChapSettable; //boolean
	public $targetChapSettable; //boolean
	public $targetMutualChapSettable; //boolean

	function __construct($chapAuthSettable = null, $krb5AuthSettable = null, $srpAuthSettable = null, $spkmAuthSettable = null, $mutualChapSettable = null, $targetChapSettable = null, $targetMutualChapSettable = null) {
		$this->chapAuthSettable = $chapAuthSettable;
		$this->krb5AuthSettable = $krb5AuthSettable;
		$this->srpAuthSettable = $srpAuthSettable;
		$this->spkmAuthSettable = $spkmAuthSettable;
		$this->mutualChapSettable = $mutualChapSettable;
		$this->targetChapSettable = $targetChapSettable;
		$this->targetMutualChapSettable = $targetMutualChapSettable;
	}
}

class HostInternetScsiHbaAuthenticationProperties extends phpDynamicProperties {
	public $chapAuthEnabled; //boolean
	public $chapName; //string
	public $chapSecret; //string
	public $chapAuthenticationType; //string
	public $chapInherited; //boolean
	public $mutualChapName; //string
	public $mutualChapSecret; //string
	public $mutualChapAuthenticationType; //string
	public $mutualChapInherited; //boolean

	function __construct($chapAuthEnabled = null, $chapName = null, $chapSecret = null, $chapAuthenticationType = null, $chapInherited = null, $mutualChapName = null, $mutualChapSecret = null, $mutualChapAuthenticationType = null, $mutualChapInherited = null) {
		$this->chapAuthEnabled = $chapAuthEnabled;
		$this->chapName = $chapName;
		$this->chapSecret = $chapSecret;
		$this->chapAuthenticationType = $chapAuthenticationType;
		$this->chapInherited = $chapInherited;
		$this->mutualChapName = $mutualChapName;
		$this->mutualChapSecret = $mutualChapSecret;
		$this->mutualChapAuthenticationType = $mutualChapAuthenticationType;
		$this->mutualChapInherited = $mutualChapInherited;
	}
}

class HostInternetScsiHbaDigestCapabilities extends phpDynamicProperties {
	public $headerDigestSettable; //boolean
	public $dataDigestSettable; //boolean
	public $targetHeaderDigestSettable; //boolean
	public $targetDataDigestSettable; //boolean

	function __construct($headerDigestSettable = null, $dataDigestSettable = null, $targetHeaderDigestSettable = null, $targetDataDigestSettable = null) {
		$this->headerDigestSettable = $headerDigestSettable;
		$this->dataDigestSettable = $dataDigestSettable;
		$this->targetHeaderDigestSettable = $targetHeaderDigestSettable;
		$this->targetDataDigestSettable = $targetDataDigestSettable;
	}
}

class HostInternetScsiHbaDigestProperties extends phpDynamicProperties {
	public $headerDigestType; //string
	public $headerDigestInherited; //boolean
	public $dataDigestType; //string
	public $dataDigestInherited; //boolean

	function __construct($headerDigestType = null, $headerDigestInherited = null, $dataDigestType = null, $dataDigestInherited = null) {
		$this->headerDigestType = $headerDigestType;
		$this->headerDigestInherited = $headerDigestInherited;
		$this->dataDigestType = $dataDigestType;
		$this->dataDigestInherited = $dataDigestInherited;
	}
}

class HostInternetScsiHbaIPCapabilities extends phpDynamicProperties {
	public $addressSettable; //boolean
	public $ipConfigurationMethodSettable; //boolean
	public $subnetMaskSettable; //boolean
	public $defaultGatewaySettable; //boolean
	public $primaryDnsServerAddressSettable; //boolean
	public $alternateDnsServerAddressSettable; //boolean
	public $ipv6Supported; //boolean
	public $arpRedirectSettable; //boolean
	public $mtuSettable; //boolean
	public $hostNameAsTargetAddress; //boolean
	public $nameAliasSettable; //boolean

	function __construct($addressSettable = null, $ipConfigurationMethodSettable = null, $subnetMaskSettable = null, $defaultGatewaySettable = null, $primaryDnsServerAddressSettable = null, $alternateDnsServerAddressSettable = null, $ipv6Supported = null, $arpRedirectSettable = null, $mtuSettable = null, $hostNameAsTargetAddress = null, $nameAliasSettable = null) {
		$this->addressSettable = $addressSettable;
		$this->ipConfigurationMethodSettable = $ipConfigurationMethodSettable;
		$this->subnetMaskSettable = $subnetMaskSettable;
		$this->defaultGatewaySettable = $defaultGatewaySettable;
		$this->primaryDnsServerAddressSettable = $primaryDnsServerAddressSettable;
		$this->alternateDnsServerAddressSettable = $alternateDnsServerAddressSettable;
		$this->ipv6Supported = $ipv6Supported;
		$this->arpRedirectSettable = $arpRedirectSettable;
		$this->mtuSettable = $mtuSettable;
		$this->hostNameAsTargetAddress = $hostNameAsTargetAddress;
		$this->nameAliasSettable = $nameAliasSettable;
	}
}

class HostInternetScsiHbaIPProperties extends phpDynamicProperties {
	public $mac; //string
	public $address; //string
	public $dhcpConfigurationEnabled; //boolean
	public $subnetMask; //string
	public $defaultGateway; //string
	public $primaryDnsServerAddress; //string
	public $alternateDnsServerAddress; //string
	public $ipv6Address; //string
	public $ipv6SubnetMask; //string
	public $ipv6DefaultGateway; //string
	public $arpRedirectEnabled; //boolean
	public $mtu; //int
	public $jumboFramesEnabled; //boolean

	function __construct($mac = null, $address = null, $dhcpConfigurationEnabled = null, $subnetMask = null, $defaultGateway = null, $primaryDnsServerAddress = null, $alternateDnsServerAddress = null, $ipv6Address = null, $ipv6SubnetMask = null, $ipv6DefaultGateway = null, $arpRedirectEnabled = null, $mtu = null, $jumboFramesEnabled = null) {
		$this->mac = $mac;
		$this->address = $address;
		$this->dhcpConfigurationEnabled = $dhcpConfigurationEnabled;
		$this->subnetMask = $subnetMask;
		$this->defaultGateway = $defaultGateway;
		$this->primaryDnsServerAddress = $primaryDnsServerAddress;
		$this->alternateDnsServerAddress = $alternateDnsServerAddress;
		$this->ipv6Address = $ipv6Address;
		$this->ipv6SubnetMask = $ipv6SubnetMask;
		$this->ipv6DefaultGateway = $ipv6DefaultGateway;
		$this->arpRedirectEnabled = $arpRedirectEnabled;
		$this->mtu = $mtu;
		$this->jumboFramesEnabled = $jumboFramesEnabled;
	}
}

class HostInternetScsiHbaSendTarget extends phpDynamicProperties {
	public $address; //string
	public $port; //int
	public $authenticationProperties; //HostInternetScsiHbaAuthenticationProperties
	public $digestProperties; //HostInternetScsiHbaDigestProperties
	public $supportedAdvancedOptions; //OptionDef
	public $advancedOptions; //HostInternetScsiHbaParamValue
	public $parent; //string

	function __construct($address = null, $port = null, $authenticationProperties = null, $digestProperties = null, $supportedAdvancedOptions = null, $advancedOptions = null, $parent = null) {
		$this->address = $address;
		$this->port = $port;
		$this->authenticationProperties = $authenticationProperties;
		$this->digestProperties = $digestProperties;
		$this->supportedAdvancedOptions = $supportedAdvancedOptions;
		$this->advancedOptions = $advancedOptions;
		$this->parent = $parent;
	}
}

class ArrayOfHostInternetScsiHbaSendTarget extends phpDynamicProperties {
	public $HostInternetScsiHbaSendTarget; //HostInternetScsiHbaSendTarget

	function __construct($HostInternetScsiHbaSendTarget = null) {
		$this->HostInternetScsiHbaSendTarget = $HostInternetScsiHbaSendTarget;
	}
}

class HostInternetScsiHbaStaticTarget extends phpDynamicProperties {
	public $address; //string
	public $port; //int
	public $iScsiName; //string
	public $authenticationProperties; //HostInternetScsiHbaAuthenticationProperties
	public $digestProperties; //HostInternetScsiHbaDigestProperties
	public $supportedAdvancedOptions; //OptionDef
	public $advancedOptions; //HostInternetScsiHbaParamValue
	public $parent; //string

	function __construct($address = null, $port = null, $iScsiName = null, $authenticationProperties = null, $digestProperties = null, $supportedAdvancedOptions = null, $advancedOptions = null, $parent = null) {
		$this->address = $address;
		$this->port = $port;
		$this->iScsiName = $iScsiName;
		$this->authenticationProperties = $authenticationProperties;
		$this->digestProperties = $digestProperties;
		$this->supportedAdvancedOptions = $supportedAdvancedOptions;
		$this->advancedOptions = $advancedOptions;
		$this->parent = $parent;
	}
}

class ArrayOfHostInternetScsiHbaStaticTarget extends phpDynamicProperties {
	public $HostInternetScsiHbaStaticTarget; //HostInternetScsiHbaStaticTarget

	function __construct($HostInternetScsiHbaStaticTarget = null) {
		$this->HostInternetScsiHbaStaticTarget = $HostInternetScsiHbaStaticTarget;
	}
}

class HostInternetScsiHbaTargetSet extends phpDynamicProperties {
	public $staticTargets; //HostInternetScsiHbaStaticTarget
	public $sendTargets; //HostInternetScsiHbaSendTarget

	function __construct($staticTargets = null, $sendTargets = null) {
		$this->staticTargets = $staticTargets;
		$this->sendTargets = $sendTargets;
	}
}

class HostInternetScsiHba extends phpDynamicProperties {
	public $isSoftwareBased; //boolean
	public $canBeDisabled; //boolean
	public $networkBindingSupport; //HostInternetScsiHbaNetworkBindingSupportType
	public $discoveryCapabilities; //HostInternetScsiHbaDiscoveryCapabilities
	public $discoveryProperties; //HostInternetScsiHbaDiscoveryProperties
	public $authenticationCapabilities; //HostInternetScsiHbaAuthenticationCapabilities
	public $authenticationProperties; //HostInternetScsiHbaAuthenticationProperties
	public $digestCapabilities; //HostInternetScsiHbaDigestCapabilities
	public $digestProperties; //HostInternetScsiHbaDigestProperties
	public $ipCapabilities; //HostInternetScsiHbaIPCapabilities
	public $ipProperties; //HostInternetScsiHbaIPProperties
	public $supportedAdvancedOptions; //OptionDef
	public $advancedOptions; //HostInternetScsiHbaParamValue
	public $iScsiName; //string
	public $iScsiAlias; //string
	public $configuredSendTarget; //HostInternetScsiHbaSendTarget
	public $configuredStaticTarget; //HostInternetScsiHbaStaticTarget
	public $maxSpeedMb; //int
	public $currentSpeedMb; //int

	function __construct($isSoftwareBased = null, $canBeDisabled = null, $networkBindingSupport = null, $discoveryCapabilities = null, $discoveryProperties = null, $authenticationCapabilities = null, $authenticationProperties = null, $digestCapabilities = null, $digestProperties = null, $ipCapabilities = null, $ipProperties = null, $supportedAdvancedOptions = null, $advancedOptions = null, $iScsiName = null, $iScsiAlias = null, $configuredSendTarget = null, $configuredStaticTarget = null, $maxSpeedMb = null, $currentSpeedMb = null) {
		$this->isSoftwareBased = $isSoftwareBased;
		$this->canBeDisabled = $canBeDisabled;
		$this->networkBindingSupport = $networkBindingSupport;
		$this->discoveryCapabilities = $discoveryCapabilities;
		$this->discoveryProperties = $discoveryProperties;
		$this->authenticationCapabilities = $authenticationCapabilities;
		$this->authenticationProperties = $authenticationProperties;
		$this->digestCapabilities = $digestCapabilities;
		$this->digestProperties = $digestProperties;
		$this->ipCapabilities = $ipCapabilities;
		$this->ipProperties = $ipProperties;
		$this->supportedAdvancedOptions = $supportedAdvancedOptions;
		$this->advancedOptions = $advancedOptions;
		$this->iScsiName = $iScsiName;
		$this->iScsiAlias = $iScsiAlias;
		$this->configuredSendTarget = $configuredSendTarget;
		$this->configuredStaticTarget = $configuredStaticTarget;
		$this->maxSpeedMb = $maxSpeedMb;
		$this->currentSpeedMb = $currentSpeedMb;
	}
}

class HostFibreChannelOverEthernetHbaLinkInfo extends phpDynamicProperties {
	public $vnportMac; //string
	public $fcfMac; //string
	public $vlanId; //int

	function __construct($vnportMac = null, $fcfMac = null, $vlanId = null) {
		$this->vnportMac = $vnportMac;
		$this->fcfMac = $fcfMac;
		$this->vlanId = $vlanId;
	}
}

class HostFibreChannelOverEthernetHba extends phpDynamicProperties {
	public $underlyingNic; //string
	public $linkInfo; //HostFibreChannelOverEthernetHbaLinkInfo
	public $isSoftwareFcoe; //boolean
	public $markedForRemoval; //boolean

	function __construct($underlyingNic = null, $linkInfo = null, $isSoftwareFcoe = null, $markedForRemoval = null) {
		$this->underlyingNic = $underlyingNic;
		$this->linkInfo = $linkInfo;
		$this->isSoftwareFcoe = $isSoftwareFcoe;
		$this->markedForRemoval = $markedForRemoval;
	}
}

class HostProxySwitchSpec extends phpDynamicProperties {
	public $backing; //DistributedVirtualSwitchHostMemberBacking

	function __construct($backing = null) {
		$this->backing = $backing;
	}
}

class HostProxySwitchConfig extends phpDynamicProperties {
	public $changeOperation; //string
	public $uuid; //string
	public $spec; //HostProxySwitchSpec

	function __construct($changeOperation = null, $uuid = null, $spec = null) {
		$this->changeOperation = $changeOperation;
		$this->uuid = $uuid;
		$this->spec = $spec;
	}
}

class ArrayOfHostProxySwitchConfig extends phpDynamicProperties {
	public $HostProxySwitchConfig; //HostProxySwitchConfig

	function __construct($HostProxySwitchConfig = null) {
		$this->HostProxySwitchConfig = $HostProxySwitchConfig;
	}
}

class HostProxySwitch extends phpDynamicProperties {
	public $dvsUuid; //string
	public $dvsName; //string
	public $key; //string
	public $numPorts; //int
	public $configNumPorts; //int
	public $numPortsAvailable; //int
	public $uplinkPort; //KeyValue
	public $mtu; //int
	public $pnic; //string
	public $spec; //HostProxySwitchSpec

	function __construct($dvsUuid = null, $dvsName = null, $key = null, $numPorts = null, $configNumPorts = null, $numPortsAvailable = null, $uplinkPort = null, $mtu = null, $pnic = null, $spec = null) {
		$this->dvsUuid = $dvsUuid;
		$this->dvsName = $dvsName;
		$this->key = $key;
		$this->numPorts = $numPorts;
		$this->configNumPorts = $configNumPorts;
		$this->numPortsAvailable = $numPortsAvailable;
		$this->uplinkPort = $uplinkPort;
		$this->mtu = $mtu;
		$this->pnic = $pnic;
		$this->spec = $spec;
	}
}

class ArrayOfHostProxySwitch extends phpDynamicProperties {
	public $HostProxySwitch; //HostProxySwitch

	function __construct($HostProxySwitch = null) {
		$this->HostProxySwitch = $HostProxySwitch;
	}
}

class HostImageProfileSummary extends phpDynamicProperties {
	public $name; //string
	public $vendor; //string

	function __construct($name = null, $vendor = null) {
		$this->name = $name;
		$this->vendor = $vendor;
	}
}

class HostIpConfigIpV6Address extends phpDynamicProperties {
	public $ipAddress; //string
	public $prefixLength; //int
	public $origin; //string
	public $dadState; //string
	public $lifetime; //dateTime
	public $operation; //string

	function __construct($ipAddress = null, $prefixLength = null, $origin = null, $dadState = null, $lifetime = null, $operation = null) {
		$this->ipAddress = $ipAddress;
		$this->prefixLength = $prefixLength;
		$this->origin = $origin;
		$this->dadState = $dadState;
		$this->lifetime = $lifetime;
		$this->operation = $operation;
	}
}

class ArrayOfHostIpConfigIpV6Address extends phpDynamicProperties {
	public $HostIpConfigIpV6Address; //HostIpConfigIpV6Address

	function __construct($HostIpConfigIpV6Address = null) {
		$this->HostIpConfigIpV6Address = $HostIpConfigIpV6Address;
	}
}

class HostIpConfigIpV6AddressConfiguration extends phpDynamicProperties {
	public $ipV6Address; //HostIpConfigIpV6Address
	public $autoConfigurationEnabled; //boolean
	public $dhcpV6Enabled; //boolean

	function __construct($ipV6Address = null, $autoConfigurationEnabled = null, $dhcpV6Enabled = null) {
		$this->ipV6Address = $ipV6Address;
		$this->autoConfigurationEnabled = $autoConfigurationEnabled;
		$this->dhcpV6Enabled = $dhcpV6Enabled;
	}
}

class HostIpConfig extends phpDynamicProperties {
	public $dhcp; //boolean
	public $ipAddress; //string
	public $subnetMask; //string
	public $ipV6Config; //HostIpConfigIpV6AddressConfiguration

	function __construct($dhcp = null, $ipAddress = null, $subnetMask = null, $ipV6Config = null) {
		$this->dhcp = $dhcp;
		$this->ipAddress = $ipAddress;
		$this->subnetMask = $subnetMask;
		$this->ipV6Config = $ipV6Config;
	}
}

class HostIpRouteConfig extends phpDynamicProperties {
	public $defaultGateway; //string
	public $gatewayDevice; //string
	public $ipV6DefaultGateway; //string
	public $ipV6GatewayDevice; //string

	function __construct($defaultGateway = null, $gatewayDevice = null, $ipV6DefaultGateway = null, $ipV6GatewayDevice = null) {
		$this->defaultGateway = $defaultGateway;
		$this->gatewayDevice = $gatewayDevice;
		$this->ipV6DefaultGateway = $ipV6DefaultGateway;
		$this->ipV6GatewayDevice = $ipV6GatewayDevice;
	}
}

class HostIpRouteConfigSpec extends phpDynamicProperties {
	public $gatewayDeviceConnection; //HostVirtualNicConnection
	public $ipV6GatewayDeviceConnection; //HostVirtualNicConnection

	function __construct($gatewayDeviceConnection = null, $ipV6GatewayDeviceConnection = null) {
		$this->gatewayDeviceConnection = $gatewayDeviceConnection;
		$this->ipV6GatewayDeviceConnection = $ipV6GatewayDeviceConnection;
	}
}

class HostIpRouteEntry extends phpDynamicProperties {
	public $network; //string
	public $prefixLength; //int
	public $gateway; //string
	public $deviceName; //string

	function __construct($network = null, $prefixLength = null, $gateway = null, $deviceName = null) {
		$this->network = $network;
		$this->prefixLength = $prefixLength;
		$this->gateway = $gateway;
		$this->deviceName = $deviceName;
	}
}

class ArrayOfHostIpRouteEntry extends phpDynamicProperties {
	public $HostIpRouteEntry; //HostIpRouteEntry

	function __construct($HostIpRouteEntry = null) {
		$this->HostIpRouteEntry = $HostIpRouteEntry;
	}
}

class HostIpRouteOp extends phpDynamicProperties {
	public $changeOperation; //string
	public $route; //HostIpRouteEntry

	function __construct($changeOperation = null, $route = null) {
		$this->changeOperation = $changeOperation;
		$this->route = $route;
	}
}

class ArrayOfHostIpRouteOp extends phpDynamicProperties {
	public $HostIpRouteOp; //HostIpRouteOp

	function __construct($HostIpRouteOp = null) {
		$this->HostIpRouteOp = $HostIpRouteOp;
	}
}

class HostIpRouteTableConfig extends phpDynamicProperties {
	public $ipRoute; //HostIpRouteOp
	public $ipv6Route; //HostIpRouteOp

	function __construct($ipRoute = null, $ipv6Route = null) {
		$this->ipRoute = $ipRoute;
		$this->ipv6Route = $ipv6Route;
	}
}

class HostIpRouteTableInfo extends phpDynamicProperties {
	public $ipRoute; //HostIpRouteEntry
	public $ipv6Route; //HostIpRouteEntry

	function __construct($ipRoute = null, $ipv6Route = null) {
		$this->ipRoute = $ipRoute;
		$this->ipv6Route = $ipv6Route;
	}
}

class HostIpmiInfo extends phpDynamicProperties {
	public $bmcIpAddress; //string
	public $bmcMacAddress; //string
	public $login; //string
	public $password; //string

	function __construct($bmcIpAddress = null, $bmcMacAddress = null, $login = null, $password = null) {
		$this->bmcIpAddress = $bmcIpAddress;
		$this->bmcMacAddress = $bmcMacAddress;
		$this->login = $login;
		$this->password = $password;
	}
}

class IscsiStatus extends phpDynamicProperties {
	public $reason; //LocalizedMethodFault

	function __construct($reason = null) {
		$this->reason = $reason;
	}
}

class IscsiPortInfo extends phpDynamicProperties {
	public $vnicDevice; //string
	public $vnic; //HostVirtualNic
	public $pnicDevice; //string
	public $pnic; //PhysicalNic
	public $switchName; //string
	public $switchUuid; //string
	public $portgroupName; //string
	public $portgroupKey; //string
	public $portKey; //string
	public $complianceStatus; //IscsiStatus
	public $pathStatus; //string

	function __construct($vnicDevice = null, $vnic = null, $pnicDevice = null, $pnic = null, $switchName = null, $switchUuid = null, $portgroupName = null, $portgroupKey = null, $portKey = null, $complianceStatus = null, $pathStatus = null) {
		$this->vnicDevice = $vnicDevice;
		$this->vnic = $vnic;
		$this->pnicDevice = $pnicDevice;
		$this->pnic = $pnic;
		$this->switchName = $switchName;
		$this->switchUuid = $switchUuid;
		$this->portgroupName = $portgroupName;
		$this->portgroupKey = $portgroupKey;
		$this->portKey = $portKey;
		$this->complianceStatus = $complianceStatus;
		$this->pathStatus = $pathStatus;
	}
}

class ArrayOfIscsiPortInfo extends phpDynamicProperties {
	public $IscsiPortInfo; //IscsiPortInfo

	function __construct($IscsiPortInfo = null) {
		$this->IscsiPortInfo = $IscsiPortInfo;
	}
}

class IscsiDependencyEntity extends phpDynamicProperties {
	public $pnicDevice; //string
	public $vnicDevice; //string
	public $vmhbaName; //string

	function __construct($pnicDevice = null, $vnicDevice = null, $vmhbaName = null) {
		$this->pnicDevice = $pnicDevice;
		$this->vnicDevice = $vnicDevice;
		$this->vmhbaName = $vmhbaName;
	}
}

class ArrayOfIscsiDependencyEntity extends phpDynamicProperties {
	public $IscsiDependencyEntity; //IscsiDependencyEntity

	function __construct($IscsiDependencyEntity = null) {
		$this->IscsiDependencyEntity = $IscsiDependencyEntity;
	}
}

class IscsiMigrationDependency extends phpDynamicProperties {
	public $migrationAllowed; //boolean
	public $disallowReason; //IscsiStatus
	public $dependency; //IscsiDependencyEntity

	function __construct($migrationAllowed = null, $disallowReason = null, $dependency = null) {
		$this->migrationAllowed = $migrationAllowed;
		$this->disallowReason = $disallowReason;
		$this->dependency = $dependency;
	}
}

class KernelModuleSectionInfo extends phpDynamicProperties {
	public $address; //long
	public $length; //int

	function __construct($address = null, $length = null) {
		$this->address = $address;
		$this->length = $length;
	}
}

class KernelModuleInfo extends phpDynamicProperties {
	public $id; //int
	public $name; //string
	public $version; //string
	public $filename; //string
	public $optionString; //string
	public $loaded; //boolean
	public $enabled; //boolean
	public $useCount; //int
	public $readOnlySection; //KernelModuleSectionInfo
	public $writableSection; //KernelModuleSectionInfo
	public $textSection; //KernelModuleSectionInfo
	public $dataSection; //KernelModuleSectionInfo
	public $bssSection; //KernelModuleSectionInfo

	function __construct($id = null, $name = null, $version = null, $filename = null, $optionString = null, $loaded = null, $enabled = null, $useCount = null, $readOnlySection = null, $writableSection = null, $textSection = null, $dataSection = null, $bssSection = null) {
		$this->id = $id;
		$this->name = $name;
		$this->version = $version;
		$this->filename = $filename;
		$this->optionString = $optionString;
		$this->loaded = $loaded;
		$this->enabled = $enabled;
		$this->useCount = $useCount;
		$this->readOnlySection = $readOnlySection;
		$this->writableSection = $writableSection;
		$this->textSection = $textSection;
		$this->dataSection = $dataSection;
		$this->bssSection = $bssSection;
	}
}

class ArrayOfKernelModuleInfo extends phpDynamicProperties {
	public $KernelModuleInfo; //KernelModuleInfo

	function __construct($KernelModuleInfo = null) {
		$this->KernelModuleInfo = $KernelModuleInfo;
	}
}

class HostLicenseSpec extends phpDynamicProperties {
	public $source; //LicenseSource
	public $editionKey; //string
	public $disabledFeatureKey; //string
	public $enabledFeatureKey; //string

	function __construct($source = null, $editionKey = null, $disabledFeatureKey = null, $enabledFeatureKey = null) {
		$this->source = $source;
		$this->editionKey = $editionKey;
		$this->disabledFeatureKey = $disabledFeatureKey;
		$this->enabledFeatureKey = $enabledFeatureKey;
	}
}

class LinkDiscoveryProtocolConfig extends phpDynamicProperties {
	public $protocol; //string
	public $operation; //string

	function __construct($protocol = null, $operation = null) {
		$this->protocol = $protocol;
		$this->operation = $operation;
	}
}

class HostAccountSpec extends phpDynamicProperties {
	public $id; //string
	public $password; //string
	public $description; //string

	function __construct($id = null, $password = null, $description = null) {
		$this->id = $id;
		$this->password = $password;
		$this->description = $description;
	}
}

class ArrayOfHostAccountSpec extends phpDynamicProperties {
	public $HostAccountSpec; //HostAccountSpec

	function __construct($HostAccountSpec = null) {
		$this->HostAccountSpec = $HostAccountSpec;
	}
}

class HostPosixAccountSpec extends phpDynamicProperties {
	public $posixId; //int
	public $shellAccess; //boolean

	function __construct($posixId = null, $shellAccess = null) {
		$this->posixId = $posixId;
		$this->shellAccess = $shellAccess;
	}
}

class HostLocalAuthenticationInfo extends phpDynamicProperties {
}

class HostLowLevelProvisioningManagerDiskLayoutSpec extends phpDynamicProperties {
	public $controllerType; //string
	public $busNumber; //int
	public $unitNumber; //int
	public $srcFilename; //string
	public $dstFilename; //string

	function __construct($controllerType = null, $busNumber = null, $unitNumber = null, $srcFilename = null, $dstFilename = null) {
		$this->controllerType = $controllerType;
		$this->busNumber = $busNumber;
		$this->unitNumber = $unitNumber;
		$this->srcFilename = $srcFilename;
		$this->dstFilename = $dstFilename;
	}
}

class ArrayOfHostLowLevelProvisioningManagerDiskLayoutSpec extends phpDynamicProperties {
	public $HostLowLevelProvisioningManagerDiskLayoutSpec; //HostLowLevelProvisioningManagerDiskLayoutSpec

	function __construct($HostLowLevelProvisioningManagerDiskLayoutSpec = null) {
		$this->HostLowLevelProvisioningManagerDiskLayoutSpec = $HostLowLevelProvisioningManagerDiskLayoutSpec;
	}
}

class HostLowLevelProvisioningManagerSnapshotLayoutSpec extends phpDynamicProperties {
	public $id; //int
	public $srcFilename; //string
	public $dstFilename; //string
	public $disk; //HostLowLevelProvisioningManagerDiskLayoutSpec

	function __construct($id = null, $srcFilename = null, $dstFilename = null, $disk = null) {
		$this->id = $id;
		$this->srcFilename = $srcFilename;
		$this->dstFilename = $dstFilename;
		$this->disk = $disk;
	}
}

class ArrayOfHostLowLevelProvisioningManagerSnapshotLayoutSpec extends phpDynamicProperties {
	public $HostLowLevelProvisioningManagerSnapshotLayoutSpec; //HostLowLevelProvisioningManagerSnapshotLayoutSpec

	function __construct($HostLowLevelProvisioningManagerSnapshotLayoutSpec = null) {
		$this->HostLowLevelProvisioningManagerSnapshotLayoutSpec = $HostLowLevelProvisioningManagerSnapshotLayoutSpec;
	}
}

class ServiceConsoleReservationInfo extends phpDynamicProperties {
	public $serviceConsoleReservedCfg; //long
	public $serviceConsoleReserved; //long
	public $unreserved; //long

	function __construct($serviceConsoleReservedCfg = null, $serviceConsoleReserved = null, $unreserved = null) {
		$this->serviceConsoleReservedCfg = $serviceConsoleReservedCfg;
		$this->serviceConsoleReserved = $serviceConsoleReserved;
		$this->unreserved = $unreserved;
	}
}

class VirtualMachineMemoryReservationInfo extends phpDynamicProperties {
	public $virtualMachineMin; //long
	public $virtualMachineMax; //long
	public $virtualMachineReserved; //long
	public $allocationPolicy; //string

	function __construct($virtualMachineMin = null, $virtualMachineMax = null, $virtualMachineReserved = null, $allocationPolicy = null) {
		$this->virtualMachineMin = $virtualMachineMin;
		$this->virtualMachineMax = $virtualMachineMax;
		$this->virtualMachineReserved = $virtualMachineReserved;
		$this->allocationPolicy = $allocationPolicy;
	}
}

class VirtualMachineMemoryReservationSpec extends phpDynamicProperties {
	public $virtualMachineReserved; //long
	public $allocationPolicy; //string

	function __construct($virtualMachineReserved = null, $allocationPolicy = null) {
		$this->virtualMachineReserved = $virtualMachineReserved;
		$this->allocationPolicy = $allocationPolicy;
	}
}

class HostMemorySpec extends phpDynamicProperties {
	public $serviceConsoleReservation; //long

	function __construct($serviceConsoleReservation = null) {
		$this->serviceConsoleReservation = $serviceConsoleReservation;
	}
}

class HostMountInfo extends phpDynamicProperties {
	public $path; //string
	public $accessMode; //string
	public $mounted; //boolean
	public $accessible; //boolean

	function __construct($path = null, $accessMode = null, $mounted = null, $accessible = null) {
		$this->path = $path;
		$this->accessMode = $accessMode;
		$this->mounted = $mounted;
		$this->accessible = $accessible;
	}
}

class HostMultipathInfoLogicalUnitPolicy extends phpDynamicProperties {
	public $policy; //string

	function __construct($policy = null) {
		$this->policy = $policy;
	}
}

class HostMultipathInfoLogicalUnitStorageArrayTypePolicy extends phpDynamicProperties {
	public $policy; //string

	function __construct($policy = null) {
		$this->policy = $policy;
	}
}

class HostMultipathInfoFixedLogicalUnitPolicy extends phpDynamicProperties {
	public $prefer; //string

	function __construct($prefer = null) {
		$this->prefer = $prefer;
	}
}

class HostMultipathInfoLogicalUnit extends phpDynamicProperties {
	public $key; //string
	public $id; //string
	public $lun; //string
	public $path; //HostMultipathInfoPath
	public $policy; //HostMultipathInfoLogicalUnitPolicy
	public $storageArrayTypePolicy; //HostMultipathInfoLogicalUnitStorageArrayTypePolicy

	function __construct($key = null, $id = null, $lun = null, $path = null, $policy = null, $storageArrayTypePolicy = null) {
		$this->key = $key;
		$this->id = $id;
		$this->lun = $lun;
		$this->path = $path;
		$this->policy = $policy;
		$this->storageArrayTypePolicy = $storageArrayTypePolicy;
	}
}

class ArrayOfHostMultipathInfoLogicalUnit extends phpDynamicProperties {
	public $HostMultipathInfoLogicalUnit; //HostMultipathInfoLogicalUnit

	function __construct($HostMultipathInfoLogicalUnit = null) {
		$this->HostMultipathInfoLogicalUnit = $HostMultipathInfoLogicalUnit;
	}
}

class HostMultipathInfoPath extends phpDynamicProperties {
	public $key; //string
	public $name; //string
	public $pathState; //string
	public $state; //string
	public $isWorkingPath; //boolean
	public $adapter; //string
	public $lun; //string
	public $transport; //HostTargetTransport

	function __construct($key = null, $name = null, $pathState = null, $state = null, $isWorkingPath = null, $adapter = null, $lun = null, $transport = null) {
		$this->key = $key;
		$this->name = $name;
		$this->pathState = $pathState;
		$this->state = $state;
		$this->isWorkingPath = $isWorkingPath;
		$this->adapter = $adapter;
		$this->lun = $lun;
		$this->transport = $transport;
	}
}

class ArrayOfHostMultipathInfoPath extends phpDynamicProperties {
	public $HostMultipathInfoPath; //HostMultipathInfoPath

	function __construct($HostMultipathInfoPath = null) {
		$this->HostMultipathInfoPath = $HostMultipathInfoPath;
	}
}

class HostMultipathInfo extends phpDynamicProperties {
	public $lun; //HostMultipathInfoLogicalUnit

	function __construct($lun = null) {
		$this->lun = $lun;
	}
}

class HostMultipathStateInfoPath extends phpDynamicProperties {
	public $name; //string
	public $pathState; //string

	function __construct($name = null, $pathState = null) {
		$this->name = $name;
		$this->pathState = $pathState;
	}
}

class ArrayOfHostMultipathStateInfoPath extends phpDynamicProperties {
	public $HostMultipathStateInfoPath; //HostMultipathStateInfoPath

	function __construct($HostMultipathStateInfoPath = null) {
		$this->HostMultipathStateInfoPath = $HostMultipathStateInfoPath;
	}
}

class HostMultipathStateInfo extends phpDynamicProperties {
	public $path; //HostMultipathStateInfoPath

	function __construct($path = null) {
		$this->path = $path;
	}
}

class HostNatServicePortForwardSpec extends phpDynamicProperties {
	public $type; //string
	public $name; //string
	public $hostPort; //int
	public $guestPort; //int
	public $guestIpAddress; //string

	function __construct($type = null, $name = null, $hostPort = null, $guestPort = null, $guestIpAddress = null) {
		$this->type = $type;
		$this->name = $name;
		$this->hostPort = $hostPort;
		$this->guestPort = $guestPort;
		$this->guestIpAddress = $guestIpAddress;
	}
}

class ArrayOfHostNatServicePortForwardSpec extends phpDynamicProperties {
	public $HostNatServicePortForwardSpec; //HostNatServicePortForwardSpec

	function __construct($HostNatServicePortForwardSpec = null) {
		$this->HostNatServicePortForwardSpec = $HostNatServicePortForwardSpec;
	}
}

class HostNatServiceNameServiceSpec extends phpDynamicProperties {
	public $dnsAutoDetect; //boolean
	public $dnsPolicy; //string
	public $dnsRetries; //int
	public $dnsTimeout; //int
	public $dnsNameServer; //string
	public $nbdsTimeout; //int
	public $nbnsRetries; //int
	public $nbnsTimeout; //int

	function __construct($dnsAutoDetect = null, $dnsPolicy = null, $dnsRetries = null, $dnsTimeout = null, $dnsNameServer = null, $nbdsTimeout = null, $nbnsRetries = null, $nbnsTimeout = null) {
		$this->dnsAutoDetect = $dnsAutoDetect;
		$this->dnsPolicy = $dnsPolicy;
		$this->dnsRetries = $dnsRetries;
		$this->dnsTimeout = $dnsTimeout;
		$this->dnsNameServer = $dnsNameServer;
		$this->nbdsTimeout = $nbdsTimeout;
		$this->nbnsRetries = $nbnsRetries;
		$this->nbnsTimeout = $nbnsTimeout;
	}
}

class HostNatServiceSpec extends phpDynamicProperties {
	public $virtualSwitch; //string
	public $activeFtp; //boolean
	public $allowAnyOui; //boolean
	public $configPort; //boolean
	public $ipGatewayAddress; //string
	public $udpTimeout; //int
	public $portForward; //HostNatServicePortForwardSpec
	public $nameService; //HostNatServiceNameServiceSpec

	function __construct($virtualSwitch = null, $activeFtp = null, $allowAnyOui = null, $configPort = null, $ipGatewayAddress = null, $udpTimeout = null, $portForward = null, $nameService = null) {
		$this->virtualSwitch = $virtualSwitch;
		$this->activeFtp = $activeFtp;
		$this->allowAnyOui = $allowAnyOui;
		$this->configPort = $configPort;
		$this->ipGatewayAddress = $ipGatewayAddress;
		$this->udpTimeout = $udpTimeout;
		$this->portForward = $portForward;
		$this->nameService = $nameService;
	}
}

class HostNatServiceConfig extends phpDynamicProperties {
	public $changeOperation; //string
	public $key; //string
	public $spec; //HostNatServiceSpec

	function __construct($changeOperation = null, $key = null, $spec = null) {
		$this->changeOperation = $changeOperation;
		$this->key = $key;
		$this->spec = $spec;
	}
}

class ArrayOfHostNatServiceConfig extends phpDynamicProperties {
	public $HostNatServiceConfig; //HostNatServiceConfig

	function __construct($HostNatServiceConfig = null) {
		$this->HostNatServiceConfig = $HostNatServiceConfig;
	}
}

class HostNatService extends phpDynamicProperties {
	public $key; //string
	public $spec; //HostNatServiceSpec

	function __construct($key = null, $spec = null) {
		$this->key = $key;
		$this->spec = $spec;
	}
}

class ArrayOfHostNatService extends phpDynamicProperties {
	public $HostNatService; //HostNatService

	function __construct($HostNatService = null) {
		$this->HostNatService = $HostNatService;
	}
}

class HostNetCapabilities extends phpDynamicProperties {
	public $canSetPhysicalNicLinkSpeed; //boolean
	public $supportsNicTeaming; //boolean
	public $nicTeamingPolicy; //string
	public $supportsVlan; //boolean
	public $usesServiceConsoleNic; //boolean
	public $supportsNetworkHints; //boolean
	public $maxPortGroupsPerVswitch; //int
	public $vswitchConfigSupported; //boolean
	public $vnicConfigSupported; //boolean
	public $ipRouteConfigSupported; //boolean
	public $dnsConfigSupported; //boolean
	public $dhcpOnVnicSupported; //boolean
	public $ipV6Supported; //boolean

	function __construct($canSetPhysicalNicLinkSpeed = null, $supportsNicTeaming = null, $nicTeamingPolicy = null, $supportsVlan = null, $usesServiceConsoleNic = null, $supportsNetworkHints = null, $maxPortGroupsPerVswitch = null, $vswitchConfigSupported = null, $vnicConfigSupported = null, $ipRouteConfigSupported = null, $dnsConfigSupported = null, $dhcpOnVnicSupported = null, $ipV6Supported = null) {
		$this->canSetPhysicalNicLinkSpeed = $canSetPhysicalNicLinkSpeed;
		$this->supportsNicTeaming = $supportsNicTeaming;
		$this->nicTeamingPolicy = $nicTeamingPolicy;
		$this->supportsVlan = $supportsVlan;
		$this->usesServiceConsoleNic = $usesServiceConsoleNic;
		$this->supportsNetworkHints = $supportsNetworkHints;
		$this->maxPortGroupsPerVswitch = $maxPortGroupsPerVswitch;
		$this->vswitchConfigSupported = $vswitchConfigSupported;
		$this->vnicConfigSupported = $vnicConfigSupported;
		$this->ipRouteConfigSupported = $ipRouteConfigSupported;
		$this->dnsConfigSupported = $dnsConfigSupported;
		$this->dhcpOnVnicSupported = $dhcpOnVnicSupported;
		$this->ipV6Supported = $ipV6Supported;
	}
}

class HostNetOffloadCapabilities extends phpDynamicProperties {
	public $csumOffload; //boolean
	public $tcpSegmentation; //boolean
	public $zeroCopyXmit; //boolean

	function __construct($csumOffload = null, $tcpSegmentation = null, $zeroCopyXmit = null) {
		$this->csumOffload = $csumOffload;
		$this->tcpSegmentation = $tcpSegmentation;
		$this->zeroCopyXmit = $zeroCopyXmit;
	}
}

class HostNetworkConfigResult extends phpDynamicProperties {
	public $vnicDevice; //string
	public $consoleVnicDevice; //string

	function __construct($vnicDevice = null, $consoleVnicDevice = null) {
		$this->vnicDevice = $vnicDevice;
		$this->consoleVnicDevice = $consoleVnicDevice;
	}
}

class HostNetworkConfig extends phpDynamicProperties {
	public $vswitch; //HostVirtualSwitchConfig
	public $proxySwitch; //HostProxySwitchConfig
	public $portgroup; //HostPortGroupConfig
	public $pnic; //PhysicalNicConfig
	public $vnic; //HostVirtualNicConfig
	public $consoleVnic; //HostVirtualNicConfig
	public $dnsConfig; //HostDnsConfig
	public $ipRouteConfig; //HostIpRouteConfig
	public $consoleIpRouteConfig; //HostIpRouteConfig
	public $routeTableConfig; //HostIpRouteTableConfig
	public $dhcp; //HostDhcpServiceConfig
	public $nat; //HostNatServiceConfig
	public $ipV6Enabled; //boolean

	function __construct($vswitch = null, $proxySwitch = null, $portgroup = null, $pnic = null, $vnic = null, $consoleVnic = null, $dnsConfig = null, $ipRouteConfig = null, $consoleIpRouteConfig = null, $routeTableConfig = null, $dhcp = null, $nat = null, $ipV6Enabled = null) {
		$this->vswitch = $vswitch;
		$this->proxySwitch = $proxySwitch;
		$this->portgroup = $portgroup;
		$this->pnic = $pnic;
		$this->vnic = $vnic;
		$this->consoleVnic = $consoleVnic;
		$this->dnsConfig = $dnsConfig;
		$this->ipRouteConfig = $ipRouteConfig;
		$this->consoleIpRouteConfig = $consoleIpRouteConfig;
		$this->routeTableConfig = $routeTableConfig;
		$this->dhcp = $dhcp;
		$this->nat = $nat;
		$this->ipV6Enabled = $ipV6Enabled;
	}
}

class HostNetworkInfo extends phpDynamicProperties {
	public $vswitch; //HostVirtualSwitch
	public $proxySwitch; //HostProxySwitch
	public $portgroup; //HostPortGroup
	public $pnic; //PhysicalNic
	public $vnic; //HostVirtualNic
	public $consoleVnic; //HostVirtualNic
	public $dnsConfig; //HostDnsConfig
	public $ipRouteConfig; //HostIpRouteConfig
	public $consoleIpRouteConfig; //HostIpRouteConfig
	public $routeTableInfo; //HostIpRouteTableInfo
	public $dhcp; //HostDhcpService
	public $nat; //HostNatService
	public $ipV6Enabled; //boolean
	public $atBootIpV6Enabled; //boolean

	function __construct($vswitch = null, $proxySwitch = null, $portgroup = null, $pnic = null, $vnic = null, $consoleVnic = null, $dnsConfig = null, $ipRouteConfig = null, $consoleIpRouteConfig = null, $routeTableInfo = null, $dhcp = null, $nat = null, $ipV6Enabled = null, $atBootIpV6Enabled = null) {
		$this->vswitch = $vswitch;
		$this->proxySwitch = $proxySwitch;
		$this->portgroup = $portgroup;
		$this->pnic = $pnic;
		$this->vnic = $vnic;
		$this->consoleVnic = $consoleVnic;
		$this->dnsConfig = $dnsConfig;
		$this->ipRouteConfig = $ipRouteConfig;
		$this->consoleIpRouteConfig = $consoleIpRouteConfig;
		$this->routeTableInfo = $routeTableInfo;
		$this->dhcp = $dhcp;
		$this->nat = $nat;
		$this->ipV6Enabled = $ipV6Enabled;
		$this->atBootIpV6Enabled = $atBootIpV6Enabled;
	}
}

class HostNetworkSecurityPolicy extends phpDynamicProperties {
	public $allowPromiscuous; //boolean
	public $macChanges; //boolean
	public $forgedTransmits; //boolean

	function __construct($allowPromiscuous = null, $macChanges = null, $forgedTransmits = null) {
		$this->allowPromiscuous = $allowPromiscuous;
		$this->macChanges = $macChanges;
		$this->forgedTransmits = $forgedTransmits;
	}
}

class HostNetworkTrafficShapingPolicy extends phpDynamicProperties {
	public $enabled; //boolean
	public $averageBandwidth; //long
	public $peakBandwidth; //long
	public $burstSize; //long

	function __construct($enabled = null, $averageBandwidth = null, $peakBandwidth = null, $burstSize = null) {
		$this->enabled = $enabled;
		$this->averageBandwidth = $averageBandwidth;
		$this->peakBandwidth = $peakBandwidth;
		$this->burstSize = $burstSize;
	}
}

class HostNicFailureCriteria extends phpDynamicProperties {
	public $checkSpeed; //string
	public $speed; //int
	public $checkDuplex; //boolean
	public $fullDuplex; //boolean
	public $checkErrorPercent; //boolean
	public $percentage; //int
	public $checkBeacon; //boolean

	function __construct($checkSpeed = null, $speed = null, $checkDuplex = null, $fullDuplex = null, $checkErrorPercent = null, $percentage = null, $checkBeacon = null) {
		$this->checkSpeed = $checkSpeed;
		$this->speed = $speed;
		$this->checkDuplex = $checkDuplex;
		$this->fullDuplex = $fullDuplex;
		$this->checkErrorPercent = $checkErrorPercent;
		$this->percentage = $percentage;
		$this->checkBeacon = $checkBeacon;
	}
}

class HostNicOrderPolicy extends phpDynamicProperties {
	public $activeNic; //string
	public $standbyNic; //string

	function __construct($activeNic = null, $standbyNic = null) {
		$this->activeNic = $activeNic;
		$this->standbyNic = $standbyNic;
	}
}

class HostNicTeamingPolicy extends phpDynamicProperties {
	public $policy; //string
	public $reversePolicy; //boolean
	public $notifySwitches; //boolean
	public $rollingOrder; //boolean
	public $failureCriteria; //HostNicFailureCriteria
	public $nicOrder; //HostNicOrderPolicy

	function __construct($policy = null, $reversePolicy = null, $notifySwitches = null, $rollingOrder = null, $failureCriteria = null, $nicOrder = null) {
		$this->policy = $policy;
		$this->reversePolicy = $reversePolicy;
		$this->notifySwitches = $notifySwitches;
		$this->rollingOrder = $rollingOrder;
		$this->failureCriteria = $failureCriteria;
		$this->nicOrder = $nicOrder;
	}
}

class HostNetworkPolicy extends phpDynamicProperties {
	public $security; //HostNetworkSecurityPolicy
	public $nicTeaming; //HostNicTeamingPolicy
	public $offloadPolicy; //HostNetOffloadCapabilities
	public $shapingPolicy; //HostNetworkTrafficShapingPolicy

	function __construct($security = null, $nicTeaming = null, $offloadPolicy = null, $shapingPolicy = null) {
		$this->security = $security;
		$this->nicTeaming = $nicTeaming;
		$this->offloadPolicy = $offloadPolicy;
		$this->shapingPolicy = $shapingPolicy;
	}
}

class HostNtpConfig extends phpDynamicProperties {
	public $server; //string

	function __construct($server = null) {
		$this->server = $server;
	}
}

class HostNumericSensorInfo extends phpDynamicProperties {
	public $name; //string
	public $healthState; //ElementDescription
	public $currentReading; //long
	public $unitModifier; //int
	public $baseUnits; //string
	public $rateUnits; //string
	public $sensorType; //string

	function __construct($name = null, $healthState = null, $currentReading = null, $unitModifier = null, $baseUnits = null, $rateUnits = null, $sensorType = null) {
		$this->name = $name;
		$this->healthState = $healthState;
		$this->currentReading = $currentReading;
		$this->unitModifier = $unitModifier;
		$this->baseUnits = $baseUnits;
		$this->rateUnits = $rateUnits;
		$this->sensorType = $sensorType;
	}
}

class ArrayOfHostNumericSensorInfo extends phpDynamicProperties {
	public $HostNumericSensorInfo; //HostNumericSensorInfo

	function __construct($HostNumericSensorInfo = null) {
		$this->HostNumericSensorInfo = $HostNumericSensorInfo;
	}
}

class HostPatchManagerResult extends phpDynamicProperties {
	public $version; //string
	public $status; //HostPatchManagerStatus
	public $xmlResult; //string

	function __construct($version = null, $status = null, $xmlResult = null) {
		$this->version = $version;
		$this->status = $status;
		$this->xmlResult = $xmlResult;
	}
}

class HostPatchManagerStatusPrerequisitePatch extends phpDynamicProperties {
	public $id; //string
	public $installState; //string

	function __construct($id = null, $installState = null) {
		$this->id = $id;
		$this->installState = $installState;
	}
}

class ArrayOfHostPatchManagerStatusPrerequisitePatch extends phpDynamicProperties {
	public $HostPatchManagerStatusPrerequisitePatch; //HostPatchManagerStatusPrerequisitePatch

	function __construct($HostPatchManagerStatusPrerequisitePatch = null) {
		$this->HostPatchManagerStatusPrerequisitePatch = $HostPatchManagerStatusPrerequisitePatch;
	}
}

class HostPatchManagerStatus extends phpDynamicProperties {
	public $id; //string
	public $applicable; //boolean
	public $reason; //string
	public $integrity; //string
	public $installed; //boolean
	public $installState; //string
	public $prerequisitePatch; //HostPatchManagerStatusPrerequisitePatch
	public $restartRequired; //boolean
	public $reconnectRequired; //boolean
	public $vmOffRequired; //boolean
	public $supersededPatchIds; //string

	function __construct($id = null, $applicable = null, $reason = null, $integrity = null, $installed = null, $installState = null, $prerequisitePatch = null, $restartRequired = null, $reconnectRequired = null, $vmOffRequired = null, $supersededPatchIds = null) {
		$this->id = $id;
		$this->applicable = $applicable;
		$this->reason = $reason;
		$this->integrity = $integrity;
		$this->installed = $installed;
		$this->installState = $installState;
		$this->prerequisitePatch = $prerequisitePatch;
		$this->restartRequired = $restartRequired;
		$this->reconnectRequired = $reconnectRequired;
		$this->vmOffRequired = $vmOffRequired;
		$this->supersededPatchIds = $supersededPatchIds;
	}
}

class ArrayOfHostPatchManagerStatus extends phpDynamicProperties {
	public $HostPatchManagerStatus; //HostPatchManagerStatus

	function __construct($HostPatchManagerStatus = null) {
		$this->HostPatchManagerStatus = $HostPatchManagerStatus;
	}
}

class HostPatchManagerLocator extends phpDynamicProperties {
	public $url; //string
	public $proxy; //string

	function __construct($url = null, $proxy = null) {
		$this->url = $url;
		$this->proxy = $proxy;
	}
}

class HostPatchManagerPatchManagerOperationSpec extends phpDynamicProperties {
	public $proxy; //string
	public $port; //int
	public $userName; //string
	public $password; //string
	public $cmdOption; //string

	function __construct($proxy = null, $port = null, $userName = null, $password = null, $cmdOption = null) {
		$this->proxy = $proxy;
		$this->port = $port;
		$this->userName = $userName;
		$this->password = $password;
		$this->cmdOption = $cmdOption;
	}
}

class HostPathSelectionPolicyOption extends phpDynamicProperties {
	public $policy; //ElementDescription

	function __construct($policy = null) {
		$this->policy = $policy;
	}
}

class ArrayOfHostPathSelectionPolicyOption extends phpDynamicProperties {
	public $HostPathSelectionPolicyOption; //HostPathSelectionPolicyOption

	function __construct($HostPathSelectionPolicyOption = null) {
		$this->HostPathSelectionPolicyOption = $HostPathSelectionPolicyOption;
	}
}

class HostPciDevice extends phpDynamicProperties {
	public $id; //string
	public $classId; //short
	public $bus; //byte
	public $slot; //byte
	public $function; //byte
	public $vendorId; //short
	public $subVendorId; //short
	public $vendorName; //string
	public $deviceId; //short
	public $subDeviceId; //short
	public $parentBridge; //string
	public $deviceName; //string

	function __construct($id = null, $classId = null, $bus = null, $slot = null, $function = null, $vendorId = null, $subVendorId = null, $vendorName = null, $deviceId = null, $subDeviceId = null, $parentBridge = null, $deviceName = null) {
		$this->id = $id;
		$this->classId = $classId;
		$this->bus = $bus;
		$this->slot = $slot;
		$this->function = $function;
		$this->vendorId = $vendorId;
		$this->subVendorId = $subVendorId;
		$this->vendorName = $vendorName;
		$this->deviceId = $deviceId;
		$this->subDeviceId = $subDeviceId;
		$this->parentBridge = $parentBridge;
		$this->deviceName = $deviceName;
	}
}

class ArrayOfHostPciDevice extends phpDynamicProperties {
	public $HostPciDevice; //HostPciDevice

	function __construct($HostPciDevice = null) {
		$this->HostPciDevice = $HostPciDevice;
	}
}

class HostPciPassthruConfig extends phpDynamicProperties {
	public $id; //string
	public $passthruEnabled; //boolean

	function __construct($id = null, $passthruEnabled = null) {
		$this->id = $id;
		$this->passthruEnabled = $passthruEnabled;
	}
}

class ArrayOfHostPciPassthruConfig extends phpDynamicProperties {
	public $HostPciPassthruConfig; //HostPciPassthruConfig

	function __construct($HostPciPassthruConfig = null) {
		$this->HostPciPassthruConfig = $HostPciPassthruConfig;
	}
}

class HostPciPassthruInfo extends phpDynamicProperties {
	public $id; //string
	public $dependentDevice; //string
	public $passthruEnabled; //boolean
	public $passthruCapable; //boolean
	public $passthruActive; //boolean

	function __construct($id = null, $dependentDevice = null, $passthruEnabled = null, $passthruCapable = null, $passthruActive = null) {
		$this->id = $id;
		$this->dependentDevice = $dependentDevice;
		$this->passthruEnabled = $passthruEnabled;
		$this->passthruCapable = $passthruCapable;
		$this->passthruActive = $passthruActive;
	}
}

class ArrayOfHostPciPassthruInfo extends phpDynamicProperties {
	public $HostPciPassthruInfo; //HostPciPassthruInfo

	function __construct($HostPciPassthruInfo = null) {
		$this->HostPciPassthruInfo = $HostPciPassthruInfo;
	}
}

class PhysicalNicSpec extends phpDynamicProperties {
	public $ip; //HostIpConfig
	public $linkSpeed; //PhysicalNicLinkInfo

	function __construct($ip = null, $linkSpeed = null) {
		$this->ip = $ip;
		$this->linkSpeed = $linkSpeed;
	}
}

class PhysicalNicConfig extends phpDynamicProperties {
	public $device; //string
	public $spec; //PhysicalNicSpec

	function __construct($device = null, $spec = null) {
		$this->device = $device;
		$this->spec = $spec;
	}
}

class ArrayOfPhysicalNicConfig extends phpDynamicProperties {
	public $PhysicalNicConfig; //PhysicalNicConfig

	function __construct($PhysicalNicConfig = null) {
		$this->PhysicalNicConfig = $PhysicalNicConfig;
	}
}

class PhysicalNicLinkInfo extends phpDynamicProperties {
	public $speedMb; //int
	public $duplex; //boolean

	function __construct($speedMb = null, $duplex = null) {
		$this->speedMb = $speedMb;
		$this->duplex = $duplex;
	}
}

class ArrayOfPhysicalNicLinkInfo extends phpDynamicProperties {
	public $PhysicalNicLinkInfo; //PhysicalNicLinkInfo

	function __construct($PhysicalNicLinkInfo = null) {
		$this->PhysicalNicLinkInfo = $PhysicalNicLinkInfo;
	}
}

class PhysicalNicHint extends phpDynamicProperties {
	public $vlanId; //int

	function __construct($vlanId = null) {
		$this->vlanId = $vlanId;
	}
}

class PhysicalNicIpHint extends phpDynamicProperties {
	public $ipSubnet; //string

	function __construct($ipSubnet = null) {
		$this->ipSubnet = $ipSubnet;
	}
}

class ArrayOfPhysicalNicIpHint extends phpDynamicProperties {
	public $PhysicalNicIpHint; //PhysicalNicIpHint

	function __construct($PhysicalNicIpHint = null) {
		$this->PhysicalNicIpHint = $PhysicalNicIpHint;
	}
}

class PhysicalNicNameHint extends phpDynamicProperties {
	public $network; //string

	function __construct($network = null) {
		$this->network = $network;
	}
}

class ArrayOfPhysicalNicNameHint extends phpDynamicProperties {
	public $PhysicalNicNameHint; //PhysicalNicNameHint

	function __construct($PhysicalNicNameHint = null) {
		$this->PhysicalNicNameHint = $PhysicalNicNameHint;
	}
}

class PhysicalNicHintInfo extends phpDynamicProperties {
	public $device; //string
	public $subnet; //PhysicalNicIpHint
	public $network; //PhysicalNicNameHint
	public $connectedSwitchPort; //PhysicalNicCdpInfo
	public $lldpInfo; //LinkLayerDiscoveryProtocolInfo

	function __construct($device = null, $subnet = null, $network = null, $connectedSwitchPort = null, $lldpInfo = null) {
		$this->device = $device;
		$this->subnet = $subnet;
		$this->network = $network;
		$this->connectedSwitchPort = $connectedSwitchPort;
		$this->lldpInfo = $lldpInfo;
	}
}

class ArrayOfPhysicalNicHintInfo extends phpDynamicProperties {
	public $PhysicalNicHintInfo; //PhysicalNicHintInfo

	function __construct($PhysicalNicHintInfo = null) {
		$this->PhysicalNicHintInfo = $PhysicalNicHintInfo;
	}
}

class PhysicalNicCdpDeviceCapability extends phpDynamicProperties {
	public $router; //boolean
	public $transparentBridge; //boolean
	public $sourceRouteBridge; //boolean
	public $networkSwitch; //boolean
	public $host; //boolean
	public $igmpEnabled; //boolean
	public $repeater; //boolean

	function __construct($router = null, $transparentBridge = null, $sourceRouteBridge = null, $networkSwitch = null, $host = null, $igmpEnabled = null, $repeater = null) {
		$this->router = $router;
		$this->transparentBridge = $transparentBridge;
		$this->sourceRouteBridge = $sourceRouteBridge;
		$this->networkSwitch = $networkSwitch;
		$this->host = $host;
		$this->igmpEnabled = $igmpEnabled;
		$this->repeater = $repeater;
	}
}

class PhysicalNicCdpInfo extends phpDynamicProperties {
	public $cdpVersion; //int
	public $timeout; //int
	public $ttl; //int
	public $samples; //int
	public $devId; //string
	public $address; //string
	public $portId; //string
	public $deviceCapability; //PhysicalNicCdpDeviceCapability
	public $softwareVersion; //string
	public $hardwarePlatform; //string
	public $ipPrefix; //string
	public $ipPrefixLen; //int
	public $vlan; //int
	public $fullDuplex; //boolean
	public $mtu; //int
	public $systemName; //string
	public $systemOID; //string
	public $mgmtAddr; //string
	public $location; //string

	function __construct($cdpVersion = null, $timeout = null, $ttl = null, $samples = null, $devId = null, $address = null, $portId = null, $deviceCapability = null, $softwareVersion = null, $hardwarePlatform = null, $ipPrefix = null, $ipPrefixLen = null, $vlan = null, $fullDuplex = null, $mtu = null, $systemName = null, $systemOID = null, $mgmtAddr = null, $location = null) {
		$this->cdpVersion = $cdpVersion;
		$this->timeout = $timeout;
		$this->ttl = $ttl;
		$this->samples = $samples;
		$this->devId = $devId;
		$this->address = $address;
		$this->portId = $portId;
		$this->deviceCapability = $deviceCapability;
		$this->softwareVersion = $softwareVersion;
		$this->hardwarePlatform = $hardwarePlatform;
		$this->ipPrefix = $ipPrefix;
		$this->ipPrefixLen = $ipPrefixLen;
		$this->vlan = $vlan;
		$this->fullDuplex = $fullDuplex;
		$this->mtu = $mtu;
		$this->systemName = $systemName;
		$this->systemOID = $systemOID;
		$this->mgmtAddr = $mgmtAddr;
		$this->location = $location;
	}
}

class LinkLayerDiscoveryProtocolInfo extends phpDynamicProperties {
	public $chassisId; //string
	public $portId; //string
	public $timeToLive; //int
	public $parameter; //KeyAnyValue

	function __construct($chassisId = null, $portId = null, $timeToLive = null, $parameter = null) {
		$this->chassisId = $chassisId;
		$this->portId = $portId;
		$this->timeToLive = $timeToLive;
		$this->parameter = $parameter;
	}
}

class PhysicalNic extends phpDynamicProperties {
	public $key; //string
	public $device; //string
	public $pci; //string
	public $driver; //string
	public $linkSpeed; //PhysicalNicLinkInfo
	public $validLinkSpecification; //PhysicalNicLinkInfo
	public $spec; //PhysicalNicSpec
	public $wakeOnLanSupported; //boolean
	public $mac; //string
	public $fcoeConfiguration; //FcoeConfig
	public $vmDirectPathGen2Supported; //boolean
	public $vmDirectPathGen2SupportedMode; //string
	public $resourcePoolSchedulerAllowed; //boolean
	public $resourcePoolSchedulerDisallowedReason; //string
	public $autoNegotiateSupported; //boolean

	function __construct($key = null, $device = null, $pci = null, $driver = null, $linkSpeed = null, $validLinkSpecification = null, $spec = null, $wakeOnLanSupported = null, $mac = null, $fcoeConfiguration = null, $vmDirectPathGen2Supported = null, $vmDirectPathGen2SupportedMode = null, $resourcePoolSchedulerAllowed = null, $resourcePoolSchedulerDisallowedReason = null, $autoNegotiateSupported = null) {
		$this->key = $key;
		$this->device = $device;
		$this->pci = $pci;
		$this->driver = $driver;
		$this->linkSpeed = $linkSpeed;
		$this->validLinkSpecification = $validLinkSpecification;
		$this->spec = $spec;
		$this->wakeOnLanSupported = $wakeOnLanSupported;
		$this->mac = $mac;
		$this->fcoeConfiguration = $fcoeConfiguration;
		$this->vmDirectPathGen2Supported = $vmDirectPathGen2Supported;
		$this->vmDirectPathGen2SupportedMode = $vmDirectPathGen2SupportedMode;
		$this->resourcePoolSchedulerAllowed = $resourcePoolSchedulerAllowed;
		$this->resourcePoolSchedulerDisallowedReason = $resourcePoolSchedulerDisallowedReason;
		$this->autoNegotiateSupported = $autoNegotiateSupported;
	}
}

class ArrayOfPhysicalNic extends phpDynamicProperties {
	public $PhysicalNic; //PhysicalNic

	function __construct($PhysicalNic = null) {
		$this->PhysicalNic = $PhysicalNic;
	}
}

class HostPlugStoreTopologyAdapter extends phpDynamicProperties {
	public $key; //string
	public $adapter; //string
	public $path; //string

	function __construct($key = null, $adapter = null, $path = null) {
		$this->key = $key;
		$this->adapter = $adapter;
		$this->path = $path;
	}
}

class ArrayOfHostPlugStoreTopologyAdapter extends phpDynamicProperties {
	public $HostPlugStoreTopologyAdapter; //HostPlugStoreTopologyAdapter

	function __construct($HostPlugStoreTopologyAdapter = null) {
		$this->HostPlugStoreTopologyAdapter = $HostPlugStoreTopologyAdapter;
	}
}

class HostPlugStoreTopologyPath extends phpDynamicProperties {
	public $key; //string
	public $name; //string
	public $channelNumber; //int
	public $targetNumber; //int
	public $lunNumber; //int
	public $adapter; //string
	public $target; //string
	public $device; //string

	function __construct($key = null, $name = null, $channelNumber = null, $targetNumber = null, $lunNumber = null, $adapter = null, $target = null, $device = null) {
		$this->key = $key;
		$this->name = $name;
		$this->channelNumber = $channelNumber;
		$this->targetNumber = $targetNumber;
		$this->lunNumber = $lunNumber;
		$this->adapter = $adapter;
		$this->target = $target;
		$this->device = $device;
	}
}

class ArrayOfHostPlugStoreTopologyPath extends phpDynamicProperties {
	public $HostPlugStoreTopologyPath; //HostPlugStoreTopologyPath

	function __construct($HostPlugStoreTopologyPath = null) {
		$this->HostPlugStoreTopologyPath = $HostPlugStoreTopologyPath;
	}
}

class HostPlugStoreTopologyDevice extends phpDynamicProperties {
	public $key; //string
	public $lun; //string
	public $path; //string

	function __construct($key = null, $lun = null, $path = null) {
		$this->key = $key;
		$this->lun = $lun;
		$this->path = $path;
	}
}

class ArrayOfHostPlugStoreTopologyDevice extends phpDynamicProperties {
	public $HostPlugStoreTopologyDevice; //HostPlugStoreTopologyDevice

	function __construct($HostPlugStoreTopologyDevice = null) {
		$this->HostPlugStoreTopologyDevice = $HostPlugStoreTopologyDevice;
	}
}

class HostPlugStoreTopologyPlugin extends phpDynamicProperties {
	public $key; //string
	public $name; //string
	public $device; //string
	public $claimedPath; //string

	function __construct($key = null, $name = null, $device = null, $claimedPath = null) {
		$this->key = $key;
		$this->name = $name;
		$this->device = $device;
		$this->claimedPath = $claimedPath;
	}
}

class ArrayOfHostPlugStoreTopologyPlugin extends phpDynamicProperties {
	public $HostPlugStoreTopologyPlugin; //HostPlugStoreTopologyPlugin

	function __construct($HostPlugStoreTopologyPlugin = null) {
		$this->HostPlugStoreTopologyPlugin = $HostPlugStoreTopologyPlugin;
	}
}

class HostPlugStoreTopologyTarget extends phpDynamicProperties {
	public $key; //string
	public $transport; //HostTargetTransport

	function __construct($key = null, $transport = null) {
		$this->key = $key;
		$this->transport = $transport;
	}
}

class ArrayOfHostPlugStoreTopologyTarget extends phpDynamicProperties {
	public $HostPlugStoreTopologyTarget; //HostPlugStoreTopologyTarget

	function __construct($HostPlugStoreTopologyTarget = null) {
		$this->HostPlugStoreTopologyTarget = $HostPlugStoreTopologyTarget;
	}
}

class HostPlugStoreTopology extends phpDynamicProperties {
	public $adapter; //HostPlugStoreTopologyAdapter
	public $path; //HostPlugStoreTopologyPath
	public $target; //HostPlugStoreTopologyTarget
	public $device; //HostPlugStoreTopologyDevice
	public $plugin; //HostPlugStoreTopologyPlugin

	function __construct($adapter = null, $path = null, $target = null, $device = null, $plugin = null) {
		$this->adapter = $adapter;
		$this->path = $path;
		$this->target = $target;
		$this->device = $device;
		$this->plugin = $plugin;
	}
}

class HostPortGroupSpec extends phpDynamicProperties {
	public $name; //string
	public $vlanId; //int
	public $vswitchName; //string
	public $policy; //HostNetworkPolicy

	function __construct($name = null, $vlanId = null, $vswitchName = null, $policy = null) {
		$this->name = $name;
		$this->vlanId = $vlanId;
		$this->vswitchName = $vswitchName;
		$this->policy = $policy;
	}
}

class HostPortGroupConfig extends phpDynamicProperties {
	public $changeOperation; //string
	public $spec; //HostPortGroupSpec

	function __construct($changeOperation = null, $spec = null) {
		$this->changeOperation = $changeOperation;
		$this->spec = $spec;
	}
}

class ArrayOfHostPortGroupConfig extends phpDynamicProperties {
	public $HostPortGroupConfig; //HostPortGroupConfig

	function __construct($HostPortGroupConfig = null) {
		$this->HostPortGroupConfig = $HostPortGroupConfig;
	}
}

class HostPortGroupPort extends phpDynamicProperties {
	public $key; //string
	public $mac; //string
	public $type; //string

	function __construct($key = null, $mac = null, $type = null) {
		$this->key = $key;
		$this->mac = $mac;
		$this->type = $type;
	}
}

class ArrayOfHostPortGroupPort extends phpDynamicProperties {
	public $HostPortGroupPort; //HostPortGroupPort

	function __construct($HostPortGroupPort = null) {
		$this->HostPortGroupPort = $HostPortGroupPort;
	}
}

class HostPortGroup extends phpDynamicProperties {
	public $key; //string
	public $port; //HostPortGroupPort
	public $vswitch; //string
	public $computedPolicy; //HostNetworkPolicy
	public $spec; //HostPortGroupSpec

	function __construct($key = null, $port = null, $vswitch = null, $computedPolicy = null, $spec = null) {
		$this->key = $key;
		$this->port = $port;
		$this->vswitch = $vswitch;
		$this->computedPolicy = $computedPolicy;
		$this->spec = $spec;
	}
}

class ArrayOfHostPortGroup extends phpDynamicProperties {
	public $HostPortGroup; //HostPortGroup

	function __construct($HostPortGroup = null) {
		$this->HostPortGroup = $HostPortGroup;
	}
}

class HostPowerPolicy extends phpDynamicProperties {
	public $key; //int
	public $name; //string
	public $shortName; //string
	public $description; //string

	function __construct($key = null, $name = null, $shortName = null, $description = null) {
		$this->key = $key;
		$this->name = $name;
		$this->shortName = $shortName;
		$this->description = $description;
	}
}

class ArrayOfHostPowerPolicy extends phpDynamicProperties {
	public $HostPowerPolicy; //HostPowerPolicy

	function __construct($HostPowerPolicy = null) {
		$this->HostPowerPolicy = $HostPowerPolicy;
	}
}

class PowerSystemCapability extends phpDynamicProperties {
	public $availablePolicy; //HostPowerPolicy

	function __construct($availablePolicy = null) {
		$this->availablePolicy = $availablePolicy;
	}
}

class PowerSystemInfo extends phpDynamicProperties {
	public $currentPolicy; //HostPowerPolicy

	function __construct($currentPolicy = null) {
		$this->currentPolicy = $currentPolicy;
	}
}

class HostResignatureRescanResult extends phpDynamicProperties {
	public $rescan; //HostVmfsRescanResult
	public $result; //ManagedObjectReference

	function __construct($rescan = null, $result = null) {
		$this->rescan = $rescan;
		$this->result = $result;
	}
}

class HostFirewallRulesetIpNetwork extends phpDynamicProperties {
	public $network; //string
	public $prefixLength; //int

	function __construct($network = null, $prefixLength = null) {
		$this->network = $network;
		$this->prefixLength = $prefixLength;
	}
}

class ArrayOfHostFirewallRulesetIpNetwork extends phpDynamicProperties {
	public $HostFirewallRulesetIpNetwork; //HostFirewallRulesetIpNetwork

	function __construct($HostFirewallRulesetIpNetwork = null) {
		$this->HostFirewallRulesetIpNetwork = $HostFirewallRulesetIpNetwork;
	}
}

class HostFirewallRulesetIpList extends phpDynamicProperties {
	public $ipAddress; //string
	public $ipNetwork; //HostFirewallRulesetIpNetwork
	public $allIp; //boolean

	function __construct($ipAddress = null, $ipNetwork = null, $allIp = null) {
		$this->ipAddress = $ipAddress;
		$this->ipNetwork = $ipNetwork;
		$this->allIp = $allIp;
	}
}

class HostFirewallRulesetRulesetSpec extends phpDynamicProperties {
	public $allowedHosts; //HostFirewallRulesetIpList

	function __construct($allowedHosts = null) {
		$this->allowedHosts = $allowedHosts;
	}
}

class HostFirewallRule extends phpDynamicProperties {
	public $port; //int
	public $endPort; //int
	public $direction; //HostFirewallRuleDirection
	public $portType; //HostFirewallRulePortType
	public $protocol; //string

	function __construct($port = null, $endPort = null, $direction = null, $portType = null, $protocol = null) {
		$this->port = $port;
		$this->endPort = $endPort;
		$this->direction = $direction;
		$this->portType = $portType;
		$this->protocol = $protocol;
	}
}

class ArrayOfHostFirewallRule extends phpDynamicProperties {
	public $HostFirewallRule; //HostFirewallRule

	function __construct($HostFirewallRule = null) {
		$this->HostFirewallRule = $HostFirewallRule;
	}
}

class HostFirewallRuleset extends phpDynamicProperties {
	public $key; //string
	public $label; //string
	public $required; //boolean
	public $rule; //HostFirewallRule
	public $service; //string
	public $enabled; //boolean
	public $allowedHosts; //HostFirewallRulesetIpList

	function __construct($key = null, $label = null, $required = null, $rule = null, $service = null, $enabled = null, $allowedHosts = null) {
		$this->key = $key;
		$this->label = $label;
		$this->required = $required;
		$this->rule = $rule;
		$this->service = $service;
		$this->enabled = $enabled;
		$this->allowedHosts = $allowedHosts;
	}
}

class ArrayOfHostFirewallRuleset extends phpDynamicProperties {
	public $HostFirewallRuleset; //HostFirewallRuleset

	function __construct($HostFirewallRuleset = null) {
		$this->HostFirewallRuleset = $HostFirewallRuleset;
	}
}

class HostRuntimeInfo extends phpDynamicProperties {
	public $connectionState; //HostSystemConnectionState
	public $powerState; //HostSystemPowerState
	public $standbyMode; //string
	public $inMaintenanceMode; //boolean
	public $bootTime; //dateTime
	public $healthSystemRuntime; //HealthSystemRuntime
	public $dasHostState; //ClusterDasFdmHostState
	public $tpmPcrValues; //HostTpmDigestInfo

	function __construct($connectionState = null, $powerState = null, $standbyMode = null, $inMaintenanceMode = null, $bootTime = null, $healthSystemRuntime = null, $dasHostState = null, $tpmPcrValues = null) {
		$this->connectionState = $connectionState;
		$this->powerState = $powerState;
		$this->standbyMode = $standbyMode;
		$this->inMaintenanceMode = $inMaintenanceMode;
		$this->bootTime = $bootTime;
		$this->healthSystemRuntime = $healthSystemRuntime;
		$this->dasHostState = $dasHostState;
		$this->tpmPcrValues = $tpmPcrValues;
	}
}

class HostScsiDiskPartition extends phpDynamicProperties {
	public $diskName; //string
	public $partition; //int

	function __construct($diskName = null, $partition = null) {
		$this->diskName = $diskName;
		$this->partition = $partition;
	}
}

class ArrayOfHostScsiDiskPartition extends phpDynamicProperties {
	public $HostScsiDiskPartition; //HostScsiDiskPartition

	function __construct($HostScsiDiskPartition = null) {
		$this->HostScsiDiskPartition = $HostScsiDiskPartition;
	}
}

class HostScsiDisk extends phpDynamicProperties {
	public $capacity; //HostDiskDimensionsLba
	public $devicePath; //string
	public $ssd; //boolean

	function __construct($capacity = null, $devicePath = null, $ssd = null) {
		$this->capacity = $capacity;
		$this->devicePath = $devicePath;
		$this->ssd = $ssd;
	}
}

class ArrayOfHostScsiDisk extends phpDynamicProperties {
	public $HostScsiDisk; //HostScsiDisk

	function __construct($HostScsiDisk = null) {
		$this->HostScsiDisk = $HostScsiDisk;
	}
}

class ScsiLunCapabilities extends phpDynamicProperties {
	public $updateDisplayNameSupported; //boolean

	function __construct($updateDisplayNameSupported = null) {
		$this->updateDisplayNameSupported = $updateDisplayNameSupported;
	}
}

class ScsiLunDurableName extends phpDynamicProperties {
	public $namespace; //string
	public $namespaceId; //byte
	public $data; //byte

	function __construct($namespace = null, $namespaceId = null, $data = null) {
		$this->namespace = $namespace;
		$this->namespaceId = $namespaceId;
		$this->data = $data;
	}
}

class ArrayOfScsiLunDurableName extends phpDynamicProperties {
	public $ScsiLunDurableName; //ScsiLunDurableName

	function __construct($ScsiLunDurableName = null) {
		$this->ScsiLunDurableName = $ScsiLunDurableName;
	}
}

class ScsiLunDescriptor extends phpDynamicProperties {
	public $quality; //string
	public $id; //string

	function __construct($quality = null, $id = null) {
		$this->quality = $quality;
		$this->id = $id;
	}
}

class ArrayOfScsiLunDescriptor extends phpDynamicProperties {
	public $ScsiLunDescriptor; //ScsiLunDescriptor

	function __construct($ScsiLunDescriptor = null) {
		$this->ScsiLunDescriptor = $ScsiLunDescriptor;
	}
}

class ScsiLun extends phpDynamicProperties {
	public $key; //string
	public $uuid; //string
	public $descriptor; //ScsiLunDescriptor
	public $canonicalName; //string
	public $displayName; //string
	public $lunType; //string
	public $vendor; //string
	public $model; //string
	public $revision; //string
	public $scsiLevel; //int
	public $serialNumber; //string
	public $durableName; //ScsiLunDurableName
	public $alternateName; //ScsiLunDurableName
	public $standardInquiry; //byte
	public $queueDepth; //int
	public $operationalState; //string
	public $capabilities; //ScsiLunCapabilities
	public $vStorageSupport; //string

	function __construct($key = null, $uuid = null, $descriptor = null, $canonicalName = null, $displayName = null, $lunType = null, $vendor = null, $model = null, $revision = null, $scsiLevel = null, $serialNumber = null, $durableName = null, $alternateName = null, $standardInquiry = null, $queueDepth = null, $operationalState = null, $capabilities = null, $vStorageSupport = null) {
		$this->key = $key;
		$this->uuid = $uuid;
		$this->descriptor = $descriptor;
		$this->canonicalName = $canonicalName;
		$this->displayName = $displayName;
		$this->lunType = $lunType;
		$this->vendor = $vendor;
		$this->model = $model;
		$this->revision = $revision;
		$this->scsiLevel = $scsiLevel;
		$this->serialNumber = $serialNumber;
		$this->durableName = $durableName;
		$this->alternateName = $alternateName;
		$this->standardInquiry = $standardInquiry;
		$this->queueDepth = $queueDepth;
		$this->operationalState = $operationalState;
		$this->capabilities = $capabilities;
		$this->vStorageSupport = $vStorageSupport;
	}
}

class ArrayOfScsiLun extends phpDynamicProperties {
	public $ScsiLun; //ScsiLun

	function __construct($ScsiLun = null) {
		$this->ScsiLun = $ScsiLun;
	}
}

class HostScsiTopologyInterface extends phpDynamicProperties {
	public $key; //string
	public $adapter; //string
	public $target; //HostScsiTopologyTarget

	function __construct($key = null, $adapter = null, $target = null) {
		$this->key = $key;
		$this->adapter = $adapter;
		$this->target = $target;
	}
}

class ArrayOfHostScsiTopologyInterface extends phpDynamicProperties {
	public $HostScsiTopologyInterface; //HostScsiTopologyInterface

	function __construct($HostScsiTopologyInterface = null) {
		$this->HostScsiTopologyInterface = $HostScsiTopologyInterface;
	}
}

class HostScsiTopologyTarget extends phpDynamicProperties {
	public $key; //string
	public $target; //int
	public $lun; //HostScsiTopologyLun
	public $transport; //HostTargetTransport

	function __construct($key = null, $target = null, $lun = null, $transport = null) {
		$this->key = $key;
		$this->target = $target;
		$this->lun = $lun;
		$this->transport = $transport;
	}
}

class ArrayOfHostScsiTopologyTarget extends phpDynamicProperties {
	public $HostScsiTopologyTarget; //HostScsiTopologyTarget

	function __construct($HostScsiTopologyTarget = null) {
		$this->HostScsiTopologyTarget = $HostScsiTopologyTarget;
	}
}

class HostScsiTopologyLun extends phpDynamicProperties {
	public $key; //string
	public $lun; //int
	public $scsiLun; //string

	function __construct($key = null, $lun = null, $scsiLun = null) {
		$this->key = $key;
		$this->lun = $lun;
		$this->scsiLun = $scsiLun;
	}
}

class ArrayOfHostScsiTopologyLun extends phpDynamicProperties {
	public $HostScsiTopologyLun; //HostScsiTopologyLun

	function __construct($HostScsiTopologyLun = null) {
		$this->HostScsiTopologyLun = $HostScsiTopologyLun;
	}
}

class HostScsiTopology extends phpDynamicProperties {
	public $adapter; //HostScsiTopologyInterface

	function __construct($adapter = null) {
		$this->adapter = $adapter;
	}
}

class HostSecuritySpec extends phpDynamicProperties {
	public $adminPassword; //string
	public $removePermission; //Permission
	public $addPermission; //Permission

	function __construct($adminPassword = null, $removePermission = null, $addPermission = null) {
		$this->adminPassword = $adminPassword;
		$this->removePermission = $removePermission;
		$this->addPermission = $addPermission;
	}
}

class HostServiceSourcePackage extends phpDynamicProperties {
	public $sourcePackageName; //string
	public $description; //string

	function __construct($sourcePackageName = null, $description = null) {
		$this->sourcePackageName = $sourcePackageName;
		$this->description = $description;
	}
}

class HostService extends phpDynamicProperties {
	public $key; //string
	public $label; //string
	public $required; //boolean
	public $uninstallable; //boolean
	public $running; //boolean
	public $ruleset; //string
	public $policy; //string
	public $sourcePackage; //HostServiceSourcePackage

	function __construct($key = null, $label = null, $required = null, $uninstallable = null, $running = null, $ruleset = null, $policy = null, $sourcePackage = null) {
		$this->key = $key;
		$this->label = $label;
		$this->required = $required;
		$this->uninstallable = $uninstallable;
		$this->running = $running;
		$this->ruleset = $ruleset;
		$this->policy = $policy;
		$this->sourcePackage = $sourcePackage;
	}
}

class ArrayOfHostService extends phpDynamicProperties {
	public $HostService; //HostService

	function __construct($HostService = null) {
		$this->HostService = $HostService;
	}
}

class HostServiceConfig extends phpDynamicProperties {
	public $serviceId; //string
	public $startupPolicy; //string

	function __construct($serviceId = null, $startupPolicy = null) {
		$this->serviceId = $serviceId;
		$this->startupPolicy = $startupPolicy;
	}
}

class ArrayOfHostServiceConfig extends phpDynamicProperties {
	public $HostServiceConfig; //HostServiceConfig

	function __construct($HostServiceConfig = null) {
		$this->HostServiceConfig = $HostServiceConfig;
	}
}

class HostServiceInfo extends phpDynamicProperties {
	public $service; //HostService

	function __construct($service = null) {
		$this->service = $service;
	}
}

class HostSnmpDestination extends phpDynamicProperties {
	public $hostName; //string
	public $port; //int
	public $community; //string

	function __construct($hostName = null, $port = null, $community = null) {
		$this->hostName = $hostName;
		$this->port = $port;
		$this->community = $community;
	}
}

class ArrayOfHostSnmpDestination extends phpDynamicProperties {
	public $HostSnmpDestination; //HostSnmpDestination

	function __construct($HostSnmpDestination = null) {
		$this->HostSnmpDestination = $HostSnmpDestination;
	}
}

class HostSnmpConfigSpec extends phpDynamicProperties {
	public $enabled; //boolean
	public $port; //int
	public $readOnlyCommunities; //string
	public $trapTargets; //HostSnmpDestination
	public $option; //KeyValue

	function __construct($enabled = null, $port = null, $readOnlyCommunities = null, $trapTargets = null, $option = null) {
		$this->enabled = $enabled;
		$this->port = $port;
		$this->readOnlyCommunities = $readOnlyCommunities;
		$this->trapTargets = $trapTargets;
		$this->option = $option;
	}
}

class HostSnmpSystemAgentLimits extends phpDynamicProperties {
	public $maxReadOnlyCommunities; //int
	public $maxTrapDestinations; //int
	public $maxCommunityLength; //int
	public $maxBufferSize; //int
	public $capability; //HostSnmpAgentCapability

	function __construct($maxReadOnlyCommunities = null, $maxTrapDestinations = null, $maxCommunityLength = null, $maxBufferSize = null, $capability = null) {
		$this->maxReadOnlyCommunities = $maxReadOnlyCommunities;
		$this->maxTrapDestinations = $maxTrapDestinations;
		$this->maxCommunityLength = $maxCommunityLength;
		$this->maxBufferSize = $maxBufferSize;
		$this->capability = $capability;
	}
}

class HostSslThumbprintInfo extends phpDynamicProperties {
	public $principal; //string
	public $ownerTag; //string
	public $sslThumbprints; //string

	function __construct($principal = null, $ownerTag = null, $sslThumbprints = null) {
		$this->principal = $principal;
		$this->ownerTag = $ownerTag;
		$this->sslThumbprints = $sslThumbprints;
	}
}

class ArrayOfHostSslThumbprintInfo extends phpDynamicProperties {
	public $HostSslThumbprintInfo; //HostSslThumbprintInfo

	function __construct($HostSslThumbprintInfo = null) {
		$this->HostSslThumbprintInfo = $HostSslThumbprintInfo;
	}
}

class HostStorageArrayTypePolicyOption extends phpDynamicProperties {
	public $policy; //ElementDescription

	function __construct($policy = null) {
		$this->policy = $policy;
	}
}

class ArrayOfHostStorageArrayTypePolicyOption extends phpDynamicProperties {
	public $HostStorageArrayTypePolicyOption; //HostStorageArrayTypePolicyOption

	function __construct($HostStorageArrayTypePolicyOption = null) {
		$this->HostStorageArrayTypePolicyOption = $HostStorageArrayTypePolicyOption;
	}
}

class HostStorageDeviceInfo extends phpDynamicProperties {
	public $hostBusAdapter; //HostHostBusAdapter
	public $scsiLun; //ScsiLun
	public $scsiTopology; //HostScsiTopology
	public $multipathInfo; //HostMultipathInfo
	public $plugStoreTopology; //HostPlugStoreTopology
	public $softwareInternetScsiEnabled; //boolean

	function __construct($hostBusAdapter = null, $scsiLun = null, $scsiTopology = null, $multipathInfo = null, $plugStoreTopology = null, $softwareInternetScsiEnabled = null) {
		$this->hostBusAdapter = $hostBusAdapter;
		$this->scsiLun = $scsiLun;
		$this->scsiTopology = $scsiTopology;
		$this->multipathInfo = $multipathInfo;
		$this->plugStoreTopology = $plugStoreTopology;
		$this->softwareInternetScsiEnabled = $softwareInternetScsiEnabled;
	}
}

class HostHardwareSummary extends phpDynamicProperties {
	public $vendor; //string
	public $model; //string
	public $uuid; //string
	public $otherIdentifyingInfo; //HostSystemIdentificationInfo
	public $memorySize; //long
	public $cpuModel; //string
	public $cpuMhz; //int
	public $numCpuPkgs; //short
	public $numCpuCores; //short
	public $numCpuThreads; //short
	public $numNics; //int
	public $numHBAs; //int

	function __construct($vendor = null, $model = null, $uuid = null, $otherIdentifyingInfo = null, $memorySize = null, $cpuModel = null, $cpuMhz = null, $numCpuPkgs = null, $numCpuCores = null, $numCpuThreads = null, $numNics = null, $numHBAs = null) {
		$this->vendor = $vendor;
		$this->model = $model;
		$this->uuid = $uuid;
		$this->otherIdentifyingInfo = $otherIdentifyingInfo;
		$this->memorySize = $memorySize;
		$this->cpuModel = $cpuModel;
		$this->cpuMhz = $cpuMhz;
		$this->numCpuPkgs = $numCpuPkgs;
		$this->numCpuCores = $numCpuCores;
		$this->numCpuThreads = $numCpuThreads;
		$this->numNics = $numNics;
		$this->numHBAs = $numHBAs;
	}
}

class HostListSummaryQuickStats extends phpDynamicProperties {
	public $overallCpuUsage; //int
	public $overallMemoryUsage; //int
	public $distributedCpuFairness; //int
	public $distributedMemoryFairness; //int
	public $uptime; //int

	function __construct($overallCpuUsage = null, $overallMemoryUsage = null, $distributedCpuFairness = null, $distributedMemoryFairness = null, $uptime = null) {
		$this->overallCpuUsage = $overallCpuUsage;
		$this->overallMemoryUsage = $overallMemoryUsage;
		$this->distributedCpuFairness = $distributedCpuFairness;
		$this->distributedMemoryFairness = $distributedMemoryFairness;
		$this->uptime = $uptime;
	}
}

class HostConfigSummary extends phpDynamicProperties {
	public $name; //string
	public $port; //int
	public $sslThumbprint; //string
	public $product; //AboutInfo
	public $vmotionEnabled; //boolean
	public $faultToleranceEnabled; //boolean
	public $featureVersion; //HostFeatureVersionInfo
	public $agentVmDatastore; //ManagedObjectReference
	public $agentVmNetwork; //ManagedObjectReference

	function __construct($name = null, $port = null, $sslThumbprint = null, $product = null, $vmotionEnabled = null, $faultToleranceEnabled = null, $featureVersion = null, $agentVmDatastore = null, $agentVmNetwork = null) {
		$this->name = $name;
		$this->port = $port;
		$this->sslThumbprint = $sslThumbprint;
		$this->product = $product;
		$this->vmotionEnabled = $vmotionEnabled;
		$this->faultToleranceEnabled = $faultToleranceEnabled;
		$this->featureVersion = $featureVersion;
		$this->agentVmDatastore = $agentVmDatastore;
		$this->agentVmNetwork = $agentVmNetwork;
	}
}

class HostListSummary extends phpDynamicProperties {
	public $host; //ManagedObjectReference
	public $hardware; //HostHardwareSummary
	public $runtime; //HostRuntimeInfo
	public $config; //HostConfigSummary
	public $quickStats; //HostListSummaryQuickStats
	public $overallStatus; //ManagedEntityStatus
	public $rebootRequired; //boolean
	public $customValue; //CustomFieldValue
	public $managementServerIp; //string
	public $maxEVCModeKey; //string
	public $currentEVCModeKey; //string

	function __construct($host = null, $hardware = null, $runtime = null, $config = null, $quickStats = null, $overallStatus = null, $rebootRequired = null, $customValue = null, $managementServerIp = null, $maxEVCModeKey = null, $currentEVCModeKey = null) {
		$this->host = $host;
		$this->hardware = $hardware;
		$this->runtime = $runtime;
		$this->config = $config;
		$this->quickStats = $quickStats;
		$this->overallStatus = $overallStatus;
		$this->rebootRequired = $rebootRequired;
		$this->customValue = $customValue;
		$this->managementServerIp = $managementServerIp;
		$this->maxEVCModeKey = $maxEVCModeKey;
		$this->currentEVCModeKey = $currentEVCModeKey;
	}
}

class HostSystemHealthInfo extends phpDynamicProperties {
	public $numericSensorInfo; //HostNumericSensorInfo

	function __construct($numericSensorInfo = null) {
		$this->numericSensorInfo = $numericSensorInfo;
	}
}

class HostSystemIdentificationInfo extends phpDynamicProperties {
	public $identifierValue; //string
	public $identifierType; //ElementDescription

	function __construct($identifierValue = null, $identifierType = null) {
		$this->identifierValue = $identifierValue;
		$this->identifierType = $identifierType;
	}
}

class ArrayOfHostSystemIdentificationInfo extends phpDynamicProperties {
	public $HostSystemIdentificationInfo; //HostSystemIdentificationInfo

	function __construct($HostSystemIdentificationInfo = null) {
		$this->HostSystemIdentificationInfo = $HostSystemIdentificationInfo;
	}
}

class HostSystemResourceInfo extends phpDynamicProperties {
	public $key; //string
	public $config; //ResourceConfigSpec
	public $child; //HostSystemResourceInfo

	function __construct($key = null, $config = null, $child = null) {
		$this->key = $key;
		$this->config = $config;
		$this->child = $child;
	}
}

class ArrayOfHostSystemResourceInfo extends phpDynamicProperties {
	public $HostSystemResourceInfo; //HostSystemResourceInfo

	function __construct($HostSystemResourceInfo = null) {
		$this->HostSystemResourceInfo = $HostSystemResourceInfo;
	}
}

class HostTargetTransport extends phpDynamicProperties {
}

class HostParallelScsiTargetTransport extends phpDynamicProperties {
}

class HostBlockAdapterTargetTransport extends phpDynamicProperties {
}

class HostFibreChannelTargetTransport extends phpDynamicProperties {
	public $portWorldWideName; //long
	public $nodeWorldWideName; //long

	function __construct($portWorldWideName = null, $nodeWorldWideName = null) {
		$this->portWorldWideName = $portWorldWideName;
		$this->nodeWorldWideName = $nodeWorldWideName;
	}
}

class HostInternetScsiTargetTransport extends phpDynamicProperties {
	public $iScsiName; //string
	public $iScsiAlias; //string
	public $address; //string

	function __construct($iScsiName = null, $iScsiAlias = null, $address = null) {
		$this->iScsiName = $iScsiName;
		$this->iScsiAlias = $iScsiAlias;
		$this->address = $address;
	}
}

class HostFibreChannelOverEthernetTargetTransport extends phpDynamicProperties {
	public $vnportMac; //string
	public $fcfMac; //string
	public $vlanId; //int

	function __construct($vnportMac = null, $fcfMac = null, $vlanId = null) {
		$this->vnportMac = $vnportMac;
		$this->fcfMac = $fcfMac;
		$this->vlanId = $vlanId;
	}
}

class HostDigestInfo extends phpDynamicProperties {
	public $digestMethod; //string
	public $digestValue; //byte
	public $objectName; //string

	function __construct($digestMethod = null, $digestValue = null, $objectName = null) {
		$this->digestMethod = $digestMethod;
		$this->digestValue = $digestValue;
		$this->objectName = $objectName;
	}
}

class HostTpmDigestInfo extends phpDynamicProperties {
	public $pcrNumber; //int

	function __construct($pcrNumber = null) {
		$this->pcrNumber = $pcrNumber;
	}
}

class ArrayOfHostTpmDigestInfo extends phpDynamicProperties {
	public $HostTpmDigestInfo; //HostTpmDigestInfo

	function __construct($HostTpmDigestInfo = null) {
		$this->HostTpmDigestInfo = $HostTpmDigestInfo;
	}
}

class HostUnresolvedVmfsExtent extends phpDynamicProperties {
	public $device; //HostScsiDiskPartition
	public $devicePath; //string
	public $vmfsUuid; //string
	public $isHeadExtent; //boolean
	public $ordinal; //int
	public $startBlock; //int
	public $endBlock; //int
	public $reason; //string

	function __construct($device = null, $devicePath = null, $vmfsUuid = null, $isHeadExtent = null, $ordinal = null, $startBlock = null, $endBlock = null, $reason = null) {
		$this->device = $device;
		$this->devicePath = $devicePath;
		$this->vmfsUuid = $vmfsUuid;
		$this->isHeadExtent = $isHeadExtent;
		$this->ordinal = $ordinal;
		$this->startBlock = $startBlock;
		$this->endBlock = $endBlock;
		$this->reason = $reason;
	}
}

class ArrayOfHostUnresolvedVmfsExtent extends phpDynamicProperties {
	public $HostUnresolvedVmfsExtent; //HostUnresolvedVmfsExtent

	function __construct($HostUnresolvedVmfsExtent = null) {
		$this->HostUnresolvedVmfsExtent = $HostUnresolvedVmfsExtent;
	}
}

class HostUnresolvedVmfsResignatureSpec extends phpDynamicProperties {
	public $extentDevicePath; //string

	function __construct($extentDevicePath = null) {
		$this->extentDevicePath = $extentDevicePath;
	}
}

class HostUnresolvedVmfsResolutionResult extends phpDynamicProperties {
	public $spec; //HostUnresolvedVmfsResolutionSpec
	public $vmfs; //HostVmfsVolume
	public $fault; //LocalizedMethodFault

	function __construct($spec = null, $vmfs = null, $fault = null) {
		$this->spec = $spec;
		$this->vmfs = $vmfs;
		$this->fault = $fault;
	}
}

class ArrayOfHostUnresolvedVmfsResolutionResult extends phpDynamicProperties {
	public $HostUnresolvedVmfsResolutionResult; //HostUnresolvedVmfsResolutionResult

	function __construct($HostUnresolvedVmfsResolutionResult = null) {
		$this->HostUnresolvedVmfsResolutionResult = $HostUnresolvedVmfsResolutionResult;
	}
}

class HostUnresolvedVmfsResolutionSpec extends phpDynamicProperties {
	public $extentDevicePath; //string
	public $uuidResolution; //string

	function __construct($extentDevicePath = null, $uuidResolution = null) {
		$this->extentDevicePath = $extentDevicePath;
		$this->uuidResolution = $uuidResolution;
	}
}

class ArrayOfHostUnresolvedVmfsResolutionSpec extends phpDynamicProperties {
	public $HostUnresolvedVmfsResolutionSpec; //HostUnresolvedVmfsResolutionSpec

	function __construct($HostUnresolvedVmfsResolutionSpec = null) {
		$this->HostUnresolvedVmfsResolutionSpec = $HostUnresolvedVmfsResolutionSpec;
	}
}

class HostUnresolvedVmfsVolumeResolveStatus extends phpDynamicProperties {
	public $resolvable; //boolean
	public $incompleteExtents; //boolean
	public $multipleCopies; //boolean

	function __construct($resolvable = null, $incompleteExtents = null, $multipleCopies = null) {
		$this->resolvable = $resolvable;
		$this->incompleteExtents = $incompleteExtents;
		$this->multipleCopies = $multipleCopies;
	}
}

class HostUnresolvedVmfsVolume extends phpDynamicProperties {
	public $extent; //HostUnresolvedVmfsExtent
	public $vmfsLabel; //string
	public $vmfsUuid; //string
	public $totalBlocks; //int
	public $resolveStatus; //HostUnresolvedVmfsVolumeResolveStatus

	function __construct($extent = null, $vmfsLabel = null, $vmfsUuid = null, $totalBlocks = null, $resolveStatus = null) {
		$this->extent = $extent;
		$this->vmfsLabel = $vmfsLabel;
		$this->vmfsUuid = $vmfsUuid;
		$this->totalBlocks = $totalBlocks;
		$this->resolveStatus = $resolveStatus;
	}
}

class ArrayOfHostUnresolvedVmfsVolume extends phpDynamicProperties {
	public $HostUnresolvedVmfsVolume; //HostUnresolvedVmfsVolume

	function __construct($HostUnresolvedVmfsVolume = null) {
		$this->HostUnresolvedVmfsVolume = $HostUnresolvedVmfsVolume;
	}
}

class HostVMotionConfig extends phpDynamicProperties {
	public $vmotionNicKey; //string
	public $enabled; //boolean

	function __construct($vmotionNicKey = null, $enabled = null) {
		$this->vmotionNicKey = $vmotionNicKey;
		$this->enabled = $enabled;
	}
}

class HostVMotionInfo extends phpDynamicProperties {
	public $netConfig; //HostVMotionNetConfig
	public $ipConfig; //HostIpConfig

	function __construct($netConfig = null, $ipConfig = null) {
		$this->netConfig = $netConfig;
		$this->ipConfig = $ipConfig;
	}
}

class HostVMotionNetConfig extends phpDynamicProperties {
	public $candidateVnic; //HostVirtualNic
	public $selectedVnic; //string

	function __construct($candidateVnic = null, $selectedVnic = null) {
		$this->candidateVnic = $candidateVnic;
		$this->selectedVnic = $selectedVnic;
	}
}

class HostVirtualNicSpec extends phpDynamicProperties {
	public $ip; //HostIpConfig
	public $mac; //string
	public $distributedVirtualPort; //DistributedVirtualSwitchPortConnection
	public $portgroup; //string
	public $mtu; //int
	public $tsoEnabled; //boolean

	function __construct($ip = null, $mac = null, $distributedVirtualPort = null, $portgroup = null, $mtu = null, $tsoEnabled = null) {
		$this->ip = $ip;
		$this->mac = $mac;
		$this->distributedVirtualPort = $distributedVirtualPort;
		$this->portgroup = $portgroup;
		$this->mtu = $mtu;
		$this->tsoEnabled = $tsoEnabled;
	}
}

class HostVirtualNicConfig extends phpDynamicProperties {
	public $changeOperation; //string
	public $device; //string
	public $portgroup; //string
	public $spec; //HostVirtualNicSpec

	function __construct($changeOperation = null, $device = null, $portgroup = null, $spec = null) {
		$this->changeOperation = $changeOperation;
		$this->device = $device;
		$this->portgroup = $portgroup;
		$this->spec = $spec;
	}
}

class ArrayOfHostVirtualNicConfig extends phpDynamicProperties {
	public $HostVirtualNicConfig; //HostVirtualNicConfig

	function __construct($HostVirtualNicConfig = null) {
		$this->HostVirtualNicConfig = $HostVirtualNicConfig;
	}
}

class HostVirtualNic extends phpDynamicProperties {
	public $device; //string
	public $key; //string
	public $portgroup; //string
	public $spec; //HostVirtualNicSpec
	public $port; //string

	function __construct($device = null, $key = null, $portgroup = null, $spec = null, $port = null) {
		$this->device = $device;
		$this->key = $key;
		$this->portgroup = $portgroup;
		$this->spec = $spec;
		$this->port = $port;
	}
}

class ArrayOfHostVirtualNic extends phpDynamicProperties {
	public $HostVirtualNic; //HostVirtualNic

	function __construct($HostVirtualNic = null) {
		$this->HostVirtualNic = $HostVirtualNic;
	}
}

class HostVirtualNicConnection extends phpDynamicProperties {
	public $portgroup; //string
	public $dvPort; //DistributedVirtualSwitchPortConnection

	function __construct($portgroup = null, $dvPort = null) {
		$this->portgroup = $portgroup;
		$this->dvPort = $dvPort;
	}
}

class HostVirtualNicManagerNicTypeSelection extends phpDynamicProperties {
	public $vnic; //HostVirtualNicConnection
	public $nicType; //string

	function __construct($vnic = null, $nicType = null) {
		$this->vnic = $vnic;
		$this->nicType = $nicType;
	}
}

class ArrayOfHostVirtualNicManagerNicTypeSelection extends phpDynamicProperties {
	public $HostVirtualNicManagerNicTypeSelection; //HostVirtualNicManagerNicTypeSelection

	function __construct($HostVirtualNicManagerNicTypeSelection = null) {
		$this->HostVirtualNicManagerNicTypeSelection = $HostVirtualNicManagerNicTypeSelection;
	}
}

class VirtualNicManagerNetConfig extends phpDynamicProperties {
	public $nicType; //string
	public $multiSelectAllowed; //boolean
	public $candidateVnic; //HostVirtualNic
	public $selectedVnic; //string

	function __construct($nicType = null, $multiSelectAllowed = null, $candidateVnic = null, $selectedVnic = null) {
		$this->nicType = $nicType;
		$this->multiSelectAllowed = $multiSelectAllowed;
		$this->candidateVnic = $candidateVnic;
		$this->selectedVnic = $selectedVnic;
	}
}

class ArrayOfVirtualNicManagerNetConfig extends phpDynamicProperties {
	public $VirtualNicManagerNetConfig; //VirtualNicManagerNetConfig

	function __construct($VirtualNicManagerNetConfig = null) {
		$this->VirtualNicManagerNetConfig = $VirtualNicManagerNetConfig;
	}
}

class HostVirtualNicManagerInfo extends phpDynamicProperties {
	public $netConfig; //VirtualNicManagerNetConfig

	function __construct($netConfig = null) {
		$this->netConfig = $netConfig;
	}
}

class HostVirtualSwitchBridge extends phpDynamicProperties {
}

class HostVirtualSwitchAutoBridge extends phpDynamicProperties {
	public $excludedNicDevice; //string

	function __construct($excludedNicDevice = null) {
		$this->excludedNicDevice = $excludedNicDevice;
	}
}

class HostVirtualSwitchSimpleBridge extends phpDynamicProperties {
	public $nicDevice; //string

	function __construct($nicDevice = null) {
		$this->nicDevice = $nicDevice;
	}
}

class HostVirtualSwitchBondBridge extends phpDynamicProperties {
	public $nicDevice; //string
	public $beacon; //HostVirtualSwitchBeaconConfig
	public $linkDiscoveryProtocolConfig; //LinkDiscoveryProtocolConfig

	function __construct($nicDevice = null, $beacon = null, $linkDiscoveryProtocolConfig = null) {
		$this->nicDevice = $nicDevice;
		$this->beacon = $beacon;
		$this->linkDiscoveryProtocolConfig = $linkDiscoveryProtocolConfig;
	}
}

class HostVirtualSwitchBeaconConfig extends phpDynamicProperties {
	public $interval; //int

	function __construct($interval = null) {
		$this->interval = $interval;
	}
}

class HostVirtualSwitchSpec extends phpDynamicProperties {
	public $numPorts; //int
	public $bridge; //HostVirtualSwitchBridge
	public $policy; //HostNetworkPolicy
	public $mtu; //int

	function __construct($numPorts = null, $bridge = null, $policy = null, $mtu = null) {
		$this->numPorts = $numPorts;
		$this->bridge = $bridge;
		$this->policy = $policy;
		$this->mtu = $mtu;
	}
}

class HostVirtualSwitchConfig extends phpDynamicProperties {
	public $changeOperation; //string
	public $name; //string
	public $spec; //HostVirtualSwitchSpec

	function __construct($changeOperation = null, $name = null, $spec = null) {
		$this->changeOperation = $changeOperation;
		$this->name = $name;
		$this->spec = $spec;
	}
}

class ArrayOfHostVirtualSwitchConfig extends phpDynamicProperties {
	public $HostVirtualSwitchConfig; //HostVirtualSwitchConfig

	function __construct($HostVirtualSwitchConfig = null) {
		$this->HostVirtualSwitchConfig = $HostVirtualSwitchConfig;
	}
}

class HostVirtualSwitch extends phpDynamicProperties {
	public $name; //string
	public $key; //string
	public $numPorts; //int
	public $numPortsAvailable; //int
	public $mtu; //int
	public $portgroup; //string
	public $pnic; //string
	public $spec; //HostVirtualSwitchSpec

	function __construct($name = null, $key = null, $numPorts = null, $numPortsAvailable = null, $mtu = null, $portgroup = null, $pnic = null, $spec = null) {
		$this->name = $name;
		$this->key = $key;
		$this->numPorts = $numPorts;
		$this->numPortsAvailable = $numPortsAvailable;
		$this->mtu = $mtu;
		$this->portgroup = $portgroup;
		$this->pnic = $pnic;
		$this->spec = $spec;
	}
}

class ArrayOfHostVirtualSwitch extends phpDynamicProperties {
	public $HostVirtualSwitch; //HostVirtualSwitch

	function __construct($HostVirtualSwitch = null) {
		$this->HostVirtualSwitch = $HostVirtualSwitch;
	}
}

class HostVmciAccessManagerAccessSpec extends phpDynamicProperties {
	public $vm; //ManagedObjectReference
	public $services; //string
	public $mode; //string

	function __construct($vm = null, $services = null, $mode = null) {
		$this->vm = $vm;
		$this->services = $services;
		$this->mode = $mode;
	}
}

class ArrayOfHostVmciAccessManagerAccessSpec extends phpDynamicProperties {
	public $HostVmciAccessManagerAccessSpec; //HostVmciAccessManagerAccessSpec

	function __construct($HostVmciAccessManagerAccessSpec = null) {
		$this->HostVmciAccessManagerAccessSpec = $HostVmciAccessManagerAccessSpec;
	}
}

class HostVmfsRescanResult extends phpDynamicProperties {
	public $host; //ManagedObjectReference
	public $fault; //LocalizedMethodFault

	function __construct($host = null, $fault = null) {
		$this->host = $host;
		$this->fault = $fault;
	}
}

class ArrayOfHostVmfsRescanResult extends phpDynamicProperties {
	public $HostVmfsRescanResult; //HostVmfsRescanResult

	function __construct($HostVmfsRescanResult = null) {
		$this->HostVmfsRescanResult = $HostVmfsRescanResult;
	}
}

class HostVmfsSpec extends phpDynamicProperties {
	public $extent; //HostScsiDiskPartition
	public $blockSizeMb; //int
	public $majorVersion; //int
	public $volumeName; //string

	function __construct($extent = null, $blockSizeMb = null, $majorVersion = null, $volumeName = null) {
		$this->extent = $extent;
		$this->blockSizeMb = $blockSizeMb;
		$this->majorVersion = $majorVersion;
		$this->volumeName = $volumeName;
	}
}

class HostVmfsVolume extends phpDynamicProperties {
	public $blockSizeMb; //int
	public $maxBlocks; //int
	public $majorVersion; //int
	public $version; //string
	public $uuid; //string
	public $extent; //HostScsiDiskPartition
	public $vmfsUpgradable; //boolean
	public $forceMountedInfo; //HostForceMountedInfo
	public $ssd; //boolean

	function __construct($blockSizeMb = null, $maxBlocks = null, $majorVersion = null, $version = null, $uuid = null, $extent = null, $vmfsUpgradable = null, $forceMountedInfo = null, $ssd = null) {
		$this->blockSizeMb = $blockSizeMb;
		$this->maxBlocks = $maxBlocks;
		$this->majorVersion = $majorVersion;
		$this->version = $version;
		$this->uuid = $uuid;
		$this->extent = $extent;
		$this->vmfsUpgradable = $vmfsUpgradable;
		$this->forceMountedInfo = $forceMountedInfo;
		$this->ssd = $ssd;
	}
}

class NetDhcpConfigInfoDhcpOptions extends phpDynamicProperties {
	public $enable; //boolean
	public $config; //KeyValue

	function __construct($enable = null, $config = null) {
		$this->enable = $enable;
		$this->config = $config;
	}
}

class NetDhcpConfigInfo extends phpDynamicProperties {
	public $ipv6; //NetDhcpConfigInfoDhcpOptions
	public $ipv4; //NetDhcpConfigInfoDhcpOptions

	function __construct($ipv6 = null, $ipv4 = null) {
		$this->ipv6 = $ipv6;
		$this->ipv4 = $ipv4;
	}
}

class NetDhcpConfigSpecDhcpOptionsSpec extends phpDynamicProperties {
	public $enable; //boolean
	public $config; //KeyValue
	public $operation; //string

	function __construct($enable = null, $config = null, $operation = null) {
		$this->enable = $enable;
		$this->config = $config;
		$this->operation = $operation;
	}
}

class NetDhcpConfigSpec extends phpDynamicProperties {
	public $ipv6; //NetDhcpConfigSpecDhcpOptionsSpec
	public $ipv4; //NetDhcpConfigSpecDhcpOptionsSpec

	function __construct($ipv6 = null, $ipv4 = null) {
		$this->ipv6 = $ipv6;
		$this->ipv4 = $ipv4;
	}
}

class NetDnsConfigInfo extends phpDynamicProperties {
	public $dhcp; //boolean
	public $hostName; //string
	public $domainName; //string
	public $ipAddress; //string
	public $searchDomain; //string

	function __construct($dhcp = null, $hostName = null, $domainName = null, $ipAddress = null, $searchDomain = null) {
		$this->dhcp = $dhcp;
		$this->hostName = $hostName;
		$this->domainName = $domainName;
		$this->ipAddress = $ipAddress;
		$this->searchDomain = $searchDomain;
	}
}

class NetDnsConfigSpec extends phpDynamicProperties {
	public $dhcp; //boolean
	public $hostName; //string
	public $domainName; //string
	public $ipAddress; //string
	public $searchDomain; //string

	function __construct($dhcp = null, $hostName = null, $domainName = null, $ipAddress = null, $searchDomain = null) {
		$this->dhcp = $dhcp;
		$this->hostName = $hostName;
		$this->domainName = $domainName;
		$this->ipAddress = $ipAddress;
		$this->searchDomain = $searchDomain;
	}
}

class NetIpConfigInfoIpAddress extends phpDynamicProperties {
	public $ipAddress; //string
	public $prefixLength; //int
	public $origin; //string
	public $state; //string
	public $lifetime; //dateTime

	function __construct($ipAddress = null, $prefixLength = null, $origin = null, $state = null, $lifetime = null) {
		$this->ipAddress = $ipAddress;
		$this->prefixLength = $prefixLength;
		$this->origin = $origin;
		$this->state = $state;
		$this->lifetime = $lifetime;
	}
}

class ArrayOfNetIpConfigInfoIpAddress extends phpDynamicProperties {
	public $NetIpConfigInfoIpAddress; //NetIpConfigInfoIpAddress

	function __construct($NetIpConfigInfoIpAddress = null) {
		$this->NetIpConfigInfoIpAddress = $NetIpConfigInfoIpAddress;
	}
}

class NetIpConfigInfo extends phpDynamicProperties {
	public $ipAddress; //NetIpConfigInfoIpAddress
	public $dhcp; //NetDhcpConfigInfo
	public $autoConfigurationEnabled; //boolean

	function __construct($ipAddress = null, $dhcp = null, $autoConfigurationEnabled = null) {
		$this->ipAddress = $ipAddress;
		$this->dhcp = $dhcp;
		$this->autoConfigurationEnabled = $autoConfigurationEnabled;
	}
}

class NetIpConfigSpecIpAddressSpec extends phpDynamicProperties {
	public $ipAddress; //string
	public $prefixLength; //int
	public $operation; //string

	function __construct($ipAddress = null, $prefixLength = null, $operation = null) {
		$this->ipAddress = $ipAddress;
		$this->prefixLength = $prefixLength;
		$this->operation = $operation;
	}
}

class ArrayOfNetIpConfigSpecIpAddressSpec extends phpDynamicProperties {
	public $NetIpConfigSpecIpAddressSpec; //NetIpConfigSpecIpAddressSpec

	function __construct($NetIpConfigSpecIpAddressSpec = null) {
		$this->NetIpConfigSpecIpAddressSpec = $NetIpConfigSpecIpAddressSpec;
	}
}

class NetIpConfigSpec extends phpDynamicProperties {
	public $ipAddress; //NetIpConfigSpecIpAddressSpec
	public $dhcp; //NetDhcpConfigSpec
	public $autoConfigurationEnabled; //boolean

	function __construct($ipAddress = null, $dhcp = null, $autoConfigurationEnabled = null) {
		$this->ipAddress = $ipAddress;
		$this->dhcp = $dhcp;
		$this->autoConfigurationEnabled = $autoConfigurationEnabled;
	}
}

class NetIpRouteConfigInfoGateway extends phpDynamicProperties {
	public $ipAddress; //string
	public $device; //string

	function __construct($ipAddress = null, $device = null) {
		$this->ipAddress = $ipAddress;
		$this->device = $device;
	}
}

class NetIpRouteConfigInfoIpRoute extends phpDynamicProperties {
	public $network; //string
	public $prefixLength; //int
	public $gateway; //NetIpRouteConfigInfoGateway

	function __construct($network = null, $prefixLength = null, $gateway = null) {
		$this->network = $network;
		$this->prefixLength = $prefixLength;
		$this->gateway = $gateway;
	}
}

class ArrayOfNetIpRouteConfigInfoIpRoute extends phpDynamicProperties {
	public $NetIpRouteConfigInfoIpRoute; //NetIpRouteConfigInfoIpRoute

	function __construct($NetIpRouteConfigInfoIpRoute = null) {
		$this->NetIpRouteConfigInfoIpRoute = $NetIpRouteConfigInfoIpRoute;
	}
}

class NetIpRouteConfigInfo extends phpDynamicProperties {
	public $ipRoute; //NetIpRouteConfigInfoIpRoute

	function __construct($ipRoute = null) {
		$this->ipRoute = $ipRoute;
	}
}

class NetIpRouteConfigSpecGatewaySpec extends phpDynamicProperties {
	public $ipAddress; //string
	public $device; //string

	function __construct($ipAddress = null, $device = null) {
		$this->ipAddress = $ipAddress;
		$this->device = $device;
	}
}

class NetIpRouteConfigSpecIpRouteSpec extends phpDynamicProperties {
	public $network; //string
	public $prefixLength; //int
	public $gateway; //NetIpRouteConfigSpecGatewaySpec
	public $operation; //string

	function __construct($network = null, $prefixLength = null, $gateway = null, $operation = null) {
		$this->network = $network;
		$this->prefixLength = $prefixLength;
		$this->gateway = $gateway;
		$this->operation = $operation;
	}
}

class ArrayOfNetIpRouteConfigSpecIpRouteSpec extends phpDynamicProperties {
	public $NetIpRouteConfigSpecIpRouteSpec; //NetIpRouteConfigSpecIpRouteSpec

	function __construct($NetIpRouteConfigSpecIpRouteSpec = null) {
		$this->NetIpRouteConfigSpecIpRouteSpec = $NetIpRouteConfigSpecIpRouteSpec;
	}
}

class NetIpRouteConfigSpec extends phpDynamicProperties {
	public $ipRoute; //NetIpRouteConfigSpecIpRouteSpec

	function __construct($ipRoute = null) {
		$this->ipRoute = $ipRoute;
	}
}

class NetIpStackInfoNetToMedia extends phpDynamicProperties {
	public $ipAddress; //string
	public $physicalAddress; //string
	public $device; //string
	public $type; //string

	function __construct($ipAddress = null, $physicalAddress = null, $device = null, $type = null) {
		$this->ipAddress = $ipAddress;
		$this->physicalAddress = $physicalAddress;
		$this->device = $device;
		$this->type = $type;
	}
}

class ArrayOfNetIpStackInfoNetToMedia extends phpDynamicProperties {
	public $NetIpStackInfoNetToMedia; //NetIpStackInfoNetToMedia

	function __construct($NetIpStackInfoNetToMedia = null) {
		$this->NetIpStackInfoNetToMedia = $NetIpStackInfoNetToMedia;
	}
}

class NetIpStackInfoDefaultRouter extends phpDynamicProperties {
	public $ipAddress; //string
	public $device; //string
	public $lifetime; //dateTime
	public $preference; //string

	function __construct($ipAddress = null, $device = null, $lifetime = null, $preference = null) {
		$this->ipAddress = $ipAddress;
		$this->device = $device;
		$this->lifetime = $lifetime;
		$this->preference = $preference;
	}
}

class ArrayOfNetIpStackInfoDefaultRouter extends phpDynamicProperties {
	public $NetIpStackInfoDefaultRouter; //NetIpStackInfoDefaultRouter

	function __construct($NetIpStackInfoDefaultRouter = null) {
		$this->NetIpStackInfoDefaultRouter = $NetIpStackInfoDefaultRouter;
	}
}

class NetIpStackInfo extends phpDynamicProperties {
	public $neighbor; //NetIpStackInfoNetToMedia
	public $defaultRouter; //NetIpStackInfoDefaultRouter

	function __construct($neighbor = null, $defaultRouter = null) {
		$this->neighbor = $neighbor;
		$this->defaultRouter = $defaultRouter;
	}
}

class NetBIOSConfigInfo extends phpDynamicProperties {
	public $mode; //string

	function __construct($mode = null) {
		$this->mode = $mode;
	}
}

class WinNetBIOSConfigInfo extends phpDynamicProperties {
	public $primaryWINS; //string
	public $secondaryWINS; //string

	function __construct($primaryWINS = null, $secondaryWINS = null) {
		$this->primaryWINS = $primaryWINS;
		$this->secondaryWINS = $secondaryWINS;
	}
}

class ArrayUpdateSpec extends phpDynamicProperties {
	public $operation; //ArrayUpdateOperation
	public $removeKey; //anyType

	function __construct($operation = null, $removeKey = null) {
		$this->operation = $operation;
		$this->removeKey = $removeKey;
	}
}

class BoolOption extends phpDynamicProperties {
	public $supported; //boolean
	public $defaultValue; //boolean

	function __construct($supported = null, $defaultValue = null) {
		$this->supported = $supported;
		$this->defaultValue = $defaultValue;
	}
}

class ChoiceOption extends phpDynamicProperties {
	public $choiceInfo; //ElementDescription
	public $defaultIndex; //int

	function __construct($choiceInfo = null, $defaultIndex = null) {
		$this->choiceInfo = $choiceInfo;
		$this->defaultIndex = $defaultIndex;
	}
}

class FloatOption extends phpDynamicProperties {
	public $min; //float
	public $max; //float
	public $defaultValue; //float

	function __construct($min = null, $max = null, $defaultValue = null) {
		$this->min = $min;
		$this->max = $max;
		$this->defaultValue = $defaultValue;
	}
}

class IntOption extends phpDynamicProperties {
	public $min; //int
	public $max; //int
	public $defaultValue; //int

	function __construct($min = null, $max = null, $defaultValue = null) {
		$this->min = $min;
		$this->max = $max;
		$this->defaultValue = $defaultValue;
	}
}

class LongOption extends phpDynamicProperties {
	public $min; //long
	public $max; //long
	public $defaultValue; //long

	function __construct($min = null, $max = null, $defaultValue = null) {
		$this->min = $min;
		$this->max = $max;
		$this->defaultValue = $defaultValue;
	}
}

class OptionDef extends phpDynamicProperties {
	public $optionType; //OptionType

	function __construct($optionType = null) {
		$this->optionType = $optionType;
	}
}

class ArrayOfOptionDef extends phpDynamicProperties {
	public $OptionDef; //OptionDef

	function __construct($OptionDef = null) {
		$this->OptionDef = $OptionDef;
	}
}

class OptionType extends phpDynamicProperties {
	public $valueIsReadonly; //boolean

	function __construct($valueIsReadonly = null) {
		$this->valueIsReadonly = $valueIsReadonly;
	}
}

class OptionValue extends phpDynamicProperties {
	public $key; //string
	public $value; //anyType

	function __construct($key = null, $value = null) {
		$this->key = $key;
		$this->value = $value;
	}
}

class ArrayOfOptionValue extends phpDynamicProperties {
	public $OptionValue; //OptionValue

	function __construct($OptionValue = null) {
		$this->OptionValue = $OptionValue;
	}
}

class StringOption extends phpDynamicProperties {
	public $defaultValue; //string
	public $validCharacters; //string

	function __construct($defaultValue = null, $validCharacters = null) {
		$this->defaultValue = $defaultValue;
		$this->validCharacters = $validCharacters;
	}
}

class ApplyProfile extends phpDynamicProperties {
	public $enabled; //boolean
	public $policy; //ProfilePolicy
	public $profileTypeName; //string
	public $profileVersion; //string
	public $property; //ProfileApplyProfileProperty

	function __construct($enabled = null, $policy = null, $profileTypeName = null, $profileVersion = null, $property = null) {
		$this->enabled = $enabled;
		$this->policy = $policy;
		$this->profileTypeName = $profileTypeName;
		$this->profileVersion = $profileVersion;
		$this->property = $property;
	}
}

class ArrayOfApplyProfile extends phpDynamicProperties {
	public $ApplyProfile; //ApplyProfile

	function __construct($ApplyProfile = null) {
		$this->ApplyProfile = $ApplyProfile;
	}
}

class ProfileApplyProfileElement extends phpDynamicProperties {
	public $key; //string

	function __construct($key = null) {
		$this->key = $key;
	}
}

class ProfileApplyProfileProperty extends phpDynamicProperties {
	public $propertyName; //string
	public $array; //boolean
	public $profile; //ApplyProfile

	function __construct($propertyName = null, $array = null, $profile = null) {
		$this->propertyName = $propertyName;
		$this->array = $array;
		$this->profile = $profile;
	}
}

class ArrayOfProfileApplyProfileProperty extends phpDynamicProperties {
	public $ProfileApplyProfileProperty; //ProfileApplyProfileProperty

	function __construct($ProfileApplyProfileProperty = null) {
		$this->ProfileApplyProfileProperty = $ProfileApplyProfileProperty;
	}
}

class ComplianceLocator extends phpDynamicProperties {
	public $expressionName; //string
	public $applyPath; //ProfilePropertyPath

	function __construct($expressionName = null, $applyPath = null) {
		$this->expressionName = $expressionName;
		$this->applyPath = $applyPath;
	}
}

class ArrayOfComplianceLocator extends phpDynamicProperties {
	public $ComplianceLocator; //ComplianceLocator

	function __construct($ComplianceLocator = null) {
		$this->ComplianceLocator = $ComplianceLocator;
	}
}

class ComplianceProfile extends phpDynamicProperties {
	public $expression; //ProfileExpression
	public $rootExpression; //string

	function __construct($expression = null, $rootExpression = null) {
		$this->expression = $expression;
		$this->rootExpression = $rootExpression;
	}
}

class ComplianceFailure extends phpDynamicProperties {
	public $failureType; //string
	public $message; //LocalizableMessage
	public $expressionName; //string

	function __construct($failureType = null, $message = null, $expressionName = null) {
		$this->failureType = $failureType;
		$this->message = $message;
		$this->expressionName = $expressionName;
	}
}

class ArrayOfComplianceFailure extends phpDynamicProperties {
	public $ComplianceFailure; //ComplianceFailure

	function __construct($ComplianceFailure = null) {
		$this->ComplianceFailure = $ComplianceFailure;
	}
}

class ComplianceResult extends phpDynamicProperties {
	public $profile; //ManagedObjectReference
	public $complianceStatus; //string
	public $entity; //ManagedObjectReference
	public $checkTime; //dateTime
	public $failure; //ComplianceFailure

	function __construct($profile = null, $complianceStatus = null, $entity = null, $checkTime = null, $failure = null) {
		$this->profile = $profile;
		$this->complianceStatus = $complianceStatus;
		$this->entity = $entity;
		$this->checkTime = $checkTime;
		$this->failure = $failure;
	}
}

class ArrayOfComplianceResult extends phpDynamicProperties {
	public $ComplianceResult; //ComplianceResult

	function __construct($ComplianceResult = null) {
		$this->ComplianceResult = $ComplianceResult;
	}
}

class ProfileDeferredPolicyOptionParameter extends phpDynamicProperties {
	public $inputPath; //ProfilePropertyPath
	public $parameter; //KeyAnyValue

	function __construct($inputPath = null, $parameter = null) {
		$this->inputPath = $inputPath;
		$this->parameter = $parameter;
	}
}

class ArrayOfProfileDeferredPolicyOptionParameter extends phpDynamicProperties {
	public $ProfileDeferredPolicyOptionParameter; //ProfileDeferredPolicyOptionParameter

	function __construct($ProfileDeferredPolicyOptionParameter = null) {
		$this->ProfileDeferredPolicyOptionParameter = $ProfileDeferredPolicyOptionParameter;
	}
}

class ProfileExpression extends phpDynamicProperties {
	public $id; //string
	public $displayName; //string
	public $negated; //boolean

	function __construct($id = null, $displayName = null, $negated = null) {
		$this->id = $id;
		$this->displayName = $displayName;
		$this->negated = $negated;
	}
}

class ArrayOfProfileExpression extends phpDynamicProperties {
	public $ProfileExpression; //ProfileExpression

	function __construct($ProfileExpression = null) {
		$this->ProfileExpression = $ProfileExpression;
	}
}

class ProfileSimpleExpression extends phpDynamicProperties {
	public $expressionType; //string
	public $parameter; //KeyAnyValue

	function __construct($expressionType = null, $parameter = null) {
		$this->expressionType = $expressionType;
		$this->parameter = $parameter;
	}
}

class ProfileCompositeExpression extends phpDynamicProperties {
	public $operator; //string
	public $expressionName; //string

	function __construct($operator = null, $expressionName = null) {
		$this->operator = $operator;
		$this->expressionName = $expressionName;
	}
}

class ProfileExpressionMetadata extends phpDynamicProperties {
	public $expressionId; //ExtendedElementDescription
	public $parameter; //ProfileParameterMetadata

	function __construct($expressionId = null, $parameter = null) {
		$this->expressionId = $expressionId;
		$this->parameter = $parameter;
	}
}

class ArrayOfProfileExpressionMetadata extends phpDynamicProperties {
	public $ProfileExpressionMetadata; //ProfileExpressionMetadata

	function __construct($ProfileExpressionMetadata = null) {
		$this->ProfileExpressionMetadata = $ProfileExpressionMetadata;
	}
}

class ProfileParameterMetadata extends phpDynamicProperties {
	public $id; //ExtendedElementDescription
	public $type; //string
	public $optional; //boolean
	public $defaultValue; //anyType

	function __construct($id = null, $type = null, $optional = null, $defaultValue = null) {
		$this->id = $id;
		$this->type = $type;
		$this->optional = $optional;
		$this->defaultValue = $defaultValue;
	}
}

class ArrayOfProfileParameterMetadata extends phpDynamicProperties {
	public $ProfileParameterMetadata; //ProfileParameterMetadata

	function __construct($ProfileParameterMetadata = null) {
		$this->ProfileParameterMetadata = $ProfileParameterMetadata;
	}
}

class ProfilePolicy extends phpDynamicProperties {
	public $id; //string
	public $policyOption; //PolicyOption

	function __construct($id = null, $policyOption = null) {
		$this->id = $id;
		$this->policyOption = $policyOption;
	}
}

class ArrayOfProfilePolicy extends phpDynamicProperties {
	public $ProfilePolicy; //ProfilePolicy

	function __construct($ProfilePolicy = null) {
		$this->ProfilePolicy = $ProfilePolicy;
	}
}

class ProfilePolicyOptionMetadata extends phpDynamicProperties {
	public $id; //ExtendedElementDescription
	public $parameter; //ProfileParameterMetadata

	function __construct($id = null, $parameter = null) {
		$this->id = $id;
		$this->parameter = $parameter;
	}
}

class ArrayOfProfilePolicyOptionMetadata extends phpDynamicProperties {
	public $ProfilePolicyOptionMetadata; //ProfilePolicyOptionMetadata

	function __construct($ProfilePolicyOptionMetadata = null) {
		$this->ProfilePolicyOptionMetadata = $ProfilePolicyOptionMetadata;
	}
}

class ProfileCompositePolicyOptionMetadata extends phpDynamicProperties {
	public $option; //string

	function __construct($option = null) {
		$this->option = $option;
	}
}

class UserInputRequiredParameterMetadata extends phpDynamicProperties {
	public $userInputParameter; //ProfileParameterMetadata

	function __construct($userInputParameter = null) {
		$this->userInputParameter = $userInputParameter;
	}
}

class ProfilePolicyMetadata extends phpDynamicProperties {
	public $id; //ExtendedElementDescription
	public $possibleOption; //ProfilePolicyOptionMetadata

	function __construct($id = null, $possibleOption = null) {
		$this->id = $id;
		$this->possibleOption = $possibleOption;
	}
}

class ArrayOfProfilePolicyMetadata extends phpDynamicProperties {
	public $ProfilePolicyMetadata; //ProfilePolicyMetadata

	function __construct($ProfilePolicyMetadata = null) {
		$this->ProfilePolicyMetadata = $ProfilePolicyMetadata;
	}
}

class PolicyOption extends phpDynamicProperties {
	public $id; //string
	public $parameter; //KeyAnyValue

	function __construct($id = null, $parameter = null) {
		$this->id = $id;
		$this->parameter = $parameter;
	}
}

class ArrayOfPolicyOption extends phpDynamicProperties {
	public $PolicyOption; //PolicyOption

	function __construct($PolicyOption = null) {
		$this->PolicyOption = $PolicyOption;
	}
}

class CompositePolicyOption extends phpDynamicProperties {
	public $option; //PolicyOption

	function __construct($option = null) {
		$this->option = $option;
	}
}

class ProfileCreateSpec extends phpDynamicProperties {
	public $name; //string
	public $annotation; //string
	public $enabled; //boolean

	function __construct($name = null, $annotation = null, $enabled = null) {
		$this->name = $name;
		$this->annotation = $annotation;
		$this->enabled = $enabled;
	}
}

class ProfileSerializedCreateSpec extends phpDynamicProperties {
	public $profileConfigString; //string

	function __construct($profileConfigString = null) {
		$this->profileConfigString = $profileConfigString;
	}
}

class ProfileConfigInfo extends phpDynamicProperties {
	public $name; //string
	public $annotation; //string
	public $enabled; //boolean

	function __construct($name = null, $annotation = null, $enabled = null) {
		$this->name = $name;
		$this->annotation = $annotation;
		$this->enabled = $enabled;
	}
}

class ProfileDescriptionSection extends phpDynamicProperties {
	public $description; //ExtendedElementDescription
	public $message; //LocalizableMessage

	function __construct($description = null, $message = null) {
		$this->description = $description;
		$this->message = $message;
	}
}

class ArrayOfProfileDescriptionSection extends phpDynamicProperties {
	public $ProfileDescriptionSection; //ProfileDescriptionSection

	function __construct($ProfileDescriptionSection = null) {
		$this->ProfileDescriptionSection = $ProfileDescriptionSection;
	}
}

class ProfileDescription extends phpDynamicProperties {
	public $section; //ProfileDescriptionSection

	function __construct($section = null) {
		$this->section = $section;
	}
}

class ProfileMetadataProfileSortSpec extends phpDynamicProperties {
	public $policyId; //string
	public $parameter; //string

	function __construct($policyId = null, $parameter = null) {
		$this->policyId = $policyId;
		$this->parameter = $parameter;
	}
}

class ArrayOfProfileMetadataProfileSortSpec extends phpDynamicProperties {
	public $ProfileMetadataProfileSortSpec; //ProfileMetadataProfileSortSpec

	function __construct($ProfileMetadataProfileSortSpec = null) {
		$this->ProfileMetadataProfileSortSpec = $ProfileMetadataProfileSortSpec;
	}
}

class ProfileMetadata extends phpDynamicProperties {
	public $key; //string
	public $profileTypeName; //string
	public $description; //ExtendedDescription
	public $sortSpec; //ProfileMetadataProfileSortSpec

	function __construct($key = null, $profileTypeName = null, $description = null, $sortSpec = null) {
		$this->key = $key;
		$this->profileTypeName = $profileTypeName;
		$this->description = $description;
		$this->sortSpec = $sortSpec;
	}
}

class ArrayOfProfileMetadata extends phpDynamicProperties {
	public $ProfileMetadata; //ProfileMetadata

	function __construct($ProfileMetadata = null) {
		$this->ProfileMetadata = $ProfileMetadata;
	}
}

class ProfilePropertyPath extends phpDynamicProperties {
	public $profilePath; //string
	public $policyId; //string

	function __construct($profilePath = null, $policyId = null) {
		$this->profilePath = $profilePath;
		$this->policyId = $policyId;
	}
}

class ArrayOfProfilePropertyPath extends phpDynamicProperties {
	public $ProfilePropertyPath; //ProfilePropertyPath

	function __construct($ProfilePropertyPath = null) {
		$this->ProfilePropertyPath = $ProfilePropertyPath;
	}
}

class ProfileProfileStructure extends phpDynamicProperties {
	public $profileTypeName; //string
	public $child; //ProfileProfileStructureProperty

	function __construct($profileTypeName = null, $child = null) {
		$this->profileTypeName = $profileTypeName;
		$this->child = $child;
	}
}

class ProfileProfileStructureProperty extends phpDynamicProperties {
	public $propertyName; //string
	public $array; //boolean
	public $element; //ProfileProfileStructure

	function __construct($propertyName = null, $array = null, $element = null) {
		$this->propertyName = $propertyName;
		$this->array = $array;
		$this->element = $element;
	}
}

class ArrayOfProfileProfileStructureProperty extends phpDynamicProperties {
	public $ProfileProfileStructureProperty; //ProfileProfileStructureProperty

	function __construct($ProfileProfileStructureProperty = null) {
		$this->ProfileProfileStructureProperty = $ProfileProfileStructureProperty;
	}
}

class ClusterProfileConfigInfo extends phpDynamicProperties {
	public $complyProfile; //ComplianceProfile

	function __construct($complyProfile = null) {
		$this->complyProfile = $complyProfile;
	}
}

class ClusterProfileCreateSpec extends phpDynamicProperties {
}

class ClusterProfileConfigSpec extends phpDynamicProperties {
}

class ClusterProfileCompleteConfigSpec extends phpDynamicProperties {
	public $complyProfile; //ComplianceProfile

	function __construct($complyProfile = null) {
		$this->complyProfile = $complyProfile;
	}
}

class ClusterProfileConfigServiceCreateSpec extends phpDynamicProperties {
	public $serviceType; //string

	function __construct($serviceType = null) {
		$this->serviceType = $serviceType;
	}
}

class AnswerFile extends phpDynamicProperties {
	public $userInput; //ProfileDeferredPolicyOptionParameter
	public $createdTime; //dateTime
	public $modifiedTime; //dateTime

	function __construct($userInput = null, $createdTime = null, $modifiedTime = null) {
		$this->userInput = $userInput;
		$this->createdTime = $createdTime;
		$this->modifiedTime = $modifiedTime;
	}
}

class AnswerFileStatusError extends phpDynamicProperties {
	public $userInputPath; //ProfilePropertyPath
	public $errMsg; //LocalizableMessage

	function __construct($userInputPath = null, $errMsg = null) {
		$this->userInputPath = $userInputPath;
		$this->errMsg = $errMsg;
	}
}

class ArrayOfAnswerFileStatusError extends phpDynamicProperties {
	public $AnswerFileStatusError; //AnswerFileStatusError

	function __construct($AnswerFileStatusError = null) {
		$this->AnswerFileStatusError = $AnswerFileStatusError;
	}
}

class AnswerFileStatusResult extends phpDynamicProperties {
	public $checkedTime; //dateTime
	public $host; //ManagedObjectReference
	public $status; //string
	public $error; //AnswerFileStatusError

	function __construct($checkedTime = null, $host = null, $status = null, $error = null) {
		$this->checkedTime = $checkedTime;
		$this->host = $host;
		$this->status = $status;
		$this->error = $error;
	}
}

class ArrayOfAnswerFileStatusResult extends phpDynamicProperties {
	public $AnswerFileStatusResult; //AnswerFileStatusResult

	function __construct($AnswerFileStatusResult = null) {
		$this->AnswerFileStatusResult = $AnswerFileStatusResult;
	}
}

class ProfileExecuteError extends phpDynamicProperties {
	public $path; //ProfilePropertyPath
	public $message; //LocalizableMessage

	function __construct($path = null, $message = null) {
		$this->path = $path;
		$this->message = $message;
	}
}

class ArrayOfProfileExecuteError extends phpDynamicProperties {
	public $ProfileExecuteError; //ProfileExecuteError

	function __construct($ProfileExecuteError = null) {
		$this->ProfileExecuteError = $ProfileExecuteError;
	}
}

class ProfileExecuteResult extends phpDynamicProperties {
	public $status; //string
	public $configSpec; //HostConfigSpec
	public $inapplicablePath; //string
	public $requireInput; //ProfileDeferredPolicyOptionParameter
	public $error; //ProfileExecuteError

	function __construct($status = null, $configSpec = null, $inapplicablePath = null, $requireInput = null, $error = null) {
		$this->status = $status;
		$this->configSpec = $configSpec;
		$this->inapplicablePath = $inapplicablePath;
		$this->requireInput = $requireInput;
		$this->error = $error;
	}
}

class HostApplyProfile extends phpDynamicProperties {
	public $memory; //HostMemoryProfile
	public $storage; //StorageProfile
	public $network; //NetworkProfile
	public $datetime; //DateTimeProfile
	public $firewall; //FirewallProfile
	public $security; //SecurityProfile
	public $service; //ServiceProfile
	public $option; //OptionProfile
	public $userAccount; //UserProfile
	public $usergroupAccount; //UserGroupProfile
	public $authentication; //AuthenticationProfile

	function __construct($memory = null, $storage = null, $network = null, $datetime = null, $firewall = null, $security = null, $service = null, $option = null, $userAccount = null, $usergroupAccount = null, $authentication = null) {
		$this->memory = $memory;
		$this->storage = $storage;
		$this->network = $network;
		$this->datetime = $datetime;
		$this->firewall = $firewall;
		$this->security = $security;
		$this->service = $service;
		$this->option = $option;
		$this->userAccount = $userAccount;
		$this->usergroupAccount = $usergroupAccount;
		$this->authentication = $authentication;
	}
}

class PhysicalNicProfile extends phpDynamicProperties {
	public $key; //string

	function __construct($key = null) {
		$this->key = $key;
	}
}

class ArrayOfPhysicalNicProfile extends phpDynamicProperties {
	public $PhysicalNicProfile; //PhysicalNicProfile

	function __construct($PhysicalNicProfile = null) {
		$this->PhysicalNicProfile = $PhysicalNicProfile;
	}
}

class HostMemoryProfile extends phpDynamicProperties {
}

class UserProfile extends phpDynamicProperties {
	public $key; //string

	function __construct($key = null) {
		$this->key = $key;
	}
}

class ArrayOfUserProfile extends phpDynamicProperties {
	public $UserProfile; //UserProfile

	function __construct($UserProfile = null) {
		$this->UserProfile = $UserProfile;
	}
}

class UserGroupProfile extends phpDynamicProperties {
	public $key; //string

	function __construct($key = null) {
		$this->key = $key;
	}
}

class ArrayOfUserGroupProfile extends phpDynamicProperties {
	public $UserGroupProfile; //UserGroupProfile

	function __construct($UserGroupProfile = null) {
		$this->UserGroupProfile = $UserGroupProfile;
	}
}

class SecurityProfile extends phpDynamicProperties {
	public $permission; //PermissionProfile

	function __construct($permission = null) {
		$this->permission = $permission;
	}
}

class OptionProfile extends phpDynamicProperties {
	public $key; //string

	function __construct($key = null) {
		$this->key = $key;
	}
}

class ArrayOfOptionProfile extends phpDynamicProperties {
	public $OptionProfile; //OptionProfile

	function __construct($OptionProfile = null) {
		$this->OptionProfile = $OptionProfile;
	}
}

class DateTimeProfile extends phpDynamicProperties {
}

class ServiceProfile extends phpDynamicProperties {
	public $key; //string

	function __construct($key = null) {
		$this->key = $key;
	}
}

class ArrayOfServiceProfile extends phpDynamicProperties {
	public $ServiceProfile; //ServiceProfile

	function __construct($ServiceProfile = null) {
		$this->ServiceProfile = $ServiceProfile;
	}
}

class FirewallProfileRulesetProfile extends phpDynamicProperties {
	public $key; //string

	function __construct($key = null) {
		$this->key = $key;
	}
}

class ArrayOfFirewallProfileRulesetProfile extends phpDynamicProperties {
	public $FirewallProfileRulesetProfile; //FirewallProfileRulesetProfile

	function __construct($FirewallProfileRulesetProfile = null) {
		$this->FirewallProfileRulesetProfile = $FirewallProfileRulesetProfile;
	}
}

class FirewallProfile extends phpDynamicProperties {
	public $ruleset; //FirewallProfileRulesetProfile

	function __construct($ruleset = null) {
		$this->ruleset = $ruleset;
	}
}

class NasStorageProfile extends phpDynamicProperties {
	public $key; //string

	function __construct($key = null) {
		$this->key = $key;
	}
}

class ArrayOfNasStorageProfile extends phpDynamicProperties {
	public $NasStorageProfile; //NasStorageProfile

	function __construct($NasStorageProfile = null) {
		$this->NasStorageProfile = $NasStorageProfile;
	}
}

class StorageProfile extends phpDynamicProperties {
	public $nasStorage; //NasStorageProfile

	function __construct($nasStorage = null) {
		$this->nasStorage = $nasStorage;
	}
}

class NetworkProfileDnsConfigProfile extends phpDynamicProperties {
}

class NetworkProfile extends phpDynamicProperties {
	public $vswitch; //VirtualSwitchProfile
	public $vmPortGroup; //VmPortGroupProfile
	public $hostPortGroup; //HostPortGroupProfile
	public $serviceConsolePortGroup; //ServiceConsolePortGroupProfile
	public $dnsConfig; //NetworkProfileDnsConfigProfile
	public $ipRouteConfig; //IpRouteProfile
	public $consoleIpRouteConfig; //IpRouteProfile
	public $pnic; //PhysicalNicProfile
	public $dvswitch; //DvsProfile
	public $dvsServiceConsoleNic; //DvsServiceConsoleVNicProfile
	public $dvsHostNic; //DvsHostVNicProfile

	function __construct($vswitch = null, $vmPortGroup = null, $hostPortGroup = null, $serviceConsolePortGroup = null, $dnsConfig = null, $ipRouteConfig = null, $consoleIpRouteConfig = null, $pnic = null, $dvswitch = null, $dvsServiceConsoleNic = null, $dvsHostNic = null) {
		$this->vswitch = $vswitch;
		$this->vmPortGroup = $vmPortGroup;
		$this->hostPortGroup = $hostPortGroup;
		$this->serviceConsolePortGroup = $serviceConsolePortGroup;
		$this->dnsConfig = $dnsConfig;
		$this->ipRouteConfig = $ipRouteConfig;
		$this->consoleIpRouteConfig = $consoleIpRouteConfig;
		$this->pnic = $pnic;
		$this->dvswitch = $dvswitch;
		$this->dvsServiceConsoleNic = $dvsServiceConsoleNic;
		$this->dvsHostNic = $dvsHostNic;
	}
}

class DvsVNicProfile extends phpDynamicProperties {
	public $key; //string
	public $ipConfig; //IpAddressProfile

	function __construct($key = null, $ipConfig = null) {
		$this->key = $key;
		$this->ipConfig = $ipConfig;
	}
}

class DvsServiceConsoleVNicProfile extends phpDynamicProperties {
}

class ArrayOfDvsServiceConsoleVNicProfile extends phpDynamicProperties {
	public $DvsServiceConsoleVNicProfile; //DvsServiceConsoleVNicProfile

	function __construct($DvsServiceConsoleVNicProfile = null) {
		$this->DvsServiceConsoleVNicProfile = $DvsServiceConsoleVNicProfile;
	}
}

class DvsHostVNicProfile extends phpDynamicProperties {
}

class ArrayOfDvsHostVNicProfile extends phpDynamicProperties {
	public $DvsHostVNicProfile; //DvsHostVNicProfile

	function __construct($DvsHostVNicProfile = null) {
		$this->DvsHostVNicProfile = $DvsHostVNicProfile;
	}
}

class DvsProfile extends phpDynamicProperties {
	public $key; //string
	public $name; //string
	public $uplink; //PnicUplinkProfile

	function __construct($key = null, $name = null, $uplink = null) {
		$this->key = $key;
		$this->name = $name;
		$this->uplink = $uplink;
	}
}

class ArrayOfDvsProfile extends phpDynamicProperties {
	public $DvsProfile; //DvsProfile

	function __construct($DvsProfile = null) {
		$this->DvsProfile = $DvsProfile;
	}
}

class PnicUplinkProfile extends phpDynamicProperties {
	public $key; //string

	function __construct($key = null) {
		$this->key = $key;
	}
}

class ArrayOfPnicUplinkProfile extends phpDynamicProperties {
	public $PnicUplinkProfile; //PnicUplinkProfile

	function __construct($PnicUplinkProfile = null) {
		$this->PnicUplinkProfile = $PnicUplinkProfile;
	}
}

class IpRouteProfile extends phpDynamicProperties {
	public $staticRoute; //StaticRouteProfile

	function __construct($staticRoute = null) {
		$this->staticRoute = $staticRoute;
	}
}

class StaticRouteProfile extends phpDynamicProperties {
}

class ArrayOfStaticRouteProfile extends phpDynamicProperties {
	public $StaticRouteProfile; //StaticRouteProfile

	function __construct($StaticRouteProfile = null) {
		$this->StaticRouteProfile = $StaticRouteProfile;
	}
}

class LinkProfile extends phpDynamicProperties {
}

class NumPortsProfile extends phpDynamicProperties {
}

class VirtualSwitchProfile extends phpDynamicProperties {
	public $key; //string
	public $name; //string
	public $link; //LinkProfile
	public $numPorts; //NumPortsProfile
	public $networkPolicy; //NetworkPolicyProfile

	function __construct($key = null, $name = null, $link = null, $numPorts = null, $networkPolicy = null) {
		$this->key = $key;
		$this->name = $name;
		$this->link = $link;
		$this->numPorts = $numPorts;
		$this->networkPolicy = $networkPolicy;
	}
}

class ArrayOfVirtualSwitchProfile extends phpDynamicProperties {
	public $VirtualSwitchProfile; //VirtualSwitchProfile

	function __construct($VirtualSwitchProfile = null) {
		$this->VirtualSwitchProfile = $VirtualSwitchProfile;
	}
}

class VlanProfile extends phpDynamicProperties {
}

class VirtualSwitchSelectionProfile extends phpDynamicProperties {
}

class PortGroupProfile extends phpDynamicProperties {
	public $key; //string
	public $name; //string
	public $vlan; //VlanProfile
	public $vswitch; //VirtualSwitchSelectionProfile
	public $networkPolicy; //NetworkPolicyProfile

	function __construct($key = null, $name = null, $vlan = null, $vswitch = null, $networkPolicy = null) {
		$this->key = $key;
		$this->name = $name;
		$this->vlan = $vlan;
		$this->vswitch = $vswitch;
		$this->networkPolicy = $networkPolicy;
	}
}

class VmPortGroupProfile extends phpDynamicProperties {
}

class ArrayOfVmPortGroupProfile extends phpDynamicProperties {
	public $VmPortGroupProfile; //VmPortGroupProfile

	function __construct($VmPortGroupProfile = null) {
		$this->VmPortGroupProfile = $VmPortGroupProfile;
	}
}

class HostPortGroupProfile extends phpDynamicProperties {
	public $ipConfig; //IpAddressProfile

	function __construct($ipConfig = null) {
		$this->ipConfig = $ipConfig;
	}
}

class ArrayOfHostPortGroupProfile extends phpDynamicProperties {
	public $HostPortGroupProfile; //HostPortGroupProfile

	function __construct($HostPortGroupProfile = null) {
		$this->HostPortGroupProfile = $HostPortGroupProfile;
	}
}

class ServiceConsolePortGroupProfile extends phpDynamicProperties {
	public $ipConfig; //IpAddressProfile

	function __construct($ipConfig = null) {
		$this->ipConfig = $ipConfig;
	}
}

class ArrayOfServiceConsolePortGroupProfile extends phpDynamicProperties {
	public $ServiceConsolePortGroupProfile; //ServiceConsolePortGroupProfile

	function __construct($ServiceConsolePortGroupProfile = null) {
		$this->ServiceConsolePortGroupProfile = $ServiceConsolePortGroupProfile;
	}
}

class NetworkPolicyProfile extends phpDynamicProperties {
}

class IpAddressProfile extends phpDynamicProperties {
}

class AuthenticationProfile extends phpDynamicProperties {
	public $activeDirectory; //ActiveDirectoryProfile

	function __construct($activeDirectory = null) {
		$this->activeDirectory = $activeDirectory;
	}
}

class ActiveDirectoryProfile extends phpDynamicProperties {
}

class PermissionProfile extends phpDynamicProperties {
	public $key; //string

	function __construct($key = null) {
		$this->key = $key;
	}
}

class ArrayOfPermissionProfile extends phpDynamicProperties {
	public $PermissionProfile; //PermissionProfile

	function __construct($PermissionProfile = null) {
		$this->PermissionProfile = $PermissionProfile;
	}
}

class HostProfileConfigInfo extends phpDynamicProperties {
	public $applyProfile; //HostApplyProfile
	public $defaultComplyProfile; //ComplianceProfile
	public $defaultComplyLocator; //ComplianceLocator
	public $customComplyProfile; //ComplianceProfile
	public $disabledExpressionList; //string

	function __construct($applyProfile = null, $defaultComplyProfile = null, $defaultComplyLocator = null, $customComplyProfile = null, $disabledExpressionList = null) {
		$this->applyProfile = $applyProfile;
		$this->defaultComplyProfile = $defaultComplyProfile;
		$this->defaultComplyLocator = $defaultComplyLocator;
		$this->customComplyProfile = $customComplyProfile;
		$this->disabledExpressionList = $disabledExpressionList;
	}
}

class HostProfileConfigSpec extends phpDynamicProperties {
}

class HostProfileSerializedHostProfileSpec extends phpDynamicProperties {
	public $validatorHost; //ManagedObjectReference

	function __construct($validatorHost = null) {
		$this->validatorHost = $validatorHost;
	}
}

class HostProfileCompleteConfigSpec extends phpDynamicProperties {
	public $applyProfile; //HostApplyProfile
	public $customComplyProfile; //ComplianceProfile
	public $disabledExpressionListChanged; //boolean
	public $disabledExpressionList; //string
	public $validatorHost; //ManagedObjectReference

	function __construct($applyProfile = null, $customComplyProfile = null, $disabledExpressionListChanged = null, $disabledExpressionList = null, $validatorHost = null) {
		$this->applyProfile = $applyProfile;
		$this->customComplyProfile = $customComplyProfile;
		$this->disabledExpressionListChanged = $disabledExpressionListChanged;
		$this->disabledExpressionList = $disabledExpressionList;
		$this->validatorHost = $validatorHost;
	}
}

class HostProfileHostBasedConfigSpec extends phpDynamicProperties {
	public $host; //ManagedObjectReference
	public $useHostProfileEngine; //boolean

	function __construct($host = null, $useHostProfileEngine = null) {
		$this->host = $host;
		$this->useHostProfileEngine = $useHostProfileEngine;
	}
}

class HostProfileManagerConfigTaskList extends phpDynamicProperties {
	public $configSpec; //HostConfigSpec
	public $taskDescription; //LocalizableMessage

	function __construct($configSpec = null, $taskDescription = null) {
		$this->configSpec = $configSpec;
		$this->taskDescription = $taskDescription;
	}
}

class AnswerFileCreateSpec extends phpDynamicProperties {
}

class AnswerFileOptionsCreateSpec extends phpDynamicProperties {
	public $userInput; //ProfileDeferredPolicyOptionParameter

	function __construct($userInput = null) {
		$this->userInput = $userInput;
	}
}

class AnswerFileSerializedCreateSpec extends phpDynamicProperties {
	public $answerFileConfigString; //string

	function __construct($answerFileConfigString = null) {
		$this->answerFileConfigString = $answerFileConfigString;
	}
}

class ScheduledTaskDetail extends phpDynamicProperties {
	public $frequency; //string

	function __construct($frequency = null) {
		$this->frequency = $frequency;
	}
}

class ArrayOfScheduledTaskDetail extends phpDynamicProperties {
	public $ScheduledTaskDetail; //ScheduledTaskDetail

	function __construct($ScheduledTaskDetail = null) {
		$this->ScheduledTaskDetail = $ScheduledTaskDetail;
	}
}

class ScheduledTaskDescription extends phpDynamicProperties {
	public $action; //TypeDescription
	public $schedulerInfo; //ScheduledTaskDetail
	public $state; //ElementDescription
	public $dayOfWeek; //ElementDescription
	public $weekOfMonth; //ElementDescription

	function __construct($action = null, $schedulerInfo = null, $state = null, $dayOfWeek = null, $weekOfMonth = null) {
		$this->action = $action;
		$this->schedulerInfo = $schedulerInfo;
		$this->state = $state;
		$this->dayOfWeek = $dayOfWeek;
		$this->weekOfMonth = $weekOfMonth;
	}
}

class ScheduledTaskInfo extends phpDynamicProperties {
	public $scheduledTask; //ManagedObjectReference
	public $entity; //ManagedObjectReference
	public $lastModifiedTime; //dateTime
	public $lastModifiedUser; //string
	public $nextRunTime; //dateTime
	public $prevRunTime; //dateTime
	public $state; //TaskInfoState
	public $error; //LocalizedMethodFault
	public $result; //anyType
	public $progress; //int
	public $activeTask; //ManagedObjectReference
	public $taskObject; //ManagedObjectReference

	function __construct($scheduledTask = null, $entity = null, $lastModifiedTime = null, $lastModifiedUser = null, $nextRunTime = null, $prevRunTime = null, $state = null, $error = null, $result = null, $progress = null, $activeTask = null, $taskObject = null) {
		$this->scheduledTask = $scheduledTask;
		$this->entity = $entity;
		$this->lastModifiedTime = $lastModifiedTime;
		$this->lastModifiedUser = $lastModifiedUser;
		$this->nextRunTime = $nextRunTime;
		$this->prevRunTime = $prevRunTime;
		$this->state = $state;
		$this->error = $error;
		$this->result = $result;
		$this->progress = $progress;
		$this->activeTask = $activeTask;
		$this->taskObject = $taskObject;
	}
}

class TaskScheduler extends phpDynamicProperties {
	public $activeTime; //dateTime
	public $expireTime; //dateTime

	function __construct($activeTime = null, $expireTime = null) {
		$this->activeTime = $activeTime;
		$this->expireTime = $expireTime;
	}
}

class AfterStartupTaskScheduler extends phpDynamicProperties {
	public $minute; //int

	function __construct($minute = null) {
		$this->minute = $minute;
	}
}

class OnceTaskScheduler extends phpDynamicProperties {
	public $runAt; //dateTime

	function __construct($runAt = null) {
		$this->runAt = $runAt;
	}
}

class RecurrentTaskScheduler extends phpDynamicProperties {
	public $interval; //int

	function __construct($interval = null) {
		$this->interval = $interval;
	}
}

class HourlyTaskScheduler extends phpDynamicProperties {
	public $minute; //int

	function __construct($minute = null) {
		$this->minute = $minute;
	}
}

class DailyTaskScheduler extends phpDynamicProperties {
	public $hour; //int

	function __construct($hour = null) {
		$this->hour = $hour;
	}
}

class WeeklyTaskScheduler extends phpDynamicProperties {
	public $sunday; //boolean
	public $monday; //boolean
	public $tuesday; //boolean
	public $wednesday; //boolean
	public $thursday; //boolean
	public $friday; //boolean
	public $saturday; //boolean

	function __construct($sunday = null, $monday = null, $tuesday = null, $wednesday = null, $thursday = null, $friday = null, $saturday = null) {
		$this->sunday = $sunday;
		$this->monday = $monday;
		$this->tuesday = $tuesday;
		$this->wednesday = $wednesday;
		$this->thursday = $thursday;
		$this->friday = $friday;
		$this->saturday = $saturday;
	}
}

class MonthlyTaskScheduler extends phpDynamicProperties {
}

class MonthlyByDayTaskScheduler extends phpDynamicProperties {
	public $day; //int

	function __construct($day = null) {
		$this->day = $day;
	}
}

class MonthlyByWeekdayTaskScheduler extends phpDynamicProperties {
	public $offset; //WeekOfMonth
	public $weekday; //DayOfWeek

	function __construct($offset = null, $weekday = null) {
		$this->offset = $offset;
		$this->weekday = $weekday;
	}
}

class ScheduledTaskSpec extends phpDynamicProperties {
	public $name; //string
	public $description; //string
	public $enabled; //boolean
	public $scheduler; //TaskScheduler
	public $action; //Action
	public $notification; //string

	function __construct($name = null, $description = null, $enabled = null, $scheduler = null, $action = null, $notification = null) {
		$this->name = $name;
		$this->description = $description;
		$this->enabled = $enabled;
		$this->scheduler = $scheduler;
		$this->action = $action;
		$this->notification = $notification;
	}
}

class ApplyStorageRecommendationResult extends phpDynamicProperties {
	public $vm; //ManagedObjectReference

	function __construct($vm = null) {
		$this->vm = $vm;
	}
}

class StorageDrsConfigInfo extends phpDynamicProperties {
	public $podConfig; //StorageDrsPodConfigInfo
	public $vmConfig; //StorageDrsVmConfigInfo

	function __construct($podConfig = null, $vmConfig = null) {
		$this->podConfig = $podConfig;
		$this->vmConfig = $vmConfig;
	}
}

class StorageDrsConfigSpec extends phpDynamicProperties {
	public $podConfigSpec; //StorageDrsPodConfigSpec
	public $vmConfigSpec; //StorageDrsVmConfigSpec

	function __construct($podConfigSpec = null, $vmConfigSpec = null) {
		$this->podConfigSpec = $podConfigSpec;
		$this->vmConfigSpec = $vmConfigSpec;
	}
}

class StorageDrsVmConfigSpec extends phpDynamicProperties {
	public $info; //StorageDrsVmConfigInfo

	function __construct($info = null) {
		$this->info = $info;
	}
}

class ArrayOfStorageDrsVmConfigSpec extends phpDynamicProperties {
	public $StorageDrsVmConfigSpec; //StorageDrsVmConfigSpec

	function __construct($StorageDrsVmConfigSpec = null) {
		$this->StorageDrsVmConfigSpec = $StorageDrsVmConfigSpec;
	}
}

class StorageDrsPodConfigInfo extends phpDynamicProperties {
	public $enabled; //boolean
	public $ioLoadBalanceEnabled; //boolean
	public $defaultVmBehavior; //string
	public $loadBalanceInterval; //int
	public $defaultIntraVmAffinity; //boolean
	public $spaceLoadBalanceConfig; //StorageDrsSpaceLoadBalanceConfig
	public $ioLoadBalanceConfig; //StorageDrsIoLoadBalanceConfig
	public $rule; //ClusterRuleInfo
	public $option; //OptionValue

	function __construct($enabled = null, $ioLoadBalanceEnabled = null, $defaultVmBehavior = null, $loadBalanceInterval = null, $defaultIntraVmAffinity = null, $spaceLoadBalanceConfig = null, $ioLoadBalanceConfig = null, $rule = null, $option = null) {
		$this->enabled = $enabled;
		$this->ioLoadBalanceEnabled = $ioLoadBalanceEnabled;
		$this->defaultVmBehavior = $defaultVmBehavior;
		$this->loadBalanceInterval = $loadBalanceInterval;
		$this->defaultIntraVmAffinity = $defaultIntraVmAffinity;
		$this->spaceLoadBalanceConfig = $spaceLoadBalanceConfig;
		$this->ioLoadBalanceConfig = $ioLoadBalanceConfig;
		$this->rule = $rule;
		$this->option = $option;
	}
}

class StorageDrsSpaceLoadBalanceConfig extends phpDynamicProperties {
	public $spaceUtilizationThreshold; //int
	public $minSpaceUtilizationDifference; //int

	function __construct($spaceUtilizationThreshold = null, $minSpaceUtilizationDifference = null) {
		$this->spaceUtilizationThreshold = $spaceUtilizationThreshold;
		$this->minSpaceUtilizationDifference = $minSpaceUtilizationDifference;
	}
}

class StorageDrsIoLoadBalanceConfig extends phpDynamicProperties {
	public $ioLatencyThreshold; //int
	public $ioLoadImbalanceThreshold; //int

	function __construct($ioLatencyThreshold = null, $ioLoadImbalanceThreshold = null) {
		$this->ioLatencyThreshold = $ioLatencyThreshold;
		$this->ioLoadImbalanceThreshold = $ioLoadImbalanceThreshold;
	}
}

class StorageDrsPodConfigSpec extends phpDynamicProperties {
	public $enabled; //boolean
	public $ioLoadBalanceEnabled; //boolean
	public $defaultVmBehavior; //string
	public $loadBalanceInterval; //int
	public $defaultIntraVmAffinity; //boolean
	public $spaceLoadBalanceConfig; //StorageDrsSpaceLoadBalanceConfig
	public $ioLoadBalanceConfig; //StorageDrsIoLoadBalanceConfig
	public $rule; //ClusterRuleSpec
	public $option; //StorageDrsOptionSpec

	function __construct($enabled = null, $ioLoadBalanceEnabled = null, $defaultVmBehavior = null, $loadBalanceInterval = null, $defaultIntraVmAffinity = null, $spaceLoadBalanceConfig = null, $ioLoadBalanceConfig = null, $rule = null, $option = null) {
		$this->enabled = $enabled;
		$this->ioLoadBalanceEnabled = $ioLoadBalanceEnabled;
		$this->defaultVmBehavior = $defaultVmBehavior;
		$this->loadBalanceInterval = $loadBalanceInterval;
		$this->defaultIntraVmAffinity = $defaultIntraVmAffinity;
		$this->spaceLoadBalanceConfig = $spaceLoadBalanceConfig;
		$this->ioLoadBalanceConfig = $ioLoadBalanceConfig;
		$this->rule = $rule;
		$this->option = $option;
	}
}

class StorageDrsOptionSpec extends phpDynamicProperties {
	public $option; //OptionValue

	function __construct($option = null) {
		$this->option = $option;
	}
}

class ArrayOfStorageDrsOptionSpec extends phpDynamicProperties {
	public $StorageDrsOptionSpec; //StorageDrsOptionSpec

	function __construct($StorageDrsOptionSpec = null) {
		$this->StorageDrsOptionSpec = $StorageDrsOptionSpec;
	}
}

class VmPodConfigForPlacement extends phpDynamicProperties {
	public $storagePod; //ManagedObjectReference
	public $disk; //PodDiskLocator
	public $vmConfig; //StorageDrsVmConfigInfo
	public $interVmRule; //ClusterRuleInfo

	function __construct($storagePod = null, $disk = null, $vmConfig = null, $interVmRule = null) {
		$this->storagePod = $storagePod;
		$this->disk = $disk;
		$this->vmConfig = $vmConfig;
		$this->interVmRule = $interVmRule;
	}
}

class ArrayOfVmPodConfigForPlacement extends phpDynamicProperties {
	public $VmPodConfigForPlacement; //VmPodConfigForPlacement

	function __construct($VmPodConfigForPlacement = null) {
		$this->VmPodConfigForPlacement = $VmPodConfigForPlacement;
	}
}

class PodDiskLocator extends phpDynamicProperties {
	public $diskId; //int
	public $diskMoveType; //string
	public $diskBackingInfo; //VirtualDeviceBackingInfo

	function __construct($diskId = null, $diskMoveType = null, $diskBackingInfo = null) {
		$this->diskId = $diskId;
		$this->diskMoveType = $diskMoveType;
		$this->diskBackingInfo = $diskBackingInfo;
	}
}

class ArrayOfPodDiskLocator extends phpDynamicProperties {
	public $PodDiskLocator; //PodDiskLocator

	function __construct($PodDiskLocator = null) {
		$this->PodDiskLocator = $PodDiskLocator;
	}
}

class StorageDrsPodSelectionSpec extends phpDynamicProperties {
	public $initialVmConfig; //VmPodConfigForPlacement
	public $storagePod; //ManagedObjectReference

	function __construct($initialVmConfig = null, $storagePod = null) {
		$this->initialVmConfig = $initialVmConfig;
		$this->storagePod = $storagePod;
	}
}

class StorageMigrationAction extends phpDynamicProperties {
	public $vm; //ManagedObjectReference
	public $relocateSpec; //VirtualMachineRelocateSpec
	public $source; //ManagedObjectReference
	public $destination; //ManagedObjectReference
	public $sizeTransferred; //long
	public $spaceUtilSrcBefore; //float
	public $spaceUtilDstBefore; //float
	public $spaceUtilSrcAfter; //float
	public $spaceUtilDstAfter; //float
	public $ioLatencySrcBefore; //float
	public $ioLatencyDstBefore; //float

	function __construct($vm = null, $relocateSpec = null, $source = null, $destination = null, $sizeTransferred = null, $spaceUtilSrcBefore = null, $spaceUtilDstBefore = null, $spaceUtilSrcAfter = null, $spaceUtilDstAfter = null, $ioLatencySrcBefore = null, $ioLatencyDstBefore = null) {
		$this->vm = $vm;
		$this->relocateSpec = $relocateSpec;
		$this->source = $source;
		$this->destination = $destination;
		$this->sizeTransferred = $sizeTransferred;
		$this->spaceUtilSrcBefore = $spaceUtilSrcBefore;
		$this->spaceUtilDstBefore = $spaceUtilDstBefore;
		$this->spaceUtilSrcAfter = $spaceUtilSrcAfter;
		$this->spaceUtilDstAfter = $spaceUtilDstAfter;
		$this->ioLatencySrcBefore = $ioLatencySrcBefore;
		$this->ioLatencyDstBefore = $ioLatencyDstBefore;
	}
}

class StoragePlacementAction extends phpDynamicProperties {
	public $vm; //ManagedObjectReference
	public $relocateSpec; //VirtualMachineRelocateSpec
	public $destination; //ManagedObjectReference
	public $spaceUtilBefore; //float
	public $spaceUtilAfter; //float
	public $ioLatencyBefore; //float

	function __construct($vm = null, $relocateSpec = null, $destination = null, $spaceUtilBefore = null, $spaceUtilAfter = null, $ioLatencyBefore = null) {
		$this->vm = $vm;
		$this->relocateSpec = $relocateSpec;
		$this->destination = $destination;
		$this->spaceUtilBefore = $spaceUtilBefore;
		$this->spaceUtilAfter = $spaceUtilAfter;
		$this->ioLatencyBefore = $ioLatencyBefore;
	}
}

class StoragePlacementResult extends phpDynamicProperties {
	public $recommendations; //ClusterRecommendation
	public $drsFault; //ClusterDrsFaults
	public $task; //ManagedObjectReference

	function __construct($recommendations = null, $drsFault = null, $task = null) {
		$this->recommendations = $recommendations;
		$this->drsFault = $drsFault;
		$this->task = $task;
	}
}

class StoragePlacementSpec extends phpDynamicProperties {
	public $type; //string
	public $priority; //VirtualMachineMovePriority
	public $vm; //ManagedObjectReference
	public $podSelectionSpec; //StorageDrsPodSelectionSpec
	public $cloneSpec; //VirtualMachineCloneSpec
	public $cloneName; //string
	public $configSpec; //VirtualMachineConfigSpec
	public $relocateSpec; //VirtualMachineRelocateSpec
	public $resourcePool; //ManagedObjectReference
	public $host; //ManagedObjectReference
	public $folder; //ManagedObjectReference

	function __construct($type = null, $priority = null, $vm = null, $podSelectionSpec = null, $cloneSpec = null, $cloneName = null, $configSpec = null, $relocateSpec = null, $resourcePool = null, $host = null, $folder = null) {
		$this->type = $type;
		$this->priority = $priority;
		$this->vm = $vm;
		$this->podSelectionSpec = $podSelectionSpec;
		$this->cloneSpec = $cloneSpec;
		$this->cloneName = $cloneName;
		$this->configSpec = $configSpec;
		$this->relocateSpec = $relocateSpec;
		$this->resourcePool = $resourcePool;
		$this->host = $host;
		$this->folder = $folder;
	}
}

class VirtualDiskAntiAffinityRuleSpec extends phpDynamicProperties {
	public $diskId; //int

	function __construct($diskId = null) {
		$this->diskId = $diskId;
	}
}

class StorageDrsVmConfigInfo extends phpDynamicProperties {
	public $vm; //ManagedObjectReference
	public $enabled; //boolean
	public $behavior; //string
	public $intraVmAffinity; //boolean
	public $intraVmAntiAffinity; //VirtualDiskAntiAffinityRuleSpec

	function __construct($vm = null, $enabled = null, $behavior = null, $intraVmAffinity = null, $intraVmAntiAffinity = null) {
		$this->vm = $vm;
		$this->enabled = $enabled;
		$this->behavior = $behavior;
		$this->intraVmAffinity = $intraVmAffinity;
		$this->intraVmAntiAffinity = $intraVmAntiAffinity;
	}
}

class ArrayOfStorageDrsVmConfigInfo extends phpDynamicProperties {
	public $StorageDrsVmConfigInfo; //StorageDrsVmConfigInfo

	function __construct($StorageDrsVmConfigInfo = null) {
		$this->StorageDrsVmConfigInfo = $StorageDrsVmConfigInfo;
	}
}

class VAppCloneSpecNetworkMappingPair extends phpDynamicProperties {
	public $source; //ManagedObjectReference
	public $destination; //ManagedObjectReference

	function __construct($source = null, $destination = null) {
		$this->source = $source;
		$this->destination = $destination;
	}
}

class ArrayOfVAppCloneSpecNetworkMappingPair extends phpDynamicProperties {
	public $VAppCloneSpecNetworkMappingPair; //VAppCloneSpecNetworkMappingPair

	function __construct($VAppCloneSpecNetworkMappingPair = null) {
		$this->VAppCloneSpecNetworkMappingPair = $VAppCloneSpecNetworkMappingPair;
	}
}

class VAppCloneSpecResourceMap extends phpDynamicProperties {
	public $source; //ManagedObjectReference
	public $parent; //ManagedObjectReference
	public $resourceSpec; //ResourceConfigSpec
	public $location; //ManagedObjectReference

	function __construct($source = null, $parent = null, $resourceSpec = null, $location = null) {
		$this->source = $source;
		$this->parent = $parent;
		$this->resourceSpec = $resourceSpec;
		$this->location = $location;
	}
}

class ArrayOfVAppCloneSpecResourceMap extends phpDynamicProperties {
	public $VAppCloneSpecResourceMap; //VAppCloneSpecResourceMap

	function __construct($VAppCloneSpecResourceMap = null) {
		$this->VAppCloneSpecResourceMap = $VAppCloneSpecResourceMap;
	}
}

class VAppCloneSpec extends phpDynamicProperties {
	public $location; //ManagedObjectReference
	public $host; //ManagedObjectReference
	public $resourceSpec; //ResourceConfigSpec
	public $vmFolder; //ManagedObjectReference
	public $networkMapping; //VAppCloneSpecNetworkMappingPair
	public $property; //KeyValue
	public $resourceMapping; //VAppCloneSpecResourceMap
	public $provisioning; //string

	function __construct($location = null, $host = null, $resourceSpec = null, $vmFolder = null, $networkMapping = null, $property = null, $resourceMapping = null, $provisioning = null) {
		$this->location = $location;
		$this->host = $host;
		$this->resourceSpec = $resourceSpec;
		$this->vmFolder = $vmFolder;
		$this->networkMapping = $networkMapping;
		$this->property = $property;
		$this->resourceMapping = $resourceMapping;
		$this->provisioning = $provisioning;
	}
}

class VAppEntityConfigInfo extends phpDynamicProperties {
	public $key; //ManagedObjectReference
	public $tag; //string
	public $startOrder; //int
	public $startDelay; //int
	public $waitingForGuest; //boolean
	public $startAction; //string
	public $stopDelay; //int
	public $stopAction; //string
	public $destroyWithParent; //boolean

	function __construct($key = null, $tag = null, $startOrder = null, $startDelay = null, $waitingForGuest = null, $startAction = null, $stopDelay = null, $stopAction = null, $destroyWithParent = null) {
		$this->key = $key;
		$this->tag = $tag;
		$this->startOrder = $startOrder;
		$this->startDelay = $startDelay;
		$this->waitingForGuest = $waitingForGuest;
		$this->startAction = $startAction;
		$this->stopDelay = $stopDelay;
		$this->stopAction = $stopAction;
		$this->destroyWithParent = $destroyWithParent;
	}
}

class ArrayOfVAppEntityConfigInfo extends phpDynamicProperties {
	public $VAppEntityConfigInfo; //VAppEntityConfigInfo

	function __construct($VAppEntityConfigInfo = null) {
		$this->VAppEntityConfigInfo = $VAppEntityConfigInfo;
	}
}

class VAppIPAssignmentInfo extends phpDynamicProperties {
	public $supportedAllocationScheme; //string
	public $ipAllocationPolicy; //string
	public $supportedIpProtocol; //string
	public $ipProtocol; //string

	function __construct($supportedAllocationScheme = null, $ipAllocationPolicy = null, $supportedIpProtocol = null, $ipProtocol = null) {
		$this->supportedAllocationScheme = $supportedAllocationScheme;
		$this->ipAllocationPolicy = $ipAllocationPolicy;
		$this->supportedIpProtocol = $supportedIpProtocol;
		$this->ipProtocol = $ipProtocol;
	}
}

class IpPoolIpPoolConfigInfo extends phpDynamicProperties {
	public $subnetAddress; //string
	public $netmask; //string
	public $gateway; //string
	public $range; //string
	public $dns; //string
	public $dhcpServerAvailable; //boolean
	public $ipPoolEnabled; //boolean

	function __construct($subnetAddress = null, $netmask = null, $gateway = null, $range = null, $dns = null, $dhcpServerAvailable = null, $ipPoolEnabled = null) {
		$this->subnetAddress = $subnetAddress;
		$this->netmask = $netmask;
		$this->gateway = $gateway;
		$this->range = $range;
		$this->dns = $dns;
		$this->dhcpServerAvailable = $dhcpServerAvailable;
		$this->ipPoolEnabled = $ipPoolEnabled;
	}
}

class IpPoolAssociation extends phpDynamicProperties {
	public $network; //ManagedObjectReference
	public $networkName; //string

	function __construct($network = null, $networkName = null) {
		$this->network = $network;
		$this->networkName = $networkName;
	}
}

class ArrayOfIpPoolAssociation extends phpDynamicProperties {
	public $IpPoolAssociation; //IpPoolAssociation

	function __construct($IpPoolAssociation = null) {
		$this->IpPoolAssociation = $IpPoolAssociation;
	}
}

class IpPool extends phpDynamicProperties {
	public $id; //int
	public $name; //string
	public $ipv4Config; //IpPoolIpPoolConfigInfo
	public $ipv6Config; //IpPoolIpPoolConfigInfo
	public $dnsDomain; //string
	public $dnsSearchPath; //string
	public $hostPrefix; //string
	public $httpProxy; //string
	public $networkAssociation; //IpPoolAssociation

	function __construct($id = null, $name = null, $ipv4Config = null, $ipv6Config = null, $dnsDomain = null, $dnsSearchPath = null, $hostPrefix = null, $httpProxy = null, $networkAssociation = null) {
		$this->id = $id;
		$this->name = $name;
		$this->ipv4Config = $ipv4Config;
		$this->ipv6Config = $ipv6Config;
		$this->dnsDomain = $dnsDomain;
		$this->dnsSearchPath = $dnsSearchPath;
		$this->hostPrefix = $hostPrefix;
		$this->httpProxy = $httpProxy;
		$this->networkAssociation = $networkAssociation;
	}
}

class ArrayOfIpPool extends phpDynamicProperties {
	public $IpPool; //IpPool

	function __construct($IpPool = null) {
		$this->IpPool = $IpPool;
	}
}

class VAppOvfSectionInfo extends phpDynamicProperties {
	public $key; //int
	public $namespace; //string
	public $type; //string
	public $atEnvelopeLevel; //boolean
	public $contents; //string

	function __construct($key = null, $namespace = null, $type = null, $atEnvelopeLevel = null, $contents = null) {
		$this->key = $key;
		$this->namespace = $namespace;
		$this->type = $type;
		$this->atEnvelopeLevel = $atEnvelopeLevel;
		$this->contents = $contents;
	}
}

class ArrayOfVAppOvfSectionInfo extends phpDynamicProperties {
	public $VAppOvfSectionInfo; //VAppOvfSectionInfo

	function __construct($VAppOvfSectionInfo = null) {
		$this->VAppOvfSectionInfo = $VAppOvfSectionInfo;
	}
}

class VAppProductInfo extends phpDynamicProperties {
	public $key; //int
	public $classId; //string
	public $instanceId; //string
	public $name; //string
	public $vendor; //string
	public $version; //string
	public $fullVersion; //string
	public $vendorUrl; //string
	public $productUrl; //string
	public $appUrl; //string

	function __construct($key = null, $classId = null, $instanceId = null, $name = null, $vendor = null, $version = null, $fullVersion = null, $vendorUrl = null, $productUrl = null, $appUrl = null) {
		$this->key = $key;
		$this->classId = $classId;
		$this->instanceId = $instanceId;
		$this->name = $name;
		$this->vendor = $vendor;
		$this->version = $version;
		$this->fullVersion = $fullVersion;
		$this->vendorUrl = $vendorUrl;
		$this->productUrl = $productUrl;
		$this->appUrl = $appUrl;
	}
}

class ArrayOfVAppProductInfo extends phpDynamicProperties {
	public $VAppProductInfo; //VAppProductInfo

	function __construct($VAppProductInfo = null) {
		$this->VAppProductInfo = $VAppProductInfo;
	}
}

class VAppPropertyInfo extends phpDynamicProperties {
	public $key; //int
	public $classId; //string
	public $instanceId; //string
	public $id; //string
	public $category; //string
	public $label; //string
	public $type; //string
	public $userConfigurable; //boolean
	public $defaultValue; //string
	public $value; //string
	public $description; //string

	function __construct($key = null, $classId = null, $instanceId = null, $id = null, $category = null, $label = null, $type = null, $userConfigurable = null, $defaultValue = null, $value = null, $description = null) {
		$this->key = $key;
		$this->classId = $classId;
		$this->instanceId = $instanceId;
		$this->id = $id;
		$this->category = $category;
		$this->label = $label;
		$this->type = $type;
		$this->userConfigurable = $userConfigurable;
		$this->defaultValue = $defaultValue;
		$this->value = $value;
		$this->description = $description;
	}
}

class ArrayOfVAppPropertyInfo extends phpDynamicProperties {
	public $VAppPropertyInfo; //VAppPropertyInfo

	function __construct($VAppPropertyInfo = null) {
		$this->VAppPropertyInfo = $VAppPropertyInfo;
	}
}

class VAppConfigInfo extends phpDynamicProperties {
	public $entityConfig; //VAppEntityConfigInfo
	public $annotation; //string
	public $instanceUuid; //string
	public $managedBy; //ManagedByInfo

	function __construct($entityConfig = null, $annotation = null, $instanceUuid = null, $managedBy = null) {
		$this->entityConfig = $entityConfig;
		$this->annotation = $annotation;
		$this->instanceUuid = $instanceUuid;
		$this->managedBy = $managedBy;
	}
}

class VAppConfigSpec extends phpDynamicProperties {
	public $entityConfig; //VAppEntityConfigInfo
	public $annotation; //string
	public $instanceUuid; //string
	public $managedBy; //ManagedByInfo

	function __construct($entityConfig = null, $annotation = null, $instanceUuid = null, $managedBy = null) {
		$this->entityConfig = $entityConfig;
		$this->annotation = $annotation;
		$this->instanceUuid = $instanceUuid;
		$this->managedBy = $managedBy;
	}
}

class VirtualAppImportSpec extends phpDynamicProperties {
	public $name; //string
	public $vAppConfigSpec; //VAppConfigSpec
	public $resourcePoolSpec; //ResourceConfigSpec
	public $child; //ImportSpec

	function __construct($name = null, $vAppConfigSpec = null, $resourcePoolSpec = null, $child = null) {
		$this->name = $name;
		$this->vAppConfigSpec = $vAppConfigSpec;
		$this->resourcePoolSpec = $resourcePoolSpec;
		$this->child = $child;
	}
}

class VmConfigInfo extends phpDynamicProperties {
	public $product; //VAppProductInfo
	public $property; //VAppPropertyInfo
	public $ipAssignment; //VAppIPAssignmentInfo
	public $eula; //string
	public $ovfSection; //VAppOvfSectionInfo
	public $ovfEnvironmentTransport; //string
	public $installBootRequired; //boolean
	public $installBootStopDelay; //int

	function __construct($product = null, $property = null, $ipAssignment = null, $eula = null, $ovfSection = null, $ovfEnvironmentTransport = null, $installBootRequired = null, $installBootStopDelay = null) {
		$this->product = $product;
		$this->property = $property;
		$this->ipAssignment = $ipAssignment;
		$this->eula = $eula;
		$this->ovfSection = $ovfSection;
		$this->ovfEnvironmentTransport = $ovfEnvironmentTransport;
		$this->installBootRequired = $installBootRequired;
		$this->installBootStopDelay = $installBootStopDelay;
	}
}

class VmConfigSpec extends phpDynamicProperties {
	public $product; //VAppProductSpec
	public $property; //VAppPropertySpec
	public $ipAssignment; //VAppIPAssignmentInfo
	public $eula; //string
	public $ovfSection; //VAppOvfSectionSpec
	public $ovfEnvironmentTransport; //string
	public $installBootRequired; //boolean
	public $installBootStopDelay; //int

	function __construct($product = null, $property = null, $ipAssignment = null, $eula = null, $ovfSection = null, $ovfEnvironmentTransport = null, $installBootRequired = null, $installBootStopDelay = null) {
		$this->product = $product;
		$this->property = $property;
		$this->ipAssignment = $ipAssignment;
		$this->eula = $eula;
		$this->ovfSection = $ovfSection;
		$this->ovfEnvironmentTransport = $ovfEnvironmentTransport;
		$this->installBootRequired = $installBootRequired;
		$this->installBootStopDelay = $installBootStopDelay;
	}
}

class VAppProductSpec extends phpDynamicProperties {
	public $info; //VAppProductInfo

	function __construct($info = null) {
		$this->info = $info;
	}
}

class ArrayOfVAppProductSpec extends phpDynamicProperties {
	public $VAppProductSpec; //VAppProductSpec

	function __construct($VAppProductSpec = null) {
		$this->VAppProductSpec = $VAppProductSpec;
	}
}

class VAppPropertySpec extends phpDynamicProperties {
	public $info; //VAppPropertyInfo

	function __construct($info = null) {
		$this->info = $info;
	}
}

class ArrayOfVAppPropertySpec extends phpDynamicProperties {
	public $VAppPropertySpec; //VAppPropertySpec

	function __construct($VAppPropertySpec = null) {
		$this->VAppPropertySpec = $VAppPropertySpec;
	}
}

class VAppOvfSectionSpec extends phpDynamicProperties {
	public $info; //VAppOvfSectionInfo

	function __construct($info = null) {
		$this->info = $info;
	}
}

class ArrayOfVAppOvfSectionSpec extends phpDynamicProperties {
	public $VAppOvfSectionSpec; //VAppOvfSectionSpec

	function __construct($VAppOvfSectionSpec = null) {
		$this->VAppOvfSectionSpec = $VAppOvfSectionSpec;
	}
}

class VirtualMachineAffinityInfo extends phpDynamicProperties {
	public $affinitySet; //int

	function __construct($affinitySet = null) {
		$this->affinitySet = $affinitySet;
	}
}

class VirtualMachineBootOptionsBootableDevice extends phpDynamicProperties {
}

class ArrayOfVirtualMachineBootOptionsBootableDevice extends phpDynamicProperties {
	public $VirtualMachineBootOptionsBootableDevice; //VirtualMachineBootOptionsBootableDevice

	function __construct($VirtualMachineBootOptionsBootableDevice = null) {
		$this->VirtualMachineBootOptionsBootableDevice = $VirtualMachineBootOptionsBootableDevice;
	}
}

class VirtualMachineBootOptionsBootableDiskDevice extends phpDynamicProperties {
	public $deviceKey; //int

	function __construct($deviceKey = null) {
		$this->deviceKey = $deviceKey;
	}
}

class VirtualMachineBootOptionsBootableEthernetDevice extends phpDynamicProperties {
	public $deviceKey; //int

	function __construct($deviceKey = null) {
		$this->deviceKey = $deviceKey;
	}
}

class VirtualMachineBootOptionsBootableFloppyDevice extends phpDynamicProperties {
}

class VirtualMachineBootOptionsBootableCdromDevice extends phpDynamicProperties {
}

class VirtualMachineBootOptions extends phpDynamicProperties {
	public $bootDelay; //long
	public $enterBIOSSetup; //boolean
	public $bootRetryEnabled; //boolean
	public $bootRetryDelay; //long
	public $bootOrder; //VirtualMachineBootOptionsBootableDevice

	function __construct($bootDelay = null, $enterBIOSSetup = null, $bootRetryEnabled = null, $bootRetryDelay = null, $bootOrder = null) {
		$this->bootDelay = $bootDelay;
		$this->enterBIOSSetup = $enterBIOSSetup;
		$this->bootRetryEnabled = $bootRetryEnabled;
		$this->bootRetryDelay = $bootRetryDelay;
		$this->bootOrder = $bootOrder;
	}
}

class VirtualMachineCapability extends phpDynamicProperties {
	public $snapshotOperationsSupported; //boolean
	public $multipleSnapshotsSupported; //boolean
	public $snapshotConfigSupported; //boolean
	public $poweredOffSnapshotsSupported; //boolean
	public $memorySnapshotsSupported; //boolean
	public $revertToSnapshotSupported; //boolean
	public $quiescedSnapshotsSupported; //boolean
	public $disableSnapshotsSupported; //boolean
	public $lockSnapshotsSupported; //boolean
	public $consolePreferencesSupported; //boolean
	public $cpuFeatureMaskSupported; //boolean
	public $s1AcpiManagementSupported; //boolean
	public $settingScreenResolutionSupported; //boolean
	public $toolsAutoUpdateSupported; //boolean
	public $vmNpivWwnSupported; //boolean
	public $npivWwnOnNonRdmVmSupported; //boolean
	public $vmNpivWwnDisableSupported; //boolean
	public $vmNpivWwnUpdateSupported; //boolean
	public $swapPlacementSupported; //boolean
	public $toolsSyncTimeSupported; //boolean
	public $virtualMmuUsageSupported; //boolean
	public $diskSharesSupported; //boolean
	public $bootOptionsSupported; //boolean
	public $bootRetryOptionsSupported; //boolean
	public $settingVideoRamSizeSupported; //boolean
	public $settingDisplayTopologySupported; //boolean
	public $recordReplaySupported; //boolean
	public $changeTrackingSupported; //boolean
	public $multipleCoresPerSocketSupported; //boolean
	public $hostBasedReplicationSupported; //boolean
	public $guestAutoLockSupported; //boolean
	public $memoryReservationLockSupported; //boolean

	function __construct($snapshotOperationsSupported = null, $multipleSnapshotsSupported = null, $snapshotConfigSupported = null, $poweredOffSnapshotsSupported = null, $memorySnapshotsSupported = null, $revertToSnapshotSupported = null, $quiescedSnapshotsSupported = null, $disableSnapshotsSupported = null, $lockSnapshotsSupported = null, $consolePreferencesSupported = null, $cpuFeatureMaskSupported = null, $s1AcpiManagementSupported = null, $settingScreenResolutionSupported = null, $toolsAutoUpdateSupported = null, $vmNpivWwnSupported = null, $npivWwnOnNonRdmVmSupported = null, $vmNpivWwnDisableSupported = null, $vmNpivWwnUpdateSupported = null, $swapPlacementSupported = null, $toolsSyncTimeSupported = null, $virtualMmuUsageSupported = null, $diskSharesSupported = null, $bootOptionsSupported = null, $bootRetryOptionsSupported = null, $settingVideoRamSizeSupported = null, $settingDisplayTopologySupported = null, $recordReplaySupported = null, $changeTrackingSupported = null, $multipleCoresPerSocketSupported = null, $hostBasedReplicationSupported = null, $guestAutoLockSupported = null, $memoryReservationLockSupported = null) {
		$this->snapshotOperationsSupported = $snapshotOperationsSupported;
		$this->multipleSnapshotsSupported = $multipleSnapshotsSupported;
		$this->snapshotConfigSupported = $snapshotConfigSupported;
		$this->poweredOffSnapshotsSupported = $poweredOffSnapshotsSupported;
		$this->memorySnapshotsSupported = $memorySnapshotsSupported;
		$this->revertToSnapshotSupported = $revertToSnapshotSupported;
		$this->quiescedSnapshotsSupported = $quiescedSnapshotsSupported;
		$this->disableSnapshotsSupported = $disableSnapshotsSupported;
		$this->lockSnapshotsSupported = $lockSnapshotsSupported;
		$this->consolePreferencesSupported = $consolePreferencesSupported;
		$this->cpuFeatureMaskSupported = $cpuFeatureMaskSupported;
		$this->s1AcpiManagementSupported = $s1AcpiManagementSupported;
		$this->settingScreenResolutionSupported = $settingScreenResolutionSupported;
		$this->toolsAutoUpdateSupported = $toolsAutoUpdateSupported;
		$this->vmNpivWwnSupported = $vmNpivWwnSupported;
		$this->npivWwnOnNonRdmVmSupported = $npivWwnOnNonRdmVmSupported;
		$this->vmNpivWwnDisableSupported = $vmNpivWwnDisableSupported;
		$this->vmNpivWwnUpdateSupported = $vmNpivWwnUpdateSupported;
		$this->swapPlacementSupported = $swapPlacementSupported;
		$this->toolsSyncTimeSupported = $toolsSyncTimeSupported;
		$this->virtualMmuUsageSupported = $virtualMmuUsageSupported;
		$this->diskSharesSupported = $diskSharesSupported;
		$this->bootOptionsSupported = $bootOptionsSupported;
		$this->bootRetryOptionsSupported = $bootRetryOptionsSupported;
		$this->settingVideoRamSizeSupported = $settingVideoRamSizeSupported;
		$this->settingDisplayTopologySupported = $settingDisplayTopologySupported;
		$this->recordReplaySupported = $recordReplaySupported;
		$this->changeTrackingSupported = $changeTrackingSupported;
		$this->multipleCoresPerSocketSupported = $multipleCoresPerSocketSupported;
		$this->hostBasedReplicationSupported = $hostBasedReplicationSupported;
		$this->guestAutoLockSupported = $guestAutoLockSupported;
		$this->memoryReservationLockSupported = $memoryReservationLockSupported;
	}
}

class VirtualMachineCdromInfo extends phpDynamicProperties {
}

class ArrayOfVirtualMachineCdromInfo extends phpDynamicProperties {
	public $VirtualMachineCdromInfo; //VirtualMachineCdromInfo

	function __construct($VirtualMachineCdromInfo = null) {
		$this->VirtualMachineCdromInfo = $VirtualMachineCdromInfo;
	}
}

class VirtualMachineCloneSpec extends phpDynamicProperties {
	public $location; //VirtualMachineRelocateSpec
	public $template; //boolean
	public $config; //VirtualMachineConfigSpec
	public $customization; //CustomizationSpec
	public $powerOn; //boolean
	public $snapshot; //ManagedObjectReference

	function __construct($location = null, $template = null, $config = null, $customization = null, $powerOn = null, $snapshot = null) {
		$this->location = $location;
		$this->template = $template;
		$this->config = $config;
		$this->customization = $customization;
		$this->powerOn = $powerOn;
		$this->snapshot = $snapshot;
	}
}

class VirtualMachineConfigInfoDatastoreUrlPair extends phpDynamicProperties {
	public $name; //string
	public $url; //string

	function __construct($name = null, $url = null) {
		$this->name = $name;
		$this->url = $url;
	}
}

class ArrayOfVirtualMachineConfigInfoDatastoreUrlPair extends phpDynamicProperties {
	public $VirtualMachineConfigInfoDatastoreUrlPair; //VirtualMachineConfigInfoDatastoreUrlPair

	function __construct($VirtualMachineConfigInfoDatastoreUrlPair = null) {
		$this->VirtualMachineConfigInfoDatastoreUrlPair = $VirtualMachineConfigInfoDatastoreUrlPair;
	}
}

class VirtualMachineConfigInfoOverheadInfo extends phpDynamicProperties {
	public $initialMemoryReservation; //long
	public $initialSwapReservation; //long

	function __construct($initialMemoryReservation = null, $initialSwapReservation = null) {
		$this->initialMemoryReservation = $initialMemoryReservation;
		$this->initialSwapReservation = $initialSwapReservation;
	}
}

class VirtualMachineConfigInfo extends phpDynamicProperties {
	public $changeVersion; //string
	public $modified; //dateTime
	public $name; //string
	public $guestFullName; //string
	public $version; //string
	public $uuid; //string
	public $instanceUuid; //string
	public $npivNodeWorldWideName; //long
	public $npivPortWorldWideName; //long
	public $npivWorldWideNameType; //string
	public $npivDesiredNodeWwns; //short
	public $npivDesiredPortWwns; //short
	public $npivTemporaryDisabled; //boolean
	public $npivOnNonRdmDisks; //boolean
	public $locationId; //string
	public $template; //boolean
	public $guestId; //string
	public $alternateGuestName; //string
	public $annotation; //string
	public $files; //VirtualMachineFileInfo
	public $tools; //ToolsConfigInfo
	public $flags; //VirtualMachineFlagInfo
	public $consolePreferences; //VirtualMachineConsolePreferences
	public $defaultPowerOps; //VirtualMachineDefaultPowerOpInfo
	public $hardware; //VirtualHardware
	public $cpuAllocation; //ResourceAllocationInfo
	public $memoryAllocation; //ResourceAllocationInfo
	public $memoryHotAddEnabled; //boolean
	public $cpuHotAddEnabled; //boolean
	public $cpuHotRemoveEnabled; //boolean
	public $hotPlugMemoryLimit; //long
	public $hotPlugMemoryIncrementSize; //long
	public $cpuAffinity; //VirtualMachineAffinityInfo
	public $memoryAffinity; //VirtualMachineAffinityInfo
	public $networkShaper; //VirtualMachineNetworkShaperInfo
	public $extraConfig; //OptionValue
	public $cpuFeatureMask; //HostCpuIdInfo
	public $datastoreUrl; //VirtualMachineConfigInfoDatastoreUrlPair
	public $swapPlacement; //string
	public $bootOptions; //VirtualMachineBootOptions
	public $ftInfo; //FaultToleranceConfigInfo
	public $vAppConfig; //VmConfigInfo
	public $vAssertsEnabled; //boolean
	public $changeTrackingEnabled; //boolean
	public $firmware; //string
	public $maxMksConnections; //int
	public $guestAutoLockEnabled; //boolean
	public $managedBy; //ManagedByInfo
	public $memoryReservationLockedToMax; //boolean
	public $initialOverhead; //VirtualMachineConfigInfoOverheadInfo

	function __construct($changeVersion = null, $modified = null, $name = null, $guestFullName = null, $version = null, $uuid = null, $instanceUuid = null, $npivNodeWorldWideName = null, $npivPortWorldWideName = null, $npivWorldWideNameType = null, $npivDesiredNodeWwns = null, $npivDesiredPortWwns = null, $npivTemporaryDisabled = null, $npivOnNonRdmDisks = null, $locationId = null, $template = null, $guestId = null, $alternateGuestName = null, $annotation = null, $files = null, $tools = null, $flags = null, $consolePreferences = null, $defaultPowerOps = null, $hardware = null, $cpuAllocation = null, $memoryAllocation = null, $memoryHotAddEnabled = null, $cpuHotAddEnabled = null, $cpuHotRemoveEnabled = null, $hotPlugMemoryLimit = null, $hotPlugMemoryIncrementSize = null, $cpuAffinity = null, $memoryAffinity = null, $networkShaper = null, $extraConfig = null, $cpuFeatureMask = null, $datastoreUrl = null, $swapPlacement = null, $bootOptions = null, $ftInfo = null, $vAppConfig = null, $vAssertsEnabled = null, $changeTrackingEnabled = null, $firmware = null, $maxMksConnections = null, $guestAutoLockEnabled = null, $managedBy = null, $memoryReservationLockedToMax = null, $initialOverhead = null) {
		$this->changeVersion = $changeVersion;
		$this->modified = $modified;
		$this->name = $name;
		$this->guestFullName = $guestFullName;
		$this->version = $version;
		$this->uuid = $uuid;
		$this->instanceUuid = $instanceUuid;
		$this->npivNodeWorldWideName = $npivNodeWorldWideName;
		$this->npivPortWorldWideName = $npivPortWorldWideName;
		$this->npivWorldWideNameType = $npivWorldWideNameType;
		$this->npivDesiredNodeWwns = $npivDesiredNodeWwns;
		$this->npivDesiredPortWwns = $npivDesiredPortWwns;
		$this->npivTemporaryDisabled = $npivTemporaryDisabled;
		$this->npivOnNonRdmDisks = $npivOnNonRdmDisks;
		$this->locationId = $locationId;
		$this->template = $template;
		$this->guestId = $guestId;
		$this->alternateGuestName = $alternateGuestName;
		$this->annotation = $annotation;
		$this->files = $files;
		$this->tools = $tools;
		$this->flags = $flags;
		$this->consolePreferences = $consolePreferences;
		$this->defaultPowerOps = $defaultPowerOps;
		$this->hardware = $hardware;
		$this->cpuAllocation = $cpuAllocation;
		$this->memoryAllocation = $memoryAllocation;
		$this->memoryHotAddEnabled = $memoryHotAddEnabled;
		$this->cpuHotAddEnabled = $cpuHotAddEnabled;
		$this->cpuHotRemoveEnabled = $cpuHotRemoveEnabled;
		$this->hotPlugMemoryLimit = $hotPlugMemoryLimit;
		$this->hotPlugMemoryIncrementSize = $hotPlugMemoryIncrementSize;
		$this->cpuAffinity = $cpuAffinity;
		$this->memoryAffinity = $memoryAffinity;
		$this->networkShaper = $networkShaper;
		$this->extraConfig = $extraConfig;
		$this->cpuFeatureMask = $cpuFeatureMask;
		$this->datastoreUrl = $datastoreUrl;
		$this->swapPlacement = $swapPlacement;
		$this->bootOptions = $bootOptions;
		$this->ftInfo = $ftInfo;
		$this->vAppConfig = $vAppConfig;
		$this->vAssertsEnabled = $vAssertsEnabled;
		$this->changeTrackingEnabled = $changeTrackingEnabled;
		$this->firmware = $firmware;
		$this->maxMksConnections = $maxMksConnections;
		$this->guestAutoLockEnabled = $guestAutoLockEnabled;
		$this->managedBy = $managedBy;
		$this->memoryReservationLockedToMax = $memoryReservationLockedToMax;
		$this->initialOverhead = $initialOverhead;
	}
}

class VirtualMachineConfigOption extends phpDynamicProperties {
	public $version; //string
	public $description; //string
	public $guestOSDescriptor; //GuestOsDescriptor
	public $guestOSDefaultIndex; //int
	public $hardwareOptions; //VirtualHardwareOption
	public $capabilities; //VirtualMachineCapability
	public $datastore; //DatastoreOption
	public $defaultDevice; //VirtualDevice
	public $supportedMonitorType; //string
	public $supportedOvfEnvironmentTransport; //string
	public $supportedOvfInstallTransport; //string

	function __construct($version = null, $description = null, $guestOSDescriptor = null, $guestOSDefaultIndex = null, $hardwareOptions = null, $capabilities = null, $datastore = null, $defaultDevice = null, $supportedMonitorType = null, $supportedOvfEnvironmentTransport = null, $supportedOvfInstallTransport = null) {
		$this->version = $version;
		$this->description = $description;
		$this->guestOSDescriptor = $guestOSDescriptor;
		$this->guestOSDefaultIndex = $guestOSDefaultIndex;
		$this->hardwareOptions = $hardwareOptions;
		$this->capabilities = $capabilities;
		$this->datastore = $datastore;
		$this->defaultDevice = $defaultDevice;
		$this->supportedMonitorType = $supportedMonitorType;
		$this->supportedOvfEnvironmentTransport = $supportedOvfEnvironmentTransport;
		$this->supportedOvfInstallTransport = $supportedOvfInstallTransport;
	}
}

class VirtualMachineConfigOptionDescriptor extends phpDynamicProperties {
	public $key; //string
	public $description; //string
	public $host; //ManagedObjectReference
	public $createSupported; //boolean
	public $defaultConfigOption; //boolean

	function __construct($key = null, $description = null, $host = null, $createSupported = null, $defaultConfigOption = null) {
		$this->key = $key;
		$this->description = $description;
		$this->host = $host;
		$this->createSupported = $createSupported;
		$this->defaultConfigOption = $defaultConfigOption;
	}
}

class ArrayOfVirtualMachineConfigOptionDescriptor extends phpDynamicProperties {
	public $VirtualMachineConfigOptionDescriptor; //VirtualMachineConfigOptionDescriptor

	function __construct($VirtualMachineConfigOptionDescriptor = null) {
		$this->VirtualMachineConfigOptionDescriptor = $VirtualMachineConfigOptionDescriptor;
	}
}

class VirtualMachineCpuIdInfoSpec extends phpDynamicProperties {
	public $info; //HostCpuIdInfo

	function __construct($info = null) {
		$this->info = $info;
	}
}

class ArrayOfVirtualMachineCpuIdInfoSpec extends phpDynamicProperties {
	public $VirtualMachineCpuIdInfoSpec; //VirtualMachineCpuIdInfoSpec

	function __construct($VirtualMachineCpuIdInfoSpec = null) {
		$this->VirtualMachineCpuIdInfoSpec = $VirtualMachineCpuIdInfoSpec;
	}
}

class VirtualMachineConfigSpec extends phpDynamicProperties {
	public $changeVersion; //string
	public $name; //string
	public $version; //string
	public $uuid; //string
	public $instanceUuid; //string
	public $npivNodeWorldWideName; //long
	public $npivPortWorldWideName; //long
	public $npivWorldWideNameType; //string
	public $npivDesiredNodeWwns; //short
	public $npivDesiredPortWwns; //short
	public $npivTemporaryDisabled; //boolean
	public $npivOnNonRdmDisks; //boolean
	public $npivWorldWideNameOp; //string
	public $locationId; //string
	public $guestId; //string
	public $alternateGuestName; //string
	public $annotation; //string
	public $files; //VirtualMachineFileInfo
	public $tools; //ToolsConfigInfo
	public $flags; //VirtualMachineFlagInfo
	public $consolePreferences; //VirtualMachineConsolePreferences
	public $powerOpInfo; //VirtualMachineDefaultPowerOpInfo
	public $numCPUs; //int
	public $numCoresPerSocket; //int
	public $memoryMB; //long
	public $memoryHotAddEnabled; //boolean
	public $cpuHotAddEnabled; //boolean
	public $cpuHotRemoveEnabled; //boolean
	public $virtualICH7MPresent; //boolean
	public $virtualSMCPresent; //boolean
	public $deviceChange; //VirtualDeviceConfigSpec
	public $cpuAllocation; //ResourceAllocationInfo
	public $memoryAllocation; //ResourceAllocationInfo
	public $cpuAffinity; //VirtualMachineAffinityInfo
	public $memoryAffinity; //VirtualMachineAffinityInfo
	public $networkShaper; //VirtualMachineNetworkShaperInfo
	public $cpuFeatureMask; //VirtualMachineCpuIdInfoSpec
	public $extraConfig; //OptionValue
	public $swapPlacement; //string
	public $bootOptions; //VirtualMachineBootOptions
	public $vAppConfig; //VmConfigSpec
	public $ftInfo; //FaultToleranceConfigInfo
	public $vAppConfigRemoved; //boolean
	public $vAssertsEnabled; //boolean
	public $changeTrackingEnabled; //boolean
	public $firmware; //string
	public $maxMksConnections; //int
	public $guestAutoLockEnabled; //boolean
	public $managedBy; //ManagedByInfo
	public $memoryReservationLockedToMax; //boolean

	function __construct($changeVersion = null, $name = null, $version = null, $uuid = null, $instanceUuid = null, $npivNodeWorldWideName = null, $npivPortWorldWideName = null, $npivWorldWideNameType = null, $npivDesiredNodeWwns = null, $npivDesiredPortWwns = null, $npivTemporaryDisabled = null, $npivOnNonRdmDisks = null, $npivWorldWideNameOp = null, $locationId = null, $guestId = null, $alternateGuestName = null, $annotation = null, $files = null, $tools = null, $flags = null, $consolePreferences = null, $powerOpInfo = null, $numCPUs = null, $numCoresPerSocket = null, $memoryMB = null, $memoryHotAddEnabled = null, $cpuHotAddEnabled = null, $cpuHotRemoveEnabled = null, $virtualICH7MPresent = null, $virtualSMCPresent = null, $deviceChange = null, $cpuAllocation = null, $memoryAllocation = null, $cpuAffinity = null, $memoryAffinity = null, $networkShaper = null, $cpuFeatureMask = null, $extraConfig = null, $swapPlacement = null, $bootOptions = null, $vAppConfig = null, $ftInfo = null, $vAppConfigRemoved = null, $vAssertsEnabled = null, $changeTrackingEnabled = null, $firmware = null, $maxMksConnections = null, $guestAutoLockEnabled = null, $managedBy = null, $memoryReservationLockedToMax = null) {
		$this->changeVersion = $changeVersion;
		$this->name = $name;
		$this->version = $version;
		$this->uuid = $uuid;
		$this->instanceUuid = $instanceUuid;
		$this->npivNodeWorldWideName = $npivNodeWorldWideName;
		$this->npivPortWorldWideName = $npivPortWorldWideName;
		$this->npivWorldWideNameType = $npivWorldWideNameType;
		$this->npivDesiredNodeWwns = $npivDesiredNodeWwns;
		$this->npivDesiredPortWwns = $npivDesiredPortWwns;
		$this->npivTemporaryDisabled = $npivTemporaryDisabled;
		$this->npivOnNonRdmDisks = $npivOnNonRdmDisks;
		$this->npivWorldWideNameOp = $npivWorldWideNameOp;
		$this->locationId = $locationId;
		$this->guestId = $guestId;
		$this->alternateGuestName = $alternateGuestName;
		$this->annotation = $annotation;
		$this->files = $files;
		$this->tools = $tools;
		$this->flags = $flags;
		$this->consolePreferences = $consolePreferences;
		$this->powerOpInfo = $powerOpInfo;
		$this->numCPUs = $numCPUs;
		$this->numCoresPerSocket = $numCoresPerSocket;
		$this->memoryMB = $memoryMB;
		$this->memoryHotAddEnabled = $memoryHotAddEnabled;
		$this->cpuHotAddEnabled = $cpuHotAddEnabled;
		$this->cpuHotRemoveEnabled = $cpuHotRemoveEnabled;
		$this->virtualICH7MPresent = $virtualICH7MPresent;
		$this->virtualSMCPresent = $virtualSMCPresent;
		$this->deviceChange = $deviceChange;
		$this->cpuAllocation = $cpuAllocation;
		$this->memoryAllocation = $memoryAllocation;
		$this->cpuAffinity = $cpuAffinity;
		$this->memoryAffinity = $memoryAffinity;
		$this->networkShaper = $networkShaper;
		$this->cpuFeatureMask = $cpuFeatureMask;
		$this->extraConfig = $extraConfig;
		$this->swapPlacement = $swapPlacement;
		$this->bootOptions = $bootOptions;
		$this->vAppConfig = $vAppConfig;
		$this->ftInfo = $ftInfo;
		$this->vAppConfigRemoved = $vAppConfigRemoved;
		$this->vAssertsEnabled = $vAssertsEnabled;
		$this->changeTrackingEnabled = $changeTrackingEnabled;
		$this->firmware = $firmware;
		$this->maxMksConnections = $maxMksConnections;
		$this->guestAutoLockEnabled = $guestAutoLockEnabled;
		$this->managedBy = $managedBy;
		$this->memoryReservationLockedToMax = $memoryReservationLockedToMax;
	}
}

class ConfigTarget extends phpDynamicProperties {
	public $numCpus; //int
	public $numCpuCores; //int
	public $numNumaNodes; //int
	public $smcPresent; //boolean
	public $datastore; //VirtualMachineDatastoreInfo
	public $network; //VirtualMachineNetworkInfo
	public $distributedVirtualPortgroup; //DistributedVirtualPortgroupInfo
	public $distributedVirtualSwitch; //DistributedVirtualSwitchInfo
	public $cdRom; //VirtualMachineCdromInfo
	public $serial; //VirtualMachineSerialInfo
	public $parallel; //VirtualMachineParallelInfo
	public $sound; //VirtualMachineSoundInfo
	public $usb; //VirtualMachineUsbInfo
	public $floppy; //VirtualMachineFloppyInfo
	public $legacyNetworkInfo; //VirtualMachineLegacyNetworkSwitchInfo
	public $scsiPassthrough; //VirtualMachineScsiPassthroughInfo
	public $scsiDisk; //VirtualMachineScsiDiskDeviceInfo
	public $ideDisk; //VirtualMachineIdeDiskDeviceInfo
	public $maxMemMBOptimalPerf; //int
	public $resourcePool; //ResourcePoolRuntimeInfo
	public $autoVmotion; //boolean
	public $pciPassthrough; //VirtualMachinePciPassthroughInfo

	function __construct($numCpus = null, $numCpuCores = null, $numNumaNodes = null, $smcPresent = null, $datastore = null, $network = null, $distributedVirtualPortgroup = null, $distributedVirtualSwitch = null, $cdRom = null, $serial = null, $parallel = null, $sound = null, $usb = null, $floppy = null, $legacyNetworkInfo = null, $scsiPassthrough = null, $scsiDisk = null, $ideDisk = null, $maxMemMBOptimalPerf = null, $resourcePool = null, $autoVmotion = null, $pciPassthrough = null) {
		$this->numCpus = $numCpus;
		$this->numCpuCores = $numCpuCores;
		$this->numNumaNodes = $numNumaNodes;
		$this->smcPresent = $smcPresent;
		$this->datastore = $datastore;
		$this->network = $network;
		$this->distributedVirtualPortgroup = $distributedVirtualPortgroup;
		$this->distributedVirtualSwitch = $distributedVirtualSwitch;
		$this->cdRom = $cdRom;
		$this->serial = $serial;
		$this->parallel = $parallel;
		$this->sound = $sound;
		$this->usb = $usb;
		$this->floppy = $floppy;
		$this->legacyNetworkInfo = $legacyNetworkInfo;
		$this->scsiPassthrough = $scsiPassthrough;
		$this->scsiDisk = $scsiDisk;
		$this->ideDisk = $ideDisk;
		$this->maxMemMBOptimalPerf = $maxMemMBOptimalPerf;
		$this->resourcePool = $resourcePool;
		$this->autoVmotion = $autoVmotion;
		$this->pciPassthrough = $pciPassthrough;
	}
}

class VirtualMachineConsolePreferences extends phpDynamicProperties {
	public $powerOnWhenOpened; //boolean
	public $enterFullScreenOnPowerOn; //boolean
	public $closeOnPowerOffOrSuspend; //boolean

	function __construct($powerOnWhenOpened = null, $enterFullScreenOnPowerOn = null, $closeOnPowerOffOrSuspend = null) {
		$this->powerOnWhenOpened = $powerOnWhenOpened;
		$this->enterFullScreenOnPowerOn = $enterFullScreenOnPowerOn;
		$this->closeOnPowerOffOrSuspend = $closeOnPowerOffOrSuspend;
	}
}

class VirtualMachineDatastoreInfo extends phpDynamicProperties {
	public $datastore; //DatastoreSummary
	public $capability; //DatastoreCapability
	public $maxFileSize; //long
	public $mode; //string
	public $vStorageSupport; //string

	function __construct($datastore = null, $capability = null, $maxFileSize = null, $mode = null, $vStorageSupport = null) {
		$this->datastore = $datastore;
		$this->capability = $capability;
		$this->maxFileSize = $maxFileSize;
		$this->mode = $mode;
		$this->vStorageSupport = $vStorageSupport;
	}
}

class ArrayOfVirtualMachineDatastoreInfo extends phpDynamicProperties {
	public $VirtualMachineDatastoreInfo; //VirtualMachineDatastoreInfo

	function __construct($VirtualMachineDatastoreInfo = null) {
		$this->VirtualMachineDatastoreInfo = $VirtualMachineDatastoreInfo;
	}
}

class VirtualMachineDatastoreVolumeOption extends phpDynamicProperties {
	public $fileSystemType; //string
	public $majorVersion; //int

	function __construct($fileSystemType = null, $majorVersion = null) {
		$this->fileSystemType = $fileSystemType;
		$this->majorVersion = $majorVersion;
	}
}

class ArrayOfVirtualMachineDatastoreVolumeOption extends phpDynamicProperties {
	public $VirtualMachineDatastoreVolumeOption; //VirtualMachineDatastoreVolumeOption

	function __construct($VirtualMachineDatastoreVolumeOption = null) {
		$this->VirtualMachineDatastoreVolumeOption = $VirtualMachineDatastoreVolumeOption;
	}
}

class DatastoreOption extends phpDynamicProperties {
	public $unsupportedVolumes; //VirtualMachineDatastoreVolumeOption

	function __construct($unsupportedVolumes = null) {
		$this->unsupportedVolumes = $unsupportedVolumes;
	}
}

class VirtualMachineDefaultPowerOpInfo extends phpDynamicProperties {
	public $powerOffType; //string
	public $suspendType; //string
	public $resetType; //string
	public $defaultPowerOffType; //string
	public $defaultSuspendType; //string
	public $defaultResetType; //string
	public $standbyAction; //string

	function __construct($powerOffType = null, $suspendType = null, $resetType = null, $defaultPowerOffType = null, $defaultSuspendType = null, $defaultResetType = null, $standbyAction = null) {
		$this->powerOffType = $powerOffType;
		$this->suspendType = $suspendType;
		$this->resetType = $resetType;
		$this->defaultPowerOffType = $defaultPowerOffType;
		$this->defaultSuspendType = $defaultSuspendType;
		$this->defaultResetType = $defaultResetType;
		$this->standbyAction = $standbyAction;
	}
}

class VirtualMachineDeviceRuntimeInfoDeviceRuntimeState extends phpDynamicProperties {
}

class VirtualMachineDeviceRuntimeInfoVirtualEthernetCardRuntimeState extends phpDynamicProperties {
	public $vmDirectPathGen2Active; //boolean
	public $vmDirectPathGen2InactiveReasonVm; //string
	public $vmDirectPathGen2InactiveReasonOther; //string
	public $vmDirectPathGen2InactiveReasonExtended; //string

	function __construct($vmDirectPathGen2Active = null, $vmDirectPathGen2InactiveReasonVm = null, $vmDirectPathGen2InactiveReasonOther = null, $vmDirectPathGen2InactiveReasonExtended = null) {
		$this->vmDirectPathGen2Active = $vmDirectPathGen2Active;
		$this->vmDirectPathGen2InactiveReasonVm = $vmDirectPathGen2InactiveReasonVm;
		$this->vmDirectPathGen2InactiveReasonOther = $vmDirectPathGen2InactiveReasonOther;
		$this->vmDirectPathGen2InactiveReasonExtended = $vmDirectPathGen2InactiveReasonExtended;
	}
}

class VirtualMachineDeviceRuntimeInfo extends phpDynamicProperties {
	public $runtimeState; //VirtualMachineDeviceRuntimeInfoDeviceRuntimeState
	public $key; //int

	function __construct($runtimeState = null, $key = null) {
		$this->runtimeState = $runtimeState;
		$this->key = $key;
	}
}

class ArrayOfVirtualMachineDeviceRuntimeInfo extends phpDynamicProperties {
	public $VirtualMachineDeviceRuntimeInfo; //VirtualMachineDeviceRuntimeInfo

	function __construct($VirtualMachineDeviceRuntimeInfo = null) {
		$this->VirtualMachineDeviceRuntimeInfo = $VirtualMachineDeviceRuntimeInfo;
	}
}

class VirtualMachineDiskDeviceInfo extends phpDynamicProperties {
	public $capacity; //long
	public $vm; //ManagedObjectReference

	function __construct($capacity = null, $vm = null) {
		$this->capacity = $capacity;
		$this->vm = $vm;
	}
}

class FaultToleranceConfigInfo extends phpDynamicProperties {
	public $role; //int
	public $instanceUuids; //string
	public $configPaths; //string

	function __construct($role = null, $instanceUuids = null, $configPaths = null) {
		$this->role = $role;
		$this->instanceUuids = $instanceUuids;
		$this->configPaths = $configPaths;
	}
}

class FaultTolerancePrimaryConfigInfo extends phpDynamicProperties {
	public $secondaries; //ManagedObjectReference

	function __construct($secondaries = null) {
		$this->secondaries = $secondaries;
	}
}

class FaultToleranceSecondaryConfigInfo extends phpDynamicProperties {
	public $primaryVM; //ManagedObjectReference

	function __construct($primaryVM = null) {
		$this->primaryVM = $primaryVM;
	}
}

class FaultToleranceSecondaryOpResult extends phpDynamicProperties {
	public $vm; //ManagedObjectReference
	public $powerOnAttempted; //boolean
	public $powerOnResult; //ClusterPowerOnVmResult

	function __construct($vm = null, $powerOnAttempted = null, $powerOnResult = null) {
		$this->vm = $vm;
		$this->powerOnAttempted = $powerOnAttempted;
		$this->powerOnResult = $powerOnResult;
	}
}

class VirtualMachineFileInfo extends phpDynamicProperties {
	public $vmPathName; //string
	public $snapshotDirectory; //string
	public $suspendDirectory; //string
	public $logDirectory; //string

	function __construct($vmPathName = null, $snapshotDirectory = null, $suspendDirectory = null, $logDirectory = null) {
		$this->vmPathName = $vmPathName;
		$this->snapshotDirectory = $snapshotDirectory;
		$this->suspendDirectory = $suspendDirectory;
		$this->logDirectory = $logDirectory;
	}
}

class VirtualMachineFileLayoutDiskLayout extends phpDynamicProperties {
	public $key; //int
	public $diskFile; //string

	function __construct($key = null, $diskFile = null) {
		$this->key = $key;
		$this->diskFile = $diskFile;
	}
}

class ArrayOfVirtualMachineFileLayoutDiskLayout extends phpDynamicProperties {
	public $VirtualMachineFileLayoutDiskLayout; //VirtualMachineFileLayoutDiskLayout

	function __construct($VirtualMachineFileLayoutDiskLayout = null) {
		$this->VirtualMachineFileLayoutDiskLayout = $VirtualMachineFileLayoutDiskLayout;
	}
}

class VirtualMachineFileLayoutSnapshotLayout extends phpDynamicProperties {
	public $key; //ManagedObjectReference
	public $snapshotFile; //string

	function __construct($key = null, $snapshotFile = null) {
		$this->key = $key;
		$this->snapshotFile = $snapshotFile;
	}
}

class ArrayOfVirtualMachineFileLayoutSnapshotLayout extends phpDynamicProperties {
	public $VirtualMachineFileLayoutSnapshotLayout; //VirtualMachineFileLayoutSnapshotLayout

	function __construct($VirtualMachineFileLayoutSnapshotLayout = null) {
		$this->VirtualMachineFileLayoutSnapshotLayout = $VirtualMachineFileLayoutSnapshotLayout;
	}
}

class VirtualMachineFileLayout extends phpDynamicProperties {
	public $configFile; //string
	public $logFile; //string
	public $disk; //VirtualMachineFileLayoutDiskLayout
	public $snapshot; //VirtualMachineFileLayoutSnapshotLayout
	public $swapFile; //string

	function __construct($configFile = null, $logFile = null, $disk = null, $snapshot = null, $swapFile = null) {
		$this->configFile = $configFile;
		$this->logFile = $logFile;
		$this->disk = $disk;
		$this->snapshot = $snapshot;
		$this->swapFile = $swapFile;
	}
}

class VirtualMachineFileLayoutExFileInfo extends phpDynamicProperties {
	public $key; //int
	public $name; //string
	public $type; //string
	public $size; //long

	function __construct($key = null, $name = null, $type = null, $size = null) {
		$this->key = $key;
		$this->name = $name;
		$this->type = $type;
		$this->size = $size;
	}
}

class ArrayOfVirtualMachineFileLayoutExFileInfo extends phpDynamicProperties {
	public $VirtualMachineFileLayoutExFileInfo; //VirtualMachineFileLayoutExFileInfo

	function __construct($VirtualMachineFileLayoutExFileInfo = null) {
		$this->VirtualMachineFileLayoutExFileInfo = $VirtualMachineFileLayoutExFileInfo;
	}
}

class VirtualMachineFileLayoutExDiskUnit extends phpDynamicProperties {
	public $fileKey; //int

	function __construct($fileKey = null) {
		$this->fileKey = $fileKey;
	}
}

class ArrayOfVirtualMachineFileLayoutExDiskUnit extends phpDynamicProperties {
	public $VirtualMachineFileLayoutExDiskUnit; //VirtualMachineFileLayoutExDiskUnit

	function __construct($VirtualMachineFileLayoutExDiskUnit = null) {
		$this->VirtualMachineFileLayoutExDiskUnit = $VirtualMachineFileLayoutExDiskUnit;
	}
}

class VirtualMachineFileLayoutExDiskLayout extends phpDynamicProperties {
	public $key; //int
	public $chain; //VirtualMachineFileLayoutExDiskUnit

	function __construct($key = null, $chain = null) {
		$this->key = $key;
		$this->chain = $chain;
	}
}

class ArrayOfVirtualMachineFileLayoutExDiskLayout extends phpDynamicProperties {
	public $VirtualMachineFileLayoutExDiskLayout; //VirtualMachineFileLayoutExDiskLayout

	function __construct($VirtualMachineFileLayoutExDiskLayout = null) {
		$this->VirtualMachineFileLayoutExDiskLayout = $VirtualMachineFileLayoutExDiskLayout;
	}
}

class VirtualMachineFileLayoutExSnapshotLayout extends phpDynamicProperties {
	public $key; //ManagedObjectReference
	public $dataKey; //int
	public $disk; //VirtualMachineFileLayoutExDiskLayout

	function __construct($key = null, $dataKey = null, $disk = null) {
		$this->key = $key;
		$this->dataKey = $dataKey;
		$this->disk = $disk;
	}
}

class ArrayOfVirtualMachineFileLayoutExSnapshotLayout extends phpDynamicProperties {
	public $VirtualMachineFileLayoutExSnapshotLayout; //VirtualMachineFileLayoutExSnapshotLayout

	function __construct($VirtualMachineFileLayoutExSnapshotLayout = null) {
		$this->VirtualMachineFileLayoutExSnapshotLayout = $VirtualMachineFileLayoutExSnapshotLayout;
	}
}

class VirtualMachineFileLayoutEx extends phpDynamicProperties {
	public $file; //VirtualMachineFileLayoutExFileInfo
	public $disk; //VirtualMachineFileLayoutExDiskLayout
	public $snapshot; //VirtualMachineFileLayoutExSnapshotLayout
	public $timestamp; //dateTime

	function __construct($file = null, $disk = null, $snapshot = null, $timestamp = null) {
		$this->file = $file;
		$this->disk = $disk;
		$this->snapshot = $snapshot;
		$this->timestamp = $timestamp;
	}
}

class VirtualMachineFlagInfo extends phpDynamicProperties {
	public $disableAcceleration; //boolean
	public $enableLogging; //boolean
	public $useToe; //boolean
	public $runWithDebugInfo; //boolean
	public $monitorType; //string
	public $htSharing; //string
	public $snapshotDisabled; //boolean
	public $snapshotLocked; //boolean
	public $diskUuidEnabled; //boolean
	public $virtualMmuUsage; //string
	public $virtualExecUsage; //string
	public $snapshotPowerOffBehavior; //string
	public $recordReplayEnabled; //boolean

	function __construct($disableAcceleration = null, $enableLogging = null, $useToe = null, $runWithDebugInfo = null, $monitorType = null, $htSharing = null, $snapshotDisabled = null, $snapshotLocked = null, $diskUuidEnabled = null, $virtualMmuUsage = null, $virtualExecUsage = null, $snapshotPowerOffBehavior = null, $recordReplayEnabled = null) {
		$this->disableAcceleration = $disableAcceleration;
		$this->enableLogging = $enableLogging;
		$this->useToe = $useToe;
		$this->runWithDebugInfo = $runWithDebugInfo;
		$this->monitorType = $monitorType;
		$this->htSharing = $htSharing;
		$this->snapshotDisabled = $snapshotDisabled;
		$this->snapshotLocked = $snapshotLocked;
		$this->diskUuidEnabled = $diskUuidEnabled;
		$this->virtualMmuUsage = $virtualMmuUsage;
		$this->virtualExecUsage = $virtualExecUsage;
		$this->snapshotPowerOffBehavior = $snapshotPowerOffBehavior;
		$this->recordReplayEnabled = $recordReplayEnabled;
	}
}

class VirtualMachineFloppyInfo extends phpDynamicProperties {
}

class ArrayOfVirtualMachineFloppyInfo extends phpDynamicProperties {
	public $VirtualMachineFloppyInfo; //VirtualMachineFloppyInfo

	function __construct($VirtualMachineFloppyInfo = null) {
		$this->VirtualMachineFloppyInfo = $VirtualMachineFloppyInfo;
	}
}

class GuestDiskInfo extends phpDynamicProperties {
	public $diskPath; //string
	public $capacity; //long
	public $freeSpace; //long

	function __construct($diskPath = null, $capacity = null, $freeSpace = null) {
		$this->diskPath = $diskPath;
		$this->capacity = $capacity;
		$this->freeSpace = $freeSpace;
	}
}

class ArrayOfGuestDiskInfo extends phpDynamicProperties {
	public $GuestDiskInfo; //GuestDiskInfo

	function __construct($GuestDiskInfo = null) {
		$this->GuestDiskInfo = $GuestDiskInfo;
	}
}

class GuestNicInfo extends phpDynamicProperties {
	public $network; //string
	public $ipAddress; //string
	public $macAddress; //string
	public $connected; //boolean
	public $deviceConfigId; //int
	public $dnsConfig; //NetDnsConfigInfo
	public $ipConfig; //NetIpConfigInfo
	public $netBIOSConfig; //NetBIOSConfigInfo

	function __construct($network = null, $ipAddress = null, $macAddress = null, $connected = null, $deviceConfigId = null, $dnsConfig = null, $ipConfig = null, $netBIOSConfig = null) {
		$this->network = $network;
		$this->ipAddress = $ipAddress;
		$this->macAddress = $macAddress;
		$this->connected = $connected;
		$this->deviceConfigId = $deviceConfigId;
		$this->dnsConfig = $dnsConfig;
		$this->ipConfig = $ipConfig;
		$this->netBIOSConfig = $netBIOSConfig;
	}
}

class ArrayOfGuestNicInfo extends phpDynamicProperties {
	public $GuestNicInfo; //GuestNicInfo

	function __construct($GuestNicInfo = null) {
		$this->GuestNicInfo = $GuestNicInfo;
	}
}

class GuestStackInfo extends phpDynamicProperties {
	public $dnsConfig; //NetDnsConfigInfo
	public $ipRouteConfig; //NetIpRouteConfigInfo
	public $ipStackConfig; //KeyValue
	public $dhcpConfig; //NetDhcpConfigInfo

	function __construct($dnsConfig = null, $ipRouteConfig = null, $ipStackConfig = null, $dhcpConfig = null) {
		$this->dnsConfig = $dnsConfig;
		$this->ipRouteConfig = $ipRouteConfig;
		$this->ipStackConfig = $ipStackConfig;
		$this->dhcpConfig = $dhcpConfig;
	}
}

class ArrayOfGuestStackInfo extends phpDynamicProperties {
	public $GuestStackInfo; //GuestStackInfo

	function __construct($GuestStackInfo = null) {
		$this->GuestStackInfo = $GuestStackInfo;
	}
}

class GuestScreenInfo extends phpDynamicProperties {
	public $width; //int
	public $height; //int

	function __construct($width = null, $height = null) {
		$this->width = $width;
		$this->height = $height;
	}
}

class GuestInfo extends phpDynamicProperties {
	public $toolsStatus; //VirtualMachineToolsStatus
	public $toolsVersionStatus; //string
	public $toolsVersionStatus2; //string
	public $toolsRunningStatus; //string
	public $toolsVersion; //string
	public $guestId; //string
	public $guestFamily; //string
	public $guestFullName; //string
	public $hostName; //string
	public $ipAddress; //string
	public $net; //GuestNicInfo
	public $ipStack; //GuestStackInfo
	public $disk; //GuestDiskInfo
	public $screen; //GuestScreenInfo
	public $guestState; //string
	public $appHeartbeatStatus; //string
	public $guestOperationsReady; //boolean
	public $interactiveGuestOperationsReady; //boolean

	function __construct($toolsStatus = null, $toolsVersionStatus = null, $toolsVersionStatus2 = null, $toolsRunningStatus = null, $toolsVersion = null, $guestId = null, $guestFamily = null, $guestFullName = null, $hostName = null, $ipAddress = null, $net = null, $ipStack = null, $disk = null, $screen = null, $guestState = null, $appHeartbeatStatus = null, $guestOperationsReady = null, $interactiveGuestOperationsReady = null) {
		$this->toolsStatus = $toolsStatus;
		$this->toolsVersionStatus = $toolsVersionStatus;
		$this->toolsVersionStatus2 = $toolsVersionStatus2;
		$this->toolsRunningStatus = $toolsRunningStatus;
		$this->toolsVersion = $toolsVersion;
		$this->guestId = $guestId;
		$this->guestFamily = $guestFamily;
		$this->guestFullName = $guestFullName;
		$this->hostName = $hostName;
		$this->ipAddress = $ipAddress;
		$this->net = $net;
		$this->ipStack = $ipStack;
		$this->disk = $disk;
		$this->screen = $screen;
		$this->guestState = $guestState;
		$this->appHeartbeatStatus = $appHeartbeatStatus;
		$this->guestOperationsReady = $guestOperationsReady;
		$this->interactiveGuestOperationsReady = $interactiveGuestOperationsReady;
	}
}

class GuestOsDescriptor extends phpDynamicProperties {
	public $id; //string
	public $family; //string
	public $fullName; //string
	public $supportedMaxCPUs; //int
	public $numSupportedPhysicalSockets; //int
	public $numSupportedCoresPerSocket; //int
	public $supportedMinMemMB; //int
	public $supportedMaxMemMB; //int
	public $recommendedMemMB; //int
	public $recommendedColorDepth; //int
	public $supportedDiskControllerList; //string
	public $recommendedSCSIController; //string
	public $recommendedDiskController; //string
	public $supportedNumDisks; //int
	public $recommendedDiskSizeMB; //int
	public $supportedEthernetCard; //string
	public $recommendedEthernetCard; //string
	public $supportsSlaveDisk; //boolean
	public $cpuFeatureMask; //HostCpuIdInfo
	public $smcRequired; //boolean
	public $supportsWakeOnLan; //boolean
	public $supportsVMI; //boolean
	public $supportsMemoryHotAdd; //boolean
	public $supportsCpuHotAdd; //boolean
	public $supportsCpuHotRemove; //boolean
	public $supportedFirmware; //string
	public $recommendedFirmware; //string
	public $supportedUSBControllerList; //string
	public $recommendedUSBController; //string
	public $supports3D; //boolean
	public $smcRecommended; //boolean
	public $ich7mRecommended; //boolean
	public $usbRecommended; //boolean
	public $supportLevel; //string
	public $supportedForCreate; //boolean
	public $vRAMSizeInKB; //IntOption

	function __construct($id = null, $family = null, $fullName = null, $supportedMaxCPUs = null, $numSupportedPhysicalSockets = null, $numSupportedCoresPerSocket = null, $supportedMinMemMB = null, $supportedMaxMemMB = null, $recommendedMemMB = null, $recommendedColorDepth = null, $supportedDiskControllerList = null, $recommendedSCSIController = null, $recommendedDiskController = null, $supportedNumDisks = null, $recommendedDiskSizeMB = null, $supportedEthernetCard = null, $recommendedEthernetCard = null, $supportsSlaveDisk = null, $cpuFeatureMask = null, $smcRequired = null, $supportsWakeOnLan = null, $supportsVMI = null, $supportsMemoryHotAdd = null, $supportsCpuHotAdd = null, $supportsCpuHotRemove = null, $supportedFirmware = null, $recommendedFirmware = null, $supportedUSBControllerList = null, $recommendedUSBController = null, $supports3D = null, $smcRecommended = null, $ich7mRecommended = null, $usbRecommended = null, $supportLevel = null, $supportedForCreate = null, $vRAMSizeInKB = null) {
		$this->id = $id;
		$this->family = $family;
		$this->fullName = $fullName;
		$this->supportedMaxCPUs = $supportedMaxCPUs;
		$this->numSupportedPhysicalSockets = $numSupportedPhysicalSockets;
		$this->numSupportedCoresPerSocket = $numSupportedCoresPerSocket;
		$this->supportedMinMemMB = $supportedMinMemMB;
		$this->supportedMaxMemMB = $supportedMaxMemMB;
		$this->recommendedMemMB = $recommendedMemMB;
		$this->recommendedColorDepth = $recommendedColorDepth;
		$this->supportedDiskControllerList = $supportedDiskControllerList;
		$this->recommendedSCSIController = $recommendedSCSIController;
		$this->recommendedDiskController = $recommendedDiskController;
		$this->supportedNumDisks = $supportedNumDisks;
		$this->recommendedDiskSizeMB = $recommendedDiskSizeMB;
		$this->supportedEthernetCard = $supportedEthernetCard;
		$this->recommendedEthernetCard = $recommendedEthernetCard;
		$this->supportsSlaveDisk = $supportsSlaveDisk;
		$this->cpuFeatureMask = $cpuFeatureMask;
		$this->smcRequired = $smcRequired;
		$this->supportsWakeOnLan = $supportsWakeOnLan;
		$this->supportsVMI = $supportsVMI;
		$this->supportsMemoryHotAdd = $supportsMemoryHotAdd;
		$this->supportsCpuHotAdd = $supportsCpuHotAdd;
		$this->supportsCpuHotRemove = $supportsCpuHotRemove;
		$this->supportedFirmware = $supportedFirmware;
		$this->recommendedFirmware = $recommendedFirmware;
		$this->supportedUSBControllerList = $supportedUSBControllerList;
		$this->recommendedUSBController = $recommendedUSBController;
		$this->supports3D = $supports3D;
		$this->smcRecommended = $smcRecommended;
		$this->ich7mRecommended = $ich7mRecommended;
		$this->usbRecommended = $usbRecommended;
		$this->supportLevel = $supportLevel;
		$this->supportedForCreate = $supportedForCreate;
		$this->vRAMSizeInKB = $vRAMSizeInKB;
	}
}

class ArrayOfGuestOsDescriptor extends phpDynamicProperties {
	public $GuestOsDescriptor; //GuestOsDescriptor

	function __construct($GuestOsDescriptor = null) {
		$this->GuestOsDescriptor = $GuestOsDescriptor;
	}
}

class VirtualMachineIdeDiskDevicePartitionInfo extends phpDynamicProperties {
	public $id; //int
	public $capacity; //int

	function __construct($id = null, $capacity = null) {
		$this->id = $id;
		$this->capacity = $capacity;
	}
}

class ArrayOfVirtualMachineIdeDiskDevicePartitionInfo extends phpDynamicProperties {
	public $VirtualMachineIdeDiskDevicePartitionInfo; //VirtualMachineIdeDiskDevicePartitionInfo

	function __construct($VirtualMachineIdeDiskDevicePartitionInfo = null) {
		$this->VirtualMachineIdeDiskDevicePartitionInfo = $VirtualMachineIdeDiskDevicePartitionInfo;
	}
}

class VirtualMachineIdeDiskDeviceInfo extends phpDynamicProperties {
	public $partitionTable; //VirtualMachineIdeDiskDevicePartitionInfo

	function __construct($partitionTable = null) {
		$this->partitionTable = $partitionTable;
	}
}

class ArrayOfVirtualMachineIdeDiskDeviceInfo extends phpDynamicProperties {
	public $VirtualMachineIdeDiskDeviceInfo; //VirtualMachineIdeDiskDeviceInfo

	function __construct($VirtualMachineIdeDiskDeviceInfo = null) {
		$this->VirtualMachineIdeDiskDeviceInfo = $VirtualMachineIdeDiskDeviceInfo;
	}
}

class VirtualMachineLegacyNetworkSwitchInfo extends phpDynamicProperties {
	public $name; //string

	function __construct($name = null) {
		$this->name = $name;
	}
}

class ArrayOfVirtualMachineLegacyNetworkSwitchInfo extends phpDynamicProperties {
	public $VirtualMachineLegacyNetworkSwitchInfo; //VirtualMachineLegacyNetworkSwitchInfo

	function __construct($VirtualMachineLegacyNetworkSwitchInfo = null) {
		$this->VirtualMachineLegacyNetworkSwitchInfo = $VirtualMachineLegacyNetworkSwitchInfo;
	}
}

class VirtualMachineMessage extends phpDynamicProperties {
	public $id; //string
	public $argument; //anyType
	public $text; //string

	function __construct($id = null, $argument = null, $text = null) {
		$this->id = $id;
		$this->argument = $argument;
		$this->text = $text;
	}
}

class ArrayOfVirtualMachineMessage extends phpDynamicProperties {
	public $VirtualMachineMessage; //VirtualMachineMessage

	function __construct($VirtualMachineMessage = null) {
		$this->VirtualMachineMessage = $VirtualMachineMessage;
	}
}

class VirtualMachineNetworkInfo extends phpDynamicProperties {
	public $network; //NetworkSummary

	function __construct($network = null) {
		$this->network = $network;
	}
}

class ArrayOfVirtualMachineNetworkInfo extends phpDynamicProperties {
	public $VirtualMachineNetworkInfo; //VirtualMachineNetworkInfo

	function __construct($VirtualMachineNetworkInfo = null) {
		$this->VirtualMachineNetworkInfo = $VirtualMachineNetworkInfo;
	}
}

class VirtualMachineNetworkShaperInfo extends phpDynamicProperties {
	public $enabled; //boolean
	public $peakBps; //long
	public $averageBps; //long
	public $burstSize; //long

	function __construct($enabled = null, $peakBps = null, $averageBps = null, $burstSize = null) {
		$this->enabled = $enabled;
		$this->peakBps = $peakBps;
		$this->averageBps = $averageBps;
		$this->burstSize = $burstSize;
	}
}

class VirtualMachineParallelInfo extends phpDynamicProperties {
}

class ArrayOfVirtualMachineParallelInfo extends phpDynamicProperties {
	public $VirtualMachineParallelInfo; //VirtualMachineParallelInfo

	function __construct($VirtualMachineParallelInfo = null) {
		$this->VirtualMachineParallelInfo = $VirtualMachineParallelInfo;
	}
}

class VirtualMachinePciPassthroughInfo extends phpDynamicProperties {
	public $pciDevice; //HostPciDevice
	public $systemId; //string

	function __construct($pciDevice = null, $systemId = null) {
		$this->pciDevice = $pciDevice;
		$this->systemId = $systemId;
	}
}

class ArrayOfVirtualMachinePciPassthroughInfo extends phpDynamicProperties {
	public $VirtualMachinePciPassthroughInfo; //VirtualMachinePciPassthroughInfo

	function __construct($VirtualMachinePciPassthroughInfo = null) {
		$this->VirtualMachinePciPassthroughInfo = $VirtualMachinePciPassthroughInfo;
	}
}

class VirtualMachineQuestionInfo extends phpDynamicProperties {
	public $id; //string
	public $text; //string
	public $choice; //ChoiceOption
	public $message; //VirtualMachineMessage

	function __construct($id = null, $text = null, $choice = null, $message = null) {
		$this->id = $id;
		$this->text = $text;
		$this->choice = $choice;
		$this->message = $message;
	}
}

class VirtualMachineRelocateSpecDiskLocator extends phpDynamicProperties {
	public $diskId; //int
	public $datastore; //ManagedObjectReference
	public $diskMoveType; //string
	public $diskBackingInfo; //VirtualDeviceBackingInfo

	function __construct($diskId = null, $datastore = null, $diskMoveType = null, $diskBackingInfo = null) {
		$this->diskId = $diskId;
		$this->datastore = $datastore;
		$this->diskMoveType = $diskMoveType;
		$this->diskBackingInfo = $diskBackingInfo;
	}
}

class ArrayOfVirtualMachineRelocateSpecDiskLocator extends phpDynamicProperties {
	public $VirtualMachineRelocateSpecDiskLocator; //VirtualMachineRelocateSpecDiskLocator

	function __construct($VirtualMachineRelocateSpecDiskLocator = null) {
		$this->VirtualMachineRelocateSpecDiskLocator = $VirtualMachineRelocateSpecDiskLocator;
	}
}

class VirtualMachineRelocateSpec extends phpDynamicProperties {
	public $datastore; //ManagedObjectReference
	public $diskMoveType; //string
	public $pool; //ManagedObjectReference
	public $host; //ManagedObjectReference
	public $disk; //VirtualMachineRelocateSpecDiskLocator
	public $transform; //VirtualMachineRelocateTransformation

	function __construct($datastore = null, $diskMoveType = null, $pool = null, $host = null, $disk = null, $transform = null) {
		$this->datastore = $datastore;
		$this->diskMoveType = $diskMoveType;
		$this->pool = $pool;
		$this->host = $host;
		$this->disk = $disk;
		$this->transform = $transform;
	}
}

class ReplicationInfoDiskSettings extends phpDynamicProperties {
	public $key; //int
	public $diskReplicationId; //string

	function __construct($key = null, $diskReplicationId = null) {
		$this->key = $key;
		$this->diskReplicationId = $diskReplicationId;
	}
}

class ArrayOfReplicationInfoDiskSettings extends phpDynamicProperties {
	public $ReplicationInfoDiskSettings; //ReplicationInfoDiskSettings

	function __construct($ReplicationInfoDiskSettings = null) {
		$this->ReplicationInfoDiskSettings = $ReplicationInfoDiskSettings;
	}
}

class VirtualMachineRuntimeInfoDasProtectionState extends phpDynamicProperties {
	public $dasProtected; //boolean

	function __construct($dasProtected = null) {
		$this->dasProtected = $dasProtected;
	}
}

class VirtualMachineRuntimeInfo extends phpDynamicProperties {
	public $device; //VirtualMachineDeviceRuntimeInfo
	public $host; //ManagedObjectReference
	public $connectionState; //VirtualMachineConnectionState
	public $powerState; //VirtualMachinePowerState
	public $faultToleranceState; //VirtualMachineFaultToleranceState
	public $dasVmProtection; //VirtualMachineRuntimeInfoDasProtectionState
	public $toolsInstallerMounted; //boolean
	public $suspendTime; //dateTime
	public $bootTime; //dateTime
	public $suspendInterval; //long
	public $question; //VirtualMachineQuestionInfo
	public $memoryOverhead; //long
	public $maxCpuUsage; //int
	public $maxMemoryUsage; //int
	public $numMksConnections; //int
	public $recordReplayState; //VirtualMachineRecordReplayState
	public $cleanPowerOff; //boolean
	public $needSecondaryReason; //string
	public $minRequiredEVCModeKey; //string
	public $consolidationNeeded; //boolean

	function __construct($device = null, $host = null, $connectionState = null, $powerState = null, $faultToleranceState = null, $dasVmProtection = null, $toolsInstallerMounted = null, $suspendTime = null, $bootTime = null, $suspendInterval = null, $question = null, $memoryOverhead = null, $maxCpuUsage = null, $maxMemoryUsage = null, $numMksConnections = null, $recordReplayState = null, $cleanPowerOff = null, $needSecondaryReason = null, $minRequiredEVCModeKey = null, $consolidationNeeded = null) {
		$this->device = $device;
		$this->host = $host;
		$this->connectionState = $connectionState;
		$this->powerState = $powerState;
		$this->faultToleranceState = $faultToleranceState;
		$this->dasVmProtection = $dasVmProtection;
		$this->toolsInstallerMounted = $toolsInstallerMounted;
		$this->suspendTime = $suspendTime;
		$this->bootTime = $bootTime;
		$this->suspendInterval = $suspendInterval;
		$this->question = $question;
		$this->memoryOverhead = $memoryOverhead;
		$this->maxCpuUsage = $maxCpuUsage;
		$this->maxMemoryUsage = $maxMemoryUsage;
		$this->numMksConnections = $numMksConnections;
		$this->recordReplayState = $recordReplayState;
		$this->cleanPowerOff = $cleanPowerOff;
		$this->needSecondaryReason = $needSecondaryReason;
		$this->minRequiredEVCModeKey = $minRequiredEVCModeKey;
		$this->consolidationNeeded = $consolidationNeeded;
	}
}

class VirtualMachineScsiDiskDeviceInfo extends phpDynamicProperties {
	public $disk; //HostScsiDisk
	public $transportHint; //string
	public $lunNumber; //int

	function __construct($disk = null, $transportHint = null, $lunNumber = null) {
		$this->disk = $disk;
		$this->transportHint = $transportHint;
		$this->lunNumber = $lunNumber;
	}
}

class ArrayOfVirtualMachineScsiDiskDeviceInfo extends phpDynamicProperties {
	public $VirtualMachineScsiDiskDeviceInfo; //VirtualMachineScsiDiskDeviceInfo

	function __construct($VirtualMachineScsiDiskDeviceInfo = null) {
		$this->VirtualMachineScsiDiskDeviceInfo = $VirtualMachineScsiDiskDeviceInfo;
	}
}

class VirtualMachineScsiPassthroughInfo extends phpDynamicProperties {
	public $scsiClass; //string
	public $vendor; //string
	public $physicalUnitNumber; //int

	function __construct($scsiClass = null, $vendor = null, $physicalUnitNumber = null) {
		$this->scsiClass = $scsiClass;
		$this->vendor = $vendor;
		$this->physicalUnitNumber = $physicalUnitNumber;
	}
}

class ArrayOfVirtualMachineScsiPassthroughInfo extends phpDynamicProperties {
	public $VirtualMachineScsiPassthroughInfo; //VirtualMachineScsiPassthroughInfo

	function __construct($VirtualMachineScsiPassthroughInfo = null) {
		$this->VirtualMachineScsiPassthroughInfo = $VirtualMachineScsiPassthroughInfo;
	}
}

class VirtualMachineSerialInfo extends phpDynamicProperties {
}

class ArrayOfVirtualMachineSerialInfo extends phpDynamicProperties {
	public $VirtualMachineSerialInfo; //VirtualMachineSerialInfo

	function __construct($VirtualMachineSerialInfo = null) {
		$this->VirtualMachineSerialInfo = $VirtualMachineSerialInfo;
	}
}

class VirtualMachineSnapshotInfo extends phpDynamicProperties {
	public $currentSnapshot; //ManagedObjectReference
	public $rootSnapshotList; //VirtualMachineSnapshotTree

	function __construct($currentSnapshot = null, $rootSnapshotList = null) {
		$this->currentSnapshot = $currentSnapshot;
		$this->rootSnapshotList = $rootSnapshotList;
	}
}

class VirtualMachineSnapshotTree extends phpDynamicProperties {
	public $snapshot; //ManagedObjectReference
	public $vm; //ManagedObjectReference
	public $name; //string
	public $description; //string
	public $id; //int
	public $createTime; //dateTime
	public $state; //VirtualMachinePowerState
	public $quiesced; //boolean
	public $backupManifest; //string
	public $childSnapshotList; //VirtualMachineSnapshotTree
	public $replaySupported; //boolean

	function __construct($snapshot = null, $vm = null, $name = null, $description = null, $id = null, $createTime = null, $state = null, $quiesced = null, $backupManifest = null, $childSnapshotList = null, $replaySupported = null) {
		$this->snapshot = $snapshot;
		$this->vm = $vm;
		$this->name = $name;
		$this->description = $description;
		$this->id = $id;
		$this->createTime = $createTime;
		$this->state = $state;
		$this->quiesced = $quiesced;
		$this->backupManifest = $backupManifest;
		$this->childSnapshotList = $childSnapshotList;
		$this->replaySupported = $replaySupported;
	}
}

class ArrayOfVirtualMachineSnapshotTree extends phpDynamicProperties {
	public $VirtualMachineSnapshotTree; //VirtualMachineSnapshotTree

	function __construct($VirtualMachineSnapshotTree = null) {
		$this->VirtualMachineSnapshotTree = $VirtualMachineSnapshotTree;
	}
}

class VirtualMachineSoundInfo extends phpDynamicProperties {
}

class ArrayOfVirtualMachineSoundInfo extends phpDynamicProperties {
	public $VirtualMachineSoundInfo; //VirtualMachineSoundInfo

	function __construct($VirtualMachineSoundInfo = null) {
		$this->VirtualMachineSoundInfo = $VirtualMachineSoundInfo;
	}
}

class VirtualMachineUsageOnDatastore extends phpDynamicProperties {
	public $datastore; //ManagedObjectReference
	public $committed; //long
	public $uncommitted; //long
	public $unshared; //long

	function __construct($datastore = null, $committed = null, $uncommitted = null, $unshared = null) {
		$this->datastore = $datastore;
		$this->committed = $committed;
		$this->uncommitted = $uncommitted;
		$this->unshared = $unshared;
	}
}

class ArrayOfVirtualMachineUsageOnDatastore extends phpDynamicProperties {
	public $VirtualMachineUsageOnDatastore; //VirtualMachineUsageOnDatastore

	function __construct($VirtualMachineUsageOnDatastore = null) {
		$this->VirtualMachineUsageOnDatastore = $VirtualMachineUsageOnDatastore;
	}
}

class VirtualMachineStorageInfo extends phpDynamicProperties {
	public $perDatastoreUsage; //VirtualMachineUsageOnDatastore
	public $timestamp; //dateTime

	function __construct($perDatastoreUsage = null, $timestamp = null) {
		$this->perDatastoreUsage = $perDatastoreUsage;
		$this->timestamp = $timestamp;
	}
}

class VirtualMachineConfigSummary extends phpDynamicProperties {
	public $name; //string
	public $template; //boolean
	public $vmPathName; //string
	public $memorySizeMB; //int
	public $cpuReservation; //int
	public $memoryReservation; //int
	public $numCpu; //int
	public $numEthernetCards; //int
	public $numVirtualDisks; //int
	public $uuid; //string
	public $instanceUuid; //string
	public $guestId; //string
	public $guestFullName; //string
	public $annotation; //string
	public $product; //VAppProductInfo
	public $installBootRequired; //boolean
	public $ftInfo; //FaultToleranceConfigInfo
	public $managedBy; //ManagedByInfo

	function __construct($name = null, $template = null, $vmPathName = null, $memorySizeMB = null, $cpuReservation = null, $memoryReservation = null, $numCpu = null, $numEthernetCards = null, $numVirtualDisks = null, $uuid = null, $instanceUuid = null, $guestId = null, $guestFullName = null, $annotation = null, $product = null, $installBootRequired = null, $ftInfo = null, $managedBy = null) {
		$this->name = $name;
		$this->template = $template;
		$this->vmPathName = $vmPathName;
		$this->memorySizeMB = $memorySizeMB;
		$this->cpuReservation = $cpuReservation;
		$this->memoryReservation = $memoryReservation;
		$this->numCpu = $numCpu;
		$this->numEthernetCards = $numEthernetCards;
		$this->numVirtualDisks = $numVirtualDisks;
		$this->uuid = $uuid;
		$this->instanceUuid = $instanceUuid;
		$this->guestId = $guestId;
		$this->guestFullName = $guestFullName;
		$this->annotation = $annotation;
		$this->product = $product;
		$this->installBootRequired = $installBootRequired;
		$this->ftInfo = $ftInfo;
		$this->managedBy = $managedBy;
	}
}

class VirtualMachineQuickStats extends phpDynamicProperties {
	public $overallCpuUsage; //int
	public $overallCpuDemand; //int
	public $guestMemoryUsage; //int
	public $hostMemoryUsage; //int
	public $guestHeartbeatStatus; //ManagedEntityStatus
	public $distributedCpuEntitlement; //int
	public $distributedMemoryEntitlement; //int
	public $staticCpuEntitlement; //int
	public $staticMemoryEntitlement; //int
	public $privateMemory; //int
	public $sharedMemory; //int
	public $swappedMemory; //int
	public $balloonedMemory; //int
	public $consumedOverheadMemory; //int
	public $ftLogBandwidth; //int
	public $ftSecondaryLatency; //int
	public $ftLatencyStatus; //ManagedEntityStatus
	public $compressedMemory; //long
	public $uptimeSeconds; //int
	public $ssdSwappedMemory; //long

	function __construct($overallCpuUsage = null, $overallCpuDemand = null, $guestMemoryUsage = null, $hostMemoryUsage = null, $guestHeartbeatStatus = null, $distributedCpuEntitlement = null, $distributedMemoryEntitlement = null, $staticCpuEntitlement = null, $staticMemoryEntitlement = null, $privateMemory = null, $sharedMemory = null, $swappedMemory = null, $balloonedMemory = null, $consumedOverheadMemory = null, $ftLogBandwidth = null, $ftSecondaryLatency = null, $ftLatencyStatus = null, $compressedMemory = null, $uptimeSeconds = null, $ssdSwappedMemory = null) {
		$this->overallCpuUsage = $overallCpuUsage;
		$this->overallCpuDemand = $overallCpuDemand;
		$this->guestMemoryUsage = $guestMemoryUsage;
		$this->hostMemoryUsage = $hostMemoryUsage;
		$this->guestHeartbeatStatus = $guestHeartbeatStatus;
		$this->distributedCpuEntitlement = $distributedCpuEntitlement;
		$this->distributedMemoryEntitlement = $distributedMemoryEntitlement;
		$this->staticCpuEntitlement = $staticCpuEntitlement;
		$this->staticMemoryEntitlement = $staticMemoryEntitlement;
		$this->privateMemory = $privateMemory;
		$this->sharedMemory = $sharedMemory;
		$this->swappedMemory = $swappedMemory;
		$this->balloonedMemory = $balloonedMemory;
		$this->consumedOverheadMemory = $consumedOverheadMemory;
		$this->ftLogBandwidth = $ftLogBandwidth;
		$this->ftSecondaryLatency = $ftSecondaryLatency;
		$this->ftLatencyStatus = $ftLatencyStatus;
		$this->compressedMemory = $compressedMemory;
		$this->uptimeSeconds = $uptimeSeconds;
		$this->ssdSwappedMemory = $ssdSwappedMemory;
	}
}

class VirtualMachineGuestSummary extends phpDynamicProperties {
	public $guestId; //string
	public $guestFullName; //string
	public $toolsStatus; //VirtualMachineToolsStatus
	public $toolsVersionStatus; //string
	public $toolsVersionStatus2; //string
	public $toolsRunningStatus; //string
	public $hostName; //string
	public $ipAddress; //string

	function __construct($guestId = null, $guestFullName = null, $toolsStatus = null, $toolsVersionStatus = null, $toolsVersionStatus2 = null, $toolsRunningStatus = null, $hostName = null, $ipAddress = null) {
		$this->guestId = $guestId;
		$this->guestFullName = $guestFullName;
		$this->toolsStatus = $toolsStatus;
		$this->toolsVersionStatus = $toolsVersionStatus;
		$this->toolsVersionStatus2 = $toolsVersionStatus2;
		$this->toolsRunningStatus = $toolsRunningStatus;
		$this->hostName = $hostName;
		$this->ipAddress = $ipAddress;
	}
}

class VirtualMachineStorageSummary extends phpDynamicProperties {
	public $committed; //long
	public $uncommitted; //long
	public $unshared; //long
	public $timestamp; //dateTime

	function __construct($committed = null, $uncommitted = null, $unshared = null, $timestamp = null) {
		$this->committed = $committed;
		$this->uncommitted = $uncommitted;
		$this->unshared = $unshared;
		$this->timestamp = $timestamp;
	}
}

class VirtualMachineSummary extends phpDynamicProperties {
	public $vm; //ManagedObjectReference
	public $runtime; //VirtualMachineRuntimeInfo
	public $guest; //VirtualMachineGuestSummary
	public $config; //VirtualMachineConfigSummary
	public $storage; //VirtualMachineStorageSummary
	public $quickStats; //VirtualMachineQuickStats
	public $overallStatus; //ManagedEntityStatus
	public $customValue; //CustomFieldValue

	function __construct($vm = null, $runtime = null, $guest = null, $config = null, $storage = null, $quickStats = null, $overallStatus = null, $customValue = null) {
		$this->vm = $vm;
		$this->runtime = $runtime;
		$this->guest = $guest;
		$this->config = $config;
		$this->storage = $storage;
		$this->quickStats = $quickStats;
		$this->overallStatus = $overallStatus;
		$this->customValue = $customValue;
	}
}

class ArrayOfVirtualMachineSummary extends phpDynamicProperties {
	public $VirtualMachineSummary; //VirtualMachineSummary

	function __construct($VirtualMachineSummary = null) {
		$this->VirtualMachineSummary = $VirtualMachineSummary;
	}
}

class VirtualMachineTargetInfo extends phpDynamicProperties {
	public $name; //string
	public $configurationTag; //string

	function __construct($name = null, $configurationTag = null) {
		$this->name = $name;
		$this->configurationTag = $configurationTag;
	}
}

class ToolsConfigInfoToolsLastInstallInfo extends phpDynamicProperties {
	public $counter; //int
	public $fault; //LocalizedMethodFault

	function __construct($counter = null, $fault = null) {
		$this->counter = $counter;
		$this->fault = $fault;
	}
}

class ToolsConfigInfo extends phpDynamicProperties {
	public $toolsVersion; //int
	public $afterPowerOn; //boolean
	public $afterResume; //boolean
	public $beforeGuestStandby; //boolean
	public $beforeGuestShutdown; //boolean
	public $beforeGuestReboot; //boolean
	public $toolsUpgradePolicy; //string
	public $pendingCustomization; //string
	public $syncTimeWithHost; //boolean
	public $lastInstallInfo; //ToolsConfigInfoToolsLastInstallInfo

	function __construct($toolsVersion = null, $afterPowerOn = null, $afterResume = null, $beforeGuestStandby = null, $beforeGuestShutdown = null, $beforeGuestReboot = null, $toolsUpgradePolicy = null, $pendingCustomization = null, $syncTimeWithHost = null, $lastInstallInfo = null) {
		$this->toolsVersion = $toolsVersion;
		$this->afterPowerOn = $afterPowerOn;
		$this->afterResume = $afterResume;
		$this->beforeGuestStandby = $beforeGuestStandby;
		$this->beforeGuestShutdown = $beforeGuestShutdown;
		$this->beforeGuestReboot = $beforeGuestReboot;
		$this->toolsUpgradePolicy = $toolsUpgradePolicy;
		$this->pendingCustomization = $pendingCustomization;
		$this->syncTimeWithHost = $syncTimeWithHost;
		$this->lastInstallInfo = $lastInstallInfo;
	}
}

class VirtualMachineUsbInfo extends phpDynamicProperties {
	public $description; //string
	public $vendor; //int
	public $product; //int
	public $physicalPath; //string
	public $family; //string
	public $speed; //string
	public $summary; //VirtualMachineSummary

	function __construct($description = null, $vendor = null, $product = null, $physicalPath = null, $family = null, $speed = null, $summary = null) {
		$this->description = $description;
		$this->vendor = $vendor;
		$this->product = $product;
		$this->physicalPath = $physicalPath;
		$this->family = $family;
		$this->speed = $speed;
		$this->summary = $summary;
	}
}

class ArrayOfVirtualMachineUsbInfo extends phpDynamicProperties {
	public $VirtualMachineUsbInfo; //VirtualMachineUsbInfo

	function __construct($VirtualMachineUsbInfo = null) {
		$this->VirtualMachineUsbInfo = $VirtualMachineUsbInfo;
	}
}

class VirtualHardware extends phpDynamicProperties {
	public $numCPU; //int
	public $numCoresPerSocket; //int
	public $memoryMB; //int
	public $virtualICH7MPresent; //boolean
	public $virtualSMCPresent; //boolean
	public $device; //VirtualDevice

	function __construct($numCPU = null, $numCoresPerSocket = null, $memoryMB = null, $virtualICH7MPresent = null, $virtualSMCPresent = null, $device = null) {
		$this->numCPU = $numCPU;
		$this->numCoresPerSocket = $numCoresPerSocket;
		$this->memoryMB = $memoryMB;
		$this->virtualICH7MPresent = $virtualICH7MPresent;
		$this->virtualSMCPresent = $virtualSMCPresent;
		$this->device = $device;
	}
}

class VirtualHardwareOption extends phpDynamicProperties {
	public $hwVersion; //int
	public $virtualDeviceOption; //VirtualDeviceOption
	public $deviceListReadonly; //boolean
	public $numCPU; //int
	public $numCoresPerSocket; //IntOption
	public $numCpuReadonly; //boolean
	public $memoryMB; //LongOption
	public $numPCIControllers; //IntOption
	public $numIDEControllers; //IntOption
	public $numUSBControllers; //IntOption
	public $numUSBXHCIControllers; //IntOption
	public $numSIOControllers; //IntOption
	public $numPS2Controllers; //IntOption
	public $licensingLimit; //string
	public $numSupportedWwnPorts; //IntOption
	public $numSupportedWwnNodes; //IntOption
	public $resourceConfigOption; //ResourceConfigOption

	function __construct($hwVersion = null, $virtualDeviceOption = null, $deviceListReadonly = null, $numCPU = null, $numCoresPerSocket = null, $numCpuReadonly = null, $memoryMB = null, $numPCIControllers = null, $numIDEControllers = null, $numUSBControllers = null, $numUSBXHCIControllers = null, $numSIOControllers = null, $numPS2Controllers = null, $licensingLimit = null, $numSupportedWwnPorts = null, $numSupportedWwnNodes = null, $resourceConfigOption = null) {
		$this->hwVersion = $hwVersion;
		$this->virtualDeviceOption = $virtualDeviceOption;
		$this->deviceListReadonly = $deviceListReadonly;
		$this->numCPU = $numCPU;
		$this->numCoresPerSocket = $numCoresPerSocket;
		$this->numCpuReadonly = $numCpuReadonly;
		$this->memoryMB = $memoryMB;
		$this->numPCIControllers = $numPCIControllers;
		$this->numIDEControllers = $numIDEControllers;
		$this->numUSBControllers = $numUSBControllers;
		$this->numUSBXHCIControllers = $numUSBXHCIControllers;
		$this->numSIOControllers = $numSIOControllers;
		$this->numPS2Controllers = $numPS2Controllers;
		$this->licensingLimit = $licensingLimit;
		$this->numSupportedWwnPorts = $numSupportedWwnPorts;
		$this->numSupportedWwnNodes = $numSupportedWwnNodes;
		$this->resourceConfigOption = $resourceConfigOption;
	}
}

class VirtualMachineImportSpec extends phpDynamicProperties {
	public $configSpec; //VirtualMachineConfigSpec
	public $resPoolEntity; //ManagedObjectReference

	function __construct($configSpec = null, $resPoolEntity = null) {
		$this->configSpec = $configSpec;
		$this->resPoolEntity = $resPoolEntity;
	}
}

class CheckResult extends phpDynamicProperties {
	public $vm; //ManagedObjectReference
	public $host; //ManagedObjectReference
	public $warning; //LocalizedMethodFault
	public $error; //LocalizedMethodFault

	function __construct($vm = null, $host = null, $warning = null, $error = null) {
		$this->vm = $vm;
		$this->host = $host;
		$this->warning = $warning;
		$this->error = $error;
	}
}

class ArrayOfCheckResult extends phpDynamicProperties {
	public $CheckResult; //CheckResult

	function __construct($CheckResult = null) {
		$this->CheckResult = $CheckResult;
	}
}

class CustomizationIPSettingsIpV6AddressSpec extends phpDynamicProperties {
	public $ip; //CustomizationIpV6Generator
	public $gateway; //string

	function __construct($ip = null, $gateway = null) {
		$this->ip = $ip;
		$this->gateway = $gateway;
	}
}

class CustomizationIPSettings extends phpDynamicProperties {
	public $ip; //CustomizationIpGenerator
	public $subnetMask; //string
	public $gateway; //string
	public $ipV6Spec; //CustomizationIPSettingsIpV6AddressSpec
	public $dnsServerList; //string
	public $dnsDomain; //string
	public $primaryWINS; //string
	public $secondaryWINS; //string
	public $netBIOS; //CustomizationNetBIOSMode

	function __construct($ip = null, $subnetMask = null, $gateway = null, $ipV6Spec = null, $dnsServerList = null, $dnsDomain = null, $primaryWINS = null, $secondaryWINS = null, $netBIOS = null) {
		$this->ip = $ip;
		$this->subnetMask = $subnetMask;
		$this->gateway = $gateway;
		$this->ipV6Spec = $ipV6Spec;
		$this->dnsServerList = $dnsServerList;
		$this->dnsDomain = $dnsDomain;
		$this->primaryWINS = $primaryWINS;
		$this->secondaryWINS = $secondaryWINS;
		$this->netBIOS = $netBIOS;
	}
}

class CustomizationSpec extends phpDynamicProperties {
	public $options; //CustomizationOptions
	public $identity; //CustomizationIdentitySettings
	public $globalIPSettings; //CustomizationGlobalIPSettings
	public $nicSettingMap; //CustomizationAdapterMapping
	public $encryptionKey; //byte

	function __construct($options = null, $identity = null, $globalIPSettings = null, $nicSettingMap = null, $encryptionKey = null) {
		$this->options = $options;
		$this->identity = $identity;
		$this->globalIPSettings = $globalIPSettings;
		$this->nicSettingMap = $nicSettingMap;
		$this->encryptionKey = $encryptionKey;
	}
}

class CustomizationName extends phpDynamicProperties {
}

class CustomizationFixedName extends phpDynamicProperties {
	public $name; //string

	function __construct($name = null) {
		$this->name = $name;
	}
}

class CustomizationPrefixName extends phpDynamicProperties {
	public $base; //string

	function __construct($base = null) {
		$this->base = $base;
	}
}

class CustomizationVirtualMachineName extends phpDynamicProperties {
}

class CustomizationUnknownName extends phpDynamicProperties {
}

class CustomizationCustomName extends phpDynamicProperties {
	public $argument; //string

	function __construct($argument = null) {
		$this->argument = $argument;
	}
}

class CustomizationPassword extends phpDynamicProperties {
	public $value; //string
	public $plainText; //boolean

	function __construct($value = null, $plainText = null) {
		$this->value = $value;
		$this->plainText = $plainText;
	}
}

class CustomizationOptions extends phpDynamicProperties {
}

class CustomizationWinOptions extends phpDynamicProperties {
	public $changeSID; //boolean
	public $deleteAccounts; //boolean
	public $reboot; //CustomizationSysprepRebootOption

	function __construct($changeSID = null, $deleteAccounts = null, $reboot = null) {
		$this->changeSID = $changeSID;
		$this->deleteAccounts = $deleteAccounts;
		$this->reboot = $reboot;
	}
}

class CustomizationLinuxOptions extends phpDynamicProperties {
}

class CustomizationGuiUnattended extends phpDynamicProperties {
	public $password; //CustomizationPassword
	public $timeZone; //int
	public $autoLogon; //boolean
	public $autoLogonCount; //int

	function __construct($password = null, $timeZone = null, $autoLogon = null, $autoLogonCount = null) {
		$this->password = $password;
		$this->timeZone = $timeZone;
		$this->autoLogon = $autoLogon;
		$this->autoLogonCount = $autoLogonCount;
	}
}

class CustomizationUserData extends phpDynamicProperties {
	public $fullName; //string
	public $orgName; //string
	public $computerName; //CustomizationName
	public $productId; //string

	function __construct($fullName = null, $orgName = null, $computerName = null, $productId = null) {
		$this->fullName = $fullName;
		$this->orgName = $orgName;
		$this->computerName = $computerName;
		$this->productId = $productId;
	}
}

class CustomizationGuiRunOnce extends phpDynamicProperties {
	public $commandList; //string

	function __construct($commandList = null) {
		$this->commandList = $commandList;
	}
}

class CustomizationIdentification extends phpDynamicProperties {
	public $joinWorkgroup; //string
	public $joinDomain; //string
	public $domainAdmin; //string
	public $domainAdminPassword; //CustomizationPassword

	function __construct($joinWorkgroup = null, $joinDomain = null, $domainAdmin = null, $domainAdminPassword = null) {
		$this->joinWorkgroup = $joinWorkgroup;
		$this->joinDomain = $joinDomain;
		$this->domainAdmin = $domainAdmin;
		$this->domainAdminPassword = $domainAdminPassword;
	}
}

class CustomizationLicenseFilePrintData extends phpDynamicProperties {
	public $autoMode; //CustomizationLicenseDataMode
	public $autoUsers; //int

	function __construct($autoMode = null, $autoUsers = null) {
		$this->autoMode = $autoMode;
		$this->autoUsers = $autoUsers;
	}
}

class CustomizationIdentitySettings extends phpDynamicProperties {
}

class CustomizationSysprepText extends phpDynamicProperties {
	public $value; //string

	function __construct($value = null) {
		$this->value = $value;
	}
}

class CustomizationSysprep extends phpDynamicProperties {
	public $guiUnattended; //CustomizationGuiUnattended
	public $userData; //CustomizationUserData
	public $guiRunOnce; //CustomizationGuiRunOnce
	public $identification; //CustomizationIdentification
	public $licenseFilePrintData; //CustomizationLicenseFilePrintData

	function __construct($guiUnattended = null, $userData = null, $guiRunOnce = null, $identification = null, $licenseFilePrintData = null) {
		$this->guiUnattended = $guiUnattended;
		$this->userData = $userData;
		$this->guiRunOnce = $guiRunOnce;
		$this->identification = $identification;
		$this->licenseFilePrintData = $licenseFilePrintData;
	}
}

class CustomizationLinuxPrep extends phpDynamicProperties {
	public $hostName; //CustomizationName
	public $domain; //string
	public $timeZone; //string
	public $hwClockUTC; //boolean

	function __construct($hostName = null, $domain = null, $timeZone = null, $hwClockUTC = null) {
		$this->hostName = $hostName;
		$this->domain = $domain;
		$this->timeZone = $timeZone;
		$this->hwClockUTC = $hwClockUTC;
	}
}

class CustomizationGlobalIPSettings extends phpDynamicProperties {
	public $dnsSuffixList; //string
	public $dnsServerList; //string

	function __construct($dnsSuffixList = null, $dnsServerList = null) {
		$this->dnsSuffixList = $dnsSuffixList;
		$this->dnsServerList = $dnsServerList;
	}
}

class CustomizationIpGenerator extends phpDynamicProperties {
}

class CustomizationDhcpIpGenerator extends phpDynamicProperties {
}

class CustomizationFixedIp extends phpDynamicProperties {
	public $ipAddress; //string

	function __construct($ipAddress = null) {
		$this->ipAddress = $ipAddress;
	}
}

class CustomizationUnknownIpGenerator extends phpDynamicProperties {
}

class CustomizationCustomIpGenerator extends phpDynamicProperties {
	public $argument; //string

	function __construct($argument = null) {
		$this->argument = $argument;
	}
}

class CustomizationIpV6Generator extends phpDynamicProperties {
}

class ArrayOfCustomizationIpV6Generator extends phpDynamicProperties {
	public $CustomizationIpV6Generator; //CustomizationIpV6Generator

	function __construct($CustomizationIpV6Generator = null) {
		$this->CustomizationIpV6Generator = $CustomizationIpV6Generator;
	}
}

class CustomizationDhcpIpV6Generator extends phpDynamicProperties {
}

class CustomizationStatelessIpV6Generator extends phpDynamicProperties {
}

class CustomizationFixedIpV6 extends phpDynamicProperties {
	public $ipAddress; //string
	public $subnetMask; //int

	function __construct($ipAddress = null, $subnetMask = null) {
		$this->ipAddress = $ipAddress;
		$this->subnetMask = $subnetMask;
	}
}

class CustomizationAutoIpV6Generator extends phpDynamicProperties {
}

class CustomizationUnknownIpV6Generator extends phpDynamicProperties {
}

class CustomizationCustomIpV6Generator extends phpDynamicProperties {
	public $argument; //string

	function __construct($argument = null) {
		$this->argument = $argument;
	}
}

class CustomizationAdapterMapping extends phpDynamicProperties {
	public $macAddress; //string
	public $adapter; //CustomizationIPSettings

	function __construct($macAddress = null, $adapter = null) {
		$this->macAddress = $macAddress;
		$this->adapter = $adapter;
	}
}

class ArrayOfCustomizationAdapterMapping extends phpDynamicProperties {
	public $CustomizationAdapterMapping; //CustomizationAdapterMapping

	function __construct($CustomizationAdapterMapping = null) {
		$this->CustomizationAdapterMapping = $CustomizationAdapterMapping;
	}
}

class HostDiskMappingPartitionInfo extends phpDynamicProperties {
	public $name; //string
	public $fileSystem; //string
	public $capacityInKb; //long

	function __construct($name = null, $fileSystem = null, $capacityInKb = null) {
		$this->name = $name;
		$this->fileSystem = $fileSystem;
		$this->capacityInKb = $capacityInKb;
	}
}

class HostDiskMappingInfo extends phpDynamicProperties {
	public $physicalPartition; //HostDiskMappingPartitionInfo
	public $name; //string
	public $exclusive; //boolean

	function __construct($physicalPartition = null, $name = null, $exclusive = null) {
		$this->physicalPartition = $physicalPartition;
		$this->name = $name;
		$this->exclusive = $exclusive;
	}
}

class HostDiskMappingPartitionOption extends phpDynamicProperties {
	public $name; //string
	public $fileSystem; //string
	public $capacityInKb; //long

	function __construct($name = null, $fileSystem = null, $capacityInKb = null) {
		$this->name = $name;
		$this->fileSystem = $fileSystem;
		$this->capacityInKb = $capacityInKb;
	}
}

class ArrayOfHostDiskMappingPartitionOption extends phpDynamicProperties {
	public $HostDiskMappingPartitionOption; //HostDiskMappingPartitionOption

	function __construct($HostDiskMappingPartitionOption = null) {
		$this->HostDiskMappingPartitionOption = $HostDiskMappingPartitionOption;
	}
}

class HostDiskMappingOption extends phpDynamicProperties {
	public $physicalPartition; //HostDiskMappingPartitionOption
	public $name; //string

	function __construct($physicalPartition = null, $name = null) {
		$this->physicalPartition = $physicalPartition;
		$this->name = $name;
	}
}

class ParaVirtualSCSIController extends phpDynamicProperties {
}

class ParaVirtualSCSIControllerOption extends phpDynamicProperties {
}

class VirtualBusLogicController extends phpDynamicProperties {
}

class VirtualBusLogicControllerOption extends phpDynamicProperties {
}

class VirtualCdromIsoBackingInfo extends phpDynamicProperties {
}

class VirtualCdromPassthroughBackingInfo extends phpDynamicProperties {
	public $exclusive; //boolean

	function __construct($exclusive = null) {
		$this->exclusive = $exclusive;
	}
}

class VirtualCdromRemotePassthroughBackingInfo extends phpDynamicProperties {
	public $exclusive; //boolean

	function __construct($exclusive = null) {
		$this->exclusive = $exclusive;
	}
}

class VirtualCdromAtapiBackingInfo extends phpDynamicProperties {
}

class VirtualCdromRemoteAtapiBackingInfo extends phpDynamicProperties {
}

class VirtualCdrom extends phpDynamicProperties {
}

class VirtualCdromIsoBackingOption extends phpDynamicProperties {
}

class VirtualCdromPassthroughBackingOption extends phpDynamicProperties {
	public $exclusive; //BoolOption

	function __construct($exclusive = null) {
		$this->exclusive = $exclusive;
	}
}

class VirtualCdromRemotePassthroughBackingOption extends phpDynamicProperties {
	public $exclusive; //BoolOption

	function __construct($exclusive = null) {
		$this->exclusive = $exclusive;
	}
}

class VirtualCdromAtapiBackingOption extends phpDynamicProperties {
}

class VirtualCdromRemoteAtapiBackingOption extends phpDynamicProperties {
}

class VirtualCdromOption extends phpDynamicProperties {
}

class VirtualController extends phpDynamicProperties {
	public $busNumber; //int
	public $device; //int

	function __construct($busNumber = null, $device = null) {
		$this->busNumber = $busNumber;
		$this->device = $device;
	}
}

class VirtualControllerOption extends phpDynamicProperties {
	public $devices; //IntOption
	public $supportedDevice; //string

	function __construct($devices = null, $supportedDevice = null) {
		$this->devices = $devices;
		$this->supportedDevice = $supportedDevice;
	}
}

class VirtualDeviceBackingInfo extends phpDynamicProperties {
}

class VirtualDeviceFileBackingInfo extends phpDynamicProperties {
	public $fileName; //string
	public $datastore; //ManagedObjectReference

	function __construct($fileName = null, $datastore = null) {
		$this->fileName = $fileName;
		$this->datastore = $datastore;
	}
}

class VirtualDeviceDeviceBackingInfo extends phpDynamicProperties {
	public $deviceName; //string
	public $useAutoDetect; //boolean

	function __construct($deviceName = null, $useAutoDetect = null) {
		$this->deviceName = $deviceName;
		$this->useAutoDetect = $useAutoDetect;
	}
}

class VirtualDeviceRemoteDeviceBackingInfo extends phpDynamicProperties {
	public $deviceName; //string
	public $useAutoDetect; //boolean

	function __construct($deviceName = null, $useAutoDetect = null) {
		$this->deviceName = $deviceName;
		$this->useAutoDetect = $useAutoDetect;
	}
}

class VirtualDevicePipeBackingInfo extends phpDynamicProperties {
	public $pipeName; //string

	function __construct($pipeName = null) {
		$this->pipeName = $pipeName;
	}
}

class VirtualDeviceURIBackingInfo extends phpDynamicProperties {
	public $serviceURI; //string
	public $direction; //string
	public $proxyURI; //string

	function __construct($serviceURI = null, $direction = null, $proxyURI = null) {
		$this->serviceURI = $serviceURI;
		$this->direction = $direction;
		$this->proxyURI = $proxyURI;
	}
}

class VirtualDeviceConnectInfo extends phpDynamicProperties {
	public $startConnected; //boolean
	public $allowGuestControl; //boolean
	public $connected; //boolean
	public $status; //string

	function __construct($startConnected = null, $allowGuestControl = null, $connected = null, $status = null) {
		$this->startConnected = $startConnected;
		$this->allowGuestControl = $allowGuestControl;
		$this->connected = $connected;
		$this->status = $status;
	}
}

class VirtualDevice extends phpDynamicProperties {
	public $key; //int
	public $deviceInfo; //Description
	public $backing; //VirtualDeviceBackingInfo
	public $connectable; //VirtualDeviceConnectInfo
	public $controllerKey; //int
	public $unitNumber; //int

	function __construct($key = null, $deviceInfo = null, $backing = null, $connectable = null, $controllerKey = null, $unitNumber = null) {
		$this->key = $key;
		$this->deviceInfo = $deviceInfo;
		$this->backing = $backing;
		$this->connectable = $connectable;
		$this->controllerKey = $controllerKey;
		$this->unitNumber = $unitNumber;
	}
}

class ArrayOfVirtualDevice extends phpDynamicProperties {
	public $VirtualDevice; //VirtualDevice

	function __construct($VirtualDevice = null) {
		$this->VirtualDevice = $VirtualDevice;
	}
}

class VirtualDeviceBackingOption extends phpDynamicProperties {
	public $type; //string

	function __construct($type = null) {
		$this->type = $type;
	}
}

class ArrayOfVirtualDeviceBackingOption extends phpDynamicProperties {
	public $VirtualDeviceBackingOption; //VirtualDeviceBackingOption

	function __construct($VirtualDeviceBackingOption = null) {
		$this->VirtualDeviceBackingOption = $VirtualDeviceBackingOption;
	}
}

class VirtualDeviceFileBackingOption extends phpDynamicProperties {
	public $fileNameExtensions; //ChoiceOption

	function __construct($fileNameExtensions = null) {
		$this->fileNameExtensions = $fileNameExtensions;
	}
}

class VirtualDeviceDeviceBackingOption extends phpDynamicProperties {
	public $autoDetectAvailable; //BoolOption

	function __construct($autoDetectAvailable = null) {
		$this->autoDetectAvailable = $autoDetectAvailable;
	}
}

class VirtualDeviceRemoteDeviceBackingOption extends phpDynamicProperties {
	public $autoDetectAvailable; //BoolOption

	function __construct($autoDetectAvailable = null) {
		$this->autoDetectAvailable = $autoDetectAvailable;
	}
}

class VirtualDevicePipeBackingOption extends phpDynamicProperties {
}

class VirtualDeviceURIBackingOption extends phpDynamicProperties {
	public $directions; //ChoiceOption

	function __construct($directions = null) {
		$this->directions = $directions;
	}
}

class VirtualDeviceConnectOption extends phpDynamicProperties {
	public $startConnected; //BoolOption
	public $allowGuestControl; //BoolOption

	function __construct($startConnected = null, $allowGuestControl = null) {
		$this->startConnected = $startConnected;
		$this->allowGuestControl = $allowGuestControl;
	}
}

class VirtualDeviceOption extends phpDynamicProperties {
	public $type; //string
	public $connectOption; //VirtualDeviceConnectOption
	public $controllerType; //string
	public $autoAssignController; //BoolOption
	public $backingOption; //VirtualDeviceBackingOption
	public $defaultBackingOptionIndex; //int
	public $licensingLimit; //string
	public $deprecated; //boolean
	public $plugAndPlay; //boolean
	public $hotRemoveSupported; //boolean

	function __construct($type = null, $connectOption = null, $controllerType = null, $autoAssignController = null, $backingOption = null, $defaultBackingOptionIndex = null, $licensingLimit = null, $deprecated = null, $plugAndPlay = null, $hotRemoveSupported = null) {
		$this->type = $type;
		$this->connectOption = $connectOption;
		$this->controllerType = $controllerType;
		$this->autoAssignController = $autoAssignController;
		$this->backingOption = $backingOption;
		$this->defaultBackingOptionIndex = $defaultBackingOptionIndex;
		$this->licensingLimit = $licensingLimit;
		$this->deprecated = $deprecated;
		$this->plugAndPlay = $plugAndPlay;
		$this->hotRemoveSupported = $hotRemoveSupported;
	}
}

class ArrayOfVirtualDeviceOption extends phpDynamicProperties {
	public $VirtualDeviceOption; //VirtualDeviceOption

	function __construct($VirtualDeviceOption = null) {
		$this->VirtualDeviceOption = $VirtualDeviceOption;
	}
}

class VirtualDeviceConfigSpec extends phpDynamicProperties {
	public $operation; //VirtualDeviceConfigSpecOperation
	public $fileOperation; //VirtualDeviceConfigSpecFileOperation
	public $device; //VirtualDevice

	function __construct($operation = null, $fileOperation = null, $device = null) {
		$this->operation = $operation;
		$this->fileOperation = $fileOperation;
		$this->device = $device;
	}
}

class ArrayOfVirtualDeviceConfigSpec extends phpDynamicProperties {
	public $VirtualDeviceConfigSpec; //VirtualDeviceConfigSpec

	function __construct($VirtualDeviceConfigSpec = null) {
		$this->VirtualDeviceConfigSpec = $VirtualDeviceConfigSpec;
	}
}

class VirtualDiskSparseVer1BackingInfo extends phpDynamicProperties {
	public $diskMode; //string
	public $split; //boolean
	public $writeThrough; //boolean
	public $spaceUsedInKB; //long
	public $contentId; //string
	public $parent; //VirtualDiskSparseVer1BackingInfo

	function __construct($diskMode = null, $split = null, $writeThrough = null, $spaceUsedInKB = null, $contentId = null, $parent = null) {
		$this->diskMode = $diskMode;
		$this->split = $split;
		$this->writeThrough = $writeThrough;
		$this->spaceUsedInKB = $spaceUsedInKB;
		$this->contentId = $contentId;
		$this->parent = $parent;
	}
}

class VirtualDiskSparseVer2BackingInfo extends phpDynamicProperties {
	public $diskMode; //string
	public $split; //boolean
	public $writeThrough; //boolean
	public $spaceUsedInKB; //long
	public $uuid; //string
	public $contentId; //string
	public $changeId; //string
	public $parent; //VirtualDiskSparseVer2BackingInfo

	function __construct($diskMode = null, $split = null, $writeThrough = null, $spaceUsedInKB = null, $uuid = null, $contentId = null, $changeId = null, $parent = null) {
		$this->diskMode = $diskMode;
		$this->split = $split;
		$this->writeThrough = $writeThrough;
		$this->spaceUsedInKB = $spaceUsedInKB;
		$this->uuid = $uuid;
		$this->contentId = $contentId;
		$this->changeId = $changeId;
		$this->parent = $parent;
	}
}

class VirtualDiskFlatVer1BackingInfo extends phpDynamicProperties {
	public $diskMode; //string
	public $split; //boolean
	public $writeThrough; //boolean
	public $contentId; //string
	public $parent; //VirtualDiskFlatVer1BackingInfo

	function __construct($diskMode = null, $split = null, $writeThrough = null, $contentId = null, $parent = null) {
		$this->diskMode = $diskMode;
		$this->split = $split;
		$this->writeThrough = $writeThrough;
		$this->contentId = $contentId;
		$this->parent = $parent;
	}
}

class VirtualDiskFlatVer2BackingInfo extends phpDynamicProperties {
	public $diskMode; //string
	public $split; //boolean
	public $writeThrough; //boolean
	public $thinProvisioned; //boolean
	public $eagerlyScrub; //boolean
	public $uuid; //string
	public $contentId; //string
	public $changeId; //string
	public $parent; //VirtualDiskFlatVer2BackingInfo
	public $deltaDiskFormat; //string
	public $digestEnabled; //boolean

	function __construct($diskMode = null, $split = null, $writeThrough = null, $thinProvisioned = null, $eagerlyScrub = null, $uuid = null, $contentId = null, $changeId = null, $parent = null, $deltaDiskFormat = null, $digestEnabled = null) {
		$this->diskMode = $diskMode;
		$this->split = $split;
		$this->writeThrough = $writeThrough;
		$this->thinProvisioned = $thinProvisioned;
		$this->eagerlyScrub = $eagerlyScrub;
		$this->uuid = $uuid;
		$this->contentId = $contentId;
		$this->changeId = $changeId;
		$this->parent = $parent;
		$this->deltaDiskFormat = $deltaDiskFormat;
		$this->digestEnabled = $digestEnabled;
	}
}

class VirtualDiskRawDiskVer2BackingInfo extends phpDynamicProperties {
	public $descriptorFileName; //string
	public $uuid; //string
	public $changeId; //string

	function __construct($descriptorFileName = null, $uuid = null, $changeId = null) {
		$this->descriptorFileName = $descriptorFileName;
		$this->uuid = $uuid;
		$this->changeId = $changeId;
	}
}

class VirtualDiskPartitionedRawDiskVer2BackingInfo extends phpDynamicProperties {
	public $partition; //int

	function __construct($partition = null) {
		$this->partition = $partition;
	}
}

class VirtualDiskRawDiskMappingVer1BackingInfo extends phpDynamicProperties {
	public $lunUuid; //string
	public $deviceName; //string
	public $compatibilityMode; //string
	public $diskMode; //string
	public $uuid; //string
	public $contentId; //string
	public $changeId; //string
	public $parent; //VirtualDiskRawDiskMappingVer1BackingInfo

	function __construct($lunUuid = null, $deviceName = null, $compatibilityMode = null, $diskMode = null, $uuid = null, $contentId = null, $changeId = null, $parent = null) {
		$this->lunUuid = $lunUuid;
		$this->deviceName = $deviceName;
		$this->compatibilityMode = $compatibilityMode;
		$this->diskMode = $diskMode;
		$this->uuid = $uuid;
		$this->contentId = $contentId;
		$this->changeId = $changeId;
		$this->parent = $parent;
	}
}

class VirtualDisk extends phpDynamicProperties {
	public $capacityInKB; //long
	public $shares; //SharesInfo
	public $storageIOAllocation; //StorageIOAllocationInfo

	function __construct($capacityInKB = null, $shares = null, $storageIOAllocation = null) {
		$this->capacityInKB = $capacityInKB;
		$this->shares = $shares;
		$this->storageIOAllocation = $storageIOAllocation;
	}
}

class ArrayOfVirtualDisk extends phpDynamicProperties {
	public $VirtualDisk; //VirtualDisk

	function __construct($VirtualDisk = null) {
		$this->VirtualDisk = $VirtualDisk;
	}
}

class VirtualDiskId extends phpDynamicProperties {
	public $vm; //ManagedObjectReference
	public $diskId; //int

	function __construct($vm = null, $diskId = null) {
		$this->vm = $vm;
		$this->diskId = $diskId;
	}
}

class VirtualDiskSparseVer1BackingOption extends phpDynamicProperties {
	public $diskModes; //ChoiceOption
	public $split; //BoolOption
	public $writeThrough; //BoolOption
	public $growable; //boolean

	function __construct($diskModes = null, $split = null, $writeThrough = null, $growable = null) {
		$this->diskModes = $diskModes;
		$this->split = $split;
		$this->writeThrough = $writeThrough;
		$this->growable = $growable;
	}
}

class VirtualDiskSparseVer2BackingOption extends phpDynamicProperties {
	public $diskMode; //ChoiceOption
	public $split; //BoolOption
	public $writeThrough; //BoolOption
	public $growable; //boolean
	public $hotGrowable; //boolean
	public $uuid; //boolean

	function __construct($diskMode = null, $split = null, $writeThrough = null, $growable = null, $hotGrowable = null, $uuid = null) {
		$this->diskMode = $diskMode;
		$this->split = $split;
		$this->writeThrough = $writeThrough;
		$this->growable = $growable;
		$this->hotGrowable = $hotGrowable;
		$this->uuid = $uuid;
	}
}

class VirtualDiskFlatVer1BackingOption extends phpDynamicProperties {
	public $diskMode; //ChoiceOption
	public $split; //BoolOption
	public $writeThrough; //BoolOption
	public $growable; //boolean

	function __construct($diskMode = null, $split = null, $writeThrough = null, $growable = null) {
		$this->diskMode = $diskMode;
		$this->split = $split;
		$this->writeThrough = $writeThrough;
		$this->growable = $growable;
	}
}

class VirtualDiskFlatVer2BackingOption extends phpDynamicProperties {
	public $diskMode; //ChoiceOption
	public $split; //BoolOption
	public $writeThrough; //BoolOption
	public $growable; //boolean
	public $hotGrowable; //boolean
	public $uuid; //boolean
	public $thinProvisioned; //BoolOption
	public $eagerlyScrub; //BoolOption
	public $deltaDiskFormat; //ChoiceOption

	function __construct($diskMode = null, $split = null, $writeThrough = null, $growable = null, $hotGrowable = null, $uuid = null, $thinProvisioned = null, $eagerlyScrub = null, $deltaDiskFormat = null) {
		$this->diskMode = $diskMode;
		$this->split = $split;
		$this->writeThrough = $writeThrough;
		$this->growable = $growable;
		$this->hotGrowable = $hotGrowable;
		$this->uuid = $uuid;
		$this->thinProvisioned = $thinProvisioned;
		$this->eagerlyScrub = $eagerlyScrub;
		$this->deltaDiskFormat = $deltaDiskFormat;
	}
}

class VirtualDiskRawDiskVer2BackingOption extends phpDynamicProperties {
	public $descriptorFileNameExtensions; //ChoiceOption
	public $uuid; //boolean

	function __construct($descriptorFileNameExtensions = null, $uuid = null) {
		$this->descriptorFileNameExtensions = $descriptorFileNameExtensions;
		$this->uuid = $uuid;
	}
}

class VirtualDiskPartitionedRawDiskVer2BackingOption extends phpDynamicProperties {
}

class VirtualDiskRawDiskMappingVer1BackingOption extends phpDynamicProperties {
	public $descriptorFileNameExtensions; //ChoiceOption
	public $compatibilityMode; //ChoiceOption
	public $diskMode; //ChoiceOption
	public $uuid; //boolean

	function __construct($descriptorFileNameExtensions = null, $compatibilityMode = null, $diskMode = null, $uuid = null) {
		$this->descriptorFileNameExtensions = $descriptorFileNameExtensions;
		$this->compatibilityMode = $compatibilityMode;
		$this->diskMode = $diskMode;
		$this->uuid = $uuid;
	}
}

class VirtualDiskOption extends phpDynamicProperties {
	public $capacityInKB; //LongOption
	public $ioAllocationOption; //StorageIOAllocationOption

	function __construct($capacityInKB = null, $ioAllocationOption = null) {
		$this->capacityInKB = $capacityInKB;
		$this->ioAllocationOption = $ioAllocationOption;
	}
}

class VirtualE1000 extends phpDynamicProperties {
}

class VirtualE1000Option extends phpDynamicProperties {
}

class VirtualE1000e extends phpDynamicProperties {
}

class VirtualE1000eOption extends phpDynamicProperties {
}

class VirtualEnsoniq1371 extends phpDynamicProperties {
}

class VirtualEnsoniq1371Option extends phpDynamicProperties {
}

class VirtualEthernetCardNetworkBackingInfo extends phpDynamicProperties {
	public $network; //ManagedObjectReference
	public $inPassthroughMode; //boolean

	function __construct($network = null, $inPassthroughMode = null) {
		$this->network = $network;
		$this->inPassthroughMode = $inPassthroughMode;
	}
}

class VirtualEthernetCardLegacyNetworkBackingInfo extends phpDynamicProperties {
}

class VirtualEthernetCardDistributedVirtualPortBackingInfo extends phpDynamicProperties {
	public $port; //DistributedVirtualSwitchPortConnection

	function __construct($port = null) {
		$this->port = $port;
	}
}

class VirtualEthernetCard extends phpDynamicProperties {
	public $addressType; //string
	public $macAddress; //string
	public $wakeOnLanEnabled; //boolean

	function __construct($addressType = null, $macAddress = null, $wakeOnLanEnabled = null) {
		$this->addressType = $addressType;
		$this->macAddress = $macAddress;
		$this->wakeOnLanEnabled = $wakeOnLanEnabled;
	}
}

class VirtualEthernetCardNetworkBackingOption extends phpDynamicProperties {
}

class VirtualEthernetCardLegacyNetworkBackingOption extends phpDynamicProperties {
}

class VirtualEthernetCardDVPortBackingOption extends phpDynamicProperties {
}

class VirtualEthernetCardOption extends phpDynamicProperties {
	public $supportedOUI; //ChoiceOption
	public $macType; //ChoiceOption
	public $wakeOnLanEnabled; //BoolOption
	public $vmDirectPathGen2Supported; //boolean

	function __construct($supportedOUI = null, $macType = null, $wakeOnLanEnabled = null, $vmDirectPathGen2Supported = null) {
		$this->supportedOUI = $supportedOUI;
		$this->macType = $macType;
		$this->wakeOnLanEnabled = $wakeOnLanEnabled;
		$this->vmDirectPathGen2Supported = $vmDirectPathGen2Supported;
	}
}

class VirtualFloppyImageBackingInfo extends phpDynamicProperties {
}

class VirtualFloppyDeviceBackingInfo extends phpDynamicProperties {
}

class VirtualFloppyRemoteDeviceBackingInfo extends phpDynamicProperties {
}

class VirtualFloppy extends phpDynamicProperties {
}

class VirtualFloppyImageBackingOption extends phpDynamicProperties {
}

class VirtualFloppyDeviceBackingOption extends phpDynamicProperties {
}

class VirtualFloppyRemoteDeviceBackingOption extends phpDynamicProperties {
}

class VirtualFloppyOption extends phpDynamicProperties {
}

class VirtualHdAudioCard extends phpDynamicProperties {
}

class VirtualHdAudioCardOption extends phpDynamicProperties {
}

class VirtualIDEController extends phpDynamicProperties {
}

class VirtualIDEControllerOption extends phpDynamicProperties {
	public $numIDEDisks; //IntOption
	public $numIDECdroms; //IntOption

	function __construct($numIDEDisks = null, $numIDECdroms = null) {
		$this->numIDEDisks = $numIDEDisks;
		$this->numIDECdroms = $numIDECdroms;
	}
}

class VirtualKeyboard extends phpDynamicProperties {
}

class VirtualKeyboardOption extends phpDynamicProperties {
}

class VirtualLsiLogicController extends phpDynamicProperties {
}

class VirtualLsiLogicControllerOption extends phpDynamicProperties {
}

class VirtualLsiLogicSASController extends phpDynamicProperties {
}

class VirtualLsiLogicSASControllerOption extends phpDynamicProperties {
}

class VirtualPCIController extends phpDynamicProperties {
}

class VirtualPCIControllerOption extends phpDynamicProperties {
	public $numSCSIControllers; //IntOption
	public $numEthernetCards; //IntOption
	public $numVideoCards; //IntOption
	public $numSoundCards; //IntOption
	public $numVmiRoms; //IntOption
	public $numVmciDevices; //IntOption
	public $numPCIPassthroughDevices; //IntOption
	public $numSasSCSIControllers; //IntOption
	public $numVmxnet3EthernetCards; //IntOption
	public $numParaVirtualSCSIControllers; //IntOption

	function __construct($numSCSIControllers = null, $numEthernetCards = null, $numVideoCards = null, $numSoundCards = null, $numVmiRoms = null, $numVmciDevices = null, $numPCIPassthroughDevices = null, $numSasSCSIControllers = null, $numVmxnet3EthernetCards = null, $numParaVirtualSCSIControllers = null) {
		$this->numSCSIControllers = $numSCSIControllers;
		$this->numEthernetCards = $numEthernetCards;
		$this->numVideoCards = $numVideoCards;
		$this->numSoundCards = $numSoundCards;
		$this->numVmiRoms = $numVmiRoms;
		$this->numVmciDevices = $numVmciDevices;
		$this->numPCIPassthroughDevices = $numPCIPassthroughDevices;
		$this->numSasSCSIControllers = $numSasSCSIControllers;
		$this->numVmxnet3EthernetCards = $numVmxnet3EthernetCards;
		$this->numParaVirtualSCSIControllers = $numParaVirtualSCSIControllers;
	}
}

class VirtualPCIPassthroughDeviceBackingInfo extends phpDynamicProperties {
	public $id; //string
	public $deviceId; //string
	public $systemId; //string
	public $vendorId; //short

	function __construct($id = null, $deviceId = null, $systemId = null, $vendorId = null) {
		$this->id = $id;
		$this->deviceId = $deviceId;
		$this->systemId = $systemId;
		$this->vendorId = $vendorId;
	}
}

class VirtualPCIPassthrough extends phpDynamicProperties {
}

class VirtualPCIPassthroughDeviceBackingOption extends phpDynamicProperties {
}

class VirtualPCIPassthroughOption extends phpDynamicProperties {
}

class VirtualPCNet32 extends phpDynamicProperties {
}

class VirtualPCNet32Option extends phpDynamicProperties {
	public $supportsMorphing; //boolean

	function __construct($supportsMorphing = null) {
		$this->supportsMorphing = $supportsMorphing;
	}
}

class VirtualPS2Controller extends phpDynamicProperties {
}

class VirtualPS2ControllerOption extends phpDynamicProperties {
	public $numKeyboards; //IntOption
	public $numPointingDevices; //IntOption

	function __construct($numKeyboards = null, $numPointingDevices = null) {
		$this->numKeyboards = $numKeyboards;
		$this->numPointingDevices = $numPointingDevices;
	}
}

class VirtualParallelPortFileBackingInfo extends phpDynamicProperties {
}

class VirtualParallelPortDeviceBackingInfo extends phpDynamicProperties {
}

class VirtualParallelPort extends phpDynamicProperties {
}

class VirtualParallelPortFileBackingOption extends phpDynamicProperties {
}

class VirtualParallelPortDeviceBackingOption extends phpDynamicProperties {
}

class VirtualParallelPortOption extends phpDynamicProperties {
}

class VirtualPointingDeviceDeviceBackingInfo extends phpDynamicProperties {
	public $hostPointingDevice; //string

	function __construct($hostPointingDevice = null) {
		$this->hostPointingDevice = $hostPointingDevice;
	}
}

class VirtualPointingDevice extends phpDynamicProperties {
}

class VirtualPointingDeviceBackingOption extends phpDynamicProperties {
	public $hostPointingDevice; //ChoiceOption

	function __construct($hostPointingDevice = null) {
		$this->hostPointingDevice = $hostPointingDevice;
	}
}

class VirtualPointingDeviceOption extends phpDynamicProperties {
}

class ArrayOfVirtualSCSISharing extends phpDynamicProperties {
	public $VirtualSCSISharing; //VirtualSCSISharing

	function __construct($VirtualSCSISharing = null) {
		$this->VirtualSCSISharing = $VirtualSCSISharing;
	}
}

class VirtualSCSIController extends phpDynamicProperties {
	public $hotAddRemove; //boolean
	public $sharedBus; //VirtualSCSISharing
	public $scsiCtlrUnitNumber; //int

	function __construct($hotAddRemove = null, $sharedBus = null, $scsiCtlrUnitNumber = null) {
		$this->hotAddRemove = $hotAddRemove;
		$this->sharedBus = $sharedBus;
		$this->scsiCtlrUnitNumber = $scsiCtlrUnitNumber;
	}
}

class VirtualSCSIControllerOption extends phpDynamicProperties {
	public $numSCSIDisks; //IntOption
	public $numSCSICdroms; //IntOption
	public $numSCSIPassthrough; //IntOption
	public $sharing; //VirtualSCSISharing
	public $defaultSharedIndex; //int
	public $hotAddRemove; //BoolOption
	public $scsiCtlrUnitNumber; //int

	function __construct($numSCSIDisks = null, $numSCSICdroms = null, $numSCSIPassthrough = null, $sharing = null, $defaultSharedIndex = null, $hotAddRemove = null, $scsiCtlrUnitNumber = null) {
		$this->numSCSIDisks = $numSCSIDisks;
		$this->numSCSICdroms = $numSCSICdroms;
		$this->numSCSIPassthrough = $numSCSIPassthrough;
		$this->sharing = $sharing;
		$this->defaultSharedIndex = $defaultSharedIndex;
		$this->hotAddRemove = $hotAddRemove;
		$this->scsiCtlrUnitNumber = $scsiCtlrUnitNumber;
	}
}

class VirtualSCSIPassthroughDeviceBackingInfo extends phpDynamicProperties {
}

class VirtualSCSIPassthrough extends phpDynamicProperties {
}

class VirtualSCSIPassthroughDeviceBackingOption extends phpDynamicProperties {
}

class VirtualSCSIPassthroughOption extends phpDynamicProperties {
}

class VirtualSIOController extends phpDynamicProperties {
}

class VirtualSIOControllerOption extends phpDynamicProperties {
	public $numFloppyDrives; //IntOption
	public $numSerialPorts; //IntOption
	public $numParallelPorts; //IntOption

	function __construct($numFloppyDrives = null, $numSerialPorts = null, $numParallelPorts = null) {
		$this->numFloppyDrives = $numFloppyDrives;
		$this->numSerialPorts = $numSerialPorts;
		$this->numParallelPorts = $numParallelPorts;
	}
}

class VirtualSerialPortFileBackingInfo extends phpDynamicProperties {
}

class VirtualSerialPortDeviceBackingInfo extends phpDynamicProperties {
}

class VirtualSerialPortPipeBackingInfo extends phpDynamicProperties {
	public $endpoint; //string
	public $noRxLoss; //boolean

	function __construct($endpoint = null, $noRxLoss = null) {
		$this->endpoint = $endpoint;
		$this->noRxLoss = $noRxLoss;
	}
}

class VirtualSerialPortURIBackingInfo extends phpDynamicProperties {
}

class VirtualSerialPort extends phpDynamicProperties {
	public $yieldOnPoll; //boolean

	function __construct($yieldOnPoll = null) {
		$this->yieldOnPoll = $yieldOnPoll;
	}
}

class VirtualSerialPortFileBackingOption extends phpDynamicProperties {
}

class VirtualSerialPortDeviceBackingOption extends phpDynamicProperties {
}

class VirtualSerialPortPipeBackingOption extends phpDynamicProperties {
	public $endpoint; //ChoiceOption
	public $noRxLoss; //BoolOption

	function __construct($endpoint = null, $noRxLoss = null) {
		$this->endpoint = $endpoint;
		$this->noRxLoss = $noRxLoss;
	}
}

class VirtualSerialPortURIBackingOption extends phpDynamicProperties {
}

class VirtualSerialPortOption extends phpDynamicProperties {
	public $yieldOnPoll; //BoolOption

	function __construct($yieldOnPoll = null) {
		$this->yieldOnPoll = $yieldOnPoll;
	}
}

class VirtualSoundBlaster16 extends phpDynamicProperties {
}

class VirtualSoundBlaster16Option extends phpDynamicProperties {
}

class VirtualSoundCardDeviceBackingInfo extends phpDynamicProperties {
}

class VirtualSoundCard extends phpDynamicProperties {
}

class VirtualSoundCardDeviceBackingOption extends phpDynamicProperties {
}

class VirtualSoundCardOption extends phpDynamicProperties {
}

class VirtualUSBUSBBackingInfo extends phpDynamicProperties {
}

class VirtualUSBRemoteHostBackingInfo extends phpDynamicProperties {
	public $hostname; //string

	function __construct($hostname = null) {
		$this->hostname = $hostname;
	}
}

class VirtualUSBRemoteClientBackingInfo extends phpDynamicProperties {
	public $hostname; //string

	function __construct($hostname = null) {
		$this->hostname = $hostname;
	}
}

class VirtualUSB extends phpDynamicProperties {
	public $connected; //boolean
	public $vendor; //int
	public $product; //int
	public $family; //string
	public $speed; //string

	function __construct($connected = null, $vendor = null, $product = null, $family = null, $speed = null) {
		$this->connected = $connected;
		$this->vendor = $vendor;
		$this->product = $product;
		$this->family = $family;
		$this->speed = $speed;
	}
}

class VirtualUSBController extends phpDynamicProperties {
	public $autoConnectDevices; //boolean
	public $ehciEnabled; //boolean

	function __construct($autoConnectDevices = null, $ehciEnabled = null) {
		$this->autoConnectDevices = $autoConnectDevices;
		$this->ehciEnabled = $ehciEnabled;
	}
}

class VirtualUSBControllerOption extends phpDynamicProperties {
	public $autoConnectDevices; //BoolOption
	public $ehciSupported; //BoolOption
	public $supportedSpeeds; //string

	function __construct($autoConnectDevices = null, $ehciSupported = null, $supportedSpeeds = null) {
		$this->autoConnectDevices = $autoConnectDevices;
		$this->ehciSupported = $ehciSupported;
		$this->supportedSpeeds = $supportedSpeeds;
	}
}

class VirtualUSBUSBBackingOption extends phpDynamicProperties {
}

class VirtualUSBRemoteHostBackingOption extends phpDynamicProperties {
}

class VirtualUSBRemoteClientBackingOption extends phpDynamicProperties {
}

class VirtualUSBOption extends phpDynamicProperties {
}

class VirtualUSBXHCIController extends phpDynamicProperties {
	public $autoConnectDevices; //boolean

	function __construct($autoConnectDevices = null) {
		$this->autoConnectDevices = $autoConnectDevices;
	}
}

class VirtualUSBXHCIControllerOption extends phpDynamicProperties {
	public $autoConnectDevices; //BoolOption
	public $supportedSpeeds; //string

	function __construct($autoConnectDevices = null, $supportedSpeeds = null) {
		$this->autoConnectDevices = $autoConnectDevices;
		$this->supportedSpeeds = $supportedSpeeds;
	}
}

class VirtualMachineVMCIDevice extends phpDynamicProperties {
	public $id; //long
	public $allowUnrestrictedCommunication; //boolean

	function __construct($id = null, $allowUnrestrictedCommunication = null) {
		$this->id = $id;
		$this->allowUnrestrictedCommunication = $allowUnrestrictedCommunication;
	}
}

class VirtualMachineVMCIDeviceOption extends phpDynamicProperties {
	public $allowUnrestrictedCommunication; //BoolOption

	function __construct($allowUnrestrictedCommunication = null) {
		$this->allowUnrestrictedCommunication = $allowUnrestrictedCommunication;
	}
}

class VirtualMachineVMIROM extends phpDynamicProperties {
}

class VirtualVMIROMOption extends phpDynamicProperties {
}

class VirtualMachineVideoCard extends phpDynamicProperties {
	public $videoRamSizeInKB; //long
	public $numDisplays; //int
	public $useAutoDetect; //boolean
	public $enable3DSupport; //boolean

	function __construct($videoRamSizeInKB = null, $numDisplays = null, $useAutoDetect = null, $enable3DSupport = null) {
		$this->videoRamSizeInKB = $videoRamSizeInKB;
		$this->numDisplays = $numDisplays;
		$this->useAutoDetect = $useAutoDetect;
		$this->enable3DSupport = $enable3DSupport;
	}
}

class VirtualVideoCardOption extends phpDynamicProperties {
	public $videoRamSizeInKB; //LongOption
	public $numDisplays; //IntOption
	public $useAutoDetect; //BoolOption
	public $support3D; //BoolOption

	function __construct($videoRamSizeInKB = null, $numDisplays = null, $useAutoDetect = null, $support3D = null) {
		$this->videoRamSizeInKB = $videoRamSizeInKB;
		$this->numDisplays = $numDisplays;
		$this->useAutoDetect = $useAutoDetect;
		$this->support3D = $support3D;
	}
}

class VirtualVmxnet extends phpDynamicProperties {
}

class VirtualVmxnet2 extends phpDynamicProperties {
}

class VirtualVmxnet2Option extends phpDynamicProperties {
}

class VirtualVmxnet3 extends phpDynamicProperties {
}

class VirtualVmxnet3Option extends phpDynamicProperties {
}

class VirtualVmxnetOption extends phpDynamicProperties {
}

class GuestFileAttributes extends phpDynamicProperties {
	public $modificationTime; //dateTime
	public $accessTime; //dateTime
	public $symlinkTarget; //string

	function __construct($modificationTime = null, $accessTime = null, $symlinkTarget = null) {
		$this->modificationTime = $modificationTime;
		$this->accessTime = $accessTime;
		$this->symlinkTarget = $symlinkTarget;
	}
}

class GuestPosixFileAttributes extends phpDynamicProperties {
	public $ownerId; //int
	public $groupId; //int
	public $permissions; //long

	function __construct($ownerId = null, $groupId = null, $permissions = null) {
		$this->ownerId = $ownerId;
		$this->groupId = $groupId;
		$this->permissions = $permissions;
	}
}

class GuestWindowsFileAttributes extends phpDynamicProperties {
	public $hidden; //boolean
	public $readOnly; //boolean
	public $createTime; //dateTime

	function __construct($hidden = null, $readOnly = null, $createTime = null) {
		$this->hidden = $hidden;
		$this->readOnly = $readOnly;
		$this->createTime = $createTime;
	}
}

class GuestFileInfo extends phpDynamicProperties {
	public $path; //string
	public $type; //string
	public $size; //long
	public $attributes; //GuestFileAttributes

	function __construct($path = null, $type = null, $size = null, $attributes = null) {
		$this->path = $path;
		$this->type = $type;
		$this->size = $size;
		$this->attributes = $attributes;
	}
}

class ArrayOfGuestFileInfo extends phpDynamicProperties {
	public $GuestFileInfo; //GuestFileInfo

	function __construct($GuestFileInfo = null) {
		$this->GuestFileInfo = $GuestFileInfo;
	}
}

class GuestListFileInfo extends phpDynamicProperties {
	public $files; //GuestFileInfo
	public $remaining; //int

	function __construct($files = null, $remaining = null) {
		$this->files = $files;
		$this->remaining = $remaining;
	}
}

class FileTransferInformation extends phpDynamicProperties {
	public $attributes; //GuestFileAttributes
	public $size; //long
	public $url; //string

	function __construct($attributes = null, $size = null, $url = null) {
		$this->attributes = $attributes;
		$this->size = $size;
		$this->url = $url;
	}
}

class GuestAuthentication extends phpDynamicProperties {
	public $interactiveSession; //boolean

	function __construct($interactiveSession = null) {
		$this->interactiveSession = $interactiveSession;
	}
}

class NamePasswordAuthentication extends phpDynamicProperties {
	public $username; //string
	public $password; //string

	function __construct($username = null, $password = null) {
		$this->username = $username;
		$this->password = $password;
	}
}

class GuestProgramSpec extends phpDynamicProperties {
	public $programPath; //string
	public $arguments; //string
	public $workingDirectory; //string
	public $envVariables; //string

	function __construct($programPath = null, $arguments = null, $workingDirectory = null, $envVariables = null) {
		$this->programPath = $programPath;
		$this->arguments = $arguments;
		$this->workingDirectory = $workingDirectory;
		$this->envVariables = $envVariables;
	}
}

class GuestWindowsProgramSpec extends phpDynamicProperties {
	public $startMinimized; //boolean

	function __construct($startMinimized = null) {
		$this->startMinimized = $startMinimized;
	}
}

class GuestProcessInfo extends phpDynamicProperties {
	public $name; //string
	public $pid; //long
	public $owner; //string
	public $cmdLine; //string
	public $startTime; //dateTime
	public $endTime; //dateTime
	public $exitCode; //int

	function __construct($name = null, $pid = null, $owner = null, $cmdLine = null, $startTime = null, $endTime = null, $exitCode = null) {
		$this->name = $name;
		$this->pid = $pid;
		$this->owner = $owner;
		$this->cmdLine = $cmdLine;
		$this->startTime = $startTime;
		$this->endTime = $endTime;
		$this->exitCode = $exitCode;
	}
}

class ArrayOfGuestProcessInfo extends phpDynamicProperties {
	public $GuestProcessInfo; //GuestProcessInfo

	function __construct($GuestProcessInfo = null) {
		$this->GuestProcessInfo = $GuestProcessInfo;
	}
}

class SSPIAuthentication extends phpDynamicProperties {
	public $sspiToken; //string

	function __construct($sspiToken = null) {
		$this->sspiToken = $sspiToken;
	}
}

class TicketedSessionAuthentication extends phpDynamicProperties {
	public $ticket; //string

	function __construct($ticket = null) {
		$this->ticket = $ticket;
	}
}

class AddAuthorizationRoleRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $name; //string
	public $privIds; //string

	function __construct($_this = null, $name = null, $privIds = null) {
		$this->_this = $_this;
		$this->name = $name;
		$this->privIds = $privIds;
	}
}

class RemoveAuthorizationRoleRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $roleId; //int
	public $failIfUsed; //boolean

	function __construct($_this = null, $roleId = null, $failIfUsed = null) {
		$this->_this = $_this;
		$this->roleId = $roleId;
		$this->failIfUsed = $failIfUsed;
	}
}

class UpdateAuthorizationRoleRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $roleId; //int
	public $newName; //string
	public $privIds; //string

	function __construct($_this = null, $roleId = null, $newName = null, $privIds = null) {
		$this->_this = $_this;
		$this->roleId = $roleId;
		$this->newName = $newName;
		$this->privIds = $privIds;
	}
}

class MergePermissionsRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $srcRoleId; //int
	public $dstRoleId; //int

	function __construct($_this = null, $srcRoleId = null, $dstRoleId = null) {
		$this->_this = $_this;
		$this->srcRoleId = $srcRoleId;
		$this->dstRoleId = $dstRoleId;
	}
}

class RetrieveRolePermissionsRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $roleId; //int

	function __construct($_this = null, $roleId = null) {
		$this->_this = $_this;
		$this->roleId = $roleId;
	}
}

class RetrieveEntityPermissionsRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $entity; //ManagedObjectReference
	public $inherited; //boolean

	function __construct($_this = null, $entity = null, $inherited = null) {
		$this->_this = $_this;
		$this->entity = $entity;
		$this->inherited = $inherited;
	}
}

class RetrieveAllPermissionsRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference

	function __construct($_this = null) {
		$this->_this = $_this;
	}
}

class SetEntityPermissionsRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $entity; //ManagedObjectReference
	public $permission; //Permission

	function __construct($_this = null, $entity = null, $permission = null) {
		$this->_this = $_this;
		$this->entity = $entity;
		$this->permission = $permission;
	}
}

class ResetEntityPermissionsRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $entity; //ManagedObjectReference
	public $permission; //Permission

	function __construct($_this = null, $entity = null, $permission = null) {
		$this->_this = $_this;
		$this->entity = $entity;
		$this->permission = $permission;
	}
}

class RemoveEntityPermissionRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $entity; //ManagedObjectReference
	public $user; //string
	public $isGroup; //boolean

	function __construct($_this = null, $entity = null, $user = null, $isGroup = null) {
		$this->_this = $_this;
		$this->entity = $entity;
		$this->user = $user;
		$this->isGroup = $isGroup;
	}
}

class HasPrivilegeOnEntityRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $entity; //ManagedObjectReference
	public $sessionId; //string
	public $privId; //string

	function __construct($_this = null, $entity = null, $sessionId = null, $privId = null) {
		$this->_this = $_this;
		$this->entity = $entity;
		$this->sessionId = $sessionId;
		$this->privId = $privId;
	}
}

class ReconfigureClusterRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $spec; //ClusterConfigSpec
	public $modify; //boolean

	function __construct($_this = null, $spec = null, $modify = null) {
		$this->_this = $_this;
		$this->spec = $spec;
		$this->modify = $modify;
	}
}

class ApplyRecommendationRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $key; //string

	function __construct($_this = null, $key = null) {
		$this->_this = $_this;
		$this->key = $key;
	}
}

class CancelRecommendationRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $key; //string

	function __construct($_this = null, $key = null) {
		$this->_this = $_this;
		$this->key = $key;
	}
}

class RecommendHostsForVmRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $vm; //ManagedObjectReference
	public $pool; //ManagedObjectReference

	function __construct($_this = null, $vm = null, $pool = null) {
		$this->_this = $_this;
		$this->vm = $vm;
		$this->pool = $pool;
	}
}

class AddHostRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $spec; //HostConnectSpec
	public $asConnected; //boolean
	public $resourcePool; //ManagedObjectReference
	public $license; //string

	function __construct($_this = null, $spec = null, $asConnected = null, $resourcePool = null, $license = null) {
		$this->_this = $_this;
		$this->spec = $spec;
		$this->asConnected = $asConnected;
		$this->resourcePool = $resourcePool;
		$this->license = $license;
	}
}

class MoveIntoRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $host; //ManagedObjectReference

	function __construct($_this = null, $host = null) {
		$this->_this = $_this;
		$this->host = $host;
	}
}

class MoveHostIntoRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $host; //ManagedObjectReference
	public $resourcePool; //ManagedObjectReference

	function __construct($_this = null, $host = null, $resourcePool = null) {
		$this->_this = $_this;
		$this->host = $host;
		$this->resourcePool = $resourcePool;
	}
}

class RefreshRecommendationRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference

	function __construct($_this = null) {
		$this->_this = $_this;
	}
}

class RetrieveDasAdvancedRuntimeInfoRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference

	function __construct($_this = null) {
		$this->_this = $_this;
	}
}

class ClusterEnterMaintenanceModeRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $host; //ManagedObjectReference
	public $option; //OptionValue

	function __construct($_this = null, $host = null, $option = null) {
		$this->_this = $_this;
		$this->host = $host;
		$this->option = $option;
	}
}

class ReconfigureComputeResourceRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $spec; //ComputeResourceConfigSpec
	public $modify; //boolean

	function __construct($_this = null, $spec = null, $modify = null) {
		$this->_this = $_this;
		$this->spec = $spec;
		$this->modify = $modify;
	}
}

class AddCustomFieldDefRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $name; //string
	public $moType; //string
	public $fieldDefPolicy; //PrivilegePolicyDef
	public $fieldPolicy; //PrivilegePolicyDef

	function __construct($_this = null, $name = null, $moType = null, $fieldDefPolicy = null, $fieldPolicy = null) {
		$this->_this = $_this;
		$this->name = $name;
		$this->moType = $moType;
		$this->fieldDefPolicy = $fieldDefPolicy;
		$this->fieldPolicy = $fieldPolicy;
	}
}

class RemoveCustomFieldDefRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $key; //int

	function __construct($_this = null, $key = null) {
		$this->_this = $_this;
		$this->key = $key;
	}
}

class RenameCustomFieldDefRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $key; //int
	public $name; //string

	function __construct($_this = null, $key = null, $name = null) {
		$this->_this = $_this;
		$this->key = $key;
		$this->name = $name;
	}
}

class SetFieldRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $entity; //ManagedObjectReference
	public $key; //int
	public $value; //string

	function __construct($_this = null, $entity = null, $key = null, $value = null) {
		$this->_this = $_this;
		$this->entity = $entity;
		$this->key = $key;
		$this->value = $value;
	}
}

class DoesCustomizationSpecExistRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $name; //string

	function __construct($_this = null, $name = null) {
		$this->_this = $_this;
		$this->name = $name;
	}
}

class GetCustomizationSpecRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $name; //string

	function __construct($_this = null, $name = null) {
		$this->_this = $_this;
		$this->name = $name;
	}
}

class CreateCustomizationSpecRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $item; //CustomizationSpecItem

	function __construct($_this = null, $item = null) {
		$this->_this = $_this;
		$this->item = $item;
	}
}

class OverwriteCustomizationSpecRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $item; //CustomizationSpecItem

	function __construct($_this = null, $item = null) {
		$this->_this = $_this;
		$this->item = $item;
	}
}

class DeleteCustomizationSpecRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $name; //string

	function __construct($_this = null, $name = null) {
		$this->_this = $_this;
		$this->name = $name;
	}
}

class DuplicateCustomizationSpecRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $name; //string
	public $newName; //string

	function __construct($_this = null, $name = null, $newName = null) {
		$this->_this = $_this;
		$this->name = $name;
		$this->newName = $newName;
	}
}

class RenameCustomizationSpecRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $name; //string
	public $newName; //string

	function __construct($_this = null, $name = null, $newName = null) {
		$this->_this = $_this;
		$this->name = $name;
		$this->newName = $newName;
	}
}

class CustomizationSpecItemToXmlRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $item; //CustomizationSpecItem

	function __construct($_this = null, $item = null) {
		$this->_this = $_this;
		$this->item = $item;
	}
}

class XmlToCustomizationSpecItemRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $specItemXml; //string

	function __construct($_this = null, $specItemXml = null) {
		$this->_this = $_this;
		$this->specItemXml = $specItemXml;
	}
}

class CheckCustomizationResourcesRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $guestOs; //string

	function __construct($_this = null, $guestOs = null) {
		$this->_this = $_this;
		$this->guestOs = $guestOs;
	}
}

class QueryConnectionInfoRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $hostname; //string
	public $port; //int
	public $username; //string
	public $password; //string
	public $sslThumbprint; //string

	function __construct($_this = null, $hostname = null, $port = null, $username = null, $password = null, $sslThumbprint = null) {
		$this->_this = $_this;
		$this->hostname = $hostname;
		$this->port = $port;
		$this->username = $username;
		$this->password = $password;
		$this->sslThumbprint = $sslThumbprint;
	}
}

class PowerOnMultiVMRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $vm; //ManagedObjectReference
	public $option; //OptionValue

	function __construct($_this = null, $vm = null, $option = null) {
		$this->_this = $_this;
		$this->vm = $vm;
		$this->option = $option;
	}
}

class RefreshDatastoreRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference

	function __construct($_this = null) {
		$this->_this = $_this;
	}
}

class RefreshDatastoreStorageInfoRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference

	function __construct($_this = null) {
		$this->_this = $_this;
	}
}

class UpdateVirtualMachineFilesRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $mountPathDatastoreMapping; //DatastoreMountPathDatastorePair

	function __construct($_this = null, $mountPathDatastoreMapping = null) {
		$this->_this = $_this;
		$this->mountPathDatastoreMapping = $mountPathDatastoreMapping;
	}
}

class RenameDatastoreRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $newName; //string

	function __construct($_this = null, $newName = null) {
		$this->_this = $_this;
		$this->newName = $newName;
	}
}

class DestroyDatastoreRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference

	function __construct($_this = null) {
		$this->_this = $_this;
	}
}

class DatastoreEnterMaintenanceModeRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference

	function __construct($_this = null) {
		$this->_this = $_this;
	}
}

class DatastoreExitMaintenanceModeRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference

	function __construct($_this = null) {
		$this->_this = $_this;
	}
}

class QueryDescriptionsRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $host; //ManagedObjectReference

	function __construct($_this = null, $host = null) {
		$this->_this = $_this;
		$this->host = $host;
	}
}

class BrowseDiagnosticLogRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $host; //ManagedObjectReference
	public $key; //string
	public $start; //int
	public $lines; //int

	function __construct($_this = null, $host = null, $key = null, $start = null, $lines = null) {
		$this->_this = $_this;
		$this->host = $host;
		$this->key = $key;
		$this->start = $start;
		$this->lines = $lines;
	}
}

class GenerateLogBundlesRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $includeDefault; //boolean
	public $host; //ManagedObjectReference

	function __construct($_this = null, $includeDefault = null, $host = null) {
		$this->_this = $_this;
		$this->includeDefault = $includeDefault;
		$this->host = $host;
	}
}

class FetchDVPortKeysRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $criteria; //DistributedVirtualSwitchPortCriteria

	function __construct($_this = null, $criteria = null) {
		$this->_this = $_this;
		$this->criteria = $criteria;
	}
}

class FetchDVPortsRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $criteria; //DistributedVirtualSwitchPortCriteria

	function __construct($_this = null, $criteria = null) {
		$this->_this = $_this;
		$this->criteria = $criteria;
	}
}

class QueryUsedVlanIdInDvsRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference

	function __construct($_this = null) {
		$this->_this = $_this;
	}
}

class ReconfigureDvsRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $spec; //DVSConfigSpec

	function __construct($_this = null, $spec = null) {
		$this->_this = $_this;
		$this->spec = $spec;
	}
}

class PerformDvsProductSpecOperationRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $operation; //string
	public $productSpec; //DistributedVirtualSwitchProductSpec

	function __construct($_this = null, $operation = null, $productSpec = null) {
		$this->_this = $_this;
		$this->operation = $operation;
		$this->productSpec = $productSpec;
	}
}

class MergeDvsRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $dvs; //ManagedObjectReference

	function __construct($_this = null, $dvs = null) {
		$this->_this = $_this;
		$this->dvs = $dvs;
	}
}

class AddDVPortgroupRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $spec; //DVPortgroupConfigSpec

	function __construct($_this = null, $spec = null) {
		$this->_this = $_this;
		$this->spec = $spec;
	}
}

class MoveDVPortRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $portKey; //string
	public $destinationPortgroupKey; //string

	function __construct($_this = null, $portKey = null, $destinationPortgroupKey = null) {
		$this->_this = $_this;
		$this->portKey = $portKey;
		$this->destinationPortgroupKey = $destinationPortgroupKey;
	}
}

class UpdateDvsCapabilityRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $capability; //DVSCapability

	function __construct($_this = null, $capability = null) {
		$this->_this = $_this;
		$this->capability = $capability;
	}
}

class ReconfigureDVPortRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $port; //DVPortConfigSpec

	function __construct($_this = null, $port = null) {
		$this->_this = $_this;
		$this->port = $port;
	}
}

class RefreshDVPortStateRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $portKeys; //string

	function __construct($_this = null, $portKeys = null) {
		$this->_this = $_this;
		$this->portKeys = $portKeys;
	}
}

class RectifyDvsHostRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $hosts; //ManagedObjectReference

	function __construct($_this = null, $hosts = null) {
		$this->_this = $_this;
		$this->hosts = $hosts;
	}
}

class UpdateNetworkResourcePoolRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $configSpec; //DVSNetworkResourcePoolConfigSpec

	function __construct($_this = null, $configSpec = null) {
		$this->_this = $_this;
		$this->configSpec = $configSpec;
	}
}

class AddNetworkResourcePoolRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $configSpec; //DVSNetworkResourcePoolConfigSpec

	function __construct($_this = null, $configSpec = null) {
		$this->_this = $_this;
		$this->configSpec = $configSpec;
	}
}

class RemoveNetworkResourcePoolRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $key; //string

	function __construct($_this = null, $key = null) {
		$this->_this = $_this;
		$this->key = $key;
	}
}

class EnableNetworkResourceManagementRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $enable; //boolean

	function __construct($_this = null, $enable = null) {
		$this->_this = $_this;
		$this->enable = $enable;
	}
}

class QueryConfigOptionDescriptorRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference

	function __construct($_this = null) {
		$this->_this = $_this;
	}
}

class QueryConfigOptionRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $key; //string
	public $host; //ManagedObjectReference

	function __construct($_this = null, $key = null, $host = null) {
		$this->_this = $_this;
		$this->key = $key;
		$this->host = $host;
	}
}

class QueryConfigTargetRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $host; //ManagedObjectReference

	function __construct($_this = null, $host = null) {
		$this->_this = $_this;
		$this->host = $host;
	}
}

class QueryTargetCapabilitiesRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $host; //ManagedObjectReference

	function __construct($_this = null, $host = null) {
		$this->_this = $_this;
		$this->host = $host;
	}
}

class setCustomValueRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $key; //string
	public $value; //string

	function __construct($_this = null, $key = null, $value = null) {
		$this->_this = $_this;
		$this->key = $key;
		$this->value = $value;
	}
}

class UnregisterExtensionRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $extensionKey; //string

	function __construct($_this = null, $extensionKey = null) {
		$this->_this = $_this;
		$this->extensionKey = $extensionKey;
	}
}

class FindExtensionRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $extensionKey; //string

	function __construct($_this = null, $extensionKey = null) {
		$this->_this = $_this;
		$this->extensionKey = $extensionKey;
	}
}

class RegisterExtensionRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $extension; //Extension

	function __construct($_this = null, $extension = null) {
		$this->_this = $_this;
		$this->extension = $extension;
	}
}

class UpdateExtensionRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $extension; //Extension

	function __construct($_this = null, $extension = null) {
		$this->_this = $_this;
		$this->extension = $extension;
	}
}

class GetPublicKeyRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference

	function __construct($_this = null) {
		$this->_this = $_this;
	}
}

class SetPublicKeyRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $extensionKey; //string
	public $publicKey; //string

	function __construct($_this = null, $extensionKey = null, $publicKey = null) {
		$this->_this = $_this;
		$this->extensionKey = $extensionKey;
		$this->publicKey = $publicKey;
	}
}

class SetExtensionCertificateRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $extensionKey; //string
	public $certificatePem; //string

	function __construct($_this = null, $extensionKey = null, $certificatePem = null) {
		$this->_this = $_this;
		$this->extensionKey = $extensionKey;
		$this->certificatePem = $certificatePem;
	}
}

class QueryManagedByRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $extensionKey; //string

	function __construct($_this = null, $extensionKey = null) {
		$this->_this = $_this;
		$this->extensionKey = $extensionKey;
	}
}

class MoveDatastoreFileRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $sourceName; //string
	public $sourceDatacenter; //ManagedObjectReference
	public $destinationName; //string
	public $destinationDatacenter; //ManagedObjectReference
	public $force; //boolean

	function __construct($_this = null, $sourceName = null, $sourceDatacenter = null, $destinationName = null, $destinationDatacenter = null, $force = null) {
		$this->_this = $_this;
		$this->sourceName = $sourceName;
		$this->sourceDatacenter = $sourceDatacenter;
		$this->destinationName = $destinationName;
		$this->destinationDatacenter = $destinationDatacenter;
		$this->force = $force;
	}
}

class CopyDatastoreFileRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $sourceName; //string
	public $sourceDatacenter; //ManagedObjectReference
	public $destinationName; //string
	public $destinationDatacenter; //ManagedObjectReference
	public $force; //boolean

	function __construct($_this = null, $sourceName = null, $sourceDatacenter = null, $destinationName = null, $destinationDatacenter = null, $force = null) {
		$this->_this = $_this;
		$this->sourceName = $sourceName;
		$this->sourceDatacenter = $sourceDatacenter;
		$this->destinationName = $destinationName;
		$this->destinationDatacenter = $destinationDatacenter;
		$this->force = $force;
	}
}

class DeleteDatastoreFileRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $name; //string
	public $datacenter; //ManagedObjectReference

	function __construct($_this = null, $name = null, $datacenter = null) {
		$this->_this = $_this;
		$this->name = $name;
		$this->datacenter = $datacenter;
	}
}

class MakeDirectoryRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $name; //string
	public $datacenter; //ManagedObjectReference
	public $createParentDirectories; //boolean

	function __construct($_this = null, $name = null, $datacenter = null, $createParentDirectories = null) {
		$this->_this = $_this;
		$this->name = $name;
		$this->datacenter = $datacenter;
		$this->createParentDirectories = $createParentDirectories;
	}
}

class ChangeOwnerRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $name; //string
	public $datacenter; //ManagedObjectReference
	public $owner; //string

	function __construct($_this = null, $name = null, $datacenter = null, $owner = null) {
		$this->_this = $_this;
		$this->name = $name;
		$this->datacenter = $datacenter;
		$this->owner = $owner;
	}
}

class CreateFolderRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $name; //string

	function __construct($_this = null, $name = null) {
		$this->_this = $_this;
		$this->name = $name;
	}
}

class MoveIntoFolderRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $list; //ManagedObjectReference

	function __construct($_this = null, $list = null) {
		$this->_this = $_this;
		$this->list = $list;
	}
}

class CreateVMRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $config; //VirtualMachineConfigSpec
	public $pool; //ManagedObjectReference
	public $host; //ManagedObjectReference

	function __construct($_this = null, $config = null, $pool = null, $host = null) {
		$this->_this = $_this;
		$this->config = $config;
		$this->pool = $pool;
		$this->host = $host;
	}
}

class RegisterVMRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $path; //string
	public $name; //string
	public $asTemplate; //boolean
	public $pool; //ManagedObjectReference
	public $host; //ManagedObjectReference

	function __construct($_this = null, $path = null, $name = null, $asTemplate = null, $pool = null, $host = null) {
		$this->_this = $_this;
		$this->path = $path;
		$this->name = $name;
		$this->asTemplate = $asTemplate;
		$this->pool = $pool;
		$this->host = $host;
	}
}

class CreateClusterRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $name; //string
	public $spec; //ClusterConfigSpec

	function __construct($_this = null, $name = null, $spec = null) {
		$this->_this = $_this;
		$this->name = $name;
		$this->spec = $spec;
	}
}

class CreateClusterExRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $name; //string
	public $spec; //ClusterConfigSpecEx

	function __construct($_this = null, $name = null, $spec = null) {
		$this->_this = $_this;
		$this->name = $name;
		$this->spec = $spec;
	}
}

class AddStandaloneHostRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $spec; //HostConnectSpec
	public $compResSpec; //ComputeResourceConfigSpec
	public $addConnected; //boolean
	public $license; //string

	function __construct($_this = null, $spec = null, $compResSpec = null, $addConnected = null, $license = null) {
		$this->_this = $_this;
		$this->spec = $spec;
		$this->compResSpec = $compResSpec;
		$this->addConnected = $addConnected;
		$this->license = $license;
	}
}

class CreateDatacenterRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $name; //string

	function __construct($_this = null, $name = null) {
		$this->_this = $_this;
		$this->name = $name;
	}
}

class UnregisterAndDestroyRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference

	function __construct($_this = null) {
		$this->_this = $_this;
	}
}

class CreateDVSRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $spec; //DVSCreateSpec

	function __construct($_this = null, $spec = null) {
		$this->_this = $_this;
		$this->spec = $spec;
	}
}

class CreateStoragePodRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $name; //string

	function __construct($_this = null, $name = null) {
		$this->_this = $_this;
		$this->name = $name;
	}
}

class SetCollectorPageSizeRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $maxCount; //int

	function __construct($_this = null, $maxCount = null) {
		$this->_this = $_this;
		$this->maxCount = $maxCount;
	}
}

class RewindCollectorRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference

	function __construct($_this = null) {
		$this->_this = $_this;
	}
}

class ResetCollectorRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference

	function __construct($_this = null) {
		$this->_this = $_this;
	}
}

class DestroyCollectorRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference

	function __construct($_this = null) {
		$this->_this = $_this;
	}
}

class QueryHostConnectionInfoRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference

	function __construct($_this = null) {
		$this->_this = $_this;
	}
}

class UpdateSystemResourcesRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $resourceInfo; //HostSystemResourceInfo

	function __construct($_this = null, $resourceInfo = null) {
		$this->_this = $_this;
		$this->resourceInfo = $resourceInfo;
	}
}

class ReconnectHostRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $cnxSpec; //HostConnectSpec
	public $reconnectSpec; //HostSystemReconnectSpec

	function __construct($_this = null, $cnxSpec = null, $reconnectSpec = null) {
		$this->_this = $_this;
		$this->cnxSpec = $cnxSpec;
		$this->reconnectSpec = $reconnectSpec;
	}
}

class DisconnectHostRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference

	function __construct($_this = null) {
		$this->_this = $_this;
	}
}

class EnterMaintenanceModeRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $timeout; //int
	public $evacuatePoweredOffVms; //boolean

	function __construct($_this = null, $timeout = null, $evacuatePoweredOffVms = null) {
		$this->_this = $_this;
		$this->timeout = $timeout;
		$this->evacuatePoweredOffVms = $evacuatePoweredOffVms;
	}
}

class ExitMaintenanceModeRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $timeout; //int

	function __construct($_this = null, $timeout = null) {
		$this->_this = $_this;
		$this->timeout = $timeout;
	}
}

class RebootHostRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $force; //boolean

	function __construct($_this = null, $force = null) {
		$this->_this = $_this;
		$this->force = $force;
	}
}

class ShutdownHostRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $force; //boolean

	function __construct($_this = null, $force = null) {
		$this->_this = $_this;
		$this->force = $force;
	}
}

class PowerDownHostToStandByRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $timeoutSec; //int
	public $evacuatePoweredOffVms; //boolean

	function __construct($_this = null, $timeoutSec = null, $evacuatePoweredOffVms = null) {
		$this->_this = $_this;
		$this->timeoutSec = $timeoutSec;
		$this->evacuatePoweredOffVms = $evacuatePoweredOffVms;
	}
}

class PowerUpHostFromStandByRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $timeoutSec; //int

	function __construct($_this = null, $timeoutSec = null) {
		$this->_this = $_this;
		$this->timeoutSec = $timeoutSec;
	}
}

class QueryMemoryOverheadRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $memorySize; //long
	public $videoRamSize; //int
	public $numVcpus; //int

	function __construct($_this = null, $memorySize = null, $videoRamSize = null, $numVcpus = null) {
		$this->_this = $_this;
		$this->memorySize = $memorySize;
		$this->videoRamSize = $videoRamSize;
		$this->numVcpus = $numVcpus;
	}
}

class QueryMemoryOverheadExRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $vmConfigInfo; //VirtualMachineConfigInfo

	function __construct($_this = null, $vmConfigInfo = null) {
		$this->_this = $_this;
		$this->vmConfigInfo = $vmConfigInfo;
	}
}

class ReconfigureHostForDASRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference

	function __construct($_this = null) {
		$this->_this = $_this;
	}
}

class UpdateFlagsRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $flagInfo; //HostFlagInfo

	function __construct($_this = null, $flagInfo = null) {
		$this->_this = $_this;
		$this->flagInfo = $flagInfo;
	}
}

class EnterLockdownModeRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference

	function __construct($_this = null) {
		$this->_this = $_this;
	}
}

class ExitLockdownModeRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference

	function __construct($_this = null) {
		$this->_this = $_this;
	}
}

class AcquireCimServicesTicketRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference

	function __construct($_this = null) {
		$this->_this = $_this;
	}
}

class UpdateIpmiRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $ipmiInfo; //HostIpmiInfo

	function __construct($_this = null, $ipmiInfo = null) {
		$this->_this = $_this;
		$this->ipmiInfo = $ipmiInfo;
	}
}

class RetrieveHardwareUptimeRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference

	function __construct($_this = null) {
		$this->_this = $_this;
	}
}

class HttpNfcLeaseGetManifestRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference

	function __construct($_this = null) {
		$this->_this = $_this;
	}
}

class HttpNfcLeaseCompleteRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference

	function __construct($_this = null) {
		$this->_this = $_this;
	}
}

class HttpNfcLeaseAbortRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $fault; //LocalizedMethodFault

	function __construct($_this = null, $fault = null) {
		$this->_this = $_this;
		$this->fault = $fault;
	}
}

class HttpNfcLeaseProgressRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $percent; //int

	function __construct($_this = null, $percent = null) {
		$this->_this = $_this;
		$this->percent = $percent;
	}
}

class QueryIpPoolsRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $dc; //ManagedObjectReference

	function __construct($_this = null, $dc = null) {
		$this->_this = $_this;
		$this->dc = $dc;
	}
}

class CreateIpPoolRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $dc; //ManagedObjectReference
	public $pool; //IpPool

	function __construct($_this = null, $dc = null, $pool = null) {
		$this->_this = $_this;
		$this->dc = $dc;
		$this->pool = $pool;
	}
}

class UpdateIpPoolRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $dc; //ManagedObjectReference
	public $pool; //IpPool

	function __construct($_this = null, $dc = null, $pool = null) {
		$this->_this = $_this;
		$this->dc = $dc;
		$this->pool = $pool;
	}
}

class DestroyIpPoolRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $dc; //ManagedObjectReference
	public $id; //int
	public $force; //boolean

	function __construct($_this = null, $dc = null, $id = null, $force = null) {
		$this->_this = $_this;
		$this->dc = $dc;
		$this->id = $id;
		$this->force = $force;
	}
}

class UpdateAssignedLicenseRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $entity; //string
	public $licenseKey; //string
	public $entityDisplayName; //string

	function __construct($_this = null, $entity = null, $licenseKey = null, $entityDisplayName = null) {
		$this->_this = $_this;
		$this->entity = $entity;
		$this->licenseKey = $licenseKey;
		$this->entityDisplayName = $entityDisplayName;
	}
}

class RemoveAssignedLicenseRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $entityId; //string

	function __construct($_this = null, $entityId = null) {
		$this->_this = $_this;
		$this->entityId = $entityId;
	}
}

class QueryAssignedLicensesRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $entityId; //string

	function __construct($_this = null, $entityId = null) {
		$this->_this = $_this;
		$this->entityId = $entityId;
	}
}

class QuerySupportedFeaturesRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $host; //ManagedObjectReference

	function __construct($_this = null, $host = null) {
		$this->_this = $_this;
		$this->host = $host;
	}
}

class QueryLicenseSourceAvailabilityRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $host; //ManagedObjectReference

	function __construct($_this = null, $host = null) {
		$this->_this = $_this;
		$this->host = $host;
	}
}

class QueryLicenseUsageRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $host; //ManagedObjectReference

	function __construct($_this = null, $host = null) {
		$this->_this = $_this;
		$this->host = $host;
	}
}

class SetLicenseEditionRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $host; //ManagedObjectReference
	public $featureKey; //string

	function __construct($_this = null, $host = null, $featureKey = null) {
		$this->_this = $_this;
		$this->host = $host;
		$this->featureKey = $featureKey;
	}
}

class CheckLicenseFeatureRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $host; //ManagedObjectReference
	public $featureKey; //string

	function __construct($_this = null, $host = null, $featureKey = null) {
		$this->_this = $_this;
		$this->host = $host;
		$this->featureKey = $featureKey;
	}
}

class EnableFeatureRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $host; //ManagedObjectReference
	public $featureKey; //string

	function __construct($_this = null, $host = null, $featureKey = null) {
		$this->_this = $_this;
		$this->host = $host;
		$this->featureKey = $featureKey;
	}
}

class DisableFeatureRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $host; //ManagedObjectReference
	public $featureKey; //string

	function __construct($_this = null, $host = null, $featureKey = null) {
		$this->_this = $_this;
		$this->host = $host;
		$this->featureKey = $featureKey;
	}
}

class ConfigureLicenseSourceRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $host; //ManagedObjectReference
	public $licenseSource; //LicenseSource

	function __construct($_this = null, $host = null, $licenseSource = null) {
		$this->_this = $_this;
		$this->host = $host;
		$this->licenseSource = $licenseSource;
	}
}

class UpdateLicenseRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $licenseKey; //string
	public $labels; //KeyValue

	function __construct($_this = null, $licenseKey = null, $labels = null) {
		$this->_this = $_this;
		$this->licenseKey = $licenseKey;
		$this->labels = $labels;
	}
}

class AddLicenseRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $licenseKey; //string
	public $labels; //KeyValue

	function __construct($_this = null, $licenseKey = null, $labels = null) {
		$this->_this = $_this;
		$this->licenseKey = $licenseKey;
		$this->labels = $labels;
	}
}

class RemoveLicenseRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $licenseKey; //string

	function __construct($_this = null, $licenseKey = null) {
		$this->_this = $_this;
		$this->licenseKey = $licenseKey;
	}
}

class DecodeLicenseRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $licenseKey; //string

	function __construct($_this = null, $licenseKey = null) {
		$this->_this = $_this;
		$this->licenseKey = $licenseKey;
	}
}

class UpdateLicenseLabelRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $licenseKey; //string
	public $labelKey; //string
	public $labelValue; //string

	function __construct($_this = null, $licenseKey = null, $labelKey = null, $labelValue = null) {
		$this->_this = $_this;
		$this->licenseKey = $licenseKey;
		$this->labelKey = $labelKey;
		$this->labelValue = $labelValue;
	}
}

class RemoveLicenseLabelRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $licenseKey; //string
	public $labelKey; //string

	function __construct($_this = null, $licenseKey = null, $labelKey = null) {
		$this->_this = $_this;
		$this->licenseKey = $licenseKey;
		$this->labelKey = $labelKey;
	}
}

class ReloadRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference

	function __construct($_this = null) {
		$this->_this = $_this;
	}
}

class RenameRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $newName; //string

	function __construct($_this = null, $newName = null) {
		$this->_this = $_this;
		$this->newName = $newName;
	}
}

class DestroyRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference

	function __construct($_this = null) {
		$this->_this = $_this;
	}
}

class DestroyNetworkRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference

	function __construct($_this = null) {
		$this->_this = $_this;
	}
}

class ValidateHostRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $ovfDescriptor; //string
	public $host; //ManagedObjectReference
	public $vhp; //OvfValidateHostParams

	function __construct($_this = null, $ovfDescriptor = null, $host = null, $vhp = null) {
		$this->_this = $_this;
		$this->ovfDescriptor = $ovfDescriptor;
		$this->host = $host;
		$this->vhp = $vhp;
	}
}

class ParseDescriptorRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $ovfDescriptor; //string
	public $pdp; //OvfParseDescriptorParams

	function __construct($_this = null, $ovfDescriptor = null, $pdp = null) {
		$this->_this = $_this;
		$this->ovfDescriptor = $ovfDescriptor;
		$this->pdp = $pdp;
	}
}

class CreateImportSpecRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $ovfDescriptor; //string
	public $resourcePool; //ManagedObjectReference
	public $datastore; //ManagedObjectReference
	public $cisp; //OvfCreateImportSpecParams

	function __construct($_this = null, $ovfDescriptor = null, $resourcePool = null, $datastore = null, $cisp = null) {
		$this->_this = $_this;
		$this->ovfDescriptor = $ovfDescriptor;
		$this->resourcePool = $resourcePool;
		$this->datastore = $datastore;
		$this->cisp = $cisp;
	}
}

class CreateDescriptorRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $obj; //ManagedObjectReference
	public $cdp; //OvfCreateDescriptorParams

	function __construct($_this = null, $obj = null, $cdp = null) {
		$this->_this = $_this;
		$this->obj = $obj;
		$this->cdp = $cdp;
	}
}

class QueryPerfProviderSummaryRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $entity; //ManagedObjectReference

	function __construct($_this = null, $entity = null) {
		$this->_this = $_this;
		$this->entity = $entity;
	}
}

class QueryAvailablePerfMetricRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $entity; //ManagedObjectReference
	public $beginTime; //dateTime
	public $endTime; //dateTime
	public $intervalId; //int

	function __construct($_this = null, $entity = null, $beginTime = null, $endTime = null, $intervalId = null) {
		$this->_this = $_this;
		$this->entity = $entity;
		$this->beginTime = $beginTime;
		$this->endTime = $endTime;
		$this->intervalId = $intervalId;
	}
}

class QueryPerfCounterRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $counterId; //int

	function __construct($_this = null, $counterId = null) {
		$this->_this = $_this;
		$this->counterId = $counterId;
	}
}

class QueryPerfCounterByLevelRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $level; //int

	function __construct($_this = null, $level = null) {
		$this->_this = $_this;
		$this->level = $level;
	}
}

class QueryPerfRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $querySpec; //PerfQuerySpec

	function __construct($_this = null, $querySpec = null) {
		$this->_this = $_this;
		$this->querySpec = $querySpec;
	}
}

class QueryPerfCompositeRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $querySpec; //PerfQuerySpec

	function __construct($_this = null, $querySpec = null) {
		$this->_this = $_this;
		$this->querySpec = $querySpec;
	}
}

class CreatePerfIntervalRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $intervalId; //PerfInterval

	function __construct($_this = null, $intervalId = null) {
		$this->_this = $_this;
		$this->intervalId = $intervalId;
	}
}

class RemovePerfIntervalRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $samplePeriod; //int

	function __construct($_this = null, $samplePeriod = null) {
		$this->_this = $_this;
		$this->samplePeriod = $samplePeriod;
	}
}

class UpdatePerfIntervalRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $interval; //PerfInterval

	function __construct($_this = null, $interval = null) {
		$this->_this = $_this;
		$this->interval = $interval;
	}
}

class UpdateCounterLevelMappingRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $counterLevelMap; //PerformanceManagerCounterLevelMapping

	function __construct($_this = null, $counterLevelMap = null) {
		$this->_this = $_this;
		$this->counterLevelMap = $counterLevelMap;
	}
}

class ResetCounterLevelMappingRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $counters; //int

	function __construct($_this = null, $counters = null) {
		$this->_this = $_this;
		$this->counters = $counters;
	}
}

class EstimateDatabaseSizeRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $dbSizeParam; //DatabaseSizeParam

	function __construct($_this = null, $dbSizeParam = null) {
		$this->_this = $_this;
		$this->dbSizeParam = $dbSizeParam;
	}
}

class UpdateConfigRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $name; //string
	public $config; //ResourceConfigSpec

	function __construct($_this = null, $name = null, $config = null) {
		$this->_this = $_this;
		$this->name = $name;
		$this->config = $config;
	}
}

class MoveIntoResourcePoolRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $list; //ManagedObjectReference

	function __construct($_this = null, $list = null) {
		$this->_this = $_this;
		$this->list = $list;
	}
}

class UpdateChildResourceConfigurationRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $spec; //ResourceConfigSpec

	function __construct($_this = null, $spec = null) {
		$this->_this = $_this;
		$this->spec = $spec;
	}
}

class CreateResourcePoolRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $name; //string
	public $spec; //ResourceConfigSpec

	function __construct($_this = null, $name = null, $spec = null) {
		$this->_this = $_this;
		$this->name = $name;
		$this->spec = $spec;
	}
}

class DestroyChildrenRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference

	function __construct($_this = null) {
		$this->_this = $_this;
	}
}

class CreateVAppRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $name; //string
	public $resSpec; //ResourceConfigSpec
	public $configSpec; //VAppConfigSpec
	public $vmFolder; //ManagedObjectReference

	function __construct($_this = null, $name = null, $resSpec = null, $configSpec = null, $vmFolder = null) {
		$this->_this = $_this;
		$this->name = $name;
		$this->resSpec = $resSpec;
		$this->configSpec = $configSpec;
		$this->vmFolder = $vmFolder;
	}
}

class CreateChildVMRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $config; //VirtualMachineConfigSpec
	public $host; //ManagedObjectReference

	function __construct($_this = null, $config = null, $host = null) {
		$this->_this = $_this;
		$this->config = $config;
		$this->host = $host;
	}
}

class RegisterChildVMRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $path; //string
	public $name; //string
	public $host; //ManagedObjectReference

	function __construct($_this = null, $path = null, $name = null, $host = null) {
		$this->_this = $_this;
		$this->path = $path;
		$this->name = $name;
		$this->host = $host;
	}
}

class ImportVAppRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $spec; //ImportSpec
	public $folder; //ManagedObjectReference
	public $host; //ManagedObjectReference

	function __construct($_this = null, $spec = null, $folder = null, $host = null) {
		$this->_this = $_this;
		$this->spec = $spec;
		$this->folder = $folder;
		$this->host = $host;
	}
}

class QueryResourceConfigOptionRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference

	function __construct($_this = null) {
		$this->_this = $_this;
	}
}

class RefreshRuntimeRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference

	function __construct($_this = null) {
		$this->_this = $_this;
	}
}

class FindByUuidRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $datacenter; //ManagedObjectReference
	public $uuid; //string
	public $vmSearch; //boolean
	public $instanceUuid; //boolean

	function __construct($_this = null, $datacenter = null, $uuid = null, $vmSearch = null, $instanceUuid = null) {
		$this->_this = $_this;
		$this->datacenter = $datacenter;
		$this->uuid = $uuid;
		$this->vmSearch = $vmSearch;
		$this->instanceUuid = $instanceUuid;
	}
}

class FindByDatastorePathRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $datacenter; //ManagedObjectReference
	public $path; //string

	function __construct($_this = null, $datacenter = null, $path = null) {
		$this->_this = $_this;
		$this->datacenter = $datacenter;
		$this->path = $path;
	}
}

class FindByDnsNameRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $datacenter; //ManagedObjectReference
	public $dnsName; //string
	public $vmSearch; //boolean

	function __construct($_this = null, $datacenter = null, $dnsName = null, $vmSearch = null) {
		$this->_this = $_this;
		$this->datacenter = $datacenter;
		$this->dnsName = $dnsName;
		$this->vmSearch = $vmSearch;
	}
}

class FindByIpRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $datacenter; //ManagedObjectReference
	public $ip; //string
	public $vmSearch; //boolean

	function __construct($_this = null, $datacenter = null, $ip = null, $vmSearch = null) {
		$this->_this = $_this;
		$this->datacenter = $datacenter;
		$this->ip = $ip;
		$this->vmSearch = $vmSearch;
	}
}

class FindByInventoryPathRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $inventoryPath; //string

	function __construct($_this = null, $inventoryPath = null) {
		$this->_this = $_this;
		$this->inventoryPath = $inventoryPath;
	}
}

class FindChildRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $entity; //ManagedObjectReference
	public $name; //string

	function __construct($_this = null, $entity = null, $name = null) {
		$this->_this = $_this;
		$this->entity = $entity;
		$this->name = $name;
	}
}

class FindAllByUuidRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $datacenter; //ManagedObjectReference
	public $uuid; //string
	public $vmSearch; //boolean
	public $instanceUuid; //boolean

	function __construct($_this = null, $datacenter = null, $uuid = null, $vmSearch = null, $instanceUuid = null) {
		$this->_this = $_this;
		$this->datacenter = $datacenter;
		$this->uuid = $uuid;
		$this->vmSearch = $vmSearch;
		$this->instanceUuid = $instanceUuid;
	}
}

class FindAllByDnsNameRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $datacenter; //ManagedObjectReference
	public $dnsName; //string
	public $vmSearch; //boolean

	function __construct($_this = null, $datacenter = null, $dnsName = null, $vmSearch = null) {
		$this->_this = $_this;
		$this->datacenter = $datacenter;
		$this->dnsName = $dnsName;
		$this->vmSearch = $vmSearch;
	}
}

class FindAllByIpRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $datacenter; //ManagedObjectReference
	public $ip; //string
	public $vmSearch; //boolean

	function __construct($_this = null, $datacenter = null, $ip = null, $vmSearch = null) {
		$this->_this = $_this;
		$this->datacenter = $datacenter;
		$this->ip = $ip;
		$this->vmSearch = $vmSearch;
	}
}

class CurrentTimeRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference

	function __construct($_this = null) {
		$this->_this = $_this;
	}
}

class RetrieveServiceContentRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference

	function __construct($_this = null) {
		$this->_this = $_this;
	}
}

class ValidateMigrationRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $vm; //ManagedObjectReference
	public $state; //VirtualMachinePowerState
	public $testType; //string
	public $pool; //ManagedObjectReference
	public $host; //ManagedObjectReference

	function __construct($_this = null, $vm = null, $state = null, $testType = null, $pool = null, $host = null) {
		$this->_this = $_this;
		$this->vm = $vm;
		$this->state = $state;
		$this->testType = $testType;
		$this->pool = $pool;
		$this->host = $host;
	}
}

class QueryVMotionCompatibilityRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $vm; //ManagedObjectReference
	public $host; //ManagedObjectReference
	public $compatibility; //string

	function __construct($_this = null, $vm = null, $host = null, $compatibility = null) {
		$this->_this = $_this;
		$this->vm = $vm;
		$this->host = $host;
		$this->compatibility = $compatibility;
	}
}

class RetrieveProductComponentsRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference

	function __construct($_this = null) {
		$this->_this = $_this;
	}
}

class UpdateServiceMessageRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $message; //string

	function __construct($_this = null, $message = null) {
		$this->_this = $_this;
		$this->message = $message;
	}
}

class LoginRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $userName; //string
	public $password; //string
	public $locale; //string

	function __construct($_this = null, $userName = null, $password = null, $locale = null) {
		$this->_this = $_this;
		$this->userName = $userName;
		$this->password = $password;
		$this->locale = $locale;
	}
}

class LoginBySSPIRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $base64Token; //string
	public $locale; //string

	function __construct($_this = null, $base64Token = null, $locale = null) {
		$this->_this = $_this;
		$this->base64Token = $base64Token;
		$this->locale = $locale;
	}
}

class LogoutRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference

	function __construct($_this = null) {
		$this->_this = $_this;
	}
}

class AcquireLocalTicketRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $userName; //string

	function __construct($_this = null, $userName = null) {
		$this->_this = $_this;
		$this->userName = $userName;
	}
}

class AcquireGenericServiceTicketRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $spec; //SessionManagerServiceRequestSpec

	function __construct($_this = null, $spec = null) {
		$this->_this = $_this;
		$this->spec = $spec;
	}
}

class TerminateSessionRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $sessionId; //string

	function __construct($_this = null, $sessionId = null) {
		$this->_this = $_this;
		$this->sessionId = $sessionId;
	}
}

class SetLocaleRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $locale; //string

	function __construct($_this = null, $locale = null) {
		$this->_this = $_this;
		$this->locale = $locale;
	}
}

class LoginExtensionBySubjectNameRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $extensionKey; //string
	public $locale; //string

	function __construct($_this = null, $extensionKey = null, $locale = null) {
		$this->_this = $_this;
		$this->extensionKey = $extensionKey;
		$this->locale = $locale;
	}
}

class LoginExtensionByCertificateRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $extensionKey; //string
	public $locale; //string

	function __construct($_this = null, $extensionKey = null, $locale = null) {
		$this->_this = $_this;
		$this->extensionKey = $extensionKey;
		$this->locale = $locale;
	}
}

class ImpersonateUserRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $userName; //string
	public $locale; //string

	function __construct($_this = null, $userName = null, $locale = null) {
		$this->_this = $_this;
		$this->userName = $userName;
		$this->locale = $locale;
	}
}

class SessionIsActiveRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $sessionID; //string
	public $userName; //string

	function __construct($_this = null, $sessionID = null, $userName = null) {
		$this->_this = $_this;
		$this->sessionID = $sessionID;
		$this->userName = $userName;
	}
}

class AcquireCloneTicketRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference

	function __construct($_this = null) {
		$this->_this = $_this;
	}
}

class CloneSessionRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $cloneTicket; //string

	function __construct($_this = null, $cloneTicket = null) {
		$this->_this = $_this;
		$this->cloneTicket = $cloneTicket;
	}
}

class ConfigureDatastoreIORMRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $datastore; //ManagedObjectReference
	public $spec; //StorageIORMConfigSpec

	function __construct($_this = null, $datastore = null, $spec = null) {
		$this->_this = $_this;
		$this->datastore = $datastore;
		$this->spec = $spec;
	}
}

class QueryIORMConfigOptionRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $host; //ManagedObjectReference

	function __construct($_this = null, $host = null) {
		$this->_this = $_this;
		$this->host = $host;
	}
}

class ApplyStorageDrsRecommendationToPodRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $pod; //ManagedObjectReference
	public $key; //string

	function __construct($_this = null, $pod = null, $key = null) {
		$this->_this = $_this;
		$this->pod = $pod;
		$this->key = $key;
	}
}

class ApplyStorageDrsRecommendationRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $key; //string

	function __construct($_this = null, $key = null) {
		$this->_this = $_this;
		$this->key = $key;
	}
}

class CancelStorageDrsRecommendationRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $key; //string

	function __construct($_this = null, $key = null) {
		$this->_this = $_this;
		$this->key = $key;
	}
}

class RefreshStorageDrsRecommendationRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $pod; //ManagedObjectReference

	function __construct($_this = null, $pod = null) {
		$this->_this = $_this;
		$this->pod = $pod;
	}
}

class ConfigureStorageDrsForPodRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $pod; //ManagedObjectReference
	public $spec; //StorageDrsConfigSpec
	public $modify; //boolean

	function __construct($_this = null, $pod = null, $spec = null, $modify = null) {
		$this->_this = $_this;
		$this->pod = $pod;
		$this->spec = $spec;
		$this->modify = $modify;
	}
}

class RecommendDatastoresRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $storageSpec; //StoragePlacementSpec

	function __construct($_this = null, $storageSpec = null) {
		$this->_this = $_this;
		$this->storageSpec = $storageSpec;
	}
}

class CancelTaskRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference

	function __construct($_this = null) {
		$this->_this = $_this;
	}
}

class UpdateProgressRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $percentDone; //int

	function __construct($_this = null, $percentDone = null) {
		$this->_this = $_this;
		$this->percentDone = $percentDone;
	}
}

class SetTaskStateRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $state; //TaskInfoState
	public $result; //anyType
	public $fault; //LocalizedMethodFault

	function __construct($_this = null, $state = null, $result = null, $fault = null) {
		$this->_this = $_this;
		$this->state = $state;
		$this->result = $result;
		$this->fault = $fault;
	}
}

class SetTaskDescriptionRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $description; //LocalizableMessage

	function __construct($_this = null, $description = null) {
		$this->_this = $_this;
		$this->description = $description;
	}
}

class ReadNextTasksRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $maxCount; //int

	function __construct($_this = null, $maxCount = null) {
		$this->_this = $_this;
		$this->maxCount = $maxCount;
	}
}

class ReadPreviousTasksRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $maxCount; //int

	function __construct($_this = null, $maxCount = null) {
		$this->_this = $_this;
		$this->maxCount = $maxCount;
	}
}

class CreateCollectorForTasksRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $filter; //TaskFilterSpec

	function __construct($_this = null, $filter = null) {
		$this->_this = $_this;
		$this->filter = $filter;
	}
}

class CreateTaskRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $obj; //ManagedObjectReference
	public $taskTypeId; //string
	public $initiatedBy; //string
	public $cancelable; //boolean
	public $parentTaskKey; //string

	function __construct($_this = null, $obj = null, $taskTypeId = null, $initiatedBy = null, $cancelable = null, $parentTaskKey = null) {
		$this->_this = $_this;
		$this->obj = $obj;
		$this->taskTypeId = $taskTypeId;
		$this->initiatedBy = $initiatedBy;
		$this->cancelable = $cancelable;
		$this->parentTaskKey = $parentTaskKey;
	}
}

class RetrieveUserGroupsRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $domain; //string
	public $searchStr; //string
	public $belongsToGroup; //string
	public $belongsToUser; //string
	public $exactMatch; //boolean
	public $findUsers; //boolean
	public $findGroups; //boolean

	function __construct($_this = null, $domain = null, $searchStr = null, $belongsToGroup = null, $belongsToUser = null, $exactMatch = null, $findUsers = null, $findGroups = null) {
		$this->_this = $_this;
		$this->domain = $domain;
		$this->searchStr = $searchStr;
		$this->belongsToGroup = $belongsToGroup;
		$this->belongsToUser = $belongsToUser;
		$this->exactMatch = $exactMatch;
		$this->findUsers = $findUsers;
		$this->findGroups = $findGroups;
	}
}

class UpdateVAppConfigRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $spec; //VAppConfigSpec

	function __construct($_this = null, $spec = null) {
		$this->_this = $_this;
		$this->spec = $spec;
	}
}

class UpdateLinkedChildrenRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $addChangeSet; //VirtualAppLinkInfo
	public $removeSet; //ManagedObjectReference

	function __construct($_this = null, $addChangeSet = null, $removeSet = null) {
		$this->_this = $_this;
		$this->addChangeSet = $addChangeSet;
		$this->removeSet = $removeSet;
	}
}

class CloneVAppRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $name; //string
	public $target; //ManagedObjectReference
	public $spec; //VAppCloneSpec

	function __construct($_this = null, $name = null, $target = null, $spec = null) {
		$this->_this = $_this;
		$this->name = $name;
		$this->target = $target;
		$this->spec = $spec;
	}
}

class ExportVAppRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference

	function __construct($_this = null) {
		$this->_this = $_this;
	}
}

class PowerOnVAppRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference

	function __construct($_this = null) {
		$this->_this = $_this;
	}
}

class PowerOffVAppRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $force; //boolean

	function __construct($_this = null, $force = null) {
		$this->_this = $_this;
		$this->force = $force;
	}
}

class SuspendVAppRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference

	function __construct($_this = null) {
		$this->_this = $_this;
	}
}

class unregisterVAppRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference

	function __construct($_this = null) {
		$this->_this = $_this;
	}
}

class CreateVirtualDiskRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $name; //string
	public $datacenter; //ManagedObjectReference
	public $spec; //VirtualDiskSpec

	function __construct($_this = null, $name = null, $datacenter = null, $spec = null) {
		$this->_this = $_this;
		$this->name = $name;
		$this->datacenter = $datacenter;
		$this->spec = $spec;
	}
}

class DeleteVirtualDiskRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $name; //string
	public $datacenter; //ManagedObjectReference

	function __construct($_this = null, $name = null, $datacenter = null) {
		$this->_this = $_this;
		$this->name = $name;
		$this->datacenter = $datacenter;
	}
}

class MoveVirtualDiskRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $sourceName; //string
	public $sourceDatacenter; //ManagedObjectReference
	public $destName; //string
	public $destDatacenter; //ManagedObjectReference
	public $force; //boolean

	function __construct($_this = null, $sourceName = null, $sourceDatacenter = null, $destName = null, $destDatacenter = null, $force = null) {
		$this->_this = $_this;
		$this->sourceName = $sourceName;
		$this->sourceDatacenter = $sourceDatacenter;
		$this->destName = $destName;
		$this->destDatacenter = $destDatacenter;
		$this->force = $force;
	}
}

class CopyVirtualDiskRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $sourceName; //string
	public $sourceDatacenter; //ManagedObjectReference
	public $destName; //string
	public $destDatacenter; //ManagedObjectReference
	public $destSpec; //VirtualDiskSpec
	public $force; //boolean

	function __construct($_this = null, $sourceName = null, $sourceDatacenter = null, $destName = null, $destDatacenter = null, $destSpec = null, $force = null) {
		$this->_this = $_this;
		$this->sourceName = $sourceName;
		$this->sourceDatacenter = $sourceDatacenter;
		$this->destName = $destName;
		$this->destDatacenter = $destDatacenter;
		$this->destSpec = $destSpec;
		$this->force = $force;
	}
}

class ExtendVirtualDiskRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $name; //string
	public $datacenter; //ManagedObjectReference
	public $newCapacityKb; //long
	public $eagerZero; //boolean

	function __construct($_this = null, $name = null, $datacenter = null, $newCapacityKb = null, $eagerZero = null) {
		$this->_this = $_this;
		$this->name = $name;
		$this->datacenter = $datacenter;
		$this->newCapacityKb = $newCapacityKb;
		$this->eagerZero = $eagerZero;
	}
}

class QueryVirtualDiskFragmentationRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $name; //string
	public $datacenter; //ManagedObjectReference

	function __construct($_this = null, $name = null, $datacenter = null) {
		$this->_this = $_this;
		$this->name = $name;
		$this->datacenter = $datacenter;
	}
}

class DefragmentVirtualDiskRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $name; //string
	public $datacenter; //ManagedObjectReference

	function __construct($_this = null, $name = null, $datacenter = null) {
		$this->_this = $_this;
		$this->name = $name;
		$this->datacenter = $datacenter;
	}
}

class ShrinkVirtualDiskRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $name; //string
	public $datacenter; //ManagedObjectReference
	public $copy; //boolean

	function __construct($_this = null, $name = null, $datacenter = null, $copy = null) {
		$this->_this = $_this;
		$this->name = $name;
		$this->datacenter = $datacenter;
		$this->copy = $copy;
	}
}

class InflateVirtualDiskRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $name; //string
	public $datacenter; //ManagedObjectReference

	function __construct($_this = null, $name = null, $datacenter = null) {
		$this->_this = $_this;
		$this->name = $name;
		$this->datacenter = $datacenter;
	}
}

class EagerZeroVirtualDiskRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $name; //string
	public $datacenter; //ManagedObjectReference

	function __construct($_this = null, $name = null, $datacenter = null) {
		$this->_this = $_this;
		$this->name = $name;
		$this->datacenter = $datacenter;
	}
}

class ZeroFillVirtualDiskRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $name; //string
	public $datacenter; //ManagedObjectReference

	function __construct($_this = null, $name = null, $datacenter = null) {
		$this->_this = $_this;
		$this->name = $name;
		$this->datacenter = $datacenter;
	}
}

class SetVirtualDiskUuidRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $name; //string
	public $datacenter; //ManagedObjectReference
	public $uuid; //string

	function __construct($_this = null, $name = null, $datacenter = null, $uuid = null) {
		$this->_this = $_this;
		$this->name = $name;
		$this->datacenter = $datacenter;
		$this->uuid = $uuid;
	}
}

class QueryVirtualDiskUuidRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $name; //string
	public $datacenter; //ManagedObjectReference

	function __construct($_this = null, $name = null, $datacenter = null) {
		$this->_this = $_this;
		$this->name = $name;
		$this->datacenter = $datacenter;
	}
}

class QueryVirtualDiskGeometryRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $name; //string
	public $datacenter; //ManagedObjectReference

	function __construct($_this = null, $name = null, $datacenter = null) {
		$this->_this = $_this;
		$this->name = $name;
		$this->datacenter = $datacenter;
	}
}

class RefreshStorageInfoRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference

	function __construct($_this = null) {
		$this->_this = $_this;
	}
}

class CreateSnapshotRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $name; //string
	public $description; //string
	public $memory; //boolean
	public $quiesce; //boolean

	function __construct($_this = null, $name = null, $description = null, $memory = null, $quiesce = null) {
		$this->_this = $_this;
		$this->name = $name;
		$this->description = $description;
		$this->memory = $memory;
		$this->quiesce = $quiesce;
	}
}

class RevertToCurrentSnapshotRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $host; //ManagedObjectReference
	public $suppressPowerOn; //boolean

	function __construct($_this = null, $host = null, $suppressPowerOn = null) {
		$this->_this = $_this;
		$this->host = $host;
		$this->suppressPowerOn = $suppressPowerOn;
	}
}

class RemoveAllSnapshotsRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $consolidate; //boolean

	function __construct($_this = null, $consolidate = null) {
		$this->_this = $_this;
		$this->consolidate = $consolidate;
	}
}

class ConsolidateVMDisksRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference

	function __construct($_this = null) {
		$this->_this = $_this;
	}
}

class EstimateStorageForConsolidateSnapshotsRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference

	function __construct($_this = null) {
		$this->_this = $_this;
	}
}

class ReconfigVMRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $spec; //VirtualMachineConfigSpec

	function __construct($_this = null, $spec = null) {
		$this->_this = $_this;
		$this->spec = $spec;
	}
}

class UpgradeVMRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $version; //string

	function __construct($_this = null, $version = null) {
		$this->_this = $_this;
		$this->version = $version;
	}
}

class ExtractOvfEnvironmentRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference

	function __construct($_this = null) {
		$this->_this = $_this;
	}
}

class PowerOnVMRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $host; //ManagedObjectReference

	function __construct($_this = null, $host = null) {
		$this->_this = $_this;
		$this->host = $host;
	}
}

class PowerOffVMRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference

	function __construct($_this = null) {
		$this->_this = $_this;
	}
}

class SuspendVMRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference

	function __construct($_this = null) {
		$this->_this = $_this;
	}
}

class ResetVMRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference

	function __construct($_this = null) {
		$this->_this = $_this;
	}
}

class ShutdownGuestRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference

	function __construct($_this = null) {
		$this->_this = $_this;
	}
}

class RebootGuestRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference

	function __construct($_this = null) {
		$this->_this = $_this;
	}
}

class StandbyGuestRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference

	function __construct($_this = null) {
		$this->_this = $_this;
	}
}

class AnswerVMRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $questionId; //string
	public $answerChoice; //string

	function __construct($_this = null, $questionId = null, $answerChoice = null) {
		$this->_this = $_this;
		$this->questionId = $questionId;
		$this->answerChoice = $answerChoice;
	}
}

class CustomizeVMRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $spec; //CustomizationSpec

	function __construct($_this = null, $spec = null) {
		$this->_this = $_this;
		$this->spec = $spec;
	}
}

class CheckCustomizationSpecRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $spec; //CustomizationSpec

	function __construct($_this = null, $spec = null) {
		$this->_this = $_this;
		$this->spec = $spec;
	}
}

class MigrateVMRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $pool; //ManagedObjectReference
	public $host; //ManagedObjectReference
	public $priority; //VirtualMachineMovePriority
	public $state; //VirtualMachinePowerState

	function __construct($_this = null, $pool = null, $host = null, $priority = null, $state = null) {
		$this->_this = $_this;
		$this->pool = $pool;
		$this->host = $host;
		$this->priority = $priority;
		$this->state = $state;
	}
}

class RelocateVMRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $spec; //VirtualMachineRelocateSpec
	public $priority; //VirtualMachineMovePriority

	function __construct($_this = null, $spec = null, $priority = null) {
		$this->_this = $_this;
		$this->spec = $spec;
		$this->priority = $priority;
	}
}

class CloneVMRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $folder; //ManagedObjectReference
	public $name; //string
	public $spec; //VirtualMachineCloneSpec

	function __construct($_this = null, $folder = null, $name = null, $spec = null) {
		$this->_this = $_this;
		$this->folder = $folder;
		$this->name = $name;
		$this->spec = $spec;
	}
}

class ExportVmRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference

	function __construct($_this = null) {
		$this->_this = $_this;
	}
}

class MarkAsTemplateRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference

	function __construct($_this = null) {
		$this->_this = $_this;
	}
}

class MarkAsVirtualMachineRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $pool; //ManagedObjectReference
	public $host; //ManagedObjectReference

	function __construct($_this = null, $pool = null, $host = null) {
		$this->_this = $_this;
		$this->pool = $pool;
		$this->host = $host;
	}
}

class UnregisterVMRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference

	function __construct($_this = null) {
		$this->_this = $_this;
	}
}

class ResetGuestInformationRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference

	function __construct($_this = null) {
		$this->_this = $_this;
	}
}

class MountToolsInstallerRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference

	function __construct($_this = null) {
		$this->_this = $_this;
	}
}

class UnmountToolsInstallerRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference

	function __construct($_this = null) {
		$this->_this = $_this;
	}
}

class UpgradeToolsRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $installerOptions; //string

	function __construct($_this = null, $installerOptions = null) {
		$this->_this = $_this;
		$this->installerOptions = $installerOptions;
	}
}

class AcquireMksTicketRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference

	function __construct($_this = null) {
		$this->_this = $_this;
	}
}

class AcquireTicketRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $ticketType; //string

	function __construct($_this = null, $ticketType = null) {
		$this->_this = $_this;
		$this->ticketType = $ticketType;
	}
}

class SetScreenResolutionRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $width; //int
	public $height; //int

	function __construct($_this = null, $width = null, $height = null) {
		$this->_this = $_this;
		$this->width = $width;
		$this->height = $height;
	}
}

class DefragmentAllDisksRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference

	function __construct($_this = null) {
		$this->_this = $_this;
	}
}

class CreateSecondaryVMRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $host; //ManagedObjectReference

	function __construct($_this = null, $host = null) {
		$this->_this = $_this;
		$this->host = $host;
	}
}

class TurnOffFaultToleranceForVMRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference

	function __construct($_this = null) {
		$this->_this = $_this;
	}
}

class MakePrimaryVMRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $vm; //ManagedObjectReference

	function __construct($_this = null, $vm = null) {
		$this->_this = $_this;
		$this->vm = $vm;
	}
}

class TerminateFaultTolerantVMRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $vm; //ManagedObjectReference

	function __construct($_this = null, $vm = null) {
		$this->_this = $_this;
		$this->vm = $vm;
	}
}

class DisableSecondaryVMRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $vm; //ManagedObjectReference

	function __construct($_this = null, $vm = null) {
		$this->_this = $_this;
		$this->vm = $vm;
	}
}

class EnableSecondaryVMRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $vm; //ManagedObjectReference
	public $host; //ManagedObjectReference

	function __construct($_this = null, $vm = null, $host = null) {
		$this->_this = $_this;
		$this->vm = $vm;
		$this->host = $host;
	}
}

class SetDisplayTopologyRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $displays; //VirtualMachineDisplayTopology

	function __construct($_this = null, $displays = null) {
		$this->_this = $_this;
		$this->displays = $displays;
	}
}

class StartRecordingRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $name; //string
	public $description; //string

	function __construct($_this = null, $name = null, $description = null) {
		$this->_this = $_this;
		$this->name = $name;
		$this->description = $description;
	}
}

class StopRecordingRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference

	function __construct($_this = null) {
		$this->_this = $_this;
	}
}

class StartReplayingRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $replaySnapshot; //ManagedObjectReference

	function __construct($_this = null, $replaySnapshot = null) {
		$this->_this = $_this;
		$this->replaySnapshot = $replaySnapshot;
	}
}

class StopReplayingRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference

	function __construct($_this = null) {
		$this->_this = $_this;
	}
}

class PromoteDisksRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $unlink; //boolean
	public $disks; //VirtualDisk

	function __construct($_this = null, $unlink = null, $disks = null) {
		$this->_this = $_this;
		$this->unlink = $unlink;
		$this->disks = $disks;
	}
}

class CreateScreenshotRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference

	function __construct($_this = null) {
		$this->_this = $_this;
	}
}

class QueryChangedDiskAreasRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $snapshot; //ManagedObjectReference
	public $deviceKey; //int
	public $startOffset; //long
	public $changeId; //string

	function __construct($_this = null, $snapshot = null, $deviceKey = null, $startOffset = null, $changeId = null) {
		$this->_this = $_this;
		$this->snapshot = $snapshot;
		$this->deviceKey = $deviceKey;
		$this->startOffset = $startOffset;
		$this->changeId = $changeId;
	}
}

class QueryUnownedFilesRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference

	function __construct($_this = null) {
		$this->_this = $_this;
	}
}

class reloadVirtualMachineFromPathRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $configurationPath; //string

	function __construct($_this = null, $configurationPath = null) {
		$this->_this = $_this;
		$this->configurationPath = $configurationPath;
	}
}

class QueryFaultToleranceCompatibilityRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference

	function __construct($_this = null) {
		$this->_this = $_this;
	}
}

class RemoveAlarmRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference

	function __construct($_this = null) {
		$this->_this = $_this;
	}
}

class ReconfigureAlarmRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $spec; //AlarmSpec

	function __construct($_this = null, $spec = null) {
		$this->_this = $_this;
		$this->spec = $spec;
	}
}

class CreateAlarmRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $entity; //ManagedObjectReference
	public $spec; //AlarmSpec

	function __construct($_this = null, $entity = null, $spec = null) {
		$this->_this = $_this;
		$this->entity = $entity;
		$this->spec = $spec;
	}
}

class GetAlarmRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $entity; //ManagedObjectReference

	function __construct($_this = null, $entity = null) {
		$this->_this = $_this;
		$this->entity = $entity;
	}
}

class AreAlarmActionsEnabledRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $entity; //ManagedObjectReference

	function __construct($_this = null, $entity = null) {
		$this->_this = $_this;
		$this->entity = $entity;
	}
}

class EnableAlarmActionsRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $entity; //ManagedObjectReference
	public $enabled; //boolean

	function __construct($_this = null, $entity = null, $enabled = null) {
		$this->_this = $_this;
		$this->entity = $entity;
		$this->enabled = $enabled;
	}
}

class GetAlarmStateRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $entity; //ManagedObjectReference

	function __construct($_this = null, $entity = null) {
		$this->_this = $_this;
		$this->entity = $entity;
	}
}

class AcknowledgeAlarmRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $alarm; //ManagedObjectReference
	public $entity; //ManagedObjectReference

	function __construct($_this = null, $alarm = null, $entity = null) {
		$this->_this = $_this;
		$this->alarm = $alarm;
		$this->entity = $entity;
	}
}

class ReconfigureDVPortgroupRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $spec; //DVPortgroupConfigSpec

	function __construct($_this = null, $spec = null) {
		$this->_this = $_this;
		$this->spec = $spec;
	}
}

class QueryAvailableDvsSpecRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference

	function __construct($_this = null) {
		$this->_this = $_this;
	}
}

class QueryCompatibleHostForNewDvsRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $container; //ManagedObjectReference
	public $recursive; //boolean
	public $switchProductSpec; //DistributedVirtualSwitchProductSpec

	function __construct($_this = null, $container = null, $recursive = null, $switchProductSpec = null) {
		$this->_this = $_this;
		$this->container = $container;
		$this->recursive = $recursive;
		$this->switchProductSpec = $switchProductSpec;
	}
}

class QueryCompatibleHostForExistingDvsRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $container; //ManagedObjectReference
	public $recursive; //boolean
	public $dvs; //ManagedObjectReference

	function __construct($_this = null, $container = null, $recursive = null, $dvs = null) {
		$this->_this = $_this;
		$this->container = $container;
		$this->recursive = $recursive;
		$this->dvs = $dvs;
	}
}

class QueryDvsCompatibleHostSpecRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $switchProductSpec; //DistributedVirtualSwitchProductSpec

	function __construct($_this = null, $switchProductSpec = null) {
		$this->_this = $_this;
		$this->switchProductSpec = $switchProductSpec;
	}
}

class QueryDvsFeatureCapabilityRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $switchProductSpec; //DistributedVirtualSwitchProductSpec

	function __construct($_this = null, $switchProductSpec = null) {
		$this->_this = $_this;
		$this->switchProductSpec = $switchProductSpec;
	}
}

class QueryDvsByUuidRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $uuid; //string

	function __construct($_this = null, $uuid = null) {
		$this->_this = $_this;
		$this->uuid = $uuid;
	}
}

class QueryDvsConfigTargetRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $host; //ManagedObjectReference
	public $dvs; //ManagedObjectReference

	function __construct($_this = null, $host = null, $dvs = null) {
		$this->_this = $_this;
		$this->host = $host;
		$this->dvs = $dvs;
	}
}

class QueryDvsCheckCompatibilityRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $hostContainer; //DistributedVirtualSwitchManagerHostContainer
	public $dvsProductSpec; //DistributedVirtualSwitchManagerDvsProductSpec
	public $hostFilterSpec; //DistributedVirtualSwitchManagerHostDvsFilterSpec

	function __construct($_this = null, $hostContainer = null, $dvsProductSpec = null, $hostFilterSpec = null) {
		$this->_this = $_this;
		$this->hostContainer = $hostContainer;
		$this->dvsProductSpec = $dvsProductSpec;
		$this->hostFilterSpec = $hostFilterSpec;
	}
}

class RectifyDvsOnHostRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $hosts; //ManagedObjectReference

	function __construct($_this = null, $hosts = null) {
		$this->_this = $_this;
		$this->hosts = $hosts;
	}
}

class ReadNextEventsRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $maxCount; //int

	function __construct($_this = null, $maxCount = null) {
		$this->_this = $_this;
		$this->maxCount = $maxCount;
	}
}

class ReadPreviousEventsRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $maxCount; //int

	function __construct($_this = null, $maxCount = null) {
		$this->_this = $_this;
		$this->maxCount = $maxCount;
	}
}

class RetrieveArgumentDescriptionRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $eventTypeId; //string

	function __construct($_this = null, $eventTypeId = null) {
		$this->_this = $_this;
		$this->eventTypeId = $eventTypeId;
	}
}

class CreateCollectorForEventsRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $filter; //EventFilterSpec

	function __construct($_this = null, $filter = null) {
		$this->_this = $_this;
		$this->filter = $filter;
	}
}

class LogUserEventRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $entity; //ManagedObjectReference
	public $msg; //string

	function __construct($_this = null, $entity = null, $msg = null) {
		$this->_this = $_this;
		$this->entity = $entity;
		$this->msg = $msg;
	}
}

class QueryEventsRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $filter; //EventFilterSpec

	function __construct($_this = null, $filter = null) {
		$this->_this = $_this;
		$this->filter = $filter;
	}
}

class PostEventRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $eventToPost; //Event
	public $taskInfo; //TaskInfo

	function __construct($_this = null, $eventToPost = null, $taskInfo = null) {
		$this->_this = $_this;
		$this->eventToPost = $eventToPost;
		$this->taskInfo = $taskInfo;
	}
}

class JoinDomainRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $domainName; //string
	public $userName; //string
	public $password; //string

	function __construct($_this = null, $domainName = null, $userName = null, $password = null) {
		$this->_this = $_this;
		$this->domainName = $domainName;
		$this->userName = $userName;
		$this->password = $password;
	}
}

class JoinDomainWithCAMRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $domainName; //string
	public $camServer; //string

	function __construct($_this = null, $domainName = null, $camServer = null) {
		$this->_this = $_this;
		$this->domainName = $domainName;
		$this->camServer = $camServer;
	}
}

class ImportCertificateForCAMRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $certPath; //string
	public $camServer; //string

	function __construct($_this = null, $certPath = null, $camServer = null) {
		$this->_this = $_this;
		$this->certPath = $certPath;
		$this->camServer = $camServer;
	}
}

class LeaveCurrentDomainRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $force; //boolean

	function __construct($_this = null, $force = null) {
		$this->_this = $_this;
		$this->force = $force;
	}
}

class ReconfigureAutostartRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $spec; //HostAutoStartManagerConfig

	function __construct($_this = null, $spec = null) {
		$this->_this = $_this;
		$this->spec = $spec;
	}
}

class AutoStartPowerOnRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference

	function __construct($_this = null) {
		$this->_this = $_this;
	}
}

class AutoStartPowerOffRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference

	function __construct($_this = null) {
		$this->_this = $_this;
	}
}

class QueryBootDevicesRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference

	function __construct($_this = null) {
		$this->_this = $_this;
	}
}

class UpdateBootDeviceRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $key; //string

	function __construct($_this = null, $key = null) {
		$this->_this = $_this;
		$this->key = $key;
	}
}

class ConfigureHostCacheRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $spec; //HostCacheConfigurationSpec

	function __construct($_this = null, $spec = null) {
		$this->_this = $_this;
		$this->spec = $spec;
	}
}

class EnableHyperThreadingRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference

	function __construct($_this = null) {
		$this->_this = $_this;
	}
}

class DisableHyperThreadingRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference

	function __construct($_this = null) {
		$this->_this = $_this;
	}
}

class SearchDatastoreRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $datastorePath; //string
	public $searchSpec; //HostDatastoreBrowserSearchSpec

	function __construct($_this = null, $datastorePath = null, $searchSpec = null) {
		$this->_this = $_this;
		$this->datastorePath = $datastorePath;
		$this->searchSpec = $searchSpec;
	}
}

class SearchDatastoreSubFoldersRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $datastorePath; //string
	public $searchSpec; //HostDatastoreBrowserSearchSpec

	function __construct($_this = null, $datastorePath = null, $searchSpec = null) {
		$this->_this = $_this;
		$this->datastorePath = $datastorePath;
		$this->searchSpec = $searchSpec;
	}
}

class DeleteFileRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $datastorePath; //string

	function __construct($_this = null, $datastorePath = null) {
		$this->_this = $_this;
		$this->datastorePath = $datastorePath;
	}
}

class UpdateLocalSwapDatastoreRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $datastore; //ManagedObjectReference

	function __construct($_this = null, $datastore = null) {
		$this->_this = $_this;
		$this->datastore = $datastore;
	}
}

class QueryAvailableDisksForVmfsRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $datastore; //ManagedObjectReference

	function __construct($_this = null, $datastore = null) {
		$this->_this = $_this;
		$this->datastore = $datastore;
	}
}

class QueryVmfsDatastoreCreateOptionsRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $devicePath; //string
	public $vmfsMajorVersion; //int

	function __construct($_this = null, $devicePath = null, $vmfsMajorVersion = null) {
		$this->_this = $_this;
		$this->devicePath = $devicePath;
		$this->vmfsMajorVersion = $vmfsMajorVersion;
	}
}

class CreateVmfsDatastoreRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $spec; //VmfsDatastoreCreateSpec

	function __construct($_this = null, $spec = null) {
		$this->_this = $_this;
		$this->spec = $spec;
	}
}

class QueryVmfsDatastoreExtendOptionsRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $datastore; //ManagedObjectReference
	public $devicePath; //string
	public $suppressExpandCandidates; //boolean

	function __construct($_this = null, $datastore = null, $devicePath = null, $suppressExpandCandidates = null) {
		$this->_this = $_this;
		$this->datastore = $datastore;
		$this->devicePath = $devicePath;
		$this->suppressExpandCandidates = $suppressExpandCandidates;
	}
}

class QueryVmfsDatastoreExpandOptionsRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $datastore; //ManagedObjectReference

	function __construct($_this = null, $datastore = null) {
		$this->_this = $_this;
		$this->datastore = $datastore;
	}
}

class ExtendVmfsDatastoreRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $datastore; //ManagedObjectReference
	public $spec; //VmfsDatastoreExtendSpec

	function __construct($_this = null, $datastore = null, $spec = null) {
		$this->_this = $_this;
		$this->datastore = $datastore;
		$this->spec = $spec;
	}
}

class ExpandVmfsDatastoreRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $datastore; //ManagedObjectReference
	public $spec; //VmfsDatastoreExpandSpec

	function __construct($_this = null, $datastore = null, $spec = null) {
		$this->_this = $_this;
		$this->datastore = $datastore;
		$this->spec = $spec;
	}
}

class CreateNasDatastoreRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $spec; //HostNasVolumeSpec

	function __construct($_this = null, $spec = null) {
		$this->_this = $_this;
		$this->spec = $spec;
	}
}

class CreateLocalDatastoreRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $name; //string
	public $path; //string

	function __construct($_this = null, $name = null, $path = null) {
		$this->_this = $_this;
		$this->name = $name;
		$this->path = $path;
	}
}

class RemoveDatastoreRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $datastore; //ManagedObjectReference

	function __construct($_this = null, $datastore = null) {
		$this->_this = $_this;
		$this->datastore = $datastore;
	}
}

class ConfigureDatastorePrincipalRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $userName; //string
	public $password; //string

	function __construct($_this = null, $userName = null, $password = null) {
		$this->_this = $_this;
		$this->userName = $userName;
		$this->password = $password;
	}
}

class QueryUnresolvedVmfsVolumesRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference

	function __construct($_this = null) {
		$this->_this = $_this;
	}
}

class ResignatureUnresolvedVmfsVolumeRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $resolutionSpec; //HostUnresolvedVmfsResignatureSpec

	function __construct($_this = null, $resolutionSpec = null) {
		$this->_this = $_this;
		$this->resolutionSpec = $resolutionSpec;
	}
}

class UpdateDateTimeConfigRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $config; //HostDateTimeConfig

	function __construct($_this = null, $config = null) {
		$this->_this = $_this;
		$this->config = $config;
	}
}

class QueryAvailableTimeZonesRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference

	function __construct($_this = null) {
		$this->_this = $_this;
	}
}

class QueryDateTimeRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference

	function __construct($_this = null) {
		$this->_this = $_this;
	}
}

class UpdateDateTimeRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $dateTime; //dateTime

	function __construct($_this = null, $dateTime = null) {
		$this->_this = $_this;
		$this->dateTime = $dateTime;
	}
}

class RefreshDateTimeSystemRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference

	function __construct($_this = null) {
		$this->_this = $_this;
	}
}

class QueryAvailablePartitionRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference

	function __construct($_this = null) {
		$this->_this = $_this;
	}
}

class SelectActivePartitionRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $partition; //HostScsiDiskPartition

	function __construct($_this = null, $partition = null) {
		$this->_this = $_this;
		$this->partition = $partition;
	}
}

class QueryPartitionCreateOptionsRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $storageType; //string
	public $diagnosticType; //string

	function __construct($_this = null, $storageType = null, $diagnosticType = null) {
		$this->_this = $_this;
		$this->storageType = $storageType;
		$this->diagnosticType = $diagnosticType;
	}
}

class QueryPartitionCreateDescRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $diskUuid; //string
	public $diagnosticType; //string

	function __construct($_this = null, $diskUuid = null, $diagnosticType = null) {
		$this->_this = $_this;
		$this->diskUuid = $diskUuid;
		$this->diagnosticType = $diagnosticType;
	}
}

class CreateDiagnosticPartitionRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $spec; //HostDiagnosticPartitionCreateSpec

	function __construct($_this = null, $spec = null) {
		$this->_this = $_this;
		$this->spec = $spec;
	}
}

class EsxAgentHostManagerUpdateConfigRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $configInfo; //HostEsxAgentHostManagerConfigInfo

	function __construct($_this = null, $configInfo = null) {
		$this->_this = $_this;
		$this->configInfo = $configInfo;
	}
}

class UpdateDefaultPolicyRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $defaultPolicy; //HostFirewallDefaultPolicy

	function __construct($_this = null, $defaultPolicy = null) {
		$this->_this = $_this;
		$this->defaultPolicy = $defaultPolicy;
	}
}

class EnableRulesetRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $id; //string

	function __construct($_this = null, $id = null) {
		$this->_this = $_this;
		$this->id = $id;
	}
}

class DisableRulesetRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $id; //string

	function __construct($_this = null, $id = null) {
		$this->_this = $_this;
		$this->id = $id;
	}
}

class UpdateRulesetRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $id; //string
	public $spec; //HostFirewallRulesetRulesetSpec

	function __construct($_this = null, $id = null, $spec = null) {
		$this->_this = $_this;
		$this->id = $id;
		$this->spec = $spec;
	}
}

class RefreshFirewallRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference

	function __construct($_this = null) {
		$this->_this = $_this;
	}
}

class ResetFirmwareToFactoryDefaultsRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference

	function __construct($_this = null) {
		$this->_this = $_this;
	}
}

class BackupFirmwareConfigurationRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference

	function __construct($_this = null) {
		$this->_this = $_this;
	}
}

class QueryFirmwareConfigUploadURLRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference

	function __construct($_this = null) {
		$this->_this = $_this;
	}
}

class RestoreFirmwareConfigurationRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $force; //boolean

	function __construct($_this = null, $force = null) {
		$this->_this = $_this;
		$this->force = $force;
	}
}

class RefreshHealthStatusSystemRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference

	function __construct($_this = null) {
		$this->_this = $_this;
	}
}

class ResetSystemHealthInfoRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference

	function __construct($_this = null) {
		$this->_this = $_this;
	}
}

class HostImageConfigGetAcceptanceRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference

	function __construct($_this = null) {
		$this->_this = $_this;
	}
}

class HostImageConfigGetProfileRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference

	function __construct($_this = null) {
		$this->_this = $_this;
	}
}

class UpdateHostImageAcceptanceLevelRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $newAcceptanceLevel; //string

	function __construct($_this = null, $newAcceptanceLevel = null) {
		$this->_this = $_this;
		$this->newAcceptanceLevel = $newAcceptanceLevel;
	}
}

class QueryVnicStatusRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $vnicDevice; //string

	function __construct($_this = null, $vnicDevice = null) {
		$this->_this = $_this;
		$this->vnicDevice = $vnicDevice;
	}
}

class QueryPnicStatusRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $pnicDevice; //string

	function __construct($_this = null, $pnicDevice = null) {
		$this->_this = $_this;
		$this->pnicDevice = $pnicDevice;
	}
}

class QueryBoundVnicsRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $iScsiHbaName; //string

	function __construct($_this = null, $iScsiHbaName = null) {
		$this->_this = $_this;
		$this->iScsiHbaName = $iScsiHbaName;
	}
}

class QueryCandidateNicsRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $iScsiHbaName; //string

	function __construct($_this = null, $iScsiHbaName = null) {
		$this->_this = $_this;
		$this->iScsiHbaName = $iScsiHbaName;
	}
}

class BindVnicRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $iScsiHbaName; //string
	public $vnicDevice; //string

	function __construct($_this = null, $iScsiHbaName = null, $vnicDevice = null) {
		$this->_this = $_this;
		$this->iScsiHbaName = $iScsiHbaName;
		$this->vnicDevice = $vnicDevice;
	}
}

class UnbindVnicRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $iScsiHbaName; //string
	public $vnicDevice; //string
	public $force; //boolean

	function __construct($_this = null, $iScsiHbaName = null, $vnicDevice = null, $force = null) {
		$this->_this = $_this;
		$this->iScsiHbaName = $iScsiHbaName;
		$this->vnicDevice = $vnicDevice;
		$this->force = $force;
	}
}

class QueryMigrationDependenciesRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $pnicDevice; //string

	function __construct($_this = null, $pnicDevice = null) {
		$this->_this = $_this;
		$this->pnicDevice = $pnicDevice;
	}
}

class QueryModulesRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference

	function __construct($_this = null) {
		$this->_this = $_this;
	}
}

class UpdateModuleOptionStringRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $name; //string
	public $options; //string

	function __construct($_this = null, $name = null, $options = null) {
		$this->_this = $_this;
		$this->name = $name;
		$this->options = $options;
	}
}

class QueryConfiguredModuleOptionStringRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $name; //string

	function __construct($_this = null, $name = null) {
		$this->_this = $_this;
		$this->name = $name;
	}
}

class CreateUserRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $user; //HostAccountSpec

	function __construct($_this = null, $user = null) {
		$this->_this = $_this;
		$this->user = $user;
	}
}

class UpdateUserRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $user; //HostAccountSpec

	function __construct($_this = null, $user = null) {
		$this->_this = $_this;
		$this->user = $user;
	}
}

class CreateGroupRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $group; //HostAccountSpec

	function __construct($_this = null, $group = null) {
		$this->_this = $_this;
		$this->group = $group;
	}
}

class RemoveUserRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $userName; //string

	function __construct($_this = null, $userName = null) {
		$this->_this = $_this;
		$this->userName = $userName;
	}
}

class RemoveGroupRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $groupName; //string

	function __construct($_this = null, $groupName = null) {
		$this->_this = $_this;
		$this->groupName = $groupName;
	}
}

class AssignUserToGroupRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $user; //string
	public $group; //string

	function __construct($_this = null, $user = null, $group = null) {
		$this->_this = $_this;
		$this->user = $user;
		$this->group = $group;
	}
}

class UnassignUserFromGroupRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $user; //string
	public $group; //string

	function __construct($_this = null, $user = null, $group = null) {
		$this->_this = $_this;
		$this->user = $user;
		$this->group = $group;
	}
}

class ReconfigureServiceConsoleReservationRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $cfgBytes; //long

	function __construct($_this = null, $cfgBytes = null) {
		$this->_this = $_this;
		$this->cfgBytes = $cfgBytes;
	}
}

class ReconfigureVirtualMachineReservationRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $spec; //VirtualMachineMemoryReservationSpec

	function __construct($_this = null, $spec = null) {
		$this->_this = $_this;
		$this->spec = $spec;
	}
}

class UpdateNetworkConfigRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $config; //HostNetworkConfig
	public $changeMode; //string

	function __construct($_this = null, $config = null, $changeMode = null) {
		$this->_this = $_this;
		$this->config = $config;
		$this->changeMode = $changeMode;
	}
}

class UpdateDnsConfigRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $config; //HostDnsConfig

	function __construct($_this = null, $config = null) {
		$this->_this = $_this;
		$this->config = $config;
	}
}

class UpdateIpRouteConfigRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $config; //HostIpRouteConfig

	function __construct($_this = null, $config = null) {
		$this->_this = $_this;
		$this->config = $config;
	}
}

class UpdateConsoleIpRouteConfigRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $config; //HostIpRouteConfig

	function __construct($_this = null, $config = null) {
		$this->_this = $_this;
		$this->config = $config;
	}
}

class UpdateIpRouteTableConfigRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $config; //HostIpRouteTableConfig

	function __construct($_this = null, $config = null) {
		$this->_this = $_this;
		$this->config = $config;
	}
}

class AddVirtualSwitchRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $vswitchName; //string
	public $spec; //HostVirtualSwitchSpec

	function __construct($_this = null, $vswitchName = null, $spec = null) {
		$this->_this = $_this;
		$this->vswitchName = $vswitchName;
		$this->spec = $spec;
	}
}

class RemoveVirtualSwitchRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $vswitchName; //string

	function __construct($_this = null, $vswitchName = null) {
		$this->_this = $_this;
		$this->vswitchName = $vswitchName;
	}
}

class UpdateVirtualSwitchRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $vswitchName; //string
	public $spec; //HostVirtualSwitchSpec

	function __construct($_this = null, $vswitchName = null, $spec = null) {
		$this->_this = $_this;
		$this->vswitchName = $vswitchName;
		$this->spec = $spec;
	}
}

class AddPortGroupRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $portgrp; //HostPortGroupSpec

	function __construct($_this = null, $portgrp = null) {
		$this->_this = $_this;
		$this->portgrp = $portgrp;
	}
}

class RemovePortGroupRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $pgName; //string

	function __construct($_this = null, $pgName = null) {
		$this->_this = $_this;
		$this->pgName = $pgName;
	}
}

class UpdatePortGroupRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $pgName; //string
	public $portgrp; //HostPortGroupSpec

	function __construct($_this = null, $pgName = null, $portgrp = null) {
		$this->_this = $_this;
		$this->pgName = $pgName;
		$this->portgrp = $portgrp;
	}
}

class UpdatePhysicalNicLinkSpeedRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $device; //string
	public $linkSpeed; //PhysicalNicLinkInfo

	function __construct($_this = null, $device = null, $linkSpeed = null) {
		$this->_this = $_this;
		$this->device = $device;
		$this->linkSpeed = $linkSpeed;
	}
}

class QueryNetworkHintRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $device; //string

	function __construct($_this = null, $device = null) {
		$this->_this = $_this;
		$this->device = $device;
	}
}

class AddVirtualNicRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $portgroup; //string
	public $nic; //HostVirtualNicSpec

	function __construct($_this = null, $portgroup = null, $nic = null) {
		$this->_this = $_this;
		$this->portgroup = $portgroup;
		$this->nic = $nic;
	}
}

class RemoveVirtualNicRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $device; //string

	function __construct($_this = null, $device = null) {
		$this->_this = $_this;
		$this->device = $device;
	}
}

class UpdateVirtualNicRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $device; //string
	public $nic; //HostVirtualNicSpec

	function __construct($_this = null, $device = null, $nic = null) {
		$this->_this = $_this;
		$this->device = $device;
		$this->nic = $nic;
	}
}

class AddServiceConsoleVirtualNicRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $portgroup; //string
	public $nic; //HostVirtualNicSpec

	function __construct($_this = null, $portgroup = null, $nic = null) {
		$this->_this = $_this;
		$this->portgroup = $portgroup;
		$this->nic = $nic;
	}
}

class RemoveServiceConsoleVirtualNicRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $device; //string

	function __construct($_this = null, $device = null) {
		$this->_this = $_this;
		$this->device = $device;
	}
}

class UpdateServiceConsoleVirtualNicRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $device; //string
	public $nic; //HostVirtualNicSpec

	function __construct($_this = null, $device = null, $nic = null) {
		$this->_this = $_this;
		$this->device = $device;
		$this->nic = $nic;
	}
}

class RestartServiceConsoleVirtualNicRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $device; //string

	function __construct($_this = null, $device = null) {
		$this->_this = $_this;
		$this->device = $device;
	}
}

class RefreshNetworkSystemRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference

	function __construct($_this = null) {
		$this->_this = $_this;
	}
}

class CheckHostPatchRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $metaUrls; //string
	public $bundleUrls; //string
	public $spec; //HostPatchManagerPatchManagerOperationSpec

	function __construct($_this = null, $metaUrls = null, $bundleUrls = null, $spec = null) {
		$this->_this = $_this;
		$this->metaUrls = $metaUrls;
		$this->bundleUrls = $bundleUrls;
		$this->spec = $spec;
	}
}

class ScanHostPatchRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $repository; //HostPatchManagerLocator
	public $updateID; //string

	function __construct($_this = null, $repository = null, $updateID = null) {
		$this->_this = $_this;
		$this->repository = $repository;
		$this->updateID = $updateID;
	}
}

class ScanHostPatchV2RequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $metaUrls; //string
	public $bundleUrls; //string
	public $spec; //HostPatchManagerPatchManagerOperationSpec

	function __construct($_this = null, $metaUrls = null, $bundleUrls = null, $spec = null) {
		$this->_this = $_this;
		$this->metaUrls = $metaUrls;
		$this->bundleUrls = $bundleUrls;
		$this->spec = $spec;
	}
}

class StageHostPatchRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $metaUrls; //string
	public $bundleUrls; //string
	public $vibUrls; //string
	public $spec; //HostPatchManagerPatchManagerOperationSpec

	function __construct($_this = null, $metaUrls = null, $bundleUrls = null, $vibUrls = null, $spec = null) {
		$this->_this = $_this;
		$this->metaUrls = $metaUrls;
		$this->bundleUrls = $bundleUrls;
		$this->vibUrls = $vibUrls;
		$this->spec = $spec;
	}
}

class InstallHostPatchRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $repository; //HostPatchManagerLocator
	public $updateID; //string
	public $force; //boolean

	function __construct($_this = null, $repository = null, $updateID = null, $force = null) {
		$this->_this = $_this;
		$this->repository = $repository;
		$this->updateID = $updateID;
		$this->force = $force;
	}
}

class InstallHostPatchV2RequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $metaUrls; //string
	public $bundleUrls; //string
	public $vibUrls; //string
	public $spec; //HostPatchManagerPatchManagerOperationSpec

	function __construct($_this = null, $metaUrls = null, $bundleUrls = null, $vibUrls = null, $spec = null) {
		$this->_this = $_this;
		$this->metaUrls = $metaUrls;
		$this->bundleUrls = $bundleUrls;
		$this->vibUrls = $vibUrls;
		$this->spec = $spec;
	}
}

class UninstallHostPatchRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $bulletinIds; //string
	public $spec; //HostPatchManagerPatchManagerOperationSpec

	function __construct($_this = null, $bulletinIds = null, $spec = null) {
		$this->_this = $_this;
		$this->bulletinIds = $bulletinIds;
		$this->spec = $spec;
	}
}

class QueryHostPatchRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $spec; //HostPatchManagerPatchManagerOperationSpec

	function __construct($_this = null, $spec = null) {
		$this->_this = $_this;
		$this->spec = $spec;
	}
}

class RefreshRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference

	function __construct($_this = null) {
		$this->_this = $_this;
	}
}

class UpdatePassthruConfigRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $config; //HostPciPassthruConfig

	function __construct($_this = null, $config = null) {
		$this->_this = $_this;
		$this->config = $config;
	}
}

class ConfigurePowerPolicyRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $key; //int

	function __construct($_this = null, $key = null) {
		$this->_this = $_this;
		$this->key = $key;
	}
}

class UpdateServicePolicyRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $id; //string
	public $policy; //string

	function __construct($_this = null, $id = null, $policy = null) {
		$this->_this = $_this;
		$this->id = $id;
		$this->policy = $policy;
	}
}

class StartServiceRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $id; //string

	function __construct($_this = null, $id = null) {
		$this->_this = $_this;
		$this->id = $id;
	}
}

class StopServiceRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $id; //string

	function __construct($_this = null, $id = null) {
		$this->_this = $_this;
		$this->id = $id;
	}
}

class RestartServiceRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $id; //string

	function __construct($_this = null, $id = null) {
		$this->_this = $_this;
		$this->id = $id;
	}
}

class UninstallServiceRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $id; //string

	function __construct($_this = null, $id = null) {
		$this->_this = $_this;
		$this->id = $id;
	}
}

class RefreshServicesRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference

	function __construct($_this = null) {
		$this->_this = $_this;
	}
}

class ReconfigureSnmpAgentRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $spec; //HostSnmpConfigSpec

	function __construct($_this = null, $spec = null) {
		$this->_this = $_this;
		$this->spec = $spec;
	}
}

class SendTestNotificationRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference

	function __construct($_this = null) {
		$this->_this = $_this;
	}
}

class RetrieveDiskPartitionInfoRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $devicePath; //string

	function __construct($_this = null, $devicePath = null) {
		$this->_this = $_this;
		$this->devicePath = $devicePath;
	}
}

class ComputeDiskPartitionInfoRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $devicePath; //string
	public $layout; //HostDiskPartitionLayout
	public $partitionFormat; //string

	function __construct($_this = null, $devicePath = null, $layout = null, $partitionFormat = null) {
		$this->_this = $_this;
		$this->devicePath = $devicePath;
		$this->layout = $layout;
		$this->partitionFormat = $partitionFormat;
	}
}

class ComputeDiskPartitionInfoForResizeRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $partition; //HostScsiDiskPartition
	public $blockRange; //HostDiskPartitionBlockRange
	public $partitionFormat; //string

	function __construct($_this = null, $partition = null, $blockRange = null, $partitionFormat = null) {
		$this->_this = $_this;
		$this->partition = $partition;
		$this->blockRange = $blockRange;
		$this->partitionFormat = $partitionFormat;
	}
}

class UpdateDiskPartitionsRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $devicePath; //string
	public $spec; //HostDiskPartitionSpec

	function __construct($_this = null, $devicePath = null, $spec = null) {
		$this->_this = $_this;
		$this->devicePath = $devicePath;
		$this->spec = $spec;
	}
}

class FormatVmfsRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $createSpec; //HostVmfsSpec

	function __construct($_this = null, $createSpec = null) {
		$this->_this = $_this;
		$this->createSpec = $createSpec;
	}
}

class MountVmfsVolumeRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $vmfsUuid; //string

	function __construct($_this = null, $vmfsUuid = null) {
		$this->_this = $_this;
		$this->vmfsUuid = $vmfsUuid;
	}
}

class UnmountVmfsVolumeRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $vmfsUuid; //string

	function __construct($_this = null, $vmfsUuid = null) {
		$this->_this = $_this;
		$this->vmfsUuid = $vmfsUuid;
	}
}

class RescanVmfsRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference

	function __construct($_this = null) {
		$this->_this = $_this;
	}
}

class AttachVmfsExtentRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $vmfsPath; //string
	public $extent; //HostScsiDiskPartition

	function __construct($_this = null, $vmfsPath = null, $extent = null) {
		$this->_this = $_this;
		$this->vmfsPath = $vmfsPath;
		$this->extent = $extent;
	}
}

class ExpandVmfsExtentRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $vmfsPath; //string
	public $extent; //HostScsiDiskPartition

	function __construct($_this = null, $vmfsPath = null, $extent = null) {
		$this->_this = $_this;
		$this->vmfsPath = $vmfsPath;
		$this->extent = $extent;
	}
}

class UpgradeVmfsRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $vmfsPath; //string

	function __construct($_this = null, $vmfsPath = null) {
		$this->_this = $_this;
		$this->vmfsPath = $vmfsPath;
	}
}

class UpgradeVmLayoutRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference

	function __construct($_this = null) {
		$this->_this = $_this;
	}
}

class QueryUnresolvedVmfsVolumeRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference

	function __construct($_this = null) {
		$this->_this = $_this;
	}
}

class ResolveMultipleUnresolvedVmfsVolumesRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $resolutionSpec; //HostUnresolvedVmfsResolutionSpec

	function __construct($_this = null, $resolutionSpec = null) {
		$this->_this = $_this;
		$this->resolutionSpec = $resolutionSpec;
	}
}

class UnmountForceMountedVmfsVolumeRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $vmfsUuid; //string

	function __construct($_this = null, $vmfsUuid = null) {
		$this->_this = $_this;
		$this->vmfsUuid = $vmfsUuid;
	}
}

class RescanHbaRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $hbaDevice; //string

	function __construct($_this = null, $hbaDevice = null) {
		$this->_this = $_this;
		$this->hbaDevice = $hbaDevice;
	}
}

class RescanAllHbaRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference

	function __construct($_this = null) {
		$this->_this = $_this;
	}
}

class UpdateSoftwareInternetScsiEnabledRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $enabled; //boolean

	function __construct($_this = null, $enabled = null) {
		$this->_this = $_this;
		$this->enabled = $enabled;
	}
}

class UpdateInternetScsiDiscoveryPropertiesRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $iScsiHbaDevice; //string
	public $discoveryProperties; //HostInternetScsiHbaDiscoveryProperties

	function __construct($_this = null, $iScsiHbaDevice = null, $discoveryProperties = null) {
		$this->_this = $_this;
		$this->iScsiHbaDevice = $iScsiHbaDevice;
		$this->discoveryProperties = $discoveryProperties;
	}
}

class UpdateInternetScsiAuthenticationPropertiesRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $iScsiHbaDevice; //string
	public $authenticationProperties; //HostInternetScsiHbaAuthenticationProperties
	public $targetSet; //HostInternetScsiHbaTargetSet

	function __construct($_this = null, $iScsiHbaDevice = null, $authenticationProperties = null, $targetSet = null) {
		$this->_this = $_this;
		$this->iScsiHbaDevice = $iScsiHbaDevice;
		$this->authenticationProperties = $authenticationProperties;
		$this->targetSet = $targetSet;
	}
}

class UpdateInternetScsiDigestPropertiesRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $iScsiHbaDevice; //string
	public $targetSet; //HostInternetScsiHbaTargetSet
	public $digestProperties; //HostInternetScsiHbaDigestProperties

	function __construct($_this = null, $iScsiHbaDevice = null, $targetSet = null, $digestProperties = null) {
		$this->_this = $_this;
		$this->iScsiHbaDevice = $iScsiHbaDevice;
		$this->targetSet = $targetSet;
		$this->digestProperties = $digestProperties;
	}
}

class UpdateInternetScsiAdvancedOptionsRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $iScsiHbaDevice; //string
	public $targetSet; //HostInternetScsiHbaTargetSet
	public $options; //HostInternetScsiHbaParamValue

	function __construct($_this = null, $iScsiHbaDevice = null, $targetSet = null, $options = null) {
		$this->_this = $_this;
		$this->iScsiHbaDevice = $iScsiHbaDevice;
		$this->targetSet = $targetSet;
		$this->options = $options;
	}
}

class UpdateInternetScsiIPPropertiesRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $iScsiHbaDevice; //string
	public $ipProperties; //HostInternetScsiHbaIPProperties

	function __construct($_this = null, $iScsiHbaDevice = null, $ipProperties = null) {
		$this->_this = $_this;
		$this->iScsiHbaDevice = $iScsiHbaDevice;
		$this->ipProperties = $ipProperties;
	}
}

class UpdateInternetScsiNameRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $iScsiHbaDevice; //string
	public $iScsiName; //string

	function __construct($_this = null, $iScsiHbaDevice = null, $iScsiName = null) {
		$this->_this = $_this;
		$this->iScsiHbaDevice = $iScsiHbaDevice;
		$this->iScsiName = $iScsiName;
	}
}

class UpdateInternetScsiAliasRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $iScsiHbaDevice; //string
	public $iScsiAlias; //string

	function __construct($_this = null, $iScsiHbaDevice = null, $iScsiAlias = null) {
		$this->_this = $_this;
		$this->iScsiHbaDevice = $iScsiHbaDevice;
		$this->iScsiAlias = $iScsiAlias;
	}
}

class AddInternetScsiSendTargetsRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $iScsiHbaDevice; //string
	public $targets; //HostInternetScsiHbaSendTarget

	function __construct($_this = null, $iScsiHbaDevice = null, $targets = null) {
		$this->_this = $_this;
		$this->iScsiHbaDevice = $iScsiHbaDevice;
		$this->targets = $targets;
	}
}

class RemoveInternetScsiSendTargetsRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $iScsiHbaDevice; //string
	public $targets; //HostInternetScsiHbaSendTarget

	function __construct($_this = null, $iScsiHbaDevice = null, $targets = null) {
		$this->_this = $_this;
		$this->iScsiHbaDevice = $iScsiHbaDevice;
		$this->targets = $targets;
	}
}

class AddInternetScsiStaticTargetsRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $iScsiHbaDevice; //string
	public $targets; //HostInternetScsiHbaStaticTarget

	function __construct($_this = null, $iScsiHbaDevice = null, $targets = null) {
		$this->_this = $_this;
		$this->iScsiHbaDevice = $iScsiHbaDevice;
		$this->targets = $targets;
	}
}

class RemoveInternetScsiStaticTargetsRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $iScsiHbaDevice; //string
	public $targets; //HostInternetScsiHbaStaticTarget

	function __construct($_this = null, $iScsiHbaDevice = null, $targets = null) {
		$this->_this = $_this;
		$this->iScsiHbaDevice = $iScsiHbaDevice;
		$this->targets = $targets;
	}
}

class EnableMultipathPathRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $pathName; //string

	function __construct($_this = null, $pathName = null) {
		$this->_this = $_this;
		$this->pathName = $pathName;
	}
}

class DisableMultipathPathRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $pathName; //string

	function __construct($_this = null, $pathName = null) {
		$this->_this = $_this;
		$this->pathName = $pathName;
	}
}

class SetMultipathLunPolicyRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $lunId; //string
	public $policy; //HostMultipathInfoLogicalUnitPolicy

	function __construct($_this = null, $lunId = null, $policy = null) {
		$this->_this = $_this;
		$this->lunId = $lunId;
		$this->policy = $policy;
	}
}

class QueryPathSelectionPolicyOptionsRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference

	function __construct($_this = null) {
		$this->_this = $_this;
	}
}

class QueryStorageArrayTypePolicyOptionsRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference

	function __construct($_this = null) {
		$this->_this = $_this;
	}
}

class UpdateScsiLunDisplayNameRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $lunUuid; //string
	public $displayName; //string

	function __construct($_this = null, $lunUuid = null, $displayName = null) {
		$this->_this = $_this;
		$this->lunUuid = $lunUuid;
		$this->displayName = $displayName;
	}
}

class DetachScsiLunRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $lunUuid; //string

	function __construct($_this = null, $lunUuid = null) {
		$this->_this = $_this;
		$this->lunUuid = $lunUuid;
	}
}

class AttachScsiLunRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $lunUuid; //string

	function __construct($_this = null, $lunUuid = null) {
		$this->_this = $_this;
		$this->lunUuid = $lunUuid;
	}
}

class RefreshStorageSystemRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference

	function __construct($_this = null) {
		$this->_this = $_this;
	}
}

class DiscoverFcoeHbasRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $fcoeSpec; //FcoeConfigFcoeSpecification

	function __construct($_this = null, $fcoeSpec = null) {
		$this->_this = $_this;
		$this->fcoeSpec = $fcoeSpec;
	}
}

class MarkForRemovalRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $hbaName; //string
	public $remove; //boolean

	function __construct($_this = null, $hbaName = null, $remove = null) {
		$this->_this = $_this;
		$this->hbaName = $hbaName;
		$this->remove = $remove;
	}
}

class UpdateIpConfigRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $ipConfig; //HostIpConfig

	function __construct($_this = null, $ipConfig = null) {
		$this->_this = $_this;
		$this->ipConfig = $ipConfig;
	}
}

class SelectVnicRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $device; //string

	function __construct($_this = null, $device = null) {
		$this->_this = $_this;
		$this->device = $device;
	}
}

class DeselectVnicRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference

	function __construct($_this = null) {
		$this->_this = $_this;
	}
}

class QueryNetConfigRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $nicType; //string

	function __construct($_this = null, $nicType = null) {
		$this->_this = $_this;
		$this->nicType = $nicType;
	}
}

class SelectVnicForNicTypeRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $nicType; //string
	public $device; //string

	function __construct($_this = null, $nicType = null, $device = null) {
		$this->_this = $_this;
		$this->nicType = $nicType;
		$this->device = $device;
	}
}

class DeselectVnicForNicTypeRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $nicType; //string
	public $device; //string

	function __construct($_this = null, $nicType = null, $device = null) {
		$this->_this = $_this;
		$this->nicType = $nicType;
		$this->device = $device;
	}
}

class QueryOptionsRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $name; //string

	function __construct($_this = null, $name = null) {
		$this->_this = $_this;
		$this->name = $name;
	}
}

class UpdateOptionsRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $changedValue; //OptionValue

	function __construct($_this = null, $changedValue = null) {
		$this->_this = $_this;
		$this->changedValue = $changedValue;
	}
}

class CheckComplianceRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $profile; //ManagedObjectReference
	public $entity; //ManagedObjectReference

	function __construct($_this = null, $profile = null, $entity = null) {
		$this->_this = $_this;
		$this->profile = $profile;
		$this->entity = $entity;
	}
}

class QueryComplianceStatusRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $profile; //ManagedObjectReference
	public $entity; //ManagedObjectReference

	function __construct($_this = null, $profile = null, $entity = null) {
		$this->_this = $_this;
		$this->profile = $profile;
		$this->entity = $entity;
	}
}

class ClearComplianceStatusRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $profile; //ManagedObjectReference
	public $entity; //ManagedObjectReference

	function __construct($_this = null, $profile = null, $entity = null) {
		$this->_this = $_this;
		$this->profile = $profile;
		$this->entity = $entity;
	}
}

class QueryExpressionMetadataRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $expressionName; //string
	public $profile; //ManagedObjectReference

	function __construct($_this = null, $expressionName = null, $profile = null) {
		$this->_this = $_this;
		$this->expressionName = $expressionName;
		$this->profile = $profile;
	}
}

class RetrieveDescriptionRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference

	function __construct($_this = null) {
		$this->_this = $_this;
	}
}

class DestroyProfileRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference

	function __construct($_this = null) {
		$this->_this = $_this;
	}
}

class AssociateProfileRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $entity; //ManagedObjectReference

	function __construct($_this = null, $entity = null) {
		$this->_this = $_this;
		$this->entity = $entity;
	}
}

class DissociateProfileRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $entity; //ManagedObjectReference

	function __construct($_this = null, $entity = null) {
		$this->_this = $_this;
		$this->entity = $entity;
	}
}

class CheckProfileComplianceRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $entity; //ManagedObjectReference

	function __construct($_this = null, $entity = null) {
		$this->_this = $_this;
		$this->entity = $entity;
	}
}

class ExportProfileRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference

	function __construct($_this = null) {
		$this->_this = $_this;
	}
}

class CreateProfileRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $createSpec; //ProfileCreateSpec

	function __construct($_this = null, $createSpec = null) {
		$this->_this = $_this;
		$this->createSpec = $createSpec;
	}
}

class QueryPolicyMetadataRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $policyName; //string
	public $profile; //ManagedObjectReference

	function __construct($_this = null, $policyName = null, $profile = null) {
		$this->_this = $_this;
		$this->policyName = $policyName;
		$this->profile = $profile;
	}
}

class FindAssociatedProfileRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $entity; //ManagedObjectReference

	function __construct($_this = null, $entity = null) {
		$this->_this = $_this;
		$this->entity = $entity;
	}
}

class UpdateClusterProfileRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $config; //ClusterProfileConfigSpec

	function __construct($_this = null, $config = null) {
		$this->_this = $_this;
		$this->config = $config;
	}
}

class UpdateReferenceHostRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $host; //ManagedObjectReference

	function __construct($_this = null, $host = null) {
		$this->_this = $_this;
		$this->host = $host;
	}
}

class UpdateHostProfileRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $config; //HostProfileConfigSpec

	function __construct($_this = null, $config = null) {
		$this->_this = $_this;
		$this->config = $config;
	}
}

class ExecuteHostProfileRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $host; //ManagedObjectReference
	public $deferredParam; //ProfileDeferredPolicyOptionParameter

	function __construct($_this = null, $host = null, $deferredParam = null) {
		$this->_this = $_this;
		$this->host = $host;
		$this->deferredParam = $deferredParam;
	}
}

class ApplyHostConfigRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $host; //ManagedObjectReference
	public $configSpec; //HostConfigSpec
	public $userInput; //ProfileDeferredPolicyOptionParameter

	function __construct($_this = null, $host = null, $configSpec = null, $userInput = null) {
		$this->_this = $_this;
		$this->host = $host;
		$this->configSpec = $configSpec;
		$this->userInput = $userInput;
	}
}

class GenerateConfigTaskListRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $configSpec; //HostConfigSpec
	public $host; //ManagedObjectReference

	function __construct($_this = null, $configSpec = null, $host = null) {
		$this->_this = $_this;
		$this->configSpec = $configSpec;
		$this->host = $host;
	}
}

class QueryHostProfileMetadataRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $profileName; //string
	public $profile; //ManagedObjectReference

	function __construct($_this = null, $profileName = null, $profile = null) {
		$this->_this = $_this;
		$this->profileName = $profileName;
		$this->profile = $profile;
	}
}

class QueryProfileStructureRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $profile; //ManagedObjectReference

	function __construct($_this = null, $profile = null) {
		$this->_this = $_this;
		$this->profile = $profile;
	}
}

class CreateDefaultProfileRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $profileType; //string
	public $profileTypeName; //string
	public $profile; //ManagedObjectReference

	function __construct($_this = null, $profileType = null, $profileTypeName = null, $profile = null) {
		$this->_this = $_this;
		$this->profileType = $profileType;
		$this->profileTypeName = $profileTypeName;
		$this->profile = $profile;
	}
}

class UpdateAnswerFileRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $host; //ManagedObjectReference
	public $configSpec; //AnswerFileCreateSpec

	function __construct($_this = null, $host = null, $configSpec = null) {
		$this->_this = $_this;
		$this->host = $host;
		$this->configSpec = $configSpec;
	}
}

class RetrieveAnswerFileRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $host; //ManagedObjectReference

	function __construct($_this = null, $host = null) {
		$this->_this = $_this;
		$this->host = $host;
	}
}

class ExportAnswerFileRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $host; //ManagedObjectReference

	function __construct($_this = null, $host = null) {
		$this->_this = $_this;
		$this->host = $host;
	}
}

class CheckAnswerFileStatusRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $host; //ManagedObjectReference

	function __construct($_this = null, $host = null) {
		$this->_this = $_this;
		$this->host = $host;
	}
}

class QueryAnswerFileStatusRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $host; //ManagedObjectReference

	function __construct($_this = null, $host = null) {
		$this->_this = $_this;
		$this->host = $host;
	}
}

class RemoveScheduledTaskRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference

	function __construct($_this = null) {
		$this->_this = $_this;
	}
}

class ReconfigureScheduledTaskRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $spec; //ScheduledTaskSpec

	function __construct($_this = null, $spec = null) {
		$this->_this = $_this;
		$this->spec = $spec;
	}
}

class RunScheduledTaskRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference

	function __construct($_this = null) {
		$this->_this = $_this;
	}
}

class CreateScheduledTaskRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $entity; //ManagedObjectReference
	public $spec; //ScheduledTaskSpec

	function __construct($_this = null, $entity = null, $spec = null) {
		$this->_this = $_this;
		$this->entity = $entity;
		$this->spec = $spec;
	}
}

class RetrieveEntityScheduledTaskRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $entity; //ManagedObjectReference

	function __construct($_this = null, $entity = null) {
		$this->_this = $_this;
		$this->entity = $entity;
	}
}

class CreateObjectScheduledTaskRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $obj; //ManagedObjectReference
	public $spec; //ScheduledTaskSpec

	function __construct($_this = null, $obj = null, $spec = null) {
		$this->_this = $_this;
		$this->obj = $obj;
		$this->spec = $spec;
	}
}

class RetrieveObjectScheduledTaskRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $obj; //ManagedObjectReference

	function __construct($_this = null, $obj = null) {
		$this->_this = $_this;
		$this->obj = $obj;
	}
}

class OpenInventoryViewFolderRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $entity; //ManagedObjectReference

	function __construct($_this = null, $entity = null) {
		$this->_this = $_this;
		$this->entity = $entity;
	}
}

class CloseInventoryViewFolderRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $entity; //ManagedObjectReference

	function __construct($_this = null, $entity = null) {
		$this->_this = $_this;
		$this->entity = $entity;
	}
}

class ModifyListViewRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $add; //ManagedObjectReference
	public $remove; //ManagedObjectReference

	function __construct($_this = null, $add = null, $remove = null) {
		$this->_this = $_this;
		$this->add = $add;
		$this->remove = $remove;
	}
}

class ResetListViewRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $obj; //ManagedObjectReference

	function __construct($_this = null, $obj = null) {
		$this->_this = $_this;
		$this->obj = $obj;
	}
}

class ResetListViewFromViewRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $view; //ManagedObjectReference

	function __construct($_this = null, $view = null) {
		$this->_this = $_this;
		$this->view = $view;
	}
}

class DestroyViewRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference

	function __construct($_this = null) {
		$this->_this = $_this;
	}
}

class CreateInventoryViewRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference

	function __construct($_this = null) {
		$this->_this = $_this;
	}
}

class CreateContainerViewRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $container; //ManagedObjectReference
	public $type; //string
	public $recursive; //boolean

	function __construct($_this = null, $container = null, $type = null, $recursive = null) {
		$this->_this = $_this;
		$this->container = $container;
		$this->type = $type;
		$this->recursive = $recursive;
	}
}

class CreateListViewRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $obj; //ManagedObjectReference

	function __construct($_this = null, $obj = null) {
		$this->_this = $_this;
		$this->obj = $obj;
	}
}

class CreateListViewFromViewRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $view; //ManagedObjectReference

	function __construct($_this = null, $view = null) {
		$this->_this = $_this;
		$this->view = $view;
	}
}

class RevertToSnapshotRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $host; //ManagedObjectReference
	public $suppressPowerOn; //boolean

	function __construct($_this = null, $host = null, $suppressPowerOn = null) {
		$this->_this = $_this;
		$this->host = $host;
		$this->suppressPowerOn = $suppressPowerOn;
	}
}

class RemoveSnapshotRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $removeChildren; //boolean
	public $consolidate; //boolean

	function __construct($_this = null, $removeChildren = null, $consolidate = null) {
		$this->_this = $_this;
		$this->removeChildren = $removeChildren;
		$this->consolidate = $consolidate;
	}
}

class RenameSnapshotRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $name; //string
	public $description; //string

	function __construct($_this = null, $name = null, $description = null) {
		$this->_this = $_this;
		$this->name = $name;
		$this->description = $description;
	}
}

class CheckCompatibilityRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $vm; //ManagedObjectReference
	public $host; //ManagedObjectReference
	public $pool; //ManagedObjectReference
	public $testType; //string

	function __construct($_this = null, $vm = null, $host = null, $pool = null, $testType = null) {
		$this->_this = $_this;
		$this->vm = $vm;
		$this->host = $host;
		$this->pool = $pool;
		$this->testType = $testType;
	}
}

class QueryVMotionCompatibilityExRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $vm; //ManagedObjectReference
	public $host; //ManagedObjectReference

	function __construct($_this = null, $vm = null, $host = null) {
		$this->_this = $_this;
		$this->vm = $vm;
		$this->host = $host;
	}
}

class CheckMigrateRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $vm; //ManagedObjectReference
	public $host; //ManagedObjectReference
	public $pool; //ManagedObjectReference
	public $state; //VirtualMachinePowerState
	public $testType; //string

	function __construct($_this = null, $vm = null, $host = null, $pool = null, $state = null, $testType = null) {
		$this->_this = $_this;
		$this->vm = $vm;
		$this->host = $host;
		$this->pool = $pool;
		$this->state = $state;
		$this->testType = $testType;
	}
}

class CheckRelocateRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $vm; //ManagedObjectReference
	public $spec; //VirtualMachineRelocateSpec
	public $testType; //string

	function __construct($_this = null, $vm = null, $spec = null, $testType = null) {
		$this->_this = $_this;
		$this->vm = $vm;
		$this->spec = $spec;
		$this->testType = $testType;
	}
}

class ValidateCredentialsInGuestRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $vm; //ManagedObjectReference
	public $auth; //GuestAuthentication

	function __construct($_this = null, $vm = null, $auth = null) {
		$this->_this = $_this;
		$this->vm = $vm;
		$this->auth = $auth;
	}
}

class AcquireCredentialsInGuestRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $vm; //ManagedObjectReference
	public $requestedAuth; //GuestAuthentication
	public $sessionID; //long

	function __construct($_this = null, $vm = null, $requestedAuth = null, $sessionID = null) {
		$this->_this = $_this;
		$this->vm = $vm;
		$this->requestedAuth = $requestedAuth;
		$this->sessionID = $sessionID;
	}
}

class ReleaseCredentialsInGuestRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $vm; //ManagedObjectReference
	public $auth; //GuestAuthentication

	function __construct($_this = null, $vm = null, $auth = null) {
		$this->_this = $_this;
		$this->vm = $vm;
		$this->auth = $auth;
	}
}

class MakeDirectoryInGuestRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $vm; //ManagedObjectReference
	public $auth; //GuestAuthentication
	public $directoryPath; //string
	public $createParentDirectories; //boolean

	function __construct($_this = null, $vm = null, $auth = null, $directoryPath = null, $createParentDirectories = null) {
		$this->_this = $_this;
		$this->vm = $vm;
		$this->auth = $auth;
		$this->directoryPath = $directoryPath;
		$this->createParentDirectories = $createParentDirectories;
	}
}

class DeleteFileInGuestRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $vm; //ManagedObjectReference
	public $auth; //GuestAuthentication
	public $filePath; //string

	function __construct($_this = null, $vm = null, $auth = null, $filePath = null) {
		$this->_this = $_this;
		$this->vm = $vm;
		$this->auth = $auth;
		$this->filePath = $filePath;
	}
}

class DeleteDirectoryInGuestRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $vm; //ManagedObjectReference
	public $auth; //GuestAuthentication
	public $directoryPath; //string
	public $recursive; //boolean

	function __construct($_this = null, $vm = null, $auth = null, $directoryPath = null, $recursive = null) {
		$this->_this = $_this;
		$this->vm = $vm;
		$this->auth = $auth;
		$this->directoryPath = $directoryPath;
		$this->recursive = $recursive;
	}
}

class MoveDirectoryInGuestRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $vm; //ManagedObjectReference
	public $auth; //GuestAuthentication
	public $srcDirectoryPath; //string
	public $dstDirectoryPath; //string

	function __construct($_this = null, $vm = null, $auth = null, $srcDirectoryPath = null, $dstDirectoryPath = null) {
		$this->_this = $_this;
		$this->vm = $vm;
		$this->auth = $auth;
		$this->srcDirectoryPath = $srcDirectoryPath;
		$this->dstDirectoryPath = $dstDirectoryPath;
	}
}

class MoveFileInGuestRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $vm; //ManagedObjectReference
	public $auth; //GuestAuthentication
	public $srcFilePath; //string
	public $dstFilePath; //string
	public $overwrite; //boolean

	function __construct($_this = null, $vm = null, $auth = null, $srcFilePath = null, $dstFilePath = null, $overwrite = null) {
		$this->_this = $_this;
		$this->vm = $vm;
		$this->auth = $auth;
		$this->srcFilePath = $srcFilePath;
		$this->dstFilePath = $dstFilePath;
		$this->overwrite = $overwrite;
	}
}

class CreateTemporaryFileInGuestRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $vm; //ManagedObjectReference
	public $auth; //GuestAuthentication
	public $prefix; //string
	public $suffix; //string
	public $directoryPath; //string

	function __construct($_this = null, $vm = null, $auth = null, $prefix = null, $suffix = null, $directoryPath = null) {
		$this->_this = $_this;
		$this->vm = $vm;
		$this->auth = $auth;
		$this->prefix = $prefix;
		$this->suffix = $suffix;
		$this->directoryPath = $directoryPath;
	}
}

class CreateTemporaryDirectoryInGuestRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $vm; //ManagedObjectReference
	public $auth; //GuestAuthentication
	public $prefix; //string
	public $suffix; //string
	public $directoryPath; //string

	function __construct($_this = null, $vm = null, $auth = null, $prefix = null, $suffix = null, $directoryPath = null) {
		$this->_this = $_this;
		$this->vm = $vm;
		$this->auth = $auth;
		$this->prefix = $prefix;
		$this->suffix = $suffix;
		$this->directoryPath = $directoryPath;
	}
}

class ListFilesInGuestRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $vm; //ManagedObjectReference
	public $auth; //GuestAuthentication
	public $filePath; //string
	public $index; //int
	public $maxResults; //int
	public $matchPattern; //string

	function __construct($_this = null, $vm = null, $auth = null, $filePath = null, $index = null, $maxResults = null, $matchPattern = null) {
		$this->_this = $_this;
		$this->vm = $vm;
		$this->auth = $auth;
		$this->filePath = $filePath;
		$this->index = $index;
		$this->maxResults = $maxResults;
		$this->matchPattern = $matchPattern;
	}
}

class ChangeFileAttributesInGuestRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $vm; //ManagedObjectReference
	public $auth; //GuestAuthentication
	public $guestFilePath; //string
	public $fileAttributes; //GuestFileAttributes

	function __construct($_this = null, $vm = null, $auth = null, $guestFilePath = null, $fileAttributes = null) {
		$this->_this = $_this;
		$this->vm = $vm;
		$this->auth = $auth;
		$this->guestFilePath = $guestFilePath;
		$this->fileAttributes = $fileAttributes;
	}
}

class InitiateFileTransferFromGuestRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $vm; //ManagedObjectReference
	public $auth; //GuestAuthentication
	public $guestFilePath; //string

	function __construct($_this = null, $vm = null, $auth = null, $guestFilePath = null) {
		$this->_this = $_this;
		$this->vm = $vm;
		$this->auth = $auth;
		$this->guestFilePath = $guestFilePath;
	}
}

class InitiateFileTransferToGuestRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $vm; //ManagedObjectReference
	public $auth; //GuestAuthentication
	public $guestFilePath; //string
	public $fileAttributes; //GuestFileAttributes
	public $fileSize; //long
	public $overwrite; //boolean

	function __construct($_this = null, $vm = null, $auth = null, $guestFilePath = null, $fileAttributes = null, $fileSize = null, $overwrite = null) {
		$this->_this = $_this;
		$this->vm = $vm;
		$this->auth = $auth;
		$this->guestFilePath = $guestFilePath;
		$this->fileAttributes = $fileAttributes;
		$this->fileSize = $fileSize;
		$this->overwrite = $overwrite;
	}
}

class StartProgramInGuestRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $vm; //ManagedObjectReference
	public $auth; //GuestAuthentication
	public $spec; //GuestProgramSpec

	function __construct($_this = null, $vm = null, $auth = null, $spec = null) {
		$this->_this = $_this;
		$this->vm = $vm;
		$this->auth = $auth;
		$this->spec = $spec;
	}
}

class ListProcessesInGuestRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $vm; //ManagedObjectReference
	public $auth; //GuestAuthentication
	public $pids; //long

	function __construct($_this = null, $vm = null, $auth = null, $pids = null) {
		$this->_this = $_this;
		$this->vm = $vm;
		$this->auth = $auth;
		$this->pids = $pids;
	}
}

class TerminateProcessInGuestRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $vm; //ManagedObjectReference
	public $auth; //GuestAuthentication
	public $pid; //long

	function __construct($_this = null, $vm = null, $auth = null, $pid = null) {
		$this->_this = $_this;
		$this->vm = $vm;
		$this->auth = $auth;
		$this->pid = $pid;
	}
}

class ReadEnvironmentVariableInGuestRequestType extends phpDynamicProperties {
	public $_this; //ManagedObjectReference
	public $vm; //ManagedObjectReference
	public $auth; //GuestAuthentication
	public $names; //string

	function __construct($_this = null, $vm = null, $auth = null, $names = null) {
		$this->_this = $_this;
		$this->vm = $vm;
		$this->auth = $auth;
		$this->names = $names;
	}
}

class AddAuthorizationRoleResponse extends phpDynamicProperties {
	public $returnval; //int

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class RemoveAuthorizationRoleResponse extends phpDynamicProperties {
}

class UpdateAuthorizationRoleResponse extends phpDynamicProperties {
}

class MergePermissionsResponse extends phpDynamicProperties {
}

class RetrieveRolePermissionsResponse extends phpDynamicProperties {
	public $returnval; //Permission

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class RetrieveEntityPermissionsResponse extends phpDynamicProperties {
	public $returnval; //Permission

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class RetrieveAllPermissionsResponse extends phpDynamicProperties {
	public $returnval; //Permission

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class SetEntityPermissionsResponse extends phpDynamicProperties {
}

class ResetEntityPermissionsResponse extends phpDynamicProperties {
}

class RemoveEntityPermissionResponse extends phpDynamicProperties {
}

class HasPrivilegeOnEntityResponse extends phpDynamicProperties {
	public $returnval; //boolean

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class ReconfigureCluster_TaskResponse extends phpDynamicProperties {
	public $returnval; //ManagedObjectReference

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class ApplyRecommendationResponse extends phpDynamicProperties {
}

class CancelRecommendationResponse extends phpDynamicProperties {
}

class RecommendHostsForVmResponse extends phpDynamicProperties {
	public $returnval; //ClusterHostRecommendation

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class AddHost_TaskResponse extends phpDynamicProperties {
	public $returnval; //ManagedObjectReference

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class MoveInto_TaskResponse extends phpDynamicProperties {
	public $returnval; //ManagedObjectReference

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class MoveHostInto_TaskResponse extends phpDynamicProperties {
	public $returnval; //ManagedObjectReference

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class RefreshRecommendationResponse extends phpDynamicProperties {
}

class RetrieveDasAdvancedRuntimeInfoResponse extends phpDynamicProperties {
	public $returnval; //ClusterDasAdvancedRuntimeInfo

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class ClusterEnterMaintenanceModeResponse extends phpDynamicProperties {
	public $returnval; //ClusterEnterMaintenanceResult

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class ReconfigureComputeResource_TaskResponse extends phpDynamicProperties {
	public $returnval; //ManagedObjectReference

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class AddCustomFieldDefResponse extends phpDynamicProperties {
	public $returnval; //CustomFieldDef

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class RemoveCustomFieldDefResponse extends phpDynamicProperties {
}

class RenameCustomFieldDefResponse extends phpDynamicProperties {
}

class SetFieldResponse extends phpDynamicProperties {
}

class DoesCustomizationSpecExistResponse extends phpDynamicProperties {
	public $returnval; //boolean

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class GetCustomizationSpecResponse extends phpDynamicProperties {
	public $returnval; //CustomizationSpecItem

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class CreateCustomizationSpecResponse extends phpDynamicProperties {
}

class OverwriteCustomizationSpecResponse extends phpDynamicProperties {
}

class DeleteCustomizationSpecResponse extends phpDynamicProperties {
}

class DuplicateCustomizationSpecResponse extends phpDynamicProperties {
}

class RenameCustomizationSpecResponse extends phpDynamicProperties {
}

class CustomizationSpecItemToXmlResponse extends phpDynamicProperties {
	public $returnval; //string

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class XmlToCustomizationSpecItemResponse extends phpDynamicProperties {
	public $returnval; //CustomizationSpecItem

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class CheckCustomizationResourcesResponse extends phpDynamicProperties {
}

class QueryConnectionInfoResponse extends phpDynamicProperties {
	public $returnval; //HostConnectInfo

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class PowerOnMultiVM_TaskResponse extends phpDynamicProperties {
	public $returnval; //ManagedObjectReference

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class RefreshDatastoreResponse extends phpDynamicProperties {
}

class RefreshDatastoreStorageInfoResponse extends phpDynamicProperties {
}

class UpdateVirtualMachineFiles_TaskResponse extends phpDynamicProperties {
	public $returnval; //ManagedObjectReference

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class RenameDatastoreResponse extends phpDynamicProperties {
}

class DestroyDatastoreResponse extends phpDynamicProperties {
}

class DatastoreEnterMaintenanceModeResponse extends phpDynamicProperties {
	public $returnval; //StoragePlacementResult

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class DatastoreExitMaintenanceMode_TaskResponse extends phpDynamicProperties {
	public $returnval; //ManagedObjectReference

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class QueryDescriptionsResponse extends phpDynamicProperties {
	public $returnval; //DiagnosticManagerLogDescriptor

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class BrowseDiagnosticLogResponse extends phpDynamicProperties {
	public $returnval; //DiagnosticManagerLogHeader

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class GenerateLogBundles_TaskResponse extends phpDynamicProperties {
	public $returnval; //ManagedObjectReference

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class FetchDVPortKeysResponse extends phpDynamicProperties {
	public $returnval; //string

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class FetchDVPortsResponse extends phpDynamicProperties {
	public $returnval; //DistributedVirtualPort

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class QueryUsedVlanIdInDvsResponse extends phpDynamicProperties {
	public $returnval; //int

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class ReconfigureDvs_TaskResponse extends phpDynamicProperties {
	public $returnval; //ManagedObjectReference

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class PerformDvsProductSpecOperation_TaskResponse extends phpDynamicProperties {
	public $returnval; //ManagedObjectReference

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class MergeDvs_TaskResponse extends phpDynamicProperties {
	public $returnval; //ManagedObjectReference

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class AddDVPortgroup_TaskResponse extends phpDynamicProperties {
	public $returnval; //ManagedObjectReference

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class MoveDVPort_TaskResponse extends phpDynamicProperties {
	public $returnval; //ManagedObjectReference

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class UpdateDvsCapabilityResponse extends phpDynamicProperties {
}

class ReconfigureDVPort_TaskResponse extends phpDynamicProperties {
	public $returnval; //ManagedObjectReference

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class RefreshDVPortStateResponse extends phpDynamicProperties {
}

class RectifyDvsHost_TaskResponse extends phpDynamicProperties {
	public $returnval; //ManagedObjectReference

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class UpdateNetworkResourcePoolResponse extends phpDynamicProperties {
}

class AddNetworkResourcePoolResponse extends phpDynamicProperties {
}

class RemoveNetworkResourcePoolResponse extends phpDynamicProperties {
}

class EnableNetworkResourceManagementResponse extends phpDynamicProperties {
}

class QueryConfigOptionDescriptorResponse extends phpDynamicProperties {
	public $returnval; //VirtualMachineConfigOptionDescriptor

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class QueryConfigOptionResponse extends phpDynamicProperties {
	public $returnval; //VirtualMachineConfigOption

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class QueryConfigTargetResponse extends phpDynamicProperties {
	public $returnval; //ConfigTarget

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class QueryTargetCapabilitiesResponse extends phpDynamicProperties {
	public $returnval; //HostCapability

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class setCustomValueResponse extends phpDynamicProperties {
}

class UnregisterExtensionResponse extends phpDynamicProperties {
}

class FindExtensionResponse extends phpDynamicProperties {
	public $returnval; //Extension

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class RegisterExtensionResponse extends phpDynamicProperties {
}

class UpdateExtensionResponse extends phpDynamicProperties {
}

class GetPublicKeyResponse extends phpDynamicProperties {
	public $returnval; //string

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class SetPublicKeyResponse extends phpDynamicProperties {
}

class SetExtensionCertificateResponse extends phpDynamicProperties {
}

class QueryManagedByResponse extends phpDynamicProperties {
	public $returnval; //ManagedObjectReference

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class MoveDatastoreFile_TaskResponse extends phpDynamicProperties {
	public $returnval; //ManagedObjectReference

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class CopyDatastoreFile_TaskResponse extends phpDynamicProperties {
	public $returnval; //ManagedObjectReference

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class DeleteDatastoreFile_TaskResponse extends phpDynamicProperties {
	public $returnval; //ManagedObjectReference

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class MakeDirectoryResponse extends phpDynamicProperties {
}

class ChangeOwnerResponse extends phpDynamicProperties {
}

class CreateFolderResponse extends phpDynamicProperties {
	public $returnval; //ManagedObjectReference

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class MoveIntoFolder_TaskResponse extends phpDynamicProperties {
	public $returnval; //ManagedObjectReference

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class CreateVM_TaskResponse extends phpDynamicProperties {
	public $returnval; //ManagedObjectReference

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class RegisterVM_TaskResponse extends phpDynamicProperties {
	public $returnval; //ManagedObjectReference

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class CreateClusterResponse extends phpDynamicProperties {
	public $returnval; //ManagedObjectReference

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class CreateClusterExResponse extends phpDynamicProperties {
	public $returnval; //ManagedObjectReference

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class AddStandaloneHost_TaskResponse extends phpDynamicProperties {
	public $returnval; //ManagedObjectReference

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class CreateDatacenterResponse extends phpDynamicProperties {
	public $returnval; //ManagedObjectReference

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class UnregisterAndDestroy_TaskResponse extends phpDynamicProperties {
	public $returnval; //ManagedObjectReference

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class CreateDVS_TaskResponse extends phpDynamicProperties {
	public $returnval; //ManagedObjectReference

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class CreateStoragePodResponse extends phpDynamicProperties {
	public $returnval; //ManagedObjectReference

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class SetCollectorPageSizeResponse extends phpDynamicProperties {
}

class RewindCollectorResponse extends phpDynamicProperties {
}

class ResetCollectorResponse extends phpDynamicProperties {
}

class DestroyCollectorResponse extends phpDynamicProperties {
}

class QueryHostConnectionInfoResponse extends phpDynamicProperties {
	public $returnval; //HostConnectInfo

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class UpdateSystemResourcesResponse extends phpDynamicProperties {
}

class ReconnectHost_TaskResponse extends phpDynamicProperties {
	public $returnval; //ManagedObjectReference

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class DisconnectHost_TaskResponse extends phpDynamicProperties {
	public $returnval; //ManagedObjectReference

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class EnterMaintenanceMode_TaskResponse extends phpDynamicProperties {
	public $returnval; //ManagedObjectReference

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class ExitMaintenanceMode_TaskResponse extends phpDynamicProperties {
	public $returnval; //ManagedObjectReference

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class RebootHost_TaskResponse extends phpDynamicProperties {
	public $returnval; //ManagedObjectReference

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class ShutdownHost_TaskResponse extends phpDynamicProperties {
	public $returnval; //ManagedObjectReference

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class PowerDownHostToStandBy_TaskResponse extends phpDynamicProperties {
	public $returnval; //ManagedObjectReference

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class PowerUpHostFromStandBy_TaskResponse extends phpDynamicProperties {
	public $returnval; //ManagedObjectReference

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class QueryMemoryOverheadResponse extends phpDynamicProperties {
	public $returnval; //long

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class QueryMemoryOverheadExResponse extends phpDynamicProperties {
	public $returnval; //long

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class ReconfigureHostForDAS_TaskResponse extends phpDynamicProperties {
	public $returnval; //ManagedObjectReference

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class UpdateFlagsResponse extends phpDynamicProperties {
}

class EnterLockdownModeResponse extends phpDynamicProperties {
}

class ExitLockdownModeResponse extends phpDynamicProperties {
}

class AcquireCimServicesTicketResponse extends phpDynamicProperties {
	public $returnval; //HostServiceTicket

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class UpdateIpmiResponse extends phpDynamicProperties {
}

class RetrieveHardwareUptimeResponse extends phpDynamicProperties {
	public $returnval; //long

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class HttpNfcLeaseGetManifestResponse extends phpDynamicProperties {
	public $returnval; //HttpNfcLeaseManifestEntry

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class HttpNfcLeaseCompleteResponse extends phpDynamicProperties {
}

class HttpNfcLeaseAbortResponse extends phpDynamicProperties {
}

class HttpNfcLeaseProgressResponse extends phpDynamicProperties {
}

class QueryIpPoolsResponse extends phpDynamicProperties {
	public $returnval; //IpPool

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class CreateIpPoolResponse extends phpDynamicProperties {
	public $returnval; //int

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class UpdateIpPoolResponse extends phpDynamicProperties {
}

class DestroyIpPoolResponse extends phpDynamicProperties {
}

class UpdateAssignedLicenseResponse extends phpDynamicProperties {
	public $returnval; //LicenseManagerLicenseInfo

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class RemoveAssignedLicenseResponse extends phpDynamicProperties {
}

class QueryAssignedLicensesResponse extends phpDynamicProperties {
	public $returnval; //LicenseAssignmentManagerLicenseAssignment

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class QuerySupportedFeaturesResponse extends phpDynamicProperties {
	public $returnval; //LicenseFeatureInfo

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class QueryLicenseSourceAvailabilityResponse extends phpDynamicProperties {
	public $returnval; //LicenseAvailabilityInfo

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class QueryLicenseUsageResponse extends phpDynamicProperties {
	public $returnval; //LicenseUsageInfo

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class SetLicenseEditionResponse extends phpDynamicProperties {
}

class CheckLicenseFeatureResponse extends phpDynamicProperties {
	public $returnval; //boolean

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class EnableFeatureResponse extends phpDynamicProperties {
	public $returnval; //boolean

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class DisableFeatureResponse extends phpDynamicProperties {
	public $returnval; //boolean

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class ConfigureLicenseSourceResponse extends phpDynamicProperties {
}

class UpdateLicenseResponse extends phpDynamicProperties {
	public $returnval; //LicenseManagerLicenseInfo

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class AddLicenseResponse extends phpDynamicProperties {
	public $returnval; //LicenseManagerLicenseInfo

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class RemoveLicenseResponse extends phpDynamicProperties {
}

class DecodeLicenseResponse extends phpDynamicProperties {
	public $returnval; //LicenseManagerLicenseInfo

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class UpdateLicenseLabelResponse extends phpDynamicProperties {
}

class RemoveLicenseLabelResponse extends phpDynamicProperties {
}

class ReloadResponse extends phpDynamicProperties {
}

class Rename_TaskResponse extends phpDynamicProperties {
	public $returnval; //ManagedObjectReference

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class Destroy_TaskResponse extends phpDynamicProperties {
	public $returnval; //ManagedObjectReference

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class DestroyNetworkResponse extends phpDynamicProperties {
}

class ValidateHostResponse extends phpDynamicProperties {
	public $returnval; //OvfValidateHostResult

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class ParseDescriptorResponse extends phpDynamicProperties {
	public $returnval; //OvfParseDescriptorResult

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class CreateImportSpecResponse extends phpDynamicProperties {
	public $returnval; //OvfCreateImportSpecResult

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class CreateDescriptorResponse extends phpDynamicProperties {
	public $returnval; //OvfCreateDescriptorResult

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class QueryPerfProviderSummaryResponse extends phpDynamicProperties {
	public $returnval; //PerfProviderSummary

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class QueryAvailablePerfMetricResponse extends phpDynamicProperties {
	public $returnval; //PerfMetricId

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class QueryPerfCounterResponse extends phpDynamicProperties {
	public $returnval; //PerfCounterInfo

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class QueryPerfCounterByLevelResponse extends phpDynamicProperties {
	public $returnval; //PerfCounterInfo

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class QueryPerfResponse extends phpDynamicProperties {
	public $returnval; //PerfEntityMetricBase

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class QueryPerfCompositeResponse extends phpDynamicProperties {
	public $returnval; //PerfCompositeMetric

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class CreatePerfIntervalResponse extends phpDynamicProperties {
}

class RemovePerfIntervalResponse extends phpDynamicProperties {
}

class UpdatePerfIntervalResponse extends phpDynamicProperties {
}

class UpdateCounterLevelMappingResponse extends phpDynamicProperties {
}

class ResetCounterLevelMappingResponse extends phpDynamicProperties {
}

class EstimateDatabaseSizeResponse extends phpDynamicProperties {
	public $returnval; //DatabaseSizeEstimate

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class UpdateConfigResponse extends phpDynamicProperties {
}

class MoveIntoResourcePoolResponse extends phpDynamicProperties {
}

class UpdateChildResourceConfigurationResponse extends phpDynamicProperties {
}

class CreateResourcePoolResponse extends phpDynamicProperties {
	public $returnval; //ManagedObjectReference

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class DestroyChildrenResponse extends phpDynamicProperties {
}

class CreateVAppResponse extends phpDynamicProperties {
	public $returnval; //ManagedObjectReference

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class CreateChildVM_TaskResponse extends phpDynamicProperties {
	public $returnval; //ManagedObjectReference

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class RegisterChildVM_TaskResponse extends phpDynamicProperties {
	public $returnval; //ManagedObjectReference

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class ImportVAppResponse extends phpDynamicProperties {
	public $returnval; //ManagedObjectReference

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class QueryResourceConfigOptionResponse extends phpDynamicProperties {
	public $returnval; //ResourceConfigOption

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class RefreshRuntimeResponse extends phpDynamicProperties {
}

class FindByUuidResponse extends phpDynamicProperties {
	public $returnval; //ManagedObjectReference

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class FindByDatastorePathResponse extends phpDynamicProperties {
	public $returnval; //ManagedObjectReference

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class FindByDnsNameResponse extends phpDynamicProperties {
	public $returnval; //ManagedObjectReference

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class FindByIpResponse extends phpDynamicProperties {
	public $returnval; //ManagedObjectReference

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class FindByInventoryPathResponse extends phpDynamicProperties {
	public $returnval; //ManagedObjectReference

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class FindChildResponse extends phpDynamicProperties {
	public $returnval; //ManagedObjectReference

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class FindAllByUuidResponse extends phpDynamicProperties {
	public $returnval; //ManagedObjectReference

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class FindAllByDnsNameResponse extends phpDynamicProperties {
	public $returnval; //ManagedObjectReference

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class FindAllByIpResponse extends phpDynamicProperties {
	public $returnval; //ManagedObjectReference

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class CurrentTimeResponse extends phpDynamicProperties {
	public $returnval; //dateTime

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class RetrieveServiceContentResponse extends phpDynamicProperties {
	public $returnval; //ServiceContent

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class ValidateMigrationResponse extends phpDynamicProperties {
	public $returnval; //Event

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class QueryVMotionCompatibilityResponse extends phpDynamicProperties {
	public $returnval; //HostVMotionCompatibility

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class RetrieveProductComponentsResponse extends phpDynamicProperties {
	public $returnval; //ProductComponentInfo

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class UpdateServiceMessageResponse extends phpDynamicProperties {
}

class LoginResponse extends phpDynamicProperties {
	public $returnval; //UserSession

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class LoginBySSPIResponse extends phpDynamicProperties {
	public $returnval; //UserSession

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class LogoutResponse extends phpDynamicProperties {
}

class AcquireLocalTicketResponse extends phpDynamicProperties {
	public $returnval; //SessionManagerLocalTicket

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class AcquireGenericServiceTicketResponse extends phpDynamicProperties {
	public $returnval; //SessionManagerGenericServiceTicket

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class TerminateSessionResponse extends phpDynamicProperties {
}

class SetLocaleResponse extends phpDynamicProperties {
}

class LoginExtensionBySubjectNameResponse extends phpDynamicProperties {
	public $returnval; //UserSession

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class LoginExtensionByCertificateResponse extends phpDynamicProperties {
	public $returnval; //UserSession

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class ImpersonateUserResponse extends phpDynamicProperties {
	public $returnval; //UserSession

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class SessionIsActiveResponse extends phpDynamicProperties {
	public $returnval; //boolean

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class AcquireCloneTicketResponse extends phpDynamicProperties {
	public $returnval; //string

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class CloneSessionResponse extends phpDynamicProperties {
	public $returnval; //UserSession

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class ConfigureDatastoreIORM_TaskResponse extends phpDynamicProperties {
	public $returnval; //ManagedObjectReference

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class QueryIORMConfigOptionResponse extends phpDynamicProperties {
	public $returnval; //StorageIORMConfigOption

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class ApplyStorageDrsRecommendationToPod_TaskResponse extends phpDynamicProperties {
	public $returnval; //ManagedObjectReference

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class ApplyStorageDrsRecommendation_TaskResponse extends phpDynamicProperties {
	public $returnval; //ManagedObjectReference

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class CancelStorageDrsRecommendationResponse extends phpDynamicProperties {
}

class RefreshStorageDrsRecommendationResponse extends phpDynamicProperties {
}

class ConfigureStorageDrsForPod_TaskResponse extends phpDynamicProperties {
	public $returnval; //ManagedObjectReference

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class RecommendDatastoresResponse extends phpDynamicProperties {
	public $returnval; //StoragePlacementResult

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class CancelTaskResponse extends phpDynamicProperties {
}

class UpdateProgressResponse extends phpDynamicProperties {
}

class SetTaskStateResponse extends phpDynamicProperties {
}

class SetTaskDescriptionResponse extends phpDynamicProperties {
}

class ReadNextTasksResponse extends phpDynamicProperties {
	public $returnval; //TaskInfo

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class ReadPreviousTasksResponse extends phpDynamicProperties {
	public $returnval; //TaskInfo

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class CreateCollectorForTasksResponse extends phpDynamicProperties {
	public $returnval; //ManagedObjectReference

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class CreateTaskResponse extends phpDynamicProperties {
	public $returnval; //TaskInfo

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class RetrieveUserGroupsResponse extends phpDynamicProperties {
	public $returnval; //UserSearchResult

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class UpdateVAppConfigResponse extends phpDynamicProperties {
}

class UpdateLinkedChildrenResponse extends phpDynamicProperties {
}

class CloneVApp_TaskResponse extends phpDynamicProperties {
	public $returnval; //ManagedObjectReference

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class ExportVAppResponse extends phpDynamicProperties {
	public $returnval; //ManagedObjectReference

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class PowerOnVApp_TaskResponse extends phpDynamicProperties {
	public $returnval; //ManagedObjectReference

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class PowerOffVApp_TaskResponse extends phpDynamicProperties {
	public $returnval; //ManagedObjectReference

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class SuspendVApp_TaskResponse extends phpDynamicProperties {
	public $returnval; //ManagedObjectReference

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class unregisterVApp_TaskResponse extends phpDynamicProperties {
	public $returnval; //ManagedObjectReference

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class CreateVirtualDisk_TaskResponse extends phpDynamicProperties {
	public $returnval; //ManagedObjectReference

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class DeleteVirtualDisk_TaskResponse extends phpDynamicProperties {
	public $returnval; //ManagedObjectReference

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class MoveVirtualDisk_TaskResponse extends phpDynamicProperties {
	public $returnval; //ManagedObjectReference

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class CopyVirtualDisk_TaskResponse extends phpDynamicProperties {
	public $returnval; //ManagedObjectReference

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class ExtendVirtualDisk_TaskResponse extends phpDynamicProperties {
	public $returnval; //ManagedObjectReference

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class QueryVirtualDiskFragmentationResponse extends phpDynamicProperties {
	public $returnval; //int

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class DefragmentVirtualDisk_TaskResponse extends phpDynamicProperties {
	public $returnval; //ManagedObjectReference

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class ShrinkVirtualDisk_TaskResponse extends phpDynamicProperties {
	public $returnval; //ManagedObjectReference

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class InflateVirtualDisk_TaskResponse extends phpDynamicProperties {
	public $returnval; //ManagedObjectReference

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class EagerZeroVirtualDisk_TaskResponse extends phpDynamicProperties {
	public $returnval; //ManagedObjectReference

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class ZeroFillVirtualDisk_TaskResponse extends phpDynamicProperties {
	public $returnval; //ManagedObjectReference

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class SetVirtualDiskUuidResponse extends phpDynamicProperties {
}

class QueryVirtualDiskUuidResponse extends phpDynamicProperties {
	public $returnval; //string

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class QueryVirtualDiskGeometryResponse extends phpDynamicProperties {
	public $returnval; //HostDiskDimensionsChs

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class RefreshStorageInfoResponse extends phpDynamicProperties {
}

class CreateSnapshot_TaskResponse extends phpDynamicProperties {
	public $returnval; //ManagedObjectReference

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class RevertToCurrentSnapshot_TaskResponse extends phpDynamicProperties {
	public $returnval; //ManagedObjectReference

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class RemoveAllSnapshots_TaskResponse extends phpDynamicProperties {
	public $returnval; //ManagedObjectReference

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class ConsolidateVMDisks_TaskResponse extends phpDynamicProperties {
	public $returnval; //ManagedObjectReference

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class EstimateStorageForConsolidateSnapshots_TaskResponse extends phpDynamicProperties {
	public $returnval; //ManagedObjectReference

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class ReconfigVM_TaskResponse extends phpDynamicProperties {
	public $returnval; //ManagedObjectReference

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class UpgradeVM_TaskResponse extends phpDynamicProperties {
	public $returnval; //ManagedObjectReference

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class ExtractOvfEnvironmentResponse extends phpDynamicProperties {
	public $returnval; //string

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class PowerOnVM_TaskResponse extends phpDynamicProperties {
	public $returnval; //ManagedObjectReference

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class PowerOffVM_TaskResponse extends phpDynamicProperties {
	public $returnval; //ManagedObjectReference

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class SuspendVM_TaskResponse extends phpDynamicProperties {
	public $returnval; //ManagedObjectReference

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class ResetVM_TaskResponse extends phpDynamicProperties {
	public $returnval; //ManagedObjectReference

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class ShutdownGuestResponse extends phpDynamicProperties {
}

class RebootGuestResponse extends phpDynamicProperties {
}

class StandbyGuestResponse extends phpDynamicProperties {
}

class AnswerVMResponse extends phpDynamicProperties {
}

class CustomizeVM_TaskResponse extends phpDynamicProperties {
	public $returnval; //ManagedObjectReference

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class CheckCustomizationSpecResponse extends phpDynamicProperties {
}

class MigrateVM_TaskResponse extends phpDynamicProperties {
	public $returnval; //ManagedObjectReference

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class RelocateVM_TaskResponse extends phpDynamicProperties {
	public $returnval; //ManagedObjectReference

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class CloneVM_TaskResponse extends phpDynamicProperties {
	public $returnval; //ManagedObjectReference

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class ExportVmResponse extends phpDynamicProperties {
	public $returnval; //ManagedObjectReference

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class MarkAsTemplateResponse extends phpDynamicProperties {
}

class MarkAsVirtualMachineResponse extends phpDynamicProperties {
}

class UnregisterVMResponse extends phpDynamicProperties {
}

class ResetGuestInformationResponse extends phpDynamicProperties {
}

class MountToolsInstallerResponse extends phpDynamicProperties {
}

class UnmountToolsInstallerResponse extends phpDynamicProperties {
}

class UpgradeTools_TaskResponse extends phpDynamicProperties {
	public $returnval; //ManagedObjectReference

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class AcquireMksTicketResponse extends phpDynamicProperties {
	public $returnval; //VirtualMachineMksTicket

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class AcquireTicketResponse extends phpDynamicProperties {
	public $returnval; //VirtualMachineTicket

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class SetScreenResolutionResponse extends phpDynamicProperties {
}

class DefragmentAllDisksResponse extends phpDynamicProperties {
}

class CreateSecondaryVM_TaskResponse extends phpDynamicProperties {
	public $returnval; //ManagedObjectReference

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class TurnOffFaultToleranceForVM_TaskResponse extends phpDynamicProperties {
	public $returnval; //ManagedObjectReference

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class MakePrimaryVM_TaskResponse extends phpDynamicProperties {
	public $returnval; //ManagedObjectReference

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class TerminateFaultTolerantVM_TaskResponse extends phpDynamicProperties {
	public $returnval; //ManagedObjectReference

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class DisableSecondaryVM_TaskResponse extends phpDynamicProperties {
	public $returnval; //ManagedObjectReference

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class EnableSecondaryVM_TaskResponse extends phpDynamicProperties {
	public $returnval; //ManagedObjectReference

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class SetDisplayTopologyResponse extends phpDynamicProperties {
}

class StartRecording_TaskResponse extends phpDynamicProperties {
	public $returnval; //ManagedObjectReference

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class StopRecording_TaskResponse extends phpDynamicProperties {
	public $returnval; //ManagedObjectReference

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class StartReplaying_TaskResponse extends phpDynamicProperties {
	public $returnval; //ManagedObjectReference

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class StopReplaying_TaskResponse extends phpDynamicProperties {
	public $returnval; //ManagedObjectReference

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class PromoteDisks_TaskResponse extends phpDynamicProperties {
	public $returnval; //ManagedObjectReference

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class CreateScreenshot_TaskResponse extends phpDynamicProperties {
	public $returnval; //ManagedObjectReference

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class QueryChangedDiskAreasResponse extends phpDynamicProperties {
	public $returnval; //DiskChangeInfo

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class QueryUnownedFilesResponse extends phpDynamicProperties {
	public $returnval; //string

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class reloadVirtualMachineFromPath_TaskResponse extends phpDynamicProperties {
	public $returnval; //ManagedObjectReference

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class QueryFaultToleranceCompatibilityResponse extends phpDynamicProperties {
	public $returnval; //LocalizedMethodFault

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class RemoveAlarmResponse extends phpDynamicProperties {
}

class ReconfigureAlarmResponse extends phpDynamicProperties {
}

class CreateAlarmResponse extends phpDynamicProperties {
	public $returnval; //ManagedObjectReference

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class GetAlarmResponse extends phpDynamicProperties {
	public $returnval; //ManagedObjectReference

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class AreAlarmActionsEnabledResponse extends phpDynamicProperties {
	public $returnval; //boolean

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class EnableAlarmActionsResponse extends phpDynamicProperties {
}

class GetAlarmStateResponse extends phpDynamicProperties {
	public $returnval; //AlarmState

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class AcknowledgeAlarmResponse extends phpDynamicProperties {
}

class ReconfigureDVPortgroup_TaskResponse extends phpDynamicProperties {
	public $returnval; //ManagedObjectReference

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class QueryAvailableDvsSpecResponse extends phpDynamicProperties {
	public $returnval; //DistributedVirtualSwitchProductSpec

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class QueryCompatibleHostForNewDvsResponse extends phpDynamicProperties {
	public $returnval; //ManagedObjectReference

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class QueryCompatibleHostForExistingDvsResponse extends phpDynamicProperties {
	public $returnval; //ManagedObjectReference

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class QueryDvsCompatibleHostSpecResponse extends phpDynamicProperties {
	public $returnval; //DistributedVirtualSwitchHostProductSpec

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class QueryDvsFeatureCapabilityResponse extends phpDynamicProperties {
	public $returnval; //DVSFeatureCapability

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class QueryDvsByUuidResponse extends phpDynamicProperties {
	public $returnval; //ManagedObjectReference

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class QueryDvsConfigTargetResponse extends phpDynamicProperties {
	public $returnval; //DVSManagerDvsConfigTarget

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class QueryDvsCheckCompatibilityResponse extends phpDynamicProperties {
	public $returnval; //DistributedVirtualSwitchManagerCompatibilityResult

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class RectifyDvsOnHost_TaskResponse extends phpDynamicProperties {
	public $returnval; //ManagedObjectReference

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class ReadNextEventsResponse extends phpDynamicProperties {
	public $returnval; //Event

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class ReadPreviousEventsResponse extends phpDynamicProperties {
	public $returnval; //Event

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class RetrieveArgumentDescriptionResponse extends phpDynamicProperties {
	public $returnval; //EventArgDesc

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class CreateCollectorForEventsResponse extends phpDynamicProperties {
	public $returnval; //ManagedObjectReference

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class LogUserEventResponse extends phpDynamicProperties {
}

class QueryEventsResponse extends phpDynamicProperties {
	public $returnval; //Event

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class PostEventResponse extends phpDynamicProperties {
}

class JoinDomain_TaskResponse extends phpDynamicProperties {
	public $returnval; //ManagedObjectReference

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class JoinDomainWithCAM_TaskResponse extends phpDynamicProperties {
	public $returnval; //ManagedObjectReference

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class ImportCertificateForCAM_TaskResponse extends phpDynamicProperties {
	public $returnval; //ManagedObjectReference

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class LeaveCurrentDomain_TaskResponse extends phpDynamicProperties {
	public $returnval; //ManagedObjectReference

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class ReconfigureAutostartResponse extends phpDynamicProperties {
}

class AutoStartPowerOnResponse extends phpDynamicProperties {
}

class AutoStartPowerOffResponse extends phpDynamicProperties {
}

class QueryBootDevicesResponse extends phpDynamicProperties {
	public $returnval; //HostBootDeviceInfo

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class UpdateBootDeviceResponse extends phpDynamicProperties {
}

class ConfigureHostCache_TaskResponse extends phpDynamicProperties {
	public $returnval; //ManagedObjectReference

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class EnableHyperThreadingResponse extends phpDynamicProperties {
}

class DisableHyperThreadingResponse extends phpDynamicProperties {
}

class SearchDatastore_TaskResponse extends phpDynamicProperties {
	public $returnval; //ManagedObjectReference

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class SearchDatastoreSubFolders_TaskResponse extends phpDynamicProperties {
	public $returnval; //ManagedObjectReference

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class DeleteFileResponse extends phpDynamicProperties {
}

class UpdateLocalSwapDatastoreResponse extends phpDynamicProperties {
}

class QueryAvailableDisksForVmfsResponse extends phpDynamicProperties {
	public $returnval; //HostScsiDisk

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class QueryVmfsDatastoreCreateOptionsResponse extends phpDynamicProperties {
	public $returnval; //VmfsDatastoreOption

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class CreateVmfsDatastoreResponse extends phpDynamicProperties {
	public $returnval; //ManagedObjectReference

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class QueryVmfsDatastoreExtendOptionsResponse extends phpDynamicProperties {
	public $returnval; //VmfsDatastoreOption

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class QueryVmfsDatastoreExpandOptionsResponse extends phpDynamicProperties {
	public $returnval; //VmfsDatastoreOption

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class ExtendVmfsDatastoreResponse extends phpDynamicProperties {
	public $returnval; //ManagedObjectReference

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class ExpandVmfsDatastoreResponse extends phpDynamicProperties {
	public $returnval; //ManagedObjectReference

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class CreateNasDatastoreResponse extends phpDynamicProperties {
	public $returnval; //ManagedObjectReference

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class CreateLocalDatastoreResponse extends phpDynamicProperties {
	public $returnval; //ManagedObjectReference

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class RemoveDatastoreResponse extends phpDynamicProperties {
}

class ConfigureDatastorePrincipalResponse extends phpDynamicProperties {
}

class QueryUnresolvedVmfsVolumesResponse extends phpDynamicProperties {
	public $returnval; //HostUnresolvedVmfsVolume

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class ResignatureUnresolvedVmfsVolume_TaskResponse extends phpDynamicProperties {
	public $returnval; //ManagedObjectReference

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class UpdateDateTimeConfigResponse extends phpDynamicProperties {
}

class QueryAvailableTimeZonesResponse extends phpDynamicProperties {
	public $returnval; //HostDateTimeSystemTimeZone

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class QueryDateTimeResponse extends phpDynamicProperties {
	public $returnval; //dateTime

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class UpdateDateTimeResponse extends phpDynamicProperties {
}

class RefreshDateTimeSystemResponse extends phpDynamicProperties {
}

class QueryAvailablePartitionResponse extends phpDynamicProperties {
	public $returnval; //HostDiagnosticPartition

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class SelectActivePartitionResponse extends phpDynamicProperties {
}

class QueryPartitionCreateOptionsResponse extends phpDynamicProperties {
	public $returnval; //HostDiagnosticPartitionCreateOption

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class QueryPartitionCreateDescResponse extends phpDynamicProperties {
	public $returnval; //HostDiagnosticPartitionCreateDescription

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class CreateDiagnosticPartitionResponse extends phpDynamicProperties {
}

class EsxAgentHostManagerUpdateConfigResponse extends phpDynamicProperties {
}

class UpdateDefaultPolicyResponse extends phpDynamicProperties {
}

class EnableRulesetResponse extends phpDynamicProperties {
}

class DisableRulesetResponse extends phpDynamicProperties {
}

class UpdateRulesetResponse extends phpDynamicProperties {
}

class RefreshFirewallResponse extends phpDynamicProperties {
}

class ResetFirmwareToFactoryDefaultsResponse extends phpDynamicProperties {
}

class BackupFirmwareConfigurationResponse extends phpDynamicProperties {
	public $returnval; //string

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class QueryFirmwareConfigUploadURLResponse extends phpDynamicProperties {
	public $returnval; //string

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class RestoreFirmwareConfigurationResponse extends phpDynamicProperties {
}

class RefreshHealthStatusSystemResponse extends phpDynamicProperties {
}

class ResetSystemHealthInfoResponse extends phpDynamicProperties {
}

class HostImageConfigGetAcceptanceResponse extends phpDynamicProperties {
	public $returnval; //string

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class HostImageConfigGetProfileResponse extends phpDynamicProperties {
	public $returnval; //HostImageProfileSummary

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class UpdateHostImageAcceptanceLevelResponse extends phpDynamicProperties {
}

class QueryVnicStatusResponse extends phpDynamicProperties {
	public $returnval; //IscsiStatus

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class QueryPnicStatusResponse extends phpDynamicProperties {
	public $returnval; //IscsiStatus

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class QueryBoundVnicsResponse extends phpDynamicProperties {
	public $returnval; //IscsiPortInfo

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class QueryCandidateNicsResponse extends phpDynamicProperties {
	public $returnval; //IscsiPortInfo

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class BindVnicResponse extends phpDynamicProperties {
}

class UnbindVnicResponse extends phpDynamicProperties {
}

class QueryMigrationDependenciesResponse extends phpDynamicProperties {
	public $returnval; //IscsiMigrationDependency

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class QueryModulesResponse extends phpDynamicProperties {
	public $returnval; //KernelModuleInfo

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class UpdateModuleOptionStringResponse extends phpDynamicProperties {
}

class QueryConfiguredModuleOptionStringResponse extends phpDynamicProperties {
	public $returnval; //string

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class CreateUserResponse extends phpDynamicProperties {
}

class UpdateUserResponse extends phpDynamicProperties {
}

class CreateGroupResponse extends phpDynamicProperties {
}

class RemoveUserResponse extends phpDynamicProperties {
}

class RemoveGroupResponse extends phpDynamicProperties {
}

class AssignUserToGroupResponse extends phpDynamicProperties {
}

class UnassignUserFromGroupResponse extends phpDynamicProperties {
}

class ReconfigureServiceConsoleReservationResponse extends phpDynamicProperties {
}

class ReconfigureVirtualMachineReservationResponse extends phpDynamicProperties {
}

class UpdateNetworkConfigResponse extends phpDynamicProperties {
	public $returnval; //HostNetworkConfigResult

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class UpdateDnsConfigResponse extends phpDynamicProperties {
}

class UpdateIpRouteConfigResponse extends phpDynamicProperties {
}

class UpdateConsoleIpRouteConfigResponse extends phpDynamicProperties {
}

class UpdateIpRouteTableConfigResponse extends phpDynamicProperties {
}

class AddVirtualSwitchResponse extends phpDynamicProperties {
}

class RemoveVirtualSwitchResponse extends phpDynamicProperties {
}

class UpdateVirtualSwitchResponse extends phpDynamicProperties {
}

class AddPortGroupResponse extends phpDynamicProperties {
}

class RemovePortGroupResponse extends phpDynamicProperties {
}

class UpdatePortGroupResponse extends phpDynamicProperties {
}

class UpdatePhysicalNicLinkSpeedResponse extends phpDynamicProperties {
}

class QueryNetworkHintResponse extends phpDynamicProperties {
	public $returnval; //PhysicalNicHintInfo

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class AddVirtualNicResponse extends phpDynamicProperties {
	public $returnval; //string

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class RemoveVirtualNicResponse extends phpDynamicProperties {
}

class UpdateVirtualNicResponse extends phpDynamicProperties {
}

class AddServiceConsoleVirtualNicResponse extends phpDynamicProperties {
	public $returnval; //string

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class RemoveServiceConsoleVirtualNicResponse extends phpDynamicProperties {
}

class UpdateServiceConsoleVirtualNicResponse extends phpDynamicProperties {
}

class RestartServiceConsoleVirtualNicResponse extends phpDynamicProperties {
}

class RefreshNetworkSystemResponse extends phpDynamicProperties {
}

class CheckHostPatch_TaskResponse extends phpDynamicProperties {
	public $returnval; //ManagedObjectReference

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class ScanHostPatch_TaskResponse extends phpDynamicProperties {
	public $returnval; //ManagedObjectReference

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class ScanHostPatchV2_TaskResponse extends phpDynamicProperties {
	public $returnval; //ManagedObjectReference

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class StageHostPatch_TaskResponse extends phpDynamicProperties {
	public $returnval; //ManagedObjectReference

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class InstallHostPatch_TaskResponse extends phpDynamicProperties {
	public $returnval; //ManagedObjectReference

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class InstallHostPatchV2_TaskResponse extends phpDynamicProperties {
	public $returnval; //ManagedObjectReference

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class UninstallHostPatch_TaskResponse extends phpDynamicProperties {
	public $returnval; //ManagedObjectReference

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class QueryHostPatch_TaskResponse extends phpDynamicProperties {
	public $returnval; //ManagedObjectReference

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class RefreshResponse extends phpDynamicProperties {
}

class UpdatePassthruConfigResponse extends phpDynamicProperties {
}

class ConfigurePowerPolicyResponse extends phpDynamicProperties {
}

class UpdateServicePolicyResponse extends phpDynamicProperties {
}

class StartServiceResponse extends phpDynamicProperties {
}

class StopServiceResponse extends phpDynamicProperties {
}

class RestartServiceResponse extends phpDynamicProperties {
}

class UninstallServiceResponse extends phpDynamicProperties {
}

class RefreshServicesResponse extends phpDynamicProperties {
}

class ReconfigureSnmpAgentResponse extends phpDynamicProperties {
}

class SendTestNotificationResponse extends phpDynamicProperties {
}

class RetrieveDiskPartitionInfoResponse extends phpDynamicProperties {
	public $returnval; //HostDiskPartitionInfo

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class ComputeDiskPartitionInfoResponse extends phpDynamicProperties {
	public $returnval; //HostDiskPartitionInfo

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class ComputeDiskPartitionInfoForResizeResponse extends phpDynamicProperties {
	public $returnval; //HostDiskPartitionInfo

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class UpdateDiskPartitionsResponse extends phpDynamicProperties {
}

class FormatVmfsResponse extends phpDynamicProperties {
	public $returnval; //HostVmfsVolume

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class MountVmfsVolumeResponse extends phpDynamicProperties {
}

class UnmountVmfsVolumeResponse extends phpDynamicProperties {
}

class RescanVmfsResponse extends phpDynamicProperties {
}

class AttachVmfsExtentResponse extends phpDynamicProperties {
}

class ExpandVmfsExtentResponse extends phpDynamicProperties {
}

class UpgradeVmfsResponse extends phpDynamicProperties {
}

class UpgradeVmLayoutResponse extends phpDynamicProperties {
}

class QueryUnresolvedVmfsVolumeResponse extends phpDynamicProperties {
	public $returnval; //HostUnresolvedVmfsVolume

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class ResolveMultipleUnresolvedVmfsVolumesResponse extends phpDynamicProperties {
	public $returnval; //HostUnresolvedVmfsResolutionResult

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class UnmountForceMountedVmfsVolumeResponse extends phpDynamicProperties {
}

class RescanHbaResponse extends phpDynamicProperties {
}

class RescanAllHbaResponse extends phpDynamicProperties {
}

class UpdateSoftwareInternetScsiEnabledResponse extends phpDynamicProperties {
}

class UpdateInternetScsiDiscoveryPropertiesResponse extends phpDynamicProperties {
}

class UpdateInternetScsiAuthenticationPropertiesResponse extends phpDynamicProperties {
}

class UpdateInternetScsiDigestPropertiesResponse extends phpDynamicProperties {
}

class UpdateInternetScsiAdvancedOptionsResponse extends phpDynamicProperties {
}

class UpdateInternetScsiIPPropertiesResponse extends phpDynamicProperties {
}

class UpdateInternetScsiNameResponse extends phpDynamicProperties {
}

class UpdateInternetScsiAliasResponse extends phpDynamicProperties {
}

class AddInternetScsiSendTargetsResponse extends phpDynamicProperties {
}

class RemoveInternetScsiSendTargetsResponse extends phpDynamicProperties {
}

class AddInternetScsiStaticTargetsResponse extends phpDynamicProperties {
}

class RemoveInternetScsiStaticTargetsResponse extends phpDynamicProperties {
}

class EnableMultipathPathResponse extends phpDynamicProperties {
}

class DisableMultipathPathResponse extends phpDynamicProperties {
}

class SetMultipathLunPolicyResponse extends phpDynamicProperties {
}

class QueryPathSelectionPolicyOptionsResponse extends phpDynamicProperties {
	public $returnval; //HostPathSelectionPolicyOption

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class QueryStorageArrayTypePolicyOptionsResponse extends phpDynamicProperties {
	public $returnval; //HostStorageArrayTypePolicyOption

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class UpdateScsiLunDisplayNameResponse extends phpDynamicProperties {
}

class DetachScsiLunResponse extends phpDynamicProperties {
}

class AttachScsiLunResponse extends phpDynamicProperties {
}

class RefreshStorageSystemResponse extends phpDynamicProperties {
}

class DiscoverFcoeHbasResponse extends phpDynamicProperties {
}

class MarkForRemovalResponse extends phpDynamicProperties {
}

class UpdateIpConfigResponse extends phpDynamicProperties {
}

class SelectVnicResponse extends phpDynamicProperties {
}

class DeselectVnicResponse extends phpDynamicProperties {
}

class QueryNetConfigResponse extends phpDynamicProperties {
	public $returnval; //VirtualNicManagerNetConfig

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class SelectVnicForNicTypeResponse extends phpDynamicProperties {
}

class DeselectVnicForNicTypeResponse extends phpDynamicProperties {
}

class QueryOptionsResponse extends phpDynamicProperties {
	public $returnval; //OptionValue

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class UpdateOptionsResponse extends phpDynamicProperties {
}

class CheckCompliance_TaskResponse extends phpDynamicProperties {
	public $returnval; //ManagedObjectReference

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class QueryComplianceStatusResponse extends phpDynamicProperties {
	public $returnval; //ComplianceResult

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class ClearComplianceStatusResponse extends phpDynamicProperties {
}

class QueryExpressionMetadataResponse extends phpDynamicProperties {
	public $returnval; //ProfileExpressionMetadata

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class RetrieveDescriptionResponse extends phpDynamicProperties {
	public $returnval; //ProfileDescription

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class DestroyProfileResponse extends phpDynamicProperties {
}

class AssociateProfileResponse extends phpDynamicProperties {
}

class DissociateProfileResponse extends phpDynamicProperties {
}

class CheckProfileCompliance_TaskResponse extends phpDynamicProperties {
	public $returnval; //ManagedObjectReference

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class ExportProfileResponse extends phpDynamicProperties {
	public $returnval; //string

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class CreateProfileResponse extends phpDynamicProperties {
	public $returnval; //ManagedObjectReference

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class QueryPolicyMetadataResponse extends phpDynamicProperties {
	public $returnval; //ProfilePolicyMetadata

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class FindAssociatedProfileResponse extends phpDynamicProperties {
	public $returnval; //ManagedObjectReference

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class UpdateClusterProfileResponse extends phpDynamicProperties {
}

class UpdateReferenceHostResponse extends phpDynamicProperties {
}

class UpdateHostProfileResponse extends phpDynamicProperties {
}

class ExecuteHostProfileResponse extends phpDynamicProperties {
	public $returnval; //ProfileExecuteResult

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class ApplyHostConfig_TaskResponse extends phpDynamicProperties {
	public $returnval; //ManagedObjectReference

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class GenerateConfigTaskListResponse extends phpDynamicProperties {
	public $returnval; //HostProfileManagerConfigTaskList

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class QueryHostProfileMetadataResponse extends phpDynamicProperties {
	public $returnval; //ProfileMetadata

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class QueryProfileStructureResponse extends phpDynamicProperties {
	public $returnval; //ProfileProfileStructure

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class CreateDefaultProfileResponse extends phpDynamicProperties {
	public $returnval; //ApplyProfile

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class UpdateAnswerFile_TaskResponse extends phpDynamicProperties {
	public $returnval; //ManagedObjectReference

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class RetrieveAnswerFileResponse extends phpDynamicProperties {
	public $returnval; //AnswerFile

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class ExportAnswerFile_TaskResponse extends phpDynamicProperties {
	public $returnval; //ManagedObjectReference

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class CheckAnswerFileStatus_TaskResponse extends phpDynamicProperties {
	public $returnval; //ManagedObjectReference

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class QueryAnswerFileStatusResponse extends phpDynamicProperties {
	public $returnval; //AnswerFileStatusResult

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class RemoveScheduledTaskResponse extends phpDynamicProperties {
}

class ReconfigureScheduledTaskResponse extends phpDynamicProperties {
}

class RunScheduledTaskResponse extends phpDynamicProperties {
}

class CreateScheduledTaskResponse extends phpDynamicProperties {
	public $returnval; //ManagedObjectReference

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class RetrieveEntityScheduledTaskResponse extends phpDynamicProperties {
	public $returnval; //ManagedObjectReference

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class CreateObjectScheduledTaskResponse extends phpDynamicProperties {
	public $returnval; //ManagedObjectReference

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class RetrieveObjectScheduledTaskResponse extends phpDynamicProperties {
	public $returnval; //ManagedObjectReference

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class OpenInventoryViewFolderResponse extends phpDynamicProperties {
	public $returnval; //ManagedObjectReference

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class CloseInventoryViewFolderResponse extends phpDynamicProperties {
	public $returnval; //ManagedObjectReference

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class ModifyListViewResponse extends phpDynamicProperties {
	public $returnval; //ManagedObjectReference

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class ResetListViewResponse extends phpDynamicProperties {
	public $returnval; //ManagedObjectReference

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class ResetListViewFromViewResponse extends phpDynamicProperties {
}

class DestroyViewResponse extends phpDynamicProperties {
}

class CreateInventoryViewResponse extends phpDynamicProperties {
	public $returnval; //ManagedObjectReference

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class CreateContainerViewResponse extends phpDynamicProperties {
	public $returnval; //ManagedObjectReference

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class CreateListViewResponse extends phpDynamicProperties {
	public $returnval; //ManagedObjectReference

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class CreateListViewFromViewResponse extends phpDynamicProperties {
	public $returnval; //ManagedObjectReference

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class RevertToSnapshot_TaskResponse extends phpDynamicProperties {
	public $returnval; //ManagedObjectReference

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class RemoveSnapshot_TaskResponse extends phpDynamicProperties {
	public $returnval; //ManagedObjectReference

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class RenameSnapshotResponse extends phpDynamicProperties {
}

class CheckCompatibility_TaskResponse extends phpDynamicProperties {
	public $returnval; //ManagedObjectReference

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class QueryVMotionCompatibilityEx_TaskResponse extends phpDynamicProperties {
	public $returnval; //ManagedObjectReference

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class CheckMigrate_TaskResponse extends phpDynamicProperties {
	public $returnval; //ManagedObjectReference

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class CheckRelocate_TaskResponse extends phpDynamicProperties {
	public $returnval; //ManagedObjectReference

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class ValidateCredentialsInGuestResponse extends phpDynamicProperties {
}

class AcquireCredentialsInGuestResponse extends phpDynamicProperties {
	public $returnval; //GuestAuthentication

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class ReleaseCredentialsInGuestResponse extends phpDynamicProperties {
}

class MakeDirectoryInGuestResponse extends phpDynamicProperties {
}

class DeleteFileInGuestResponse extends phpDynamicProperties {
}

class DeleteDirectoryInGuestResponse extends phpDynamicProperties {
}

class MoveDirectoryInGuestResponse extends phpDynamicProperties {
}

class MoveFileInGuestResponse extends phpDynamicProperties {
}

class CreateTemporaryFileInGuestResponse extends phpDynamicProperties {
	public $returnval; //string

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class CreateTemporaryDirectoryInGuestResponse extends phpDynamicProperties {
	public $returnval; //string

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class ListFilesInGuestResponse extends phpDynamicProperties {
	public $returnval; //GuestListFileInfo

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class ChangeFileAttributesInGuestResponse extends phpDynamicProperties {
}

class InitiateFileTransferFromGuestResponse extends phpDynamicProperties {
	public $returnval; //FileTransferInformation

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class InitiateFileTransferToGuestResponse extends phpDynamicProperties {
	public $returnval; //string

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class StartProgramInGuestResponse extends phpDynamicProperties {
	public $returnval; //long

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class ListProcessesInGuestResponse extends phpDynamicProperties {
	public $returnval; //GuestProcessInfo

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class TerminateProcessInGuestResponse extends phpDynamicProperties {
}

class ReadEnvironmentVariableInGuestResponse extends phpDynamicProperties {
	public $returnval; //string

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class DestroyPropertyFilterResponse extends phpDynamicProperties {
}

class CreateFilterResponse extends phpDynamicProperties {
	public $returnval; //ManagedObjectReference

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class RetrievePropertiesResponse extends phpDynamicProperties {
	public $returnval; //ObjectContent

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class CheckForUpdatesResponse extends phpDynamicProperties {
	public $returnval; //UpdateSet

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class WaitForUpdatesResponse extends phpDynamicProperties {
	public $returnval; //UpdateSet

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class CancelWaitForUpdatesResponse extends phpDynamicProperties {
}

class WaitForUpdatesExResponse extends phpDynamicProperties {
	public $returnval; //UpdateSet

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class RetrievePropertiesExResponse extends phpDynamicProperties {
	public $returnval; //RetrieveResult

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class ContinueRetrievePropertiesExResponse extends phpDynamicProperties {
	public $returnval; //RetrieveResult

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class CancelRetrievePropertiesExResponse extends phpDynamicProperties {
}

class CreatePropertyCollectorResponse extends phpDynamicProperties {
	public $returnval; //ManagedObjectReference

	function __construct($returnval = null) {
		$this->returnval = $returnval;
	}
}

class DestroyPropertyCollectorResponse extends phpDynamicProperties {
}
