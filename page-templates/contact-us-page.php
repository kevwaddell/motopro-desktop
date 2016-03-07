<?php 
/*
Template Name: Contact us page
*/
?>
<?php get_header(); ?>

<?php if ( have_posts() ): while ( have_posts() ) : the_post(); ?>	

<?php 
$pg_sections = get_field('pg_sections');
$banner_title_active =	false;
$form_active = false;
$map_active = false;

if (!empty($pg_sections) ) {
	//echo '<pre class="debug">';print_r($pg_sections);echo '</pre>';
	
	foreach ($pg_sections as $section) {
		
		switch ($section) {
			case "Banner title": $banner_title_active = true;	
			break;
			case "Contact Form": $form_active = true;
			break;
			case "Location Map": $map_active = true;
			break;
		}
		
	}
}
?>

<?php if ( has_post_thumbnail() && $banner_title_active ) { ?>
	<?php inc('contact-us-intro', 'pages'); ?>
<?php } ?>

<?php if ($form_active) { ?>
<?php inc('contact-us-form', 'sections'); ?>		
<?php } ?>

<?php if ($map_active) { ?>
<?php inc('location-map', 'sections'); ?>
<?php } ?>

<?php endwhile; ?>
<?php endif; ?>

<?php get_footer(); ?>
