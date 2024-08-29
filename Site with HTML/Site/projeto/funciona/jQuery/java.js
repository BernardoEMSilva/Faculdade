/**
 * Adds three markers and alters the view bounds of the map to ensure that all
 * markers are visible
 *
 * @param  {H.Map} map      A HERE Map instance within the application
 */
function addMarkersAndSetViewBounds() {
  // create map objects
  var po1 = new H.map.Marker({lat:38.81394751662163,  lng:-369.36208963394165}),
      po2 = new H.map.Marker({lat:38.77322388791319, lng:-369.31640625}),
      po3 = new H.map.Marker({lat:38.78867986456369, lng:-369.33966636657715}),
      po4 = new H.map.Marker({lat:38.7746625725795, lng:-369.34176921844477}),
      po5 = new H.map.Marker({lat:38.77596740101918, lng:-369.3385934829712}),
      po6 = new H.map.Marker({lat:38.7784431637227, lng:-369.34842109680176}),
      po7 = new H.map.Marker({lat:38.737649039950796, lng:-369.39910411834717}),
      po8 = new H.map.Marker({lat:38.70587438959806, lng:-369.30155754089355}),
      po9 = new H.map.Marker({lat:38.741381382702045, lng:-369.2328929901123}),
      po10 = new H.map.Marker({lat:38.79195797438578, lng:-369.1958999633789}),
      po11 = new H.map.Marker({lat:38.781855560628394, lng:-369.11723613739014}),
      po12 = new H.map.Marker({lat:38.75813267961184, lng:-369.11320209503174}),
      po13 = new H.map.Marker({lat:38.76766125852377, lng:-369.0968298912048}),
      group = new H.map.Group();

  // add markers to the group
  group.addObjects([po1, po2, po3, po4, po5, po6, po7, po8, po9, po10, po11, po12, po13]);
  map.addObject(group);

  // get geo bounding box for the group and set it to the map
  map.getViewModel().setLookAtData({
    bounds: group.getBoundingBox()
  });
}

/**
 * Boilerplate map initialization code starts below:
 */

//Step 1: initialize communication with the platform
// In your own code, replace variable window.apikey with your own apikey
var platform = new H.service.Platform({
  apikey: 'Ey2ffFpa_oCdcte-C3HJd3wAoWmBPPmN4_fOgM8vqyA'
});
var defaultLayers = platform.createDefaultLayers();

//Step 2: initialize a map - this map is centered over Europe
// note that all the markers are in North America...
var map = new H.Map(document.getElementById('map'),
  defaultLayers.vector.normal.map,{
  center: {lat:52, lng:5},
  zoom: 5,
  pixelRatio: window.devicePixelRatio || 1
});
// add a resize listener to make sure that the map occupies the whole container
window.addEventListener('resize', () => map.getViewPort().resize());

//Step 3: make the map interactive
// MapEvents enables the event system
// Behavior implements default interactions for pan/zoom (also on mobile touch environments)
var behavior = new H.mapevents.Behavior(new H.mapevents.MapEvents(map));

// Now use the map as required...
addMarkersAndSetViewBounds(map);