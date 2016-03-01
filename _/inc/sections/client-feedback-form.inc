<?php 
$form_activated = get_field('form_activated');

if ($form_activated) { 
$form = get_field('form');
?>		
<a name="request-a-callback"></a>
<section id="request-a-callback" class="section-with-form">
	
	<div class="container">
		<div class="row">
			<div class="col-xs-6 col-xs-offset-3">
				<h3>Send us your feedback</h3>
			</div>
		</div>
		
		<?php show_form($form->id); ?>
	</div>

</section>
<?php } ?>