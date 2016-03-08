<section class="post-list grid">	
<?php if ( have_posts() ): ?>
	
	<div class="page-links pl-top">
		<?php wp_pagenavi(); ?>
	</div>
	
	<div class="row">
<?php while ( have_posts() ) : the_post(); $post_counter++; ?>	
	<?php
	$post_thumbnail = get_post_thumbnail_id();	
	if ($post_thumbnail) {
	$img = wp_get_attachment_image_src($post_thumbnail, 'feat-img-wide');
	$bg_img = $img[0];	
	} else {
	$bg_img = get_bloginfo('stylesheet_directory'). "/_/css/img/sml-full-icon-white.svg";	
	}	
	//echo '<pre class="debug">';print_r($img);echo '</pre>';
	?>
	<div class="col-xs-<?php echo ( $post_counter == 1 || $post_counter == 4 || $post_counter == 5 ) ? '4':'8'; ?>">
		<article <?php post_class(); ?>>
			<div class="post-img" style="background-image: url(<?php echo $bg_img; ?>)"></div>
			<h3 class="font-cond caps"><a href="<?php the_permalink(); ?>" title="<?php the_title_attribute(); ?>"><?php the_title(); ?></a></h3>
			<a href="<?php the_permalink(); ?>" class="grad-link" title="<?php the_title_attribute(); ?>"><span class="sr-only">View article</span></a>
		</article>
	</div>
<?php endwhile; ?>
	</div>
	
	<div class="page-links pl-bottom">
		<?php wp_pagenavi(); ?>
	</div>
	
<?php else: ?>
	<div class="well well-lg text-centre">
		<h2>Sorry there is no news at the moment.</h2>
		<p>Please return soon.</p>
	</div>
<?php endif; ?>
</section>