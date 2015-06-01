<?php
/**
 * @file
 * rooms_faceted_search.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function rooms_faceted_search_taxonomy_default_vocabularies() {
  return array(
    'attributes' => array(
      'name' => 'Attributes',
      'machine_name' => 'attributes',
      'description' => 'Bookable unit attributes',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
  );
}
