<?php
$client_fb_args = array(
	'post_type' 		=> 'mp_feedback_cpt',
	'posts_per_page'	=> 1,
	'orderby'			=> 'rand',
	'meta_query' => array(
   	 array(
        'key' => 'fb_client_quote',
        'value'   => array(''),
        'compare' => 'NOT IN'
		)
	)
);
$client_fb = get_posts($client_fb_args);	

$client_quote = get_field('fb_client_quote', $client_fb[0]->ID);

if ($client_fb) {	
?>
<a name="client-quote"></a>
<section id="client-quote" class="fw-quote">
	<div class="container">
		<div class="row">
			<div class="col-xs-1">
				<i class="fa fa-quote-left quote-icon"></i>
			</div>
			
			<div class="col-xs-10 quote-text">
				<?php echo $client_quote; ?>
			</div>
			
			<div class="col-xs-1">
				<i class="fa fa-quote-right quote-icon"></i>
			</div>
		</div>
	</div>
</section>
			
<?php } ?>