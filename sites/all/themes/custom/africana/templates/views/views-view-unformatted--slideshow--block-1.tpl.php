<?php if (!empty($title)): ?>
  <h3><?php print filter_xss($title); ?></h3>
<?php endif; ?>
<?php $count = 1; ?>

<?php foreach ($rows as $id => $row): ?>
<?php
 if ($count == 1) {
   echo '<div class="active ' . filter_xss($classes_array[$id]) . '">';
 }
 else {
   echo '<div class="' . filter_xss($classes_array[$id]) . '">';
 }
?>

   <?php print filter_xss($row, $allowed_tags = array('div', 'img', 'h4', 'p', 'a', 'em', 'strong')); ?>

   <?php $count++ ?>

 </div>
<?php endforeach; ?>