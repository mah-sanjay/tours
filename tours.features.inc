<?php
/**
 * @file
 * tours.features.inc
 */

/**
 * Implements hook_default_cer().
 */
function tours_default_cer() {
  $items = array();
  $items['rooms_unit:single_day_tour:field_daily_slot*rooms_unit:single_day_tour_slot:field_day_tour'] = entity_import('cer', '{
    "identifier" : "rooms_unit:single_day_tour:field_daily_slot*rooms_unit:single_day_tour_slot:field_day_tour",
    "cer_bidirectional" : { "und" : [ { "value" : "1" } ] },
    "cer_enabled" : { "und" : [ { "value" : "1" } ] },
    "cer_weight" : { "und" : [ { "value" : "0" } ] },
    "cer_left" : { "und" : [ { "path" : "rooms_unit:single_day_tour:field_daily_slot" } ] },
    "cer_right" : { "und" : [ { "path" : "rooms_unit:single_day_tour_slot:field_day_tour" } ] },
    "rdf_mapping" : []
  }');
  return $items;
}

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
  $items['private_single_day_tour_slot'] = entity_import('rooms_unit_type', '{
    "type" : "private_single_day_tour_slot",
    "label" : "Private Single-Day Tour Slot",
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
