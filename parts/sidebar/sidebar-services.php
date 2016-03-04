<?php 
$pg_sb_items = get_field('pg_sb_items');
$sb_menu_pgs = false;
$related_pgs = false;
$jump2menu = false;

//echo '<pre>';print_r($pg_sb_items);echo '</pre>';

if (!empty($pg_sb_items)) {
	
	if (in_array("Pop up menu", $pg_sb_items)) {
	$sb_menu_btn_title = get_field('sb_menu_btn_title');	
	$sb_menu_pages = get_field('sb_menu_pages');
	$sb_menu_pgs = true;
	}
	
	if (in_array("Related pages", $pg_sb_items)) {
	$sb_related_pages = get_field('sb_related_pages');	
	$related_pgs = true;
	}
	
	if (in_array("Jump to menu", $pg_sb_items)) {
	$sb_jump_menu_title = get_field('sb_jump_menu_title');
	$sb_jump_menu_items = get_field('sb_jump_menu_items');
	//echo '<pre class="debug">';print_r($sb_jump_menu_items);echo '</pre>';
	$jump2menu = true;	
	}
}

?>
<aside class="pg-sidebar">
	
	<?php if ($sb_menu_pgs) { ?>
		<button id="sb-menu-pages-btn" class="btn btn-block sb-menu-btn" data-toggle="modal" data-target="#sb-menu-pgs-modal"><i class="fa fa-bars"></i><?php echo $sb_menu_btn_title; ?></button>
		
		<div class="modal fade" id="sb-menu-pgs-modal" tabindex="-1" role="dialog">
			<div class="modal-dialog modal-lg">	
			  
			  <button type="button" class="btn btn-default close-btn" data-dismiss="modal"><i class="fa fa-close"></i><span class="sr-only">Close</span></button>
		      
		      <div class="modal-body">
			      <?php foreach ($sb_menu_pages as $menu_pg) { ?>
			      	<a href="<?php echo get_permalink($menu_pg['sb_page']); ?>" class="btn btn-default btn-block btn-link"><?php echo $menu_pg['sb_pg_icon']; ?><?php echo get_the_title($menu_pg['sb_page']); ?></a>
			      <?php } ?>
		      </div>
		      
			</div><!-- /.modal-dialog -->
		</div><!-- /.modal -->
	<?php } ?>
	
	<?php if ($related_pgs) { ?>
		<ul class="list-unstyled sb-links-red">
			<?php foreach ($sb_related_pages as $p) { 
			$page = get_page($p['rel_page']);
			$icon = $p['link_icon'];
			?>
			<li><a href="<?php echo get_permalink($p['rel_page']); ?>"><?php echo($icon) ? $icon : ''; ?><?php echo $page->post_title; ?></a></li>
			<?php } ?>
		</ul>	
	<?php } ?>
	
	<?php if ($jump2menu) { ?>
		<ul class="list-unstyled sb-jump2-links">
			<li class="header"><?php echo $sb_jump_menu_title; ?></li>
			
			<?php foreach ($sb_jump_menu_items as $item) { 
			$item = $item['menu_item'];
				if ($item === "Contact Form") {
				$item = "Request a Callback";	
				}
			$id = sanitize_title($item);
			?>
			<li><a href="#<?php echo $id ?>"><?php echo $item; ?></a></li>
			<?php } ?>
			
		</ul>
	<?php } ?>
	
	
</aside>