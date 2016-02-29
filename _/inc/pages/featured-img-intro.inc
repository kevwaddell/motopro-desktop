<?php 
$post_thumbnail = get_post_thumbnail_id();	
$img = wp_get_attachment_image_src($post_thumbnail, 'full');
global $banner_title_active;
//echo '<pre class="debug">';print_r($img);echo '</pre>';
?>
<figure class="feat-img-wide with-intro" style="background-image: url(<?php echo $img[0]; ?>)">
	<div class="img-overlay"></div><div class="star-icon"></div>
	<?php if ($banner_title_active) { 
	$banner_title = get_field('banner_title');	
	?>
		<div class="container">
			<h1 class="font-cond caps"><?php echo $banner_title; ?></h1>
			<div class="intro"><?php the_content(); ?></div>
		</div>		
	<?php } ?>
</figure>