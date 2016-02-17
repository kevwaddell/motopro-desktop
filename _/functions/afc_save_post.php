<?php 
function my_acf_save_post( $post_id )
{
	global $current_screen;
	// vars	
	
	if ($current_screen->id == 'mp_faq') {
	wp_update_post( array( 'ID' => $post_id, 'post_title' => 'FAQ -'.$post_id, 'post_name' => 'faq-'.$post_id) );
	}
	
}
 
// run before ACF saves the $_POST['fields'] data
add_action('acf/save_post', 'my_acf_save_post', 1);
 ?>