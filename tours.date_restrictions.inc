<?php


/**
 * Implements hook_date_restrictions_allowed_values_info().
 */
function tours_date_restrictions_allowed_values_info() {
  return array(
    'tours' => array(
      'title' => t('Tours'),
      'settings' => array(),
    ),
  );
}

/**
 * Implements allowed_values_valid_date callback.
 */
function tours_allowed_values_valid_date($date, $type, $settings, $element, $form_state, $form) {
  return TRUE;
}

/**
 * Implements allowed_values_remitter_pack callback.
 */
function tours_allowed_values_remitter_pack($type, $element, $form_state, $context) {
  return $element['#restrictions']['allowed_values']['tour_id'];
}

/**
 * Implements allowed_values_remitter_unpack callback.
 */
function tours_allowed_values_remitter_unpack($type, $remitter) {
  return $remitter;
}

/**
 * Implements allowed_values_access_callback callback.
 */
function tours_allowed_values_access_callback($type, $remitter) {
  return TRUE;
}

/**
 * Implements allowed_values_page_callback callback.
 */
function tours_allowed_values_page_callback($type, $remitter, $year, $month) {
  $dates = array();

  $single_day_tour = rooms_unit_load($remitter);

  $single_day_tour_slots = array();
  foreach ($single_day_tour->field_daily_slot[LANGUAGE_NONE] as $slot) {
    $single_day_tour_slots[] = $slot['target_id'];
  }
  foreach ($single_day_tour->field_private_daily_slot[LANGUAGE_NONE] as $slot) {
    $single_day_tour_slots[] = $slot['target_id'];
  }

  $booking_ids = rooms_booking_ids(array('unit_id' => $single_day_tour_slots));

  $bookings = rooms_booking_load_multiple(array_keys($booking_ids), array('type' => 'tour_instance'));

  $now = new DateTime();
  foreach ($bookings as $booking) {
    if (!$booking->field_tour_full_booked[LANGUAGE_NONE][0]['value']) {
      if ($booking->end_date_object > $now) {
        $start = $booking->start_date_object;
        $end = $booking->end_date_object;
        $end = $end->modify('+1 day');

        $interval = new DateInterval('P1D');
        $period = new DatePeriod($start, $interval, $end);

        foreach ($period as $dt) {
          $dates[] = $dt->format('Y-m-d');
        }
      }
    }
  }

  return $dates;
}
