<?php
	// ** NODE TEMPLATE: CENTER **

	$page_url = $_SERVER['HTTP_HOST'] . request_uri();
	$path_to_theme = drupal_get_path('theme', 'africana');

	$wrapper = entity_metadata_wrapper('node', $node);

	$body_wrapper = $wrapper->body->value();
	$body_content = $body_wrapper['value'];

	$photo_wrapper = $wrapper->field_image->value();
	$photo_uri = $photo_wrapper['uri'];
	$photo_url_small = image_style_url('banner__small', $photo_uri);
	$photo_url_medium = image_style_url('banner__medium', $photo_uri);
	$photo_url_large = image_style_url('banner__large', $photo_uri);

	// Set Regions
	$primary_sidebar_region = block_get_blocks_by_region('sidebar_first');
	$secondary_sidebar_region = block_get_blocks_by_region('sidebar_second');
	$body_content_region = block_get_blocks_by_region('body_content');
	$body_content_after_region = block_get_blocks_by_region('body_content_after');
?>

<div class="<?php $photo_uri ? print 'banner' : print 'no-banner'; ?> container-main subhomepage node-<?php print $node->nid; ?> <?php print $classes; ?>"<?php print $attributes; ?>>
  <?php print render($title_prefix); print render($title_suffix); ?>
  <picture>
	  <source 
	    media="(min-width: 750px)"
	    srcset="<?php print $photo_url_large; ?>">
	   <source 
	    media="(min-width: 500px)"
	    srcset="<?php print $photo_url_medium; ?>">
	  <img 
	    src="<?php print $photo_url_small; ?>" 
	    class="banner-pic" >
	</picture>
	<div class="container-content-wrapper">
	  <h1 class="page-header"><img class="sub-logo" src="<?php print $path_to_theme . '/dist/images/logo-center-black.png'; ?>" /><span><?php print $title; ?></span></h1>
  </div>
  <?php if($primary_sidebar_region): ?>
		<div class="sidebar-nav-wrapper">
			<?php print render($primary_sidebar_region); ?>
		</div>
	<?php endif; ?>
	<?php if($body_content_region || $body_content): ?>
		<div class="body-content-wrapper">
			<div class="body-content-region">
				<div class="body-content">
				  <?php print $body_content; ?>
			  </div>
				<?php print render($body_content_region); ?>
			</div>
			<?php if ($body_content_after_region): ?>
				<div class="body-content-after-wrapper">
					<?php print render($body_content_after_region); ?>
				</div>
			<?php endif; ?>
		</div>
	<?php endif; ?>

</div>