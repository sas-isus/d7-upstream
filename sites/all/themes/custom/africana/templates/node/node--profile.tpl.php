<?php

	// Set Regions
	$primary_sidebar_region = block_get_blocks_by_region('sidebar_first');
	$secondary_sidebar_region = block_get_blocks_by_region('sidebar_second');
	$body_content_region = block_get_blocks_by_region('body_content');
?>
<div class="full container-main node-<?php print $node->nid; ?> <?php print $classes; ?>"<?php print $attributes; ?>>
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

		  <div class="content">
			  <?php print render($content); ?>
			</div>

			</div>
		</div>
	</div> <?php //.container-content-wrapper ?>
</div>