//
//  TransportConditionHelpers.h
//  DittoKit
//
//  Created by Hamilton Chapman on 29/01/2020.
//  Copyright © 2020 Ditto. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <DittoKit/DITTransportCondition.h>

#import "dittoffi.h"

NS_ASSUME_NONNULL_BEGIN

@interface TransportConditionHelpers : NSObject

+ (enum DITTransportCondition)DITTransportConditionFromTransportCondition:
    (enum TransportCondition)transportCondition;
+ (NSString *)transportConditionDescription:(enum DITTransportCondition)DITTransportCondition;
+ (enum DITConditionSource)DITConditionSourceFromConditionSource:
    (enum ConditionSource)conditionSource;
+ (NSString *)conditionSourceDescription:(enum DITConditionSource)conditionSource;

@end

NS_ASSUME_NONNULL_END
