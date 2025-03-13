<?php

namespace Vmwarephp;
use Vmwarephp\Exception as Ex;

class Vhost {
    private  array $aProperties = [];

	function __construct($host, $username, $password) {
		$this->aProperties['host'] = $host;
		$this->aProperties['username'] = $username;
		$this->aProperties['password'] = $password;
	}

	function getPort() {
		$port = parse_url($this->host, PHP_URL_PORT);
		return $port ? : '443';
	}

    function __get($propertyName) {
        if (!array_key_exists($propertyName, $this->aProperties)) {
            throw new \InvalidArgumentException('Property ' . $propertyName . ' not set on this object!');
        }
        return $this->aProperties[$propertyName];
    }

    function __set($propertyName, $value) {
        $this->validateProperty($propertyName, $value);
        $this->aProperties[$propertyName] = $value;
    }

	function __call($method, $arguments) {
		if (!array_key_exists('service', $this->aProperties)) {
            $this->initializeService();
        }
		return call_user_func_array(array($this->aProperties['service'], $method), $arguments);
	}

	function getApiType() {
		return $this->getServiceContent()->about->apiType;
	}

	function getApiVersion() {
		return $this->getServiceContent()->about->apiVersion;
	}
	
	function changeService(\Vmwarephp\Service $service) {
		$this->aProperties['service'] = $service;
	}

	private function initializeService() {
        if (!array_key_exists('service', $this->aProperties)) {
            $this->aProperties['service'] = \Vmwarephp\Factory\Service::makeConnected($this);
        }
	}

	private function validateProperty($propertyName, $value) {
		if (in_array($propertyName, array('host', 'username', 'password')) && empty($value))
			throw new Ex\InvalidVhost('Vhost ' . ucfirst($propertyName) . ' cannot be empty!');
	}
}
