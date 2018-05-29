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
<?php print render($page['content']); ?>

<?php if (!empty($page['home_content'])): ?>
  <?php print render($page['home_content']); ?>
<?php endif; ?>

<?php include $path_to_includes . 'footer.tpl.php'; ?>
