// TODO: When migrating a site or installing a new site
// - This should be copied to settings.primaryredirect.php
// - $primarydomain needs to be set

if (isset($_ENV['PANTHEON_ENVIRONMENT']) && php_sapi_name() != 'cli') {
    // Redirect to https://$primary_domain in the Live environment
    if ($_ENV['PANTHEON_ENVIRONMENT'] === 'live') {
        /** TODO Replace www.example.com with your registered domain name */
        $primary_domain = 'www.example.com';
    }
    else {
        // Redirect to HTTPS on every Pantheon environment.
        $primary_domain = $_SERVER['HTTP_HOST'];
    }

    // Make sure we check the various ways in which a HTTP site can be accessed
    if ($_SERVER['HTTP_HOST'] != $primary_domain
        || !isset($_SERVER['HTTP_USER_AGENT_HTTPS'])
        || $_SERVER['HTTP_USER_AGENT_HTTPS'] != 'ON' )
        || (empty($_SERVER['HTTPS']) 
        || $_SERVER['HTTPS'] == "OFF") {

        # Name transaction "redirect" in New Relic for improved reporting (optional)
        if (extension_loaded('newrelic')) {
            newrelic_name_transaction("redirect");
        }

        header('HTTP/1.0 301 Moved Permanently');
        header('Location: https://'. $primary_domain . $_SERVER['REQUEST_URI']);
        exit();
    }
}

