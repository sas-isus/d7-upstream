<?php
	$wrapper = entity_metadata_wrapper('node', $node);

	$body_wrapper = $wrapper->body->value();
	$body_content = $body_wrapper['summary'];

	$photo_wrapper = $wrapper->field_image->value();
	$photo_uri = $photo_wrapper['uri'];
	$photo_url = image_style_url('news-thumb', $photo_uri);
?>

<div class="teaser node-<?php print $node->nid; ?> <?php print $classes; ?>"<?php print $attributes; ?>>
  <?php print render($title_prefix); print render($title_suffix); ?>

  <a href="<?php print $node_url; ?>">
	<img class="thumb" src="<?php print $photo_url; ?>" />
	<div class="content"><?php print $body_content; ?></div>
	<div class="clearfix"></div>
	</a>

</div>