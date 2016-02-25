<?php 
/*
Template Name: About page
*/
?>
<?php get_header(); ?>

<?php if ( have_posts() ): while ( have_posts() ) : the_post(); ?>	

<?php if ( has_post_thumbnail() ) { ?>
	<?php inc('featured-img', 'pages'); ?>
<?php } ?>

<!-- Container  -->
<div class="container">
	<h2 class="font-cond caps pg-tag"><?php the_title(); ?></h2>
	<?php the_content(); ?>
</div>
<!-- Container end  -->

<?php endwhile; ?>
<?php endif; ?>

<?php get_footer(); ?>