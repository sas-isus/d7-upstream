  
  <?php
 function removenl($field) {
    return preg_replace( "/\r|\n/", " ", $field);
}

function convert_to_date_field($date, $format = 'Y-m-d H:i:s') {
 $date = strtotime($date);
 $date = date($format, $date);
  return (object) array(
    'value' => $date,
  );
}

function convert_to_date_created($field, $format = 'U') {
 $field = strtotime($field);
 $field = date($format, $field);
  return (object) array(
    'value' => $field,
  );
}

function html_decode($field) {
	return html_entity_decode($field, ENT_QUOTES, 'UTF-8');
}
