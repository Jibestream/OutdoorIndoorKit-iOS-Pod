//
//  JMapGMController.h
//  JMapControllerKit
//
//  Created by Louie Yuen on 2019-03-11.
//  Copyright © 2019 Jibestream. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <JMapCoreKit/JMapCoreKit.h>
#import <JMapRenderingKit/JMapRenderingKit.h>
#import <GoogleMaps/GoogleMaps.h>
#import "JMapGMGeometry.h"
#import "JMapGMMap.h"

/**
 *  The JMapGMControllerDelegate Delegate
 */
@protocol JMapGMControllerDelegate <NSObject>

@optional
/**
 *  Delegate method for handling tap gesture
 *
 *  @param mapView GMSMapView object associated to interaction
 *  @param element Element tapped on the map
 *  @param point CGPoint x,y coordinate tapped
 */
- (void)mapView:(nonnull GMSMapView *)mapView detectedTapOnElement:(nullable id)element atPoint:(CGPoint)point;

/**
 *  Delegate method for handling zoom changes
 *
 *  @param mapView GMSMapView object associated to interaction
 *  @param zoomScale float value of changed zoom scale
 */
- (void)mapView:(nonnull GMSMapView *)mapView mapViewDidZoom:(float)zoomScale;

/**
 *  Delegate method for reading rotation of the map
 *  @param mapView GMSMapView object associated to interaction
 *  @param degrees float value for the roation of the map
 */
- (void)mapView:(nonnull GMSMapView *)mapView mapViewDidRotateByDegrees:(float)degrees;

@end

/**
 *  The JMapGMController object
*/
@interface JMapGMController : NSObject

/**
 *  The venue that is currently active and used.
 */
@property(nonatomic, strong, readonly, nullable) JMapActiveVenue *activeVenue;
/**
 *  The current viewing floor.
 */
@property(nonatomic, strong, readonly, nullable) JMapFloor *currentFloor;
/**
 *  The current viewing map.
 */
@property(nonatomic, strong, readonly, nullable) JMapMap *currentMap;
/**
 *  The current viewing GM map.
 */
@property(nonatomic, strong, readonly, nullable) JMapGMMap *currentGMMap;
/**
 *  The current loaded building.
 */
@property(nonatomic, strong, readonly, nullable) JMapBuilding *currentBuilding;

/**
 *  The GM controller kit delegate.
 */
@property (nonatomic, weak, nullable) id<JMapGMControllerDelegate> delegate;

/**
 *  The google maps delegate.
 */
@property(nonatomic, readonly, weak, nullable) id<GMSMapViewDelegate> mapDelegate;

/**
 *  Type definition of the JMapError.
 */
typedef void(^_Nullable ErrorCompletion)(JMapError * _Nullable error);

/**
 *  MapView reference
 */
@property(nonatomic, nullable, strong, readonly) GMSMapView *mapView;

/**
 *  Initializes a JMapJCore object along with canvas and activeVenue.
 *
 *  @param mapView A GMSMapView object that will be used to display the map
 *  @param activeVenue A JMapActiveVenue object to be loaded
 *  @param APIKey The Google Map SDK API Key used to make API requests
 */
-(nonnull instancetype)initWithMapView:(nonnull GMSMapView*)mapView activeVenue:(nonnull JMapActiveVenue *)activeVenue APIKey:(nonnull NSString *)APIKey;

/**
 *  Renders and displays map. This method will also parse the map if needed.
 *
 *  @param map The JMapMap object to be rendered and displayed.
 *  @param completion The completion handler for the API call.
 */
- (void)showMap:(nonnull JMapMap *)map completionHandler:(ErrorCompletion)completion;

/**
 *  Displays the default map.
 *
 *  @param completion The completion handler for the API call.
 */
- (void)showDefaultMapWithCompletionHandler:(ErrorCompletion)completion;

/**
 *  Gets the corresponding JMapGMMap with map ID.
 *
 *  @param mapId The map ID used to search for a JMapGMMap.
 */
- (nullable JMapGMMap *)getGMMapById:(nonnull NSNumber *)mapId;

/**
 *  Parses a map so it is ready to be rendered.
 *
 *  @param map The JMapMap object to be parsed.
 */
- (void)parseMap:(nonnull JMapMap *)map;

/**
 * Parses all maps. Can be used to parse all maps in the active venue before rendering.
 *
 */
- (void)parseAllMaps;

/**
 *  The instance of the user location class.
 */
@property (nonatomic, nonnull) UIView *userLocation;

#pragma mark - Map Layer Helpers

/**
 *  Applies custom styling using a json config file
 *
 *  @param stylesheet NSString containing styles info
 */
- (void)loadJsonStyleConfiguration:(nonnull NSString *)stylesheet;

/**
 *  Define a sequence for map layers to be loaded using a json config file
 *
 *  @param sequence NSString containing sequence info
 */
- (void)loadMapWithSequence:(nonnull NSString *)sequence;

/**
 *  Shows all amenities
 */
- (void)showAllAmenities;

/**
 *  Shows all amenities of a given type that are placed on a certain waypoint.
 *
 *  @param amenity A JMapAmenity which will be used to determine which type of amenities to show.
 *  @param waypoint The waypoint that is associated with the amenities to be shown.
 */
- (void)showAmenity:(nonnull JMapAmenity *)amenity atWaypoint:(nullable JMapWaypoint*)waypoint;

/**
 *  Hides all amenities
 */
- (void)hideAllAmenities;

/**
 *  Hides all amenities of a given type that are placed on a certain waypoint.
 *
 *  @param amenity A JMapAmenity which will be used to determine which type of amenities to hide.
 *  @param waypoint The waypoint that is associated with the amenities to be hidden.
 */
- (void)hideAmenity:(nonnull JMapAmenity *)amenity atWaypoint:(nullable JMapWaypoint*)waypoint;

/**
 *  Shows all path types
 */
- (void)showAllPathTypes;

/**
 *  Shows all path types of a given type that are placed on a certain waypoint.
 *
 *  @param pathType A JMapPathType which will be used to determine which type of path types to show.
 *  @param waypoint The waypoint that is associated with the path types to be shown.
 */
- (void)showPathType:(nonnull JMapPathType*)pathType atWaypoint:(nullable JMapWaypoint*)waypoint;

/**
 *  Hides all path types of a given type that are placed on a certain waypoint.
 *
 *  @param pathType A JMapPathType which will be used to determine which type of path types to hide.
 *  @param waypoint The waypoint that is associated with the path types to be hidden.
 */
- (void)hidePathType:(nonnull JMapPathType*)pathType atWaypoint:(nullable JMapWaypoint*)waypoint;

/**
 *  Hides all path types
 */
- (void)hideAllPathTypes;

/**
 *  Shows the layer with the specified name.
 *
 *  @param name The name of the layer to be shown.
 */
- (void)showLayer:(nonnull NSString *)name;

/**
 *  Hides the layer with the specified name.
 *
 *  @param name The name of the layer to be hidden.
 */
- (void)hideLayer:(nonnull NSString *)name;

/**
 *  Retrieves the JMapGMGeometry shape objects in a map layer.
 *
 *  @param name The name of the layer that the shapes should be retrieved from.
 *  @param map The map that the layer is associated with.
 *  @return An array of JMapGMGeometry shapes.
 */
- (nullable NSArray <JMapGMGeometry *>*)getShapesInLayerWithName:(nonnull NSString *)name fromMap:(nonnull JMapMap *)map;

/**
 *  Gets all the layer names in the map. Used to retrieve all layer names for a particular map.
 *
 *  @param map desired map to retrieve all layer names
 *  @return An array of layer name strings
 */
- (nonnull NSArray <NSString *>*)getAllLayerNamesInMap:(nonnull JMapMap *)map;

/**
 *  Sets the layer interactivity by layer name. Sets all elements within a layer to be interactive.
 *
 *  @param layerName string of the desired layer to be set interactive.
 */
- (void)enableLayerInteractivityForLayerName:(nonnull NSString *)layerName;

/**
 *  Removes the layer interactivity by layer name. Sets all elements within a layer to be non-interactive.
 *
 *  @param layerName string of the desired layer to be set non-interactive.
 */
- (void)disableLayerInteractivityForLayerName:(nonnull NSString *)layerName;

/**
 *  Gets a list of destinations from a shape.
 *
 *  @param shape A JMapGMGeometry object to search JMapDestinations with
 *  @return Array of JMapDestination objects associated with the provided JMapGMGeometry object
 */
- (nonnull NSArray <JMapDestination *>*)getDestinationsFromShape:(nonnull JMapGMGeometry *)shape;

/**
 *  Get a list of waypoints from a shape.
 *
 *  @param shape A JMapGMGeometry object to search JMapWaypoints with
 *  @return Array of JMapWaypoint objects associated with the provided JMapGMGeometry object
 */
- (nonnull NSArray <JMapWaypoint *>*)getWaypointsFromShape:(nonnull JMapGMGeometry *)shape;

#pragma mark - Gestures

/**
 *  Enables rotation gestures on the map.
 */
-(void)enableRotationGestures;

/**
 *  Disables rotation gestures on the map.
 */
-(void)disableRotationGestures;

/**
 *  Enables pan (swipe) gestures on the map.
 */
-(void)enablePanGestures;

/**
 *  Disables pan (swipe) gestures on the map.
 */
-(void)disablePanGestures;

/**
 *  Enables scale (pinch zoom) gestures on the map.
 */
-(void)enableScaleGestures;

/**
 *  Disables scale (pinch zoom) gestures on the map.
 */
-(void)disableScaleGestures;

#pragma mark - Text Map Labels

/**
 *  Shows all text map labels.
 */
- (void)showAllTextMapLabels;

/**
 *  Hides all text map labels.
 */
- (void)hideAllTextMapLabels;

#pragma mark - Units Helpers

/**
 *  Retreive all unit shapes from the given map.
 *
 *  @param map The JMapMap object to get the shapes from.
 *  @return An array of JMapGMGeometry shapes associated to units on that map.
 */
- (nullable NSArray <JMapGMGeometry *>*)getUnitsFromMap:(nonnull JMapMap*)map;

/**
 *  Gets a unit from a waypoint.
 *
 *  @param waypoint A JMapWaypoint object used to search for unit
 *  @return A JMapGMGeometry shape associated to the waypoint.
 */
- (nullable JMapGMGeometry *)getUnitFromWaypoint:(nonnull JMapWaypoint *)waypoint;

/**
 *  Gets a units from a destination.
 *
 *  @param destination A JMapDestination object used to search for units.
 *  @return An array of JMapGMGeometry shapes associated to the destination.
 */
- (nullable NSArray <JMapGMGeometry *>*)getUnitsFromDestination:(nonnull JMapDestination *)destination;

/**
*  Resets all the units back to the original style.
*/
- (void)resetAllUnitStyles;

/**
 *  Hides the contents of a unit.
 *
 *  @param unit A shape representing the unit on the map which will have its text content hidden.
 */
- (void)hideUnitContents:(nonnull JMapGMGeometry *)unit;

/**
 *  Shows the contents of a unit.
 *
 *  @param unit A shape representing the unit on the map which will have its text contents shown.
 */
- (void)showUnitContents:(nonnull JMapGMGeometry *)unit;

/**
 *  Applies display mode to all units.
 */
- (void)applyDisplayModeToAllUnits;

#pragma mark - Wayfinding

/**
 *  Wayfind between two waypoints within the Jibestream map.
 *
 *  @param waypointStart The origin waypoint object to start the wayfinding from.
 *  @param waypointEnd The destination waypoint object to end the wayfinding path.
 *  @param accessibility A NSInteger value between 0-100 to indicate accessibility level; 0 - Not accessible, 100 - Accessible path.
 *  @return An array of GMSPolyline objects to indicate wayfinding paths across all floors. If count is 0 then no paths were found.
 */
- (nonnull NSArray <GMSPolyline *>*)wayfindBetweenWaypoint:(nonnull JMapWaypoint *)waypointStart andWaypoint:(nonnull JMapWaypoint *)waypointEnd withAccessibility:(NSInteger)accessibility;

/**
 *  Wayfind between a waypoints within the Jibestream map to an outdoor geocoordinate.
 *
 *  @param waypointStart The origin waypoint object to start the wayfinding from.
 *  @param geoCoordinate The outdoor geoCoordinate to end the wayfinding path.
 *  @param accessibility A NSInteger value between 0-100 to indicate accessibility level; 0 - Not accessible, 100 - Accessible path.
 *  @param completion A completion block storing paths data. Keys - "indoorPath", "outdoorPath" and "connectingPath" will indicate the indoor wayfinding path, outdoor wayfinding path and the path that connects the two respectively.
 */
- (void)wayfindBetweenWaypoint:(nonnull JMapWaypoint *)waypointStart andGeoCoordinate:(CGPoint)geoCoordinate withAccessibility:(NSInteger)accessibility completion:(void(^ _Nullable)(NSDictionary  * _Nonnull data))completion;

/**
 *  Wayfind between an outdoor geocoordinate to a waypoint within the Jibestream map.
 *
 *  @param geoCoordinate The outdoor geoCoordinate to start the wayfinding from.
 *  @param waypointEnd The destination waypoint object to end the wayfinding path.
 *  @param accessibility A NSInteger value between 0-100 to indicate accessibility level; 0 - Not accessible, 100 - Accessible path.
 *  @param completion A completion block storing paths data. Keys - "indoorPath", "outdoorPath" and "connectingPath" will indicate the indoor wayfinding path, outdoor wayfinding path and the path that connects the two respectively.
 */
- (void)wayfindBetweenGeoCoordinate:(CGPoint)geoCoordinate andWaypoint:(nonnull JMapWaypoint *)waypointEnd withAccessibility:(NSInteger)accessibility completion:(void(^ _Nullable)(NSDictionary  * _Nonnull data))completion;

/**
 *  Wayfind between two outdoor geocoordinates.
 *
 *  @param geoCoordinateFrom The outdoor geoCoordinate to start the wayfinding from.
 *  @param geoCoordinateTo The outdoor geoCoordinate to end the wayfinding path.
 *  @param completion A completion block storing paths data. Returns a GMSPolyline object for the outdoor path.
 */
- (void)wayfindBetweenGeoCoordinate:(CGPoint)geoCoordinateFrom andGeoCoordinate:(CGPoint)geoCoordinateTo completion:(void(^ _Nullable)(GMSPolyline * _Nullable path))completion;

/**
 *  Removes all wayfinding paths on indoor and outdoor maps.
 */
- (void)clearWayfindPath;

#pragma mark - Map Styling Helpers

/**
 *  Resets the styling for the map to its default state.
 */
-(void)resetMapStyle;

/**
 *  Applies a style to all amenities.
 *
 *  @param style A JMapIconStyle object that defines the style to be used for all amenities.
 */
- (void)styleAllAmenities:(nullable JMapIconStyle*)style;

/**
 *  Applies a style to all amenities that are of the provided type and placed at a given waypoint.
 *
 *  @param amenity A JMapAmenity which will determine which type of amenities to style.
 *  @param waypoint The JMapWaypoint that is associated with the amenities to be styled.
 *  @param style A JMapIconStyle object that defines the style that will be applied to the amenities.
 */
- (void)styleAmenity:(nonnull JMapAmenity*)amenity atWaypoint:(nullable JMapWaypoint*)waypoint withStyling:(nonnull JMapIconStyle*)style;

/**
 *  Resets the style of all amenities to their defaults.
 */
- (void)resetAllAmenityStyle;

/**
 *  Resets the style of all amenities that are of the provided type and placed at a given waypoint.
 *
 *  @param amenity A JMapAmenity which will determine which type of amenities will have their styling reset.
 *  @param waypoint The JMapWaypoint that is associated with the amenities that will have their styling reset.
 *  Passing nil to waypoint will reset style for all instances of the amenity type
 */
- (void)resetAmenityStyle:(nonnull JMapAmenity*)amenity atWaypoint:(nullable JMapWaypoint*)waypoint;

/**
 *  Applies a style to all path types.
 *
 *  @param style A JMapPathType object that defines the style to be used for all path types.
 */
- (void)styleAllPathTypes:(nullable JMapIconStyle*)style;

/**
 *  Applies a style to all path types that are of the provided type and placed at a given waypoint.
 *
 *  @param pathType A JMapPathType which will determine which type of path types to style.
 *  @param waypoint The JMapWaypoint that is associated with the path types to be styled.
 *  @param style A JMapIconStyle object that defines the style that will be applied to the path types.
 */
- (void)stylePathType:(nonnull JMapPathType*)pathType atWaypoint:(nullable JMapWaypoint*)waypoint withStyling:(nonnull JMapIconStyle*)style;

/**
 *  Resets the style of all path types to their defaults.
 */
- (void)resetAllPathTypeStyle;

/**
 *  Resets the style of all path types that are of the provided type and placed at a given waypoint.
 *
 *  @param pathType A JMapPathType which will determine which type of path types will have their styling reset.
 *  @param waypoint The JMapWaypoint that is associated with the path types that will have their styling reset.
 *  Passing nil to waypoint will reset style for all instances of the path type
 */
- (void)resetPathTypeStyle:(nonnull JMapPathType *)pathType atWaypoint:(nullable JMapWaypoint*)waypoint;

/**
 *  Resets the style of shapes passed in.
 *
 *  @param shapes An array of JMapGMGeometry shapes to have the style reset.
 */
- (void)resetStyleForShapes:(nonnull NSArray <JMapGMGeometry *>*)shapes;

/**
 *  Zooms to bounds with given top right and bottom left coordinates.
 *
 *  @param northEast The top right coordinate of the bounds.
 *  @param southWest The bottom left coordinate of the bounds.
 */
- (void)zoomToBoundsNorthEast:(CLLocationCoordinate2D)northEast andSouthWest:(CLLocationCoordinate2D)southWest;

/**
 *  Zooms to bounds with given top right and bottom left coordinates.
 */
- (void)zoomToVenue;

/**
 *  Styles the shapes in the list with specific JMapStyle.
 *
 *  @param shapes An array of JMapGMGeometry shapes to be styled.
 *  @param style A JMapStyle object that defines the style.
 */
-(void)styleShapes:(nonnull NSArray <JMapGMGeometry*>*)shapes withStyling:(nonnull JMapStyle*)style;

/**
 *  Applies a style to all empty units
 *
 *  @param style A JMapStyle object that defines the style to be used for all units with Destinations.
 */
- (void)styleEmptyUnits:(nonnull JMapStyle*)style;

/**
 *  Applies a style to all units with Destinations
 *
 *  @param style A JMapStyle object that defines the style to be used for all units with Destinations.
 */
- (void)styleUnitsWithDestinations:(nonnull JMapStyle*)style;

/**
*  Gets the bounds in northeast and southwest lat/lng coordinates for the given shapes.
*
*  @param shapes The shapes array to generate the bounds
*/
- (nonnull NSArray <NSArray <NSNumber *>*>*)getBoundsFromShapes:(nonnull NSArray <JMapGMGeometry*>*)shapes;

#pragma mark - User Location Methods

/**
 *  Updates the user's location with a new position on the map.
 *
 *  @param position A CGPoint indicating user's location in x,y coordinates
 *  @param map A JMapMap object that the location is currently on
 *  @param orientation A NSInteger float value to determine the icon's angle relative to the map's true north (degrees)
 *  @param confidence A NSInteger integer value indicating the radius of confidence measured in pixels
 */
- (void)updateUserLocation:(CGPoint)position floorMap:(nonnull JMapMap *)map orientation:(nullable NSNumber *)orientation confidenceRadius:(nullable NSNumber *)confidence;

@end
