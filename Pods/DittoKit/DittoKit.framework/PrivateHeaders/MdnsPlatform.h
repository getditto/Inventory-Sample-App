//
//  MdnsPlatform.h
//  DittoTransportsObjC
//
//  Created by Hamilton Chapman on 30/10/2019.
//  Copyright © 2019 Ditto. All rights reserved.
//

#import <Foundation/Foundation.h>
#if TARGET_OS_IPHONE || TARGET_IPHONE_SIMULATOR
#import <UIKit/UIKit.h>
#elif TARGET_OS_MAC
#import <AppKit/AppKit.h>
#endif

#import "TransportHandleWrapper.h"

@class ServiceCache;

NS_ASSUME_NONNULL_BEGIN

@interface MdnsPlatform : NSObject <NSNetServiceBrowserDelegate, NSNetServiceDelegate>

@property(nonatomic, assign, readonly) void *dittoHandle;
@property(nonatomic, strong, nullable) TransportHandleWrapper *clientHandleWrapper;
@property(nonatomic, strong, nullable) TransportHandleWrapper *serverHandleWrapper;

@property(nonatomic, strong, nullable) NSNetService *service;
@property(nonatomic, strong, nullable) NSNetServiceBrowser *browser;
@property(nonatomic, strong) ServiceCache *services;
@property(nonatomic, assign) enum OnlineState searching;
@property(nonatomic, assign) enum OnlineState advertising;
@property(nonatomic, strong) NSString *announce;
@property(nonatomic, strong) NSString *prefix;
@property(nonatomic, assign) int32_t port;
@property(nonatomic, strong, readonly, nullable) NSString* serviceName;
@property(nonatomic, strong, readonly) dispatch_queue_t startStopQueue;

// For ClientPlatformProtocol
@property (nonatomic, assign) bool isWifiEnabled;
@property (nonatomic, assign) bool appInForeground;
@property (nonatomic, strong, nullable) NSTimer *wifiCheckTimer;

+ (struct MdnsServerCallbacks)serverCallbacks;
+ (struct MdnsClientCallbacks)clientCallbacks;

- (instancetype)initWithDittoHandle:(void *)dittoHandle;
- (void)appWillEnterForegroundWithN:(NSNotification *)n;
- (void)appDidEnterBackgroundWithN:(NSNotification *)n;
- (void)netServiceDidPublish:(NSNetService *)sender;
- (void)netService:(NSNetService *)sender didNotPublish:(NSDictionary<NSString *, NSNumber *> *)errorDict;
- (void)netServiceBrowser:(NSNetServiceBrowser *)browser didNotSearch:(NSDictionary<NSString *, NSNumber *> *)errorDict;
- (void)netServiceBrowser:(NSNetServiceBrowser *)browser didFindService:(NSNetService *)service moreComing:(BOOL)moreComing;
- (void)netServiceBrowser:(NSNetServiceBrowser *)browser didRemoveService:(NSNetService *)service moreComing:(BOOL)moreComing;
- (void)netServiceDidResolveAddress:(NSNetService *)sender;
- (void)netService:(NSNetService *)sender didNotResolve:(NSDictionary<NSString *, NSNumber *> *)errorDict;
- (void)shutdown;

@end

NS_ASSUME_NONNULL_END
