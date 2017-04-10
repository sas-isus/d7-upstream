(function ($) {

  Drupal.behaviors.easysocialFieldsetSummeries = {
    attach: function (context) {
      $('fieldset.easysocial-settings-form', context).drupalSetSummary(function (context) {
        if($('.easy-social-current-type', context).is(':checked')) {

          var vals = [];

          // Default easy social setting.

          // On Comments.
          var comments = $("input.easy-social-comment-type:checked", context);
          if (comments.length) {
            vals.push('On comments');
          }

          // Widgets per page.
          var number = $("select.easy-social-number-fields-type option:selected", context).val();
          vals.push(Drupal.t('@number Widget fields per page', {'@number': number}));

          // Type of buttons
          vals.push($('div.easy-social-type-buttons input:checked', context).next('label').text());

          // Selected widgets
          $('input.easy-social-each-widget:checked', context).each(function(){
            vals.push($(this).next('label').text());
          });

          return Drupal.checkPlain(vals.join(', '));

        }
        else {
          return Drupal.t('Easy Social is disabled for this type.');
        }
      });
    }
  }
})(jQuery);