<?php 
/*
Template Name: Service page with Fee info section
*/
?>
<?php get_header(); ?>
<?php if ( have_posts() ): while ( have_posts() ) : the_post(); ?>	

<?php 
$sidebar_active = get_field('sb_active');	
$pg_sections = get_field('pg_sections');
$banner_title_active =	false;
$procedures_active = false;
$fees_info_active = false;
$fees_active = false;
$form_active = false;
$quote_active = false;

if (!empty($pg_sections) ) {
	//echo '<pre class="debug">';print_r($pg_sections);echo '</pre>';
	
	foreach ($pg_sections as $section) {
		
		switch ($section) {
			case "Banner title": $banner_title_active = true;	
			break;
			case "Fee Information": $fees_info_active = true;
			break;
			case "Legal Fees": $fees_active = true;
			break;
			case "Contact Form": $form_active = true;
			break;
			case "Client quote": $quote_active = true;
			break;
		}
		
	}
}
?>

<?php if ( has_post_thumbnail() ) { ?>
	<?php inc('featured-img', 'pages'); ?>
<?php } ?>

<!-- Container  -->
<div class="container">
	<article <?php post_class(); ?>>
		
		<div class="row">
			<div class="col-xs-6 col-xs-offset-3">
				<h2 class="font-cond caps text-center pg-tag"><?php the_title(); ?></h2>
			</div>
		</div>
		
		<?php if ($sidebar_active) { ?>
			<div class="row">
			
				<div class="col-xs-8">
					<div class="main-text">
						<?php the_content(); ?>
					</div>
				</div>
				
				<div class="col-xs-4">
					<?php get_template_part( 'parts/sidebar/sidebar', 'services' ); ?>	
				</div>
		
			</div>
		<?php } else { ?>
			<div class="main-text">
			<?php the_content(); ?>
			</div
		<?php } ?>
		
	</article>
</div>
<!-- Container end  -->

<?php if ($fees_info_active) { ?>
<?php inc('fee-information', 'sections'); ?>		
<?php } ?>

<?php if ($form_active) { ?>
<?php inc('request-a-callback', 'sections'); ?>		
<?php } ?>

<?php if ($fees_active) { ?>
<?php inc('legal-fees', 'sections'); ?>		
<?php } ?>

<?php if ($quote_active) { ?>
<?php inc('client-quote', 'sections'); ?>		
<?php } ?>

<?php endwhile; ?>
<?php endif; ?>

<?php get_footer(); ?>