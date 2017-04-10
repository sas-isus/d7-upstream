<?php
/*
 * This page should live in a Cosign protected directory, as configured in httpd.conf
 * 
 * If no Cosign credentials are found, the user will be redirected to 
 * https://weblogin.pennkey.upenn.edu/login
 * 
 * otherwise, redirect the user back to 
 * https://$_SERVER['HTTP_HOST']/pennweblogin/confirm?$_SERVER['QUERY_STRING']
 */

$request_array = split('/',$_SERVER['REQUEST_URI']);

$root = (($request_array[1] == 'sites') ? '' : '/'.$request_array[1]);

header('Location: https://'.$_SERVER['SERVER_NAME'].$root.'/pennweblogin/confirm?'.urldecode($_SERVER['QUERY_STRING']));

?>
