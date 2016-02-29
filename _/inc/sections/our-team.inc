<?php 
$section_title = get_field('mp_team_title', 'options');
$mp_team = get_field('mp_team', 'options');
$team_total = count($mp_team);
$team_counter = 0;
$inner_height = 580 * $team_total."px";
?>

<a name="our-team"></a>
<section id="our-team" class="section-our-team">
	
	<div class="container">
		<div class="row">
			<div class="col-xs-6 col-xs-offset-3">
				<h3><?php echo $section_title; ?></h3>
			</div>
		</div>
	</div>
	
	<div class="team-items">
		<div class="team-items-inner" style="height: <?php echo $inner_height; ?>;">
		
		<?php foreach ($mp_team as $k => $profile) { 
		//echo '<pre>';print_r($profile);echo '</pre>';
		$team_counter++;
		$name = $profile['tm_name'];
		$img = wp_get_attachment_image_src($profile['tm_img'], 'thumbnail-300');
		$profile_id = sanitize_title($name);
		$position = $profile['tm_position'];
		$email = $profile['tm_email'];
		$social_links = $profile['social_links'];
		$biog = $profile['tm_biog'];
		$next_name = null;	
		
		if ($team_total > 1 && $team_counter < $team_total) {
		$next_name = $mp_team[$k + 1]['tm_name'];	
		}
		
		if ($team_total > 1 && $team_counter == $team_total) {
		$next_name = $mp_team[0]['tm_name'];	
		}
		
		?>
		<div id="profile-<?php echo $profile_id; ?>" class="team-profile">
			
			<div class="container">
			<div class="row">
				
				<div class="col-xs-3">
					<img src="<?php echo $img[0]; ?>" class="img-responsive profile-img" />
					<div class="name caps font-cond"><?php echo $name; ?></div>
					<?php if ($next_name != null) { ?>
					<div class="next-name caps font-cond"><a href="#profile-<?php echo sanitize_title($next_name); ?>"><?php echo $next_name; ?></a></div>
					<?php } ?>
				</div>
				
				<div class="col-xs-9">
					<div class="caps font-slab-reg tm-position"><?php echo $position; ?></div>
					<a href="mailto:<?php echo $email; ?>" class="email-link"><?php echo $email; ?></a>
					<?php if (!empty($social_links)) { ?>
						<ul class="list-unstyled social-links">
							<?php foreach ($social_links as $sl) { ?>
							<li><a href="<?php echo $sl['social_url']; ?>" target="_blank"><i class="fa <?php echo $sl['social_icon']; ?>"></i><span class="sr-only"><?php echo $sl['social_title']; ?></span></a></li>
							<?php } ?>
						</ul>
					<?php } ?>
					<div class="biog-txt">
						<?php echo $biog; ?>
					</div>
				</div>
				
			</div>
			</div>
			
		</div>
		<?php } ?>
		
		</div>	
	</div>

</section>