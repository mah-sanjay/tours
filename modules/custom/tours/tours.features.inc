<?php
/**
 * @file
 * tours.features.inc
 */

/**
 * Implements hook_views_api().
 */
function tours_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_default_rooms_booking_type().
 */
function tours_default_rooms_booking_type() {
  $items = array();
  $items['tour_instance'] = entity_import('rooms_booking_type', '{
    "type" : "tour_instance",
    "label" : "Tour Instance",
    "weight" : "0",
    "data" : "",
    "rdf_mapping" : []
  }');
  return $items;
}

/**
 * Implements hook_default_rooms_unit_type().
 */
function tours_default_rooms_unit_type() {
  $items = array();
  $items['multi_day_tour'] = entity_import('rooms_unit_type', '{
    "type" : "multi_day_tour",
    "label" : "Multi-Day Tour",
    "weight" : "0",
    "data" : {
      "base_price" : "",
      "min_sleeps" : "",
      "max_sleeps" : "",
      "min_children" : "",
      "max_children" : "",
      "rooms_description_source" : ""
    },
    "rooms_booking_unit_options" : [],
    "rdf_mapping" : []
  }');
  $items['single_day_tour'] = entity_import('rooms_unit_type', '{
    "type" : "single_day_tour",
    "label" : "Single-Day Tour",
    "weight" : "0",
    "data" : {
      "base_price" : "",
      "min_sleeps" : "",
      "max_sleeps" : "",
      "min_children" : "",
      "max_children" : "",
      "rooms_description_source" : ""
    },
    "rooms_booking_unit_options" : [],
    "rdf_mapping" : []
  }');
  $items['single_day_tour_slot'] = entity_import('rooms_unit_type', '{
    "type" : "single_day_tour_slot",
    "label" : "Single-Day Tour Slot",
    "weight" : "0",
    "data" : {
      "base_price" : "1",
      "min_sleeps" : "",
      "max_sleeps" : "",
      "min_children" : "",
      "max_children" : "",
      "rooms_description_source" : ""
    },
    "rooms_booking_unit_options" : [],
    "rdf_mapping" : []
  }');
  return $items;
}
