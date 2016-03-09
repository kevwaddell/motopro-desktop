<?php
$newsletter_page = get_page_by_path('join-our-mailing-list');
?>

<div class="row blog-links">
	<div class="col-xs-6">
		<a href="<?php echo get_permalink($newsletter_page->ID) ?>" class="btn btn-block"><i class="fa fa-newspaper-o"></i>Sign up to our newsletter</a>
	</div>
	
	<div class="col-xs-6">
		<a href="<?php bloginfo('rss2_url'); ?>" class="btn btn-block"><i class="fa fa-rss"></i>Motopro blog feed</a>
	</div>
</div>		
<div class="row blog-selects">
	<div class="col-xs-6">
		<?php 
		$cats_args = array(
			'hide_empty'               => 1,
			'hierarchical'             => 0
		);
			
		$cats = get_categories($cats_args);
		
		//echo '<pre>';print_r($cats);echo '</pre>';
		?>
		<?php if ($cats) { ?>
		<select id="cats-dd" class="selectpicker" data-width="100%">
			<option value="0" data-hidden="true">Blog Categories</option>
			<?php foreach ($cats as $cat) { 
			$category_id = 	$cat->term_id;
			?>
			<option value="<?php echo get_category_link( $category_id ); ?>"><?php echo get_cat_name($category_id); ?></option>
			<?php } ?>
		</select>
			
		<script type="text/javascript">
			var cats_dropdown = document.getElementById("cats-dd");
			function onCatsChange() {
				if ( cats_dropdown.options[cats_dropdown.selectedIndex].value != 0 ) {
					location.href = cats_dropdown.options[cats_dropdown.selectedIndex].value;
				}
			}
			cats_dropdown.onchange = onCatsChange;
		</script>
		<?php } ?>
	</div>
	
	<div class="col-xs-6">
		<?php 
		$archives_args = array(
			'type'          => 'monthly',
			'limit'         => '6',
			'format'        => 'option',
			'echo'			=> 0
		);
			
		$archives = wp_get_archives($archives_args);
		
		//echo '<pre>';print_r($archives);echo '</pre>';
		?>
		<?php if ($archives) { ?>
			
		<select id="archive-dd" class="selectpicker" data-width="100%">
			<option value="0" data-hidden="true">Blog Archives</option>
			<?php echo $archives; ?>
		</select>
			
		<script type="text/javascript">
			var archive_dropdown = document.getElementById("archive-dd");
			function onArchiveChange() {
				if ( archive_dropdown.options[archive_dropdown.selectedIndex].value != 0 ) {
					location.href = archive_dropdown.options[archive_dropdown.selectedIndex].value;
				}
			}
			archive_dropdown.onchange = onArchiveChange;
		</script>
		<?php } ?>
	</div>

</div>