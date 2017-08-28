<?php
/**
 * @file
 * penncourse.admin.inc
 *
 * Form functions for the administration pages for the PennCourse module
 */

/**
 * function penncourse_admin_settings()
 *
 * build penncourse administrative settings form
 */
function penncourse_admin_settings() {
  /* $form['penncourse_subject_areas_select'] = array(
    '#type' => 'select',
    '#title' => t('Subject areas'),
    '#multiple' => TRUE,
    '#required' => TRUE,
    '#default_value' => variable_get('penncourse_subject_areas', ''),
    '#options' => penncourse_get_all_subject_areas(),
    '#description' => t('Select the subject areas from which you would like to display course data on your site.'),
  ); */

  $form['penncourse_subject_areas'] = array(
    '#type' => 'textfield',
    '#title' => t('Subject areas'),
    '#required' => TRUE,
    '#default_value' => variable_get('penncourse_subject_areas', ''),
    '#description' => t('Enter the subject areas from which you would like to display course data on your site. Use the alphanumeric subject code.<br> List multiple subject areas separated by a space (<em>eg,</em> "DTCH GRMN SCND YDSH").'),
  );

  $form['penncourse_authorization_bearer'] = array(
    '#type' => 'textfield',
    '#title' => t('Application ID'),
    '#required' => TRUE,
    '#default_value' => variable_get('penncourse_authorization_bearer', ''),
    '#description' => t('Enter the application ID for this service access account. ' . l('Request credentials here.', 'https://secure.www.upenn.edu/computing/da/webloginportal/eforms/index.html?content=kew/EDocLite?edlName=openDataRequestForm&userAction=initiate')),
  );

  $form['penncourse_authorization_token'] = array(
    '#type' => 'textfield',
    '#title' => t('Authorization token'),
    '#required' => TRUE,
    '#default_value' => variable_get('penncourse_authorization_token', ''),
    '#description' => t('Enter the authorization token for this service access account. ' . l('Request credentials here.', 'https://secure.www.upenn.edu/computing/da/webloginportal/eforms/index.html?content=kew/EDocLite?edlName=openDataRequestForm&userAction=initiate')),
  );

  return system_settings_form($form);
}

/**
 * function penncourse_get_all_subject_areas()
 *
 * Creates an array for populating the list of available subject areas
 */
function penncourse_get_all_subject_areas() {
  $options = array();
  $results = db_query('SELECT DISTINCT subject_area, subject_area_desc FROM {warehousesync.pc_subj_area_temp} ORDER BY subject_area_desc');
  while ($subject_area = db_fetch_object($results)) {
    $options[drupal_html_to_text(check_plain(trim($subject_area->subject_area)))] = drupal_html_to_text(check_plain(trim($subject_area->subject_area_desc)));
  }
  return $options;
}

/**
 * function penncourse_admin_settings_validate()
 *
 * validation function for the penncourse_admin_settings form
 */
function penncourse_admin_settings_validate($form, &$form_state) {
  $subject_areas = trim($form_state['values']['penncourse_subject_areas']);

  if (!preg_match('/^([a-zA-Z0-9]{3,4}\s)*[a-zA-Z]{3,4}$/', $subject_areas)) {
    form_set_error('penncourse_subject_areas', t('An incorrect format was entered. Enter the subject areas from which you would like to display course data on your site. Use the alphanumeric subject code.<br> List multiple subject areas separated by a space (<em>eg,</em> "DTCH GRMN SCND YDSH").'));
  }
}
