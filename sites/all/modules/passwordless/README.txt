This module replaces the regular Drupal login form with a modification of the password-
request form, to give the possibility to log in without using a password.

Every time a user needs to log in, only the e-mail address is required. The login link 
will be sent to the user's e-mail address, and will expire in 24 hours if not used.

Passwordless disables the password-reset form, and changes the relevant settings at 
admin/config/people/accounts. Uninstalling the module will restore everything to the way 
it was before (including the settings). It's also compatible with other login-enhancing 
modules, like [LoginToboggan](http://drupal.org/project/logintoboggan).

### Note

Passwordless disables the password fields in user-registration and user-profile forms, 
which means that:

1. the system takes care of creating a password for new users
2. there's no longer a requirement for users to reenter their current password when they 
enter a new e-mail address in their profile.

Due to point number 2, Passwordless depends on 
[Email Change Confirmation](http://drupal.org/project/email_confirm), 
at least until [#85494] is resolved. Make sure you save settings at 
admin/config/people/email_confirm, including the "From" address, for the module to work 
properly.

### Settings

Passwordless settings can be found at admin/config/system/passwordless.

### Suggested modules

[Email Registration](http://drupal.org/project/email_registration) is recommended, to 
allow users to register just with their e-mail address, without providing a user name.

Enabling [HTML5 Tools](http://drupal.org/project/html5_tools) is encouraged for HTML5 
sites, since it allows Passwordless to produce an HTML5-compliant `type="email"` field in 
login forms. Without HTML5 Tools, a regular text field will be produced.

### Due credit

Passwordless follows the idea behind [NoPassword](https://nopassword.alexsmolen.com), but 
is all based on Drupal's native functionality and code.