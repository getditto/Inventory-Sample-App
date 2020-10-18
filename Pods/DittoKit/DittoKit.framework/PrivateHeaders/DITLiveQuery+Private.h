//
//  DITLiveQuery+Private.h
//  DittoKit
//
//  Created by Hamilton Chapman on 31/01/2020.
//  Copyright © 2020 Ditto. All rights reserved.
//

@class DittoHandleWrapper;
@class DocumentHandleWrapper;
@class DITDocument;
@class DITLiveQueryEvent;
@class DITLiveQueryMove;
@class DITSubscription;

struct Ditto_Document;
struct Ditto_OrderDefinition;

NS_ASSUME_NONNULL_BEGIN

@interface DITLiveQuery ()
@property (nonatomic, readonly) DittoHandleWrapper *dittoHandleWrapper;
@property (nonatomic, readonly) int limit;
@property (nonatomic, readonly) uint offset;
@property (nonatomic, readonly, nullable) DITSubscription *subscription;
@property (nonatomic, readonly) int64_t lqID;
@property (nonatomic, readonly) dispatch_queue_t deliveryDispatchQueue;
@property (nonatomic, readonly, nullable) void (^eventHandler)
    (NSArray<DITDocument *> *, DITLiveQueryEvent *);
@property (nonatomic, readonly, nullable) void (^documentHandleEventHandler)
    (BOOL,
     NSArray<DocumentHandleWrapper *> *,
     NSArray<DocumentHandleWrapper *> *,
     NSArray<NSNumber *> *,
     NSArray<NSNumber *> *,
     NSArray<NSNumber *> *,
     NSArray<DITLiveQueryMove *> *);

- (instancetype)initWithQuery:(NSString *)query
               collectionName:(NSString *)collectionName
             orderDefinitions:(nullable struct Ditto_OrderDefinition *)orderDefinitions
        orderDefinitionsCount:(uint)orderDefinitionsCount
                        limit:(int)limit
                       offset:(uint)offset
                 subscription:(nullable DITSubscription *)subscription
           dittoHandleWrapper:(DittoHandleWrapper *)dittoHandleWrapper
        deliveryDispatchQueue:(dispatch_queue_t)dispatchQueue
                 eventHandler:(void (^)(NSArray<DITDocument *> *, DITLiveQueryEvent *))eventHandler;

- (instancetype)initWithQuery:(NSString *)query
                collectionName:(NSString *)collectionName
              orderDefinitions:(nullable struct Ditto_OrderDefinition *)orderDefinitions
         orderDefinitionsCount:(uint)orderDefinitionsCount
                         limit:(int)limit
                        offset:(uint)offset
                  subscription:(nullable DITSubscription *)subscription
            dittoHandleWrapper:(DittoHandleWrapper *)dittoHandleWrapper
         deliveryDispatchQueue:(dispatch_queue_t)dispatchQueue
    documentHandleEventHandler:(void (^)(BOOL,
                                         NSArray<DocumentHandleWrapper *> *,
                                         NSArray<DocumentHandleWrapper *> *,
                                         NSArray<NSNumber *> *,
                                         NSArray<NSNumber *> *,
                                         NSArray<NSNumber *> *,
                                         NSArray<DITLiveQueryMove *> *))eventHandler;

+ (NSArray<DITDocument *> *)
    documentsFrom:(const struct Ditto_Document *_Nonnull *_Nonnull)CF_RELEASES_ARGUMENT docsPtr
            count:(uintptr_t)docCount;
+ (NSArray<NSNumber *> *)indexesFrom:(uintptr_t *)CF_RELEASES_ARGUMENT indexesPtr
                               count:(uintptr_t)count;
+ (NSArray<DocumentHandleWrapper *> *)
    documentHandlesFrom:(const struct Ditto_Document *_Nonnull *_Nonnull)CF_RELEASES_ARGUMENT
    docsPtr
                  count:(uintptr_t)docCount;

@end

NS_ASSUME_NONNULL_END
