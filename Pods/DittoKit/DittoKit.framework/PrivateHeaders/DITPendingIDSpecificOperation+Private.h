//
//  DITPendingIDSpecificOperation+Private.h
//  DittoKit
//
//  Created by Hamilton Chapman on 31/01/2020.
//  Copyright © 2020 Ditto. All rights reserved.
//

@class DittoHandleWrapper;
@class DocumentHandleWrapper;
@class DITDocument;
@class DITLiveQuery;
@class DITSingleDocumentLiveQueryEvent;
@class DITSubscription;

NS_ASSUME_NONNULL_BEGIN

@interface DITPendingIDSpecificOperation ()
@property (nonatomic, readonly) DittoHandleWrapper *dittoHandleWrapper;
@property (nonatomic, readonly) NSString *documentID;
@property (nonatomic, readonly) NSString *collectionName;
@property (nonatomic, readonly) NSString *query;

- (instancetype)initWithDocumentID:(NSString *)documentID
                    collectionName:(NSString *)collectionName
                dittoHandleWrapper:(DittoHandleWrapper *)dittoHandleWrapper;

- (DITLiveQuery *)observeWithSubscription:(nullable DITSubscription *)subscription
                            deliveryQueue:(dispatch_queue_t)deliveryQueue
                             eventHandler:(void (^)(DITDocument *_Nullable,
                                                    DITSingleDocumentLiveQueryEvent *))eventHandler;

- (DITLiveQuery *)observeWithDeliveryQueue:(dispatch_queue_t)dispatchQueue
           eventHandlerUsingDocumentHandle:(void (^)(BOOL,
                                                     DocumentHandleWrapper *_Nullable,
                                                     DocumentHandleWrapper *_Nullable))eventHandler;
- (DITLiveQuery *)observeLocalWithDeliveryQueue:(dispatch_queue_t)dispatchQueue
                eventHandlerUsingDocumentHandle:
                    (void (^)(BOOL,
                              DocumentHandleWrapper *_Nullable,
                              DocumentHandleWrapper *_Nullable))eventHandler;

- (void)updateUsingData:(NSData *)data;
- (nullable DocumentHandleWrapper *)execReturningDocumentHandle;
@end

NS_ASSUME_NONNULL_END
