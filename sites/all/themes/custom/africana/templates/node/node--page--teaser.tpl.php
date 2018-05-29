<?php
	$wrapper = entity_metadata_wrapper('node', $node);

	$body_wrapper = $wrapper->body->value();
	$body_content = $body_wrapper['value'];

	$photo_wrapper = $wrapper->field_image->value();
	$photo_uri = $photo_wrapper['uri'];
	$photo_url = image_style_url('banner__large', $photo_uri);
?>

<div class="<?php $photo_uri ? print 'banner' : print 'no-banner'; ?> container-main full node-<?php print $node->nid; ?> <?php print $classes; ?>"<?php print $attributes; ?>>
  <?php print render($title_prefix); print render($title_suffix); ?>

  <a href="<?php print $node_url; ?>">
	<img class="thumb" src="<?php print $photo_url; ?>" />
	<div class="content"><?php print $body_content; ?></div>
	<div class="clearfix"></div>
	</a>
</div>

