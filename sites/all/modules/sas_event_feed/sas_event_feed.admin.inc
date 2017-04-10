<?php
/**
 * @file
 * Functions for administration of the SAS Event Feed module
 */

function sas_event_feed_admin_settings() {
    module_load_include('inc', 'sas_event_feed', 'sas_event_feed.include');
    $event_type = variable_get('sas_event_feed_content_type');

    if ($event_type) {
        // get fields for the event content type
        $fields = _sas_event_feed_get_content_fields($event_type);
    }

    $form['sas_event_feed_content_type'] = array(
        '#type' => 'select',
        '#title' => t('Event content type'),
        '#options' => _sas_event_feed_get_content_types(),
        // '#options' => array('test' => 'test'),
        '#default_value' => variable_get('sas_event_feed_content_type', 'events'),
        '#description' => t('Select the content type used for event content on this site.'),
    );

    if ($event_type) {
        $form['sas_event_feed_field_description'] = array(
            '#type' => 'select',
            '#title' => t('Description or body field'),
            '#options' => $fields,
            // '#options' => array('test' => 'test'),
            '#default_value' => variable_get('sas_event_feed_field_description', 'body'),
            '#description' => t('Select the field used for event descriptions on this site.'),
        );
        $form['sas_event_feed_field_date'] = array(
            '#type' => 'select',
            '#title' => t('Date field'),
            '#options' => $fields,
            // '#options' => array('test' => 'test'),
            '#default_value' => variable_get('sas_event_feed_field_date', 'field_date'),
            '#description' => t('Select the field used for event dates on this site.'),
        );
        $form['sas_event_feed_field_location'] = array(
            '#type' => 'select',
            '#title' => t('Location field'),
            '#options' => $fields,
            // '#options' => array('test' => 'test'),
            '#default_value' => variable_get('sas_event_feed_field_location', 'field_location'),
            '#description' => t('Select the field used for event locations on this site.'),
        );
    }

    $processed_form = system_settings_form($form);

    return $processed_form;
}
