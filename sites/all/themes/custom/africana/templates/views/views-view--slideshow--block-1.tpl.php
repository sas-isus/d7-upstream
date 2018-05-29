<?php
	$results_array = $view->result;
?>
<div id="myCarousel" data-ride="carousel" class="<?php print $classes; ?>">
  <?php if ($rows): ?>
  	<ol class="carousel-indicators">
  	<?php $count = 0; ?>
  	<?php foreach($results_array as $key=>$val): ?>
	      <li data-target="#myCarousel" data-slide-to="<?php print $count; ?>"<?php ($count == 0) ? print 'class="active"' : ''; ?>></li>
	    <?php $count++; ?>
	  <?php endforeach; ?>
	  </ol>
	  <div class="carousel-inner">
		  <?php print $rows; ?>
    </div>

    <a class="left carousel-control" href="#myCarousel" data-slide="prev">&lsaquo;</a>
      <a class="right carousel-control" href="#myCarousel" data-slide="next">&rsaquo;</a>
      
  <?php endif; ?>
</div><?php /* class view */ ?>