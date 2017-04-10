<?php
	/**
	 * IMPORTANT: Place this script in your drupal home installation
	 * folder.
	 * Run this script using
	 * 
     *       sudo -u apache php fix_securityrev.php
	 * 
     * This script fixed problems associated with writable files on
     * the server as well as problems with anonymous content.
     *
	 * PS: Make sure to run the drush command from the correct path (set it down below) Or
	 * else, the checks will return false positives.
	 */
 
	// These vary across environments.
    $OWNER = "root";
    $GROUP = "apache";

    // Point this to your LOCAL drush path!
    $DRUSH_PATH = "/var/www/.composer/vendor/bin/drush";
	
    $HOST = "localhost";
    $ADMIN = "drupal_u";
    $PASS = "drupal";
    $DB = "drupal";
	// These are for your drupal database, and needed to set a user
	// to anonymous content.
	$CONTENT_OWNER = 1;
    // Ignore anon content that has this string because this is from
    // the custom course module.
    $IGNORE = "ppc";

    function main() {
        global $DRUSH_PATH;
        $output = shell_exec( escapeshellcmd($DRUSH_PATH)." secrev --raw");

        if ($output == NULL) {
            fwrite(STDERR, "Is shell_exec disabled on your machine? Or nor problems were found!");
            exit(1);
        }

        // Here are all the writable file and anon content problems
        // from the output of the drush command.
        $all = explode("\n", $output);	
        
        global $HOST, $ADMIN, $PASS, $DB;

        // Connect to a database
        $connect = mysql_connect($HOST, $ADMIN, $PASS);
        $select = mysql_select_db($DB);

        if (!$connect && !$select) {
            fwrite(STDERR, "Couldn't connect to the database! Be sure to put your credentials!\n");
            exit(1); // A response code other than 0 is a failure
        }

        echo "Looking through ...";
            
        global $OWNER, $GROUP, $CONTENT_OWNER, $IGNORE;

        //while ( ($line = fgets($handle)) !== false) {
        foreach ( $all as $line) {
            if (strpos($line, 'writable') !== FALSE) {
                $f_path = explode(":", $line)[0];
                fix_file_permission($f_path, $OWNER, $GROUP);
            }
            else if (strpos($line, 'anoncontent') !== FALSE) {
                $content = explode(":", $line)[0];
                fix_anon_content($content, $CONTENT_OWNER, $IGNORE);
            }
        }
            
    }


    /**
     * Sets the recommended Drupal file permission on a give file/directory
     */
    function fix_file_permission($path, $owner, $group) {
        if (is_dir($path)) {
            // Set directory to the right owner.
            $chown = chown($path, $owner);
            // Set directory to the right grp.
            $chgrp = chgrp($path, $group);
            // Remove write permission from group and other.
            $chmod = chmod($path, 0755);
        }
        else if (is_file($path)) {
            $chown = chown($path, $owner);
            $chgrp = chgrp($path, $group);
            $chmod = chmod($path, 0644);
        }

        if ($chwon && $chgrp && $chmod)
            echo "Fixed ".$path."\n";
        else
            fwrite(STDERR, "Couldn't fix the files. Check if chown, chgrp and chmod are allowed.\n")
    }

    /**
     * Assings anonymous content the admin user.
     */
    function fix_anon_content($content, $CONTENT_OWNER, $IGNORE) {
        $content = explode('=>', $content);
        $name = $content[1];
        $nid = $content[0];

        if (strpos($name, $IGNORE) == FALSE) {
            // Make sure the anon content is in the database.
            $q = "SELECT nid FROM node WHERE uid = 0 and nid=".$nid;
            // Then update it.
            $update = "UPDATE node SET uid=".$CONTENT_OWNER." WHERE uid = 0 and nid=";
            $res = mysql_query($q) or die (showError(0));
            
            while ($row = mysql_fetch_object($res)) {
                $nid = $row->nid;
                $update = $update.$nid;
                echo $update."\n";
            
                mysql_query($update) or die (showError());
                echo "Fixed Owner of Anon content: ".$name."\n";
            }
        }
        
        echo "Anonymous Content problems fixed\n";
    }

    function showError($which=1) {
        
        if ($which == 0)
            return "I could not query the database!\n".
                   "Failed to update Anon content!\n";


        return "*************************************\n".
               "The command Failed! Make sure to set the\n".
               "required variables in this script, such as\n".
               "your database details!\n".
               "**************************************\n";
    }

    main();
?>
