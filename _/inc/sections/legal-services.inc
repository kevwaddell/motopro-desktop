<?php 
$section_title = get_field('ls_section_title', 'options'); 	
$section_bg_img = get_field('ls_section_bg_img', 'options');
$section_links = get_field('ls_section_links', 'options');
?>
<section id="legal-services-section" class="section-with-bg-img" style="background-image: url(<?php echo $section_bg_img; ?>)">
	<div class="overlay-dk"></div>
	<div class="container">
		<div class="row">
			<div class="col-xs-6 col-xs-offset-3">
				<h3><?php echo $section_title; ?></h3>
			</div>
		</div>
		<div class="section-links">
			<?php foreach ($section_links as $sl) { ?>
				<a href="<?php echo get_permalink($sl['link_page']); ?>"><i class="fa <?php echo $sl['link_icon']; ?>"></i><?php echo $sl['link_title']; ?></a>
			<?php } ?>
		</div>
	</div>
</section>