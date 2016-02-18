<nav id="main-nav" class="nav-closed">
	<div class="container">
		<button id="close-nav" class="btn"><i class="fa fa-close"></i></button>
		<div class="nav-wrapper">
			<?php wp_nav_menu(array( 
			'container' => 'false', 
			'menu' => 'Main Menu', 
			'menu_class'  => 'menu clearfix list-unstyled',
			'fallback_cb' => false ) ); 
			?>
		</div>
	</div>
</nav>