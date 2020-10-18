//
//  DITWriteTransaction+Private.h
//  DittoKit
//
//  Created by Hamilton Chapman on 03/02/2020.
//  Copyright © 2020 Ditto. All rights reserved.
//

@class DittoHandleWrapper;
@class DITWriteTransactionResult;

struct Ditto_WriteTransaction;

NS_ASSUME_NONNULL_BEGIN

@interface DITWriteTransaction ()
@property (nonatomic, readonly) DittoHandleWrapper *dittoHandleWrapper;
@property (nonatomic, readonly) uint32_t siteID;
@property (nonatomic, readonly) const struct Ditto_WriteTransaction *writeTxn;
@property (nonatomic, readonly) NSMutableArray<DITWriteTransactionResult *> *results;

- (instancetype)initWithDittoHandleWrapper:(DittoHandleWrapper *)dittoHandleWrapper
                                    siteID:(uint32_t)siteID
                                  writeTxn:(const struct Ditto_WriteTransaction *)writeTxn;
@end

NS_ASSUME_NONNULL_END
