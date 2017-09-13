<?php
/**
 * @file
 * penn403.admin.inc
 *
 * Form functions for the administration pages for the Penn403 module
 */

/**
 * function penncourse_admin_settings()
 *
 * build penncourse administrative settings form
 */
function penn403_admin_settings() {
  $form['penn403_auto_redirect'] = array(
    '#type' => 'radios',
    '#title' => t('Auto redirect'),
    '#options' => array(
      'yes' => t('Yes'),
      'no' => t('No'),
    ),
    '#default_value' => variable_get('penn403_auto_redirect', 'yes'),
    '#description' => t('By default, then Penn 403 module will automatically redirect anonymous users to PennKey login if they encounter a 403 access denied error. This behavior may not be desired in a site that supports mixed authentication. If this option is set to No, the user will be presented with a theme-able 403 error page that includes a link to PennKey authentication.'),
  );

  return system_settings_form($form);
}
