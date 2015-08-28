<?php
/**
 * @file
 * tours.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function tours_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'rooms_booking-tour_instance-field_tour_orders'
  $field_instances['rooms_booking-tour_instance-field_tour_orders'] = array(
    'bundle' => 'tour_instance',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'link' => FALSE,
        ),
        'type' => 'entityreference_label',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'rooms_booking',
    'field_name' => 'field_tour_orders',
    'label' => 'Tour Orders',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'entityreference',
      'settings' => array(
        'match_operator' => 'CONTAINS',
        'path' => '',
        'size' => 60,
      ),
      'type' => 'entityreference_autocomplete',
      'weight' => 1,
    ),
  );

  // Exported field_instance: 'rooms_unit-multi_day_tour-field_tours_reference'
  $field_instances['rooms_unit-multi_day_tour-field_tours_reference'] = array(
    'bundle' => 'multi_day_tour',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'tours',
        'settings' => array(
          'book_now' => 1,
          'display_calendar' => 0,
          'enquire_about' => 1,
        ),
        'type' => 'tours_availability_reference_default',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'rooms_unit',
    'field_name' => 'field_tours_reference',
    'label' => 'Tours Reference',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'tours',
      'settings' => array(
        'autocomplete_match' => 'contains',
        'autocomplete_path' => 'tours_availability_reference/autocomplete',
        'size' => 60,
      ),
      'type' => 'tours_availability_reference_autocomplete',
      'weight' => 1,
    ),
  );

  // Exported field_instance:
  // 'rooms_unit-multi_day_tour-rooms_booking_unit_options'
  $field_instances['rooms_unit-multi_day_tour-rooms_booking_unit_options'] = array(
    'bundle' => 'multi_day_tour',
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

  // Exported field_instance:
  // 'rooms_unit-private_single_day_tour_slot-field_day_tour'
  $field_instances['rooms_unit-private_single_day_tour_slot-field_day_tour'] = array(
    'bundle' => 'private_single_day_tour_slot',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'link' => FALSE,
        ),
        'type' => 'entityreference_label',
        'weight' => 3,
      ),
    ),
    'entity_type' => 'rooms_unit',
    'field_name' => 'field_day_tour',
    'label' => 'Day Tour',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'entityreference',
      'settings' => array(
        'match_operator' => 'CONTAINS',
        'path' => '',
        'size' => 60,
      ),
      'type' => 'entityreference_autocomplete',
      'weight' => 2,
    ),
  );

  // Exported field_instance:
  // 'rooms_unit-private_single_day_tour_slot-field_day_tour_time_slot'
  $field_instances['rooms_unit-private_single_day_tour_slot-field_day_tour_time_slot'] = array(
    'bundle' => 'private_single_day_tour_slot',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'timefield',
        'settings' => array(
          'display_format' => array(
            'hour' => 'g',
            'minute' => 'i',
            'period' => 'a',
            'period_separator' => '',
            'separator' => ':',
          ),
        ),
        'type' => 'timefield_default',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'rooms_unit',
    'field_name' => 'field_day_tour_time_slot',
    'label' => 'Day Tour Time Slot',
    'required' => 0,
    'settings' => array(
      'disable_plugin' => 0,
      'input_format' => array(
        'am_text' => 'AM',
        'atPosition' => 'left bottom',
        'closeButtonText' => 'Done',
        'deselectButtonText' => 'Deselect',
        'myPosition' => 'left top',
        'nowButtonText' => 'Now',
        'periodSeparator' => '',
        'pm_text' => 'PM',
        'separator' => ':',
        'showCloseButton' => 0,
        'showDeselectButton' => 0,
        'showLeadingZero' => 0,
        'showNowButton' => 0,
        'showPeriod' => 1,
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'timefield',
      'settings' => array(
        'label_position' => 'above',
      ),
      'type' => 'timefield_standard',
      'weight' => 1,
    ),
  );

  // Exported field_instance:
  // 'rooms_unit-private_single_day_tour_slot-field_variable_pricing'
  $field_instances['rooms_unit-private_single_day_tour_slot-field_variable_pricing'] = array(
    'bundle' => 'private_single_day_tour_slot',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'double_field',
        'settings' => array(
          'first' => array(
            'format' => '_none',
            'hidden' => 0,
            'prefix' => '',
            'suffix' => ':&nbsp;',
          ),
          'second' => array(
            'format' => '_none',
            'hidden' => 0,
            'prefix' => '',
            'suffix' => '',
          ),
          'style' => 'inline',
        ),
        'type' => 'double_field_unformatted_list',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'rooms_unit',
    'field_name' => 'field_variable_pricing',
    'label' => 'Variable Pricing',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'double_field',
      'settings' => array(
        'first' => array(
          'general' => array(
            'prefix' => '',
            'required' => 1,
            'suffix' => '',
          ),
          'textfield' => array(
            'placeholder' => '',
            'size' => 10,
          ),
        ),
        'inline' => 1,
        'second' => array(
          'general' => array(
            'prefix' => '',
            'required' => 1,
            'suffix' => '',
          ),
          'textfield' => array(
            'placeholder' => '',
            'size' => 10,
          ),
        ),
      ),
      'type' => 'textfield_&_textfield',
      'weight' => 3,
    ),
  );

  // Exported field_instance:
  // 'rooms_unit-private_single_day_tour_slot-rooms_booking_unit_options'
  $field_instances['rooms_unit-private_single_day_tour_slot-rooms_booking_unit_options'] = array(
    'bundle' => 'private_single_day_tour_slot',
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

  // Exported field_instance: 'rooms_unit-single_day_tour-field_daily_slot'
  $field_instances['rooms_unit-single_day_tour-field_daily_slot'] = array(
    'bundle' => 'single_day_tour',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'link' => FALSE,
        ),
        'type' => 'entityreference_label',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'rooms_unit',
    'field_name' => 'field_daily_slot',
    'label' => 'Daily Slot',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'inline_entity_form',
      'settings' => array(
        'fields' => array(),
        'type_settings' => array(
          'allow_existing' => 0,
          'allow_new' => 1,
          'delete_references' => 0,
          'label_plural' => 'time slots',
          'label_singular' => 'time slot',
          'match_operator' => 'CONTAINS',
          'override_labels' => 1,
        ),
      ),
      'type' => 'inline_entity_form',
      'weight' => 1,
    ),
  );

  // Exported field_instance:
  // 'rooms_unit-single_day_tour-field_private_daily_slot'
  $field_instances['rooms_unit-single_day_tour-field_private_daily_slot'] = array(
    'bundle' => 'single_day_tour',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'link' => FALSE,
        ),
        'type' => 'entityreference_label',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'rooms_unit',
    'field_name' => 'field_private_daily_slot',
    'label' => 'Private Daily Slot',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'inline_entity_form',
      'settings' => array(
        'fields' => array(),
        'type_settings' => array(
          'allow_existing' => 0,
          'allow_new' => 1,
          'delete_references' => 0,
          'label_plural' => 'private time slots',
          'label_singular' => 'private time slot',
          'match_operator' => 'CONTAINS',
          'override_labels' => 1,
        ),
      ),
      'type' => 'inline_entity_form',
      'weight' => 2,
    ),
  );

  // Exported field_instance:
  // 'rooms_unit-single_day_tour-rooms_booking_unit_options'
  $field_instances['rooms_unit-single_day_tour-rooms_booking_unit_options'] = array(
    'bundle' => 'single_day_tour',
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

  // Exported field_instance: 'rooms_unit-single_day_tour_slot-field_day_tour'
  $field_instances['rooms_unit-single_day_tour_slot-field_day_tour'] = array(
    'bundle' => 'single_day_tour_slot',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'link' => FALSE,
        ),
        'type' => 'entityreference_label',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'rooms_unit',
    'field_name' => 'field_day_tour',
    'label' => 'Day Tour',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'entityreference',
      'settings' => array(
        'match_operator' => 'CONTAINS',
        'path' => '',
        'size' => 60,
      ),
      'type' => 'entityreference_autocomplete',
      'weight' => 2,
    ),
  );

  // Exported field_instance:
  // 'rooms_unit-single_day_tour_slot-field_day_tour_time_slot'
  $field_instances['rooms_unit-single_day_tour_slot-field_day_tour_time_slot'] = array(
    'bundle' => 'single_day_tour_slot',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'timefield',
        'settings' => array(
          'display_format' => array(
            'hour' => 'g',
            'minute' => 'i',
            'period' => 'a',
            'period_separator' => '',
            'separator' => ':',
          ),
        ),
        'type' => 'timefield_default',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'rooms_unit',
    'field_name' => 'field_day_tour_time_slot',
    'label' => 'Day Tour Time Slot',
    'required' => 0,
    'settings' => array(
      'disable_plugin' => FALSE,
      'input_format' => array(
        'am_text' => 'AM',
        'atPosition' => 'left bottom',
        'closeButtonText' => 'Done',
        'deselectButtonText' => 'Deselect',
        'myPosition' => 'left top',
        'nowButtonText' => 'Now',
        'periodSeparator' => '',
        'pm_text' => 'PM',
        'separator' => ':',
        'showCloseButton' => 0,
        'showDeselectButton' => 0,
        'showLeadingZero' => 0,
        'showNowButton' => 0,
        'showPeriod' => 1,
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'timefield',
      'settings' => array(
        'label_position' => 'above',
      ),
      'type' => 'timefield_standard',
      'weight' => 1,
    ),
  );

  // Exported field_instance:
  // 'rooms_unit-single_day_tour_slot-rooms_booking_unit_options'
  $field_instances['rooms_unit-single_day_tour_slot-rooms_booking_unit_options'] = array(
    'bundle' => 'single_day_tour_slot',
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

  // Exported field_instance:
  // 'rooms_unit_type-rooms_unit_type-rooms_booking_unit_options'
  $field_instances['rooms_unit_type-rooms_unit_type-rooms_booking_unit_options'] = array(
    'bundle' => 'rooms_unit_type',
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
    'entity_type' => 'rooms_unit_type',
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
  t('Daily Slot');
  t('Day Tour');
  t('Day Tour Time Slot');
  t('Options');
  t('Private Daily Slot');
  t('Tour Orders');
  t('Tours Reference');
  t('Variable Pricing');

  return $field_instances;
}
