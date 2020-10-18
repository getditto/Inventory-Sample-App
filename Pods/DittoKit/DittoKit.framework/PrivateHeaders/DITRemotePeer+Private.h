//
//  DITRemotePeer+Private.h
//  DittoKit
//
//  Created by Hamilton Chapman on 07/02/2020.
//  Copyright © 2020 Ditto. All rights reserved.
//

NS_ASSUME_NONNULL_BEGIN

@interface DITRemotePeer ()
- (instancetype)initWithDeviceName:(NSString *)deviceName
                       connections:(NSArray<NSString *> *)connections;
@end

NS_ASSUME_NONNULL_END
