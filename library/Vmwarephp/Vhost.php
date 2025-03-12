<?php

namespace Vmwarephp;
use Vmwarephp\Exception as Ex;

class Vhost {
	private $service;
    private string $host;
    private string $username;
    private string $password;
    private array $aProperties = [];

	function __construct($host, $username, $password, $options = []) {
		$this->host = $host;
		$this->username = $username;
		$this->password = $password;
        $this->options = $options;
	}

	function getPort() {
		$port = parse_url($this->host, PHP_URL_PORT);
		return $port ? : '443';
	}

    function __get($propertyName) {
        if (!array_key_exists($propertyName, $this->aProperties)) throw new \InvalidArgumentException('Property ' . $propertyName . ' not set on this object!');
        return $this->aProperties[$propertyName];
    }

    function __set($propertyName, $value) {
        $this->validateProperty($propertyName, $value);
        $this->aProperties[$propertyName] = $value;
    }

	function __call($method, $arguments) {
		if (!$this->service) $this->initializeService();
		return call_user_func_array(array($this->service, $method), $arguments);
	}

	function getApiType() {
		return $this->getServiceContent()->about->apiType;
	}

	function getApiVersion() {
		return $this->getServiceContent()->about->apiVersion;
	}

	function changeService(\Vmwarephp\Service $service) {
		$this->service = $service;
	}

	private function initializeService() {
		if (!$this->service)
			$this->service = \Vmwarephp\Factory\Service::makeConnected($this);
	}

	private function validateProperty($propertyName, $value) {
		if (in_array($propertyName, array('host', 'username', 'password')) && empty($value))
			throw new Ex\InvalidVhost('Vhost ' . ucfirst($propertyName) . ' cannot be empty!');
	}
}
