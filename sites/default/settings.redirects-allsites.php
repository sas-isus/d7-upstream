<?php
/*
 * settings.redirects-site.php sets
 *  $primary_domain
 *  $ReWriteMap
 */

/* Include primary domain and any site specific redirects   */
/* THIS FILE MUST EXIST for primary domain redirect to work */
if (file_exists(__DIR__ . '/settings.redirects-site.php')) {
    include __DIR__ . "/settings.redirects-site.php";
}

/*
 * Use _ENV not _SERVER - https://pantheon.io/docs/read-environment-config/
 *
 * Ensure we're on https, redirect to primary domain and set up simplesaml
 */

if (isset($_ENV['PANTHEON_ENVIRONMENT']) && php_sapi_name() != 'cli') {
    // re-set primary domain if we're coming here via pantheonsite.io or 
    // the $primary_domain isn't set in settings.redirects-site.php.
    // Override the primary_domain with the $_SERVER['HTTP_HOST']
    if (preg_match('@pantheonsite.io@',$_SERVER['HTTP_HOST']) || !isset($primary_domain)) {
        $primary_domain = $_SERVER['HTTP_HOST'];
    }

    // From https://pantheon.io/docs/domains/
    // Make sure we check the various ways in which a HTTP site can be accessed
    if ($_SERVER['HTTP_HOST'] != $primary_domain
        || !isset($_SERVER['HTTP_USER_AGENT_HTTPS'])
        || $_SERVER['HTTP_USER_AGENT_HTTPS'] != 'ON'
        || empty($_SERVER['HTTPS']) 
        || $_SERVER['HTTPS'] == "OFF") {

        # Name transaction "redirect" in New Relic for improved reporting (optional)
        if (extension_loaded('newrelic')) {
            newrelic_name_transaction("redirect");
        }

        header('HTTP/1.0 301 Moved Permanently');
        header('Location: https://'. $primary_domain . $_SERVER['REQUEST_URI']);
        exit();
    }

    #
    # From https://pantheon.io/docs/shibboleth-sso/
    #  D7: $conf['simplesamlphp_auth_installdir'] = $_ENV['HOME'] .'/code/private/simplesamlphp';
    #  D8: $settings['simplesamlphp_dir'] = $_ENV['HOME'] .'/code/web/private/simplesamlphp';
    #
    if (file_exists($_ENV['HOME'] . '/code/web/private/simplesamlphp')) {
        $settings['simplesamlphp_dir'] = $_ENV['HOME'] . '/code/web/private/simplesamlphp';
    }
    else {
        $conf['simplesamlphp_auth_installdir'] = $_ENV['HOME'] . '/code/private/simplesamlphp';
    }
}

if (isset($RewriteMap) && (isset($_SERVER['argv'][1]) || isset($_SERVER['REQUEST_URI']))) {
    #
    # run as:
    # php settings.rewrites.php /uniconn
    #

    $oldurl = (php_sapi_name() == "cli") ? $_SERVER['argv'][1] : $_SERVER['REQUEST_URI'];

    foreach ($RewriteMap as $key => $value) {
        if (preg_match($key, $oldurl)) {
            $newurl = preg_replace($key,$value,$oldurl);
            if (isset($_ENV['PANTHEON_ENVIRONMENT'])) {
                # Name transaction "redirect" in New Relic for improved reporting (optional)
                if (extension_loaded('newrelic')) {
                    newrelic_name_transaction("redirect");
                }

                header('HTTP/1.0 301 Moved Permanently');
                header("Location: $newurl");
            }
            else {
                print("$oldurl => $newurl\n");
            }

            exit();
        }
    }
}
