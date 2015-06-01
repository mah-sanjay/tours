api = 2
core = 7.x

; Drupal core.
projects[drupal][type] = core
projects[drupal][version] = 7.35
projects[drupal][patch][] = "https://drupal.org/files/issues/install-redirect-on-empty-database-728702-36.patch"

; Drush make allows a default sub directory for all contributed projects.
defaults[projects][subdir] = contrib

; Platform indicator module.
projects[platform][version] = 1.3


; +++++ Modules +++++
projects[rooms][version] = 1.x-dev
projects[addressfield][subdir] = "contrib"

projects[addressfield][version] = "1.0"
projects[addressfield][subdir] = "contrib"

projects[chosen][version] = "2.0-beta4"
projects[chosen][subdir] = "contrib"

projects[commerce][version] = "1.11"
projects[commerce][subdir] = "contrib"

projects[commerce_cart_expiration][version] = "1.2"
projects[commerce_cart_expiration][subdir] = "contrib"

projects[ctools][version] = "1.6"
projects[ctools][subdir] = "contrib"

projects[date][version] = "2.8"
projects[date][subdir] = "contrib"

projects[devel][version] = "1.5"
projects[devel][subdir] = "contrib"

projects[diff][version] = "3.2"
projects[diff][subdir] = "contrib"

projects[entity][version] = "1.5"
projects[entity][subdir] = "contrib"

projects[environment_indicator][version] = "2.5"
projects[environment_indicator][subdir] = "contrib"

projects[facetapi][version] = "1.5"
projects[facetapi][subdir] = "contrib"

projects[features][version] = "2.3"
projects[features][subdir] = "contrib"

projects[field_group][version] = "1.4"
projects[field_group][subdir] = "contrib"

projects[inline_entity_form][version] = "1.5"
projects[inline_entity_form][subdir] = "contrib"

projects[entityreference][version] = "1.1"
projects[entityreference][subdir] = "contrib"

projects[jquery_update][version] = "2.5"
projects[jquery_update][subdir] = "contrib"

projects[libraries][version] = "2.2"
projects[libraries][subdir] = "contrib"

projects[navbar][version] = "1.5"
projects[navbar][subdir] = "contrib"

projects[panels][version] = "3.5"
projects[panels][subdir] = "contrib"

projects[panels_everywhere][version] = "1.0-rc2"
projects[panels_everywhere][subdir] = "contrib"

projects[panels_bootstrap_layouts][version] = "3.0"
projects[panels_bootstrap_layouts][subdir] = "contrib"

projects[panels_tabs][version] = "2.x-dev"
projects[panels_tabs][subdir] = "contrib"

projects[rules][version] = "2.7"
projects[rules][subdir] = "contrib"

projects[search_api][version] = "1.14"
projects[search_api][subdir] = "contrib"

projects[search_api_db][version] = "1.4"
projects[search_api_db][subdir] = "contrib"

projects[strongarm][version] = "2.0"
projects[strongarm][subdir] = "contrib"

projects[token][version] = "1.5"
projects[token][subdir] = "contrib"

projects[timefield][version] = "1.x-dev"
projects[timefield][subdir] = "contrib"

projects[variable][version] = "2.5"
projects[variable][subdir] = "contrib"

projects[views][version] = "3.8"
projects[views][subdir] = "contrib"

projects[views_bootstrap][version] = "3.1"
projects[views_bootstrap][subdir] = "contrib"

projects[views_php][version] = "1.0-alpha1"
projects[views_php][subdir] = "contrib"

project[module_filter][version] = "2.0"
project[module_filter][subdir] = "contrib"

; +++++ Themes +++++

; bootstrap
projects[bootstrap][type] = "theme"
projects[bootstrap][version] = "3.x-dev"
projects[bootstrap][subdir] = "contrib"

; shiny
projects[shiny][type] = "theme"
projects[shiny][version] = "1.6"
projects[shiny][subdir] = "contrib"

; +++++ Libraries +++++

; backbone
libraries[backbone][directory_name] = "backbone"
libraries[backbone][type] = "library"
libraries[backbone][destination] = "libraries"
libraries[backbone][download][type] = "get"
libraries[backbone][download][url] = "https://github.com/documentcloud/backbone/archive/1.0.0.zip"

; chosen
libraries[chosen][directory_name] = "chosen"
libraries[chosen][type] = "library"
libraries[chosen][destination] = "libraries"
libraries[chosen][download][type] = "get"
libraries[chosen][download][url] = "https://github.com/harvesthq/chosen/releases/download/1.4.2/chosen_v1.4.2.zip"

; modernizr
libraries[modernizr][directory_name] = "modernizr"
libraries[modernizr][type] = "library"
libraries[modernizr][destination] = "libraries"
libraries[modernizr][download][type] = "get"
libraries[modernizr][download][url] = "https://github.com/Modernizr/Modernizr/archive/v2.7.1.zip"

; moment
libraries[moment][directory_name] = "moment"
libraries[moment][type] = "library"
libraries[moment][destination] = "libraries"
libraries[moment][download][type] = "get"
libraries[moment][download][url] = "http://momentjs.com/downloads/moment.min.js"

; fullcalendar
libraries[rooms_fullcalendar][download][type] = "file"
libraries[rooms_fullcalendar][download][url] = "https://github.com/Roomify/fullcalendar/archive/master.zip"
libraries[rooms_fullcalendar][directory_name] = "rooms_fullcalendar"
libraries[rooms_fullcalendar][type] = "library"

; underscore
libraries[underscore][directory_name] = "underscore"
libraries[underscore][type] = "library"
libraries[underscore][destination] = "libraries"
libraries[underscore][download][type] = "get"
libraries[underscore][download][url] = "https://github.com/documentcloud/underscore/archive/1.6.0.zip"

; jquery.timepicker
libraries[jquery.timepicker][directory_name] = "jquery.timepicker"
libraries[jquery.timepicker][type] = "library"
libraries[jquery.timepicker][destination] = "libraries"
libraries[jquery.timepicker][download][type] = "get"
libraries[jquery.timepicker][download][url] = "https://fgelinas.com/code/timepicker/releases/jquery-ui-timepicker-0.3.3.zip"

