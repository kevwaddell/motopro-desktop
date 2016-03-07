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
	SCROLLABLE FUNCTIONS
	initiate the slimscroll function	
	*/
	
	$('.scrollable-inner').slimScroll({
         position: 'right',
		 height: 'auto',
		 size: '20px',
		 color: '#4b565c',
		 railOpacity: 1,
		 railVisible: true,
		 alwaysVisible: true,
		 railColor: 'transparent'
    });
	
	/*
	MENU FUNCTIONS
	Functions and actions for main navigation
	*/
	
	 $('body').on('click','button#main-nav-btn', function(e){
		 
		 $('body').addClass('nav-open');
		 
		$('#main-nav').animate({top: '0%', opacity: '1'}, 500, "easeInQuart", function(){
			
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
	
	/*
	MENU SCROLL TO HASH FUNCTIONS
	If hash is present in url scroll to with animation;
	*/
	
	if(window.location.hash) {
		
		var hash = window.location.hash;
		
		console.log($(hash).offset());

		if (hash.indexOf('profile') > 0) {
			
			$('html, body').animate({scrollTop: ($('#our-team').offset().top - 80)}, 500);
			
			$(hash).find('.next-name a').trigger('click');
		} else {
			
			$('html, body').animate({scrollTop: ($(hash).offset().top - 80)}, 500);
			
		}
	}
	
	$(window).on('hashchange', function() {
		
		var hash = window.location.hash;
		var offset = $('#our-team').position();
		
		if (hash.indexOf('profile') > 0) {
			$('html, body').scrollTop( $('#our-team').offset().top - 80 );
		}
		
	});
	
	$('body').on('click','#menu-main-menu ul.sub-menu a', function(e){
		var hash = window.location.hash;
		var href = $(this).attr('href');
		var path = href.split('#');
		var current_url = window.location.pathname;	 
		
		if (href.indexOf('#') > 0 && path[0] == current_url) {	
			
			if ( $('#main-nav').hasClass('nav-open') ) {
				
				$('html, body').animate({scrollTop: ($('#'+path[1]).offset().top - 80)}, 500);
				
				$('#close-nav').trigger('click');	
				
			} else {
				
				$('html, body').animate({scrollTop: ($(hash).offset().top - 80)}, 500);	
			
			}
		
		return false;	
		
		}
		
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
	
	// JUMP TO FUNCTIONS
	
	$('body').on('click','ul.sb-jump2-links a', function(e){
		
		var id = $(this).attr('href');
		
		if ($(id).length > 0) {
		$('html, body').animate({scrollTop: ($(id).offset().top - 80)}, 500);	
		}
		
		return false;
		
	});
	
	//OUR TEAM NEXT PRIFILE BUTTON
	$('body').on('click','.next-name a', function(e){
		
		var next_id = $(this).attr('href');
		var current = $(this).parents('.team-profile');
		var offset = $(next_id).position().top;
		var hash = window.location.hash;
		
		if (hash.indexOf('#profile') == -1) {
			
			$('.team-items-inner').animate({top: "-"+offset+"px"}, 500);
			return false
			
		}
		
	});
	
});