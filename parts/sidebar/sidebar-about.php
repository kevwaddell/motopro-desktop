<?php 
$pg_sb_items = get_field('pg_sb_items');
$related_pgs = false;

if (!empty($pg_sb_items)) {
	
	if (in_array("Related pages", $pg_sb_items)) {
	$sb_related_pages = get_field('sb_related_pages');	
	$related_pgs = true;
	}
	
	if (in_array("Jump to menu", $pg_sb_items)) {
	$sb_jump_menu_title = get_field('sb_jump_menu_title');
	$sb_jump_menu_items = get_field('sb_jump_menu_items');
	$jump2menu = true;	
	}
}

?>
<aside class="pg-sidebar">
	
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