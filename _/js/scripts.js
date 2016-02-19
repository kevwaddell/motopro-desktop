jQuery(document).ready(function( $ ) {
	
	
	/*
	MENU FUNCTIONS
	Functions and actions for main navigation
	*/
	
	 $('body').on('click','button#main-nav-btn', function(e){
		 
		$('#main-nav').animate({top: '0%', opacity: '1'}, 500, "easeInQuart", function(){
			
			console.log($(this));
			
			$(this).removeClass('nav-closed').addClass('nav-open').removeAttr("style");
			
		});
				
		return false;
	});
	
	 $('body').on('click','li.top-level > a', function(e){
		 
		var parent = $(this).parent();
		
		$('#menu-main-menu > li.top-level').not(parent).removeClass('show-sub-nav');
		$('li.top-level > a').not(this).removeClass('active');
		 
		$(this).parent().toggleClass('show-sub-nav');
		$(this).toggleClass('active');
		
		return false;
	});
	
	 $('body').on('click','#close-nav', function(e){
		 
		$('#menu-main-menu > li.top-level').not(parent).removeClass('show-sub-nav');
		$('li.top-level > a').not(this).removeClass('active');
		 
		$('#main-nav').animate({top: '-100%', opacity: '0'}, 500, "easeOutQuart", function(){
			
			$(this).removeClass('nav-open').addClass('nav-closed').removeAttr("style");
			
		});

		return false;
	});
	
});