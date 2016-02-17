<?php 
add_action( 'init', 'register_cpt_mp_package_option' );

function register_cpt_mp_package_option() {

    $labels = array( 
        'name' => _x( 'Package options', 'mp_package_option' ),
        'singular_name' => _x( 'Package option', 'mp_package_option' ),
        'add_new' => _x( 'Add New', 'mp_package_option' ),
        'add_new_item' => _x( 'Add New Package option', 'mp_package_option' ),
        'edit_item' => _x( 'Edit Package option', 'mp_package_option' ),
        'new_item' => _x( 'New Package option', 'mp_package_option' ),
        'view_item' => _x( 'View Package option', 'mp_package_option' ),
        'search_items' => _x( 'Search Package options', 'mp_package_option' ),
        'not_found' => _x( 'No package options found', 'mp_package_option' ),
        'not_found_in_trash' => _x( 'No package options found in Trash', 'mp_package_option' ),
        'parent_item_colon' => _x( 'Parent Package option:', 'mp_package_option' ),
        'menu_name' => _x( 'Package options', 'mp_package_option' ),
    );

    $args = array( 
        'labels' => $labels,
        'hierarchical' => true,
        'description' => 'MotoPro Package Options CPT.',
        'supports' => array( 'title' ),
        
        'public' => false,
        'show_ui' => true,
        'show_in_menu' => true,
        'menu_position' => 5,
        'menu_icon' => 'dashicons-archive',
        'show_in_nav_menus' => false,
        'publicly_queryable' => true,
        'exclude_from_search' => true,
        'has_archive' => false,
        'query_var' => true,
        'can_export' => true,
        'rewrite' => false,
        'capability_type' => 'page'
    );

    register_post_type( 'mp_package_option', $args );
}
 ?>