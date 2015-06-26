<?php
/**
 * @file
 * tours_faceted_search.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function tours_faceted_search_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'rooms_unit-unit_with_attributes-field_attributes'
  $field_instances['rooms_unit-unit_with_attributes-field_attributes'] = array(
    'bundle' => 'unit_with_attributes',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Select attributes of this unit.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'rooms_unit',
    'field_name' => 'field_attributes',
    'label' => 'Attributes',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 1,
    ),
  );

  // Exported field_instance:
  // 'rooms_unit-unit_with_attributes-rooms_booking_unit_options'
  $field_instances['rooms_unit-unit_with_attributes-rooms_booking_unit_options'] = array(
    'bundle' => 'unit_with_attributes',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'rooms',
        'settings' => array(),
        'type' => 'rooms_options_default',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'rooms_unit',
    'field_name' => 'rooms_booking_unit_options',
    'label' => 'Options',
    'required' => FALSE,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'rooms',
      'settings' => array(),
      'type' => 'rooms_options_combined',
      'weight' => 0,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Attributes');
  t('Options');
  t('Select attributes of this unit.');

  return $field_instances;
}
