<?php

function africana_menu_link(array $variables) {
  $element = $variables['element'];
  $sub_menu = '';
  
  if ($element['#below']) {

    // Prevent dropdown functions from being added to management menu as to not affect navbar module.
    if (($element['#original_link']['menu_name'] == 'management') && (module_exists('navbar'))) {
      $sub_menu = drupal_render($element['#below']);
    }

    else {
      // Add our own wrapper
      unset($element['#below']['#theme_wrappers']);
      $sub_menu = '<ul>' . drupal_render($element['#below']) . '</ul>';
      
      // Uncomment to revert to standard bootstrap dropdown behavior (no hover)
      // $element['#localized_options']['attributes']['class'][] = 'dropdown-toggle';
      // $element['#localized_options']['attributes']['data-toggle'] = 'dropdown';

      // Check if this element is nested within another
      if ((!empty($element['#original_link']['depth'])) && ($element['#original_link']['depth'] > 1)) {
        // Generate as dropdown submenu

        // Uncommented to eliminate dropdown behavior
        // $element['#attributes']['class'][] = 'dropdown-submenu';
      }
      else {
        // Generate as standard dropdown

        // Uncommented to eliminate dropdown behavior
        // $element['#attributes']['class'][] = 'dropdown';
        // $element['#localized_options']['html'] = TRUE;
        // $element['#title'] .= ' <span class="caret"></span>';
      }

      // Set dropdown trigger element to # to prevent inadvertant page loading with submenu click
      $element['#localized_options']['attributes']['data-target'] = '#';
    }
  }
 // Issue #1896674 - On primary navigation menu, class 'active' is not set on active menu item.
 // @see http://drupal.org/node/1896674
 if (($element['#href'] == $_GET['q'] || ($element['#href'] == '<front>' && drupal_is_front_page())) && (empty($element['#localized_options']['language']) || $element['#localized_options']['language']->language == $language_url->language)) {
   $element['#attributes']['class'][] = 'active';
 }
  $output = l($element['#title'], $element['#href'], $element['#localized_options']);
  return '<li' . drupal_attributes($element['#attributes']) . '>' . $output . $sub_menu . "</li>\n";
}

/** This replicates a patch (https://www.drupal.org/node/2294973) to Date module 7.x-2.8 and corrects the Calendar title view **/

function africana_date_nav_title($params) {
  $granularity = $params['granularity'];
  $view = $params['view'];
  $date_info = $view->date_info;
  $link = !empty($params['link']) ? $params['link'] : FALSE;
  $format = !empty($params['format']) ? $params['format'] : NULL;
  $format_with_year = variable_get('date_views_' . $granularity . '_format_with_year', 'l, F j, Y');
  $format_without_year = variable_get('date_views_' . $granularity . '_format_without_year', 'l, F j');
  switch ($granularity) {
    case 'year':
      $title = $date_info->year;
      $date_arg = $date_info->year;
      break;
    case 'month':
      $format = !empty($format) ? $format : (empty($date_info->mini) ? $format_with_year : $format_without_year);
      $title = date_format_date($date_info->min_date, 'custom', $format);
      $date_arg = $date_info->year . '-' . date_pad($date_info->month);
      break;
    case 'day':
      $format = !empty($format) ? $format : (empty($date_info->mini) ? $format_with_year : $format_without_year);
      $title = date_format_date($date_info->min_date, 'custom', $format);
      $date_arg = $date_info->year . '-' . date_pad($date_info->month) . '-' . date_pad($date_info->day);
      break;
    case 'week':
      $format = !empty($format) ? $format : (empty($date_info->mini) ? $format_with_year : $format_without_year);
      $title = t('Week of @date', array('@date' => date_format_date($date_info->min_date, 'custom', $format)));
      $date_arg = $date_info->year . '-W' . date_pad($date_info->week);
      break;
  }
  if (!empty($date_info->mini) || $link) {
    // Month navigation titles are used as links in the mini view.
    $attributes = array('title' => t('View full page month'));
    $url = date_pager_url($view, $granularity, $date_arg, TRUE);
    return l($title, $url, array('attributes' => $attributes));
  }
  else {
    return $title;
  }
}

/**
 * Implementation of hook_preprocess_page().
 */
function africana_preprocess_page(&$variables){
  // add templates for node pages, eg page--node-article.tpl.php
  if (!empty($variables['node'])) {
    $variables['theme_hook_suggestions'][] =  'page__node_'. $variables['node']->type;
  }

}

// Node teaser template suggestions
function africana_preprocess_node(&$vars) {
  if($vars['view_mode'] == 'teaser') {
    $vars['theme_hook_suggestions'][] = 'node__' . $vars['node']->type . '__teaser';
    $vars['theme_hook_suggestions'][] = 'node__' . $vars['node']->nid . '__teaser';
  }
}

/**
 * Implementation of hook_form_alter().
 */
function africana_form_alter(&$form, &$form_state, $form_id) {
  if ($form_id == 'search_form') {
    $form_default = t('SEARCH');
    $form['basic']['keys']['#default_value'] = $form_default;
    $form['basic']['keys']['#attributes'] = array(
                                                  'onblur' => "if (this.value == '') {this.value = '{$form_default}'; this.style.textAlign='center'; }", 
                                                  'onfocus' => "if (this.value == '{$form_default}') {this.value = ''; this.style.textAlign='left'; }" );
// HTML5 placeholder attribute
    $form['basic']['keys']['#placeholder'] = t('SEARCH');
  }
}

// allow for the dpm of entity_metadate_wrappers
function _wrapper_debug($w) {
  $values = array();
  foreach ($w->getPropertyInfo() as $key => $val) {
    $values[$key] = $w->$key->value();
  }
  return $values;
}

// Add only current page argument class to the <body>
function africana_preprocess_html(&$vars) {
  $path = drupal_get_path_alias();
  $aliases = explode('/', $path);
  $i = 0;
  $length = count($aliases);
  foreach($aliases as $alias) {
    if ($i == $length - 1 && $alias !== 'calendar') {
    $vars['classes_array'][] = drupal_clean_css_identifier($alias);
    }
    $i++;
  }
}


