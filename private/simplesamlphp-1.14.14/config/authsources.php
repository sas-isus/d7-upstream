<?php

// getting environment info

if (isset($_ENV['PANTHEON_SITE_NAME'])) {
	$SiteName = $_ENV['PANTHEON_SITE_NAME'];
}
else {
	$SiteName = 'local';
}

if (file_exists($_SERVER['DOCUMENT_ROOT']. '/sites/default/settings.sas-functions.php')) {
        require_once($_SERVER['DOCUMENT_ROOT']. '/sites/default/settings.sas-functions.php');
}

//$EntityID = getEntityID();

$config = array(

	// This is a authentication source which handles admin authentication.
	'admin' => array(
		// The default is to use core:AdminPassword, but it can be replaced with
		// any authentication source.

		'core:AdminPassword',
	),
	// An authentication source which can authenticate against both SAML 2.0
	// and Shibboleth 1.3 IdPs.
	'default-sp' => array(
    'saml:SP',
		'privatekey' => $SiteName . '.pem',
		'certificate' => $SiteName . '.crt',
		'entityID' => NULL,
		'idp' => 'https://idp.pennkey.upenn.edu/idp/shibboleth',
		'discoURL' => NULL,
		'authproc' => array(
			50 => array( // map attributes to names rather than numeric ids
				'class' => 'core:AttributeMap', 'oid2name'
			),
			60 => array( // replace colons in group names
				'class'   => 'core:AttributeAlter',
				'subject' => 'eduPersonEntitlement',
				'pattern' => '/:/',
				'replacement' => '.'
			),
		),
	),
);
