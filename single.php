<?php get_header(); ?>

<?php if ( have_posts() ): while ( have_posts() ) : the_post(); ?>	

<?php 
$post_content = get_extended( $post->post_content );
$content_main = apply_filters('the_content', $post_content['main'] );
$content_extended = apply_filters('the_content', $post_content['extended'] );
$show_author = get_field('show_author');
//echo '<pre class="debug">';print_r($post_content);echo '</pre>';

if (!empty($post_content['more_text'])) {
$more_btn_text = $post_content['more_text'];	
} else {
$more_btn_text = "Continue Reading";	
}

?>

<!-- Container  -->
<div class="container">
	<article <?php post_class(); ?>>
			<div class="row">
				<div class="col-xs-8">

					<header class="article-header">
						<div class="post-info">
							<div class="row">
								<div class="col-xs-2">
									
									<time class="pub-date" datetime="<?php echo get_the_date('Y-m-d'); ?>">
										<span class="month"><?php echo get_the_date('M'); ?></span>
										<span class="day"><?php echo get_the_date('j'); ?></span>
										<span class="year"><?php echo get_the_date('Y'); ?></span>
									</time>

								</div>
								<div class="col-xs-10">
									
									<div class="author-details">
										<?php if ($show_author) { ?>
										Posted by: <?php the_author(); ?>
										<?php } ?>
									</div>
									<?php if ( function_exists( 'ADDTOANY_SHARE_SAVE_KIT' ) ) { ADDTOANY_SHARE_SAVE_KIT(); } ?>
								</div>
							</div>
						</div>
						<h1 class="font-cond caps"><?php the_title(); ?></h1>
					</header>
					<div class="main-text">
						
						<?php if (!empty($post_content['extended'])) { ?>
						<?php echo $content_main;  ?>
						<div id="content-extra" class="closed">
							<div id="content-extra-inner">
								<?php echo $content_extended;  ?>
								<button id="close-content-extra-btn" class="btn btn-default"><i class="fa fa-times-circle"></i><span class="sr-only">Close</span></button>
							</div>
						</div>
						
						<?php } else { ?>
						<?php the_content(); ?>
						<?php } ?>
						
					</div>
				</div>
				
				<div class="col-xs-4">
					<?php get_sidebar(); ?>	
				</div>
		
			</div>
			
			<?php if (!empty($post_content['extended'])) { ?>
			<button id="continue-read-btn" class="btn btn-default btn-block"><?php echo $more_btn_text; ?><i class="fa fa-plus-circle"></i></button>
			<?php } ?>
			
	</article>
</div>
<!-- Container end  -->

<?php inc('request-a-callback', 'sections'); ?>	

<?php inc('related-posts', 'blog'); ?>	

<?php endwhile; ?>
<?php endif; ?>

<?php get_footer(); ?>