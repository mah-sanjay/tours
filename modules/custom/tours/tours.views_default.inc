<?php
/**
 * @file
 * tours.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function tours_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'upcoming_tours_by_unit';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'rooms_bookings';
  $view->human_name = 'Upcoming tours by unit';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Upcoming Tour Dates';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Bookings: Unit ID */
  $handler->display->display_options['relationships']['unit_id']['id'] = 'unit_id';
  $handler->display->display_options['relationships']['unit_id']['table'] = 'rooms_bookings';
  $handler->display->display_options['relationships']['unit_id']['field'] = 'unit_id';
  $handler->display->display_options['relationships']['unit_id']['required'] = TRUE;
  /* Field: Bookings: Bookings ID */
  $handler->display->display_options['fields']['booking_id']['id'] = 'booking_id';
  $handler->display->display_options['fields']['booking_id']['table'] = 'rooms_bookings';
  $handler->display->display_options['fields']['booking_id']['field'] = 'booking_id';
  $handler->display->display_options['fields']['booking_id']['label'] = '';
  $handler->display->display_options['fields']['booking_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['booking_id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['booking_id']['separator'] = '';
  /* Field: Bookings: Start Date */
  $handler->display->display_options['fields']['start_date']['id'] = 'start_date';
  $handler->display->display_options['fields']['start_date']['table'] = 'rooms_bookings';
  $handler->display->display_options['fields']['start_date']['field'] = 'start_date';
  $handler->display->display_options['fields']['start_date']['label'] = '';
  $handler->display->display_options['fields']['start_date']['exclude'] = TRUE;
  $handler->display->display_options['fields']['start_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['start_date']['date_format'] = 'short';
  $handler->display->display_options['fields']['start_date']['second_date_format'] = 'long';
  /* Field: Bookings: End Date */
  $handler->display->display_options['fields']['end_date']['id'] = 'end_date';
  $handler->display->display_options['fields']['end_date']['table'] = 'rooms_bookings';
  $handler->display->display_options['fields']['end_date']['field'] = 'end_date';
  $handler->display->display_options['fields']['end_date']['label'] = '';
  $handler->display->display_options['fields']['end_date']['exclude'] = TRUE;
  $handler->display->display_options['fields']['end_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['end_date']['date_format'] = 'short';
  $handler->display->display_options['fields']['end_date']['second_date_format'] = 'long';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[start_date] - [end_date]';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Contextual filter: Bookable Units: Bookable units ID */
  $handler->display->display_options['arguments']['unit_id']['id'] = 'unit_id';
  $handler->display->display_options['arguments']['unit_id']['table'] = 'rooms_units';
  $handler->display->display_options['arguments']['unit_id']['field'] = 'unit_id';
  $handler->display->display_options['arguments']['unit_id']['relationship'] = 'unit_id';
  $handler->display->display_options['arguments']['unit_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['unit_id']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['unit_id']['default_argument_options']['index'] = '1';
  $handler->display->display_options['arguments']['unit_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['unit_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['unit_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['unit_id']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['unit_id']['validate']['type'] = 'numeric';
  /* Filter criterion: Bookings: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'rooms_bookings';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'tour_instance' => 'tour_instance',
  );
  /* Filter criterion: Bookings: Booking_status */
  $handler->display->display_options['filters']['booking_status']['id'] = 'booking_status';
  $handler->display->display_options['filters']['booking_status']['table'] = 'rooms_bookings';
  $handler->display->display_options['filters']['booking_status']['field'] = 'booking_status';
  $handler->display->display_options['filters']['booking_status']['value']['value'] = '0';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
  $export['upcoming_tours_by_unit'] = $view;

  return $export;
}
