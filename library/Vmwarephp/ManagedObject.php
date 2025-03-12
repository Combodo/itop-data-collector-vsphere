<?php
namespace Vmwarephp;

class ManagedObject {
	private $reference;
	protected $vmwareService;
    private array $aProperties = [];

	function __construct(Service $vmwareService, \ManagedObjectReference $managedObjectReference) {
		$this->vmwareService = $vmwareService;
		$this->reference = $managedObjectReference;
	}

	function getParentHost() {
		return $this->vmwareService->getVhostHost();
	}

    function __get($propertyName) {
        if (!array_key_exists($propertyName, $this->aProperties)) {
            $queryForProperty = 'get' . ucfirst($propertyName);
            return $this->$queryForProperty();
        }
        return $this->aProperties[$propertyName];
    }

    function __set($propertyName, $propertyValue) {
        $this->aProperties[$propertyName] = $propertyValue;
    }

	function getReferenceType() {
		return $this->reference->type;
	}

	function getReferenceId() {
		return $this->reference->_;
	}

	function toReference() {
		return $this->reference;
	}

	function __call($method, $arguments) {
		return $this->vmwareService->$method($this, $arguments);
	}

	function equals(ManagedObject $managedObject) {
		return $this->toReference() == $managedObject->toReference() && $this->getParentHost() == $managedObject->getParentHost();
	}
}