<?php
	$wrapper = entity_metadata_wrapper('node', $node);

	$body_wrapper = $wrapper->body->value();
	$body_content = $body_wrapper['safe_summary'];

	$location_wrapper = $wrapper->field_location->value();
	$location = $location_wrapper['safe_value'];

	$event_type = $wrapper->field_event_type->value();

	$speaker = $wrapper->field_speaker->value();

	$date_wrapper = $wrapper->field_date->value();
	$date_raw = strtotime($date_wrapper['value']);
	$date_month = format_date($date_raw, 'month');
	$date_day = format_date($date_raw, 'day');
	$date_time = format_date($date_raw, 'time');
?>
<div class="teaser node-<?php print $node->nid; ?> <?php print $classes; ?>"<?php print $attributes; ?>>
  <?php print render($title_prefix); print render($title_suffix); ?>

  <a href="<?php print $node_url; ?>">
  <div class="container-date-wrapper">
	  <span class="day"><?php print $date_day; ?></span><br />
  	<span class="month"><?php print $date_month; ?></span>
	</div>
	<div class="content-col">
		<?php if($event_type): ?>
			<strong><?php print $event_type; ?></strong><br />
		<?php endif; ?>
		<em><?php print $title; ?></em><br />
		<?php $speaker ? print $speaker . '<br />' : ''; ?>
		<?php $date_time ? print $date_time . '<br />' : ''; ?>
		<?php $location ? print $location : ''; ?>
		<?php print $body_content; ?>
	</div>
	<div class="clearfix"></div>
	</a>

</div>