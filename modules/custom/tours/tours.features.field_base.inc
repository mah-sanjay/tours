<?php
/**
 * @file
 * tours.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function tours_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_daily_slot'
  $field_bases['field_daily_slot'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_daily_slot',
    'foreign keys' => array(
      'rooms_units' => array(
        'columns' => array(
          'target_id' => 'unit_id',
        ),
        'table' => 'rooms_units',
      ),
    ),
    'indexes' => array(
      'target_id' => array(
        0 => 'target_id',
      ),
    ),
    'locked' => 0,
    'module' => 'entityreference',
    'settings' => array(
      'handler' => 'base',
      'handler_settings' => array(
        'behaviors' => array(
          'views-select-list' => array(
            'status' => 0,
          ),
        ),
        'sort' => array(
          'type' => 'none',
        ),
        'target_bundles' => array(
          'single_day_tour_slot' => 'single_day_tour_slot',
        ),
      ),
      'target_type' => 'rooms_unit',
    ),
    'translatable' => 0,
    'type' => 'entityreference',
  );

  // Exported field_base: 'field_day_tour_time_slot'
  $field_bases['field_day_tour_time_slot'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_day_tour_time_slot',
    'foreign keys' => array(),
    'indexes' => array(),
    'locked' => 0,
    'module' => 'timefield',
    'settings' => array(
      'totime' => 'optional',
      'weekly_summary' => 0,
      'weekly_summary_with_label' => 0,
    ),
    'translatable' => 0,
    'type' => 'timefield',
  );

  // Exported field_base: 'field_tour_orders'
  $field_bases['field_tour_orders'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_tour_orders',
    'foreign keys' => array(
      'commerce_order' => array(
        'columns' => array(
          'target_id' => 'order_id',
        ),
        'table' => 'commerce_order',
      ),
    ),
    'indexes' => array(
      'target_id' => array(
        0 => 'target_id',
      ),
    ),
    'locked' => 0,
    'module' => 'entityreference',
    'settings' => array(
      'handler' => 'base',
      'handler_settings' => array(
        'behaviors' => array(
          'views-select-list' => array(
            'status' => 0,
          ),
        ),
        'sort' => array(
          'direction' => 'ASC',
          'property' => 'created',
          'type' => 'property',
        ),
        'target_bundles' => array(
          'commerce_order' => 'commerce_order',
        ),
      ),
      'target_type' => 'commerce_order',
    ),
    'translatable' => 0,
    'type' => 'entityreference',
  );

  return $field_bases;
}
