<?php 
global $post;

$faqs_args = array(
	'post_type'			=> 'mp_faq',
	'posts_per_page'	=>	-1,
	'orderby'			=> 'ID',
	'order'				=> 'ASC',
	'meta_key'			=> 	'related',
	'meta_value' 		=> $post->ID
);

$faqs = get_posts($faqs_args);
//$faqs = true;
$section_title = "FAQs";
//echo '<pre class="debug">';print_r($faqs_args);echo '</pre>';	
?>
<?php if ($faqs) { ?>
<a name="faqs"></a>

<div id="faqs">
	
	<div class="container">
		
		<div class="row">
			<div class="col-xs-6 col-xs-offset-3">
				<h3><?php echo $section_title; ?></h3>
			</div>
		</div>

	
		<div class="faqs-inner scrollable">
		
				<div class="scrollable-inner">
				
					<dl class="faqs-list">
						<?php foreach ($faqs as $faq) { 
						$question = get_field('faq_question', $faq->ID);
						$answer = get_field('faq_answer', $faq->ID);
						///$related = get_field('related', $faq->ID);
						//echo '<pre class="debug">';print_r($related);echo '</pre>';
						?>
						<dt class="caps font-cond"><?php echo $question; ?></dt>
						<dd><?php echo $answer; ?></dd>
						<?php } ?>
			
					</dl>
				
				</div>
		
		</div>
			
	</div>

</div>
<?php } ?>