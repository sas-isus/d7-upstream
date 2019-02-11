<?php

// kirk 2018
// template to render qualtrics survey in iframe

// get plain text height number
// in this way, small surveys can take up less website real estate and be embedded easier
$field = field_get_items('node', $node, 'field_qualtrics_height');
$height_output = intval(render(field_view_value('node', $node, 'field_qualtrics_height', $field[0])));

// get plain text URL field value for external qualtrics survey
// working with just the index number of the qualtrics survey (e.g., "SV_50YeavU8VJtcJIV", not the entire URL)
$field = field_get_items('node', $node, 'field_qualtrics_url');
$url_output = render(field_view_value('node', $node, 'field_qualtrics_url', $field[0]));;


// check to make sure height_output is an integer and that url_output is set
// render the iframe using full URL built from the above qualtrics index
// sample qualtrics anonymous URL: https://upenn.co1.qualtrics.com/jfe/form/SV_50YeavU8VJtcJIV

if (filter_var($height_output, FILTER_VALIDATE_INT)) {
  if ( isset($url_output) ) {
     print("<iframe class=\"qualtrics\" style=\"height:" . $height_output . "px;\" src=\"https://upenn.co1.qualtrics.com/jfe/form/" . $url_output . "\">ERROR: Browser not compatible</iframe>");
  }
}



?>


