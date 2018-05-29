<?php
$path_to_theme = DRUPAL_ROOT . '/'. drupal_get_path('theme', 'africana');
$path_to_includes = $path_to_theme . '/templates/includes/';
?>
<?php include $path_to_includes . 'topper.tpl.php'; ?>



<div class="<?php $page['sidebar_first'] ? print 'is-leftnav' : print 'no-leftnav'; ?> container-main full <?php print $classes; ?>"<?php print $attributes; ?>>
  <?php print render($title_prefix); print render($title_suffix); ?>

		<div class="container-content-wrapper">
			<?php if($primary_sidebar_region): ?>
				<div class="sidebar-nav-wrapper">
					<?php print render($primary_sidebar_region); ?>
				</div>
			<?php endif; ?>
			<div class="body-content-wrapper">
				<h1 class="page-header"><?php print $title; ?></h1>
				<?php if (!empty($page['sidebar_first'])): ?>
					<div class="container-leftnav sidebar-first">
						<?php print render($page['sidebar_first']); ?>
					</div>
				<?php endif; ?>
				<div class="body-content">
				  <?php print $messages; ?>
<?php if ($tabs && $is_admin): ?>
  <?php print render($tabs); ?>
  <div class="clearfix"></div>
<?php endif; ?>
<?php if (!empty($page['highlighted'])): ?>
  <div class="highlighted hero-unit"><?php print render($page['highlighted']); ?></div>
<?php endif; ?>
<?php if (!empty($page['help'])): ?>
  <div class="well"><?php print render($page['help']); ?></div>
<?php endif; ?>

<?php print render($page['content']); ?>
			  </div>
			  <div class="clearfix"></div>
		  </div>
			
			<div class="clearfix"></div>
	  </div> <?php //.container-content-wrapper ?>


</div>






<?php include $path_to_includes . 'footer.tpl.php'; ?>