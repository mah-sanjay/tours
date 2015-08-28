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
    unset($entity_form['field_day_tour']);

    $entity_form['tour_capacity'] = array(
      '#type' => 'fieldset',
      '#title' => t('Tour capacity'),
      '#tree' => TRUE,
      '#attributes' => array('class' => array('rooms-unit-guest-capacity')),
    );

    $entity_form['tour_capacity']['min_sleeps'] = array(
      '#type' => 'textfield',
      '#size' => 5,
      '#default_value' => ($rooms_unit->min_sleeps != '') ? $rooms_unit->min_sleeps : $form_state['input']['min_sleeps'],
      '#field_suffix' => t('Person minimum'),
    );

    $entity_form['tour_capacity']['max_sleeps'] = array(
      '#type' => 'textfield',
      '#size' => 5,
      '#default_value' => ($rooms_unit->max_sleeps != '') ? $rooms_unit->max_sleeps : $form_state['input']['max_sleeps'],
      '#field_suffix' => t('Person maximum'),
      '#description' => t('The total number of people that can participate in the tour.'),
    );

    return $entity_form;
  }

  /**
   * Overrides EntityInlineEntityFormController::entityFormSubmit().
   */
  public function entityFormSubmit(&$entity_form, &$form_state) {
    parent::entityFormSubmit($entity_form, $form_state);

    $child_form_state = form_state_defaults();
    $child_form_state['values'] = drupal_array_get_nested_value($form_state['values'], $entity_form['#parents']);

    $entity_form['#entity']->min_sleeps = $child_form_state['values']['tour_capacity']['min_sleeps'];
    $entity_form['#entity']->max_sleeps = $child_form_state['values']['tour_capacity']['max_sleeps'];

    unset($entity_form['#entity']->tour_capacity);
  }
}
