<?php
// $Id$

/**
 * @file
 * Contains the coda style plugin.
 */

/**
 * Outputs a view into a coda slider.
 * @ingroup views_style_plugins
 */
class views_coda_plugin_style_default extends views_plugin_style {
  /**
   * Set default options
   */
  function option_definition() {
    $options = parent::option_definition();

    $options['autoHeight'] = array(
      'default' => '1',
    );

    $options['autoHeightEaseDuration'] = array(
      'default' => 1000,
    );

    $options['autoSlide'] = array(
      'default' => '0',
    );

    $options['autoSlideInterval'] = array(
      'default' => 7000,
    );

    $options['autoSlideStopWhenClicked'] = array(
      'default' => '1',
    );

    $options['dynamicArrows'] = array(
      'default' => '1',
    );

    $options['dynamicArrowLeftText'] = array(
      'default' => '&#171; ' . t('left'),
    );

    $options['dynamicArrowRightText'] = array(
      'default' => t('right') . ' &#187;',
    );
    $options['dynamicTabs'] = array(
      'default' => '1',
    );

    $options['dynamicTabsAlign'] = array(
      'default' => 'center',
    );

    $options['dynamicTabsPosition'] = array(
      'default' => 'top',
    );

    $options['firstPanelToLoad'] = array(
      'default' => 1,
    );

    $options['slideEaseDuration'] = array(
      'default' => 1000,
    );

    $options['autoHeightEaseFunction'] = array(
      'default' => 'easeInOutExpo',
    );

    $options['crossLinking'] = array(
      'default' => '1',
    );

    $options['externalTriggerSelector'] = array(
      'default' => 'a.xtrig',
    );

    $options['panelTitle'] = array(
      'default' => 'count',
    );

    $options['panelTitleField'] = array(
      'default' => '',
    );

    $options['panelTitleSelector'] = array(
      'default' => '.field-content',
    );

    $options['slideEaseFunction'] = array(
      'default' => 'easeInOutExpo',
    );

    return $options;
  }

  /**
   * Render the given style.
   */
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    $form['autoHeight'] = array(
      '#type' => 'radios',
      '#title' => t('Auto Height'),
      '#options' => array(
        '1' => t('Yes'),
        '0' => t('No'),
      ),
      '#description' => t('Dynamically adjusts slider height according to the height of the content in each panel.  If set to false or 0, the height of the slider will be set to the height of the tallest panel.'),
      '#default_value' => $this->options['autoHeight'],
    );

    $form['autoHeightEaseDuration'] = array(
      '#type' => 'textfield',
      '#title' => t('Auto Height Ease Duration'),
      '#description' => t('Duration of autoHeight easing effect.  Ideally, this should use the same value as slideEaseDuration (see below). Depends on autoHeight being set to true or 1.'),
      '#default_value' => $this->options['autoHeightEaseDuration'],
    );

    $form['autoSlide'] = array(
      '#type' => 'radios',
      '#title' => t('Auto Slide'),
      '#options' => array(
        '1' => t('Yes'),
        '0' => t('No'),
      ),
      '#description' => t('Specifies whether slider should move between panels automatically.'),
      '#default_value' => $this->options['autoSlide'],
    );

    $form['autoSlideInterval'] = array(
      '#type' => 'textfield',
      '#title' => t('Auto Slide Interval'),
      '#description' => t('Time to wait before auto sliding.'),
      '#default_value' => $this->options['autoSlideInterval'],
    );

    $form['autoSlideStopWhenClicked'] = array(
      '#type' => 'radios',
      '#title' => t('Auto Slide Stop When Clicked'),
      '#options' => array(
        '1' => t('Yes'),
        '0' => t('No'),
      ),
      '#description' => t('Determines whether the autoSlide function should stop when user interacts with the slider.'),
      '#default_value' => $this->options['autoSlideStopWhenClicked'],
    );

    $form['dynamicArrows'] = array(
      '#type' => 'radios',
      '#title' => t('Dynamic Arrows'),
      '#options' => array(
        '1' => t('Yes'),
        '0' => t('No'),
      ),
      '#description' => t('Places left and right buttons alongside the slider.  Set this to No and you can still hardcode the left and eight buttons in the HTML, giving you more flexibility with positioning.'),
      '#default_value' => $this->options['dynamicArrows'],
    );

    $form['dynamicArrowLeftText'] = array(
      '#type' => 'textfield',
      '#title' => t('Dynamic Arrow Left Text'),
      '#description' => t('The anchor text used for the dynamic "slide left" button.'),
      '#default_value' => $this->options['dynamicArrowLeftText'],
    );

    $form['dynamicArrowRightText'] = array(
      '#type' => 'textfield',
      '#title' => t('Dynamic Arrow Right Text'),
      '#description' => t('The anchor text used for the dynamic "slide right" button.'),
      '#default_value' => $this->options['dynamicArrowRightText'],
    );

    $form['dynamicTabs'] = array(
      '#type' => 'radios',
      '#title' => t('Dynamic Tabs'),
      '#options' => array(
        '1' => t('Yes'),
        '0' => t('No'),
      ),
      '#description' => t('Adds tabbed navigation to the slider.'),
      '#default_value' => $this->options['dynamicTabs'],
    );

    $form['dynamicTabsAlign'] = array(
      '#type' => 'radios',
      '#title' => t('Dynamic Tabs Align'),
      '#options' => array(
        'left' => t('Left'),
        'center' => t('Center'),
        'right' => t('Right'),
      ),
      '#description' => t('Specifies the horizontal alignment of the tabbed navigation, relative to the slider.  Dynamic Tabs must be set to Yes'),
      '#default_value' => $this->options['dynamicTabsAlign'],
    );

    $form['dynamicTabsPosition'] = array(
      '#type' => 'radios',
      '#title' => t('Dynamic Tabs Position'),
      '#options' => array(
        'top' => t('Top'),
        'bottom' => t('Bottom'),
      ),
      '#description' => t('Specifies whether the tabbed navigation should appear above or below the slider.'),
      '#default_value' => $this->options['dynamicTabsPosition'],
    );

    $form['firstPanelToLoad'] = array(
      '#type' => 'textfield',
      '#title' => t('First Panel To Load'),
      '#description' => t('Specifies the panel that should be loaded first, in the absence of cross-linking.'),
      '#default_value' => $this->options['firstPanelToLoad'],
    );

    $form['slideEaseDuration'] = array(
      '#type' => 'textfield',
      '#title' => t('Slide Ease Duration'),
      '#description' => t('Duration of slide easing effect.  Ideally, this should use the same value as autoHeightEaseDuration.  Auto Height must be set to Yes'),
      '#default_value' => $this->options['slideEaseDuration'],
    );

    $form['autoHeightEaseFunction'] = array(
      '#type' => 'textfield',
      '#title' => t('Auto Height Ease Function'),
      '#description' => t('Easing method used for autoHeight effect.'),
      '#default_value' => $this->options['autoHeightEaseFunction'],
    );

    $form['crossLinking'] = array(
      '#type' => 'radios',
      '#title' => t('Cross Linking'),
      '#options' => array(
        '1' => t('Yes'),
        '0' => t('No'),
      ),
      '#description' => t('Allows permalinking to each slider panel via a URL hash.'),
      '#default_value' => $this->options['crossLinking'],
    );

    $form['externalTriggerSelector'] = array(
      '#type' => 'textfield',
      '#title' => t('External Trigger Selector'),
      '#description' => t('Specifies the selector for elements on the page, apart from the usual navigation elements, which should trigger a slide.'),
      '#default_value' => $this->options['externalTriggerSelector'],
    );

    $form['panelTitle'] = array(
      '#type' => 'radios',
      '#title' => t('Panel Title Type'),
      '#options' => array(
        'count' => t('Count'),
        'grouping' => t('Grouping'),
        'field' => t('Field'),
        'selector' => t('Selector'),
      ),
      '#description' => t('Specifies how to determine the dynamic tabs caption.  If set to Count, the record count will be used.  If set to Grouping, the grouping title will be used.  If set to Field Index, the value '),
      '#default_value' => $this->options['panelTitle'],
    );

    if ( get_class($this->row_plugin) == 'views_plugin_row_fields' ) {
      $fieldoptions = array();

      $fields = $this->display->handler->handlers['field'];

      if ( is_array($fields) && count($fields) ) {
        $count = 0;

        foreach ( $fields as $key => $field ) {
          $label = $field->definition['group'] . ': ' . $field->definition['title'];

          if ( $field->options['label'] != '' ) {
            $label .= ' ' . $field->options['label'];
          }

          $fieldoptions[$count] = $label;

          $count++;
        }
      }

      $form['panelTitleField'] = array(
        '#type' => 'select',
        '#title' => t('Panel Title Field'),
        '#options' => $fieldoptions,
        '#description' => t('Specifies which field from fields should be used for the dynamic tabs.  Dynamic Tabs must be set to Yes.'),
        '#default_value' => $this->options['panelTitleField'],
      );
    }

    $form['panelTitleSelector'] = array(
      '#type' => 'textfield',
      '#title' => t('Panel Title Selector'),
      '#description' => t('Specifies which element within each panel the tabbed navigation anchor text should be copied from.  Dynamic Tabs must be set to Yes.'),
      '#default_value' => $this->options['panelTitleSelector'],
    );

    $form['slideEaseFunction'] = array(
      '#type' => 'textfield',
      '#title' => t('Slide Ease Function'),
      '#description' => t('Easing method used for slide effect.'),
      '#default_value' => $this->options['slideEaseFunction'],
    );
  }

  /**
   * Validate the options form.
   */
  function options_validate(&$form, &$form_state) {
    $debug = TRUE;

    switch ($form_state['section']) {
      case 'style_options':
        $values = $form_state['values']['style_options'];

        if ( !is_numeric($values['autoHeightEaseDuration']) || $values['autoHeightEaseDuration'] < 0 ) {
          form_set_error('autoHeightEaseDuration', t('Auto Height Ease Duration: Please specify a number greater than 0.'));
        }

        if ( !is_numeric($values['autoSlideInterval']) || $values['autoSlideInterval'] < 0 ) {
          form_set_error('autoSlideInterval', t('Auto Slide Interval: Please specify a number greater than 0.'));
        }

        if ( !is_numeric($values['firstPanelToLoad']) || $values['firstPanelToLoad'] < 0 ) {
          form_set_error('firstPanelToLoad', t('First Panel to Load: Please specify a number greater than 0.'));
        }

        if ( !is_numeric($values['slideEaseDuration']) || $values['slideEaseDuration'] < 0 ) {
          form_set_error('slideEaseDuration', t('Slide Ease Duration: Please specify a number greater than 0.'));
        }

        if ( $values['panelTitle'] == 'selector' && $values['panelTitleSelector'] == '' ) {
          form_set_error('panelTitleSelector', t('Panel Title Selector: Please specify a valid jquery selector.'));
        }

        break;
    }
  }
}