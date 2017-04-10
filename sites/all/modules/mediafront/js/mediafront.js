(function($) {
  $(function() {

    // Add the media object.
    jQuery.media = jQuery.media ? jQuery.media : {};

    // Connecting the media blocks to the player.
    var mediaplayer = null;
    var mediaNids = [];
    var mediaIndex = 0;
    var mediaSelected = 'mediafront-selected-media';

    // Get the previous media node.
    jQuery.media.prevMedia = function() {
      mediaIndex = (mediaIndex > 0) ? (mediaIndex - 1) : (mediaNids.length - 1);
      return jQuery.media.nodes[mediaNids[mediaIndex]];
    };

    // Get the next media node.
    jQuery.media.nextMedia = function() {
      mediaIndex = (mediaIndex < (mediaNids.length - 1)) ? (mediaIndex + 1) : 0;
      return jQuery.media.nodes[mediaNids[mediaIndex]];
    };

    // Loads a node by checking to see if it is a full object or not.
    jQuery.media.loadNode = function( node ) {
      if (mediaplayer && node && node.nid) {
        mediaplayer.node.setNode(node);
      }
    };

    // Load the next media.
    jQuery.media.loadNext = function() {
      $("." + mediaSelected).removeClass(mediaSelected);
      var newMedia = jQuery.media.nextMedia();
      $(jQuery.media.fieldSelector).eq(mediaIndex).parent().addClass(mediaSelected);
      jQuery.media.loadNode(newMedia);
    };

    // Load the previous media.
    jQuery.media.loadPrev = function() {
      $("." + mediaSelected).removeClass(mediaSelected);
      var newMedia = jQuery.media.prevMedia();
      $(jQuery.media.fieldSelector).eq(mediaIndex).parent().addClass(mediaSelected);
      jQuery.media.loadNode(newMedia);
    };

    // Only call this if the code is available.
    if (jQuery.media.onLoaded) {

      // Register for media complete events, and load the next media on completion.
      jQuery.media.onLoaded(jQuery.media.playerId, function( player ) {

        // Set the mediaplayer.
        mediaplayer = player;

        // Bind the media update for when one media completes.
        player.node.player.display.bind( "mediaupdate", function( event, data ) {
          if( data.type == 'complete' && jQuery.media.hasMedia ) {
            jQuery.media.loadNext();
          }
        });

        // Load the first media.
        $(jQuery.media.fieldSelector).eq(0).parent().addClass(mediaSelected);
        jQuery.media.loadNode(jQuery.media.nodes[mediaNids[0]]);
      });
    }

    // Iterate through all of the nid fields.
    $(jQuery.media.fieldSelector).each(function(index) {

      // Get the nid for this item.
      var nid = $(this).parent().find('.views-field-mediafront-nid .media-nid-hidden').text();
      mediaNids.push(nid);

      // Alter the parent handler so that this becomes a link to the main player.
      $(this).parent().css("cursor", "pointer").bind('click', {nid:nid, index:index}, function(event) {
        event.preventDefault();
        $("." + mediaSelected).removeClass(mediaSelected);
        $(this).addClass(mediaSelected);
        mediaIndex = event.data.index;
        jQuery.media.loadNode( jQuery.media.nodes[event.data.nid] );
      });
    });

    // Handle when a user clicks on the next button.
    $("#mediaplayer_next").click(function(event) {
      event.preventDefault();
      jQuery.media.loadNext();
    });

    // Handle when a user clicks on the previous button.
    $("#mediaplayer_prev").click(function(event) {
      event.preventDefault();
      jQuery.media.loadPrev();
    });
  });
}(jQuery));