jQuery(document).ready(function( $ ) {
	
	var select_picker = $('.selectpicker').find('select');
	
	if (select_picker.length > 0) {
		var placeholder = $(select_picker).find('option.gf_placeholder');
		$(placeholder).attr('data-hidden', 'true');
	}
	
	$('.selectpicker').find('select').selectpicker({
		'style': 'btn btn-group btn-default', 
		'width': '98%'
	});

	
	/*
	MENU FUNCTIONS
	Functions and actions for main navigation
	*/
	
	 $('body').on('click','button#main-nav-btn', function(e){
		 
		 $('body').addClass('nav-open');
		 
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
			$('body').removeClass('nav-open');
			
		});

		return false;
	});
	
	// 	HEADER SEARCH BUTTON
	
	$('body').on('click','button#search-btn', function(e){
	
		if ( $('#search-pop-up').hasClass('off') ) {
			
			$('#search-pop-up').removeClass('off').addClass('on');
		} 
		
		return false;
		
	});
	
	$('body').on('click','button#close-search', function(e){
	
		if ( $('#search-pop-up').hasClass('on') ) {
			$('#search-pop-up').removeClass('on').addClass('turn-off');
			
			$('.turn-off').one('webkitAnimationEnd mozAnimationEnd MSAnimationEnd oanimationend animationend', function(){
		
				$(this).removeClass('turn-off').addClass('off');	
				
			});

		} 
		
		return false;
		
	});
	
});