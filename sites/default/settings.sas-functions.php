<?php

if (file_exists(__DIR__ . '/site.php')) {
    include __DIR__ . "/site.php";
}


function isPantheonSite () {
	return(preg_match('@pantheonsite.io@',$_SERVER['HTTP_HOST']));
}


function isProxied() {
	// HTTP_X_FORWARDED_HOST is undefined when coming in through the load-balancer
	// HTTP_HOST == HTTP_X_FORWARDED_HOST for direct access to pantheon + via CDN
	// via proxy, HTTP_HOST -> 'live-sas-school.pantheonsite.io' while
	//   HTTP_X_FORWARDED_HOST -> 'www.sas.upenn.edu, live-sas-school.pantheonsite.io'
	return(	   isset($_SERVER['HTTP_X_FORWARDED_HOST']) 
        	&& ($_SERVER['HTTP_HOST'] != $_SERVER['HTTP_X_FORWARDED_HOST']));
}

function isHTTP() {
    // From https://pantheon.io/docs/domains/ 
    return (   !isset($_SERVER['HTTP_USER_AGENT_HTTPS']) 
            || $_SERVER['HTTP_USER_AGENT_HTTPS'] != 'ON'
            || empty($_SERVER['HTTPS']) 
            || $_SERVER['HTTPS'] == "OFF");
} 

function getCanonicalHost() {
	global $CanonicalHost;

	return($CanonicalHost);
}

function getBaseURL() {
	global $BaseURL;

	$URL = 'https://' . $_SERVER['HTTP_HOST'];
	if (isProxied() && isset($BaseURL) ) {
		$URL = $BaseURL;
	}

	return($URL);
}

function getEntityID() {
	global $EntityID;

	$ID = 'https://' . $_SERVER['HTTP_HOST'];
	if (isset($EntityID)) {
		$ID = $EntityID;
	}

	return($ID);
}

function redirectTo($url,$cache = True) {
	if (extension_loaded('newrelic')) {
		newrelic_name_transaction("redirect");
	}

	// From https://github.com/pantheon-systems/documentation/issues/1280
	if (!$cache) {
		header("Cache-Control: no-store, no-cache, must-revalidate, max-age=0");
		header("Cache-Control: post-check=0, pre-check=0", false);
		header("Pragma: no-cache");
	}
            
	header('HTTP/1.0 301 Moved Permanently');
	header('Location: '. $url);
	exit();
}
