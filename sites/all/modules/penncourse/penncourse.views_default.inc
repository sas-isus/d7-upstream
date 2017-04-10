<?php
/**
 * @file
 * penncourse.views_default.inc
 *
 * default views for the Penncourse module
 */

function penncourse_views_default_views() {
    $views = array();

    $view = new view();
    $view->name = 'pc_section_table';
    $view->description = '';
    $view->tag = 'default';
    $view->base_table = 'node';
    $view->human_name = 'pc_section_table';
    $view->core = 7;
    $view->api_version = '3.0';
    $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

    /* Display: Master */
    $handler = $view->new_display('default', 'Master', 'default');
    $handler->display->display_options['use_more_always'] = FALSE;
    $handler->display->display_options['access']['type'] = 'perm';
    $handler->display->display_options['cache']['type'] = 'none';
    $handler->display->display_options['query']['type'] = 'views_query';
    $handler->display->display_options['exposed_form']['type'] = 'basic';
    $handler->display->display_options['pager']['type'] = 'full';
    $handler->display->display_options['pager']['options']['items_per_page'] = '0';
    $handler->display->display_options['pager']['options']['offset'] = '0';
    $handler->display->display_options['pager']['options']['id'] = '0';
    $handler->display->display_options['pager']['options']['quantity'] = '9';
    $handler->display->display_options['style_plugin'] = 'table';
    $handler->display->display_options['style_options']['columns'] = array(
        'title' => 'title',
    );
    $handler->display->display_options['style_options']['default'] = '-1';
    $handler->display->display_options['style_options']['info'] = array(
        'title' => array(
            'sortable' => 0,
            'default_sort_order' => 'asc',
            'align' => '',
            'separator' => '',
            'empty_column' => 0,
        ),
    );
    /* Relationship: Course */
    $handler->display->display_options['relationships']['field_pc_course_target_id']['id'] = 'field_pc_course_target_id';
    $handler->display->display_options['relationships']['field_pc_course_target_id']['table'] = 'field_data_field_pc_course';
    $handler->display->display_options['relationships']['field_pc_course_target_id']['field'] = 'field_pc_course_target_id';
    $handler->display->display_options['relationships']['field_pc_course_target_id']['ui_name'] = 'Course';
    /* Field: Content: Subject Area */
    $handler->display->display_options['fields']['field_pc_subj_area']['id'] = 'field_pc_subj_area';
    $handler->display->display_options['fields']['field_pc_subj_area']['table'] = 'field_data_field_pc_subj_area';
    $handler->display->display_options['fields']['field_pc_subj_area']['field'] = 'field_pc_subj_area';
    $handler->display->display_options['fields']['field_pc_subj_area']['label'] = '';
    $handler->display->display_options['fields']['field_pc_subj_area']['exclude'] = TRUE;
    $handler->display->display_options['fields']['field_pc_subj_area']['element_label_colon'] = FALSE;
    /* Field: Content: Course Number Only */
    $handler->display->display_options['fields']['field_pc_course_no']['id'] = 'field_pc_course_no';
    $handler->display->display_options['fields']['field_pc_course_no']['table'] = 'field_data_field_pc_course_no';
    $handler->display->display_options['fields']['field_pc_course_no']['field'] = 'field_pc_course_no';
    $handler->display->display_options['fields']['field_pc_course_no']['label'] = '';
    $handler->display->display_options['fields']['field_pc_course_no']['exclude'] = TRUE;
    $handler->display->display_options['fields']['field_pc_course_no']['element_label_colon'] = FALSE;
    /* Field: Content: Section Number Only */
    $handler->display->display_options['fields']['field_pc_section_no']['id'] = 'field_pc_section_no';
    $handler->display->display_options['fields']['field_pc_section_no']['table'] = 'field_data_field_pc_section_no';
    $handler->display->display_options['fields']['field_pc_section_no']['field'] = 'field_pc_section_no';
    $handler->display->display_options['fields']['field_pc_section_no']['label'] = '';
    $handler->display->display_options['fields']['field_pc_section_no']['exclude'] = TRUE;
    $handler->display->display_options['fields']['field_pc_section_no']['element_label_colon'] = FALSE;
    /* Field: Content: Section ID */
    $handler->display->display_options['fields']['field_pc_section_id']['id'] = 'field_pc_section_id';
    $handler->display->display_options['fields']['field_pc_section_id']['table'] = 'field_data_field_pc_section_id';
    $handler->display->display_options['fields']['field_pc_section_id']['field'] = 'field_pc_section_id';
    $handler->display->display_options['fields']['field_pc_section_id']['label'] = '';
    $handler->display->display_options['fields']['field_pc_section_id']['exclude'] = TRUE;
    $handler->display->display_options['fields']['field_pc_section_id']['element_label_colon'] = FALSE;
    /* Field: Content: Title */
    $handler->display->display_options['fields']['title']['id'] = 'title';
    $handler->display->display_options['fields']['title']['table'] = 'node';
    $handler->display->display_options['fields']['title']['field'] = 'title';
    $handler->display->display_options['fields']['title']['label'] = '';
    $handler->display->display_options['fields']['title']['exclude'] = TRUE;
    $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
    $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
    $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
    /* Field: Section ID Formatted */
    $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
    $handler->display->display_options['fields']['nothing']['table'] = 'views';
    $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
    $handler->display->display_options['fields']['nothing']['ui_name'] = 'Section ID Formatted';
    $handler->display->display_options['fields']['nothing']['label'] = '';
    $handler->display->display_options['fields']['nothing']['alter']['text'] = '[field_pc_subj_area] [field_pc_course_no]-[field_pc_section_no]';
    $handler->display->display_options['fields']['nothing']['element_class'] = 'section-id-formatted';
    $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
    /* Field: Content: Title (text only) */
    $handler->display->display_options['fields']['field_pc_title']['id'] = 'field_pc_title';
    $handler->display->display_options['fields']['field_pc_title']['table'] = 'field_data_field_pc_title';
    $handler->display->display_options['fields']['field_pc_title']['field'] = 'field_pc_title';
    $handler->display->display_options['fields']['field_pc_title']['label'] = 'Title';
    $handler->display->display_options['fields']['field_pc_title']['element_label_colon'] = FALSE;
    /* Field: Content: Instructors */
    $handler->display->display_options['fields']['field_pc_instructors']['id'] = 'field_pc_instructors';
    $handler->display->display_options['fields']['field_pc_instructors']['table'] = 'field_data_field_pc_instructors';
    $handler->display->display_options['fields']['field_pc_instructors']['field'] = 'field_pc_instructors';
    $handler->display->display_options['fields']['field_pc_instructors']['label'] = 'Instructor';
    $handler->display->display_options['fields']['field_pc_instructors']['element_label_colon'] = FALSE;
    /* Field: Content: Meeting location */
    $handler->display->display_options['fields']['field_pc_location']['id'] = 'field_pc_location';
    $handler->display->display_options['fields']['field_pc_location']['table'] = 'field_data_field_pc_location';
    $handler->display->display_options['fields']['field_pc_location']['field'] = 'field_pc_location';
    $handler->display->display_options['fields']['field_pc_location']['label'] = 'Location';
    $handler->display->display_options['fields']['field_pc_location']['element_label_colon'] = FALSE;
    /* Field: Content: Meeting times */
    $handler->display->display_options['fields']['field_pc_meeting']['id'] = 'field_pc_meeting';
    $handler->display->display_options['fields']['field_pc_meeting']['table'] = 'field_data_field_pc_meeting';
    $handler->display->display_options['fields']['field_pc_meeting']['field'] = 'field_pc_meeting';
    $handler->display->display_options['fields']['field_pc_meeting']['label'] = 'Time';
    $handler->display->display_options['fields']['field_pc_meeting']['element_label_colon'] = FALSE;
    /* Field: Content: All taxonomy terms */
    $handler->display->display_options['fields']['term_node_tid']['id'] = 'term_node_tid';
    $handler->display->display_options['fields']['term_node_tid']['table'] = 'node';
    $handler->display->display_options['fields']['term_node_tid']['field'] = 'term_node_tid';
    $handler->display->display_options['fields']['term_node_tid']['relationship'] = 'field_pc_course_target_id';
    $handler->display->display_options['fields']['term_node_tid']['element_label_colon'] = FALSE;
    $handler->display->display_options['fields']['term_node_tid']['type'] = 'ul';
    $handler->display->display_options['fields']['term_node_tid']['vocabularies'] = array(
        'scald_authors' => 0,
        'scald_tags' => 0,
        'course_theme' => 0,
        'tags' => 0,
    );
    /* Field: Content: Course Description */
    $handler->display->display_options['fields']['field_pc_descr']['id'] = 'field_pc_descr';
    $handler->display->display_options['fields']['field_pc_descr']['table'] = 'field_data_field_pc_descr';
    $handler->display->display_options['fields']['field_pc_descr']['field'] = 'field_pc_descr';
    $handler->display->display_options['fields']['field_pc_descr']['relationship'] = 'field_pc_course_target_id';
    $handler->display->display_options['fields']['field_pc_descr']['label'] = 'Description';
    $handler->display->display_options['fields']['field_pc_descr']['element_label_colon'] = FALSE;
    /* Field: Section Description */
    $handler->display->display_options['fields']['field_pc_descr_1']['id'] = 'field_pc_descr_1';
    $handler->display->display_options['fields']['field_pc_descr_1']['table'] = 'field_data_field_pc_descr';
    $handler->display->display_options['fields']['field_pc_descr_1']['field'] = 'field_pc_descr';
    $handler->display->display_options['fields']['field_pc_descr_1']['ui_name'] = 'Section Description';
    $handler->display->display_options['fields']['field_pc_descr_1']['label'] = 'Section Description';
    $handler->display->display_options['fields']['field_pc_descr_1']['element_label_colon'] = FALSE;
    $handler->display->display_options['fields']['field_pc_descr_1']['element_wrapper_class'] = 'views-field-field-pc-section-descr';
    /* Field: Content: Cross Listings */
    $handler->display->display_options['fields']['field_pc_xlist']['id'] = 'field_pc_xlist';
    $handler->display->display_options['fields']['field_pc_xlist']['table'] = 'field_data_field_pc_xlist';
    $handler->display->display_options['fields']['field_pc_xlist']['field'] = 'field_pc_xlist';
    /* Field: Content: Fulfills */
    $handler->display->display_options['fields']['field_pc_dist_req']['id'] = 'field_pc_dist_req';
    $handler->display->display_options['fields']['field_pc_dist_req']['table'] = 'field_data_field_pc_dist_req';
    $handler->display->display_options['fields']['field_pc_dist_req']['field'] = 'field_pc_dist_req';
    $handler->display->display_options['fields']['field_pc_dist_req']['relationship'] = 'field_pc_course_target_id';
    /* Field: Content: Registration Notes */
    $handler->display->display_options['fields']['field_pc_sec_reg_ctrl']['id'] = 'field_pc_sec_reg_ctrl';
    $handler->display->display_options['fields']['field_pc_sec_reg_ctrl']['table'] = 'field_data_field_pc_sec_reg_ctrl';
    $handler->display->display_options['fields']['field_pc_sec_reg_ctrl']['field'] = 'field_pc_sec_reg_ctrl';
    /* Field: Content: Syllabus */
    $handler->display->display_options['fields']['field_pc_syllabus']['id'] = 'field_pc_syllabus';
    $handler->display->display_options['fields']['field_pc_syllabus']['table'] = 'field_data_field_pc_syllabus';
    $handler->display->display_options['fields']['field_pc_syllabus']['field'] = 'field_pc_syllabus';
    $handler->display->display_options['fields']['field_pc_syllabus']['click_sort_column'] = 'fid';
    /* Field: Content: Syllabus URL */
    $handler->display->display_options['fields']['field_pc_syllabus_url']['id'] = 'field_pc_syllabus_url';
    $handler->display->display_options['fields']['field_pc_syllabus_url']['table'] = 'field_data_field_pc_syllabus_url';
    $handler->display->display_options['fields']['field_pc_syllabus_url']['field'] = 'field_pc_syllabus_url';
    $handler->display->display_options['fields']['field_pc_syllabus_url']['click_sort_column'] = 'url';
    /* Field: Course Syllabus URL */
    $handler->display->display_options['fields']['field_pc_syllabus_url_1']['id'] = 'field_pc_syllabus_url_1';
    $handler->display->display_options['fields']['field_pc_syllabus_url_1']['table'] = 'field_data_field_pc_syllabus_url';
    $handler->display->display_options['fields']['field_pc_syllabus_url_1']['field'] = 'field_pc_syllabus_url';
    $handler->display->display_options['fields']['field_pc_syllabus_url_1']['relationship'] = 'field_pc_course_target_id';
    $handler->display->display_options['fields']['field_pc_syllabus_url_1']['ui_name'] = 'Course Syllabus URL';
    $handler->display->display_options['fields']['field_pc_syllabus_url_1']['label'] = 'Course Syllabus URL';
    $handler->display->display_options['fields']['field_pc_syllabus_url_1']['click_sort_column'] = 'url';
    /* Field: Content: Edit link */
    $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
    $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
    $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
    $handler->display->display_options['fields']['edit_node']['label'] = '';
    $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
    $handler->display->display_options['fields']['edit_node']['text'] = '[edit]';
    /* Sort criterion: Content: Section ID (field_pc_section_id) */
    $handler->display->display_options['sorts']['field_pc_section_id_value']['id'] = 'field_pc_section_id_value';
    $handler->display->display_options['sorts']['field_pc_section_id_value']['table'] = 'field_data_field_pc_section_id';
    $handler->display->display_options['sorts']['field_pc_section_id_value']['field'] = 'field_pc_section_id_value';
    /* Contextual filter: Content: Term (field_pc_term) */
    $handler->display->display_options['arguments']['field_pc_term_value']['id'] = 'field_pc_term_value';
    $handler->display->display_options['arguments']['field_pc_term_value']['table'] = 'field_data_field_pc_term';
    $handler->display->display_options['arguments']['field_pc_term_value']['field'] = 'field_pc_term_value';
    $handler->display->display_options['arguments']['field_pc_term_value']['default_action'] = 'empty';
    $handler->display->display_options['arguments']['field_pc_term_value']['default_argument_type'] = 'fixed';
    $handler->display->display_options['arguments']['field_pc_term_value']['summary']['number_of_records'] = '0';
    $handler->display->display_options['arguments']['field_pc_term_value']['summary']['format'] = 'default_summary';
    $handler->display->display_options['arguments']['field_pc_term_value']['summary_options']['items_per_page'] = '25';
    $handler->display->display_options['arguments']['field_pc_term_value']['limit'] = '0';
    /* Contextual filter: Content: Subject Area (field_pc_subj_area) */
    $handler->display->display_options['arguments']['field_pc_subj_area_value']['id'] = 'field_pc_subj_area_value';
    $handler->display->display_options['arguments']['field_pc_subj_area_value']['table'] = 'field_data_field_pc_subj_area';
    $handler->display->display_options['arguments']['field_pc_subj_area_value']['field'] = 'field_pc_subj_area_value';
    $handler->display->display_options['arguments']['field_pc_subj_area_value']['default_argument_type'] = 'fixed';
    $handler->display->display_options['arguments']['field_pc_subj_area_value']['summary']['number_of_records'] = '0';
    $handler->display->display_options['arguments']['field_pc_subj_area_value']['summary']['format'] = 'default_summary';
    $handler->display->display_options['arguments']['field_pc_subj_area_value']['summary_options']['items_per_page'] = '25';
    $handler->display->display_options['arguments']['field_pc_subj_area_value']['limit'] = '0';
    /* Contextual filter: Content: Level (field_pc_level) */
    $handler->display->display_options['arguments']['field_pc_level_value']['id'] = 'field_pc_level_value';
    $handler->display->display_options['arguments']['field_pc_level_value']['table'] = 'field_data_field_pc_level';
    $handler->display->display_options['arguments']['field_pc_level_value']['field'] = 'field_pc_level_value';
    $handler->display->display_options['arguments']['field_pc_level_value']['default_argument_type'] = 'fixed';
    $handler->display->display_options['arguments']['field_pc_level_value']['summary']['number_of_records'] = '0';
    $handler->display->display_options['arguments']['field_pc_level_value']['summary']['format'] = 'default_summary';
    $handler->display->display_options['arguments']['field_pc_level_value']['summary_options']['items_per_page'] = '25';
    $handler->display->display_options['arguments']['field_pc_level_value']['limit'] = '0';
    /* Filter criterion: Content: Published */
    $handler->display->display_options['filters']['status']['id'] = 'status';
    $handler->display->display_options['filters']['status']['table'] = 'node';
    $handler->display->display_options['filters']['status']['field'] = 'status';
    $handler->display->display_options['filters']['status']['value'] = 1;
    $handler->display->display_options['filters']['status']['group'] = 1;
    $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
    /* Filter criterion: Content: Type */
    $handler->display->display_options['filters']['type']['id'] = 'type';
    $handler->display->display_options['filters']['type']['table'] = 'node';
    $handler->display->display_options['filters']['type']['field'] = 'type';
    $handler->display->display_options['filters']['type']['value'] = array(
        'pc_section' => 'pc_section',
    );
    /* Filter criterion: Content: Activity (field_pc_activity) */
    $handler->display->display_options['filters']['field_pc_activity_value']['id'] = 'field_pc_activity_value';
    $handler->display->display_options['filters']['field_pc_activity_value']['table'] = 'field_data_field_pc_activity';
    $handler->display->display_options['filters']['field_pc_activity_value']['field'] = 'field_pc_activity_value';
    $handler->display->display_options['filters']['field_pc_activity_value']['operator'] = '!=';
    $handler->display->display_options['filters']['field_pc_activity_value']['value'] = 'REC';
    /* Filter criterion: Content: Activity (field_pc_activity) */
    $handler->display->display_options['filters']['field_pc_activity_value_1']['id'] = 'field_pc_activity_value_1';
    $handler->display->display_options['filters']['field_pc_activity_value_1']['table'] = 'field_data_field_pc_activity';
    $handler->display->display_options['filters']['field_pc_activity_value_1']['field'] = 'field_pc_activity_value';
    $handler->display->display_options['filters']['field_pc_activity_value_1']['operator'] = '!=';
    $handler->display->display_options['filters']['field_pc_activity_value_1']['value'] = 'DIS';
    /* Filter criterion: Content: Activity (field_pc_activity) */
    $handler->display->display_options['filters']['field_pc_activity_value_2']['id'] = 'field_pc_activity_value_2';
    $handler->display->display_options['filters']['field_pc_activity_value_2']['table'] = 'field_data_field_pc_activity';
    $handler->display->display_options['filters']['field_pc_activity_value_2']['field'] = 'field_pc_activity_value';
    $handler->display->display_options['filters']['field_pc_activity_value_2']['operator'] = '!=';
    $handler->display->display_options['filters']['field_pc_activity_value_2']['value'] = 'IND';
    /* Filter criterion: Content: Activity (field_pc_activity) */
    $handler->display->display_options['filters']['field_pc_activity_value_3']['id'] = 'field_pc_activity_value_3';
    $handler->display->display_options['filters']['field_pc_activity_value_3']['table'] = 'field_data_field_pc_activity';
    $handler->display->display_options['filters']['field_pc_activity_value_3']['field'] = 'field_pc_activity_value';
    $handler->display->display_options['filters']['field_pc_activity_value_3']['operator'] = '!=';
    $handler->display->display_options['filters']['field_pc_activity_value_3']['value'] = 'MST';
    $views[$view->name] = $view;

    // At the end, return array of default views.
    return $views;
}
