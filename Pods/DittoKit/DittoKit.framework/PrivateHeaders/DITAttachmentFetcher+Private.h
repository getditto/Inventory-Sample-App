//
//  DITAttachmentFetcher+Private.h
//  DittoKit
//
//  Created by Hamilton Chapman on 11/03/2020.
//  Copyright © 2020 Ditto. All rights reserved.
//

@class DITAttachmentToken;
@class DITAttachmentStatus;
@class DittoHandleWrapper;

NS_ASSUME_NONNULL_BEGIN

@interface DITAttachmentFetcher ()

@property (nonatomic, readonly) DittoHandleWrapper *dittoHandleWrapper;
@property (nonatomic, readonly) void (^onStatusChanged)(DITAttachmentStatus *);
@property (nonatomic, readonly) DITAttachmentToken *token;
@property (nonatomic, readonly) int64_t cancelToken;

- (instancetype)initWithAttachmentToken:(DITAttachmentToken *)attachmentToken
                        onStatusChanged:(void (^)(DITAttachmentStatus *))onStatusChanged
                     dittoHandleWrapper:(DittoHandleWrapper *)dittoHandleWrapper;

@end

NS_ASSUME_NONNULL_END
