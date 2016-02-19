<footer class="footer-info">
	
	<div class="container">
		
		<div class="row">
			<div class="col-xs-3">
				<?php wp_nav_menu(array( 
				'container' => 'false', 
				'menu' => 'Footer Service Links', 
				'menu_class'  => 'footer-links list-unstyled',
				'fallback_cb' => false ) ); 
				?>
				
				<?php wp_nav_menu(array( 
				'container' => 'false', 
				'menu' => 'Footer Company Links', 
				'menu_class'  => 'footer-links list-unstyled',
				'fallback_cb' => false ) ); 
				?>
			</div>
			<div class="col-xs-3">
				<?php wp_nav_menu(array( 
				'container' => 'false', 
				'menu' => 'General Footer Links', 
				'menu_class'  => 'footer-links list-unstyled',
				'fallback_cb' => false ) ); 
				?>
				
				<?php wp_nav_menu(array( 
				'container' => 'false', 
				'menu' => 'Footer Blog Links', 
				'menu_class'  => 'footer-links list-unstyled',
				'fallback_cb' => false ) ); 
				?>
			</div>
			<div class="col-xs-3">
				<?php wp_nav_menu(array( 
				'container' => 'false', 
				'menu' => 'Footer Motoring Offences Links', 
				'menu_class'  => 'footer-links list-unstyled',
				'fallback_cb' => false ) ); 
				?>
			</div>
			<div class="col-xs-3">
				<?php wp_nav_menu(array( 
				'container' => 'false', 
				'menu_id'	=> 'footer-social-links',
				'menu' => 'Social Links Menu', 
				'menu_class'  => 'list-unstyled pull-right',
				'fallback_cb' => false ) ); 
				?>
				
				<div class="mp-footer-logo clearfix">
					
				</div>
				<?php $standards_notice = get_field('standards_notice', 'option');?>
				
				<?php if (isset($standards_notice)) { ?>			 		
				<div class="compliance-notice">
					<?php echo $standards_notice; ?>
				</div>
				<?php }  ?>
			</div>
		</div>
		
		<hr />
		
		<div class="row">
			<div class="col-xs-6"><?php $copyright = get_field('copyright_notice', 'option');?>	
				<?php if (isset($copyright)) { ?>
				<div class="copyright-notice">
					&copy; <?php bloginfo( 'name' ); ?> <?php echo date("Y"); ?> <?php echo $copyright; ?>
				</div>
				<?php }  ?>
			</div>
			<div class="col-xs-6">
				<?php wp_nav_menu(array( 
				'container' => 'false', 
				'menu' => 'Footer Legal Links', 
				'menu_class'  => 'list-unstyled pull-right',
				'fallback_cb' => false ) ); 
				?>
			</div>
		</div>
		
	</div>
			
</footer>