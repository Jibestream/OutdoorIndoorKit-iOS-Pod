//
//  JMapGMMap.h
//  JMapControllerKit
//
//  Created by Louie Yuen on 2019-03-13.
//  Copyright © 2019 Jibestream. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "JMapGMGeometry.h"

@interface JMapGMMap : NSObject

@property (nonatomic, readonly, nonnull) NSMutableDictionary *layers;
@property (nonatomic, nonnull) NSMutableArray *sortedLayerNames;

- (void)addShape:(nonnull JMapGMGeometry *)shape toLayer:(nonnull NSString *)layerName;

// Return type can be array of JMapGeometry, JMapGeometryCollection or GMSOverlay
- (nullable NSArray *)getShapesInLayer:(nonnull NSString *)layerName;

@end
