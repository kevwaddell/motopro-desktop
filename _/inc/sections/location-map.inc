<?php 
$location = get_field('location', 'options');	
$address = get_field('address', 'options');
//echo '<pre>';print_r($address);echo '</pre>';
$map_marker = get_stylesheet_directory_uri()."/_/img/map-marker.png";
?>
<?php if ($location) { ?>
<script src="https://maps.googleapis.com/maps/api/js?v=3.exp&sensor=false"></script>
<a name="find-us" id="find-us"></a>
<section id="wide-map">
<script>
	var TLW_MAP_ID = 'TLW_style';
	
    var wide_map;
    var TLW_MAPTYPE_ID = 'wide_map';
    var myLatLang = new google.maps.LatLng( <?php echo $location['lat']; ?>, <?php echo $location['lng']; ?>);
	var img_url = "<?php echo $map_marker; ?>";
	var marker;
	
	//console.log(myLatLang);
	
	 var image = {
		 url: img_url,
		 // This marker is 20 pixels wide by 32 pixels tall.
		 size: new google.maps.Size(60, 70),
		 // The origin for this image is 0,0.
		 origin: new google.maps.Point(0,0),
		 // The anchor for this image is the base of the flagpole at 0,32.
		 anchor: new google.maps.Point(30, 60)
		 };
		
   
   function wide_map_init() {
    
	var mapOptions = {
		center: myLatLang,
            zoom: 15,
            zoomControl: true,
            zoomControlOptions: {
                style: google.maps.ZoomControlStyle.DEFAULT,
            },
            disableDoubleClickZoom: true,
            mapTypeControl: false,
            scaleControl: true,
            scrollwheel: true,
            panControl: true,
            streetViewControl: false,
            draggable : true,
            overviewMapControl: true,
            overviewMapControlOptions: {
                opened: false,
            },
            mapTypeId: google.maps.MapTypeId.ROADMAP,
            <?php inc('map-styles', 'map'); ?>
		};

	<?php //inc('map-options', 'map'); ?>	
		
    wide_map = new google.maps.Map(document.getElementById('wide-map-canvas'), mapOptions);
    	
    marker = new google.maps.Marker({position: myLatLang, map: wide_map, icon: image,title: "MotoPro"});
		
	};

	google.maps.event.addDomListener(window, 'load', wide_map_init);
	
</script>

	<div id="wide-map-canvas"></div>

	<div class="container">
		<div class="row">
			<div class="col-xs-4">
				<div class="location-box">
					<address>
						<span class="company bold caps col-red font-size-25"><?php bloginfo('name'); ?></span><br>
						<?php echo $address; ?>
					</address>
					
					<button class="btn btn-block" data-toggle="modal" data-target="#route-finder-modal"><i class="fa fa-car"></i> Route finder</button>
						
				</div>
			</div>
		</div>
		
	</div>

</section>

<div class="modal fade" id="route-finder-modal" tabindex="-1" role="dialog">
	
	<div class="modal-dialog">	
		<div class="modal-content">
			
			<div class="modal-header">
				<h4 class="modal-title"><i class="fa fa-car"></i> Route Finder</h4>
				<button type="button" class="btn btn-block close-btn" data-dismiss="modal" aria-label="Close"><span aria-hidden="true">&times;</span></button>
      		</div>
      		
			<div class="modal-body">	
				<!-- <form action="http://maps.google.com/maps/" method="get" target="_blank"> -->
				<form action="http://maps.google.com/maps" method="get" target="_blank" class="route-finder">
					<div class="form-group">
						<label for="saddr">Enter Your Post code:</label>
						<input type="hidden" name="daddr" value="NE29 7ST">
						<input type="text" class="form-control input-lg" name="saddr" maxlength="9" id="start">
					</div>
	
					<button class="btn btn-block">Get directions <i class="fa fa-arrow-circle-right pull-right"></i></button>
				</form>
				
			</div>
		</div>
	
	</div>
	
</div>
<?php } ?>