<?php
	$wrapper = entity_metadata_wrapper('node', $node);

	$body_content_wrapper = $wrapper->body->value();
	$body_content = $body_content_wrapper['value'];

	$photo_wrapper = $wrapper->field_image->value();
	$photo_uri = $photo_wrapper['uri'];
	$photo_url = image_style_url('slideshow', $photo_uri);

	$logo_wrapper = $wrapper->field_logo->value();
	$logo_uri = $logo_wrapper['uri'];
	$logo_url = file_create_url($logo_uri);

	$content_url_wrapper = $wrapper->field_url->value();
	$content_url = $content_url_wrapper['url'];
?>
<div class="teaser node-<?php print $node->nid; ?> <?php print $classes; ?>"<?php print $attributes; ?>>
  <?php print render($title_prefix); print render($title_suffix); ?>
  <?php if($content_url): ?>
  	<a class="main" href="<?php print $content_url; ?>">
  <?php endif; ?>
	<img class="main" src="<?php print $photo_url; ?>" />
	<div class="container <?php $logo_uri ? print 'slide-logo' : ''; ?>">
		<div class="carousel-caption">
			<?php if($logo_uri): ?>
				<div class="container-logo">
					<img src="<?php print $logo_url; ?>" />
				</div>
			<?php endif; ?>
			<h3><?php print $title; ?></h3>
			<?php print $body_content; ?>
		</div>
	</div>
	<?php $content_url ? print '</a>' : ''; ?>
</div>