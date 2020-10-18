//
//  DITDBConfig.h
//  DittoKit
//
//  Created by Hamilton Chapman on 20/01/2020.
//  Copyright © 2020 Ditto. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

FOUNDATION_EXPORT NSInteger const kDITDefaultMapSize;

/**
 Configuration for the database backend that DittoKit uses.
 */
@interface DITDBConfig : NSObject

/**
 The maximum size of the database.
 */
@property (nonatomic, readonly) size_t mapSize;

/**
 Initializes a `DBConfig` object that can be passed to the `DittoStore` initializer.

 The default mapsize is 200MB.
 */
- (instancetype)init;

/**
 Initializes a `DITDBConfig` object that can be passed to the `DITDittoKit` initializer.

@param mapSize The size of the memory map to use. The size should be a multiple of the OS page size.
The default is 200 * 1048576 bytes (200MB). The size of the memory map is also the maximum size of
the database.
 */
- (instancetype)initWithMapSize:(size_t)mapSize;

@end

NS_ASSUME_NONNULL_END
