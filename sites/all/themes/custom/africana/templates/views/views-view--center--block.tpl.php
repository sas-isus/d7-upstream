<div class="<?php print $classes; ?>">
  <?php print render($title_prefix); ?>

  <?php if ($rows): ?>
    <div class="view-content masonry">
      <div class="gutter-size"></div>
      <?php print $rows; ?>
      <div class="clearfix"></div>
    </div>
  <?php elseif ($empty): ?>
    <div class="view-empty">
      <?php print $empty; ?>
    </div>
  <?php endif; ?>

  <?php if ($pager): ?>
    <?php print $pager; ?>
  <?php endif; ?>

  <?php if ($footer): ?>
    <div class="view-footer">
      <?php print $footer; ?>
    </div>
  <?php endif; ?>

</div><?php /* class view */ ?>