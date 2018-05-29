<?php
	$wrapper = entity_metadata_wrapper('node', $node);

	$body_wrapper = $wrapper->body->value();
	$body_content = $body_wrapper['safe_value'];

	$photo_wrapper = $wrapper->field_image->value();
	$photo_uri = $photo_wrapper['uri'];
	$photo_url = image_style_url('news-medium', $photo_uri);

	$section = $wrapper->field_section->value();
	if($section == 'department') {
		$section_title = t('Department of Africana Studies');
	} else {
		$section_title = t('Center for Africana Studies');
	}

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
		<div class="container-content">
		  <h1 class="page-header"><?php print $title; ?></h1>
			<div class="content-col">
				<?php print render($content); ?>
			</div>
			<div class="clearfix"></div>
			<?php if($body_content_region): ?>
				<div class="body-content-region">
					<?php print render($body_content_region); ?>
				</div>
			<?php endif; ?>
		</div>
  </div> <?php //.container-content-wrapper ?>

	<?php if($secondary_sidebar_region): ?>
		<div class="">
			<?php print render($secondary_sidebar_region); ?>
		</div>
	<?php endif; ?>

</div>