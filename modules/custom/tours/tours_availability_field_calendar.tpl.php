<?php $bookings = $tours_availability_field_calendar['bookings']; ?>

<table width="100%" class="tours-availability">
  <thead>
    <th width="20%">Start Date</th>
    <th width="20%">End Date</th>
    <th width="20%">Price</th>
    <th width="40%"></th>
  </thead>

  <tbody>
    <?php foreach ($bookings as $booking) { ?>

    <tr>
      <td class="start-date"><?php print $booking['start_date'] ?></td>
      <td class="end-date"><?php print $booking['end_date'] ?></td>
      <td class="price"><?php print $booking['price'] ?></td>

      <td class="enquire">
        <?php if ($booking['settings']['enquire_about']): ?>
          <div class="enquire-about"><a href="/enquiry-tour/<?php print $booking['id']; ?>">Enquire about this Tour</a></div>
        <?php endif; ?>

        <?php if ($booking['settings']['book_now']): ?>
          <div class="enquire-about"><?php print drupal_render($booking['book_now']); ?></div>
        <?php endif; ?>
      </td>
    </tr>

    <?php } ?>
  </tbody>
</table>
