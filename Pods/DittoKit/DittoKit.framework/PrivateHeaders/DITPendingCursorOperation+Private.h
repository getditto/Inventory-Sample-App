//
//  DITPendingCursorOperation+Private.h
//  DittoKit
//
//  Created by Hamilton Chapman on 31/01/2020.
//  Copyright © 2020 Ditto. All rights reserved.
//

@class DittoHandleWrapper;
@class DocumentHandleWrapper;
@class DITLiveQuery;
@class DITLiveQueryEvent;
@class DITLiveQueryMove;
@class DITSubscription;

struct Ditto_OrderDefinition;

NS_ASSUME_NONNULL_BEGIN

@interface DITPendingCursorOperation ()
@property (nonatomic, readonly) DittoHandleWrapper *dittoHandleWrapper;
@property (nonatomic, readonly) NSString *collectionName;
@property (nonatomic, readonly) NSString *query;
@property (nonatomic, readwrite) int limit;
@property (nonatomic, readwrite) uint offset;
@property (nonatomic, readwrite, nullable) struct Ditto_OrderDefinition *orderDefinitions;
@property (nonatomic, readwrite) uint orderDefinitionsCount;
@property (nonatomic, readwrite, nullable) NSError *error;

- (instancetype)initWithQuery:(NSString *)query
               collectionName:(NSString *)collectionName
           dittoHandleWrapper:(DittoHandleWrapper *)dittoHandleWrapper;

- (NSArray<DocumentHandleWrapper *> *)execReturningDocumentHandles;
- (DITLiveQuery *)observeWithDeliveryQueue:(dispatch_queue_t)dispatchQueue
          eventHandlerUsingDocumentHandles:(void (^)(BOOL,
                                                     NSArray<DocumentHandleWrapper *> *,
                                                     NSArray<DocumentHandleWrapper *> *,
                                                     NSArray<NSNumber *> *,
                                                     NSArray<NSNumber *> *,
                                                     NSArray<NSNumber *> *,
                                                     NSArray<DITLiveQueryMove *> *))eventHandler;
- (DITLiveQuery *)observeLocalWithDeliveryQueue:(dispatch_queue_t)dispatchQueue
               eventHandlerUsingDocumentHandles:
                   (void (^)(BOOL,
                             NSArray<DocumentHandleWrapper *> *,
                             NSArray<DocumentHandleWrapper *> *,
                             NSArray<NSNumber *> *,
                             NSArray<NSNumber *> *,
                             NSArray<NSNumber *> *,
                             NSArray<DITLiveQueryMove *> *))eventHandler;
@end

NS_ASSUME_NONNULL_END
