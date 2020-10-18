//
//  DITAttachmentStatus.h
//  DittoKit
//
//  Created by Hamilton Chapman on 10/03/2020.
//  Copyright © 2020 Ditto. All rights reserved.
//

#import <Foundation/Foundation.h>

@class DITAttachment;
@class DITAttachmentStatusCompleted;
@class DITAttachmentStatusIncomplete;
@class DITAttachmentStatusDeleted;

/**
 The types of attachment status that can be delivered to an attachment fetcher's `onStatusChanged`
 block.
 */
typedef NS_ENUM(NSUInteger, DITAttachmentStatusType) {
    DITAttachmentStatusTypeCompleted = 0,
    DITAttachmentStatusTypeIncomplete,
    DITAttachmentStatusTypeDeleted,
};

NS_ASSUME_NONNULL_BEGIN

/**
 A representation of the status of an attachment.

 An attachment's status can be one of three types: completed, incomplete, or deleted.

 Updates to an attachment's status are delivered by registering a `DITAttachmentFetcher` through a
 call to `fetchAttachment` on a `DITCollection` instance.
 */
@interface DITAttachmentStatus : NSObject

/**
 The attachment staus' type.

 Check this value before using one of `asCompleted`, `asIncomplete`, or
 `asDeleted` to ensure that you get a richer attachment status object of the
 correct type.
 */
@property (nonatomic, readonly) DITAttachmentStatusType type;

/**
 Return the attachment status object as a `DITAttachmentStatusCompleted` object.

 @return A `DITAttachmentStatusCompleted` object or `nil` if the attachment's status is not
 completed.
 */
- (nullable DITAttachmentStatusCompleted *)asCompleted;

/**
 Return the attachment status object as a `DITAttachmentStatusIncomplete` object.

 @return A `DITAttachmentStatusIncomplete` object or `nil` if the attachment's status is not
 incomplete.
 */
- (nullable DITAttachmentStatusIncomplete *)asIncomplete;

/**
 Return the attachment status object as a `DITAttachmentStatusDeleted` object.

 @return A `DITAttachmentStatusDeleted` object or `nil` if the attachment's status is not deleted.
 */
- (nullable DITAttachmentStatusDeleted *)asDeleted;

@end

/**
 An attachment status used when the attachment's download has completed.
 */
@interface DITAttachmentStatusCompleted : DITAttachmentStatus

/**
 The complete attachment.
 */
@property (nonatomic, readonly) DITAttachment *attachment;

@end

/**
 An attachment status used when the attachment's download is incomplete.
 */
@interface DITAttachmentStatusIncomplete : DITAttachmentStatus

/**
 The size of the attachment that was successfully downloaded, in bytes.
 */
@property (nonatomic, readonly) NSUInteger downloadedBytes;

/**
 The full size of the attachment, if it were complete.
 */
@property (nonatomic, readonly) NSUInteger totalBytes;

@end

/**
 An attachment status used when the attachment is deleted.
 */
@interface DITAttachmentStatusDeleted : DITAttachmentStatus
@end

NS_ASSUME_NONNULL_END
