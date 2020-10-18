//
//  DITTransport+Private.h
//  DittoKit
//
//  Created by Hamilton Chapman on 17/04/2020.
//  Copyright © 2020 Ditto. All rights reserved.
//

NS_ASSUME_NONNULL_BEGIN

@interface DITTransportBluetooth ()
- (instancetype)init;
@end

@interface DITTransportWiFi ()
- (instancetype)init;
@end

@interface DITTransportAWDL ()
- (instancetype)init;
@end

@interface DITTransportServer ()
- (instancetype)initWithAddress:(NSString *)serverAddress;
@end

@interface DITTransportWiFiFixedPort ()
- (instancetype)initWithPort:(uint16_t)listenPort;
@end

NS_ASSUME_NONNULL_END
