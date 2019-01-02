<?php

if (file_exists(__DIR__ . '/settings.sas-functions.php')) {
    require_once __DIR__ . "/settings.sas-functions.php";
}

/*
 * Use _ENV not _SERVER - https://pantheon.io/docs/read-environment-config/
 *
 */

if (isset($_ENV['PANTHEON_ENVIRONMENT']) && php_sapi_name() != 'cli') {
 
	// Ensure we're on https
	if (isHTTP()) {
		$NewURL = 'https://' . $_SERVER['HTTP_HOST'];
		if (isset($_SERVER['REQUEST_URI'])) {
			$NewURL = $NewURL . $_SERVER['REQUEST_URI'];
		}

		redirectTo($NewURL);
	}

    	// keep any drupal_hash_salt we set in setting.php or other files
   	if (isset($drupal_hash_salt)) {
       		$pf = json_decode($_SERVER['PRESSFLOW_SETTINGS']);
       		$pf->drupal_hash_salt = $drupal_hash_salt;
        	$_SERVER['PRESSFLOW_SETTINGS'] = json_encode($pf);
    	}


	// redirect to BaseURL unless we're being proxied or we're on a pantheon site -- The proxy is supposed to handle redirections
	// Never let this redirect be cached in case we're proxied at some point -- just don't do it.
	$CanonicalHost = getCanonicalHost();

	$CurrentHost = $_SERVER['HTTP_HOST'];
	$RequestURI = $_SERVER['REQUEST_URL'];
	if (!isProxied() && !isPantheonSite() && isset($CanonicalHost) && $CurrentHost != $CanonicalHost) {
		$NewURL = 'https://' . $CanonicalHost . $RequestURL;
		redirectTo($NewURL, False);
	}
}

#
# Set the simplesaml directory path for d7, d8 and d8-refactored sites.
#
# This could be pulled out and redone by each repo, or just cherry pick the code here.
#
# From https://pantheon.io/docs/shibboleth-sso/
#  D7: $conf['simplesamlphp_auth_installdir'] = $_ENV['HOME'] .'/code/private/simplesamlphp';
#  D8-upstream: $settings['simplesamlphp_dir'] = $_ENV['HOME'] .'/code/private/simplesamlphp';
#  D8-refactored: $settings['simplesamlphp_dir'] = $_ENV['HOME'] .'/code/web/private/simplesamlphp';
#
if (isset($_ENV['HOME'])) {
	if (isD8()) {
		if (file_exists($_ENV['HOME'] . '/code/web/private/simplesamlphp')) {
			$settings['simplesamlphp_dir'] = $_ENV['HOME'] . '/code/web/private/simplesamlphp';
		}
		else {
			$settings['simplesamlphp_dir'] = $_ENV['HOME'] . '/code/private/simplesamlphp';
		}
	}
	else {
		$conf['simplesamlphp_auth_installdir'] = $_ENV['HOME'] . '/code/private/simplesamlphp';
	}
}

#
# Deal with site specific recdirects
#
if (isset($RewriteMap) && (isset($_SERVER['argv'][1]) || isset($_SERVER['REQUEST_URI']))) {
    #
    # run as:
    # php settings.redirects-allsites.php /uniconn
    # to see the redirects for each url
    #

    $oldurl = (php_sapi_name() == "cli") ? $_SERVER['argv'][1] : $_SERVER['REQUEST_URI'];

    foreach ($RewriteMap as $key => $value) {
        if (preg_match($key, $oldurl)) {
            $newurl = preg_replace($key,$value,$oldurl);
            if (isset($_ENV['PANTHEON_ENVIRONMENT'])) {
		redirectTo($newurl);
            }
            else {
                print("$oldurl => $newurl\n");
            }

            exit();
        }
    }
}
