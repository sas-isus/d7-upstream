(function ($) {
  // Implement a show/hide.
  Drupal.behaviors.menu_attach_block = {
    attach: function (context, settings) {
      // Attach hover events, if this link has been defined as hoverable.
      $('a.menu-attach-block-drop-link.expand-on-hover', context).hover(
          /**
           * Show on mouse in.
           */
          function() {
            // Show the block if it is not already shown.
            if (!($(this).hasClass('dropped'))) {
              expand_toggle($(this));
            }
          },
          /**
           * Hide on mouse out.
           */
          function() {
            expand_toggle($(this));
          }
      );

      // Attach click events for links configured to use that.
      $('a.menu-attach-block-drop-link.expand-on-click', context).click(function(event) {
        expand_toggle($(this));
        event.preventDefault();
      });

      /**
       * Shows a block embedded inside a menu item.
       *
       * @param link
       *   The link attached to this menu item, which triggers block show.
       */
      function expand_toggle(link) {
        if (link.hasClass('menu-ajax-enabled')) {
          // Load contents using AJAX.
          if (!link.hasClass('menu-ajax-loaded')) {
            ajax_path = Drupal.settings.basePath + 'menu_attach_block/ajax/' + (link).attr('data-block-id');
            $.ajax({
              type: 'GET',
              url: ajax_path,
              data: '',
              dataType: 'HTML',
              success: function ($block_html) {
                $(link).next('.menu-attach-block-wrapper').html($block_html);
                Drupal.attachBehaviors(link);
              }
            });
          }
        }
        // Show/hide the link.
        $(link).next('.menu-attach-block-wrapper').slideToggle('fast');
        $(link).toggleClass('dropped');
      }
    }
  }
}(jQuery));
