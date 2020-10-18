//
//  DittoKit.h
//  DittoKit
//
//  Created by Hamilton Chapman on 20/01/2020.
//  Copyright © 2020 Ditto. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <DittoKit/DITLogLevel.h>

#import "DITTransport.h"

@class DITDBConfig;
@class DITIdentity;
@class DITPeersObserver;
@class DITRemotePeer;
@class DITStore;
@class DITTransportDiagnostics;

@protocol DITDittoKitDelegate;

NS_ASSUME_NONNULL_BEGIN

/**
 The entrypoint to the DittoKit SDK.

 For a `DITDittoKit` instance to continue to connect to other devices it must be kept in scope.
 */
@interface DITDittoKit : NSObject

/**
 Represents whether logging is enabled.
 */
@property (class, nonatomic) BOOL loggingEnabled;

/**
 The minimum log level at which logs will be logged, provided `loggingEnabled` is `true`.
 */
@property (class, nonatomic) enum DITLogLevel minimumLogLevel;

/**
 Represents whether or not emojis should be used as the log level indicator in the logs.
 */
@property (class, nonatomic) BOOL emojiLogLevelHeadingsEnabled;

/**
 Configure a custom identifier for the current device.

 When using `observePeers`, each remote peer is represented by a short UTF-8 "device name".

 By default this will be a truncated version of the device's hostname. It does not need to be unique
 among peers.

 Configure the device name before calling `start`. If it is too long it will be truncated.
 */
@property (class, nonatomic) NSString *deviceName;

/**
 Provides access to the SDK's store functionality.
 */
@property (atomic, readonly) DITStore *store;

/**
 The site ID that the instance of `DittoKit` is using as part of its identity.
 */
@property (nonatomic, readonly) uint32_t siteID;

/**
 An optional delegate that will be called with SDK lifecycle information if defined.
 */
@property (nonatomic, weak) id<DITDittoKitDelegate> delegate;

/**
 The dispatch queue that will be used to deliver delegate events. Defaults to the main queue.
 */
@property (nonatomic) dispatch_queue_t delegateEventQueue;

/**
 Initializes a new `DITDittoKit`.

 This will initialize an instance of `DITDittoKit` with the default configuration.
 */
- (instancetype)init;

/**
 Initializes a new `DITDittoKit`.

 @param identity Provide the identity of the entity that is interacting with DittoKit.
 */
- (instancetype)initWithIdentity:(DITIdentity *)identity;

/**
 Initializes a new `DITDittoKit`.

 @param identity Provide the identity of the entity that is interacting with DittoKit.
 @param directory The directory that will be used to persist DittoKit data.
 */
- (instancetype)initWithIdentity:(DITIdentity *)identity persistenceDirectory:(NSURL *)directory;

/**
 Initializes a new `DITDittoKit`.

 @param identity Provide the identity of the entity that is interacting with DittoKit.
 @param dbConfig Optional configuration to pass to the underlying storage backend.
 */
- (instancetype)initWithIdentity:(DITIdentity *)identity dbConfig:(DITDBConfig *)dbConfig;

/**
 Initializes a new `DITDittoKit`.

 @param identity Provide the identity of the entity that is interacting with DittoKit.
 @param directory The directory that will be used to persist DittoKit data.
 @param dbConfig Optional configuration to pass to the underlying storage backend.
 */
- (instancetype)initWithIdentity:(DITIdentity *)identity
            persistenceDirectory:(nullable NSURL *)directory
                        dbConfig:(nullable DITDBConfig *)dbConfig;

/**
 Starts all of the transports used by DittoKit to connect to other devices.

 This has no effect for any transports that have already been started.
 */
- (void)start;

/**
 Start a set of transports used by DittoKit to connect to other devices.

 This has no effect if a provided transport is already started.

 @param transports The set of transports to be started.
 */
- (void)start:(NSArray<DITTransport *> *)transports;

/**
 Stops all of the transports used by DittoKit to connect to other devices.

 This has no effect for any transports that have already been stopped.
 */
- (void)stop;

/**
 Stop a set of transports being used by DittoKit to connect to other devices.

 This has no effect for any transports that have already been started.

 @param transports The set of transports to be stopped.
 */
- (void)stop:(NSArray<DITTransport *> *)transports;

/**
 Activate a `DITDittoKit` instance by setting an access license. You cannot meaningfully interact
 with a `DITDittoKit` instance before you have activated it.

 @param license The license to activate the `DITDittoKit` instance with.
 */
- (void)setAccessLicense:(NSString *)license;

/**
 Clears the cached site ID, if one had been cached.
 */
- (void)clearSiteID;

/**
 Request bulk status information about the transports.

 This is mostly intended for statistical or debugging purposes.

 @param error On input, a pointer to an error object. If an error occurs, this pointer
 is set to an actual error object containing the error information. You may specify nil for this
 parameter if you do not want the error information.

 @return An instance of `DITTransportDiagnostics` or `nil` if there was an error.
 */
- (nullable DITTransportDiagnostics *)transportDiagnostics:(NSError **)error;

/**
 Request information about Ditto peers in range of this device.

 This method returns an observer which should be held as long as updates are required. A newly
 registered observer will have a peers update delivered to it immediately. From then on it will be
 invoked repeatedly when Ditto devices come and go, or the active connections to them change.
 */
- (DITPeersObserver *)observePeers:(void (^)(NSArray<DITRemotePeer *> *))callback;

/**
 Returns a string identifying the version of the DittoKit SDK.
 */
- (NSString *)sdkVersion;

@end

NS_ASSUME_NONNULL_END
