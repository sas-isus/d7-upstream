/**
 * Created by rickward on 3/19/14.
 */
/* jquery */
jQuery(document).ready(function() {
    jQuery('iframe').each(function( index ) {
        var srcString = jQuery(this).attr('src');

        jQuery(this).attr('src',strip_protocol(srcString));
    });

    // also process object embeds
    jQuery('object').each(function( index ) {
        var srcString = jQuery(this).attr('data');

        jQuery(this).attr('data',strip_protocol(srcString));
    });
})

/**
 * remove everything before // from string
 * @param string
 * @returns {string}
 */
function strip_protocol (string) {
    var startIndex = string.indexOf('//');

    if (startIndex != -1) {
        return string.substr(startIndex);
    }
    else {
        return string;
    }
}
