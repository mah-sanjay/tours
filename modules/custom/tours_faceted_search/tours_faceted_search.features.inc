<?php
/**
 * @file
 * tours_faceted_search.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function tours_faceted_search_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "facetapi" && $api == "facetapi_defaults") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function tours_faceted_search_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_default_rooms_unit_type().
 */
function tours_faceted_search_default_rooms_unit_type() {
  $items = array();
  $items['unit_with_attributes'] = entity_import('rooms_unit_type', '{
    "type" : "unit_with_attributes",
    "label" : "Unit with Attributes",
    "weight" : "0",
    "data" : {
      "base_price" : "99",
      "min_sleeps" : "1",
      "max_sleeps" : "2",
      "min_children" : "0",
      "max_children" : "1",
      "rooms_description_source" : ""
    },
    "rooms_booking_unit_options" : [],
    "rdf_mapping" : []
  }');
  return $items;
}

/**
 * Implements hook_default_search_api_index().
 */
function tours_faceted_search_default_search_api_index() {
  $items = array();
  $items['default_unit_index'] = entity_import('search_api_index', '{
    "name" : "Default unit index",
    "machine_name" : "default_unit_index",
    "description" : null,
    "server" : "db",
    "item_type" : "rooms_unit",
    "options" : {
      "index_directly" : 0,
      "cron_limit" : "50",
      "fields" : {
        "base_price" : { "type" : "decimal" },
        "bookable" : { "type" : "integer" },
        "changed" : { "type" : "integer" },
        "created" : { "type" : "integer" },
        "field_attributes" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "max_children" : { "type" : "integer" },
        "max_sleeps" : { "type" : "integer" },
        "min_children" : { "type" : "integer" },
        "min_sleeps" : { "type" : "integer" },
        "name" : { "type" : "text" },
        "search_api_language" : { "type" : "string" },
        "status" : { "type" : "integer" },
        "type" : { "type" : "string" },
        "unit_id" : { "type" : "integer" }
      },
      "data_alter_callbacks" : {
        "search_api_alter_bundle_filter" : {
          "status" : 1,
          "weight" : "-10",
          "settings" : {
            "default" : "1",
            "bundles" : {
              "single_day_tour_slot" : "single_day_tour_slot",
              "unit_with_attributes" : "unit_with_attributes"
            }
          }
        },
        "search_api_alter_add_hierarchy" : { "status" : 0, "weight" : "0", "settings" : { "fields" : [] } },
        "search_api_alter_add_viewed_entity" : { "status" : 0, "weight" : "0", "settings" : { "mode" : "Tokens" } },
        "search_api_alter_add_aggregation" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_url" : { "status" : 0, "weight" : "0", "settings" : [] }
      },
      "processors" : {
        "search_api_case_ignore" : {
          "status" : 0,
          "weight" : "0",
          "settings" : { "fields" : { "name" : true } }
        },
        "search_api_html_filter" : {
          "status" : 0,
          "weight" : "10",
          "settings" : {
            "fields" : { "name" : true },
            "title" : 0,
            "alt" : 1,
            "tags" : "h1 = 5\\r\\nh2 = 3\\r\\nh3 = 2\\r\\nstrong = 2\\r\\nb = 2\\r\\nem = 1.5\\r\\nu = 1.5"
          }
        },
        "search_api_tokenizer" : {
          "status" : 0,
          "weight" : "20",
          "settings" : {
            "fields" : { "name" : true },
            "spaces" : "[^[:alnum:]]",
            "ignorable" : "[\\u0027]"
          }
        },
        "search_api_stopwords" : {
          "status" : 0,
          "weight" : "30",
          "settings" : {
            "fields" : { "name" : true },
            "file" : "",
            "stopwords" : "but\\r\\ndid\\r\\nthe this that those\\r\\netc"
          }
        },
        "search_api_highlighting" : {
          "status" : 0,
          "weight" : "35",
          "settings" : {
            "prefix" : "\\u003Cstrong\\u003E",
            "suffix" : "\\u003C\\/strong\\u003E",
            "excerpt" : 1,
            "excerpt_length" : "256",
            "exclude_fields" : [],
            "highlight" : "always"
          }
        }
      }
    },
    "enabled" : "1",
    "read_only" : "0",
    "rdf_mapping" : []
  }');
  return $items;
}

/**
 * Implements hook_default_search_api_server().
 */
function tours_faceted_search_default_search_api_server() {
  $items = array();
  $items['db'] = entity_import('search_api_server', '{
    "name" : "DB",
    "machine_name" : "db",
    "description" : "",
    "class" : "search_api_db_service",
    "options" : {
      "database" : "default:default",
      "min_chars" : 1,
      "partial_matches" : 0,
      "indexes" : {
        "default_node_index" : {
          "type" : {
            "table" : "search_api_db_default_node_index",
            "column" : "type",
            "type" : "string",
            "boost" : "1.0"
          },
          "title" : {
            "table" : "search_api_db_default_node_index_text",
            "type" : "text",
            "boost" : "5.0"
          },
          "promote" : {
            "table" : "search_api_db_default_node_index",
            "column" : "promote",
            "type" : "boolean",
            "boost" : "1.0"
          },
          "sticky" : {
            "table" : "search_api_db_default_node_index",
            "column" : "sticky",
            "type" : "boolean",
            "boost" : "1.0"
          },
          "created" : {
            "table" : "search_api_db_default_node_index",
            "column" : "created",
            "type" : "date",
            "boost" : "1.0"
          },
          "changed" : {
            "table" : "search_api_db_default_node_index",
            "column" : "changed",
            "type" : "date",
            "boost" : "1.0"
          },
          "author" : {
            "table" : "search_api_db_default_node_index",
            "column" : "author",
            "type" : "integer",
            "boost" : "1.0"
          },
          "comment_count" : {
            "table" : "search_api_db_default_node_index",
            "column" : "comment_count",
            "type" : "integer",
            "boost" : "1.0"
          },
          "search_api_language" : {
            "table" : "search_api_db_default_node_index",
            "column" : "search_api_language",
            "type" : "string",
            "boost" : "1.0"
          },
          "body:value" : {
            "table" : "search_api_db_default_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "unit_description_description" : {
            "table" : "search_api_db_default_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          }
        },
        "default_unit_index" : {
          "unit_id" : {
            "table" : "search_api_db_default_unit_index",
            "column" : "unit_id",
            "type" : "integer",
            "boost" : "1.0"
          },
          "type" : {
            "table" : "search_api_db_default_unit_index",
            "column" : "type",
            "type" : "string",
            "boost" : "1.0"
          },
          "name" : {
            "table" : "search_api_db_default_unit_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "created" : {
            "table" : "search_api_db_default_unit_index",
            "column" : "created",
            "type" : "integer",
            "boost" : "1.0"
          },
          "changed" : {
            "table" : "search_api_db_default_unit_index",
            "column" : "changed",
            "type" : "integer",
            "boost" : "1.0"
          },
          "base_price" : {
            "table" : "search_api_db_default_unit_index",
            "column" : "base_price",
            "type" : "decimal",
            "boost" : "1.0"
          },
          "bookable" : {
            "table" : "search_api_db_default_unit_index",
            "column" : "bookable",
            "type" : "integer",
            "boost" : "1.0"
          },
          "min_sleeps" : {
            "table" : "search_api_db_default_unit_index",
            "column" : "min_sleeps",
            "type" : "integer",
            "boost" : "1.0"
          },
          "max_sleeps" : {
            "table" : "search_api_db_default_unit_index",
            "column" : "max_sleeps",
            "type" : "integer",
            "boost" : "1.0"
          },
          "min_children" : {
            "table" : "search_api_db_default_unit_index",
            "column" : "min_children",
            "type" : "integer",
            "boost" : "1.0"
          },
          "max_children" : {
            "table" : "search_api_db_default_unit_index",
            "column" : "max_children",
            "type" : "integer",
            "boost" : "1.0"
          },
          "status" : {
            "table" : "search_api_db_default_unit_index",
            "column" : "status",
            "type" : "integer",
            "boost" : "1.0"
          },
          "search_api_language" : {
            "table" : "search_api_db_default_unit_index",
            "column" : "search_api_language",
            "type" : "string",
            "boost" : "1.0"
          },
          "field_attributes" : {
            "table" : "search_api_db_default_unit_index_field_attributes",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          }
        }
      }
    },
    "enabled" : "1",
    "rdf_mapping" : []
  }');
  return $items;
}
