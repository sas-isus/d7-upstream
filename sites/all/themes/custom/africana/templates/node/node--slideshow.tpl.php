<?php
	$wrapper = entity_metadata_wrapper('node', $node);

	$body_content_wrapper = $wrapper->body->value();
	$body_content = $body_content_wrapper['value'];

	$photo_wrapper = $wrapper->field_image->value();
	$photo_uri = $photo_wrapper['uri'];
	$photo_url = image_style_url('slideshow', $photo_uri);

	$content_url_wrapper = $wrapper->field_url->value();
	$content_url = $content_url_wrapper['url'];
?>
<div class="full node-<?php print $node->nid; ?> <?php print $classes; ?>"<?php print $attributes; ?>>
  <?php print render($title_prefix); print render($title_suffix); ?>
  <?php if($content_url): ?>
  	<a class="main" href="<?php print $content_url; ?>">
  <?php endif; ?>
	<img class="main" src="<?php print $photo_url; ?>" />
	<div class="container">
		<div class="carousel-caption">
			<h4><?php print $title; ?></h4>
			<?php print $body_content; ?>
		</div>
	</div>
	<?php if($content_url): ?>
  	</a>
  <?php endif; ?>
</div>