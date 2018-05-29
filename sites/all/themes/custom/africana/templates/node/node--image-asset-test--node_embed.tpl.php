<article id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> span9 pull-right example clearfix"<?php print $attributes; ?>>

<?php if(isset($content['field_image'])): ?>

<figure class="image-asset">

	<?php print render($content['field_image']); ?>

<?php if((isset($content['field_caption']) OR isset($content['field_credits']))): ?>

	<figcaption>

	<?php print render($content['field_caption']); ?>

	<?php if(isset($content['field_credits'])): ?><small><?php print render($content['field_credits']); ?></small><?php endif; ?>

	</figcaption>

<?php endif; ?>

</figure>

<?php endif; ?>

</article> <!-- /.node -->
