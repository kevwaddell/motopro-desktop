<?php 
$section_title = get_field('lf_section_title', 'options'); 	
$section_bg_img = get_field('lf_section_bg_img', 'options');
$section_fees_list = get_field('lf_fees_list', 'options');
$section_extra_info = get_field('lf_extra_info', 'options');
?>
<section id="legal-fees-section" class="section-with-bg-img" style="background-image: url(<?php echo $section_bg_img; ?>)">
	<div class="overlay-dk"></div>
	<div class="container">
		<div class="row">
			<div class="col-xs-6 col-xs-offset-3">
				<h3><?php echo $section_title; ?></h3>
			</div>
		</div>
		<dl class="fees-list">
			<?php foreach ($section_fees_list as $fl) { ?>
				<dt><?php echo $fl['procedure']; ?></dt>
				<dd>&pound;<?php echo $fl['fee']; ?></dd>
			<?php } ?>
		</dl>
		
		<div class="extra-info">
			<?php echo $section_extra_info ; ?>
		</div>
	</div>
</section>