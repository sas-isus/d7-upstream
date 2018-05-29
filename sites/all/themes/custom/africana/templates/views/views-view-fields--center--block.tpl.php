<?php
dpm($fields);
die();
	$body_content = $fields['body']->content;

	$node_title = $fields['title']->raw;

	$show_link = $fields['field_show_link_back']->content;

	$show_link_nid = $fields['view_node']->raw;
	$show_link_alias = drupal_get_path_alias('node/' . $show_link_nid);

	$content_type = $fields['type']->content;
	switch ($content_type) {
    case page:
        $show_link_title = 'Learn More';
        break;
    case events:
        $show_link_title = 'View Event';
        break;
    case news:
        $show_link_title = 'Read Story';
        break;
	}
?>

<div class="teaser node masonry-brick <?php print $classes; ?>"<?php print $attributes; ?>>
  <?php print render($title_prefix); print render($title_suffix); ?>

  	<?php print $fields['field_image']->content; ?>
	<div class="content-container">
		<h2><?php print $node_title; ?></h2>
		<div class="content"><?php print $body_content; ?></div>
		<?php if($show_link == 'Yes'): ?>
			<a class="btn-darkgray-wire" href="<?php print $show_link_alias; ?>"><?php print $show_link_title; ?></a>
			<div class="clearfix"></div>
		<?php endif; ?>
	</div>

</div>
