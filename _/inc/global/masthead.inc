<?php if (is_front_page()) { ?>
<header id="hp-masthead" class="main-masthead">
	
	<div class="container">
		<div class="row">
			<div class="col-xs-6">
				<?php wp_nav_menu(array( 
				'container' => 'false', 
				'menu' => 'Social Links Menu', 
				'menu_class'  => 'clearfix list-unstyled',
				'fallback_cb' => false ) ); 
				?>
			</div>
			
			<div class="col-xs-5">
				<button id="search-btn" class="btn pull-right with-icon"><i class="fa fa-search"></i> Search</button>
			</div>
			
			<div class="col-xs-1">
				<button id="main-nav-btn" class="btn pull-right"><i class="fa fa-bars"></i><span class="sr-only">Main Navigation</span></button>	
			</div>
		</div>
	</div>

</header>

<?php } else { ?>
<?php 
$contact_page = get_page_by_path('contact-us');	
$blog_home = get_option('page_for_posts');
?>
<header id="masthead" class="main-masthead">
		
		<div class="top-bar">
		<div class="container">
			<div class="row">
				<div class="col-xs-3">
					<a href="tel:<?php freephone_no(1); ?>" class="contact-link tel-link"><i class="fa fa-phone"></i><?php freephone_no(); ?></a>
				</div>
				<div class="col-xs-3">
					<a href="mailto:<?php contact_email(); ?>" class="contact-link email-link"><i class="fa fa-envelope-o"></i><?php contact_email(); ?></a>
				</div>
				<div class="col-xs-6">
					<?php wp_nav_menu(array( 
					'container' => 'false', 
					'menu' => 'Social Links Menu', 
					'menu_class'  => 'clearfix list-unstyled pull-right',
					'fallback_cb' => false ) ); 
					?>
				</div>
			</div>
		</div>
		</div>
		
		<div class="logo-bar">
		<?php col_strip(); ?>
		<div class="container">
			<div class="row">
				<div class="col-xs-3">
					<a href="<?php echo get_option('home'); ?>/" id="tlw-masthead-logo"><span class="sr-only"><?php bloginfo('name'); ?> - <?php bloginfo('description'); ?></span></a>
				</div>
				
				<div class="col-xs-8">
					<a href="<?php echo get_permalink($blog_home); ?>" class="btn pull-right with-icon"><i class="fa fa-bullhorn"></i> Blog</a>
					<a href="<?php echo get_permalink($contact_page->ID); ?>" class="btn pull-right with-icon"><i class="fa fa-envelope-o"></i> Contact us</a>
					<button id="search-btn" class="btn pull-right with-icon"><i class="fa fa-search"></i> Search</button>
				</div>
				
				<div class="col-xs-1">
					<button id="main-nav-btn" class="btn pull-right"><i class="fa fa-bars"></i><span class="sr-only">Main Navigation</span></button>	
				</div>
			</div>
		</div>
		</div>
		
		<div class="breadcrumbs">
			<div class="container">
				<div id="breadcrumbs-inner">	
				<?php if(function_exists('bcn_display')) { bcn_display(); }?>
				</div>
			</div>
		</div>

</header>	
	
<?php } ?>
