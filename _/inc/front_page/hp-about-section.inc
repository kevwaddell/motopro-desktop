<?php 
$about_section_active = get_field('about_section_active', 'options'); 	
	
if ($about_section_active) { 
$hp_about_section = get_field('hp_about_section', 'options');	
$hp_about_links = get_field('hp_about_links', 'options');	
$links_total = count($hp_about_links);
?>


<section id="hp-about-section" class="text-center">
	<div class="container">
		
		<article class="about-entry">
		<?php echo $hp_about_section; ?>
		</article>
		
		<nav class="about-links">
		<?php if ($links_total > 0) { ?>
		<div class="row">
			
			<?php foreach ($hp_about_links as $l) { ?>
			<div class="col-xs-4">
				<a href="<?php echo get_permalink($l['page']); ?><?php echo ($l['internal_link']) ? '#'.$l['internal_link_id']: ''; ?>" class="btn btn-default btn-block">
					<i class="fa <?php echo $l['link_icon']; ?>"></i>
					<?php echo $l['link_title']; ?>
				</a>
			</div>
			<?php } ?>
			
		</div>
		<?php } ?>
		</nav>
		
	</div>
</section>

<?php } ?>