<?php
/**
 * @file
 * pennweblogin.admin.inc
 * 
 * PennWebLogin Module v. 7.x-1.x
 *
 * Administration forms and validation for the PennWebLogin module
 */


/**
 * function pennweblogin_admin_settings()
 * 
 * build pennweblogin administrative settings form
 */
function pennweblogin_admin_settings() {
  $form['pennweblogin_allow_non_pennkey'] = array(
    '#type' => 'checkbox',
    '#title' => t('Allow non-pennkey accounts'),
    '#default_value' => variable_get('pennweblogin_allow_non_pennkey', ''),
    '#options' => array(t('False'), t('Allow non-pennkey Accounts')),
    '#description' => t('If you would like to allow non-pennkey authentication on your site, check this box. The ' . l('cache must be cleared','admin/config/development/performance') . ' after changing this setting.'),
  );
  $options = user_roles();
  unset($options[1]);
  unset($options[2]);
  $form['pennweblogin_default_roles'] = array(
    '#title' => t('Default roles'),
    '#description' => t('PennKey users will be assigned these roles on their first authentication to the site. This setting affects new user accounts only.'),
    '#type' => 'checkboxes',
    '#options' => $options,
    '#default_value' => variable_get('pennweblogin_default_roles', array()),
    );
    
  ppm(variable_get('pennweblogin_default_roles', array()));
  
  return system_settings_form($form);
}

/**
 * function pennweblogin_admin_settings_validate()
 * 
 * validation function for the pennweblogin_admin_settings form
 */
function pennweblogin_admin_settings_validate($form, &$form_state) {
}

function pennweblogin_admin_settings_submit($form, &$form_state) {
  // ... and save the settings
  system_settings_form_submit($form, $form_state);
}
