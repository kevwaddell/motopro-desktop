<?php 
	
add_action( 'init', 'register_cpt_mp_feedback_cpt' );

function register_cpt_mp_feedback_cpt() {

    $labels = array( 
        'name' => _x( 'Testimonials', 'mp_feedback_cpt' ),
        'singular_name' => _x( 'Feedback', 'mp_feedback_cpt' ),
        'add_new' => _x( 'Add New', 'mp_feedback_cpt' ),
        'add_new_item' => _x( 'Add New Feedback', 'mp_feedback_cpt' ),
        'edit_item' => _x( 'Edit Feedback', 'mp_feedback_cpt' ),
        'new_item' => _x( 'New Feedback', 'mp_feedback_cpt' ),
        'view_item' => _x( 'View Feedback', 'mp_feedback_cpt' ),
        'search_items' => _x( 'Search Testimonials', 'mp_feedback_cpt' ),
        'not_found' => _x( 'No testimonials found', 'mp_feedback_cpt' ),
        'not_found_in_trash' => _x( 'No testimonials found in Trash', 'mp_feedback_cpt' ),
        'parent_item_colon' => _x( 'Parent Feedback:', 'mp_feedback_cpt' ),
        'menu_name' => _x( 'Testimonials', 'mp_feedback_cpt' ),
    );

    $args = array( 
        'labels' => $labels,
        'hierarchical' => false,
        'description' => 'MotoPro Client Feedback CPT.',
        'supports' => array( 'title', 'editor' ),
        
        'public' => true,
        'show_ui' => true,
        'show_in_menu' => true,
        'menu_position' => 5,
        'menu_icon' => 'dashicons-editor-quote',
        'show_in_nav_menus' => false,
        'publicly_queryable' => true,
        'exclude_from_search' => true,
        'has_archive' => true,
        'query_var' => true,
        'can_export' => true,
        'rewrite' => array( 
            'slug' => 'feedback', 
            'with_front' => false,
            'feeds' => false,
            'pages' => true
        ),
        'capability_type' => 'post'
    );

    register_post_type( 'mp_feedback_cpt', $args );
}
	
?>