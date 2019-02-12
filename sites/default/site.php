<?php
	//
	// Copy from default.site.php to set the 
	// EntityID, BaseURL, drupal_hash_salt, or RewriteMap
	//

	//
	// EntityID has to be set for simplesaml to work.
	//
	global $EntityID;
	$EntityID = 'https://africana.sas.upenn.edu';

	//
	// The BaseURL is the URL you want users to access the site by.
	// for subsites, it will be something like 
	//	https://www.sas.upenn.edu/katz
	// for non-proxied sites it might be for prefering 
	//	www.bio.upenn.edu
	// over
	//	bio.upenn.edu
	//
	// global $BaseURL;
	// $BaseURL = 'https://www.sas.upenn.edu/strategic-plan';

	// Pantheon randomly generates a drupal hash salt as part of the 
	// environment.  This will conflict with any drupal hash salt 
	// from migrated site.  Code in settings.sas.php will override
	// the pantheon drupal hash salt with this one.
	//
	// global $drupal_hash_salt;
	// $drupal_hash_salt = 'abc';

	// RewriteMap example
	//
	// global $RewriteMap;
	// $RewriteMap = array(
	//                     '@^/foo/bar.htm$@'        => '/node/1',
	//                     '@^/foo/index.html$@'     => '/node/1',
	//                    );
?>
