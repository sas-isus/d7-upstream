<?php
/**
 * @file
 * Easy Social admin settings.
 */

/**
 * Form callback.
 * Main settings form.
 *
 * @see easy_social_menu()
 */
function easy_social_admin_config_main() {
  $form = array();

  // Global Settings.
  $form['global_settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Global Settings'),
    '#description' => t('Global settings for all widgets'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );

  $form['global_settings']['easy_social_global_type'] = array(
    '#type' => 'radios',
    '#title' => t('Type of buttons'),
    '#options' => array(
      EASY_SOCIAL_WIDGET_HORIZONTAL => t('Horizontal'),
      EASY_SOCIAL_WIDGET_VERTICAL => t('Vertical')
    ),
    '#default_value' => variable_get_value('easy_social_global_type'),
  );

  $options = _easy_social_get_options();

  $form['global_settings']['easy_social_global_widgets'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Social Widgets'),
    '#options' => $options,
    '#default_value' => variable_get_value('easy_social_global_widgets'),
  );

  // Block settings.
  $form['block_settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Block Settings'),
    '#description' => t('Custom settings for Blocks'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  $num_blocks = variable_get_value('easy_social_block_count');

  $form['block_settings']['easy_social_block_count'] = array(
    '#type' => 'select',
    '#title' => t('Number of Easy Social blocks'),
    '#description' => t('You can create up to !num Easy Social blocks. Please save and refresh the page to see the settings for each additional block.', array('!num' => EASY_SOCIAL_BLOCK_MAX)),
    '#options' => range(0, EASY_SOCIAL_BLOCK_MAX),
    '#default_value' => $num_blocks,
  );

  for ($i = 1; $i <= $num_blocks; ++$i) {
    $form['block_settings']["easy_social_block_{$i}"] = array(
      '#type' => 'fieldset',
      '#title' => t('Custom Settings for Block #!num', array('!num' => $i)),
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
    );

    $form['block_settings']["easy_social_block_{$i}"]["easy_social_block_{$i}_title"] = array(
      '#type' => 'textfield',
      '#title' => t('Block title'),
      '#description' => t("Leave this blank if you don't want this block to have a title."),
      '#maxlength' => 255,
      '#default_value' => variable_get_value("easy_social_block_{$i}_title"),
    );

    $form['block_settings']["easy_social_block_{$i}"]["easy_social_block_{$i}_override"] = array(
      '#type' => 'checkbox',
      '#title' => t('Override settings for this block'),
      '#description' => t('Check this option to override the global settings for this block'),
      '#default_value' => variable_get_value("easy_social_block_{$i}_override"),
    );

    $form['block_settings']["easy_social_block_{$i}"]['override'] = array(
      '#type' => 'container',
      '#states' => array(
        'invisible' => array(
          "input[name=\"easy_social_block_{$i}_override\"]" => array('checked' =>FALSE),
        ),
      ),
    );

    $form['block_settings']["easy_social_block_{$i}"]['override']["easy_social_block_{$i}_type"] = array(
      '#type' => 'radios',
      '#title' => t('Widget Type'),
      '#options' => array(
        EASY_SOCIAL_WIDGET_HORIZONTAL => t('Horizontal'),
        EASY_SOCIAL_WIDGET_VERTICAL => t('Vertical')
      ),
      '#default_value' => _easy_social_variable_get_value("easy_social_block_{$i}_type")
    );

    $form['block_settings']["easy_social_block_{$i}"]['override']["easy_social_block_{$i}_widgets"] = array(
      '#type' => 'checkboxes',
      '#title' => t('Enabled Widgets'),
      '#options' => $options,
      '#default_value' => _easy_social_variable_get_value("easy_social_block_{$i}_widgets"),
    );
 
    $form['block_settings']["easy_social_block_{$i}"]['override']['urls'] = array(
      '#type' => 'fieldset',
      '#title' => t('Custom URLs for this block'),
      '#collapsible' => TRUE,
      '#collapsed' => FALSE,
    );
 
    $widgets_block = _easy_social_variable_get_value("easy_social_block_{$i}_widgets");
 
    //Not using variable_get_value because of a problem in accessing all the widgets available 
    //with easy_social_get_widgets in the implementation of hook_variable_info
    foreach ($widgets_block as $widget_block) {
      if((bool)$widget_block !== FALSE){
        $form['block_settings']["easy_social_block_{$i}"]['override']['urls']["easy_social_block_{$i}_url_{$widget_block}"] = array(
          '#type' => 'textfield',
          '#title' => t('Custom URL for widget !widget', array('!widget' => $widget_block)),
          '#description' => t("Leave this blank or [current-path] for the current path, [base-url] for the base url, or place an internal drupal path, or even a full external URL e.g. http://external.com/myurl"),
          '#maxlength' => 255,
          '#default_value' => variable_get("easy_social_block_{$i}_url_{$widget_block}", "[current-path]"),
        );
      }
    }
  }

  return system_settings_form($form);
}

/**
 * Form callback.
 * Ignore-paths settings form.
 *
 * @see easy_social_menu()
 */
function easy_social_admin_config_ignore_paths() {
  $form = array();

  $form['easy_social_ignore_paths'] = array(
    '#type' => 'textarea',
    '#title' => t('Ignore paths'),
    '#description' => t('Any URL placed here will not have any Easy Social widgets. Use <front> for the front page'),
    '#default_value' => variable_get_value('easy_social_ignore_paths'),
  );

  return system_settings_form($form);
}

/**
 * Form callback.
 * Home tab for extra settings pages.
 *
 * @see easy_social_menu()
 */
function easy_social_admin_config_extra() {
  $form = array();

  $form['easy_social_extra'] = array(
    '#markup' => '<h4>' . t('Use the secondary tabs on the right to access extra settings for certain widgets') . '</h4>',
  );

  return $form;
}

/**
 * Form callback.
 * Extra settings for Twitter Widget.
 *
 * @see easy_social_menu()
 */
function easy_social_admin_config_extra_twitter() {
  $form = array();

  $form['easy_social_twitter_title'] = array(
    '#markup' => '<h4>' . t('Twitter widget settings') . '</h4>',
  );

  $form['easy_social_twitter_info'] = array(
    '#markup' => t('For more information check out the official Twitter widget <a href="!link" target="_blank">documentation</a>.', array('!link' => 'https://twitter.com/about/resources/tweetbutton')),
  );

  $form['easy_social_twitter_account_via'] = array(
    '#type' => 'textfield',
    '#title' => t('Mention account'),
    '#description' => t('Type the account name without the @'),
    '#size' => 40,
    '#maxlength' => 255,
    '#default_value' => variable_get_value('easy_social_twitter_account_via'),
  );

  $form['easy_social_twitter_account_related'] = array(
    '#type' => 'textfield',
    '#title' => t('Related account'),
    '#description' => t('Type the account name without the @'),
    '#size' => 40,
    '#maxlength' => 255,
    '#default_value' => variable_get_value('easy_social_twitter_account_related'),
  );

  $form['easy_social_twitter_account_description'] = array(
    '#type' => 'textfield',
    '#title' => t('Related account description'),
    '#size' => 120,
    '#maxlength' => 120,
    '#default_value' => variable_get_value('easy_social_twitter_account_description'),
  );

  $form['easy_social_twitter_count_show'] = array(
    '#type' => 'checkbox',
    '#title' => t('Display the count bubble'),
    '#default_value' => variable_get_value('easy_social_twitter_count_show'),
  );

  return system_settings_form($form);
}

/**
 * Form callback.
 * Extra settings for Facebook Widget.
 *
 * @see easy_social_menu()
 */
function easy_social_admin_config_extra_facebook() {
  $form = array();

  $form['easy_social_facebook_title'] = array(
    '#markup' => '<h4>' . t('Facebook widget settings') . '</h4>',
  );

  $form['easy_social_facebook_info'] = array(
    '#markup' => t('For more information check out the official Facebook widget <a href="!link" target="_blank">documentation</a>.', array('!link' => 'http://developers.facebook.com/docs/reference/plugins/like/')),
  );

  $form['easy_social_facebook_info_count'] = array(
    '#markup' => '<p>' . t('To hide the count: the Facebook API does not provide an option to hide the count bubble - the best workaround is to reduce the Horizontal Widget Width below (using Like verb: 50px) but this only works in horizontal display mode.') . '</p>',
  );

  $form['easy_social_facebook_appid'] = array(
    '#type' => 'textfield',
    '#title' => t('Facebook Application ID'),
    '#description' => t("Insert your Application ID if you want to integrate the widget with an existing Facebook application. Leave it blank if you don't know what this means."),
    '#default_value' => variable_get_value('easy_social_facebook_appid'),
    '#size' => 30,
  );

  $form['easy_social_facebook_widget_type'] = array(
    '#type' => 'select',
    '#title' => t('Facebook widget type'),
    '#options' => array(
      'html5' => 'HTML5',
      'xfbml' => 'XFBML',
      'iframe' => 'IFRAME',
    ),
    '#default_value' => variable_get_value('easy_social_facebook_widget_type'),
  );

  $form['easy_social_facebook_send_button'] = array(
    '#type' => 'checkbox',
    '#title' => t('Send Button (XFBML Only)'),
    '#description' => t('Include a Send Button. The Send Button is available only on sites that use the Javascript SDK.'),
    '#default_value' => variable_get_value('easy_social_facebook_send_button'),
  );

  $form['easy_social_facebook_width_vertical'] = array(
    '#type' => 'textfield',
    '#title' => t('Vertical Widget Width'),
    '#description' => t('The width of the plugin, in pixels.'),
    '#default_value' => variable_get_value('easy_social_facebook_width_vertical'),
    '#size' => 30,
  );

  $form['easy_social_facebook_width_horizontal'] = array(
    '#type' => 'textfield',
    '#title' => t('Horizontal Widget Width'),
    '#description' => t('The width of the plugin, in pixels.'),
    '#default_value' => variable_get_value('easy_social_facebook_width_horizontal'),
    '#size' => 30,
  );

  $form['easy_social_facebook_show_faces'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show faces'),
    '#description' => t('Show profile pictures below the button.'),
    '#default_value' => variable_get_value('easy_social_facebook_show_faces'),
  );

  $form['easy_social_facebook_verb'] = array(
    '#type' => 'select',
    '#title' => t('Verb to display'),
    '#description' => t("The verb to display in the button. Currently only 'like' and 'recommend' are supported."),
    '#options' => array(
      'like' => 'Like',
      'recommend' => 'Recommend',
    ),
    '#default_value' => variable_get_value('easy_social_facebook_verb'),
  );

  $form['easy_social_facebook_color_scheme'] = array(
    '#type' => 'select',
    '#title' => t('Color Scheme'),
    '#description' => t('The color scheme of the plugin.'),
    '#options' => array(
      'light' => 'light',
      'dark' => 'dark',
    ),
    '#default_value' => variable_get_value('easy_social_facebook_color_scheme'),
  );

  $form['easy_social_facebook_font'] = array(
    '#type' => 'select',
    '#title' => t('Font'),
    '#description' => t('The font of the plugin.'),
    '#options' => array(
      'default' => 'default',
      'arial' => 'arial',
      'lucida grande' => 'lucida grande',
      'segoe ui' => 'segoe ui',
      'tahoma' => 'tahoma',
      'trebuchet ms' => 'trebuchet ms',
      'verdana' => 'verdana',
    ),
    '#default_value' => variable_get_value('easy_social_facebook_font'),
  );

  return system_settings_form($form);
}

/**
 * Validation callback.
 * Validates extra Facebook settings.
 *
 * @see easy_social_admin_config_extra_facebook().
 */
function easy_social_admin_config_extra_facebook_validate(&$form, &$form_state) {
  if (!is_numeric($form_state['values']['easy_social_facebook_width_vertical'])) {
    form_set_error('easy_social_facebook_width_vertical', t('Vertical Widget Width must be numeric'));
  }
  else if (!is_numeric($form_state['values']['easy_social_facebook_width_horizontal'])) {
    form_set_error('easy_social_facebook_width_horizontal', t('Horizontal Widget Width must be numeric'));
  }
}

/**
 * Form callback.
 * Extra settings for Google+ Widget.
 *
 * @see easy_social_menu()
 */
function easy_social_admin_config_extra_googleplus() {
  $form = array();

  $form['easy_social_googleplus_title'] = array(
    '#markup' => '<h4>' . t('Google+ widget settings') . '</h4>',
  );

  $form['easy_social_googleplus_info'] = array(
    '#markup' => t('For more information check out the official Google+ widget <a href="!link" target="_blank">documentation</a>.', array('!link' => 'http://www.google.com/intl/en/webmasters/+1/button/index.html')),
  );

  $form['easy_social_googleplus_info_count'] = array(
    '#markup' => '<p>' . t('To hide the count: set Annotation to None.') . '</p>',
  );

  $form['easy_social_googleplus_annotation'] = array(
    '#type' => 'select',
    '#title' => t('Annotation'),
    '#description' => t('How the count will appear'),
    '#options' => array(
      'bubble' => 'bubble',
      'inline' => 'inline',
      'none' => 'none',
    ),
    '#default_value' => variable_get_value('easy_social_googleplus_annotation'),
  );

  $form['easy_social_googleplus_html5'] = array(
    '#type' => 'checkbox',
    '#title' => t('HTML5 valid syntax'),
    '#description' => t('Whether the widget should be output in HTML5 valid syntax or not'),
    '#default_value' => variable_get_value('easy_social_googleplus_html5'),
  );

  return system_settings_form($form);
}

/**
 * Form callback.
 * Extra settings for LinkedIn Widget.
 *
 * @see easy_social_menu()
 */
function easy_social_admin_config_extra_linkedin() {
  $form = array();
  $form['easy_social_linkedin_title'] = array(
    '#markup' => '<h4>' . t('LinkedIn widget settings') . '</h4>',
  );
  $form['easy_social_linkedin_info'] = array(
    '#markup' => t('For more information check out the official LinkedIn widget <a href="!link" target="_blank">documentation</a>.', array('!link' => 'https://developer.linkedin.com/share-plugin')),
  );
  $form['easy_social_linkedin_count_show'] = array(
    '#type' => 'checkbox',
    '#title' => t('Display the count bubble'),
    '#default_value' => variable_get_value('easy_social_linkedin_count_show'),
  );
  return system_settings_form($form);
}

/**
 * Form callback.
 * Displays Easy Social Summary.
 *
 * @see easy_social_menu()
 */
function easy_social_admin_summary() {
  $form = array();

  // Global settings.
  $form['global_settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Global Settings'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );

  $table = '<table>';
  $type = (variable_get_value('easy_social_global_type') == EASY_SOCIAL_WIDGET_HORIZONTAL) ? t('Horizontal') : t('Vertical');
  $table .= '<tr><td style="width:33%;">' . t('Global Widget Type') . '</td><td style="width:33%;">' . $type . '</td><td style="width:33%;text-align:left;">' . l(t('Configure'), 'admin/config/content/easy_social', array('attributes' => array('class' => 'module-link module-link-configure'))) . '</td></tr>';
  $widgets = variable_get_value('easy_social_global_widgets');
  $widget_info = easy_social_get_widgets();
  $widget_list = array();

  foreach ($widgets as $widget) {
    if ((bool)$widget !== FALSE) {
      $widget_list[] = $widget_info[$widget]['name'];
    }
  }

  $widget_list = theme('item_list', array('items' => $widget_list, 'type' => 'ol'));
  $table .= '<tr><td style="width:33%;">' . t('Global Widgets') . '</td><td style="width:33%;">' . $widget_list . '</td><td style="width:33%;text-align:left;">' . l(t('Configure'), 'admin/config/content/easy_social', array('attributes' => array('class' => 'module-link module-link-configure'))) . '</td></tr>';
  $ignore = check_plain(variable_get_value('easy_social_ignore_paths'));
  $table .= '<tr><td style="width:33%;">' . t('Ignore Paths') . '</td><td style="width:33%;">' . $ignore . '</td><td style="width:33%;text-align:left;">' . l(t('Configure'), 'admin/config/content/easy_social/ignore-paths', array('attributes' => array('class' => 'module-link module-link-configure'))) . '</td></tr>';
  $table .= '</table>';

  $form['global_settings']['summary'] = array('#markup' => $table);

  // Content Type settings.
  $form['content_settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Content Type Settings'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  $table = '<table>';
  $node_types = node_type_get_types();
  foreach ($node_types as $type => $typeobj) {
    $enabled = variable_get_value("easy_social_{$type}_enable");
    $enabled_string = ($enabled == 1) ? '<strong>' . t('Enabled') . '</strong>' : t('Disabled');
    $table .= '<tr><td style="width:33%;">' . $typeobj->name . '</td><td style="width:33%;">' . $enabled_string . '</td><td style="width:33%;text-align:left;">' . l(t('Configure'), 'admin/structure/types/manage/' . $type, array('attributes' => array('class' => 'module-link module-link-configure'))) . '</td></tr>';

    if ($enabled == 1) {
      $count = variable_get_value("easy_social_{$type}_count");
      $table .= '<tr><td style="width:33%;"> -- ' . t('Number of fields') . '</td><td style="width:33%;">' . $count . '</td><td style="width:33%;"></td></tr>';
      $type = (_easy_social_variable_get_value("easy_social_{$type}_type") == EASY_SOCIAL_WIDGET_HORIZONTAL) ? t('Horizontal') : t('Vertical');
      $table .= '<tr><td style="width:33%;"> -- ' . t('Widget Type') . '</td><td style="width:33%;">' . $type . '</td><td style="width:33%;"></td></tr>';
      $widgets = _easy_social_variable_get_value("easy_social_{$type}_widgets");
      $widget_list = array();

      foreach ($widgets as $widget) {
        if ((bool)$widget !== FALSE) {
          $widget_list[] = $widget_info[$widget]['name'];
        }
      }

      $widget_list = theme('item_list', array('items' => $widget_list, 'type' => 'ol'));
      $table .= '<tr><td style="width:33%;"> -- ' . t('Widgets') . '</td><td style="width:33%;">' . $widget_list . '</td><td style="width:33%;"></td></tr>';
    }
  }
  $table .= '</table>';

  $form['content_settings']['summary'] = array('#markup' => $table);

  // Block settings.
  $form['block_settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Block Settings'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  $table = '<table>';
  $count = variable_get_value('easy_social_block_count');
  $table .= '<tr><td style="width:33%;">' . t('Number of Blocks') . '</td><td style="width:33%;">' . $count . '</td><td style="width:33%;text-align:left;">' . l(t('Configure'), 'admin/config/content/easy_social', array('attributes' => array('class' => 'module-link module-link-configure'))) . '</td></tr>';
  $table .= '</table>';

  if ($count > 0) {
    for ($i = 1; $i <= $count; ++$i) {
      $table .= '<table>';
      $table .= '<tr><td colspan="2"><strong>' . t('Block') . ' #' . $i . '</strong></td></tr>';
      $title = filter_xss((variable_get_value("easy_social_block_{$i}_title"))); 

      if (empty($title)) {
        $title = check_plain('<empty>');
      }

      $override = variable_get_value("easy_social_block_{$i}_override");
      $override_string = ($override == 1) ? t('Yes') : t('No');

      $table .= '<tr><td style="width:33%;">' . t('Title') . '</td><td style="width:33%;">' . $title . '</td></tr>';
      $table .= '<tr><td style="width:33%;">' . t('Override Settings') . '</td><td style="width:33%;">' . $override_string . '</td></tr>';

      if ($override == 1) {
        $type = (variable_get_value("easy_social_block_{$i}_type") == EASY_SOCIAL_WIDGET_HORIZONTAL) ? t('Horizontal') : t('Vertical');
        $widgets = variable_get_value("easy_social_block_{$i}_widgets");
        $widget_list = array();

        foreach ($widgets as $widget) {
          $widget_list[] = $widget_info[$widget]['name'];
        }

        $widget_list = theme('item_list', array('items' => $widget_list, 'type' => 'ol'));
        $table .= '<tr><td style="width:33%;">' . t('Widgets') . '</td><td style="width:33%;">' . $widget_list . '</td></tr>';
      }
      $table .= '</table>';
    }
  }

  $table .= '</table>';

  $form['block_settings']['summary'] = array('#markup' => $table);

  return $form;
}

/**
 * Form callback.
 * Displays Easy Social widget sorting form.
 *
 * @see easy_social_menu()
 */
function easy_social_admin_order() {
  $widgets = variable_get_value('easy_social_global_order');
  $options = _easy_social_get_options();

  $data = array();
  $i = 0;

  foreach ($widgets as $widget) {
    $data[] = array(
      'id' => $widget,
      'title' => $options[$widget],
      'weight' => $i++,
    );
  }

  $form['widgets'] = array('#tree' => TRUE);
  $count = count($data);

  foreach ($data as $item) {
    $form['widgets'][$item['id']] = array(
      '#widget' => $item['title'],
      'weight' => array(
        '#type' => 'weight',
        '#delta' => $count,
        '#default_value' => isset($item['weight']) ? $item['weight'] : 0,
        '#attributes' => array('class' => array('weight_group')),
      ),
      'id' => array(
        '#type' => 'hidden',
        '#value' => $item['id'],
      ),
    );
  }

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Submit'),
  );

  return $form;
}

/**
 * Submit callback.
 * Sorts Easy Social widgets.
 *
 * @see easy_social_admin_order()
 */
function easy_social_admin_order_submit($form, &$form_state) {
  $order = array();

  foreach ($form_state['values']['widgets'] as $name => $value) {
    $order[$value['weight']] = $name;
  }

  ksort($order);
  $order = array_values($order);
  variable_set('easy_social_global_order', $order);
}

/**
 * Theme callback.
 * Implements draggable table in Easy Social sort form.
 *
 * @see easy_social_admin_order()
 * @see easy_social_theme()
 */
function theme_easy_social_admin_order($variables) {
  $output = '';
  $form = $variables['form'];
  $header = array('Title', 'Weight');
  $table_id = 'easy_social_widget_order';

  foreach (element_children($form['widgets']) as $id) {
    $data = array();
    $data[] = $form['widgets'][$id]['#widget'];
    $data[] = drupal_render($form['widgets'][$id]['weight']);
    $rows[] = array('data' => $data, 'class' => array('draggable'));
  }

  drupal_add_tabledrag($table_id, 'order', 'sibling', 'weight_group');

  $output .= theme('table', array(
    'header' => $header,
    'rows' => $rows,
    'attributes' => array('id' => $table_id),
  ));

  $output .= drupal_render_children($form);
  return $output;
}

/**
 * Form callback.
 * Wizard for quickly adding Easy Social to Content Types.
 *
 * @see easy_social_menu()
 */
function easy_social_admin_wizard() {
  $form = array();
  $node_types = node_type_get_types();

  $form['easy_social_types'] = array(
    '#type' => 'fieldset',
    '#title' => t('Content Types'),
    '#collapsible' => FALSE,
    '#description' => t('Enable Easy Social for the following content types:'),
    '#tree' => TRUE,
  );

  foreach ($node_types as $type => $typeobj) {
    $form['easy_social_types']["easy_social_{$type}_enable"] = array(
      '#title' => $typeobj->name,
      '#type' => 'checkbox',
      '#default_value' => variable_get_value("easy_social_{$type}_enable"),
    );
  }

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Submit'),
  );

  return $form;
}

/**
 * Submit callback.
 * Handles wizard settings.
 *
 * @see easy_social_admin_wizard()
 */
function easy_social_admin_wizard_submit($form, &$form_state) {
  foreach ($form_state['values']['easy_social_types'] as $name => $value) {
    variable_set($name, $value);
  }
}
