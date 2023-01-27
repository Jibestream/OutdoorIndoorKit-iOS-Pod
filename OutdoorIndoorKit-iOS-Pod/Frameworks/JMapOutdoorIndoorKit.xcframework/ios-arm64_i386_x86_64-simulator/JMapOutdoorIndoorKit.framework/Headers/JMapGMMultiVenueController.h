//
//  JMapGMMultiVenueController.h
//  JMapIndoorOutdoorKit
//
//  Created by Sonam Sodani on 2021-08-11.
//  Copyright © 2021 Jibestream. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "JMapGMController.h"


@interface JMapGMMultiVenueController : NSObject

/**
 *  Collection of ActiveVenues
 */
@property(nonatomic, nullable, strong, readonly) JMapMultiActiveVenues *multiActiveVenues;

/**
 *  Initializes a JMapGMController object for each activeVenue.
 *
 *  @param mapView A GMSMapView object that will be used to display the map
 *  @param multiActiveVenues A JMapMultiActiveVenue object to be loaded
 *  @param APIKey The Google Map SDK API Key used to make API requests
 */
-(nonnull instancetype)initWithMapView:(nonnull GMSMapView*)mapView multiActiveVenue:(nonnull JMapMultiActiveVenues *)multiActiveVenues APIKey:(nonnull NSString *)APIKey;

/**
 *  To get the JMapGMController object associated with the JMapActiveVenue object
 *
 *  @param activeVenue A JMapActiveVenue object, for which the JMapGMController is required
 *  @return A JMapGMController object associated with the provided JMapActiveVenue object
 */
-(nonnull JMapGMController*)getGMControllerByActiveVenue:(nonnull JMapActiveVenue*)activeVenue;

/**
 *  To set an ActiveVenue as a current ActiveVenue. 
 *
 *  @param activeVenue A JMapActiveVenue object, which is required to set as a current ActiveVenue.
 */
-(void)setCurrentActiveVenue:(nonnull JMapActiveVenue*)activeVenue;

/**
 *  Update the multiActiveVenues and associate properties
 *
 *  @param multiActiveVenues An updates instance of  JMapMultiActiveVenues object.
 */
- (void)updateActiveVenues:(nonnull JMapMultiActiveVenues *)multiActiveVenues;

#pragma mark - WAYFINDING
/**
 *  Wayfind between two waypoints for different venues within the Jibestream map.
 *
 *  @param waypointStart The origin waypoint object to start the wayfinding from.
 *  @param waypointEnd The destination waypoint object to end the wayfinding path.
 *  @param accessibility A NSInteger value between 0-100 to indicate accessibility level; 0 - Not accessible, 100 - Accessible path.
 *  @param completion A callback that returns indoorPaths if pure indoor path exists. Returns outdoorPathData or combination of indoor-outdoor path when pure indoor path is not found.
 *  indoorPaths : An array of GMSPolyline objects to indicate wayfinding paths across all floors.
 *  outdoorPathData: storing paths data. Keys - "indoorPathStart", "outdoorPath", "indoorPathEnd", will indicate the indoor wayfinding path for waypointStart venue , outdoor wayfinding path, indoor wayfinding path for waypointEnd venue respectively.
 */
-(void)wayfindVenueToVenueBetweenWaypoint:(nonnull JMapWaypoint *)waypointStart andWaypoint:(nonnull JMapWaypoint *)waypointEnd  withAccessibility:(NSInteger)accessibility completion:(void(^ _Nullable)(NSArray <GMSPolyline *> * _Nullable indoorPaths, NSDictionary  * _Nullable outdoorPathData))completion;

/**
 *  Removes all  indoor and outdoor wayfinding paths on map for all venues.
 */
-(void)clearWayfindPaths;

#pragma mark - SHOW & HIDE MAPS
/**
 *  Displays default map for each activeVenue
 *
 *  @param activeVenues array of activevenues to show on the map
 *  @param completion The completion handler for the API call. Returns JMapError if any of the venues failed to show default map
 */
-(void)showDefaultMapsForVenues:(NSArray<JMapActiveVenue*> *_Nonnull)activeVenues WithCompletionHandler:(ErrorCompletion)completion;

/**
 *  hide map for each activeVenue
 *
 *  @param activeVenues array of activevenues to hide on the map
 */
-(void)hideMapsForVenues:(nonnull NSArray<JMapActiveVenue *> *)activeVenues;

/**
 * to get range of levels/floors for all the active venues
 *
 */
-(int)getLevelRangeForAllActiveVenues;

/**
 * to get range of levels for the passed venues
 *
 * @param activeVenues array of activevenues for which level range is required
 */
-(int)getLevelRangeForActiveVenues:(nonnull NSArray<JMapActiveVenue*>*)activeVenues;

/**
 * show map for all active venues for the given level
 *
 * @param level the floor level, map for this level should be displayed
 */
-(void)showMapsByLevel:(nonnull NSNumber*)level;

/**
 * show map for all active venues for the given level
 *
 * @param level the floor level, map for this level should be displayed
 * @param activeVenues array of activevenues to show map for the given level
 */
-(void)showMapsByLevel:(nonnull NSNumber*)level ForVenues:(nonnull NSArray<JMapActiveVenue*>*)activeVenues;


@end

