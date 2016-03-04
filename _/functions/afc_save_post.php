<?php 
function my_acf_save_post( $post_id )
{
	global $current_screen;
	// vars	
	//echo "<pre>"; print_r($current_screen); echo "</pre>";
	
	if ($current_screen->id == 'mp_faq') {
	wp_update_post( array( 'ID' => $post_id, 'post_title' => 'FAQ - '.$post_id, 'post_name' => 'faq-'.$post_id) );
	}
	
	if ($current_screen->id == 'mp_feedback_cpt') {
	 
	 $value = get_field('fb_client_name');
	 
	 wp_update_post( array( 'ID' => $post_id, 'post_title' => $value,'post_name' => 'feedback-'.$post_id) );
	}
	
	if ($current_screen->id == 'mp_case_study_cpt') {
	 
	 $value = get_field('cs_title');
	 
	 wp_update_post( array( 'ID' => $post_id, 'post_title' => $value,'post_name' => 'casestudy-'.$post_id) );
	}
	
}
 
// run before ACF saves the $_POST['fields'] data
add_action('acf/save_post', 'my_acf_save_post', 20);
 ?>