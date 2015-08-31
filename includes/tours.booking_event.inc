<?php

/**
 * @file
 * Class BookingEvent
 */

class ToursBookingEvent extends BookingEvent {

  /**
   * {@inheritdoc}
   */
  public function formatJson($style = ROOMS_AVAILABILITY_ADMIN_STYLE, $unit_name = '') {
    $event = array(
      'id' => $this->id,
      'start' => $this->startYear() . '-' . $this->startMonth('m') . '-' . $this->startDay('d') . 'T13:00:00Z',
      'end' => $this->endYear() . '-' . $this->endMonth('m') . '-' . $this->endDay('d') . 'T13:00:00Z',
      'title' => $this->id,
    );

    // Check if we are dealing with a booking.
    if ($this->id > 10 || $this->id < -10) {
      // Get the actual booking id.
      $booking_id = rooms_availability_return_id($this->id);
      $booking = rooms_booking_load($booking_id);
      if ($style == ROOMS_AVAILABILITY_ADMIN_STYLE) {
        if ($booking->field_tour_partially_booked[LANGUAGE_NONE][0]['value']) {
          $event['title'] = 'P/B';
          $event['color'] = '#6D8C9C';
        }
        elseif ($booking->field_tour_full_booked[LANGUAGE_NONE][0]['value']) {
          $event['title'] = 'F/B';
          $event['color'] = '#481600';
        }
        elseif ($booking->booking_status) {
          $event['title'] = 'CONF';
          $event['color'] = '#017eba';
        }
        else {
          $event['title'] = 'UNCONF';
          $event['color'] = '#C5C5C5';
        }
      }
      elseif ($style == ROOMS_AVAILABILITY_GENERIC_STYLE) {
        $this->id = ROOMS_NOT_AVAILABLE;
      }
    }

    $view_unit_name = array_filter(variable_get('rooms_view_unit_name', array('')));

    // Set the color.
    switch ($this->id) {
      case ROOMS_NOT_AVAILABLE:
        $event['color']  = variable_get('rooms_not_available_color', '#CC2727');
        $event['borderColor']  = variable_get('rooms_not_available_color',
          '#CC2727');
        $event['title'] = variable_get('rooms_not_available_text', 'N/A');
        break;

      case ROOMS_AVAILABLE:
        $event['color'] = variable_get('rooms_available_color', '#8ba175');
        $event['borderColor'] = '#8ba175';
        $event['title'] = variable_get('rooms_available_text', 'AV');
        break;

      case ROOMS_ON_REQUEST:
        $event['color'] = variable_get('rooms_on_request_color', '#C5C5C5');
        $event['title'] = variable_get('rooms_on_request_text', 'ON-REQ');
        break;

      case ROOMS_ANON_BOOKED:
        if ($style == ROOMS_AVAILABILITY_ADMIN_STYLE) {
          $event['color'] = variable_get('rooms_anon_booking_color', '#8C6A5A');
          $event['title'] = variable_get('rooms_anon_booking_text', 'A-B');
        }
        elseif ($style == ROOMS_AVAILABILITY_GENERIC_STYLE) {
          $event['color']  = variable_get('rooms_not_available_color',
            '#910a1c');
          $event['title'] = variable_get('rooms_not_available_text', 'N/A');
        }
        break;

      default:
        if (!isset($event['color'])) {
          $event['color'] = '#017eba';
        }
        break;
    }

    if (!empty($view_unit_name)) {
      $event['title'] = $unit_name;
    }

    return $event;
  }

}
