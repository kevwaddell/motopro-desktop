jQuery(document).ready(function( $ ) {
	
	
	/*
	MENU FUNCTIONS
	Functions and actions for main navigation
	*/
	
	 $('body').on('click','li.top-level > a', function(e){
		 
		var parent = $(this).parent();
		
		$('#menu-main-menu > li.top-level').not(parent).removeClass('show-sub-nav');
		$('li.top-level > a').not(this).removeClass('active');
		 
		$(this).parent().toggleClass('show-sub-nav');
		$(this).toggleClass('active');
		
		return false;
	});
	
	 $('body').on('click','#close-nav', function(e){
		 
		$('#main-nav').animate({top: '-100%'}, { duration: 500, easing: "easeOutQuart"}, function(){
			
			$(this).removeClass('nav-open').addClass('nav-closed');
			
		});

		return false;
	});
	
});