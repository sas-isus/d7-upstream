<?php
/**
 * @file
 * penncourses.pages.inc
 *
 * Page callbacks for the PennCourse module
 */

/**
 * function penncourse_course_list_term($term)
 *
 * menu callback - display the list of courses for a given term
 *
 * if $subj_code is given, include Subject Area description
 */
function penncourse_course_list_term($term, $subj_code = 'all', $level = 'all') {
    // $node = node_load(1289);
    // dpm($node);
    module_load_include('inc', 'penncourse', 'penncourse.include');
    drupal_add_js(drupal_get_path('module', 'penncourse') . '/js/penncourse_course_table.js');
    $breadcrumb = array(l(t('Home'), NULL));

    // if term is null, set to current term
    if (!$term) {
        $term = penncourse_load_final_term();
    }

    // build title string and extra breadcrumb, if needed
    $title = '';
    if ((!$level || ($level == 'all')) && (!$subj_code || ($subj_code == 'all'))) {
        $title = 'Courses for ';
    }
    else {
        $breadcrumb[] = l(t('All courses for ' . penncourse_translate_term($term)), 'pc/term/' . $term);
        if ($subj_code && ($subj_code != 'all')) {
            $title = penncourse_translate_subject($subj_code);
        }
        if (($level == 'graduate') || ($level == 'undergraduate')) {
            $title = ucfirst($level) . ' ' . $title;
        }
        $title = $title . ' courses for ';
    }
    $title = $title . penncourse_translate_term($term);
    drupal_set_title(t($title));
    drupal_set_breadcrumb($breadcrumb);

    $output = '';
    $output .= views_embed_view('pc_section_table', 'default', $term, $subj_code, $level);

    return $output;
} // function penncourse_course_list_term()

/**
 * function penncourse_course_detail($term,$course_id)
 *
 * menu callback - display the detailed course listing (with sections) for a given course/term
 */
function penncourse_course_detail($term, $course_id) {
    module_load_include('inc', 'penncourse', 'penncourse.include');
    $node = penncourse_load_course_node($course_id, $term);

    drupal_set_title($node->title);
    drupal_set_breadcrumb(
        array(
            l(t('Home'), NULL),
            l(t('All courses for ' . penncourse_translate_term($term)), 'pc/term/' . $term),
            l(t(penncourse_translate_subject($node->field_pc_subj_area[0]['value']) . ' courses for ' . penncourse_translate_term($term)), 'pc/term/' . $term . '/subject/' . $node->field_pc_subj_area[0]['value'])
        )
    );

    $output = '';
    $output .= views_embed_view('pc_course_detail', 'default', $term, $course_id);

    return $output;
} // function penncourse_course_detail()

/**
 * function penncourse_load_year($year)
 *
 * load the course data for a given year
 */
function penncourse_load_year($year) {
    module_load_include('inc', 'penncourse', 'penncourse.include');
    // check for valid year - no data loaded for years before 2008
    if (!preg_match('/^[0-9]{4}$/', $year) || (($year < 2008) || ($year > date('Y', REQUEST_TIME)))) {
        $output = 'Invalid year specified.';
        return $output;
        // drupal_not_found();
    }
    else {
        // get subject areas
        $subject_array = explode(' ', trim(variable_get('penncourse_subject_areas', '')));

        // process each subject area as set on the penncourse system settings form
        foreach ($subject_array as $subject) {
            penncourse_process_subj_area($subject, $year);
        }
        $output = 'Courses loaded for ' . $year . '!';
        return $output;
    }

} // function penncourse_load_year($year)

function penncourse_data_retrieve_test() {
    module_load_include('inc', 'penncourse', 'penncourse.include');
    $output = '';
    $section_params = penncourse_retrieve_section_params();
    pcpm($section_params);

    // retrieve course inventory data for a single course
    $test_course_retrieve = _penncourse_call_course_service_test();
    pcpm($test_course_retrieve);

    $course_data = penncourse_retrieve_term_courses('ANTH');
    pcpm($course_data);

    $section_data = penncourse_retrieve_term_sections('2018C', 'ANTH');
    pcpm($section_data);

    // penncourse_load_sections_by_subj('2018C', 'RUSS');
    // penncourse_process_subj_area('RUSS');

    pcpm(penncourse_get_all_terms());

    return $output;
}

function _penncourse_call_course_service_test() {
    $curl = curl_init();
    curl_setopt_array($curl, array(
        CURLOPT_HTTPHEADER => array(
            'Authorization-Bearer: ' . variable_get('penncourse_authorization_bearer', ''),
            'Authorization-Token: ' . variable_get('penncourse_authorization_token', '')
        ),
        CURLOPT_RETURNTRANSFER => 1,
        CURLOPT_URL => 'https://esb.isc-seo.upenn.edu/8091/open_data/course_info/ANTH/219/' . '?page_number=1&number_of_results_per_page=100'
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
