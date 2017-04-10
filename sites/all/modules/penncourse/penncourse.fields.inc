<?php
/**
 * @file
 * penncourse.fields.inc
 *
 * Field definitions for the penncourse module
 */

function penncourse_build_fields() {

    // field_pc_descr
    field_create_field(array(
        'translatable' => '0',
        'entity_types' => array(),
        'settings' => array(),
        'storage' => array(
            'type' => 'field_sql_storage',
            'settings' => array(),
            'module' => 'field_sql_storage',
            'active' => '1',
            'details' => array(
                'sql' => array(
                    'FIELD_LOAD_CURRENT' => array(
                        'field_data_field_pc_descr' => array(
                            'value' => 'field_pc_descr_value',
                            'format' => 'field_pc_descr_format',
                        ),
                    ),
                    'FIELD_LOAD_REVISION' => array(
                        'field_revision_field_pc_descr' => array(
                            'value' => 'field_pc_descr_value',
                            'format' => 'field_pc_descr_format',
                        ),
                    ),
                ),
            ),
        ),
        'foreign keys' => array(
            'format' => array(
                'table' => 'filter_format',
                'columns' => array(
                    'format' => 'format',
                ),
            ),
        ),
        'indexes' => array(
            'format' => array(
                'format',
            ),
        ),
        'field_name' => 'field_pc_descr',
        'type' => 'text_long',
        'module' => 'text',
        'active' => '1',
        'locked' => '0',
        'cardinality' => '1',
        'deleted' => '0',
        'columns' => array(
            'value' => array(
                'type' => 'text',
                'size' => 'big',
                'not null' => FALSE,
            ),
            'format' => array(
                'type' => 'varchar',
                'length' => 255,
                'not null' => FALSE,
            ),
        ),
        'bundles' => array(
            'node' => array(
                'pc_course',
                'pc_section',
            ),
        ),
    ));
    // instance in pc_section
    field_create_instance(array(
        'label' => 'Description',
        'widget' => array(
            'weight' => '1',
            'type' => 'text_textarea',
            'module' => 'text',
            'active' => 1,
            'settings' => array(
                'rows' => '5',
            ),
        ),
        'settings' => array(
            'text_processing' => '0',
            'user_register_form' => FALSE,
        ),
        'display' => array(
            'default' => array(
                'label' => 'above',
                'type' => 'text_default',
                'settings' => array(),
                'module' => 'text',
                'weight' => 0,
            ),
            'teaser' => array(
                'type' => 'hidden',
                'label' => 'above',
                'settings' => array(),
                'weight' => 0,
            ),
        ),
        'required' => 0,
        'description' => '',
        'default_value' => NULL,
        'field_name' => 'field_pc_descr',
        'entity_type' => 'node',
        'bundle' => 'pc_section',
        'deleted' => '0',
    ));
    // instance in pc_course
    field_create_instance(array(
        'label' => 'Course Description',
        'widget' => array(
            'weight' => '-4',
            'type' => 'text_textarea',
            'module' => 'text',
            'active' => 1,
            'settings' => array(
                'rows' => '5',
            ),
        ),
        'settings' => array(
            'text_processing' => '0',
            'user_register_form' => FALSE,
        ),
        'display' => array(
            'default' => array(
                'label' => 'above',
                'type' => 'text_default',
                'settings' => array(),
                'module' => 'text',
                'weight' => 0,
            ),
            'teaser' => array(
                'type' => 'hidden',
                'label' => 'above',
                'settings' => array(),
                'weight' => 0,
            ),
        ),
        'required' => 0,
        'description' => '',
        'default_value' => NULL,
        'field_name' => 'field_pc_descr',
        'entity_type' => 'node',
        'bundle' => 'pc_course',
        'deleted' => '0',
    ));
    // end of field_pc_descr

    // ***********************
    // field_pc_inv_title
    field_create_field(array(
        'translatable' => '0',
        'entity_types' => array(),
        'settings' => array(
            'max_length' => '300',
        ),
        'storage' => array(
            'type' => 'field_sql_storage',
            'settings' => array(),
            'module' => 'field_sql_storage',
            'active' => '1',
            'details' => array(
                'sql' => array(
                    'FIELD_LOAD_CURRENT' => array(
                        'field_data_field_pc_inv_title' => array(
                            'value' => 'field_pc_inv_title_value',
                            'format' => 'field_pc_inv_title_format',
                        ),
                    ),
                    'FIELD_LOAD_REVISION' => array(
                        'field_revision_field_pc_inv_title' => array(
                            'value' => 'field_pc_inv_title_value',
                            'format' => 'field_pc_inv_title_format',
                        ),
                    ),
                ),
            ),
        ),
        'foreign keys' => array(
            'format' => array(
                'table' => 'filter_format',
                'columns' => array(
                    'format' => 'format',
                ),
            ),
        ),
        'indexes' => array(
            'format' => array(
                'format',
            ),
        ),
        'field_name' => 'field_pc_inv_title',
        'type' => 'text',
        'module' => 'text',
        'active' => '1',
        'locked' => '0',
        'cardinality' => '1',
        'deleted' => '0',
        'columns' => array(
            'value' => array(
                'type' => 'varchar',
                'length' => '300',
                'not null' => FALSE,
            ),
            'format' => array(
                'type' => 'varchar',
                'length' => 255,
                'not null' => FALSE,
            ),
        ),
        'bundles' => array(
            'node' => array(
                'pc_course',
            ),
        ),
    ));
    // instance pc_course
    field_create_instance(array(
        'label' => 'Course Inventory Title',
        'widget' => array(
            'weight' => '-3',
            'type' => 'text_textfield',
            'module' => 'text',
            'active' => 1,
            'settings' => array(
                'size' => '60',
            ),
        ),
        'settings' => array(
            'text_processing' => '0',
            'user_register_form' => FALSE,
        ),
        'display' => array(
            'default' => array(
                'label' => 'above',
                'type' => 'text_default',
                'settings' => array(),
                'module' => 'text',
                'weight' => 1,
            ),
            'teaser' => array(
                'type' => 'hidden',
                'label' => 'above',
                'settings' => array(),
                'weight' => 0,
            ),
        ),
        'required' => 0,
        'description' => '',
        'default_value' => NULL,
        'field_name' => 'field_pc_inv_title',
        'entity_type' => 'node',
        'bundle' => 'pc_course',
        'deleted' => '0',
    ));
    // end field_pc_inv_title

    // ***********************
    // field_pc_course_id
    field_create_field(array(
        'translatable' => '0',
        'entity_types' => array(),
        'settings' => array(
            'max_length' => '10',
        ),
        'storage' => array(
            'type' => 'field_sql_storage',
            'settings' => array(),
            'module' => 'field_sql_storage',
            'active' => '1',
            'details' => array(
                'sql' => array(
                    'FIELD_LOAD_CURRENT' => array(
                        'field_data_field_pc_course_id' => array(
                            'value' => 'field_pc_course_id_value',
                            'format' => 'field_pc_course_id_format',
                        ),
                    ),
                    'FIELD_LOAD_REVISION' => array(
                        'field_revision_field_pc_course_id' => array(
                            'value' => 'field_pc_course_id_value',
                            'format' => 'field_pc_course_id_format',
                        ),
                    ),
                ),
            ),
        ),
        'foreign keys' => array(
            'format' => array(
                'table' => 'filter_format',
                'columns' => array(
                    'format' => 'format',
                ),
            ),
        ),
        'indexes' => array(
            'format' => array(
                'format',
            ),
        ),
        'field_name' => 'field_pc_course_id',
        'type' => 'text',
        'module' => 'text',
        'active' => '1',
        'locked' => '0',
        'cardinality' => '1',
        'deleted' => '0',
        'columns' => array(
            'value' => array(
                'type' => 'varchar',
                'length' => '10',
                'not null' => FALSE,
            ),
            'format' => array(
                'type' => 'varchar',
                'length' => 255,
                'not null' => FALSE,
            ),
        ),
        'bundles' => array(
            'node' => array(
                'pc_course',
            ),
        ),
    ));
    // instance pc_course
    field_create_instance(array(
        'label' => 'Course ID',
        'widget' => array(
            'weight' => '-1',
            'type' => 'text_textfield',
            'module' => 'text',
            'active' => 1,
            'settings' => array(
                'size' => '10',
            ),
        ),
        'settings' => array(
            'text_processing' => '0',
            'user_register_form' => FALSE,
        ),
        'display' => array(
            'default' => array(
                'label' => 'above',
                'type' => 'text_default',
                'settings' => array(),
                'module' => 'text',
                'weight' => 3,
            ),
            'teaser' => array(
                'type' => 'hidden',
                'label' => 'above',
                'settings' => array(),
                'weight' => 0,
            ),
        ),
        'required' => 1,
        'description' => 'The course identifier (eg, ANTH001).',
        'default_value' => NULL,
        'field_name' => 'field_pc_course_id',
        'entity_type' => 'node',
        'bundle' => 'pc_course',
        'deleted' => '0',
    ));    // end field_pc_course_id

    // ***********************
    // field_pc_title
    field_create_field(array(
        'translatable' => '0',
        'entity_types' => array(),
        'settings' => array(
            'max_length' => '255',
        ),
        'storage' => array(
            'type' => 'field_sql_storage',
            'settings' => array(),
            'module' => 'field_sql_storage',
            'active' => '1',
            'details' => array(
                'sql' => array(
                    'FIELD_LOAD_CURRENT' => array(
                        'field_data_field_pc_title' => array(
                            'value' => 'field_pc_title_value',
                            'format' => 'field_pc_title_format',
                        ),
                    ),
                    'FIELD_LOAD_REVISION' => array(
                        'field_revision_field_pc_title' => array(
                            'value' => 'field_pc_title_value',
                            'format' => 'field_pc_title_format',
                        ),
                    ),
                ),
            ),
        ),
        'foreign keys' => array(
            'format' => array(
                'table' => 'filter_format',
                'columns' => array(
                    'format' => 'format',
                ),
            ),
        ),
        'indexes' => array(
            'format' => array(
                'format',
            ),
        ),
        'field_name' => 'field_pc_title',
        'type' => 'text',
        'module' => 'text',
        'active' => '1',
        'locked' => '0',
        'cardinality' => '1',
        'deleted' => '0',
        'columns' => array(
            'value' => array(
                'type' => 'varchar',
                'length' => '255',
                'not null' => FALSE,
            ),
            'format' => array(
                'type' => 'varchar',
                'length' => 255,
                'not null' => FALSE,
            ),
        ),
        'bundles' => array(
            'node' => array(
                'pc_course',
            ),
        ),
    ));
    // instance pc_course
    field_create_instance(array(
        'label' => 'Title (text only)',
        'widget' => array(
            'weight' => '0',
            'type' => 'text_textfield',
            'module' => 'text',
            'active' => 1,
            'settings' => array(
                'size' => '60',
            ),
        ),
        'settings' => array(
            'text_processing' => '0',
            'user_register_form' => FALSE,
        ),
        'display' => array(
            'default' => array(
                'label' => 'above',
                'type' => 'text_default',
                'settings' => array(),
                'module' => 'text',
                'weight' => 4,
            ),
            'teaser' => array(
                'type' => 'hidden',
                'label' => 'above',
                'settings' => array(),
                'weight' => 0,
            ),
        ),
        'required' => 0,
        'description' => 'The node title will include the course ID as a prefix (eg, "ANTH001 - Introduction to Anthropology"). This field should contain only the text of the course title.',
        'default_value' => NULL,
        'field_name' => 'field_pc_title',
        'entity_type' => 'node',
        'bundle' => 'pc_course',
        'deleted' => '0',
    ));
    // instance pc_section
    field_create_instance(array(
        'label' => 'Title (text only)',
        'widget' => array(
            'weight' => '1',
            'type' => 'text_textfield',
            'module' => 'text',
            'active' => 1,
            'settings' => array(
                'size' => '60',
            ),
        ),
        'settings' => array(
            'text_processing' => '0',
            'user_register_form' => FALSE,
        ),
        'display' => array(
            'default' => array(
                'label' => 'above',
                'type' => 'text_default',
                'settings' => array(),
                'module' => 'text',
                'weight' => 16,
            ),
            'teaser' => array(
                'type' => 'hidden',
                'label' => 'above',
                'settings' => array(),
                'weight' => 0,
            ),
        ),
        'required' => 0,
        'description' => '',
        'default_value' => NULL,
        'field_name' => 'field_pc_title',
        'entity_type' => 'node',
        'bundle' => 'pc_section',
        'deleted' => '0',
    ));
    // end field_pc_title

    // ***********************
    // field_pc_status
    field_create_field(array(
        'translatable' => '0',
        'entity_types' => array(),
        'settings' => array(
            'max_length' => '10',
        ),
        'storage' => array(
            'type' => 'field_sql_storage',
            'settings' => array(),
            'module' => 'field_sql_storage',
            'active' => '1',
            'details' => array(
                'sql' => array(
                    'FIELD_LOAD_CURRENT' => array(
                        'field_data_field_pc_status' => array(
                            'value' => 'field_pc_status_value',
                            'format' => 'field_pc_status_format',
                        ),
                    ),
                    'FIELD_LOAD_REVISION' => array(
                        'field_revision_field_pc_status' => array(
                            'value' => 'field_pc_status_value',
                            'format' => 'field_pc_status_format',
                        ),
                    ),
                ),
            ),
        ),
        'foreign keys' => array(
            'format' => array(
                'table' => 'filter_format',
                'columns' => array(
                    'format' => 'format',
                ),
            ),
        ),
        'indexes' => array(
            'format' => array(
                'format',
            ),
        ),
        'field_name' => 'field_pc_status',
        'type' => 'text',
        'module' => 'text',
        'active' => '1',
        'locked' => '0',
        'cardinality' => '1',
        'deleted' => '0',
        'columns' => array(
            'value' => array(
                'type' => 'varchar',
                'length' => '10',
                'not null' => FALSE,
            ),
            'format' => array(
                'type' => 'varchar',
                'length' => 255,
                'not null' => FALSE,
            ),
        ),
        'bundles' => array(
            'node' => array(
                'pc_course',
            ),
        ),
    ));
    // instance pc_course
    field_create_instance(array(
        'label' => 'Status',
        'widget' => array(
            'weight' => '4',
            'type' => 'text_textfield',
            'module' => 'text',
            'active' => 1,
            'settings' => array(
                'size' => '10',
            ),
        ),
        'settings' => array(
            'text_processing' => '0',
            'user_register_form' => FALSE,
        ),
        'display' => array(
            'default' => array(
                'label' => 'above',
                'type' => 'text_default',
                'settings' => array(),
                'module' => 'text',
                'weight' => 8,
            ),
            'teaser' => array(
                'type' => 'hidden',
                'label' => 'above',
                'settings' => array(),
                'weight' => 0,
            ),
        ),
        'required' => 0,
        'description' => 'The Status field is intended for use with course data loaded automatically from the Data Warehouse. This field should not be updated by end users.',
        'default_value' => NULL,
        'field_name' => 'field_pc_status',
        'entity_type' => 'node',
        'bundle' => 'pc_course',
        'deleted' => '0',
    ));    // end field_pc_status

    // ***********************
    // field_pc_dist_req
    field_create_field(array(
        'translatable' => '0',
        'entity_types' => array(),
        'settings' => array(
            'max_length' => '1000',
        ),
        'storage' => array(
            'type' => 'field_sql_storage',
            'settings' => array(),
            'module' => 'field_sql_storage',
            'active' => '1',
            'details' => array(
                'sql' => array(
                    'FIELD_LOAD_CURRENT' => array(
                        'field_data_field_pc_dist_req' => array(
                            'value' => 'field_pc_dist_req_value',
                            'format' => 'field_pc_dist_req_format',
                        ),
                    ),
                    'FIELD_LOAD_REVISION' => array(
                        'field_revision_field_pc_dist_req' => array(
                            'value' => 'field_pc_dist_req_value',
                            'format' => 'field_pc_dist_req_format',
                        ),
                    ),
                ),
            ),
        ),
        'foreign keys' => array(
            'format' => array(
                'table' => 'filter_format',
                'columns' => array(
                    'format' => 'format',
                ),
            ),
        ),
        'indexes' => array(
            'format' => array(
                'format',
            ),
        ),
        'field_name' => 'field_pc_dist_req',
        'type' => 'text',
        'module' => 'text',
        'active' => '1',
        'locked' => '0',
        'cardinality' => '1',
        'deleted' => '0',
        'columns' => array(
            'value' => array(
                'type' => 'varchar',
                'length' => '1000',
                'not null' => FALSE,
            ),
            'format' => array(
                'type' => 'varchar',
                'length' => 255,
                'not null' => FALSE,
            ),
        ),
        'bundles' => array(
            'node' => array(
                'pc_course',
            ),
        ),
    ));
    // instance pc_course
    field_create_instance(array(
        'label' => 'Fulfills',
        'widget' => array(
            'weight' => '5',
            'type' => 'text_textfield',
            'module' => 'text',
            'active' => 1,
            'settings' => array(
                'size' => '60',
            ),
        ),
        'settings' => array(
            'text_processing' => '0',
            'user_register_form' => FALSE,
        ),
        'display' => array(
            'default' => array(
                'label' => 'above',
                'type' => 'text_default',
                'settings' => array(),
                'module' => 'text',
                'weight' => 9,
            ),
            'teaser' => array(
                'type' => 'hidden',
                'label' => 'above',
                'settings' => array(),
                'weight' => 0,
            ),
        ),
        'required' => 0,
        'description' => '',
        'default_value' => NULL,
        'field_name' => 'field_pc_dist_req',
        'entity_type' => 'node',
        'bundle' => 'pc_course',
        'deleted' => '0',
    ));
    // end field_pc_dist_req

    // ***********************
    // field_pc_instructors
    field_create_field(array(
        'translatable' => '0',
        'entity_types' => array(),
        'settings' => array(
            'max_length' => '1000',
        ),
        'storage' => array(
            'type' => 'field_sql_storage',
            'settings' => array(),
            'module' => 'field_sql_storage',
            'active' => '1',
            'details' => array(
                'sql' => array(
                    'FIELD_LOAD_CURRENT' => array(
                        'field_data_field_pc_instructors' => array(
                            'value' => 'field_pc_instructors_value',
                            'format' => 'field_pc_instructors_format',
                        ),
                    ),
                    'FIELD_LOAD_REVISION' => array(
                        'field_revision_field_pc_instructors' => array(
                            'value' => 'field_pc_instructors_value',
                            'format' => 'field_pc_instructors_format',
                        ),
                    ),
                ),
            ),
        ),
        'foreign keys' => array(
            'format' => array(
                'table' => 'filter_format',
                'columns' => array(
                    'format' => 'format',
                ),
            ),
        ),
        'indexes' => array(
            'format' => array(
                'format',
            ),
        ),
        'field_name' => 'field_pc_instructors',
        'type' => 'text',
        'module' => 'text',
        'active' => '1',
        'locked' => '0',
        'cardinality' => '1',
        'deleted' => '0',
        'columns' => array(
            'value' => array(
                'type' => 'varchar',
                'length' => '1000',
                'not null' => FALSE,
            ),
            'format' => array(
                'type' => 'varchar',
                'length' => 255,
                'not null' => FALSE,
            ),
        ),
        'bundles' => array(
            'node' => array(
                'pc_section',
            ),
        ),
    ));
    // instance in pc_section
    field_create_instance(array(
        'label' => 'Instructors',
        'widget' => array(
            'weight' => '2',
            'type' => 'text_textfield',
            'module' => 'text',
            'active' => 1,
            'settings' => array(
                'size' => '60',
            ),
        ),
        'settings' => array(
            'text_processing' => '1',
            'user_register_form' => FALSE,
        ),
        'display' => array(
            'default' => array(
                'label' => 'above',
                'type' => 'text_default',
                'settings' => array(),
                'module' => 'text',
                'weight' => 1,
            ),
            'teaser' => array(
                'type' => 'hidden',
                'label' => 'above',
                'settings' => array(),
                'weight' => 0,
            ),
        ),
        'required' => 0,
        'description' => '',
        'default_value' => NULL,
        'field_name' => 'field_pc_instructors',
        'entity_type' => 'node',
        'bundle' => 'pc_section',
        'deleted' => '0',
    ));
    // end field_pc_instructors

    // ************************
    // field_pc_meeting
    field_create_field(array(
        'translatable' => '0',
        'entity_types' => array(),
        'settings' => array(
            'max_length' => '1000',
        ),
        'storage' => array(
            'type' => 'field_sql_storage',
            'settings' => array(),
            'module' => 'field_sql_storage',
            'active' => '1',
            'details' => array(
                'sql' => array(
                    'FIELD_LOAD_CURRENT' => array(
                        'field_data_field_pc_meeting' => array(
                            'value' => 'field_pc_meeting_value',
                            'format' => 'field_pc_meeting_format',
                        ),
                    ),
                    'FIELD_LOAD_REVISION' => array(
                        'field_revision_field_pc_meeting' => array(
                            'value' => 'field_pc_meeting_value',
                            'format' => 'field_pc_meeting_format',
                        ),
                    ),
                ),
            ),
        ),
        'foreign keys' => array(
            'format' => array(
                'table' => 'filter_format',
                'columns' => array(
                    'format' => 'format',
                ),
            ),
        ),
        'indexes' => array(
            'format' => array(
                'format',
            ),
        ),
        'field_name' => 'field_pc_meeting',
        'type' => 'text',
        'module' => 'text',
        'active' => '1',
        'locked' => '0',
        'cardinality' => '1',
        'deleted' => '0',
        'columns' => array(
            'value' => array(
                'type' => 'varchar',
                'length' => '1000',
                'not null' => FALSE,
            ),
            'format' => array(
                'type' => 'varchar',
                'length' => 255,
                'not null' => FALSE,
            ),
        ),
        'bundles' => array(
            'node' => array(
                'pc_section',
            ),
        ),
    ));
    // instance pc_section
    field_create_instance(array(
        'label' => 'Meeting times',
        'widget' => array(
            'weight' => '3',
            'type' => 'text_textfield',
            'module' => 'text',
            'active' => 1,
            'settings' => array(
                'size' => '60',
            ),
        ),
        'settings' => array(
            'text_processing' => '1',
            'user_register_form' => FALSE,
        ),
        'display' => array(
            'default' => array(
                'label' => 'above',
                'type' => 'text_default',
                'settings' => array(),
                'module' => 'text',
                'weight' => 2,
            ),
            'teaser' => array(
                'type' => 'hidden',
                'label' => 'above',
                'settings' => array(),
                'weight' => 0,
            ),
        ),
        'required' => 0,
        'description' => 'This field is populated automatically with data from the data warehouse.',
        'default_value' => NULL,
        'field_name' => 'field_pc_meeting',
        'entity_type' => 'node',
        'bundle' => 'pc_section',
        'deleted' => '0',
    ));
    // end field_pc_meeting

    // *************************
    // field_pc_location
    field_create_field(array(
        'translatable' => '0',
        'entity_types' => array(),
        'settings' => array(
            'max_length' => '1000',
        ),
        'storage' => array(
            'type' => 'field_sql_storage',
            'settings' => array(),
            'module' => 'field_sql_storage',
            'active' => '1',
            'details' => array(
                'sql' => array(
                    'FIELD_LOAD_CURRENT' => array(
                        'field_data_field_pc_location' => array(
                            'value' => 'field_pc_location_value',
                            'format' => 'field_pc_location_format',
                        ),
                    ),
                    'FIELD_LOAD_REVISION' => array(
                        'field_revision_field_pc_location' => array(
                            'value' => 'field_pc_location_value',
                            'format' => 'field_pc_location_format',
                        ),
                    ),
                ),
            ),
        ),
        'foreign keys' => array(
            'format' => array(
                'table' => 'filter_format',
                'columns' => array(
                    'format' => 'format',
                ),
            ),
        ),
        'indexes' => array(
            'format' => array(
                'format',
            ),
        ),
        'field_name' => 'field_pc_location',
        'type' => 'text',
        'module' => 'text',
        'active' => '1',
        'locked' => '0',
        'cardinality' => '1',
        'deleted' => '0',
        'columns' => array(
            'value' => array(
                'type' => 'varchar',
                'length' => '1000',
                'not null' => FALSE,
            ),
            'format' => array(
                'type' => 'varchar',
                'length' => 255,
                'not null' => FALSE,
            ),
        ),
        'bundles' => array(
            'node' => array(
                'pc_section',
            ),
        ),
    ));
    // instance pc_section
    field_create_instance(array(
        'label' => 'Meeting location',
        'widget' => array(
            'weight' => '4',
            'type' => 'text_textfield',
            'module' => 'text',
            'active' => 1,
            'settings' => array(
                'size' => '60',
            ),
        ),
        'settings' => array(
            'text_processing' => '1',
            'user_register_form' => FALSE,
        ),
        'display' => array(
            'default' => array(
                'label' => 'above',
                'type' => 'text_default',
                'settings' => array(),
                'module' => 'text',
                'weight' => 3,
            ),
            'teaser' => array(
                'type' => 'hidden',
                'label' => 'above',
                'settings' => array(),
                'weight' => 0,
            ),
        ),
        'required' => 0,
        'description' => 'This field is populated automatically with data from the data warehouse.',
        'default_value' => NULL,
        'field_name' => 'field_pc_location',
        'entity_type' => 'node',
        'bundle' => 'pc_section',
        'deleted' => '0',
    ));
    // end field_pc_location

    // ***********************
    // field_pc_section_id
    field_create_field(array(
        'translatable' => '0',
        'entity_types' => array(),
        'settings' => array(
            'max_length' => '15',
        ),
        'storage' => array(
            'type' => 'field_sql_storage',
            'settings' => array(),
            'module' => 'field_sql_storage',
            'active' => '1',
            'details' => array(
                'sql' => array(
                    'FIELD_LOAD_CURRENT' => array(
                        'field_data_field_pc_section_id' => array(
                            'value' => 'field_pc_section_id_value',
                            'format' => 'field_pc_section_id_format',
                        ),
                    ),
                    'FIELD_LOAD_REVISION' => array(
                        'field_revision_field_pc_section_id' => array(
                            'value' => 'field_pc_section_id_value',
                            'format' => 'field_pc_section_id_format',
                        ),
                    ),
                ),
            ),
        ),
        'foreign keys' => array(
            'format' => array(
                'table' => 'filter_format',
                'columns' => array(
                    'format' => 'format',
                ),
            ),
        ),
        'indexes' => array(
            'format' => array(
                'format',
            ),
        ),
        'field_name' => 'field_pc_section_id',
        'type' => 'text',
        'module' => 'text',
        'active' => '1',
        'locked' => '0',
        'cardinality' => '1',
        'deleted' => '0',
        'columns' => array(
            'value' => array(
                'type' => 'varchar',
                'length' => '15',
                'not null' => FALSE,
            ),
            'format' => array(
                'type' => 'varchar',
                'length' => 255,
                'not null' => FALSE,
            ),
        ),
        'bundles' => array(
            'node' => array(
                'pc_section',
            ),
        ),
    ));
    // instance pc_section
    field_create_instance(array(
        'label' => 'Section ID',
        'widget' => array(
            'weight' => '5',
            'type' => 'text_textfield',
            'module' => 'text',
            'active' => 1,
            'settings' => array(
                'size' => '12',
            ),
        ),
        'settings' => array(
            'text_processing' => '0',
            'user_register_form' => FALSE,
        ),
        'display' => array(
            'default' => array(
                'label' => 'above',
                'type' => 'text_default',
                'settings' => array(),
                'module' => 'text',
                'weight' => 4,
            ),
            'teaser' => array(
                'type' => 'hidden',
                'label' => 'above',
                'settings' => array(),
                'weight' => 0,
            ),
        ),
        'required' => 1,
        'description' => 'This field is populated automatically with data from the data warehouse.',
        'default_value' => NULL,
        'field_name' => 'field_pc_section_id',
        'entity_type' => 'node',
        'bundle' => 'pc_section',
        'deleted' => '0',
    ));
    // end field_pc_section_id

    // *************************
    // field_pc_course
    field_create_field(array(
        'translatable' => '0',
        'entity_types' => array(),
        'settings' => array(
            'target_type' => 'node',
            'handler' => 'base',
            'handler_settings' => array(
                'target_bundles' => array(
                    'pc_course' => 'pc_course',
                ),
                'sort' => array(
                    'type' => 'none',
                ),
                'behaviors' => array(
                    'views-select-list' => array(
                        'status' => 0,
                    ),
                ),
            ),
        ),
        'storage' => array(
            'type' => 'field_sql_storage',
            'settings' => array(),
            'module' => 'field_sql_storage',
            'active' => '1',
            'details' => array(
                'sql' => array(
                    'FIELD_LOAD_CURRENT' => array(
                        'field_data_field_pc_course' => array(
                            'target_id' => 'field_pc_course_target_id',
                        ),
                    ),
                    'FIELD_LOAD_REVISION' => array(
                        'field_revision_field_pc_course' => array(
                            'target_id' => 'field_pc_course_target_id',
                        ),
                    ),
                ),
            ),
        ),
        'foreign keys' => array(
            'node' => array(
                'table' => 'node',
                'columns' => array(
                    'target_id' => 'nid',
                ),
            ),
        ),
        'indexes' => array(
            'target_id' => array(
                'target_id',
            ),
        ),
        'field_name' => 'field_pc_course',
        'type' => 'entityreference',
        'module' => 'entityreference',
        'active' => '1',
        'locked' => '0',
        'cardinality' => '1',
        'deleted' => '0',
        'columns' => array(
            'target_id' => array(
                'description' => 'The id of the target entity.',
                'type' => 'int',
                'unsigned' => TRUE,
                'not null' => TRUE,
            ),
        ),
        'bundles' => array(
            'node' => array(
                'pc_section',
            ),
        ),
    ));
    field_create_instance(array(
        'label' => 'Course',
        'widget' => array(
            'weight' => '6',
            'type' => 'options_select',
            'module' => 'options',
            'active' => 1,
            'settings' => array(),
        ),
        'settings' => array(
            'user_register_form' => FALSE,
        ),
        'display' => array(
            'default' => array(
                'label' => 'above',
                'type' => 'entityreference_label',
                'settings' => array(
                    'link' => FALSE,
                ),
                'module' => 'entityreference',
                'weight' => 5,
            ),
            'teaser' => array(
                'type' => 'hidden',
                'label' => 'above',
                'settings' => array(),
                'weight' => 0,
            ),
        ),
        'required' => 0,
        'description' => 'This field is populated automatically with data from the data warehouse.',
        'default_value' => NULL,
        'field_name' => 'field_pc_course',
        'entity_type' => 'node',
        'bundle' => 'pc_section',
        'deleted' => '0',
    ));
    // end field_pc_course

    // **********************
    // field_pc_subj_area
    field_create_field(array(
        'translatable' => '0',
        'entity_types' => array(),
        'settings' => array(
            'max_length' => '5',
        ),
        'storage' => array(
            'type' => 'field_sql_storage',
            'settings' => array(),
            'module' => 'field_sql_storage',
            'active' => '1',
            'details' => array(
                'sql' => array(
                    'FIELD_LOAD_CURRENT' => array(
                        'field_data_field_pc_subj_area' => array(
                            'value' => 'field_pc_subj_area_value',
                            'format' => 'field_pc_subj_area_format',
                        ),
                    ),
                    'FIELD_LOAD_REVISION' => array(
                        'field_revision_field_pc_subj_area' => array(
                            'value' => 'field_pc_subj_area_value',
                            'format' => 'field_pc_subj_area_format',
                        ),
                    ),
                ),
            ),
        ),
        'foreign keys' => array(
            'format' => array(
                'table' => 'filter_format',
                'columns' => array(
                    'format' => 'format',
                ),
            ),
        ),
        'indexes' => array(
            'format' => array(
                'format',
            ),
        ),
        'field_name' => 'field_pc_subj_area',
        'type' => 'text',
        'module' => 'text',
        'active' => '1',
        'locked' => '0',
        'cardinality' => '1',
        'deleted' => '0',
        'columns' => array(
            'value' => array(
                'type' => 'varchar',
                'length' => '5',
                'not null' => FALSE,
            ),
            'format' => array(
                'type' => 'varchar',
                'length' => 255,
                'not null' => FALSE,
            ),
        ),
        'bundles' => array(
            'node' => array(
                'pc_course',
                'pc_section',
            ),
        ),
    ));
    // instance in pc_section
    field_create_instance(array(
        'label' => 'Subject Area',
        'widget' => array(
            'weight' => '7',
            'type' => 'text_textfield',
            'module' => 'text',
            'active' => 1,
            'settings' => array(
                'size' => '5',
            ),
        ),
        'settings' => array(
            'text_processing' => '0',
            'user_register_form' => FALSE,
        ),
        'display' => array(
            'default' => array(
                'label' => 'above',
                'type' => 'text_default',
                'settings' => array(),
                'module' => 'text',
                'weight' => 6,
            ),
            'teaser' => array(
                'type' => 'hidden',
                'label' => 'above',
                'settings' => array(),
                'weight' => 0,
            ),
        ),
        'required' => 1,
        'description' => 'The subject area code (eg, ANTH).',
        'default_value' => NULL,
        'field_name' => 'field_pc_subj_area',
        'entity_type' => 'node',
        'bundle' => 'pc_section',
        'deleted' => '0',
    ));
    // instance in pc_course
    field_create_instance(array(
        'label' => 'Subject Area',
        'widget' => array(
            'weight' => '3',
            'type' => 'text_textfield',
            'module' => 'text',
            'active' => 1,
            'settings' => array(
                'size' => '5',
            ),
        ),
        'settings' => array(
            'text_processing' => '0',
            'user_register_form' => FALSE,
        ),
        'display' => array(
            'default' => array(
                'label' => 'above',
                'type' => 'text_default',
                'settings' => array(),
                'module' => 'text',
                'weight' => 7,
            ),
            'teaser' => array(
                'type' => 'hidden',
                'label' => 'above',
                'settings' => array(),
                'weight' => 0,
            ),
        ),
        'required' => 1,
        'description' => 'The subject area code (eg, ANTH).',
        'default_value' => NULL,
        'field_name' => 'field_pc_subj_area',
        'entity_type' => 'node',
        'bundle' => 'pc_course',
        'deleted' => '0',
    ));
    // end field_pc_subj_area

    // *************************
    //field_pc_term
    field_create_field(array(
        'translatable' => '0',
        'entity_types' => array(),
        'settings' => array(
            'max_length' => '10',
        ),
        'storage' => array(
            'type' => 'field_sql_storage',
            'settings' => array(),
            'module' => 'field_sql_storage',
            'active' => '1',
            'details' => array(
                'sql' => array(
                    'FIELD_LOAD_CURRENT' => array(
                        'field_data_field_pc_term' => array(
                            'value' => 'field_pc_term_value',
                            'format' => 'field_pc_term_format',
                        ),
                    ),
                    'FIELD_LOAD_REVISION' => array(
                        'field_revision_field_pc_term' => array(
                            'value' => 'field_pc_term_value',
                            'format' => 'field_pc_term_format',
                        ),
                    ),
                ),
            ),
        ),
        'foreign keys' => array(
            'format' => array(
                'table' => 'filter_format',
                'columns' => array(
                    'format' => 'format',
                ),
            ),
        ),
        'indexes' => array(
            'format' => array(
                'format',
            ),
        ),
        'field_name' => 'field_pc_term',
        'type' => 'text',
        'module' => 'text',
        'active' => '1',
        'locked' => '0',
        'cardinality' => '1',
        'deleted' => '0',
        'columns' => array(
            'value' => array(
                'type' => 'varchar',
                'length' => '10',
                'not null' => FALSE,
            ),
            'format' => array(
                'type' => 'varchar',
                'length' => 255,
                'not null' => FALSE,
            ),
        ),
        'bundles' => array(
            'node' => array(
                'pc_course',
                'pc_section',
            ),
        ),
    ));
    // instance pc_section
    field_create_instance(array(
        'label' => 'Term',
        'widget' => array(
            'weight' => '8',
            'type' => 'text_textfield',
            'module' => 'text',
            'active' => 1,
            'settings' => array(
                'size' => '10',
            ),
        ),
        'settings' => array(
            'text_processing' => '0',
            'user_register_form' => FALSE,
        ),
        'display' => array(
            'default' => array(
                'label' => 'above',
                'type' => 'text_default',
                'settings' => array(),
                'module' => 'text',
                'weight' => 7,
            ),
            'teaser' => array(
                'type' => 'hidden',
                'label' => 'above',
                'settings' => array(),
                'weight' => 0,
            ),
        ),
        'required' => 1,
        'description' => 'The term code for the term in which this course is offered.',
        'default_value' => NULL,
        'field_name' => 'field_pc_term',
        'entity_type' => 'node',
        'bundle' => 'pc_section',
        'deleted' => '0',
    ));
    // instance pc_course
    field_create_instance(array(
        'label' => 'Term',
        'widget' => array(
            'weight' => '1',
            'type' => 'text_textfield',
            'module' => 'text',
            'active' => 1,
            'settings' => array(
                'size' => '10',
            ),
        ),
        'settings' => array(
            'text_processing' => '0',
            'user_register_form' => FALSE,
        ),
        'display' => array(
            'default' => array(
                'label' => 'above',
                'type' => 'text_default',
                'settings' => array(),
                'module' => 'text',
                'weight' => 5,
            ),
            'teaser' => array(
                'type' => 'hidden',
                'label' => 'above',
                'settings' => array(),
                'weight' => 0,
            ),
        ),
        'required' => 1,
        'description' => 'The code for the term in which this course is offered.',
        'default_value' => NULL,
        'field_name' => 'field_pc_term',
        'entity_type' => 'node',
        'bundle' => 'pc_course',
        'deleted' => '0',
    ));
    // end field_pc_term

    // ***********************
    // field_pc_term_session
    field_create_field(array(
        'translatable' => '0',
        'entity_types' => array(),
        'settings' => array(
            'max_length' => '10',
        ),
        'storage' => array(
            'type' => 'field_sql_storage',
            'settings' => array(),
            'module' => 'field_sql_storage',
            'active' => '1',
            'details' => array(
                'sql' => array(
                    'FIELD_LOAD_CURRENT' => array(
                        'field_data_field_pc_term_session' => array(
                            'value' => 'field_pc_term_session_value',
                            'format' => 'field_pc_term_session_format',
                        ),
                    ),
                    'FIELD_LOAD_REVISION' => array(
                        'field_revision_field_pc_term_session' => array(
                            'value' => 'field_pc_term_session_value',
                            'format' => 'field_pc_term_session_format',
                        ),
                    ),
                ),
            ),
        ),
        'foreign keys' => array(
            'format' => array(
                'table' => 'filter_format',
                'columns' => array(
                    'format' => 'format',
                ),
            ),
        ),
        'indexes' => array(
            'format' => array(
                'format',
            ),
        ),
        'field_name' => 'field_pc_term_session',
        'type' => 'text',
        'module' => 'text',
        'active' => '1',
        'locked' => '0',
        'cardinality' => '1',
        'deleted' => '0',
        'columns' => array(
            'value' => array(
                'type' => 'varchar',
                'length' => '10',
                'not null' => FALSE,
            ),
            'format' => array(
                'type' => 'varchar',
                'length' => 255,
                'not null' => FALSE,
            ),
        ),
        'bundles' => array(
            'node' => array(
                'pc_course',
                'pc_section',
            ),
        ),
    ));
    // instance pc_section
    field_create_instance(array(
        'label' => 'Term Session',
        'widget' => array(
            'weight' => '9',
            'type' => 'text_textfield',
            'module' => 'text',
            'active' => 1,
            'settings' => array(
                'size' => '10',
            ),
        ),
        'settings' => array(
            'text_processing' => '0',
            'user_register_form' => FALSE,
        ),
        'display' => array(
            'default' => array(
                'label' => 'above',
                'type' => 'text_default',
                'settings' => array(),
                'module' => 'text',
                'weight' => 8,
            ),
            'teaser' => array(
                'type' => 'hidden',
                'label' => 'above',
                'settings' => array(),
                'weight' => 0,
            ),
        ),
        'required' => 0,
        'description' => 'For summer sessions, this field indicates in which session this section is offered.',
        'default_value' => NULL,
        'field_name' => 'field_pc_term_session',
        'entity_type' => 'node',
        'bundle' => 'pc_section',
        'deleted' => '0',
    ));
    // instance pc_course
    field_create_instance(array(
        'label' => 'Term Session',
        'widget' => array(
            'type' => 'text_textfield',
            'weight' => '2',
            'settings' => array(
                'size' => 60,
            ),
            'module' => 'text',
        ),
        'settings' => array(
            'text_processing' => 0,
            'user_register_form' => FALSE,
        ),
        'display' => array(
            'default' => array(
                'label' => 'above',
                'type' => 'text_default',
                'settings' => array(),
                'module' => 'text',
                'weight' => 6,
            ),
            'teaser' => array(
                'type' => 'hidden',
                'label' => 'above',
                'settings' => array(),
                'weight' => 0,
            ),
        ),
        'required' => FALSE,
        'description' => '',
        'field_name' => 'field_pc_term_session',
        'entity_type' => 'node',
        'bundle' => 'pc_course',
        'deleted' => '0',
        'default_value' => NULL,
    ));
    // end field_pc_term_session

    // **************************
    // field_pc_activity
    field_create_field(array(
        'translatable' => '0',
        'entity_types' => array(),
        'settings' => array(
            'max_length' => '10',
        ),
        'storage' => array(
            'type' => 'field_sql_storage',
            'settings' => array(),
            'module' => 'field_sql_storage',
            'active' => '1',
            'details' => array(
                'sql' => array(
                    'FIELD_LOAD_CURRENT' => array(
                        'field_data_field_pc_activity' => array(
                            'value' => 'field_pc_activity_value',
                            'format' => 'field_pc_activity_format',
                        ),
                    ),
                    'FIELD_LOAD_REVISION' => array(
                        'field_revision_field_pc_activity' => array(
                            'value' => 'field_pc_activity_value',
                            'format' => 'field_pc_activity_format',
                        ),
                    ),
                ),
            ),
        ),
        'foreign keys' => array(
            'format' => array(
                'table' => 'filter_format',
                'columns' => array(
                    'format' => 'format',
                ),
            ),
        ),
        'indexes' => array(
            'format' => array(
                'format',
            ),
        ),
        'field_name' => 'field_pc_activity',
        'type' => 'text',
        'module' => 'text',
        'active' => '1',
        'locked' => '0',
        'cardinality' => '1',
        'deleted' => '0',
        'columns' => array(
            'value' => array(
                'type' => 'varchar',
                'length' => '10',
                'not null' => FALSE,
            ),
            'format' => array(
                'type' => 'varchar',
                'length' => 255,
                'not null' => FALSE,
            ),
        ),
        'bundles' => array(
            'node' => array(
                'pc_section',
            ),
        ),
    ));
    // instance pc_section
    field_create_instance(array(
        'label' => 'Activity',
        'widget' => array(
            'weight' => '10',
            'type' => 'text_textfield',
            'module' => 'text',
            'active' => 1,
            'settings' => array(
                'size' => '10',
            ),
        ),
        'settings' => array(
            'text_processing' => '0',
            'user_register_form' => FALSE,
        ),
        'display' => array(
            'default' => array(
                'label' => 'above',
                'type' => 'text_default',
                'settings' => array(),
                'module' => 'text',
                'weight' => 9,
            ),
            'teaser' => array(
                'type' => 'hidden',
                'label' => 'above',
                'settings' => array(),
                'weight' => 0,
            ),
        ),
        'required' => 0,
        'description' => '',
        'default_value' => NULL,
        'field_name' => 'field_pc_activity',
        'entity_type' => 'node',
        'bundle' => 'pc_section',
        'deleted' => '0',
    ));
    // end field_pc_activity

    // ***********************
    // field_pc_course_no
    field_create_field(array(
        'translatable' => '0',
        'entity_types' => array(),
        'settings' => array(
            'max_length' => '10',
        ),
        'storage' => array(
            'type' => 'field_sql_storage',
            'settings' => array(),
            'module' => 'field_sql_storage',
            'active' => '1',
            'details' => array(
                'sql' => array(
                    'FIELD_LOAD_CURRENT' => array(
                        'field_data_field_pc_course_no' => array(
                            'value' => 'field_pc_course_no_value',
                            'format' => 'field_pc_course_no_format',
                        ),
                    ),
                    'FIELD_LOAD_REVISION' => array(
                        'field_revision_field_pc_course_no' => array(
                            'value' => 'field_pc_course_no_value',
                            'format' => 'field_pc_course_no_format',
                        ),
                    ),
                ),
            ),
        ),
        'foreign keys' => array(
            'format' => array(
                'table' => 'filter_format',
                'columns' => array(
                    'format' => 'format',
                ),
            ),
        ),
        'indexes' => array(
            'format' => array(
                'format',
            ),
        ),
        'field_name' => 'field_pc_course_no',
        'type' => 'text',
        'module' => 'text',
        'active' => '1',
        'locked' => '0',
        'cardinality' => '1',
        'deleted' => '0',
        'columns' => array(
            'value' => array(
                'type' => 'varchar',
                'length' => '10',
                'not null' => FALSE,
            ),
            'format' => array(
                'type' => 'varchar',
                'length' => 255,
                'not null' => FALSE,
            ),
        ),
        'bundles' => array(
            'node' => array(
                'pc_section',
            ),
        ),
    ));
    field_create_instance(array(
        'label' => 'Course Number Only',
        'widget' => array(
            'weight' => '11',
            'type' => 'text_textfield',
            'module' => 'text',
            'active' => 1,
            'settings' => array(
                'size' => '10',
            ),
        ),
        'settings' => array(
            'text_processing' => '0',
            'user_register_form' => FALSE,
        ),
        'display' => array(
            'default' => array(
                'label' => 'above',
                'type' => 'text_default',
                'settings' => array(),
                'module' => 'text',
                'weight' => 10,
            ),
            'teaser' => array(
                'type' => 'hidden',
                'label' => 'above',
                'settings' => array(),
                'weight' => 0,
            ),
        ),
        'required' => 1,
        'description' => '',
        'default_value' => NULL,
        'field_name' => 'field_pc_course_no',
        'entity_type' => 'node',
        'bundle' => 'pc_section',
        'deleted' => '0',
    ));
    // end field_pc_course_no

    // *************************
    // field_pc_section_no
    field_create_field(array(
        'translatable' => '0',
        'entity_types' => array(),
        'settings' => array(
            'max_length' => '10',
        ),
        'storage' => array(
            'type' => 'field_sql_storage',
            'settings' => array(),
            'module' => 'field_sql_storage',
            'active' => '1',
            'details' => array(
                'sql' => array(
                    'FIELD_LOAD_CURRENT' => array(
                        'field_data_field_pc_section_no' => array(
                            'value' => 'field_pc_section_no_value',
                            'format' => 'field_pc_section_no_format',
                        ),
                    ),
                    'FIELD_LOAD_REVISION' => array(
                        'field_revision_field_pc_section_no' => array(
                            'value' => 'field_pc_section_no_value',
                            'format' => 'field_pc_section_no_format',
                        ),
                    ),
                ),
            ),
        ),
        'foreign keys' => array(
            'format' => array(
                'table' => 'filter_format',
                'columns' => array(
                    'format' => 'format',
                ),
            ),
        ),
        'indexes' => array(
            'format' => array(
                'format',
            ),
        ),
        'field_name' => 'field_pc_section_no',
        'type' => 'text',
        'module' => 'text',
        'active' => '1',
        'locked' => '0',
        'cardinality' => '1',
        'deleted' => '0',
        'columns' => array(
            'value' => array(
                'type' => 'varchar',
                'length' => '10',
                'not null' => FALSE,
            ),
            'format' => array(
                'type' => 'varchar',
                'length' => 255,
                'not null' => FALSE,
            ),
        ),
        'bundles' => array(
            'node' => array(
                'pc_section',
            ),
        ),
    ));
    // instance pc_section
    field_create_instance(array(
        'label' => 'Section Number Only',
        'widget' => array(
            'weight' => '12',
            'type' => 'text_textfield',
            'module' => 'text',
            'active' => 1,
            'settings' => array(
                'size' => '10',
            ),
        ),
        'settings' => array(
            'text_processing' => '0',
            'user_register_form' => FALSE,
        ),
        'display' => array(
            'default' => array(
                'label' => 'above',
                'type' => 'text_default',
                'settings' => array(),
                'module' => 'text',
                'weight' => 11,
            ),
            'teaser' => array(
                'type' => 'hidden',
                'label' => 'above',
                'settings' => array(),
                'weight' => 0,
            ),
        ),
        'required' => 1,
        'description' => '',
        'default_value' => NULL,
        'field_name' => 'field_pc_section_no',
        'entity_type' => 'node',
        'bundle' => 'pc_section',
        'deleted' => '0',
    ));
    // end field_pc_section_number

    // *******************************
    // field_pc_xlist
    field_create_field(array(
        'translatable' => '0',
        'entity_types' => array(),
        'settings' => array(
            'max_length' => '500',
        ),
        'storage' => array(
            'type' => 'field_sql_storage',
            'settings' => array(),
            'module' => 'field_sql_storage',
            'active' => '1',
            'details' => array(
                'sql' => array(
                    'FIELD_LOAD_CURRENT' => array(
                        'field_data_field_pc_xlist' => array(
                            'value' => 'field_pc_xlist_value',
                            'format' => 'field_pc_xlist_format',
                        ),
                    ),
                    'FIELD_LOAD_REVISION' => array(
                        'field_revision_field_pc_xlist' => array(
                            'value' => 'field_pc_xlist_value',
                            'format' => 'field_pc_xlist_format',
                        ),
                    ),
                ),
            ),
        ),
        'foreign keys' => array(
            'format' => array(
                'table' => 'filter_format',
                'columns' => array(
                    'format' => 'format',
                ),
            ),
        ),
        'indexes' => array(
            'format' => array(
                'format',
            ),
        ),
        'field_name' => 'field_pc_xlist',
        'type' => 'text',
        'module' => 'text',
        'active' => '1',
        'locked' => '0',
        'cardinality' => '1',
        'deleted' => '0',
        'columns' => array(
            'value' => array(
                'type' => 'varchar',
                'length' => '500',
                'not null' => FALSE,
            ),
            'format' => array(
                'type' => 'varchar',
                'length' => 255,
                'not null' => FALSE,
            ),
        ),
        'bundles' => array(
            'node' => array(
                'pc_section',
            ),
        ),
    ));
    // instance pc_section
    field_create_instance(array(
        'label' => 'Cross Listings',
        'widget' => array(
            'weight' => '13',
            'type' => 'text_textfield',
            'module' => 'text',
            'active' => 1,
            'settings' => array(
                'size' => '60',
            ),
        ),
        'settings' => array(
            'text_processing' => '1',
            'user_register_form' => FALSE,
        ),
        'display' => array(
            'default' => array(
                'label' => 'above',
                'type' => 'text_default',
                'settings' => array(),
                'module' => 'text',
                'weight' => 12,
            ),
            'teaser' => array(
                'type' => 'hidden',
                'label' => 'above',
                'settings' => array(),
                'weight' => 0,
            ),
        ),
        'required' => 0,
        'description' => '',
        'default_value' => NULL,
        'field_name' => 'field_pc_xlist',
        'entity_type' => 'node',
        'bundle' => 'pc_section',
        'deleted' => '0',
    ));
    // end field_pc_xlist

    // **************************
    // field_pc_syllabus_url
    field_create_field(array(
        'translatable' => '0',
        'entity_types' => array(),
        'settings' => array(
            'attributes' => array(
                'target' => 'default',
                'class' => '',
                'rel' => '',
            ),
            'url' => 0,
            'title' => 'optional',
            'title_value' => '',
            'title_maxlength' => 128,
            'enable_tokens' => 1,
            'display' => array(
                'url_cutoff' => 80,
            ),
        ),
        'storage' => array(
            'type' => 'field_sql_storage',
            'settings' => array(),
            'module' => 'field_sql_storage',
            'active' => '1',
            'details' => array(
                'sql' => array(
                    'FIELD_LOAD_CURRENT' => array(
                        'field_data_field_pc_syllabus_url' => array(
                            'url' => 'field_pc_syllabus_url_url',
                            'title' => 'field_pc_syllabus_url_title',
                            'attributes' => 'field_pc_syllabus_url_attributes',
                        ),
                    ),
                    'FIELD_LOAD_REVISION' => array(
                        'field_revision_field_pc_syllabus_url' => array(
                            'url' => 'field_pc_syllabus_url_url',
                            'title' => 'field_pc_syllabus_url_title',
                            'attributes' => 'field_pc_syllabus_url_attributes',
                        ),
                    ),
                ),
            ),
        ),
        'foreign keys' => array(),
        'indexes' => array(),
        'field_name' => 'field_pc_syllabus_url',
        'type' => 'link_field',
        'module' => 'link',
        'active' => '1',
        'locked' => '0',
        'cardinality' => '1',
        'deleted' => '0',
        'columns' => array(
            'url' => array(
                'type' => 'varchar',
                'length' => 2048,
                'not null' => FALSE,
                'sortable' => TRUE,
            ),
            'title' => array(
                'type' => 'varchar',
                'length' => 255,
                'not null' => FALSE,
                'sortable' => TRUE,
            ),
            'attributes' => array(
                'type' => 'text',
                'size' => 'medium',
                'not null' => FALSE,
            ),
        ),
        'bundles' => array(
            'node' => array(
                'pc_course',
                'pc_section',
            ),
        ),
    ));
    // instance pc_section
    field_create_instance(array(
        'label' => 'Syllabus URL',
        'widget' => array(
            'weight' => '14',
            'type' => 'link_field',
            'module' => 'link',
            'active' => 0,
            'settings' => array(),
        ),
        'settings' => array(
            'validate_url' => 0,
            'url' => 0,
            'title' => 'none',
            'title_value' => '',
            'title_maxlength' => '128',
            'display' => array(
                'url_cutoff' => '',
            ),
            'attributes' => array(
                'target' => 'default',
                'rel' => 'nofollow',
                'class' => 'pc-syllabus-url',
                'configurable_title' => 0,
                'title' => '',
            ),
            'rel_remove' => 'default',
            'enable_tokens' => 1,
            'user_register_form' => FALSE,
        ),
        'display' => array(
            'default' => array(
                'label' => 'above',
                'type' => 'link_default',
                'settings' => array(),
                'module' => 'link',
                'weight' => 13,
            ),
            'teaser' => array(
                'type' => 'hidden',
                'label' => 'above',
                'settings' => array(),
                'weight' => 0,
            ),
        ),
        'required' => 0,
        'description' => 'Enter the URL for a section-specific syllabus.',
        'default_value' => NULL,
        'field_name' => 'field_pc_syllabus_url',
        'entity_type' => 'node',
        'bundle' => 'pc_section',
        'deleted' => '0',
    ));
    // instance pc_course
    field_create_instance(array(
        'label' => 'Syllabus URL',
        'widget' => array(
            'weight' => '-2',
            'type' => 'link_field',
            'module' => 'link',
            'active' => 0,
            'settings' => array(),
        ),
        'settings' => array(
            'validate_url' => 1,
            'url' => 0,
            'title' => 'none',
            'title_value' => '',
            'title_maxlength' => '128',
            'display' => array(
                'url_cutoff' => '80',
            ),
            'attributes' => array(
                'target' => 'default',
                'rel' => '',
                'class' => 'pc-syllabus-url',
                'configurable_title' => 0,
                'title' => '',
            ),
            'rel_remove' => 'default',
            'enable_tokens' => 1,
            'user_register_form' => FALSE,
        ),
        'display' => array(
            'default' => array(
                'label' => 'above',
                'type' => 'link_default',
                'settings' => array(),
                'module' => 'link',
                'weight' => 2,
            ),
            'teaser' => array(
                'type' => 'hidden',
                'label' => 'above',
                'settings' => array(),
                'weight' => 0,
            ),
        ),
        'required' => 0,
        'description' => 'Enter the URL for the course syllabus.',
        'default_value' => NULL,
        'field_name' => 'field_pc_syllabus_url',
        'entity_type' => 'node',
        'bundle' => 'pc_course',
        'deleted' => '0',
    ));
    // end field_pc_syllabus_url

    // ****************************
    // field_pc_syllabus
    field_create_field(array(
        'translatable' => '0',
        'entity_types' => array(),
        'settings' => array(
            'display_field' => 0,
            'display_default' => 0,
            'uri_scheme' => 'public',
        ),
        'storage' => array(
            'type' => 'field_sql_storage',
            'settings' => array(),
            'module' => 'field_sql_storage',
            'active' => '1',
            'details' => array(
                'sql' => array(
                    'FIELD_LOAD_CURRENT' => array(
                        'field_data_field_pc_syllabus' => array(
                            'fid' => 'field_pc_syllabus_fid',
                            'display' => 'field_pc_syllabus_display',
                            'description' => 'field_pc_syllabus_description',
                        ),
                    ),
                    'FIELD_LOAD_REVISION' => array(
                        'field_revision_field_pc_syllabus' => array(
                            'fid' => 'field_pc_syllabus_fid',
                            'display' => 'field_pc_syllabus_display',
                            'description' => 'field_pc_syllabus_description',
                        ),
                    ),
                ),
            ),
        ),
        'foreign keys' => array(
            'fid' => array(
                'table' => 'file_managed',
                'columns' => array(
                    'fid' => 'fid',
                ),
            ),
        ),
        'indexes' => array(
            'fid' => array(
                'fid',
            ),
        ),
        'field_name' => 'field_pc_syllabus',
        'type' => 'file',
        'module' => 'file',
        'active' => '1',
        'locked' => '0',
        'cardinality' => '1',
        'deleted' => '0',
        'columns' => array(
            'fid' => array(
                'description' => 'The {file_managed}.fid being referenced in this field.',
                'type' => 'int',
                'not null' => FALSE,
                'unsigned' => TRUE,
            ),
            'display' => array(
                'description' => 'Flag to control whether this file should be displayed when viewing content.',
                'type' => 'int',
                'size' => 'tiny',
                'unsigned' => TRUE,
                'not null' => TRUE,
                'default' => 1,
            ),
            'description' => array(
                'description' => 'A description of the file.',
                'type' => 'text',
                'not null' => FALSE,
            ),
        ),
        'bundles' => array(
            'node' => array(
                'pc_section',
            ),
        ),
    ));
    // instance pc_section
    field_create_instance(array(
        'label' => 'Syllabus',
        'widget' => array(
            'weight' => '15',
            'type' => 'file_generic',
            'module' => 'file',
            'active' => 1,
            'settings' => array(
                'progress_indicator' => 'throbber',
            ),
        ),
        'settings' => array(
            'file_directory' => 'penncourse',
            'file_extensions' => 'txt pdf doc docx rtf',
            'max_filesize' => '',
            'description_field' => 0,
            'user_register_form' => FALSE,
        ),
        'display' => array(
            'default' => array(
                'label' => 'above',
                'type' => 'file_default',
                'settings' => array(),
                'module' => 'file',
                'weight' => 14,
            ),
            'teaser' => array(
                'type' => 'hidden',
                'label' => 'above',
                'settings' => array(),
                'weight' => 0,
            ),
        ),
        'required' => 0,
        'description' => 'Upload a public syllabus file.',
        'field_name' => 'field_pc_syllabus',
        'entity_type' => 'node',
        'bundle' => 'pc_section',
        'deleted' => '0',
    ));
    // end field_pc_syllabus

    // ****************************
    // field_pc_sec_reg_ctrl
    field_create_field(array(
        'translatable' => '0',
        'entity_types' => array(),
        'settings' => array(
            'max_length' => '1000',
        ),
        'storage' => array(
            'type' => 'field_sql_storage',
            'settings' => array(),
            'module' => 'field_sql_storage',
            'active' => '1',
            'details' => array(
                'sql' => array(
                    'FIELD_LOAD_CURRENT' => array(
                        'field_data_field_pc_sec_reg_ctrl' => array(
                            'value' => 'field_pc_sec_reg_ctrl_value',
                            'format' => 'field_pc_sec_reg_ctrl_format',
                        ),
                    ),
                    'FIELD_LOAD_REVISION' => array(
                        'field_revision_field_pc_sec_reg_ctrl' => array(
                            'value' => 'field_pc_sec_reg_ctrl_value',
                            'format' => 'field_pc_sec_reg_ctrl_format',
                        ),
                    ),
                ),
            ),
        ),
        'foreign keys' => array(
            'format' => array(
                'table' => 'filter_format',
                'columns' => array(
                    'format' => 'format',
                ),
            ),
        ),
        'indexes' => array(
            'format' => array(
                'format',
            ),
        ),
        'field_name' => 'field_pc_sec_reg_ctrl',
        'type' => 'text',
        'module' => 'text',
        'active' => '1',
        'locked' => '0',
        'cardinality' => '1',
        'deleted' => '0',
        'columns' => array(
            'value' => array(
                'type' => 'varchar',
                'length' => '1000',
                'not null' => FALSE,
            ),
            'format' => array(
                'type' => 'varchar',
                'length' => 255,
                'not null' => FALSE,
            ),
        ),
        'bundles' => array(
            'node' => array(
                'pc_section',
            ),
        ),
    ));
    // instance pc_section
    field_create_instance(array(
        'label' => 'Registration Notes',
        'widget' => array(
            'type' => 'text_textfield',
            'weight' => '16',
            'settings' => array(
                'size' => 60,
            ),
            'module' => 'text',
        ),
        'settings' => array(
            'text_processing' => 0,
            'user_register_form' => FALSE,
        ),
        'display' => array(
            'default' => array(
                'label' => 'above',
                'type' => 'text_default',
                'settings' => array(),
                'module' => 'text',
                'weight' => 15,
            ),
            'teaser' => array(
                'type' => 'hidden',
                'label' => 'above',
                'settings' => array(),
                'weight' => 0,
            ),
        ),
        'required' => FALSE,
        'description' => '',
        'field_name' => 'field_pc_sec_reg_ctrl',
        'entity_type' => 'node',
        'bundle' => 'pc_section',
        'deleted' => '0',
        'default_value' => NULL,
    ));
    // end field_pc_sec_reg_ctrl

    // ****************************
    // field_pc_level
    field_create_field(array(
        'translatable' => '0',
        'entity_types' => array(),
        'settings' => array(
            'max_length' => '20',
        ),
        'storage' => array(
            'type' => 'field_sql_storage',
            'settings' => array(),
            'module' => 'field_sql_storage',
            'active' => '1',
            'details' => array(
                'sql' => array(
                    'FIELD_LOAD_CURRENT' => array(
                        'field_data_field_pc_level' => array(
                            'value' => 'field_pc_level_value',
                            'format' => 'field_pc_level_format',
                        ),
                    ),
                    'FIELD_LOAD_REVISION' => array(
                        'field_revision_field_pc_level' => array(
                            'value' => 'field_pc_level_value',
                            'format' => 'field_pc_level_format',
                        ),
                    ),
                ),
            ),
        ),
        'foreign keys' => array(
            'format' => array(
                'table' => 'filter_format',
                'columns' => array(
                    'format' => 'format',
                ),
            ),
        ),
        'indexes' => array(
            'format' => array(
                'format',
            ),
        ),
        'field_name' => 'field_pc_level',
        'type' => 'text',
        'module' => 'text',
        'active' => '1',
        'locked' => '0',
        'cardinality' => '1',
        'deleted' => '0',
        'columns' => array(
            'value' => array(
                'type' => 'varchar',
                'length' => '20',
                'not null' => FALSE,
            ),
            'format' => array(
                'type' => 'varchar',
                'length' => 255,
                'not null' => FALSE,
            ),
        ),
        'bundles' => array(
            'node' => array(
                'pc_course',
                'pc_section',
            ),
        ),
    ));
    // instance pc_course
    field_create_instance(array(
        'label' => 'Level',
        'widget' => array(
            'weight' => '6',
            'type' => 'text_textfield',
            'module' => 'text',
            'active' => 1,
            'settings' => array(
                'size' => '20',
            ),
        ),
        'settings' => array(
            'text_processing' => '0',
            'user_register_form' => FALSE,
        ),
        'display' => array(
            'default' => array(
                'label' => 'above',
                'type' => 'text_default',
                'settings' => array(),
                'module' => 'text',
                'weight' => 10,
            ),
            'teaser' => array(
                'type' => 'hidden',
                'label' => 'above',
                'settings' => array(),
                'weight' => 0,
            ),
        ),
        'required' => 0,
        'description' => '',
        'default_value' => NULL,
        'field_name' => 'field_pc_level',
        'entity_type' => 'node',
        'bundle' => 'pc_course',
        'deleted' => '0',
    ));
    // instance pc_section
    field_create_instance(array(
        'label' => 'Level',
        'widget' => array(
            'weight' => '18',
            'type' => 'text_textfield',
            'module' => 'text',
            'active' => 1,
            'settings' => array(
                'size' => '20',
            ),
        ),
        'settings' => array(
            'text_processing' => '0',
            'user_register_form' => FALSE,
        ),
        'display' => array(
            'default' => array(
                'label' => 'above',
                'type' => 'text_default',
                'settings' => array(),
                'module' => 'text',
                'weight' => 17,
            ),
            'teaser' => array(
                'type' => 'hidden',
                'label' => 'above',
                'settings' => array(),
                'weight' => 0,
            ),
        ),
        'required' => 0,
        'description' => '',
        'default_value' => NULL,
        'field_name' => 'field_pc_level',
        'entity_type' => 'node',
        'bundle' => 'pc_section',
        'deleted' => '0',
    ));
    // end field_pc_level

    // ***********************
    // field_pc_course_int
    field_create_field(array(
        'translatable' => '0',
        'entity_types' => array(),
        'settings' => array(),
        'storage' => array(
            'type' => 'field_sql_storage',
            'settings' => array(),
            'module' => 'field_sql_storage',
            'active' => '1',
            'details' => array(
                'sql' => array(
                    'FIELD_LOAD_CURRENT' => array(
                        'field_data_field_pc_course_int' => array(
                            'value' => 'field_pc_course_int_value',
                        ),
                    ),
                    'FIELD_LOAD_REVISION' => array(
                        'field_revision_field_pc_course_int' => array(
                            'value' => 'field_pc_course_int_value',
                        ),
                    ),
                ),
            ),
        ),
        'foreign keys' => array(),
        'indexes' => array(),
        'field_name' => 'field_pc_course_int',
        'type' => 'number_integer',
        'module' => 'number',
        'active' => '1',
        'locked' => '0',
        'cardinality' => '1',
        'deleted' => '0',
        'columns' => array(
            'value' => array(
                'type' => 'int',
                'not null' => FALSE,
            ),
        ),
        'bundles' => array(
            'node' => array(
                'pc_section',
            ),
        ),
    ));
    // instance pc_section
    field_create_instance(array(
        'label' => 'Course Number Integer',
        'widget' => array(
            'weight' => '19',
            'type' => 'number',
            'module' => 'number',
            'active' => 0,
            'settings' => array(),
        ),
        'settings' => array(
            'min' => '',
            'max' => '',
            'prefix' => '',
            'suffix' => '',
            'user_register_form' => FALSE,
        ),
        'display' => array(
            'default' => array(
                'label' => 'hidden',
                'type' => 'hidden',
                'weight' => '18',
                'settings' => array(),
            ),
            'teaser' => array(
                'type' => 'hidden',
                'label' => 'above',
                'settings' => array(),
                'weight' => 0,
            ),
        ),
        'required' => 1,
        'description' => '',
        'default_value' => NULL,
        'field_name' => 'field_pc_course_int',
        'entity_type' => 'node',
        'bundle' => 'pc_section',
        'deleted' => '0',
    ));
    // end field_pc_course_int

    // ************************
    // field_pc_section_int
    field_create_field(array(
        'translatable' => '0',
        'entity_types' => array(),
        'settings' => array(),
        'storage' => array(
            'type' => 'field_sql_storage',
            'settings' => array(),
            'module' => 'field_sql_storage',
            'active' => '1',
            'details' => array(
                'sql' => array(
                    'FIELD_LOAD_CURRENT' => array(
                        'field_data_field_pc_section_int' => array(
                            'value' => 'field_pc_section_int_value',
                        ),
                    ),
                    'FIELD_LOAD_REVISION' => array(
                        'field_revision_field_pc_section_int' => array(
                            'value' => 'field_pc_section_int_value',
                        ),
                    ),
                ),
            ),
        ),
        'foreign keys' => array(),
        'indexes' => array(),
        'field_name' => 'field_pc_section_int',
        'type' => 'number_integer',
        'module' => 'number',
        'active' => '1',
        'locked' => '0',
        'cardinality' => '1',
        'deleted' => '0',
        'columns' => array(
            'value' => array(
                'type' => 'int',
                'not null' => FALSE,
            ),
        ),
        'bundles' => array(
            'node' => array(
                'pc_section',
            ),
        ),
    ));
    // instance pc_section
    field_create_instance(array(
        'label' => 'Section Number Integer',
        'widget' => array(
            'weight' => '20',
            'type' => 'number',
            'module' => 'number',
            'active' => 0,
            'settings' => array(),
        ),
        'settings' => array(
            'min' => '',
            'max' => '',
            'prefix' => '',
            'suffix' => '',
            'user_register_form' => FALSE,
        ),
        'display' => array(
            'default' => array(
                'label' => 'hidden',
                'type' => 'hidden',
                'weight' => '19',
                'settings' => array(),
            ),
            'teaser' => array(
                'type' => 'hidden',
                'label' => 'above',
                'settings' => array(),
                'weight' => 0,
            ),
        ),
        'required' => 1,
        'description' => '',
        'default_value' => NULL,
        'field_name' => 'field_pc_section_int',
        'entity_type' => 'node',
        'bundle' => 'pc_section',
        'deleted' => '0',
    ));
    // end field_pc_section_int
}