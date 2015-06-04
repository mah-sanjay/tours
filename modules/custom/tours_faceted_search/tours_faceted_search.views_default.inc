<?php
/**
 * @file
 * tours_faceted_search.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function tours_faceted_search_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'filtered_availability_search';
  $view->description = 'Overrides Drupal Rooms\' default booking page with a filtered availability search';
  $view->tag = 'default';
  $view->base_table = 'search_api_index_default_unit_index';
  $view->human_name = 'Filtered Availability Search';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Filtered Availability Search';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Indexed Bookable Units: Bookable units ID */
  $handler->display->display_options['fields']['unit_id']['id'] = 'unit_id';
  $handler->display->display_options['fields']['unit_id']['table'] = 'search_api_index_default_unit_index';
  $handler->display->display_options['fields']['unit_id']['field'] = 'unit_id';
  $handler->display->display_options['fields']['unit_id']['label'] = '';
  $handler->display->display_options['fields']['unit_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['unit_id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['unit_id']['separator'] = '';
  $handler->display->display_options['fields']['unit_id']['link_to_entity'] = 0;
  /* Field: Indexed Bookable Units: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'search_api_index_default_unit_index';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_entity'] = 1;
  /* Filter criterion: Indexed Bookable Units: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'search_api_index_default_unit_index';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'unit_with_attributes' => 'unit_with_attributes',
    'single_day_tour' => 'single_day_tour',
    'single_day_tour_slot' => 'single_day_tour_slot',
    'multi_day_tour' => 'multi_day_tour',
  );
  /* Filter criterion: Indexed Bookable Units: Bookable */
  $handler->display->display_options['filters']['bookable']['id'] = 'bookable';
  $handler->display->display_options['filters']['bookable']['table'] = 'search_api_index_default_unit_index';
  $handler->display->display_options['filters']['bookable']['field'] = 'bookable';
  $handler->display->display_options['filters']['bookable']['value'] = '1';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'booking';
  $export['filtered_availability_search'] = $view;

  return $export;
}
