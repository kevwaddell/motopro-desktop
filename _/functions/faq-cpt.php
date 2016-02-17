<?php 
add_action( 'init', 'register_cpt_mp_faq' );

function register_cpt_mp_faq() {

    $labels = array( 
        'name' => _x( 'FAQs', 'mp_faq' ),
        'singular_name' => _x( 'Question', 'mp_faq' ),
        'add_new' => _x( 'Add New', 'mp_faq' ),
        'add_new_item' => _x( 'Add New Question', 'mp_faq' ),
        'edit_item' => _x( 'Edit Question', 'mp_faq' ),
        'new_item' => _x( 'New Question', 'mp_faq' ),
        'view_item' => _x( 'View Question', 'mp_faq' ),
        'search_items' => _x( 'Search FAQs', 'mp_faq' ),
        'not_found' => _x( 'No faqs found', 'mp_faq' ),
        'not_found_in_trash' => _x( 'No faqs found in Trash', 'mp_faq' ),
        'parent_item_colon' => _x( 'Parent Question:', 'mp_faq' ),
        'menu_name' => _x( 'FAQs', 'mp_faq' ),
    );

    $args = array( 
        'labels' => $labels,
        'hierarchical' => true,
        'description' => 'MotoPro FAQs CPT.',
        'supports' => array( 'title' ),
        
        'public' => false,
        'show_ui' => true,
        'show_in_menu' => true,
        'menu_position' => 5,
        'menu_icon' => 'dashicons-editor-help',
        'show_in_nav_menus' => false,
        'publicly_queryable' => true,
        'exclude_from_search' => true,
        'has_archive' => false,
        'query_var' => true,
        'can_export' => true,
        'rewrite' => false,
        'capability_type' => 'page'
    );

    register_post_type( 'mp_faq', $args );
    
    remove_post_type_support( 'mp_faq', 'title' );
}
 ?>