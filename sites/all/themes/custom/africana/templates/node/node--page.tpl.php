<?php
	$wrapper = entity_metadata_wrapper('node', $node);

	$body_wrapper = $wrapper->body->value();
	$body_content = $body_wrapper['value'];

	$photo_wrapper = $wrapper->field_image->value();
	$photo_uri = $photo_wrapper['uri'];
	$photo_url = image_style_url('banner__large', $photo_uri);

	// Set Regions
	$primary_sidebar_region = block_get_blocks_by_region('sidebar_first');
	$secondary_sidebar_region = block_get_blocks_by_region('sidebar_second');
	$body_content_region = block_get_blocks_by_region('body_content');
	$body_content_after_region = block_get_blocks_by_region('body_content_after');
	$left_nav_region = block_get_blocks_by_region('left_nav');

	// Set Section title
  $menuParent = menu_get_active_trail();
  $menuParentTitle = $menuParent['1']['link_title'];
  if ($menuParentTitle == 'Department of Africana Studies' || $menuParentTitle == 'Center for Africana Studies') {
  	$menuParentShow = TRUE;
  } else {
  	$menuParentShow = FALSE;
  }
?>


<?php if (!($is_front)): ?>
<div class="<?php $photo_uri ? print 'banner' : print 'no-banner'; ?> <?php $left_nav_region ? print 'is-leftnav' : print 'no-leftnav'; ?> container-main full node-<?php print $node->nid; ?> <?php print $classes; ?>"<?php print $attributes; ?>>
  <?php print render($title_prefix); print render($title_suffix); ?>

  <?php if($photo_uri): ?>
	  <img class="banner-pic" src="<?php print $photo_url; ?>" />
		<div class="container-content-wrapper">
			 <?php /* if ($menuParentTitle): ?>
				<h2 class="main"><?php print $menuParentTitle; ?></h2>
			<?php endif; */ ?>
		  <?php if($primary_sidebar_region): ?>
				<div class="">
					<?php print render($primary_sidebar_region); ?>
				</div>
			<?php endif; ?>
			<div class="body-content-wrapper">
				<h1 class="page-header"><?php print $title; ?></h1>
				<?php if($left_nav_region): ?>
					<div class="container-leftnav">
						<?php print render($left_nav_region); ?>
					</div>
				<?php endif; ?>
				<div class="body-content">
				  <?php print render($content['body']); ?>
				  <?php print render($body_content_region); ?>
			  </div>
			  <div class="clearfix"></div>
		  </div>
	  </div>
		<?php if($secondary_sidebar_region): ?>
			<div class="sidebar-nav-wrapper">
				<?php print render($secondary_sidebar_region); ?>
			</div>
		<?php endif; ?>

	<?php else: // No banner pic ?>
		<div class="container-content-wrapper">
			<?php if ($menuParentTitle && $menuParentShow): ?>
				<h2 class="main"><?php print $menuParentTitle; ?></h2>
			<?php endif; ?>
			<?php if($primary_sidebar_region): ?>
				<div class="sidebar-nav-wrapper">
					<?php print render($primary_sidebar_region); ?>
				</div>
			<?php endif; ?>
		  <?php if ($body_content || $body_content_region): ?>
			<div class="body-content-wrapper">
				<h1 class="page-header"><?php print $title; ?></h1>
				<?php if($left_nav_region): ?>
					<div class="container-leftnav">
						<?php print render($left_nav_region); ?>
					</div>
				<?php endif; ?>
				<div class="body-content">
				  <?php print render($content['body']); ?>
				  <?php print render($body_content_region); ?>
			  </div>
			  <div class="clearfix"></div>
		  </div>
			<?php endif; ?>
			<?php if ($body_content_after_region): ?>
				<div class="body-content-after-wrapper">
					<?php print render($body_content_after_region); ?>
				</div>
			<?php endif; ?>
			<div class="clearfix"></div>
	  </div> <?php //.container-content-wrapper ?>

		<?php if($secondary_sidebar_region): ?>
			<div class="">
				<?php print render($secondary_sidebar_region); ?>
			</div>
		<?php endif; ?>

	<?php endif; // photo_uri ?>
</div>
<?php endif; // is_front ?>

