<?php
$contact_email = get_field('contact_email', 'options');	
$contact_page = get_page_by_path('contact-us');
//echo '<pre class="debug">';print_r($contact_page);echo '</pre>';
?>
<nav id="main-nav" class="nav-closed">
	
	<div class="container">
		<div class="nav-top-bar">
			<div class="row">
				<div class="col-xs-11">
					<ul class="list-unstyled nav-bar-links">
						<li><a href="<?php echo get_option('home'); ?>/"><i class="fa fa-home"></i><span class="sr-only">Home</span></a></li>
						<li><a href="mailto:<?php echo $contact_email; ?>"><i class="fa fa-envelope-o"></i><span class="sr-only"><?php echo $contact_email; ?></span></a></li>
						<li><a href="<?php echo get_permalink($contact_page->ID); ?>#find-us"><i class="fa fa-map-marker"></i><span class="sr-only">Find us</span></a></li>
					</ul>
				</div>
				<div class="col-xs-1">
					<button id="close-nav" class="btn"><i class="fa fa-close"></i><span class="sr-only">Close</span></button>
				</div>
			</div>
		</div>
		<div class="nav-wrapper">
			<?php wp_nav_menu(array( 
			'container' => 'false', 
			'menu' => 'Main Menu', 
			'menu_class'  => 'menu clearfix list-unstyled',
			'fallback_cb' => false ) ); 
			?>
		</div>
	</div>
	
	<?php col_strip();  ?>
</nav>