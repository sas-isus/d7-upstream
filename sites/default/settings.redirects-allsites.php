<?php
/*
 * settings.redirects-site.php sets
 *  $primary_domain
 *  $ReWriteMap
 */

/* Include primary domain and any site specific redirects   */
/* THIS FILE MUST EXIST for primary domain redirect to work */

if (file_exists(__DIR__ . '/settings.redirects-functions.php')) {
    require_once __DIR__ . "/settings.redirects-functions.php";
}

// print("'_SERVER[DOCUMENT_ROOT] = '".$_SERVER['DOCUMENT_ROOT']."', _ENV[HOME] = '".$_ENV['HOME']."'");

/*
 * Use _ENV not _SERVER - https://pantheon.io/docs/read-environment-config/
 *
 * Ensure we're on https, redirect to primary domain and set up simplesaml
 */
if (isset($_ENV['PANTHEON_ENVIRONMENT']) && php_sapi_name() != 'cli') {

    // keep any drupal_hash_salt we set in setting.php or other files
    if (isset($drupal_hash_salt)) {
    	$pf = json_decode($_SERVER['PRESSFLOW_SETTINGS']);
    	$pf->drupal_hash_salt = $drupal_hash_salt;
    	$_SERVER['PRESSFLOW_SETTINGS'] = json_encode($pf);
    }

    $CanonicalHost = getCanonicalHost();
    $ClientHost = getClientHost();

    // echo "allsites: CanonicalHost = '$CanonicalHost', ClientHost = '$ClientHost'";

    //debug_print_backtrace();
    if (($CanonicalHost != $ClientHost) || isHTTP()) {
	redirectTo('https://'. $CanonicalHost . $_SERVER['REQUEST_URI']);
    }
}

#
# From https://pantheon.io/docs/shibboleth-sso/
#  D7: $conf['simplesamlphp_auth_installdir'] = $_ENV['HOME'] .'/code/private/simplesamlphp';
#  D8-upstream: $settings['simplesamlphp_dir'] = $_ENV['HOME'] .'/code/private/simplesamlphp';
#  D8-refactored: $settings['simplesamlphp_dir'] = $_ENV['HOME'] .'/code/web/private/simplesamlphp';
#
# Above document says to use _ENV[HOME], but _SERVER[DOCUMENT_ROOT] handles whether there is a web directory
#
if (isset($_ENV['HOME'])) {
    if (isD8()) {
        $settings['simplesamlphp_dir'] = getDocRoot() . '/private/simplesamlphp';
	// print("settings['simplesamlphp_dir'] = '" . $settings['simplesamlphp_dir'] . "'\n");
    }
    else {
        $conf['simplesamlphp_auth_installdir'] = getDocRoot(). '/private/simplesamlphp';
	// print("conf['simplesamlphp_auth_installdir'] = '" . $conf['simplesamlphp_auth_installdir'] . "'\n");
    }
}

if (isset($RewriteMap) && (isset($_SERVER['argv'][1]) || isset($_SERVER['REQUEST_URI']))) {
    #
    # run as:
    # php settings.redirects-allsites.php /uniconn
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
