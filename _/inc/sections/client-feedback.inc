<?php 
$feedback_args = array(
	'post_type'			=> 'mp_feedback_cpt',
	'posts_per_page'	=>	-1,
	'orderby'			=> 'date'
);

$feedback = get_posts($feedback_args);
//echo '<pre class="debug">';print_r($case_studies);echo '</pre>';	
?>
<?php if ($feedback) { ?>
<div id="client-feedback" class="scrollable">
	<div class="scrollable-inner">
		<ul class="list-unstyled">
	<?php foreach ($feedback as $fb) { 
	$content = apply_filters('the_content', get_post_field( 'post_content', $fb->ID ));
	?>
			<li><?php echo $content; ?></li>
	<?php } ?>
		</ul>
	</div>
</div>
<?php } ?>