<?php
/**
 * @file
 * This template handles the output of the Site Status Message.
 *
 * Variables available:
 * - $message: The message to display (run through check_plain).
 * - $link: An optional link to a page with more information.
 */
?>
<div id="site-status">
  <strong><?php print $message; ?></strong><?php if ($link): ?> <?php print $link; ?><?php endif; ?>
</div>
