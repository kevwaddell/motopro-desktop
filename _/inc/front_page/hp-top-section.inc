<?php 
$contact_page = get_page_by_path('contact-us');	
$blog_home = get_option('page_for_posts');
$presentation_download = get_field('global_presentation_download', 'options');
?>
<section id="hp-top-section">
	<video autoplay loop poster="<?php echo get_stylesheet_directory_uri(); ?>/_/css/img/video-poster-img.png" id="bgvid">
		<source src="<?php echo get_stylesheet_directory_uri(); ?>/_/video/motopro_video_webm.webm" type="video/webm">
		<source src="<?php echo get_stylesheet_directory_uri(); ?>/_/video/motopro_video_mp4.mp4" type="video/mp4">
	</video>
	
	<div class="hp-top-intro">
		
		<div class="container">
			<article class="hp-entry">
				
				<div class="row">
					<div class="col-xs-6"><a href="<?php freephone_no(1); ?>" class="btn btn-default btn-block tel-num"><i class="fa fa-phone"></i><?php freephone_no(); ?></a></div>
					<div class="col-xs-6"><a href="mailto:<?php contact_email(); ?>" class="btn btn-default btn-block"><i class="fa fa-envelope-o"></i><?php contact_email(); ?></a></div>
				</div>
				
				<div class="hp-top-txt text-center">
					<div class="hp-logo"></div>
					<h1><?php the_title(); ?></h1>
					<?php the_content(); ?>
				</div>
				
			</article>
			
		</div>
	</div>
	
	<?php col_strip('b'); ?>
	
	<div class="hp-top-col-links text-center">
		<div class="container">
			<div class="row">
				<div class="col-xs-4">
					<a href="<?php echo get_permalink($contact_page->ID) ?>" class="hp-col-link link-green"><i class="fa fa-comments"></i>Contact us today for free advice</a>
				</div>
				<div class="col-xs-4">
					<a href="<?php echo get_permalink($blog_home) ?>" class="hp-col-link link-blue"><i class="fa fa-rss"></i>Latest motopro News and updates</a>
				</div>
				<div class="col-xs-4">
					<a href="<?php echo $presentation_download; ?>" class="hp-col-link link-orange" target="_blank"><i class="fa fa-download"></i>Download our presentation</a>
				</div>
			</div>
		</div>
	</div>	
</section>