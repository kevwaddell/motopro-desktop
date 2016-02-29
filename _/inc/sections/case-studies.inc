<?php 
$case_studies_args = array(
	'post_type'			=> 'mp_case_study_cpt',
	'posts_per_page'	=>	-1,
	'orderby'			=> 'title'
);

$case_studies = get_posts($case_studies_args);
//echo '<pre class="debug">';print_r($case_studies);echo '</pre>';	
?>
<?php if ($case_studies) { ?>
<div id="case-studies" class="scrollable">
	<div class="scrollable-inner">
		<dl class="case-studies">
	<?php foreach ($case_studies as $cs) { 
	$content = apply_filters('the_content', get_post_field( 'post_content', $cs->ID ));
	?>
			<dt class="caps font-cond"><?php echo get_the_title($cs->ID); ?></dt>
			<dd><?php echo $content; ?></dd>
	<?php } ?>
		</dl>
	</div>
</div>
<?php } ?>