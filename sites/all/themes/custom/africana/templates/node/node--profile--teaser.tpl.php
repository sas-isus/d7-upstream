<?php
	$wrapper = entity_metadata_wrapper('node', $node);

	$first_name = $wrapper->field_first_name->value();
	$middle_name = $wrapper->field_middle_name->value();
	$last_name = $wrapper->field_last_name->value();
	$name = $first_name . ($middle_name ? ' ' . $middle_name : '') . ' ' . $last_name;

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
?>
<div class="teaser node-<?php print $node->nid; ?> <?php print $classes; ?>"<?php print $attributes; ?>>
  <?php print render($title_prefix); print render($title_suffix); ?>

  <a href="<?php print $node_url; ?>">
  <img class="thumb" src="<?php print $photo_url; ?>" />
  <div class="content">
	  <h3><?php print $name; ?></h3>
	  <div class="titles">
		  <?php print $official_title; ?><br />
		  <?php print $additional_titles; ?>
	  </div>
	  <?php if($research_interests): ?>
			<?php print $research_interests; ?>
		<?php endif; ?>

	</div>
	</a>
</div>