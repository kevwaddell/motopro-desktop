<?php 
$form_activated = get_field('form_activated');

if ($form_activated) { 
$form = get_field('form');
?>		
<a name="client-feedback-form"></a>
<section id="client-feedback-form" class="section-with-form">
	
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