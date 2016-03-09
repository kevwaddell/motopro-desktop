<?php get_header(); ?>

<?php 	
$blog_page = get_option("page_for_posts");
//echo '<pre>';print_r($blog_page);echo '</pre>';
$pg_sections = get_field('pg_sections', $blog_page);
$banner_title_active =	false;
$social_feed_active = false;
$quote_active = false;
$post_counter = 0;

if (!empty($pg_sections) ) {
	//echo '<pre class="debug">';print_r($pg_sections);echo '</pre>';
	
	foreach ($pg_sections as $section) {
		
		switch ($section) {
			case "Banner title": $banner_title_active = true;	
			break;
			case "Social Feed": $social_feed_active = true;
			break;
			case "Client quote": $quote_active = true;
			break;
		}
		
	}
}
?>

<?php if ( has_post_thumbnail($blog_page) && $banner_title_active ) { ?>
	<?php inc('blog-featured-img', 'blog'); ?>
<?php } ?>

<!-- Container  -->
<div class="container">
	
	<article <?php post_class(null, $blog_page); ?>>
		<div class="row">
			<div class="col-xs-6 col-xs-offset-3">
				<h2 class="font-cond caps text-center pg-tag"><?php echo get_the_title($blog_page); ?></h2>
			</div>
		</div>
		
		<?php get_sidebar(); ?>
	
		<?php inc('post-list-grid', 'blog'); ?>
		
		<?php inc('social-feed', 'blog'); ?>
				
	</article>
	
</div>
<!-- Container end  -->

<?php get_footer(); ?>
