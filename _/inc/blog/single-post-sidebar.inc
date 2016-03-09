<?php 
$post_thumbnail = get_post_thumbnail_id();	
$img = wp_get_attachment_image_src($post_thumbnail, 'feat-img');
$form_activated = get_field('form_activated');
$articles_active = get_field('ra_active');
$blog_links = false;	
if ( $form_activated || $articles_active) {
$blog_links = true;	
}
//echo '<pre class="debug">';print_r($img);echo '</pre>';
?>
<figure class="feat-img-round">
	<img src="<?php echo $img[0]; ?>" class="img-responsive" alt="<?php the_title_attribute('before=Image for post: '); ?>">
	<div class="star-icon"></div>	
</figure>
	
<?php if ($blog_links) { ?>
<div class="blog-links">
	<?php if ($form_activated) { ?>
	<a href="#request-a-callback" class="btn btn-block jump-to-link"><i class="fa fa-phone"></i>Contact us</a>
	<?php } ?>
	
	<?php if ($articles_active) { ?>
	<a href="#related-posts" class="btn btn-block jump-to-link"><i class="fa fa-chain"></i>Related posts</a>
	<?php } ?>
</div>
<?php } ?>

<div class="blog-selects">
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
		<option value="0" data-hidden="true">Categories</option>
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
		<option value="0" data-hidden="true">Archives</option>
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