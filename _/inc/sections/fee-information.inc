<?php 
global $post;
$section_title = get_field('fi_section_title', $post->ID);
$fee_list = get_field('fi_info_list', $post->ID);
$price = get_field('fi_price', $post->ID);
$extra_info = get_field('fi_extra_info', $post->ID);
//echo '<pre class="debug">';print_r($procedures);echo '</pre>';	
?>
<a name="fee-information"></a>
<div id="fee-information">
	
	<div class="container">
		
		<div class="row">
			<div class="col-xs-6 col-xs-offset-3">
				<h3><?php echo $section_title; ?></h3>
			</div>
		</div>

		<div class="fee-information-inner">
			<div class="row">
				<?php if ($fee_list) { ?>
				<div class="col-xs-8 fee-info-list">
					<span class="list-header bold">Fees will include:</span>
					<ul class="list-unstyled checklist">
						<?php foreach ($fee_list as $fl) { ?>
						<li><?php echo $fl['fee_item']; ?></li>
						<?php } ?>
					</ul>
				</div>
				<?php } ?>
				
				<?php if (!empty($price)) { ?>
				<div class="col-xs-4 fee-info-price">
					<div class="fee-lable caps font-cond text-center">fixed fee</div>
					<div class="price">
						<span class="text-center block font-cond">&pound;<?php echo $price; ?></span>
						<small class="caps block text-center">+VAT</small>
					</div>
				</div>
				<?php } ?>
				
			</div>	
			<?php if (!empty($extra_info)) { ?>
			<div class="extra-fee-info text-center bold">
				<?php echo $extra_info; ?>
			</div>		
			<?php } ?>

		</div>
			
	</div>

</div>