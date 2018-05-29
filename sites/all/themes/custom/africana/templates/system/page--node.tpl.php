<?php
$path_to_theme = DRUPAL_ROOT . '/'. drupal_get_path('theme', 'africana');
$path_to_includes = $path_to_theme . '/templates/includes/';
?>
<?php include $path_to_includes . 'topper.tpl.php'; ?>

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

<?php include $path_to_includes . 'footer.tpl.php'; ?>