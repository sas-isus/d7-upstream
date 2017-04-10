<?php
/**
 * @file
 * Wrapper HTML for blocks attached to menu items.
 *
 * Available variables:
 *   $content - Full block HTML of attached block.
 *   $classes - CSS class string
 *
 * Helper variables:
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 * - $is_front: Flags true when presented in the front page.
 * - $logged_in: Flags true when the current user is a logged-in member.
 * - $is_admin: Flags true when the current user is an administrator.
 *
 * @see template_preprocess()
 * @see template_preprocess_menu_attach_block_wrapper()
 * @see template_process()
 *
 * @ingroup themeable
 */
?>
<div class="<?php print $classes?>">
	<?php print $content; ?>
</div>
