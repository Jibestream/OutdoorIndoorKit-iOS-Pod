//
//  JMapGMGeometry.h
//  JMapControllerKit
//
//  Created by Louie Yuen on 2018-11-27.
//  Copyright © 2018 Jibestream. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <GoogleMaps/GoogleMaps.h>

/**
 *  The JMapGMGeometry object
*/
@interface JMapGMGeometry : NSObject

/**
 *  The type property of the geometry, refer to GeoJSON "type" property
*/
@property (nonatomic, readonly) NSString *type;
/**
 *  The coordinate list of the geometry in lat,long
*/
@property (nonatomic, readonly) NSArray <NSArray *>*coordinates;
/**
 *  The additional properties associated to the geometry
*/
@property (nonatomic, readonly) NSDictionary *properties;
/**
 *  The GMSOverlay reference to the geometry on the map
*/
@property (nonatomic, readonly) GMSOverlay *shapeOverlay;

/**
 * Initializes a JMapGMGeometry instance
 *
 * @param dict the geometry data passed in
 */
- (instancetype)initWithDictionary:(NSDictionary *)dict;

@end

