<?php
	$wrapper = entity_metadata_wrapper('node', $node);

	$official_title = $wrapper->field_official_title->value();

	$additional_titles_wrapper = $wrapper->field_additional_titles->value();
	$additional_titles = $additional_titles_wrapper['value'];

	$research_interests_wrapper = $wrapper->field_research_interests->value();
	$research_interests = $research_interests_wrapper['value'];

	$selected_publications_wrapper = $wrapper->field_selected_publications->value();
	$selected_publications = $selected_publications_wrapper['value'];

	$office_location = $wrapper->field_office_location->value();

	$office_hours = $wrapper->field_office_hours->value();

	$email_address = $wrapper->field_email->value();

	$website_wrapper = $wrapper->field_website->value();
	$website = $website_wrapper['url'];

	$phone = $wrapper->field_phone->value();

	$fax = $wrapper->field_fax->value();

	$education_wrapper = $wrapper->field_education->value();
	$education = $education_wrapper['value'];

	$affiliations_wrapper = $wrapper->field_affiliations->value();
	$affiliations = $affiliations_wrapper['value'];

	$courses_taught_wrapper = $wrapper->field_courses_taught->value();
	$courses_taught = $courses_taught_wrapper['value'];

	$cv_upload_wrapper = $wrapper->field_cv->value();
	$cv_upload_uri = $cv_upload_wrapper['uri'];
	$cv_upload_url = file_create_url($cv_upload_uri);
	$cv_url_wrapper = $wrapper->field_cv_url_->value();
	$cv_url = $cv_url_wrapper['url'];
	if($cv_upload_uri) {
		$cv = $cv_upload_url;
	}
	if($cv_url) {
		$cv = $cv_url;
	}

	$website_wrapper = $wrapper->field_website->value();
	$website = $website_wrapper['url'];

	$bio_wrapper = $wrapper->body->value();
	$bio_content = $bio_wrapper['value'];

	$photo_wrapper = $wrapper->field_image->value();
	$photo_uri = $photo_wrapper['uri'];
	$photo_url = image_style_url('profile_small', $photo_uri);

	// Set Regions
	$primary_sidebar_region = block_get_blocks_by_region('sidebar_first');
	$secondary_sidebar_region = block_get_blocks_by_region('sidebar_second');
	$body_content_region = block_get_blocks_by_region('body_content');
?>
<div class="full container-main node-<?php print $node->nid; ?> <?php print $classes; ?>"<?php print $attributes; ?>>
  <?php print render($title_prefix); print render($title_suffix); ?>

  <div class="container-content-wrapper">
	<?php if($primary_sidebar_region): ?>
		<div class="">
			<?php print render($primary_sidebar_region); ?>
		</div>
	<?php endif; ?>
	<div class="container-content">
		<h1 class="page-header"><?php print $title; ?></h1>
			<div class="content-col">

		  <img class="thumb" src="<?php print $photo_url; ?>" />
		  <div class="content">
			  <div class="titles">
				  <?php print $official_title; ?><br />
				  <?php print $additional_titles; ?>
			  </div>
				<?php print $bio_content; ?>
				<?php if($research_interests): ?>
					<?php print t('Research Interests: ') . $research_interests; ?>
				<?php endif; ?>
				<?php if($selected_publications): ?>
					<?php print t('Publications: ') . $selected_publications; ?>
				<?php endif; ?>
				<?php if($education): ?>
					<?php print t('Education: ') . $education; ?>
				<?php endif; ?>
				<?php if($courses_taught): ?>
					<?php print t('Courses Taught: ') . $courses_taught; ?>
				<?php endif; ?>
				<?php if($affiliations): ?>
					<?php print t('Affiliations: ') . $affiliations; ?>
				<?php endif; ?>
				<?php if($phone): ?>
					<?php print t('Phone: ') . $phone; ?><br />
				<?php endif; ?>
				<?php if($fax): ?>
					<?php print t('Fax: ') . $fax; ?><br />
				<?php endif; ?>
				<?php if($office_hours): ?>
					<?php print t('Office Hours: ') . $office_hours; ?><br />
				<?php endif; ?>
				<?php if($office_location): ?>
					<?php print t('Office Location: ') . $office_location; ?><br />
				<?php endif; ?>
				<?php if($email_address): ?>
					<?php print t('Email: '); ?><a href="mailto:<?php print $email_address; ?>"><?php print $email_address; ?></a><br />
				<?php endif; ?>
				<?php if($website): ?>
					<?php print t('Website: '); ?><a target="_blank" href="<?php print $website; ?>"><?php print $website; ?></a><br />
				<?php endif; ?>
				<?php if($cv): ?>
					<a target="_blank" href="<?php print $cv; ?>"><?php print t('View CV'); ?></a>
				<?php endif; ?>
			</div>

			</div>
		</div>
	</div> <?php //.container-content-wrapper ?>
</div>