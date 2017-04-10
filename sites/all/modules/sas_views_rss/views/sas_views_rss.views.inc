<?php

/**
 * @file
 * Views plugins, handlers and hooks definition for SAS Views RSS module.
 */

/**
 * Implements hook_views_style_plugins().
 * Adds view types to views UI interface.
 */
function sas_views_rss_views_plugins() {
  return array(
    'style' => array(
      'rss_fields' => array(
        'type' => 'feed',
        'title' => t('SAS RSS Feed - Fields'),
        'help' => t('Outputs a RSS formatted feed'),
        'handler' => 'sas_views_rss_plugin_style_fields',
        'path' => SAS_VIEWS_RSS_PATH . '/views',
        'theme' => 'views_view_sas_views_rss',
        'theme file' => 'theme.inc',
        'theme path' => SAS_VIEWS_RSS_PATH . '/theme',
        'uses row plugin' => FALSE,
        'uses fields' => TRUE,
        'uses options' => TRUE,
        'uses grouping' => FALSE,
      ),
    ),
  );
}

/**
 * Implements hook_views_handlers().
 */
function sas_views_rss_views_handlers() {
  return array(
    'info' => array(
      'path' => SAS_VIEWS_RSS_PATH . '/views',
    ),
    'handlers' => array(
      'sas_views_rss_handler_field_user_mail' => array(
        'parent' => 'views_handler_field_user_mail',
      ),
      'sas_views_rss_handler_field_term_node_tid' => array(
        'parent' => 'views_handler_field_term_node_tid',
      ),
    ),
  );
}

/**
 * Implements hook_views_data_alter().
 */
function sas_views_rss_views_data_alter(&$data) {
  $data['users']['mail']['field']['handler'] = 'sas_views_rss_handler_field_user_mail';
  $data['node']['term_node_tid']['field']['handler'] = 'sas_views_rss_handler_field_term_node_tid';
}
