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
$viewtest = $view;
$titletest = $title;

$output = <<<EOF
<div class="coda-slider-wrapper">
	<div class="coda-slider preload" id="coda-slider-$id">
EOF;

$count = 1;

foreach ( $rows as $row ) {
  $output .= <<<EOF
		<div class="panel">
			<div class="panel-wrapper">
			  $row
			  <div class="views-coda-count" style="display: none;">$count</div>
			</div>
		</div>
EOF;

  $count++;
}

$output .= <<<EOF
	</div>
</div>
EOF;

echo $output;
