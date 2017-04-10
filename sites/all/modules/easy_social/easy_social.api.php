<?php
/**
 * @file
 * Easy Social API documentation.
 *
 * The following is an overview of using the Easy Social API.
 *
 * For a better reading experience, try the handbook on Drupal.org:
 * http://drupal.org/node/1347326
 */

/**
 * Implements hook_easy_social_widget().
 *
 * This is how you define additional share widgets.
 */
function hook_easy_social_widget() {
  return array(
    'my_custom_share_button' => array(
      'name' => 'My Custom Share Button', // This apears on admin pages only.
      'markup' => '_mymodule_custom_share_button_markup', // Callback function that returns widget markup.
      'scripts' => array(
        array(
          'path' => 'http://mycustomshare.com/widget.js', // JavaScript include, if any.
          'type' => 'external', // Type of include: 'external', 'module' or 'inline', defaults to 'external'.
        ),
      ),
      'styles' => array(
        array(
          'path' => drupal_get_path('module', 'easy_social') . '/css/easy_social_twitter.css', // CSS include, if any.
          'type' => 'external', // Type of include: 'external', 'module' or 'inline', defaults to 'external'.
        ),
      ),
    ),
  );
}

/**
 * Widget markup callback.
 * This is where you return your widget's markup.
 *
 * @param string
 *   The URL to share.
 * @param int
 *   The widget type (horizontal or vertical). This maps to one of the defined
 *   constants: EASY_SOCIAL_WIDGET_HORIZONTAL or EASY_SOCIAL_WIDGET_VERTICAL.
 * @param string
 *   The title to share.
 * @param string
 *   The widget's language code. Not all widgets implement i18n so this can
 *   be ignored and fallback to a default language.
 * @return string
 *   A rendered html string.
 *
 * @see hook_easy_social_widget()
 */
function _mymodule_custom_share_button_markup($url, $type, $title = NULL, $lang = 'en') {
  return <<<HTML
This is my widget' markup, I can replace parameters with variables such as {$url} and {$title}.
HTML;
}