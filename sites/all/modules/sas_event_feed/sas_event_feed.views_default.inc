<?php
/**
 * @file
 * sas_event_feeds.views_default.inc
 *
 * default views for the SAS Event Feeds module
 */

function sas_event_feed_views_default_views() {
    $views = array();

    $view = new view();
    $view->name = 'sas_event_feed';
    $view->description = '';
    $view->tag = 'default';
    $view->base_table = 'node';
    $view->human_name = 'sas_event_feed';
    $view->core = 7;
    $view->api_version = '3.0';
    $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

    /* Display: Master */
    $handler = $view->new_display('default', 'Master', 'default');
    $handler->display->display_options['title'] = 'Events';
    $handler->display->display_options['use_more'] = TRUE;
    $handler->display->display_options['use_more_always'] = FALSE;
    $handler->display->display_options['use_more_text'] = 'Read More >';
    $handler->display->display_options['access']['type'] = 'perm';
    $handler->display->display_options['cache']['type'] = 'none';
    $handler->display->display_options['query']['type'] = 'views_query';
    $handler->display->display_options['exposed_form']['type'] = 'basic';
    $handler->display->display_options['pager']['type'] = 'none';
    $handler->display->display_options['pager']['options']['offset'] = '0';
    $handler->display->display_options['style_plugin'] = 'list';
    $handler->display->display_options['style_options']['row_class_special'] = FALSE;
    $handler->display->display_options['style_options']['class'] = 'unstyled';
    $handler->display->display_options['row_plugin'] = 'fields';
    $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
    /* Field: Content: Title */
    $handler->display->display_options['fields']['title']['id'] = 'title';
    $handler->display->display_options['fields']['title']['table'] = 'node';
    $handler->display->display_options['fields']['title']['field'] = 'title';
    $handler->display->display_options['fields']['title']['label'] = '';
    $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
    $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
    $handler->display->display_options['fields']['title']['alter']['strip_tags'] = TRUE;
    $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
    $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
    $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
    /* Field: Content: Date */
    $handler->display->display_options['fields']['field_date']['id'] = 'field_date';
    $handler->display->display_options['fields']['field_date']['table'] = 'field_data_field_date';
    $handler->display->display_options['fields']['field_date']['field'] = 'field_date';
    $handler->display->display_options['fields']['field_date']['label'] = '';
    $handler->display->display_options['fields']['field_date']['alter']['strip_tags'] = TRUE;
    $handler->display->display_options['fields']['field_date']['element_label_colon'] = FALSE;
    $handler->display->display_options['fields']['field_date']['element_default_classes'] = FALSE;
    $handler->display->display_options['fields']['field_date']['settings'] = array(
        'format_type' => 'sas_event_feed_date_type',
        'fromto' => 'both',
        'multiple_number' => '',
        'multiple_from' => '',
        'multiple_to' => '',
        'show_repeat_rule' => 'show',
    );
    /* Field: Content: Location */
    $handler->display->display_options['fields']['field_location']['id'] = 'field_location';
    $handler->display->display_options['fields']['field_location']['table'] = 'field_data_field_location';
    $handler->display->display_options['fields']['field_location']['field'] = 'field_location';
    $handler->display->display_options['fields']['field_location']['label'] = '';
    $handler->display->display_options['fields']['field_location']['element_type'] = 'div';
    $handler->display->display_options['fields']['field_location']['element_class'] = 'location';
    $handler->display->display_options['fields']['field_location']['element_label_colon'] = FALSE;
    $handler->display->display_options['fields']['field_location']['element_wrapper_type'] = '0';
    $handler->display->display_options['fields']['field_location']['element_default_classes'] = FALSE;
    /* Field: Content: Updated date */
    $handler->display->display_options['fields']['changed']['id'] = 'changed';
    $handler->display->display_options['fields']['changed']['table'] = 'node';
    $handler->display->display_options['fields']['changed']['field'] = 'changed';
    $handler->display->display_options['fields']['changed']['label'] = '';
    $handler->display->display_options['fields']['changed']['element_label_colon'] = FALSE;
    $handler->display->display_options['fields']['changed']['date_format'] = 'sas_event_feed_date_type';
    $handler->display->display_options['fields']['changed']['second_date_format'] = 'long';
    /* Field: Content: Body */
    $handler->display->display_options['fields']['body']['id'] = 'body';
    $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
    $handler->display->display_options['fields']['body']['field'] = 'body';
    $handler->display->display_options['fields']['body']['label'] = '';
    $handler->display->display_options['fields']['body']['alter']['strip_tags'] = TRUE;
    $handler->display->display_options['fields']['body']['alter']['preserve_tags'] = '<p> <br>';
    $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
    /* Field: Content: Path */
    $handler->display->display_options['fields']['path']['id'] = 'path';
    $handler->display->display_options['fields']['path']['table'] = 'node';
    $handler->display->display_options['fields']['path']['field'] = 'path';
    $handler->display->display_options['fields']['path']['label'] = '';
    $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
    $handler->display->display_options['fields']['path']['element_default_classes'] = FALSE;
    $handler->display->display_options['fields']['path']['absolute'] = TRUE;
    /* Field: Content: Link */
    $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
    $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
    $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
    $handler->display->display_options['fields']['view_node']['label'] = '';
    $handler->display->display_options['fields']['view_node']['alter']['strip_tags'] = TRUE;
    $handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
    $handler->display->display_options['fields']['view_node']['element_default_classes'] = FALSE;
    /* Field: Content: Nid */
    $handler->display->display_options['fields']['nid']['id'] = 'nid';
    $handler->display->display_options['fields']['nid']['table'] = 'node';
    $handler->display->display_options['fields']['nid']['field'] = 'nid';
    $handler->display->display_options['fields']['nid']['label'] = '';
    $handler->display->display_options['fields']['nid']['alter']['strip_tags'] = TRUE;
    $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
    /* Field: Dublin Core Type */
    $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
    $handler->display->display_options['fields']['nothing']['table'] = 'views';
    $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
    $handler->display->display_options['fields']['nothing']['ui_name'] = 'Dublin Core Type';
    $handler->display->display_options['fields']['nothing']['label'] = '';
    $handler->display->display_options['fields']['nothing']['alter']['text'] = 'Event';
    $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
    /* Sort criterion: Content: Date -  start date (field_date) */
    $handler->display->display_options['sorts']['field_date_value']['id'] = 'field_date_value';
    $handler->display->display_options['sorts']['field_date_value']['table'] = 'field_data_field_date';
    $handler->display->display_options['sorts']['field_date_value']['field'] = 'field_date_value';
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
        'events' => 'events',
    );
    /* Filter criterion: Content: Date -  start date (field_date) */
    $handler->display->display_options['filters']['field_date_value']['id'] = 'field_date_value';
    $handler->display->display_options['filters']['field_date_value']['table'] = 'field_data_field_date';
    $handler->display->display_options['filters']['field_date_value']['field'] = 'field_date_value';
    $handler->display->display_options['filters']['field_date_value']['operator'] = '>=';
    $handler->display->display_options['filters']['field_date_value']['default_date'] = 'now';

    /* Display: Event Feed */
    $handler = $view->new_display('feed', 'Event Feed', 'event_feed');
    $handler->display->display_options['display_description'] = 'Feed display for use in calendar aggregation.';
    $handler->display->display_options['pager']['type'] = 'none';
    $handler->display->display_options['pager']['options']['offset'] = '0';
    $handler->display->display_options['style_plugin'] = 'rss_fields';
    $handler->display->display_options['style_options']['channel'] = array(
        'core' => array(
            'sas_views_rss_core' => array(
                'description' => '',
                'language' => '',
                'category' => '',
                'image' => '',
                'copyright' => '',
                'managingEditor' => '',
                'webMaster' => '',
                'generator' => '',
                'docs' => '',
                'cloud' => '',
                'ttl' => '',
                'skipHours' => '',
                'skipDays' => '',
            ),
        ),
    );
    $handler->display->display_options['style_options']['item'] = array(
        'core' => array(
            'sas_views_rss_core' => array(
                'title' => 'title',
                'link' => 'path',
                'description' => 'body',
                'author' => '',
                'category' => '',
                'comments' => '',
                'enclosure' => '',
                'guid' => 'nid',
                'pubDate' => 'changed',
            ),
        ),
        'dc' => array(
            'sas_views_rss_dc' => array(
                'title' => '',
                'creator' => '',
                'subject' => '',
                'description' => '',
                'publisher' => '',
                'contributor' => '',
                'date' => 'field_date',
                'type' => 'nothing',
                'format' => '',
                'identifier' => '',
                'source' => '',
                'language' => '',
                'relation' => '',
                'coverage' => 'field_location',
                'rights' => '',
            ),
        ),
    );
    $handler->display->display_options['style_options']['feed_settings'] = array(
        'absolute_paths' => 1,
        'feed_in_links' => 0,
    );
    $handler->display->display_options['path'] = 'sas-event-feed';

    // add the view to the array of views
    $views[$view->name] = $view;

    // At the end, return array of default views.
    return $views;
}

