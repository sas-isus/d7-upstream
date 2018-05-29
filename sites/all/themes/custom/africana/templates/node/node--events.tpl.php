<?php
	$wrapper = entity_metadata_wrapper('node', $node);

	$body_wrapper = $wrapper->body->value();
	$body_content = $body_wrapper['safe_value'];

	$location_wrapper = $wrapper->field_location->value();
	$location = $location_wrapper['safe_value'];

	$event_type = $wrapper->field_event_type->value();

	$section = $wrapper->field_section->value();
	if($section == 'department') {
		$section_title = t('Department of Africana Studies');
	} else {
		$section_title = t('Center for Africana Studies');
	}

	$speaker = $wrapper->field_speaker->value();

	$date_wrapper = $wrapper->field_date->value();
	$date_raw = strtotime($date_wrapper['value']);
	$date_month = format_date($date_raw, 'month');
	$date_day = format_date($date_raw, 'day');
	$date_time = format_date($date_raw, 'time');

	// Set Regions
	$primary_sidebar_region = block_get_blocks_by_region('sidebar_first');
	$secondary_sidebar_region = block_get_blocks_by_region('sidebar_second');
	$body_content_region = block_get_blocks_by_region('body_content');
?>
<div class="full no-banner container-main node-<?php print $node->nid; ?> <?php print $classes; ?>"<?php print $attributes; ?>>
  <?php print render($title_prefix); print render($title_suffix); ?>

  <div class="container-content-wrapper">
		<?php if($primary_sidebar_region): ?>
			<div class="">
				<?php print render($primary_sidebar_region); ?>
			</div>
		<?php endif; ?>
	  
		<div class="body-content-wrapper">
			<h1 class="page-header"><?php print $title; ?></h1>
			<div class="body-content">
				<div class="container-date-wrapper">
				  <span class="day"><?php print $date_day; ?></span><br />
			  	<span class="month"><?php print $date_month; ?></span>
				</div>
				<div class="content-col">

					<?php if($event_type): ?>
						<strong><?php print $event_type; ?></strong><br />
					<?php endif; ?>

					   <?php print render($content); ?>

					
				</div>
			</div>
		</div>
		<div class="clearfix"></div>
		<?php if($body_content_region): ?>
			<div class="body-content-region">
				<?php print render($body_content_region); ?>
			</div>
		<?php endif; ?>
  </div> <?php //.container-content-wrapper ?>

	<?php if($secondary_sidebar_region): ?>
		<div class="">
			<?php print render($secondary_sidebar_region); ?>
		</div>
	<?php endif; ?>

</div>