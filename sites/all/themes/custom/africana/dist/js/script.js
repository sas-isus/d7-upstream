(function ($) {
  Drupal.behaviors.mainScript = {
    attach: function (context, settings) {

    	var resizeTimer;

    	$(window).on("load resize",function(e){
    		// reorder nav container
    		clearTimeout(resizeTimer);
			  resizeTimer = setTimeout(function() {
			    if (window.matchMedia('(min-width: 980px)').matches) {
			    	$('.nav-collapse .col3').append($('.region-navigation'));
			    } else {
			    	$('.nav-collapse .col3 .main').append($('.region-navigation'));
			    }
		    }, 150);
			});

		  function setGridHeight(element) {
				var currentTallest = 0,
				    currentRowStart = 0,
				    rowDivs = new Array(),
				    $el,
				    topPosition = 0;

				$(element).each(function() {

				  $el = $(this);
				  topPosition = $el.position().top;

				   if (currentRowStart != topPosition) {

				     // we just came to a new row.  Set all the heights on the completed row
				     for (currentDiv = 0 ; currentDiv < rowDivs.length ; currentDiv++) {
				       rowDivs[currentDiv].height(currentTallest);
				     }

				     // set the variables for the new row
				     rowDivs.length = 0; // empty the array
				     currentRowStart = topPosition;
				     currentTallest = $el.height();
				     rowDivs.push($el);

				   } else {

				     // another div on the current row.  Add it to the list and check if it's taller
				     rowDivs.push($el);
				     currentTallest = (currentTallest < $el.height()) ? ($el.height()) : (currentTallest);

				  }
				  // do the last row
				   for (currentDiv = 0 ; currentDiv < rowDivs.length ; currentDiv++) {
				     rowDivs[currentDiv].height(currentTallest);
				   }
				 });
		  };

			$(window).on("load resize",function(e){
				clearTimeout(resizeTimer);
			  resizeTimer = setTimeout(function() {
			  	if (window.matchMedia('(min-width: 600px)').matches) {
			  		var gutter_width = $('.gutter-size').width();
			  		console.log(gutter_width);
					  $('.block-dept-ppl-list .view-content').masonry({
						  itemSelector: '.block-dept-ppl-list .views-row',
							layoutPriorities: {
								shelfOrder: 50
							}
						});
						$('.center-list .masonry').masonry({
						  itemSelector: '.center-list .masonry-brick',
						  layoutPriorities: {
								shelfOrder: 50
							}
						});
					}
					if (window.matchMedia('(min-width: 750px)').matches) {
				    setGridHeight('.department .block-views');
				  } else {
				  	$('.department .block-views').css('height', 'auto');
				  }
				}, 150);
			});

    }
  };
})(jQuery);