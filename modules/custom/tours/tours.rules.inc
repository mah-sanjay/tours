<?php

/**
 * @file
 * Rules integration for Tours.
 */

/**
 * Implements hook_rules_action_info().
 */
function tours_rules_action_info() {
  $actions = array();

  $actions['tours_price_apply'] = array(
    'label' => t('Apply price to a tours line item'),
    'parameter' => array(
      'commerce_line_item' => array(
        'type' => 'commerce_line_item',
        'label' => t('Line item'),
      ),
    ),
    'group' => t('Tours'),
    'callbacks' => array(
      'execute' => 'tours_price_apply',
    ),
  );

  return $actions;
}
