<?php 
/*
Template Name: Case Studies page
*/
?>
<?php get_header(); ?>

<?php if ( have_posts() ): while ( have_posts() ) : the_post(); ?>	

<?php 
$pg_sections = get_field('pg_sections');
$banner_title_active =	false;
$our_team_active = false;
$form_active = false;
$quote_active = false;
$jump2menu_items = array();

if (!empty($pg_sections) ) {
	//echo '<pre class="debug">';print_r($pg_sections);echo '</pre>';
	
	foreach ($pg_sections as $section) {
		if ($section == "Banner title") {
		$banner_title_active = true;	
		}
		
		if ($section == "Contact Form") {
		$form_active = true;	
		$title = "Request a Callback";
		array_push($jump2menu_items, array('title' => $title, 'id' => sanitize_title($title) ) );
		}
		
		if ($section == "Client quote") {
		$quote_active = true;	
		array_push($jump2menu_items, array('title' => $section, 'id' => sanitize_title($section) ) );
		}	
		
	}
}
?>

<?php if ( has_post_thumbnail() ) { ?>
	<?php inc('featured-img-intro', 'pages'); ?>
<?php } ?>

<!-- Container  -->
<div class="container">
	<article <?php post_class(); ?>>
		
		<div class="row">
			<div class="col-xs-6 col-xs-offset-3">
				<h2 class="font-cond caps text-center pg-tag"><?php the_title(); ?></h2>
			</div>
		</div>
		
		<?php inc('case-studies', 'sections'); ?>		
		
	</article>
</div>
<!-- Container end  -->

<?php if ($form_active) { ?>
<?php inc('request-a-callback', 'sections'); ?>		
<?php } ?>

<?php if ($quote_active) { ?>
<?php inc('client-quote', 'sections'); ?>		
<?php } ?>

<?php endwhile; ?>
<?php endif; ?>

<?php get_footer(); ?>