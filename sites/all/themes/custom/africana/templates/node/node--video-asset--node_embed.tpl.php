

<?php

$node = node_load($nid);

/* get vimeo_id field value without markup */

$field = field_get_items('node', $node, 'field_vimeo_id');
$vimeo_output = field_view_value('node', $node, 'field_vimeo_id', $field[0]);

/* get youtube_id field value without markup */

$field = field_get_items('node', $node, 'field_youtube_id');
$youtube_output = field_view_value('node', $node, 'field_youtube_id', $field[0]);

/* get media.sas field value without markup */

$field = field_get_items('node', $node, 'field_media_sas_id');
$mediasas_output = field_view_value('node', $node, 'field_media_sas_id', $field[0]);

?>

<?php if((isset($content['field_vimeo_id']) OR isset($content['field_youtube_id']) OR isset($content['field_media_sas_id']) )): ?>

<article id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>

<?php if(isset($content['field_vimeo_id'])): ?>
<div class="videoWrapper"><iframe src="//player.vimeo.com/video/<?php print render($vimeo_output); ?>" frameborder="0" webkitallowfullscreen mozallowfullscreen allowfullscreen></iframe></div> 
<?php endif; ?>

<?php if(isset($content['field_youtube_id'])): ?>
<div class="videoWrapper"><iframe src="//www.youtube.com/embed/<?php print render($youtube_output); ?>" frameborder="0" allowfullscreen></iframe></div> 
<?php endif; ?>

<?php if(isset($content['field_media_sas_id'])): ?>
<div><iframe src="//media.sas.upenn.edu/service.php?action=embed&file_id=<?php print render($mediasas_output); ?>&caption=&poster=&width=320&height=204&autoplay=false&start=0" width="340" height="224" scrolling="no" frameborder="0" allowfullscreen></iframe></div>
<?php endif; ?>

</article> <!-- /.node -->

<?php endif; ?>