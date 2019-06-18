//
//  JMapGMGeometry.h
//  JMapControllerKit
//
//  Created by Louie Yuen on 2018-11-27.
//  Copyright © 2018 Jibestream. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <GoogleMaps/GoogleMaps.h>

@interface JMapGMGeometry : NSObject

@property (nonatomic, readonly) NSString *type;
@property (nonatomic, readonly) NSArray <NSArray *>*coordinates;
@property (nonatomic, readonly) NSDictionary *properties;
@property (nonatomic, readonly) GMSOverlay *shapeOverlay;

/**
 * Initializes a JMapGMGeometry instance
 *
 * @param dict the geometry data passed in
 */
- (instancetype)initWithDictionary:(NSDictionary *)dict;

@end

