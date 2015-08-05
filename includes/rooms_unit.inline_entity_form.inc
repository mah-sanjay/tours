<?php

/**
 * @file
 * Defines the inline entity form controller for Nodes.
 */

class RoomsUnitInlineEntityFormController extends EntityInlineEntityFormController {

  /**
   * Overrides EntityInlineEntityFormController::tableFields().
   */
  public function tableFields($bundles) {
    $fields = parent::tableFields($bundles);

    // No need to display unit id
    $fields['unit_id'];

    $fields['field_day_tour_time_slot'] = array(
      'type' => 'field',
      'label' => t('Day Tour Time Slot'),
      'formatter' => 'timefield_default',
      'weight' => 2,
    );

    return $fields;
  }

  /**
   * Overrides EntityInlineEntityFormController::entityForm().
   */
  public function entityForm($entity_form, &$form_state) {
    $rooms_unit = $entity_form['#entity'];

    field_attach_form('rooms_unit', $rooms_unit, $entity_form, $form_state, LANGUAGE_NONE);
    unset($entity_form['rooms_booking_unit_options']);
    return $entity_form;
  }

  /**
   * Overrides EntityInlineEntityFormController::entityFormSubmit().
   */
  public function entityFormSubmit(&$entity_form, &$form_state) {
    parent::entityFormSubmit($entity_form, $form_state);

    $child_form_state = form_state_defaults();
    $child_form_state['values'] = drupal_array_get_nested_value($form_state['values'], $entity_form['#parents']);
  }
}
