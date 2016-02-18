<?php head_html();  ?>

<body <?php body_class(); ?>>
<?php if ($_SERVER['SERVER_NAME']=='www.motoprolegal.co.uk') { 
$google_code_active = get_field('google_code_active', 'options');
?>
	<?php if ($google_code_active) { 
	$google_code = get_field('google_code', 'options');	
	?>
	<?php echo $google_code; ?>
	<?php } ?>
<?php } ?>

<?php main_nav();  ?>

<div class="mp-wrapper">

	<div class="content">
