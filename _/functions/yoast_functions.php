<?php 
if ( is_admin() ) { // check to make sure we aren't on the front end
	
	add_filter('wpseo_pre_analysis_post_content', 'add_custom_to_yoast');

	function add_custom_to_yoast( $content ) {
		global $post;
		$pid = $post->ID;
		$pg = get_page($pid);
		$custom_content = '';
		
		if ($post->post_name == 'feedback') {
			$feedback_args = array(
			'posts_per_page' => 4,
			'post_type'	=> 'mp_feedback_cpt'	
			);
			$feedback = get_posts($feedback_args);
			
			$custom_content .= "<h2>Client ".get_the_title($post->ID)."</h2>";
			
			if (!empty($feedback)) {
				
				foreach ($feedback as $fb) { 
				$custom_content .= '<div class="well text-center">';
				$custom_content .= $fb->post_content;
				$custom_content .= '</div>';
				}
			}
		}
		
		if ($post->post_name == 'case-studies') {
			$case_study_args = array(
			'posts_per_page' => 4,
			'post_type'	=> 'mp_case_study_cpt'	
			);
			$case_studies = get_posts($case_study_args);
			
			$custom_content .= "<h2>Case Summaries</h2>";
			
			if (!empty($case_studies)) {
				
				foreach ($case_studies as $cs) { 
				$custom_content .= '<div class="well">';
				$custom_content .= $cs->post_content;
				$custom_content .= '</div>';
				}
			}
		}
		
		return $content.' '.$custom_content;

		remove_filter('wpseo_pre_analysis_post_content', 'add_custom_to_yoast'); // don't let WP execute this twice
	}
} 
?>