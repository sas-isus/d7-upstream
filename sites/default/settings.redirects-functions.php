<?php

if (file_exists(__DIR__ . '/settings.redirects-site.php')) {
    include __DIR__ . "/settings.redirects-site.php";
}


function isPantheonSite () {
	return(preg_match('@pantheonsite.io@',$_SERVER['HTTP_HOST']));
}

function isD7() {
	return(file_exists($_SERVER['DOCUMENT_ROOT']. '/sites/all/modules'));
}

function isD8() {
	return(isset($_ENV['HOME']) && (file_exists($_ENV['HOME'].'/code/web') || file_exists($_ENV['HOME'].'/code/modules/contrib')));
}

function getDocRoot() {
	if (isset($_ENV['HOME']) && (file_exists($_ENV['HOME'].'/code/web'))) {
		return($_ENV['HOME'].'/code/web');
	}

	return($_ENV['HOME'].'/code');
}

function isProxied() {
	// HTTP_X_FORWARDED_HOST is undefined when coming in through the load-balancer
	// HTTP_HOST == HTTP_X_FORWARDED_HOST for direct access to pantheon + via CDN
	// via proxy, HTTP_HOST -> 'live-sas-school.pantheonsite.io' while
	//   HTTP_X_FORWARDED_HOST -> 'www.sas.upenn.edu, live-sas-school.pantheonsite.io'
	return(	   isset($_SERVER['HTTP_X_FORWARDED_HOST']) 
        	&& ($_SERVER['HTTP_HOST'] != $_SERVER['HTTP_X_FORWARDED_HOST']));
}


function getCanonicalHost() {
	global $primary_domain;

	$CanonicalHost = $_SERVER['HTTP_HOST'];
	if (isset($primary_domain)) {
		if (!isPantheonSite() || isProxied()) {
			// CDN or load balancer if not a pantheonsite
			// or else we are a pantheonsite and need to check if we're proxied
			$CanonicalHost = $primary_domain;
		}
	}

	return($CanonicalHost);
}

function getClientHost() {
	if (   isset($_SERVER['HTTP_X_FORWARDED_HOST'])
	    && preg_match('@^(.*?)(,|$)@',$_SERVER['HTTP_X_FORWARDED_HOST'],$match)
	    && (count($match) > 1)) {
		return($match[1]);
	}
	else {
		return($_SERVER['HTTP_HOST']);
	}
}


function redirectTo($url) {
	if (extension_loaded('newrelic')) {
		newrelic_name_transaction("redirect");
	}
            
	header('HTTP/1.0 301 Moved Permanently');
	header('Location: '. $url);
	exit();
}

function isHTTP() {
    // From https://pantheon.io/docs/domains/ 
    return (   !isset($_SERVER['HTTP_USER_AGENT_HTTPS']) 
            || $_SERVER['HTTP_USER_AGENT_HTTPS'] != 'ON'
            || empty($_SERVER['HTTPS']) 
            || $_SERVER['HTTPS'] == "OFF");
} 

