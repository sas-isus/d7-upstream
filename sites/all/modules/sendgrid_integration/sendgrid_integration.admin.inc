<?php

/**
 * Provides Settings Form.
 */
function sendgrid_integration_admin() {
  $form = [];

  $form['authentication'] = [
    '#type' => 'fieldset',
    '#title' => t('Authentication'),
  ];

  $requirenewkey = TRUE;
  if (!empty(variable_get('sendgrid_integration_apikey', FALSE))) {
    $form['authentication']['secretkeynotice'] = [
      '#markup' => t('You have saved a secret key. You may change the key by inputing a new one in the field directly below.'),
    ];
    $requirenewkey = FALSE;
  }

  $form['authentication']['sendgrid_integration_apikey'] = [
    '#type' => 'password',
    '#required' => $requirenewkey,
    '#title' => t('API Secret Key'),
    '#description' => t('The secret key of your key pair. These are only generated once by Sendgrid. Your existing key is hidden. If you need to change this, provide a new key here.'),
  ];

  $form['debugging']['maillog'] = [
    '#type' => 'fieldset',
    '#title' => t('Maillog integration'),
  ];
  $form['actions'] = ['#type' => 'actions'];
  $form['actions']['submit'] = [
    '#type' => 'submit',
    '#value' => t('Save Settings'),
    '#submit' => ['sendgrid_integration_admin_submit'],
    '#validate' => [
      'sendgrid_integration_admin_validate',
    ],
  ];

  if (!module_exists('maillog')) {
    $form['debugging']['maillog']['#description'] = t('Installing the <a href="@url">Maillog module</a> also allows keeping copies of all emails sent through the site.', ['@url' => 'https://www.drupal.org/project/maillog']);
  }
  else {
    $form['debugging']['maillog']['#description'] = t('The <a href="@url">Maillog module</a> is installed, it can also be used to keep copies of all emails sent through the site.', ['@url' => url('admin/config/development/maillog')]);

    $form['debugging']['maillog']['sendgrid_integration_maillog_log'] = [
      '#type' => 'checkbox',
      '#title' => t('Create table entries in maillog table for each e-mail.'),
      '#default_value' => variable_get('sendgrid_integration_maillog_log', TRUE),
    ];

    $form['debugging']['maillog']['sendgrid_integration_maillog_devel'] = [
      '#type' => 'checkbox',
      '#title' => t("Display the e-mails on page using devel module (if enabled)."),
      '#default_value' => variable_get('sendgrid_integration_maillog_devel', TRUE),
      '#disabled' => !module_exists('devel'),
    ];
  }

  return $form;
}

/**
 * Validation function for admin settings.
 *
 * @param $form
 * @param $form_state
 */
function sendgrid_integration_admin_validate($form, &$form_state) {
  // Check for API secret key. If missing throw error.
  if (empty(variable_get('sendgrid_integration_apikey', '')) && empty($form_state['values']['sendgrid_integration_apikey'])) {
    form_set_error('authentication][sendgrid_integration_apikey', t('You have not stored an API Secret Key.'));
  }
}

/**
 * Submit handler for admin settings.
 *
 * We use a custom submit handler to only set variables if values are supplied
 * in the UI.
 *
 * @param $form
 * @param $form_state
 *
 * @return bool
 */
function sendgrid_integration_admin_submit($form, $form_state) {
  if (isset($form_state['values']['sendgrid_integration_maillog_log'])) {
    variable_set('sendgrid_integration_maillog_log', check_plain($form_state['values']['sendgrid_integration_maillog_log']));
  }
  if (isset($form_state['values']['sendgrid_integration_maillog_devel'])) {
    variable_set('sendgrid_integration_maillog_devel', check_plain($form_state['values']['sendgrid_integration_maillog_devel']));
  }
  $existingkey = variable_get('sendgrid_integration_apikey', '');
  if (empty($form_state['values']['sendgrid_integration_apikey']) && !empty($existingkey)) {
    return TRUE;
  }
  if (isset($form_state['values']['sendgrid_integration_apikey']) && !empty($form_state['values']['sendgrid_integration_apikey'])) {
    variable_set('sendgrid_integration_apikey', check_plain($form_state['values']['sendgrid_integration_apikey']));
    drupal_set_message(t('SendGrid Settings Saved'), 'status', FALSE);
    return TRUE;
  }

}


/**
 * Provides a form to send a test email through Sendgrid.
 */
function sendgrid_integration_test() {
  $form = [];

  $defaults = variable_get(
    'sendgrid_integration_test_defaults',
    [
      'to' => variable_get('site_mail', 'user@example.com'),
      'subject' => 'Test Email from SendGrid Module',
      'body' => [
        'value' => 'Test Message for SendGrid.',
      ],
      'fromname' => '',
      'toname' => '',
      'replyto' => '',
    ]
  );

  $defaults['body']['format'] = filter_fallback_format();
  $form['fromname'] = [
    '#type' => 'textfield',
    '#title' => t('From name'),
    '#default_value' => (isset($defaults['fromname'])) ? $defaults['fromname'] : '',
    '#maxlength' => 128,
  ];
  $form['to'] = [
    '#type' => 'textfield',
    '#title' => t('To'),
    '#default_value' => $defaults['to'],
    '#maxlength' => 128,
    '#required' => TRUE,
  ];
  $form['toname'] = [
    '#type' => 'textfield',
    '#title' => t('To Name'),
    '#default_value' => (isset($defaults['toname'])) ? $defaults['toname'] : '',
    '#maxlength' => 128,
  ];
  $form['replyto'] = [
    '#type' => 'textfield',
    '#title' => t('Reply-To'),
    '#maxlength' => 128,
    '#default_value' => (isset($defaults['replyto'])) ? $defaults['replyto'] : '',
  ];
  $form['subject'] = [
    '#type' => 'textfield',
    '#title' => t('Subject'),
    '#default_value' => $defaults['subject'],
    '#maxlength' => 128,
    '#required' => TRUE,
  ];
  $form['include_attachment'] = [
    '#title' => t('Include attachment'),
    '#type' => 'checkbox',
    '#description' => t('If checked, the Drupal icon will be included as an attachment with the test email.'),
    '#default_value' => TRUE,
  ];
  $form['body'] = [
    '#type' => 'text_format',
    '#title' => t('Body'),
    '#rows' => 20,
    '#default_value' => $defaults['body']['value'],
    '#format' => $defaults['body']['format'],
    '#required' => TRUE,
  ];
  $form['submit'] = [
    '#type' => 'submit',
    '#value' => t('Send test message'),
  ];
  return $form;
}

/**
 * Implements hook_submit().
 */
function sendgrid_integration_test_submit($form, &$form_state) {
  // Create defaults array.
  $defaults = [
    'to' => $form_state['values']['to'],
    'subject' => $form_state['values']['subject'],
    'body' => $form_state['values']['body'],
    'toname' => $form_state['values']['toname'],
    'fromname' => $form_state['values']['fromname'],
    'replyto' => $form_state['values']['replyto'],
  ];
  // Set the defaults for reuse.
  variable_set('sendgrid_integration_test_defaults', $defaults);

  $params = [
    'subject' => $form_state['values']['subject'],
    'body' => check_markup(
      $form_state['values']['body']['value'],
      $form_state['values']['body']['format']
    ),
  ];
  if (!empty($form_state['values']['replyto'])) {
    $params['Reply-To'] = $form_state['values']['replyto'];
  }
  if (!empty($form_state['values']['toname'])) {
    $sendto = $form_state['values']['toname'] . '<' . $form_state['values']['to'] . '>';
  }
  else {
    $sendto = $form_state['values']['to'];
  }
  $params['include_test_attachment'] = $form_state['values']['include_attachment'];
  // Setting a specific mail system for the SendGrid Integration Module.
  if (module_exists('mailsystem')) {
    mailsystem_set(['sendgrid_integration' => 'SendGridMailSystem']);
  }
  else {
    global $conf;
    $conf['mail_system'] = array('default-system' => 'SendGridMailSystem');
  }
  // Attempt to send the email and post a message if it was successful.
  if (!empty($form_state['values']['fromname'])) {
    $senderfrom = $form_state['values']['fromname'] . ' <' . variable_get('site_mail') . '>';
  }
  else {
    $senderfrom = variable_get('site_mail');
  }
  $result = drupal_mail('sendgrid_integration', 'test', $sendto, language_default(), $params, $senderfrom);
  if (isset($result['result']) && $result['result'] == 'true') {
    drupal_set_message(t('SendGrid test email sent from %from to %to.', [
      '%from' => $senderfrom,
      '%to' => $sendto,
    ]), 'status');
  }
}
