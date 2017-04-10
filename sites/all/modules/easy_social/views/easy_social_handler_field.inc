<?php
/**
 * @file
 * Easy Social view handler.
 */

/**
 * Handler for displaying Easy Social share buttons in views.
 */
class easy_social_handler_field extends views_handler_field {
  function init(&$view, $options) {
      parent::init($view, $options);
      // Declare additional fields to be loaded with a single query.
      // This way there's no need to node_load() on render().
      $this->additional_fields['nid'] = 'nid';
      $this->additional_fields['type'] = 'type';
      $this->additional_fields['language'] = 'language';
      $this->additional_fields['title'] = 'title';
  }

  function query() {
    $this->ensure_my_table();
    $this->add_additional_fields();
  }

  /**
   * Render field.
   */
  function render($values) {
    // All $additional_fields are aliased by Views.
    // Dealias & create a partial Node object.
    $node = new stdClass;
    $node->nid = $values->{$this->aliases['nid']};
    $node->type = $values->{$this->aliases['type']};
    $node->language = $values->{$this->aliases['language']};
    $node->title = $values->{$this->aliases['title']};
    $url = url('node/'.$node->nid, array('absolute' => TRUE)); // absolute url

    // Check if Easy Social is enabled for this content type.
    if (variable_get_value("easy_social_{$node->type}_enable")) {
      $type = $this->options['easy_social_type'];
      $enabled_widgets = $this->options['easy_social_widgets'];
      $widgets = _easy_social_render_widgets($url, $node->title, $type, $enabled_widgets, $node->language);
      return theme('easy_social_links', array('widgets' => $widgets));
    }
  }

  /**
   * Define extra Easy Social field options.
   */
  function option_definition() {
    $options = parent::option_definition();
    $options['easy_social_type'] = array('default' => EASY_SOCIAL_WIDGET_HORIZONTAL);
    $options['easy_social_widgets'] = array('default' => variable_get_value('easy_social_global_widgets'));
    return $options;
  }

  /**
   * Extra Easy Social field options form.
   */
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    $form['easy_social'] = array(
      '#type' => 'fieldset',
      '#title' => t('Easy Social'),
      '#collapsible' => TRUE,
      '#collapsed' => FALSE,
      '#weight' => -1,
    );

    $form['easy_social']['easy_social_type'] = array(
      '#type' => 'radios',
      '#title' => t('Type of buttons'),
      '#options' => array(
        EASY_SOCIAL_WIDGET_HORIZONTAL => t('Horizontal'),
        EASY_SOCIAL_WIDGET_VERTICAL => t('Vertical')
      ),
      '#default_value' => $this->options['easy_social_type'],
    );

    $form['easy_social']['easy_social_widgets'] = array(
      '#type' => 'checkboxes',
      '#title' => t('Enabled Widgets'),
      '#options' => _easy_social_get_options(),
      '#default_value' => $this->options['easy_social_widgets'],
      '#description' => t('Some widgets may appear unformatted in the Views preview'),
    );
  }

  /**
   * Extra Easy Social options submit callback.
   */
  function options_submit(&$form, &$form_state) {
    parent::options_submit($form, $form_state);
    $form_state['values']['options']['easy_social_type'] = $form_state['values']['options']['easy_social']['easy_social_type'];
    $form_state['values']['options']['easy_social_widgets'] = $form_state['values']['options']['easy_social']['easy_social_widgets'];
    unset($form_state['values']['options']['easy_social']);
  }
}