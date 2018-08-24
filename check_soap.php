<?php
// Copyright (C) 2014-2016 Combodo SARL
//
//   This application is free software; you can redistribute it and/or modify	
//   it under the terms of the GNU Affero General Public License as published by
//   the Free Software Foundation, either version 3 of the License, or
//   (at your option) any later version.
//
//   iTop is distributed in the hope that it will be useful,
//   but WITHOUT ANY WARRANTY; without even the implied warranty of
//   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//   GNU Affero General Public License for more details.
//
//   You should have received a copy of the GNU Affero General Public License
//   along with this application. If not, see <http://www.gnu.org/licenses/>
/**
 * check_soap.php: stand-alone command line utility to test the SOAP connectivity to the vSphere server
 * 
 * Usage: fill the 'vsphere_uri' variable in the configuration file (conf/params.local.xml), then launch (from the command line):
 * php check_soap.php
 * 
 */


/**
 * Helper to execute an HTTP POST request
 * Source: http://netevil.org/blog/2006/nov/http-post-from-php-without-curl
 *         originaly named after do_post_request
 * Does not require cUrl but requires openssl for performing https POSTs.
 *
 * @param string $sUrl The URL to POST the data to
 * @param string $sData The raw data to POST
 * @param string $sOptionnalHeaders Additional HTTP headers as a string with newlines between headers
 * @param hash	$aResponseHeaders An array to be filled with reponse headers: WARNING: the actual content of the array depends on the library used: cURL or fopen, test with both !! See: http://fr.php.net/manual/en/function.curl-getinfo.php
 * @param hash $aCurlOptions An (optional) array of options to pass to curl_init. The format is 'option_code' => 'value'. These values have precedence over the default ones
 * @return string The result of the POST request
 * @throws Exception
 */
function DoPostRequest($sUrl, $sData, $sOptionnalHeaders = null, &$aResponseHeaders = null, $aCurlOptions = array())
{
	// $sOptionnalHeaders is a string containing additional HTTP headers that you would like to send in your request.
	$response = '';
	if (function_exists('curl_init'))
	{
		// If cURL is available, let's use it, since it provides a greater control over the various HTTP/SSL options
		// For instance fopen does not allow to work around the bug: http://stackoverflow.com/questions/18191672/php-curl-ssl-routinesssl23-get-server-helloreason1112
		// by setting the SSLVERSION to 3 as done below.
		$aHTTPHeaders = array();
		if ($sOptionnalHeaders !== null)
		{
			$aHeaders = explode("\n", $sOptionnalHeaders);
			foreach($aHeaders as $sHeaderString)
			{
				if(preg_match('/^([^:]): (.+)$/', $sHeaderString, $aMatches))
				{
					$aHTTPHeaders[$aMatches[1]] = $aMatches[2];
				}
			}
		}
		// Default options, can be overloaded/extended with the 4th parameter of this method, see above $aCurlOptions
		$aOptions = array(
			CURLOPT_RETURNTRANSFER	=> true,     // return the content of the request
			CURLOPT_HEADER			=> false,    // don't return the headers in the output
			CURLOPT_FOLLOWLOCATION	=> true,     // follow redirects
			CURLOPT_ENCODING		=> "",       // handle all encodings
			CURLOPT_USERAGENT		=> "spider", // who am i
			CURLOPT_AUTOREFERER		=> true,     // set referer on redirect
			CURLOPT_CONNECTTIMEOUT	=> 120,      // timeout on connect
			CURLOPT_TIMEOUT			=> 120,      // timeout on response
			CURLOPT_MAXREDIRS		=> 10,       // stop after 10 redirects
			CURLOPT_SSL_VERIFYHOST	=> 0,   	 // Disabled SSL Cert checks
			CURLOPT_SSL_VERIFYPEER	=> 0,   	 // Disabled SSL Cert checks
			// SSLV3 (CURL_SSLVERSION_SSLv3 = 3) is now considered as obsolete/dangerous: http://disablessl3.com/#why
			// but it used to be a MUST to prevent a strange SSL error: http://stackoverflow.com/questions/18191672/php-curl-ssl-routinesssl23-get-server-helloreason1112
			// CURLOPT_SSLVERSION		=> 3,
			CURLOPT_CUSTOMREQUEST	=> 'POST',
			CURLOPT_POSTFIELDS		=> $sData,
			CURLOPT_HTTPHEADER		=> $aHTTPHeaders,
		);
		$aAllOptions = $aCurlOptions + $aOptions;
		$ch = curl_init($sUrl);
		curl_setopt_array($ch, $aAllOptions);
		$response = curl_exec($ch);
		$iErr = curl_errno($ch);
		$sErrMsg = curl_error( $ch );
		$aHeaders = curl_getinfo( $ch );
		if ($iErr !== 0)
		{
			throw new Exception("Problem opening URL: $sUrl, $sErrMsg");
		}
		if (is_array($aResponseHeaders))
		{
			$aHeaders = curl_getinfo($ch);
			foreach($aHeaders as $sCode => $sValue)
			{
				$sName = str_replace(' ' , '-', ucwords(str_replace('_', ' ', $sCode))); // Transform "content_type" into "Content-Type"
				$aResponseHeaders[$sName] = $sValue;
			}
		}
		curl_close( $ch );
	}
	else
	{
		echo "Sorry curl is required to run this tool.\n";
	}
	return $response;
}
	
define('APPROOT', dirname(dirname(__FILE__)).'/');

require_once(APPROOT.'core/parameters.class.inc.php');
require_once(APPROOT.'core/utils.class.inc.php');

$aConfig = Utils::GetConfigFiles();
$sVSphereServerUrl = Utils::GetConfigurationValue('vsphere_uri', '');

echo "Connecting to https://$sVSphereServerUrl/sdk\n";

$sData = <<<EOF
<?xml version="1.0" encoding="UTF-8"?>
<SOAP-ENV:Envelope xmlns:SOAP-ENV="http://schemas.xmlsoap.org/soap/envelope/" xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns:ns1="urn:vim25"><SOAP-ENV:Body><ns1:RetrieveServiceContent><ns1:_this type="ServiceInstance">ServiceInstance</ns1:_this></ns1:RetrieveServiceContent></SOAP-ENV:Body></SOAP-ENV:Envelope>
EOF
;
$sResult = DoPostRequest('https://'.$sVSphereServerUrl.'/sdk', $sData, 'SOAPAction: "urn:vim25/5.0"');

if (preg_match('|^<\\?xml version="1.0" encoding="UTF-8"\\?>\n<soapenv:Envelope.+</soapenv:Envelope>$|s', $sResult))
{
	echo "\nOk, the response looks like a valid SOAP response.\n\n";
}
else
{
	echo "\nERROR, the response DOES NOT look like a valid SOAP response. See details below !!\n\n";
}

echo "--------------------- DEBUG ----------------\n";
echo "The request returned:\n$sResult\n";
echo "---------------------------------------------\n";
