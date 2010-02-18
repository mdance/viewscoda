<?php
// $Id$

/**
 * @file
 * Default view template to display a coda slider.
 *
 * - $view: The view object.
 * - $options: Style options. See below.
 * - $rows: The output for the rows.
 * - $title: The title of this group of rows.  May be empty.
 *
 * - $options['type'] will either be ul or ol.
 *
 * @ingroup views_templates
 */
$codaid = $view->views_coda['codaid'];

if ( $title != '' ) {
  $output = <<<EOF
    <h3 class="views-coda-title">$title</h3>
EOF;
}

$output .= <<<EOF
<div class="coda-slider-wrapper">
	<div class="coda-slider preload" id="$codaid">
EOF;

foreach ( $rows as $row ) {
  $output .= <<<EOF
		<div class="panel">
			<div class="panel-wrapper">
			  $row
			</div>
		</div>
EOF;
}

$output .= <<<EOF
	</div>
</div>
EOF;

echo $output;
