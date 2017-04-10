<?php
/**
 * @file
 * Admin form to add custom meta tags
 * custom_meta_form. Hans.Gutknecht@mlssoccer.com
 *
 */

/**
 * custom_meta_form
 * Creates admin form.
 *
 * @return Form for administering module.
 */
function custom_meta_form() {
  $form = array();
  $form['description'] = array(
    '#prefix' => '<div>',
    '#markup' => 'The Custom Meta module provides an interface for adding meta tags. This will add the created meta tags to the html head of all non-admin pages. Be careful with the http-equiv meta attribute, these are added to <strong>ALL PAGES</strong>, so you could very easily break your site with redirects, expires, etc.<br /><br />Formatting for tags <em>&lt;meta [Meta Attribute]="[Attribute Value]" content="[Content value]"&gt;</em>',
    '#suffix' => '</div>',
  );
  $form['custom_meta_attribute'] = array(
      '#title' => t('Meta attribute'),
      '#type' => 'select',
      '#default_value' => variable_get('custom_meta_attribute', 'property'),
      '#options' => array('property' => 'property', 'name' => 'name', 'http-equiv' => 'http-equiv')
  );
  $form['custom_meta_attribute_value'] = array(
      '#title' => t('Attribute value'),
      '#type' => 'textfield',
      '#description' => t('Value for the attribute defined above'),
      '#default_value' => variable_get('custom_meta_attribute_value', '')
  );
  $form['custom_meta_content_value'] = array(
      '#title' => t('Content value'),
      '#type' => 'textfield',
      '#description' => t('Value for the meta content defined above'),
      '#default_value' => variable_get('custom_meta_content_value', '')
  );

  $form['submit'] = array(
   '#type' => 'submit',
   '#value' => t('Add tag'),
  );

  $form['custom_meta_tags'] = array(
    '#type' => 'fieldset',
    '#title' => t('List of tags'),
  );

  $meta_tags = custom_meta_get_tags();
  if ($meta_tags) {
    foreach ($meta_tags as $key => $meta_tag) {
      $form['custom_meta_tags']['meta_tag_' . $key] = array(
        '#prefix' => '<div>',
        '#markup' => '&lt;meta ' . check_plain($meta_tag['meta_attr']) . '="' . check_plain($meta_tag['meta_attr_value']) . '" content="' . check_plain($meta_tag['meta_content']) . '"&gt; <div class="actions"><a href="/admin/config/search/custom_meta/edit/' . check_plain($meta_tag['meta_uid']) . '">Edit</a> | <a href="/admin/config/search/custom_meta/remove/' . check_plain($meta_tag['meta_uid']) . '">Remove</a>',
        '#suffix' => '</div>',
      );
    }
  }

  return $form;
}

/**
 * custom_meta_edit_form
 * Creates editing form for tags.
 *
 * @return Form for editing tags.
 */
function custom_meta_edit_form() {
  $form = array();
  $id = arg(5);
  $tag = custom_meta_get_tags($id);
  $form['custom_meta_attribute'] = array(
    '#title' => t('Meta attribute'),
    '#type' => 'select',
    '#description' => t('Either property, name or http-equiv'),
    '#default_value' => $tag['meta_attr'],
    '#options' => array('property' => 'property', 'name' => 'name', 'http-equiv' => 'http-equiv')
  );
  $form['custom_meta_attribute_value'] = array(
    '#title' => t('Meta attribute value'),
    '#type' => 'textfield',
    '#description' => t('Value for the meta attribute defined above'),
    '#default_value' => $tag['meta_attr_value']
  );
  $form['custom_meta_content_value'] = array(
    '#title' => t('Meta content value'),
    '#type' => 'textfield',
    '#description' => t('Value for the meta content defined above'),
    '#default_value' => $tag['meta_content']
  );

  $form['submit'] = array(
   '#type' => 'submit',
   '#value' => t('Save tag'),
  );

  $form['cancel'] = array(
   '#markup' => '<a href="/admin/config/search/custom_meta">' . t('Cancel') . '</a>',
  );

  return $form;
}

/**
 * custom_meta_form_validate
 * Form validation for custom_meta_form.
 *
 * @param $form: custom_meta_form.
 * @param &$form_state: Reference to state of custom_meta_form.
 */
function custom_meta_form_validate($form, &$form_state) {
  $atvalue = $form_state['values']['custom_meta_attribute_value'];
  $metacontent = $form_state['values']['custom_meta_content_value'];
  if (empty($atvalue)) {
    form_set_error('custom_meta_attribute_value', t('Must provide a value for meta attribute'));
  }
  if (empty($metacontent)) {
    form_set_error('custom_meta_content_value', t('Must provide a value for content'));
  }
}

/**
 * custom_meta_form_submit
 * Form submission for custom_meta_form.
 *
 * @param $form: custom_meta_form.
 * @param &$form_state: Reference to state of custom_meta_form.
 */
function custom_meta_form_submit(&$form, &$form_state) {
  drupal_set_message(t('All your tag belong to us. Tag saved.'));

  custom_meta_set_tag($form_state['values']['custom_meta_attribute'], $form_state['values']['custom_meta_attribute_value'], $form_state['values']['custom_meta_content_value']);
}

/**
 * custom_meta_edit_form_submit
 * Form submission for custom_meta_edit_form.
 *
 * @param $form: custom_meta_edit_form.
 * @param &$form_state: Reference to state of custom_meta_edit_form.
 */
function custom_meta_edit_form_submit(&$form, &$form_state) {
  db_update('custom_meta')
    ->fields(array(
      'meta_attr' => $form_state['input']['custom_meta_attribute'],
      'meta_attr_value' => $form_state['input']['custom_meta_attribute_value'],
      'meta_content' => $form_state['input']['custom_meta_content_value']
    ))
    -> condition('meta_uid', arg(5))
    ->execute();

  drupal_set_message(t('Tag saved.'));
  drupal_goto('admin/config/search/custom_meta');
}
