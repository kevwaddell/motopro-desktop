<?php 
$articles_active = get_field('ra_active');

if ($articles_active) {  
$section_header = get_field('ra_section_header');
$articles = get_field('ra_articles');	
?>
<a name="related-posts"></a>
<section id="related-posts" class="page-section col-grey">
	
	<div class="container">
		
		<div class="row">
			<div class="col-xs-6 col-xs-offset-3">
				<h3><?php echo $section_header; ?></h3>
			</div>
		</div>
		
		<div class="row related-posts-inner">
			<?php foreach ($articles as $article) { 
			$ra = $article['ra_article'];	
			?>
			<?php
			$post_thumbnail = get_post_thumbnail_id($ra);	
			if ($post_thumbnail) {
			$img = wp_get_attachment_image_src($post_thumbnail, 'feat-img'); 
			$bg_img = $img[0];	
			} else {
			$bg_img = get_bloginfo('stylesheet_directory'). "/_/css/img/sml-full-icon-white.svg";	
			}	
			//echo '<pre class="debug">';print_r($img);echo '</pre>';
			?>
				<div class="col-xs-4">
					<article class="related-post">
						<div class="post-img" style="background-image: url(<?php echo $bg_img; ?>)"></div>
						<a href="<?php echo get_permalink($ra); ?>" class="font-cond caps title-link"><?php echo get_the_title($ra); ?></a>
						<a href="<?php the_permalink(); ?>" class="grad-link"><span class="sr-only">View article</span></a>
						<time class="pub-date" datetime="<?php echo get_the_date('Y-m-d', $ra); ?>">
							<span class="month"><?php echo get_the_date('M', $ra); ?></span>
							<span class="day"><?php echo get_the_date('j', $ra); ?></span>
							<span class="year"><?php echo get_the_date('Y', $ra); ?></span>
						</time>
					</article>
				</div>
			<?php } ?>
		</div>
		
	</div>
	
</section>

<?php } ?>