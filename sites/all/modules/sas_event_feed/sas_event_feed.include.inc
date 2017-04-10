<?php
/**
 * @file
 * utility functions for the sas_event_feed module
 */

/**
 * Define and export date formats.
 *
 * We need to define a date format that is supported by the RSS spec and reference that format from
 * our view feed display
 */

// Give the date format type a machine name.
define('SAS_EVENT_FEED_DATE_TYPE', 'sas_event_feed_date_type');

// Define the string to be passed to date().
define('SAS_EVENT_FEED_DATE_FORMAT', 'D, d M Y H:i:s T');

/**
 * return an array of content types formatted for use in an administration form
 * @return array
 */
function _sas_event_feed_get_content_types() {
    $types = node_type_get_types();

    $result = array('' => '');
    foreach ($types as $key => $type) {
        $result[$key] = $type->name;
    }
    return $result;
}

/**
 * return an array of fields for a given content type
 * @param $type
 * @return array
 */
function _sas_event_feed_get_content_fields($type) {
    $fields = field_info_field_map();
    $type_fields = array();

    // add the default body field
    $type_fields[''] = '';

    foreach ($fields as $field_name => $field_data)
    {
        if (isset($field_data['bundles']['node']) && in_array($type, $field_data['bundles']['node']))
        {
            $type_fields[$field_name] = $field_name;
        }
    }

    return $type_fields;
}

function  _sas_event_feed_db_info($field_name) {
    $result = array('name' => $field_name);

    $field_info = field_info_field($field_name);
    $db_info = $field_info['storage']['details']['sql']['FIELD_LOAD_CURRENT'];
    foreach ($db_info as $key => $value) {
        $result['table'] = $key;
        // views assumes '_value' at the end of the column name, so we want to delete it in this case
        $result['column'] = str_replace('_value', '', $value['value']);
    }

    return $result;
} // function _sas_event_feed_db_info

/**
 * Display a single views field.
 *
 * Interesting bits of info:
 * $field->field_alias says what the raw value in $row will be. Reach it like
 * this: @code { $row->{$field->field_alias} @endcode
 *
 * here, for the sas_event_feed feed, we replace all instances of the &nbsp; entity
 */
function sas_event_feed_views_view_field($vars) {
    $view = $vars['view'];
    if ($view->name == 'sas_event_feed') {
        $vars['output'] = str_replace('&nbsp;', ' ', $vars['output']);
    }
    $field = $vars['field'];
    $row = $vars['row'];
    return $vars['output'];
}

