<?php
#
# Custom Settings
# 20170719 - Clay

if (isset($_SERVER['PANTHEON_ENVIRONMENT'])) {
    $ps = json_decode($_SERVER['PRESSFLOW_SETTINGS'], TRUE);
    $settings['simplesamlphp_dir'] = '/srv/bindings/'. $ps['conf']['pantheon_binding'] .'/code/private/simplesamlphp';
    $conf['simplesamlphp_auth_installdir'] = '/srv/bindings/'. $ps['conf']['pantheon_binding'] .'/code/private/simplesamlphp';
}

if((empty($_SERVER['HTTPS']) || $_SERVER['HTTPS'] == "OFF") && (php_sapi_name() != "cli")) {
    header('HTTP/1.0 301 Moved Permanently');
    header('Location: https://'. $_SERVER['HTTP_HOST'] . $_SERVER['REQUEST_URI']);
    exit();
}
