<?php 
$post_thumbnail = get_post_thumbnail_id();	
$img = wp_get_attachment_image_src($post_thumbnail, 'full');
$banner_title = get_field('banner_title');
$freephone_num = get_field('freephone_num', 'options');
$ooh_number = get_field('ooh_number', 'options');
$office_num = get_field('office_num', 'options');
$contact_email = get_field('contact_email', 'options');

//echo '<pre class="debug">';print_r($img);echo '</pre>';
?>
<figure class="feat-img-wide with-intro contact-links" style="background-image: url(<?php echo $img[0]; ?>)">
	<div class="img-overlay"></div><div class="star-icon"></div>
	<div class="container">
		<h1 class="font-cond caps"><?php echo $banner_title; ?></h1>
		<div class="intro"><?php the_content(); ?></div>
		
		<div class="row contact-info">
			<div class="col-xs-6"><a href="tel:<?php echo str_replace(" ", "", $freephone_num); ?>" class="contact-info-link"><i class="fa fa-phone"></i>Freephone: <?php echo $freephone_num; ?></a></div>
			<div class="col-xs-6"><a href="tel:<?php echo str_replace(" ", "", $ooh_number); ?>" class="contact-info-link"><i class="fa fa-clock-o"></i>Out of hours: <?php echo $ooh_number; ?></a></div>
			<div class="col-xs-6"><a href="tel:<?php echo str_replace(" ", "", $office_num); ?>" class="contact-info-link"><i class="fa fa-building-o"></i>Office: <?php echo $office_num; ?></a></div>
			<div class="col-xs-6"><a href="mailto:<?php echo $contact_email; ?>" class="contact-info-link"><i class="fa fa-envelope-o"></i><?php echo $contact_email; ?></a></div>
		</div>
	</div>		
</figure>