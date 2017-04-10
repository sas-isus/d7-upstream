<?php
/**
 * @file
 * Easy Social default widget functions.
 */

/**
 * Generate the needed markup for the facebook share link.
 *
 * @param $url The url to be shared
 * @param $type Generate horizontal or vertical widgets
 * @param $title The title to be shared
 * @param $lang The language of the facebook button
 * @return string the html markup
 */
function _easy_social_widget_facebook_markup($url, $type, $title = NULL, $lang = 'en') {
  // Correct for different language identification strings.
  $lang = _easy_social_facebook_langcodes($lang);

  // @TODO Subscribe to the 'edge.create' event through FB.Event.subscribe to
  // track successful shares. This will likely be in either a seperate module
  // or a new version.

  if ($type == EASY_SOCIAL_WIDGET_HORIZONTAL) {
    $width = variable_get_value('easy_social_facebook_width_horizontal');
    $type_box = 'button_count';
    $height = '21';
  }
  else {
    $width = variable_get_value('easy_social_facebook_width_vertical');
    $type_box = 'box_count';
    $height = '90';
  }

  $appid = variable_get_value('easy_social_facebook_appid');
  $facebook_type = variable_get_value('easy_social_facebook_widget_type');
  $send_button = variable_get_value('easy_social_facebook_send_button') ? 'true'
      : 'false';
  $show_faces = variable_get_value('easy_social_facebook_show_faces') ? 'true' : 'false';
  $action = variable_get_value('easy_social_facebook_verb');
  $color_scheme = variable_get_value('easy_social_facebook_color_scheme');
  $font = variable_get_value('easy_social_facebook_font');

  if ($font === 'default') {
    $font = '';
  }

  if ($facebook_type !== 'iframe') {
    // This is done here instead of using the proper hook method because the
    // script is only added in the HTMl5 and XFBML versions, not iframe.
    $script = <<<JS
(function(d, s, id) {
  var js, fjs = d.getElementsByTagName(s)[0];
  if (d.getElementById(id)) {return;}
  js = d.createElement(s); js.id = id;
  js.src = "//connect.facebook.net/{$lang}/all.js#xfbml=1&appId={$appid}";
  fjs.parentNode.insertBefore(js, fjs);
}(document, 'script', 'facebook-jssdk'));
JS;
    drupal_add_js($script, 'inline');
  }

  if ($facebook_type === 'html5') {
    $markup = <<<FB
<div class="fb-like" data-href="{$url}" data-send="{$send_button}" data-layout="{$type_box}" data-width="{$width}" data-show-faces="{$show_faces}" data-action="{$action}" data-colorscheme="{$color_scheme}" data-font="{$font}"></div>
FB;
  }
  elseif ($facebook_type === 'xfbml') {
    $markup = <<<FB
<fb:like href="{$url}" send="{$send_button}" layout="{$type_box}" width="{$width}" show_faces="{$show_faces}" action="{$action}" colorscheme="{$color_scheme}" font="{$font}"></fb:like>
FB;
  }
  else {
    $url = drupal_encode_path($url);
    $font = drupal_encode_path($font);

    $markup = <<<FB
<iframe src="//www.facebook.com/plugins/like.php?locale={$lang}&amp;href={$url}&amp;send=false&amp;layout={$type_box}&amp;width={$width}&amp;show_faces={$show_faces}&amp;action={$action}&amp;colorscheme={$color_scheme}&amp;font={$font}&amp;height={$height}&amp;appId={$appid}" scrolling="no" frameborder="0" style="border:none; overflow:hidden; width:{$width}px; height:{$height}px;" allowTransparency="true"></iframe>
FB;
  }
  return $markup;
}

/**
 * Generate the needed markeup for the Google+ share link.
 *
 * @param $url The url to be shared
 * @param $type Generate horizontal or vertical widgets
 * @param $title The title to be shared
 * @return string the html markup
 */
function _easy_social_widget_googleplus_markup($url, $type, $title = NULL, $lang = 'und') {
  // This widget doesn't yet offer a localization option.
  // @TODO Use "callback" to track successful shares. This will likely be in
  // either a seperate module or a new version.

  $annotation = variable_get_value('easy_social_googleplus_annotation');
  $type = ($type == EASY_SOCIAL_WIDGET_HORIZONTAL) ? 'medium' : 'tall';
  $html5 = variable_get_value('easy_social_googleplus_html5');

  if ($html5) {
    $markup = <<<GP
<div class="g-plusone" data-size="{$type}" data-annotation="{$annotation}" data-href="{$url}"></div>
GP;
  }
  else {
    $markup = <<<GP
<g:plusone size="{$type}" href="{$url}" annotation="{$annotation}"></g:plusone>
GP;
  }
  return $markup;
}

/**
 * Generate the needed markeup for the linkedin share link.
 *
 * @param $url The url to be shared
 * @param $type Generate horizontal or vertical widgets
 * @param $title The title to be shared
 * @return string the html markup
 */
function _easy_social_widget_linkedin_markup($url, $type, $title = NULL, $lang = 'und') {
  // This widget doesn't yet offer a localization option.
  // @TODO Use "data-onsuccess" to track successful shares this will likely be
  // in either a seperate module or a new version.

  $type = ($type == EASY_SOCIAL_WIDGET_HORIZONTAL) ? 'right' : 'top';
  $type_show = variable_get_value('easy_social_linkedin_count_show');
  if (!$type_show)
    $type = FALSE;
  $markup = <<<LI
<script type="in/share" data-url="{$url}" data-counter="{$type}"></script>
LI;
  return $markup;
}

/**
 * Generate the needed markup for the twitter share link.
 *
 * @param $url The url to be shared
 * @param $type Generate horizontal or vertical widgets
 * @param $title The title to be shared
 * @param $lang The language of the twitter button
 * @return string the html markup
 */
function _easy_social_widget_twitter_markup($url, $type, $title = NULL, $lang = 'und') {
  // Correct for different language identification strings.
  $lang = _easy_social_twitter_langcodes($lang);

  $type = ($type == EASY_SOCIAL_WIDGET_HORIZONTAL) ? 'horizontal' : 'vertical';
  // Override the data-count attribute to hide the count, if selected.
  $type_show = variable_get_value('easy_social_twitter_count_show');
  if (!$type_show)
    $type = 'none';

  $account_via = variable_get_value('easy_social_twitter_account_via');
  $account_related = variable_get_value('easy_social_twitter_account_related');
  $account_related_description = variable_get_value('easy_social_twitter_account_description');

  $markup = <<<TT
<a href="http://twitter.com/share" class="twitter-share-button"
data-url="{$url}"
data-count="{$type}"
data-lang = "{$lang}"
data-via="{$account_via}"
data-related="{$account_related}:{$account_related_description}"
data-text="{$title}">Tweet</a>
TT;
  return $markup;
}

/**
 * Returns language for Twitter widget.
 * Since this widget has very limited and specific language options, we have to
 * manually map some Drupal to Twitter language conversions.
 *
 * @param $lang The drupal langcode.
 * @return string the respective supported langcode by twitter ISO 369.
 */
function _easy_social_twitter_langcodes($lang = LANGUAGE_NONE) {
  $languages = array();

  // Hungarian.
  $languages['hu'] = 'hu';

  // Norwegian.
  $languages['nn'] = 'no';
  $languages['nb'] = 'no';

  // Malay.
  $languages['mg'] = 'msa';
  $languages['ms'] = 'msa';
  $languages['ml'] = 'msa';

  // French.
  $languages['fr'] = 'fr';

  // German.
  $languages['de'] = 'de';
  $languages['gsw-berne'] = 'de';

  // English.
  $languages[LANGUAGE_NONE] = 'en';
  $languages['en'] = 'en';
  $languages['en-us'] = 'en';
  $languages['en-gb'] = 'en';

  // Traditional Chinese.
  $languages['zh-hant'] = 'zh-tw';

  // Filipino.
  $languages['fil'] = 'fil';

  // Korean.
  $languages['ko'] = 'ko';

  // Polish.
  $languages['pl'] = 'pl';

  // Indonesian.
  $languages['id'] = 'id';

  // Russian.
  $languages['ru'] = 'ru';

  // Finnish.
  $languages['fi'] = 'fi';

  // Hindi.
  $languages['hi'] = 'hi';

  // Portuguese.
  $languages['pt'] = 'pt';
  $languages['pt-br'] = 'pt';
  $languages['pt-pt'] = 'pt';

  // Italian.
  $languages['it'] = 'it';

  // Danish.
  $languages['da'] = 'da';

  // Swedish.
  $languages['sv'] = 'sv';

  // Spanish.
  $languages['es'] = 'es';

  // Dutch.
  $languages['nl'] = 'nl';

  // Simplified Chinese.
  $languages['zh-hans'] = 'zh-cn';

  // Turkish.
  $languages['tr'] = 'tr';
  $languages['tk'] = 'tr';

  // Japanese.
  $languages['ja'] = 'ja';

  return (isset($languages[$lang])) ? $languages[$lang] : 'en';
}

/**
 * Facebook langcode.
 * Since this widget has very limited and specific language options, we have to
 * manually map some Drupal to Twitter language conversions.

 * @param $lang The drupal langcode
 * @return string the respective supported langcode by facebook II_CC
 */
function _easy_social_facebook_langcodes($lang = LANGUAGE_NONE) {
  $languages = array();

  // Afrikaans.
  $languages['af'] = 'af_ZA';

  // Arabic.
  $languages['ar'] = 'ar_AR';

  // Azeri.
  $languages['az'] = 'az_AZ';

  // Belarusian.
  $languages['be'] = 'be_BY';

  // Bulgarian.
  $languages['bg'] = 'bg_BG';

  // Bengali.
  $languages['bn'] = 'bn_IN';

  // Bosnian.
  $languages['bs'] = 'bs_BA';

  // Catalan.
  $languages['ca'] = 'ca_ES';

  // Czech.
  $languages['cs'] = 'cs_CZ';

  // Welsh.
  $languages['cy'] = 'cy_GB';

  // Danish.
  $languages['da'] = 'da_DK';

  // German.
  $languages['de'] = 'de_DE';
  $languages['gsw-berne'] = 'de_DE';

  // Greek.
  $languages['el'] = 'el_GR';

  // English (UK).
  $languages['en-gb'] = 'en_GB';

  // English (US).
  $languages[LANGUAGE_NONE] = 'en_US';
  $languages['en'] = 'en_US';
  $languages['en-us'] = 'en_US';

  // Esperanto.
  $languages['eo'] = 'eo_EO';

  // Spanish (Spain).
  $languages['es'] = 'es_ES';

  // Estonian.
  $languages['et'] = 'et_EE';

  // Basque.
  $languages['eu'] = 'eu_ES';

  // Persian.
  $languages['fa'] = 'fa_IR';

  // Leet Speak.
  $languages['fb'] = 'fb_LT';

  // Finnish.
  $languages['fi'] = 'fi_FI';

  // Faroese.
  $languages['fo'] = 'fo_FO';

  // French (France).
  $languages['fr'] = 'fr_FR';

  // Frisian.
  $languages['fy'] = 'fy_NL';

  // Irish.
  $languages['ga'] = 'ga_IE';

  // Galician.
  $languages['gl'] = 'gl_ES';

  // Hebrew.
  $languages['he'] = 'he_IL';

  // Hindi.
  $languages['hi'] = 'hi_IN';

  // Croatian.
  $languages['hr'] = 'hr_HR';

  // Hungarian.
  $languages['hu'] = 'hu_HU';

  // Armenian.
  $languages['hy'] = 'hy_AM';

  // Indonesian.
  $languages['id'] = 'id_ID';

  // Icelandic.
  $languages['is'] = 'is_IS';

  // Italian.
  $languages['it'] = 'it_IT';

  // Japanese.
  $languages['ja'] = 'ja_JP';

  // Georgian.
  $languages['ka'] = 'ka_GE';

  // Khmer.
  $languages['km'] = 'km_KH';

  // Korean.
  $languages['ko'] = 'ko_KR';

  // Kurdish.
  $languages['ku'] = 'ku_TR';

  // Latin.
  $languages['la'] = 'la_VA';

  // Lithuanian.
  $languages['lt'] = 'lt_LT';

  // Latvian.
  $languages['lv'] = 'lv_LV';

  // Macedonian.
  $languages['mk'] = 'mk_MK';

  // Malayalam.
  $languages['ml'] = 'ml_IN';

  // Malay.
  $languages['ms'] = 'ms_MY';
  $languages['mg'] = 'ms_MY';

  // Norwegian.
  $languages['nn'] = 'nb_NO';
  $languages['nb'] = 'nb_NO';

  // Nepali.
  $languages['ne'] = 'ne_NP';

  // Dutch.
  $languages['nl'] = 'nl_NL';

  // Norwegian (Nynorsk).
  $languages['nn'] = 'nn_NO';

  // Punjabi.
  $languages['pa'] = 'pa_IN';

  // Polish.
  $languages['pl'] = 'pl_PL';

  // Pashto.
  $languages['ps'] = 'ps_AF';

  // Portuguese (Brazil).
  $languages['pt'] = 'pt_BR';
  $languages['pt-br'] = 'pt_BR';

  // Portuguese (Portugal).
  $languages['pt-pt'] = 'pt_PT';

  // Romanian.
  $languages['ro'] = 'ro_RO';

  // Russian.
  $languages['ru'] = 'ru_RU';

  // Slovak.
  $languages['sk'] = 'sk_SK';

  // Slovenian.
  $languages['sl'] = 'sl_SI';

  // Albanian.
  $languages['sq'] = 'sq_AL';

  // Serbian.
  $languages['sr'] = 'sr_RS';

  // Swedish.
  $languages['sv'] = 'sv_SE';

  // Swahili.
  $languages['sw'] = 'sw_KE';

  // Tamil.
  $languages['ta'] = 'ta_IN';

  // Telugu.
  $languages['te'] = 'te_IN';

  // Thai.
  $languages['th'] = 'th_TH';

  // Filipino.
  $languages['tl'] = 'tl_PH';

  // Turkish.
  $languages['tr'] = 'tr_TR';
  $languages['tk'] = 'tr_TR';

  // Ukrainian.
  $languages['uk'] = 'uk_UA';

  // Vietnamese.
  $languages['vi'] = 'vi_VN';

  // Simplified Chinese (China).
  $languages['zh-hans'] = 'zh_CN';

  // Traditional Chinese (Taiwan).
  $languages['zh-hant'] = 'zh_TW';

  return (isset($languages[$lang])) ? $languages[$lang] : 'en_US';
}
