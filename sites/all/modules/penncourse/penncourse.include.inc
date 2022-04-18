<?php
/**
 * @file
 * penncourse.include.inc
 *
 * utility functions for the PennCourse module
 */

/**
 * function penncourse_build_course_node
 *
 * Create or update course nodes (pc_course) based on data passed in $values_array
 * @param integer $nid
 * @param array $values_array
 */
function penncourse_build_course_node($nid = NULL, $values_array) {
    global $user;
    // we want the author of this content to be a dedicated user account, penncourse_user
    $current_uid = NULL;
    $penncourse_user = user_load_by_name('penncourse_user');
    if ($penncourse_user) {
        $current_uid = $user->uid;
        $user = $penncourse_user;
    }
    module_load_include('inc', 'node', 'node.pages');

    pcpm($values_array);

    if ($nid) {
        $action = 'updating course node: ' . $nid . '[nid] ' . $values_array['course_id'] . '[course_id]';
        $node = node_load($nid, NULL, TRUE);
    }
    else {
        $action = 'new course node: ' . $values_array['course_id'] . '[course_id]';
        $node = new stdClass;
        $node->type = 'pc_course';
        node_object_prepare($node);
        $node->language = LANGUAGE_NONE;
        // $node->uid = $user->uid;
        $node->uid = $user->uid;
        $node->name = $user->name;
        $node->created = REQUEST_TIME;
        $node->status = 1;
        $node->promote = 0;
        $node->comment = 0;
    }

    $node->title = $values_array['course_id'] . ' - ' . $values_array['title'];
    $node->field_pc_descr[$node->language][0]['value'] = $values_array['descr'];
    // $node->field_pc_syllabus[$node->language][0]['url'] = $values_array['syllabus_url'];
    $node->field_pc_course_id[$node->language][0]['value'] = $values_array['course_id'];
    $node->field_pc_title[$node->language][0]['value'] = $values_array['title'];
    $node->field_pc_term[$node->language][0]['value'] = $values_array['term'];
    // $node->field_pc_term_session[$node->language][0]['value'] = $values_array['term_session'];
    $node->field_pc_subj_area[$node->language][0]['value'] = $values_array['subj_area'];
    $node->field_pc_dist_req[$node->language][0]['value'] = $values_array['dist_req'];
    // $node->field_pc_status[$node->language][0]['value'] = $values_array['status'];
    $node->field_pc_level[$node->language][0]['value'] = $values_array['level'];

    node_save($node);
    pcpm($node);
    watchdog('penncourse cron', $action . '<br />' . l($node->title, 'node/' . $node->nid), array(), WATCHDOG_NOTICE);
    $nid = $node->nid;
    unset($node);

    if ($current_uid !== NULL) {
        // reload our original user
        $user = user_load($current_uid);
    }
    return $nid;
} // function penncourse_build_course_node

/**
 * function penncourse_build_section_node
 *
 * Create or update section nodes (pc_section) based on data passed in $values_array
 * @param integer $nid
 * @param array $values_array
 */
function penncourse_build_section_node($nid = NULL, $values_array) {
    global $user;
    // we want the author of this content to be a dedicated user account, penncourse_user
    $current_uid = NULL;
    $penncourse_user = user_load_by_name('penncourse_user');
    if ($penncourse_user) {
        $current_uid = $user->uid;
        $user = $penncourse_user;
    }
    module_load_include('inc', 'node', 'node.pages');

    pcpm($values_array);

    if ($nid) {
        $action = 'updating section node: ' . $nid . '[nid] ' . $values_array['section_id'] . '[section_id]';
        $node = node_load($nid, NULL, TRUE);
    }
    else {
        $action = 'new section node: ' . $values_array['section_id'] . '[section_id]';
        $node = new stdClass;
        $node->type = 'pc_section';
        node_object_prepare($node);
        $node->language = LANGUAGE_NONE;
        // $node->uid = $user->uid;
        $node->uid = 1;
        $node->name = 'administrator';
        $node->created = REQUEST_TIME;
        $node->status = 1;
        $node->promote = 0;
        $node->comment = 0;
    }

    $node->title = $values_array['course_id'] . ' - ' . $values_array['title'];
    // $node->field_pc_descr[0]['value'] = $values_array['descr']; this field is maintained locally by departments
    $node->field_pc_instructors[$node->language][0]['value'] = $values_array['instructors'];
    $node->field_pc_instructors[$node->language][0]['format'] = 'penncourse_format'; // we need to set formats too
    if ($values_array['status'] == 'X') {
        $node->field_pc_meeting[$node->language][0]['value'] = 'CANCELED';
    }
    else {
        $node->field_pc_meeting[$node->language][0]['value'] = $values_array['meeting'];
    }
    $node->field_pc_meeting[$node->language][0]['format'] = 'penncourse_format'; // we need to set formats too
    $node->field_pc_title[$node->language][0]['value'] = $values_array['title'];
    $node->field_pc_location[$node->language][0]['value'] = $values_array['location'];
    $node->field_pc_location[$node->language][0]['format'] = 'penncourse_format'; // we need to set formats too
    $node->field_pc_section_id[$node->language][0]['value'] = $values_array['section_id'];
    $node->field_pc_course[$node->language][0]['nid'] = $values_array['course'];
    $node->field_pc_subj_area[$node->language][0]['value'] = $values_array['subj_area'];
    $node->field_pc_term[$node->language][0]['value'] = $values_array['term'];
    $node->field_pc_term_session[$node->language][0]['value'] = $values_array['term_session'];
    $node->field_pc_activity[$node->language][0]['value'] = $values_array['activity'];
    $node->field_pc_course_no[$node->language][0]['value'] = $values_array['course_no'];
    $node->field_pc_section_no[$node->language][0]['value'] = $values_array['section_no'];
    $node->field_pc_course_int[$node->language][0]['value'] = $values_array['course_no'];
    $node->field_pc_section_int[$node->language][0]['value'] = $values_array['section_no'];
    $node->field_pc_xlist[$node->language][0]['value'] = $values_array['xlist'];
    $node->field_pc_xlist[$node->language][0]['format'] = 'penncourse_format'; // we need to set formats too
    $node->field_pc_syllabus_url[$node->language][0]['url'] = $values_array['syllabus_url'];
    $node->field_pc_status[$node->language][0]['value'] = $values_array['status'];
    $node->field_pc_course_id[$node->language][0]['value'] = $values_array['course_id'];
    $node->field_pc_course[$node->language][0]['target_id'] = $values_array['course_nid'];
    $node->field_pc_course[$node->language][0]['target_type'] = 'node';
    $node->field_pc_level[$node->language][0]['value'] = $values_array['level'];
    $node->field_pc_sec_reg_ctrl[$node->language][0]['value'] = $values_array['notes'];
    $node->field_pc_sec_reg_ctrl[$node->language][0]['format'] = 'penncourse_format'; // we need to set formats too

    node_save($node);
    watchdog('penncourse cron', $action . '<br />' . l($node->title, 'node/' . $node->nid), array(), WATCHDOG_NOTICE);
    $nid = $node->nid;
    unset($node);

    if ($current_uid !== NULL) {
        // reload our original user
        $user = user_load($current_uid);
    }
    return $nid;
} // function penncourse_build_section_node

/**
 * function penncourse_dynamic_terms()
 *
 * Copied over from LPSCPS module, not currently used
 * Creates a text list for populating a drop down of terms.
 * Accepts number of TERMS both forward (from current year) and back.
 */
function penncourse_dynamic_terms($number_forward, $number_backward) {

    $year = intval(date(Y));
    $year_min = intval($year - ($number_backward / 3));
    $year_max = intval($year + ($number_forward / 3));
    $year_increment = $year_min;
    $term_codes = array('A', 'B', 'C');
    $seasons = array(' Spring', ' Summer', ' Fall');
    $terms = array();

    while ($year_increment <= $year_max) { //loop through years from min to max
        for ($i = 0; $i < 3; $i++) { //increment season
            $terms[$year_increment . $term_codes[$i]] = $year_increment . $seasons[$i];
        }
        $year_increment++;
    }
    //create drupal option list
    $term_options = array();
    foreach ($terms as $key => $value) {
        $term_options[$key] = $value;
    }

    return $term_options;
} // function penncourse_dynamic_terms

/**
 * function penncourse_session_descriptions
 *
 * Copied over from LPSCPS module, not currently used
 * return the session descriptions used for the various Summer Session codes
 */
function penncourse_session_descriptions() {
    return array('' => "12-Week Session",
        '1' => "6-Week Summer Session I",
        '2' => "6-Week Summer Session II",
        'S' => "Special Session");
} // function penncourse_session_descriptions

/**
 * function _penncourse_load_keyed_nids($type_name, $field_name)
 *
 * Copied over from LPSCPS module, not currently used
 * returns an array of nids (node id's) keyed by the field value specified by $field_name
 * may only be useful in the case of simple content types with a single identifying key field
 */
function _penncourse_load_keyed_nids($type_name, $field_name) {
    // get database info about content fields
    $db_info = penncourse_db_info($type_name, array($field_name));

    $nids = array();
    // get nids and the key specified by $field_name
    // we need to build the query string with the table and column names first
    $sql = sprintf("SELECT DISTINCT(n.nid) AS nid,
                            c.%s AS %s
                            FROM {node} n
                            LEFT JOIN {%s} c ON n.vid = c.vid
                            WHERE n.type in (:type)
                            GROUP BY nid
                            ORDER BY %s ASC",
        $db_info[$field_name]['column'],
        $field_name,
        $db_info[$field_name]['table'],
        $field_name
    );

    // now we can use the db_query parameterization
    $results = db_query($sql,
        array(':type' => $type_name));


    foreach ($results as $key_array) {
        $nids[$key_array->$field_name] = $key_array->nid;
    }
    unset($results);

    return $nids;

} // function _penncourse_load_keyed_nids

/**
 * function penncourse_load_course_nids
 *
 * returns an array of nids (node id's) keyed by the CPS course_key value for that course record
 * lookup is restricted to a single term
 * @param integer $year
 * @param string $subj_area
 */
function penncourse_load_course_nids($term, $subj_area = NULL) {
    if ($term) {
        // get database info about course fields
        $db_info = penncourse_db_info('pc_course', array('field_pc_course_id', 'field_pc_term', 'field_pc_subj_area'));

        $nids = array();
        // get nids and the course_key
        // this first string is just for debugging
        $sql = sprintf("			SELECT 		n.nid AS nid,
   																	c.%s AS field_pc_course_id,
   																	t.%s AS field_pc_term
 												 	FROM 			{node} n
 												 	LEFT JOIN {%s} t ON n.nid = t.entity_id
 												 	LEFT JOIN {%s} c ON n.nid = c.entity_id
 												 	LEFT JOIN {%s} s ON n.nid = s.entity_id
 												 	WHERE 		(n.type in ('pc_course'))
 												 	            AND (t.%s = '%s')
 												 	            AND (s.%s = '%s')
   											 	ORDER BY 	field_pc_course_id ASC",
            $db_info['field_pc_course_id']['column'],
            $db_info['field_pc_term']['column'],
            $db_info['field_pc_term']['table'],
            $db_info['field_pc_course_id']['table'],
            $db_info['field_pc_subj_area']['table'],
            $db_info['field_pc_term']['column'],
            $term,
            $db_info['field_pc_subj_area']['column'],
            $subj_area);
        pcpm('course node lookup SQL: ' . $sql);

        // now build the query string with table names, leaving named placeholders for db_query parameter substitution
        $sql = sprintf("SELECT    n.nid AS nid,
                                  c.%s AS field_pc_course_id,
                                  t.%s AS field_pc_term
                        FROM      {node} n
                                  LEFT JOIN {%s} t ON n.nid = t.entity_id
                                  LEFT JOIN {%s} c ON n.nid = c.entity_id
                                  LEFT JOIN {%s} s ON n.nid = s.entity_id
                        WHERE     (n.type in ('pc_course'))
                                  AND (t.%s = :term)
                                  AND (s.%s = :subject)
                        ORDER BY  field_pc_course_id ASC",
            $db_info['field_pc_course_id']['column'],
            $db_info['field_pc_term']['column'],
            $db_info['field_pc_term']['table'],
            $db_info['field_pc_course_id']['table'],
            $db_info['field_pc_subj_area']['table'],
            $db_info['field_pc_term']['column'],
            $db_info['field_pc_subj_area']['column']);

        // now we use that prepared statement with our query parameters
        $results = db_query($sql,
            array(':term' => $term,
                ':subject' => $subj_area));

        foreach ($results as $key_array) {
            $nids[trim($key_array->field_pc_term) . '-' . trim($key_array->field_pc_course_id)] = $key_array->nid;
        }
        unset($results);

        return $nids;

    }
    else {
        return NULL;
    }
} // function penncourse_load_course_nids

/**
 * function penncourse_load_section_nids
 *
 * returns an array of nids (node id's) keyed by the CPS course_key value for that course record
 * lookup is restricted to a single term
 * @param integer $year
 * @param string $subj_area
 */
function penncourse_load_section_nids($term, $subj_area = NULL) {
    if ($term) {
        // get database info about course fields
        $db_info = penncourse_db_info('pc_section', array('field_pc_section_id', 'field_pc_term', 'field_pc_subj_area'));

        $nids = array();
        // get nids and the course_key
        // we just build this string for debugging
        $sql = sprintf("			SELECT 		n.nid AS nid,
   																	c.%s AS field_pc_section_id,
   																	t.%s AS field_pc_term
 												 	FROM 			{node} n
 												 	LEFT JOIN {%s} t ON n.nid = t.entity_id
 												 	LEFT JOIN {%s} c ON n.nid = c.entity_id
 												 	LEFT JOIN {%s} s ON n.nid = s.entity_id
 												 	WHERE 		(n.type in ('pc_section'))
 												 	            AND (t.%s = '%s')
 												 	            AND (s.%s = '%s')
   											 	ORDER BY 	field_pc_section_id ASC",
            $db_info['field_pc_section_id']['column'],
            $db_info['field_pc_term']['column'],
            $db_info['field_pc_term']['table'],
            $db_info['field_pc_section_id']['table'],
            $db_info['field_pc_subj_area']['table'],
            $db_info['field_pc_term']['column'],
            $term,
            $db_info['field_pc_subj_area']['column'],
            $subj_area);
        pcpm('section node lookup SQL: ' . $sql);

        // now build the query string with table names, leaving named placeholders for db_query parameter substitution
        $sql = sprintf("SELECT        n.nid AS nid,
                                      c.%s AS field_pc_section_id,
                                      t.%s AS field_pc_term
                        FROM          {node} n
                                      LEFT JOIN {%s} t ON n.nid = t.entity_id
                                      LEFT JOIN {%s} c ON n.nid = c.entity_id
                                      LEFT JOIN {%s} s ON n.nid = s.entity_id
                        WHERE         (n.type in ('pc_section'))
                                      AND (t.%s = :term)
                                      AND (s.%s = :subject)
                        ORDER BY      field_pc_section_id ASC",
            $db_info['field_pc_section_id']['column'],
            $db_info['field_pc_term']['column'],
            $db_info['field_pc_term']['table'],
            $db_info['field_pc_section_id']['table'],
            $db_info['field_pc_subj_area']['table'],
            $db_info['field_pc_term']['column'],
            $db_info['field_pc_subj_area']['column']);

        // now we use that prepared statement with our query parameters
        $results = db_query($sql,
            array(':term' => $term,
                ':subject' => $subj_area));

        pcpm('section node lookup SQL: ' . $sql);

        foreach ($results as $key_array) {
            $nids[trim($key_array->field_pc_term) . '-' . trim($key_array->field_pc_section_id)] = $key_array->nid;
        }
        unset($results);

        return $nids;
    }
    else {
        return NULL;
    }
} // function penncourse_load_section_nids

/**
 * function penncourse_process_subj_area($subj_area,$year)
 * processes the course and section entries for a single subject area
 * older versions supported loading historical data (see d7 branch)
 * currently only loads data based on available terms from web service
 *
 * $year parameter is now ignored (see above)
 */
function penncourse_process_subj_area($subj_area, $year = NULL) {
  $section_params = variable_get('penncourse_section_params', '');
  $terms = $section_params->available_terms_map;
  foreach ($terms as $key => $term) {
    pcpm($key, $subj_area);
    penncourse_load_sections_by_subj($key, $subj_area);
  }
} // function penncourse_process_subj_area()

/**
 * function penncourse_update_section_params
 *
 * updates the variable penncourse_section_params with the latest search
 * parameters from the section search web service
 */
function penncourse_update_section_params() {
    $result = penncourse_retrieve_section_params();

    if (!isset($result->error_text)) {
        variable_set('penncourse_section_params', $result);
    }
    else {
        watchdog('penncourse cron', 'exception: ' . $result->error_text, array(), WATCHDOG_NOTICE);
    }
}

/**
 * function penncourse_load_sections_by_subj
 *
 * Load section data from web service and build
 * section nodes for a given term and subject area
 * @param string $term
 * @param string $subj_area
 */
function penncourse_load_sections_by_subj($term, $subj_area) {
    // has been updated to reflect the fact that only sections (not courses) are displayed
    // references to course data may be deleted at a future date
    pcpm(array('term' => $term, 'subj_area' => $subj_area));

    // only run if term has been set
    if ($term) {
        // get course node id's
        $course_nodes = penncourse_load_course_nids($term, $subj_area);
        // pcpm('course nid lookup');
        // pcpm($course_nodes);
        $section_nodes = penncourse_load_section_nids($term, $subj_area);
        pcpm('section nid lookup');
        pcpm($section_nodes);

        // let's do course data first
        $results = penncourse_retrieve_term_courses($subj_area);
        if (!$results) {
            // make sure we have returned data from the service
            watchdog('penncourse', 'warning: no course results returned for term ' . $term . ' and subject area ' . $subj_area, array(), WATCHDOG_NOTICE);
        }
        else {
            $courses = array();
            foreach ($results as $course) {
                $courses[trim($term) . '-' . trim($course->course_id)] = $course;
            }
            unset($results);

            // loop through $courses array and update or create pc_course nodes as needed
            foreach ($courses as $key => $course_record) {
                $course_info = array();
                $course_info['title'] = $course_record->course_title;
                // $course_info['descr'] = penncourse_transform_description($course_record->course_desc);
                $course_info['descr'] = $course_record->course_description;
                // $course_info['syllabus_url'] = $course_record->syllabus_url;
                $course_info['course_id'] = $course_record->course_id;
                $course_info['term'] = $term;
                // $course_info['term_session'] = $course_record->term_session;
                $course_info['subj_area'] = $subj_area;
                // $course_info['dist_req'] = penncourse_translate_dist_req($course_record->distribution_requirement);
                $course_info['dist_req'] = penncourse_translate_dist_req($course_record->distribution_requirement);
                // $course_info['status'] = $course_record->status;
                if ($course_record->course_number > 4999) {
                    $course_info['level'] = 'graduate';
                }
                else {
                    $course_info['level'] = 'undergraduate';
                }

                if (isset($course_nodes[$key])) {
                    penncourse_build_course_node($course_nodes[$key], $course_info);
                }
                else {
                    $course_nodes[$key] = penncourse_build_course_node(NULL, $course_info);
                }
            }
        }

        // now we get the course section data
        $results = penncourse_retrieve_term_sections($term, $subj_area);
        if (!$results) {
            // make sure we have returned data from the service
            watchdog('penncourse', 'warning: no section results returned for term ' . $term . ' and subject area ' . $subj_area, array(), WATCHDOG_NOTICE);
        }
        else {
            $sections = array();
            $course_id = '';
            foreach ($results as $section) {
                /* if ($course_record->course_id != $course_id) {
                    $courses[trim($course_record->term) . '-' . trim($course_record->course_id)] = $course_record;
                    $course_id = $course_record->course_id;
                } */
                $sections[trim($section->term) . '-' . trim($section->section_id)] = $section;
            }
            unset($results);

            pcpm('section data');
            pcpm($sections);

            // loop through $sections array and update or create pc_section nodes as needed
            $current_term = penncourse_current_term();
            foreach ($sections as $key => $section_record) {
                $section_info = array();
                $section_info['title'] = $section_record->section_title;
                // $section_info['descr'] = penncourse_transform_description($section_record->course_desc); this field is maintained locally on the Drupal site
                $section_info['instructors'] = penncourse_transform_instructors($section_record->instructors);
                $section_info['meeting'] = penncourse_transform_meetings($section_record->meetings);
                if ($section_record->term <= $current_term) {
                    $section_info['location'] = penncourse_transform_location($section_record->meetings);
                }
                else {
                    $section_info['location'] = '';
                }
                $section_info['section_id'] = $section_record->section_id;
                $section_info['course'] = $course_nodes[trim($section_record->term) . '-' . trim($section_record->course_department) . trim($section_record->course_number)];
                $section_info['subj_area'] = $section_record->course_department;
                $section_info['term'] = $section_record->term;
                $section_info['term_session'] = $section_record->term_session;
                $section_info['activity'] = $section_record->activity;
                $section_info['course_no'] = $section_record->course_number;
                $section_info['section_no'] = $section_record->section_number;
                $section_info['xlist'] = penncourse_build_xlists($section_record->crosslistings);
                $section_info['syllabus_url'] = $section_record->syllabus_url;
                $section_info['status'] = $section_record->course_status;
                $section_info['course_id'] = $section_record->course_department . $section_record->course_number;
                $section_info['course_nid'] = penncourse_find_course_nid(trim($section_record->course_department) . trim($section_record->course_number), $section_record->term);
                $section_info['notes'] = penncourse_build_notes($section_record->important_notes);
                if ($section_record->course_number > 4999) {
                    $section_info['level'] = 'graduate';
                }
                else {
                    $section_info['level'] = 'undergraduate';
                }

                if ($section_info['course_nid']) {
                    if (isset($section_nodes[$key])) {
                        penncourse_build_section_node($section_nodes[$key], $section_info);
                    }
                    else {
                        $section_nodes[$key] = penncourse_build_section_node(NULL, $section_info);
                    }
                }
                else {
                    watchdog('penncourse cron', 'no course node found for ' . trim($section_record->course_department) . trim($section_record->course_number) . ' ' . $section_record->term, array(), WATCHDOG_NOTICE);
                }
            }

            // switch user to delete nodes
            global $user;
            // we want the author of this content to be a dedicated user account, penncourse_user
            $current_uid = NULL;
            $penncourse_user = user_load_by_name('penncourse_user');
            if ($penncourse_user) {
                $current_uid = $user->uid;
                $user = $penncourse_user;
            }
            // if a course record no longer exists for the corresponding pc_course node, delete the node
            foreach ($course_nodes as $key => $nid) {
                if (!isset($courses[$key])) {
                    watchdog('penncourse cron', 'deleting pc_course node ' . $nid, array(), WATCHDOG_NOTICE);
                    node_delete($nid);
                }
            }

            // if a section record no longer exists for the corresponding pc_section node, delete the node
            foreach ($section_nodes as $key => $nid) {
                if (!isset($sections[$key])) {
                    watchdog('penncourse cron', 'deleting pc_section node ' . $nid, array(), WATCHDOG_NOTICE);
                    node_delete($nid);
                }
            }

            // switch user to delete nodes
            if ($current_uid !== NULL) {
                // reload our original user
                $user = user_load($current_uid);
            }
        }
    }
} // function penncourse_load_sections_by_subj

/**
 * function penncourse_is_summer_term
 *
 * Copied over from LPSCPS module, not currently used
 * Returns boolean
 */
function penncourse_is_summer_term() {
    return (substr(variable_get('penncourse_cycle_term', ''), 4, 1) == 'B');
}

/**
 * function penncourse_xml_to_array
 *
 * Copied over from LPSCPS module
 * given a simple 3-element-deep XML structure (<root><record><param1 /><param2 /></record></root>), returns a keyed array
 * @param xml $xmlstring
 * @return array
 */
function penncourse_xml_to_array($xmlstring) {
    $result = array();
    try {
        $xml = new SimpleXMLElement($xmlstring);
        foreach ($xml->xpath('/*/*') as $record) {
            $record_array = array();
            foreach ($record->children() as $element) {
                $record_array[$element->getName()] = (string)$element;
            }
            $result[] = $record_array;
        }
    }
    catch (Exception $e) {
        penncourse_log_exception($e, $xmlstring);
    }

    return $result;
} // function penncourse_xml_to_array

/**
 * function penncourse_simple_xml_to_array
 *
 * Copied over from LPSCPS module, not currently used
 * given a VERY simple 2-element-deep XML structure (<root><record1 /><record2 />... </root>), returns an array
 * @param xml $xmlstring
 * @return array
 */
function penncourse_simple_xml_to_array($xmlstring) {
    $result = array();
    try {
        $xml = new SimpleXMLElement($xmlstring);
        foreach ($xml->xpath('/*/*') as $record) {
            $result[] = (string)$record;
        }
    }
    catch (Exception $e) {
        penncourse_log_exception($e, $xmlstring);
    }

    return $result;
} // function penncourse_simple_xml_to_array

function penncourse_term_is_valid($term) {
    if (preg_match('/^[0-9]{4}[A-C]$/', $term)) {
        return TRUE;
    }
    else {
        return FALSE;
    }
}

/**
 * function penncourse_translate_dist_req
 *
 * return a formatted distribution requirement string based on a term code
 * @param string $term
 */
function penncourse_translate_dist_req($req_code) {
    $req_array = array(
        'A' => 'Arts & Letters Sector (all classes)',
        'B' => 'Hum/Soc Sci or Nat Sci/Math (new curriculum only)',
        'C' => 'General Requirement in Science Studies',
        'F' => 'General Requirement in Formal Reasoning & Analysis',
        'H' => 'History & Tradition Sector (all classes)',
        'L' => 'Living World Sector (all classes)',
        'O' => 'Hum & Soc Sci Sector (new curriculum only)',
        'N' => 'Nat Sci & Math Sector (new curriculum only)',
        'P' => 'Physical World Sector (all classes)',
        'R' => 'Writing Requirement Course',
        'S' => 'Society sector (all classes)',
        'T' => 'General Requirement in Society',
        'U' => 'General Requirement in History & Tradition',
        'V' => 'General Requirement in Arts & Letters',
        'W' => 'General Requirement in Formal Reasoning & Analysis',
        'X' => 'General Requirement in Living World',
        'Y' => 'General Requirement in Physical World',
        'Z' => 'General Requirement in Science Studies',
        '1' => 'Distributional course in Society (class of 09 and prior)',
        '2' => 'Distributional course in History & Tradition (class of 09 and prior)',
        '3' => 'Distributional course in Arts & Letters (class of 09 and prior)',
    );

    if (isset($req_array[$req_code])) {
        return $req_array[$req_code];
    }
    else {
        return NULL;
    }
} // function penncourse_translate_dist_req

/**
 * function penncourse_translate_day
 *
 * Copied over from LPSCPS module, not currently used
 * Returns a day name for a given day code
 * @param string $d day code
 */
function penncourse_translate_day($d) {
    $days = array(
        'M' => 'Monday',
        'T' => 'Tuesday',
        'W' => 'Wednesday',
        'R' => 'Thursday',
        'F' => 'Friday',
        'S' => 'Saturday',
        'U' => 'Sunday',
    );

    if (isset($days[$d])) {
        return $days[$d];
    }
    else {
        return NULL;
    }
} // function penncourse_translate_day

/**
 * function penncourse_transform_description
 * input xml string
 * output text
 */
function penncourse_transform_description($xmlstring) {
    $output = '';
    try{
        $xml = new SimpleXMLElement($xmlstring);
        foreach ($xml->xpath('/div[p]') as $description) {
            // $output .= '<ul class="penncourse-course-location">';
            foreach ($description->p as $para) {
                $output .= $para;
                $output .= chr(10) . chr(13) . chr(10) . chr(13);
            }
        }
    }
    catch (Exception $e) {
        penncourse_log_exception($e, $xmlstring);
    }

    // echo $output.chr(10).chr(13);
    return $output;
} // function penncourse_transform_description

/**
 * function penncourse_transform_instructors
 * input array
 * output xhtml formatted text
 */
function penncourse_transform_instructors(array $instructors) {
    $xhtml = '';
    foreach ($instructors as $instructor) {
        if ($instructor->name) {
            // commenting this out because we don't have access to the pennkey data from the web service
            // $xhtml .= '<span class="penncourse-course-instructor" data-pennkey="' . $instructor->pennkey . '">' . $instructor->lastname . ', ' . $instructor->firstname . '</span><br />';
            $xhtml .= '<span class="penncourse-course-instructor" data-pennkey="">' . $instructor->name . '</span><br />';
        }
    }
    // trim the last <br /> from the string
    $xhtml = substr($xhtml, 0, -6);

    // echo $xhtml.chr(10).chr(13);
    return $xhtml;
} // function penncourse_transform_instructors

/* deprecated function penncourse_transform_instructors($xmlstring) {
    $xhtml = '';
    try {
        $xml = new SimpleXMLElement($xmlstring);
        foreach ($xml->xpath("/instructors[instructor]") as $instructors) {
            // $xhtml .= '<ul class="penncourse-course-instructors">';
            foreach ($instructors->instructor as $instructor) {
                if ($instructor->lastname) {
                    $xhtml .= '<span class="penncourse-course-instructor" data-pennkey="' . $instructor->pennkey . '">' . $instructor->lastname . ', ' . $instructor->firstname . '</span><br />';
                }
            }
            // $xhtml .= '</ul>';
        }
        // trim the last <br /> from the string
        $xhtml = substr($xhtml, 0, -6);
    }
    catch (Exception $e) {
        penncourse_log_exception($e, $xmlstring);
    }

    // echo $xhtml.chr(10).chr(13);
    return $xhtml;
} // function penncourse_transform_instructors() */

/**
 * function penncourse_transform_meetings
 * input array
 * output xhtml formatted text
 */
function penncourse_transform_meetings(array $meetings) {
    $xhtml = '';
    foreach ($meetings as $meeting) {
        if ($meeting->meeting_days && $meeting->start_time && $meeting->end_time) {
            $xhtml .= '<span class="penncourse-course-meeting">' . $meeting->meeting_days . ' ' . $meeting->start_time . '-' . $meeting->end_time . '</span><br />';
        }
    }
    // trim the last <br /> from the string
    $xhtml = substr($xhtml, 0, -6);

    return $xhtml;
} // function penncourse_transform_meetings

/**
 * function penncourse_transform_location
 * input array
 * output xhtml formatted text
 */
function penncourse_transform_location(array $meetings) {
    $xhtml = '';
    foreach ($meetings as $meeting) {
        // $xhtml .= '<li><span style="font-weight:bold">Room: </span>'.$meeting->room.' &nbsp; '.$meeting->building.'</li>';
        if ($meeting->building_code && $meeting->room_number) {
            $xhtml .= '<span class="penncourse-course-location">' . $meeting->building_code . ' ' . $meeting->room_number . '</span><br />';
        }
    }
    // trim the last <br /> from the string
    $xhtml = substr($xhtml, 0, -6);

    return $xhtml;
} // function penncourse_transform_location

/**
 * function penncourse_db_info
 *
 * Given a content type and array of field names in that content type,
 * returns a keyed array of the database table and column names
 *
 * Only valid for simple field types (textfield, integer)
 *
 * $content_type     string The machine name of the content type
 * $field_name_array array  An array of field names
 */
function penncourse_db_info($content_type, $field_name_array) {
    $result = array();

    foreach ($field_name_array as $field_name) {
        $field_info = field_info_field($field_name);
        $db_info = $field_info['storage']['details']['sql']['FIELD_LOAD_CURRENT'];
        foreach ($db_info as $key => $value) {
            $result[$field_name]['table'] = $key;
            $result[$field_name]['column'] = $value['value'];
        }
    }
    return $result;
} // function penncourse_db_info

/**
 * function penncourse_start_term()
 *
 * returns the term code for the first semester of the current year
 * this helps penncourse_cleanup() to only process current records
 * (ie, we don't want to waste time cleaning up old data that is not of current use)
 */
function penncourse_start_term() {
    $term = date('Y', REQUEST_TIME);
    $term .= 'A';
    return $term;
} // function penncourse_start_term()

/**
 * function penncourse_load_final_term()
 * returns the term code for the most recent term in the database
 */
function penncourse_load_final_term() {
  $terms = penncourse_get_all_terms();
  reset($terms);
  $term = key($terms);
  return $term;
} // function penncourse_load_final_term()

/**
 * function penncourse_translate_term($term_code)
 * returns a formatted string of the term name for a given $term_code
 * ('2008C' returns 'Fall 2008')
 */
function penncourse_translate_term($term_code) {
    $term_name = array('A' => 'Spring', 'B' => 'Summer', 'C' => 'Fall');
    if (is_numeric(substr($term_code, 0, 4)) && ((strtoupper(substr($term_code, 4, 1)) == 'A') || (strtoupper(substr($term_code, 4, 1)) == 'B') || (strtoupper(substr($term_code, 4, 1)) == 'C'))) {
        return $term_name[strtoupper(substr($term_code, 4, 1))] . ' ' . substr($term_code, 0, 4);
    }
    else {
        // invalid code
        return 'Invalid term code';
    }
} // function penncourse_translate_term()

/**
 * function penncourse_translate_subject($subj_code)
 *
 * returns a formatted string of Subject Area name
 * ('ANTH' returns 'Anthropology')
 */
function penncourse_translate_subject($subj_code) {
    $subj_descr = '';
    // get the section seach parameters
    $section_params = variable_get('penncourse_section_params', '');

    if ($section_params->departments_map) {
        $subject_areas = $section_params->departments_map;

        if (property_exists($subject_areas, $subj_code)) {
          $subj_descr = $subject_areas->$subj_code;
        }
    }

    return $subj_descr;
} // function penncourse_translate_subject()

/**
 * function penncourse_current_term()
 * returns the current term
 * A = January 1 through May 20
 * B = May 21 through August 15
 * C = August 16 through December 31
 */
function penncourse_current_term() {
    // get database information about course_course_id field
    $term = date('Y', REQUEST_TIME);
    if ((date('n', REQUEST_TIME) <= 5) && ((date('j', REQUEST_TIME) <= 20) || (date('n', REQUEST_TIME) <= 4))) {
        $term .= 'A';
    }
    elseif ((date('n', REQUEST_TIME) <= 8) && ((date('j', REQUEST_TIME) <= 15) || (date('n', REQUEST_TIME) <= 7))) {
        $term .= 'B';
    }
    else {
        $term .= 'C';
    }
    return $term;
} // function penncourse_current_term()

/**
 * function penncourse_current_term_no_summer()
 * returns the current term (excluding summer terms)
 * A = January 1 through May 20
 * C = May 21 through December 31
 */
function penncourse_current_term_no_summer() {
    // get database information about course_course_id field
    $term = date('Y', REQUEST_TIME);
    if ((date('n', REQUEST_TIME) <= 5) && ((date('j', REQUEST_TIME) <= 20) || (date('n', REQUEST_TIME) <= 4))) {
        $term .= 'A';
    }
    else {
        $term .= 'C';
    }
    return $term;
} // function penncourse_current_term()

/**
 * penncourse_load_course_node($course_id)
 *
 * load course node for a course id and term
 * returns node object
 */
function penncourse_load_course_node($course_id, $term) {
    $query = new EntityFieldQuery();
    $entity = $query->entityCondition('entity_type', 'node')
        ->propertyCondition('type', 'pc_course')
        ->fieldCondition('field_pc_course_id', $course_id)
        ->fieldCondition('field_pc_term', $term)
        ->range(0, 1)
        ->execute();

    if (!empty($entity['node'])) {
        $node = node_load(current(array_keys($entity['node'])));

        return $node;
    }
    else {
        return NULL;
    }
} // function penncourse_load_course_node($subj_code)

/**
 * @param $course_id
 * @param $term
 * @return mixed|null
 * Return the node ID for a given course given the SRS Course ID and Term
 */
function penncourse_find_course_nid($course_id, $term) {
    $query = new EntityFieldQuery();
    $entity = $query->entityCondition('entity_type', 'node')
        ->propertyCondition('type', 'pc_course')
        ->fieldCondition('field_pc_course_id', 'value', $course_id, '=')
        ->fieldCondition('field_pc_term', 'value', $term, '=')
        ->range(0, 1)
        ->execute();

    if (!empty($entity['node'])) {
        $nid = current(array_keys($entity['node']));
        unset($entity);
        unset($query);
        return $nid;
    }
    else {
        return NULL;
    }
}

/**
 * Return an array of all course terms currently stored in the database
 */
function penncourse_get_all_terms() {
    // get database info about course fields
    $db_info = penncourse_db_info('pc_course', array('field_pc_term'));

    $sql = sprintf("SELECT DISTINCT     t.%s AS term
                    FROM 			    {%s} t
 					ORDER BY 	        term DESC",
        $db_info['field_pc_term']['column'],
        $db_info['field_pc_term']['table']);

    $results = db_query($sql, array());

    $terms = array();
    foreach ($results as $record) {
        $terms[$record->term] = penncourse_translate_term($record->term);
    }

    return $terms;
}

function penncourse_get_all_subjects() {
    $subject_code_array = explode(' ', variable_get('penncourse_subject_areas', ''));

    $subjects = array();
    foreach ($subject_code_array as $subject_code) {
        $subjects[$subject_code] = penncourse_translate_subject($subject_code);
    }

    return $subjects;
}

/**
 * parse $sec_reg_ctrl XML and translate control codes into text
 *
 * @param string $sec_reg_ctrl
 */
function penncourse_transform_sec_reg_ctrl($sec_reg_ctrl) {
    $result_array = array();

    if ($sec_reg_ctrl) {
        $sec_reg_ctrl_array = penncourse_xml_to_array($sec_reg_ctrl);

        foreach ($sec_reg_ctrl_array as $record) {
            if ((substr($record['reg-control-desc'], 0, 5) != 'QUOTA') && ($record['reg-control-desc'] != 'CONTINUATION OF ABOVE QUOTA')) {
                $result_array[] = $record['reg-control-desc'];
            }
        }
    }

    $result = implode('; ', $result_array);
    return $result;
}

/**
 * parse $sec_type XML and translate control codes into text
 *
 * @param string $sec_type
 */
function penncourse_transform_sec_type($sec_type) {
    // watchdog('penncourse cron', 'function penncourse_transform_sec_type', array(), WATCHDOG_NOTICE);
    $result_array = array();

    if ($sec_type) {
        // watchdog('penncourse cron', $sec_type, array(), WATCHDOG_NOTICE);
        $sec_type_array = penncourse_xml_to_array($sec_type);

        foreach ($sec_type_array as $record) {
            // watchdog('penncourse cron', $record['section-type-desc'], array(), WATCHDOG_NOTICE);
            if (isset($record['section-type-desc'])) {
                $result_array[] = $record['section-type-desc'];
            }
        }
    }

    $result = implode('; ', $result_array);
    return $result;
}

function penncourse_build_xlists(array $xlists) {
    $result = '';
    foreach ($xlists as $xlist) {
        $result .= '<span class="penncourse-course-xlist">' . $xlist->section_id . '</span>, ';
    }
    // trim the last <br /> from the string
    $result = substr($result, 0, -2);

    return $result;
}

function penncourse_build_notes(array $notes) {
    $xhtml = '';
    foreach ($notes as $note) {
        $xhtml .= '<span class="penncourse-course-notes">' . $note . '</span><br />';
    }
    // trim the last <br /> from the string
    $xhtml = substr($xhtml, 0, -6);

    return $xhtml;
}

function penncourse_log_exception(Exception $e, $message) {
    watchdog('penncourse cron', 'exception: ' . $e->getMessage() . ' - ' . $message, array(), WATCHDOG_NOTICE);
}

function _penncourse_call_course_service($subj_area, $page = 1) {
    if ($subj_area) {
        $curl = curl_init();
        curl_setopt_array($curl, array(
            CURLOPT_HTTPHEADER => array(
                'Authorization-Bearer: ' . variable_get('penncourse_authorization_bearer', ''),
                'Authorization-Token: ' . variable_get('penncourse_authorization_token', '')
            ),
            CURLOPT_RETURNTRANSFER => 1,
            CURLOPT_FOLLOWLOCATION => 1,
            CURLOPT_URL => 'https://apps.sas.upenn.edu/service/sas-course-api/course_info/' . $subj_area . '/' . '?page_number=' . $page . '&number_of_results_per_page=100'
        ));

        $curl_return = curl_exec($curl);

        $result = json_decode($curl_return);

        $service_error = $result->service_meta->error_text;
        if (!$service_error && isset($result->result_data)) {
            return $result;
            // return $result->result_data;
        }
        else {
            return (object) ['error_text' => $service_error];
        }
    }
    else {
        // term and/or subject area not supplied
        return (object) ['error_text' => 'A valid term code or subject area must be supplied'];
    }
}

function penncourse_retrieve_term_courses($subj_area) {
    $course_data = array();

    // get first data set
    try {
        $result = _penncourse_call_course_service($subj_area, 1);
        if (isset($result->error_text)) {
            throw new Exception("Course web service error: " . $result->error_text, 1);
        }
        else {
            // add course data to the array to be returned
            $course_data = array_merge($course_data, $result->result_data);

            if ($result->service_meta->number_of_pages > 1) {
                // there is more than 1 page of data, we need to get the rest
                $current_page = 1;
                $next_page = 2;

                while ($next_page > $current_page) {
                    $result = _penncourse_call_course_service($subj_area, $next_page);
                    if (isset($result->error_text)) {
                        $next_page = $current_page; // we don't want to continue looping on an error
                        throw new Exception("Course web service error: " . $result->error_text, 1);
                    }
                    else {
                        // add course data to the array to be returned
                        $course_data = array_merge($course_data, $result->result_data);
                        $next_page = $result->service_meta->next_page_number;
                        $current_page = $result->service_meta->current_page_number;
                    }
                }
            }
        }
    }
    catch (Exception $e) {
        penncourse_log_exception($e, 'course service for subject area: ' . $subj_area);
    }
    return $course_data;
}


function _penncourse_call_section_service($term, $subj_area, $page = 1) {
    if ($term && $subj_area) {
        $curl = curl_init();
        curl_setopt_array($curl, array(
            CURLOPT_HTTPHEADER => array(
                'Authorization-Bearer: ' . variable_get('penncourse_authorization_bearer', ''),
                'Authorization-Token: ' . variable_get('penncourse_authorization_token', '')
            ),
            CURLOPT_RETURNTRANSFER => 1,
            CURLOPT_FOLLOWLOCATION => 1,
            CURLOPT_URL => 'https://apps.sas.upenn.edu/service/sas-course-api/course_section_search?course_id=' . $subj_area . '&term=' . $term . '&page_number=' . $page . '&number_of_results_per_page=100'
        ));

        $curl_return = curl_exec($curl);

        $result = json_decode($curl_return);

        $service_error = $result->service_meta->error_text;
        if (!$service_error && isset($result->result_data)) {
            return $result;
            // return $result->result_data;
        }
        else {
            return (object) ['error_text' => $service_error];
        }
    }
    else {
        // term and/or subject area not supplied
        return (object) ['error_text' => 'A valid term code or subject area must be supplied'];
    }
}

/**
 * function penncourse_retrieve_term_sections
 *
 * retrieve all section data for a given term and subject area
 */
function penncourse_retrieve_term_sections($term, $subj_area) {
    $course_data = array();

    // get first data set
    try {
        $result = _penncourse_call_section_service($term, $subj_area, 1);
        if (isset($result->error_text)) {
            throw new Exception("Course section web service error: " . $result->error_text, 1);
        }
        else {
            // add course data to the array to be returned
            $course_data = array_merge($course_data, $result->result_data);

            if ($result->service_meta->number_of_pages > 1) {
                // there is more than 1 page of data, we need to get the rest
                $current_page = 1;
                $next_page = 2;

                while ($next_page > $current_page) {
                    $result = _penncourse_call_section_service($term, $subj_area, $next_page);
                    if (isset($result->error_text)) {
                        $next_page = $current_page; // we don't want to continue looping on an error
                        throw new Exception("Course section web service error: " . $result->error_text, 1);
                    }
                    else {
                        // add course data to the array to be returned
                        $course_data = array_merge($course_data, $result->result_data);
                        $next_page = $result->service_meta->next_page_number;
                        $current_page = $result->service_meta->current_page_number;
                    }
                }
            }
        }
    }
    catch (Exception $e) {
        penncourse_log_exception($e, 'term: ' . $term . '; subject area: ' . $subj_area);
    }
    return $course_data;
} // function penncourse_retrieve_term_sections

function penncourse_retrieve_subject_areas() {
    $curl = curl_init();
    curl_setopt_array($curl, array(
        CURLOPT_HTTPHEADER => array(
            'Authorization-Bearer: ' . variable_get('penncourse_authorization_bearer', ''),
            'Authorization-Token: ' . variable_get('penncourse_authorization_token', '')
        ),
        CURLOPT_RETURNTRANSFER => 1,
        CURLOPT_FOLLOWLOCATION => 1,
        CURLOPT_URL => 'https://apps.sas.upenn.edu/service/sas-course-api/course_section_search_parameters/'
    ));

    $curl_return = curl_exec($curl);
    $result = json_decode($curl_return);

    $service_error = $result->service_meta->error_text;
    if (!$service_error && isset($result->result_data[0])) {
        return $result->result_data[0];
    }
    else {
        return (object) ['error_text' => $service_error];
    }
}


/**
 * function penncourse_retrieve_section_params
 *
 * for development only: remove all penncourse content
 */
function penncourse_retrieve_section_params() {
    $curl = curl_init();
    curl_setopt_array($curl, array(
        CURLOPT_HTTPHEADER => array(
            'Authorization-Bearer: ' . variable_get('penncourse_authorization_bearer', ''),
            'Authorization-Token: ' . variable_get('penncourse_authorization_token', '')
        ),
        CURLOPT_RETURNTRANSFER => 1,
        CURLOPT_FOLLOWLOCATION => 1,
        CURLOPT_URL => 'https://apps.sas.upenn.edu/service/sas-course-api/course_section_search_parameters/'
    ));

    $curl_return = curl_exec($curl);
    $result = json_decode($curl_return);
    watchdog('penncourse test', $curl_return, array(), WATCHDOG_NOTICE);

    $service_error = $result->service_meta->error_text;
    if (!$service_error && isset($result->result_data[0])) {
        return $result->result_data[0];
    }
    else {
        return (object) ['error_text' => $service_error];
    }
}

/**
 * function _penncourse_whack
 *
 * for development only: remove all penncourse content
 */
function _penncourse_whack() {
    // delete all nodes for the penncourse content types
    foreach (array('pc_section', 'pc_course') AS $content_type) {
        // gather all $content_type nodes created
        $sql = 'SELECT nid FROM {node} n WHERE n.type = :type';
        $result = db_query($sql, array(':type' => $content_type));
        $nids = array();
        foreach ($result as $row) {
            $nids[] = $row->nid;
        }
        // delete all the $content_type nodes at once
        node_delete_multiple($nids);
    }

    return 'You just whacked your course data!';
}
