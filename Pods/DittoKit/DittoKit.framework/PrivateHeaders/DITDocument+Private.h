//
//  DITDocument+Private.h
//  DittoKit
//
//  Created by Hamilton Chapman on 29/01/2020.
//  Copyright © 2020 Ditto. All rights reserved.
//

#import <Foundation/Foundation.h>

struct Ditto_Document;

NS_ASSUME_NONNULL_BEGIN

@interface DITDocument ()
@property (nonatomic, readonly, unsafe_unretained) const struct Ditto_Document *documentHandle;

- (instancetype)initWithDocumentHandle:(const struct Ditto_Document *)documentHandle;
@end

NS_ASSUME_NONNULL_END
