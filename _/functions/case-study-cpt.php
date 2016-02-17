<?php 
	
add_action( 'init', 'register_cpt_mp_case_study_cpt' );

function register_cpt_mp_case_study_cpt() {

    $labels = array( 
        'name' => _x( 'Case studies', 'mp_case_study_cpt' ),
        'singular_name' => _x( 'Case study', 'mp_case_study_cpt' ),
        'add_new' => _x( 'Add New', 'mp_case_study_cpt' ),
        'add_new_item' => _x( 'Add New Case study', 'mp_case_study_cpt' ),
        'edit_item' => _x( 'Edit Case study', 'mp_case_study_cpt' ),
        'new_item' => _x( 'New Case study', 'mp_case_study_cpt' ),
        'view_item' => _x( 'View Case study', 'mp_case_study_cpt' ),
        'search_items' => _x( 'Search Case studies', 'mp_case_study_cpt' ),
        'not_found' => _x( 'No case studies found', 'mp_case_study_cpt' ),
        'not_found_in_trash' => _x( 'No case studies found in Trash', 'mp_case_study_cpt' ),
        'parent_item_colon' => _x( 'Parent Case study:', 'mp_case_study_cpt' ),
        'menu_name' => _x( 'Case studies', 'mp_case_study_cpt' ),
    );

    $args = array( 
        'labels' => $labels,
        'hierarchical' => false,
        'description' => 'MotoPro Case study CPT.',
        'supports' => array( 'title', 'editor' ),
        
        'public' => true,
        'show_ui' => true,
        'show_in_menu' => true,
        'menu_position' => 5,
        'menu_icon' => 'dashicons-id',
        'show_in_nav_menus' => false,
        'publicly_queryable' => true,
        'exclude_from_search' => false,
        'has_archive' => true,
        'query_var' => 'case-study',
        'can_export' => true,
        'rewrite' => array( 
            'slug' => 'case-studies', 
            'with_front' => false,
            'feeds' => false,
            'pages' => true
        ),
        'capability_type' => 'post'
    );

    register_post_type( 'mp_case_study_cpt', $args );
}
	
?>