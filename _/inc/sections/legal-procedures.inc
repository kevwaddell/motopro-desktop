<?php 
$procedures = get_field('ml_legal_procedures', 'options');
//$faqs = true;
$section_title = "Legal Procedures";
//echo '<pre class="debug">';print_r($procedures);echo '</pre>';	
?>
<?php if ($procedures) { ?>
<a name="legal-procedures"></a>
<div id="legal-procedures">
	
	<div class="container">
		
		<div class="row">
			<div class="col-xs-6 col-xs-offset-3">
				<h3><?php echo $section_title; ?></h3>
			</div>
		</div>

	
		<div class="legal-procedures-inner scrollable">
		
				<div class="scrollable-inner">
				
					<ul class="legal-procedures-list list-unstyled">
						<?php foreach ($procedures as $lp) { 
						$title = $lp['ml_procedure_title'];
						$icon = $lp['ml_procedure_icon'];
						$content = $lp['ml_procedure_content'];
						$fee = $lp['ml_procedure_fee'];
						///$related = get_field('related', $faq->ID);
						//echo '<pre class="debug">';print_r($related);echo '</pre>';
						?>
						<li class="legal-procedure-item">
							<div class="row">
								<div class="col-xs-1 icon"><i class="fa fa-gavel"></i></div>
								<div class="col-xs-10">
									<div class="title caps font-cond"><?php echo $title; ?></div>
									<div class="lp-txt">
										<?php echo $content; ?>
									</div>
									<div class="fee font-cond">Fee: <span class="col-red">&pound;<?php echo $fee; ?></span></div>
								</div>
							</div>
						</li>
						<?php } ?>
			
					</ul>
				
				</div>
		
		</div>
			
	</div>

</div>
<?php } ?>