<?php
/**
 * @file
 * Easy Social Views hooks.
 */

/**
 * Implements hook_views_data().
 */
function easy_social_views_data() {
  $data['node']['easy_social'] = array(
    'field' => array(
      'title' => t('Easy Social'),
      'help' => t('Display Easy Social share widgets.'),
      'handler' => 'easy_social_handler_field',
    ),
  );
  return $data;
}