<?php 
$section_title = get_field('mo_section_title', 'options'); 	
$section_bg_img = get_field('mo_section_bg_img', 'options');
$section_links = get_field('mo_offences', 'options');
$links_total = count($section_links);
//echo '<pre>';print_r($links_total % 2);echo '</pre>';
?>
<a name="types-of-motoring-offence"></a>
<section id="types-of-motoring-offence" class="section-with-bg-img" style="background-image: url(<?php echo $section_bg_img; ?>)">
	<div class="overlay-dk"></div>
	<div class="container">
		<div class="row">
			<div class="col-xs-6 col-xs-offset-3">
				<h3><?php echo $section_title; ?></h3>
			</div>
		</div>
		<div class="section-links">
			<?php if ($links_total % 2 == 0) { ?>
				<div class="row">
			<?php } ?>
			
			<?php foreach ($section_links as $sl) { ?>
			
			<?php if ($links_total % 2 == 0) { ?>
					<div class="col-xs-6">
			<?php } ?>
						<a href="<?php echo get_permalink($sl['mo_offence']); ?>"><?php echo get_the_title($sl['mo_offence']); ?></a>
			
			<?php if ($links_total % 2 == 0) { ?>
					</div>
			<?php } ?>
			
			<?php } ?>
			
			<?php if ($links_total % 2 == 0) { ?>
				</div>
			<?php } ?>
		</div>
	</div>
</section>