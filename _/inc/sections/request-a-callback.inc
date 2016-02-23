<?php 
$form_activated = get_field('form_activated');

if ($form_activated) { 
$form = get_field('form');
?>		
<section id="request-a-callback" class="section-with-form">
	
	<div class="container">
		<div class="row">
			<div class="col-xs-6 col-xs-offset-3">
				<h3>Request a Callback</h3>
			</div>
		</div>
		
		<?php show_form($form->id); ?>
	</div>

</section>
<?php } ?>