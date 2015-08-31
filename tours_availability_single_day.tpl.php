<div class="tours-base-price">Starting from: <?php print $tours_availability_single_day['base_price']; ?></div>

<?php if ($tours_availability_single_day['settings']['display_calendar']):
        print render($tours_availability_single_day['form']);
      endif; ?>

<?php if ($tours_availability_single_day['settings']['enquire_about']): ?>
	<div class="enquire-about"><a href="/enquiry-tour/">Enquire about this Tour</a></div>
<?php endif; ?>
