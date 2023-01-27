//
//  JMapGMMap.h
//  JMapControllerKit
//
//  Created by Louie Yuen on 2019-03-13.
//  Copyright © 2019 Jibestream. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "JMapGMGeometry.h"

/**
 *  The JMapGMMap object
*/
@interface JMapGMMap : NSObject

/**
 *  The layers on the map stored in a dictionary with key as the layerName
*/
@property (nonatomic, readonly, nonnull) NSMutableDictionary *layers;

/**
 *  Sorted list of layer names by their z index
*/
@property (nonatomic, nonnull) NSMutableArray *sortedLayerNames;

/**
 *  Method to add a JMapGMGeometry shape to a layer with layer name
 *
 *  @param shape The JMapGMGeometry shape to be added
 *  @param layerName The layer with layerName to add the shape to
*/
- (void)addShape:(nonnull JMapGMGeometry *)shape toLayer:(nonnull NSString *)layerName;

/**
 *  Method to return a list of shapes in layer with layer name
 *
 *  @param layerName The layer name to return shapes from
 *  @return An NSArray of shapes in the layer
*/
- (nullable NSArray <id>*)getShapesInLayer:(nonnull NSString *)layerName;

@end
