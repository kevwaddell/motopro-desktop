<?php 
$post_thumbnail = get_post_thumbnail_id();	
$img = wp_get_attachment_image_src($post_thumbnail, 'wide-banner-img');
$banner_title = get_field('banner_title');
//echo '<pre class="debug">';print_r($img);echo '</pre>';
?>
<figure class="feat-img-wide" style="background-image: url(<?php echo $img[0]; ?>)">
	<div class="img-overlay"></div><div class="star-icon"></div>
	<div class="container">
		<h1 class="font-cond caps"><?php echo $banner_title; ?></h1>
	</div>
</figure>