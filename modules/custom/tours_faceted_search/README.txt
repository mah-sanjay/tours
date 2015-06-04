This is an example feature that overrides the standard Rooms /booking page with a Search-API backed view of bookable units, with an availability search filter. It is meant to serve as an example/starting point, and is probably not immediately useful to many people. In particular, for ease of set up, it uses the Search API Database service, where most will want to use Solr in a production environment.

To use:

1. Enable the feature
2. Go to admin/structure/taxonomy/attributes and add some attribute terms
3. Go to admin/rooms/units and add some bookable units of type 'Unit with Attributes'
4. Run cron (this must be done to index your new terms/units, and any time you update any of this data to refresh the indexed data)
5. Go to /booking
