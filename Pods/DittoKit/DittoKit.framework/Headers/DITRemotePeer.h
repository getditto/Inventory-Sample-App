//
//  DITRemotePeer.h
//  DittoKit
//
//  Created by Hamilton Chapman on 06/02/2020.
//  Copyright © 2020 Ditto. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 A summary snapshot of the types of connections currently active to a remote peer.
 */
@interface DITRemotePeer : NSObject

/**
 The device name of the remote peer.
 */
@property (nonatomic, readonly) NSString *deviceName;

/**
 The connections that are currently active with the remote peer.
 */
@property (nonatomic, readwrite) NSArray<NSString *> *connections;

/**
 Dedicated initializer for a `DITRemotePeer`.

 - Parameter deviceName: The device name of the remote peer.
 - Parameter connections: The connections that are currently active with the remote peer.
 - Returns: A newly initialized `DITRemotePeer`.
 */
- (instancetype)initWithDeviceName:(NSString *)deviceName
                       connections:(NSArray<NSString *> *)connections;

@end

NS_ASSUME_NONNULL_END
