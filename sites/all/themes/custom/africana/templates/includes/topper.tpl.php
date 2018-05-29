<?php
  $block_search = module_invoke('search', 'block_view', 'form');
?>
<div id="sasheader" class="visible-desktop">
  <a class="logo-penn" target="_blank" href="http://www.sas.upenn.edu"><img 
    src="<?php echo $base_path . $directory . '/images/pennsas-logo-white.png';?>" alt="Penn Arts &amp; Sciences Logo" title="Penn Arts &amp; Sciences" /></a>

  <ul class="pull-right unstyled">
    <li class="first"><a href="http://www.upenn.edu">University of Pennsylvania</a></li>
    <li><a href="http://www.sas.upenn.edu/">School of Arts and Sciences</a></li>
    <li><a href="http://www.upenn.edu/penna-z/">Penn A-Z</a></li>
    <li><a href="http://www.upenn.edu/cgi-bin/calendar/calendar?school=9&view=longmonth">Penn Calendar</a></li>
  </ul>
</div>

<header role="banner" id="page-header" class="row-fluid">
  <div class="col1 span4">
    <h1 class="logo"><a href="<?php print base_path(); ?>"><span class="heavy">Africana</span><span class="light">Studies</span></a></h1>
    <a class="btn btn-navbar" data-toggle="collapse" data-target=".nav-collapse">
      <span class="icon-bar"></span>
      <span class="icon-bar"></span>
      <span class="icon-bar"></span>
    </a>
    <div class="clearfix"></div>
  </div>

  <div class="nav-collapse collapse span8">
    <div class="col2 span5">
    <?php print render($page['header']); ?>
    </div>
    <div class="col3 span7">

      <nav class="main" role="navigation">
        <?php if (!empty($page['navigation'])): ?>
          <?php print render($page['navigation']); ?>
        <?php endif; ?>
      </nav>
      <?php print render($block_search['content']); ?>
      <div class="clearfix"></div>
    </div>
  </div>

</header>

