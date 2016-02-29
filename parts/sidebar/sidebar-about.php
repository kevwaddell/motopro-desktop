<?php 
$pg_sb_items = get_field('pg_sb_items');
$related_pgs = false;
$jump2menu = false;

if (!empty($pg_sb_items)) {
	
	if (in_array("Related pages", $pg_sb_items)) {
	$sb_related_pages = get_field('sb_related_pages');	
	$related_pgs = true;
	}
	
	if (in_array("Jump to menu", $pg_sb_items)) {
	global $jump2menu_items;
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
			<li class="header">Jump to</li>
			
			<?php foreach ($jump2menu_items as $item) { ?>
			<li><a href="#<?php echo $item['id'] ?>"><?php echo $item['title'] ?></a></li>
			<?php } ?>
			
		</ul>
	<?php } ?>
	
	
</aside>