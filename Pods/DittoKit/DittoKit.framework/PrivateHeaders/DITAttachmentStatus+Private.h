//
//  DITAttachmentStatus+Private.h
//  DittoKit
//
//  Created by Hamilton Chapman on 10/03/2020.
//  Copyright © 2020 Ditto. All rights reserved.
//

@class DITAttachment;

NS_ASSUME_NONNULL_BEGIN

@interface DITAttachmentStatusCompleted ()
- (instancetype)initWithAttachment:(DITAttachment *)attachment;
@end

@interface DITAttachmentStatusIncomplete ()
- (instancetype)initWithDownloadedBytes:(NSUInteger)downloadedBytes
                             totalBytes:(NSUInteger)totalBytes;
@end

@interface DITAttachmentStatusDeleted ()
- (instancetype)init;
@end

NS_ASSUME_NONNULL_END
