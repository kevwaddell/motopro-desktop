<aside class="blog-sidebar">
	
	<?php if (!is_single()) { ?>
		<?php inc('post-filters', 'blog'); ?>			
	<?php } ?>
	
	<?php if (is_single()) { ?>
		<?php inc('single-post-sidebar', 'blog'); ?>			
	<?php } ?>
	
</aside>