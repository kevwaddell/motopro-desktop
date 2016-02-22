<?php 

function motopro_scripts() {
//Stylesheets
wp_enqueue_style('mp-select-styles', 'https://cdnjs.cloudflare.com/ajax/libs/bootstrap-select/1.9.4/css/bootstrap-select.min.css', null, '1.9.4', 'screen' );
wp_enqueue_style('mp-styles', get_stylesheet_directory_uri().'/_/css/styles.css', null, filemtime( get_stylesheet_directory_uri().'/_/css/styles.css'), 'screen' );
wp_enqueue_style('mp-print-styles', get_stylesheet_directory_uri().'/_/css/print-styles.css', null, filemtime( get_stylesheet_directory_uri().'/_/css/print-styles.css'), 'print' );
//Scripts
wp_enqueue_script('mp-jquery-easing', 'https://cdnjs.cloudflare.com/ajax/libs/jquery-easing/1.3/jquery.easing.min.js', array('jquery'), '1.3', true);
wp_enqueue_script('mp-slim-scroll', 'https://cdnjs.cloudflare.com/ajax/libs/jQuery-slimScroll/1.3.7/jquery.slimscroll.min.js', array('jquery'), '1.3.7', true);
wp_enqueue_script('mp-bootstrap-select', 'https://cdnjs.cloudflare.com/ajax/libs/bootstrap-select/1.9.4/js/bootstrap-select.min.js', array('jquery', 'bootstrap-all-min'), '1.9.4', true);
wp_enqueue_script( 'mp-functions', get_stylesheet_directory_uri() . '/_/js/scripts.js', array('jquery', 'bootstrap-all-min', 'mp-bootstrap-select','mp-slim-scroll'), '1.0.0', true );
}

add_action('wp_enqueue_scripts', 'motopro_scripts');

/*  PACKAGE OPTIONS CPT */
//include (STYLESHEETPATH . '/_/functions/package-options-cpt.php');

/*  FAQ CPT */
include (STYLESHEETPATH . '/_/functions/faq-cpt.php');

/*  CASES TUDY CPT */
include (STYLESHEETPATH . '/_/functions/case-study-cpt.php');

/*  FEEDBACK CPT */
include (STYLESHEETPATH . '/_/functions/feedback-cpt.php');

/* AFC SAVE POST FUNCTION */
include (STYLESHEETPATH . '/_/functions/afc_save_post.php');

/* SEND NEWSLETTER TO DOTMAILER */
include (STYLESHEETPATH . '/_/functions/submit_newsletter.php');

/* YOAST FUNCTIONS */
include (STYLESHEETPATH . '/_/functions/yoast_functions.php');


function editor_styles() {
	add_editor_style(get_stylesheet_directory_uri().'/_/css/custom-editor-style.css');	
}

add_action( 'after_setup_theme', 'editor_styles' );

add_theme_support('html5', array('search-form'));
		
register_nav_menus (
	array(
	  'social_links_menu' => 'Social Links',
	  'footer_services' => 'Footer Services Links',
	  'footer_company_info' => 'Footer Company Links',
	  'footer_blog' => 'Footer Blog Links',
	  'footer_motoring_offences' => 'Footer Motoring Offences Links',
	  'footer_legal_links' => 'Footer Legal Links'
	)
);
	
$login_sb_args = array(
'name'          => "User actions",
'id'            => "user-actions",
'description'   => 'Area for logged in user widget',
'class'         => 'user-links',
'before_widget' => '',
'after_widget'  => '',
'before_title'  => '',
'after_title'   => '' 
);

register_sidebar( $login_sb_args );

add_theme_support( 'post-thumbnails', array( 'post', 'page' ) );

function the_title_trim($title) {
	$title = attribute_escape($title);
	$findthese = array(
		'#Protected:#',
		'#Private:#'
	);
	$replacewith = array(
		'', // What to replace "Protected:" with
		'' // What to replace "Private:" with
	);
	$title = preg_replace($findthese, $replacewith, $title);
	return $title;
}
add_filter('the_title', 'the_title_trim');

function custom_password_form() {
    global $post;
    $o = '<form class="protected-post-form" action="' . get_option('siteurl') . '/login/?action=postpass" method="post"><div class="form-group"><input name="post_password" type="password" class="form-control text-center" size="20" /></div><input type="submit" name="Submit" class="btn btn-default btn-block" value="' . esc_attr__( "Submit" ) . '" /></form>
    ';
    return $o;
}
add_filter( 'the_password_form', 'custom_password_form' );

function custom_class($classes, $field, $form){
    
    if($field["type"] == "select"){
        $classes .= " selectpicker";
    }
    return $classes;
}

add_action("gform_field_css_class", "custom_class", 10, 3);

if(function_exists('acf_add_options_page')) { 
	acf_add_options_page();
}

/*
GLOBAL PARTS INCLUDES
These are function to get regularly used template parts
*/
function masthead() {
	include (STYLESHEETPATH . '/_/inc/global/masthead.inc');
}

function main_nav() {
	include (STYLESHEETPATH . '/_/inc/global/main-nav.inc');
}

function col_strip($pos = null) {
	
	if ($pos == "b") {
	echo '<div class="abs-bot">';
	}
	
	if ($pos == "t") {
	echo '<div class="abs-top">';
	}
	
	include (STYLESHEETPATH . '/_/inc/global/col-strip.inc');
	
	if ($pos == "b" || $pos == "t") {
	echo '</div>';
	}
}

function head_html() {
	include (STYLESHEETPATH . '/_/inc/global/head-html.inc');
}

function footer_info() {
	include (STYLESHEETPATH . '/_/inc/global/footer-info.inc');
}

function inc($file, $folder = "global") {
	include (STYLESHEETPATH . '/_/inc/'.$folder.'/'.$file.'.inc');
}
function freephone_no($link = 0){
	$number = get_field('freephone_num', 'options');
	if ($link == 1) {
		$number	= str_replace(" ", "", $number);
	}
	echo $number;
}
function contact_email(){
	$email = get_field('contact_email', 'options');
	echo $email;
}
 ?>