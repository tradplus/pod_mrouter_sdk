//
//  MRouterError.h
//  MRouter
//
//  Created by xuejun on 2022/1/14.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef enum : NSUInteger {
    MRErrorCode_NotInitialized = 10000,
    MRErrorCode_NoConfigure= 10001,
    MRErrorCode_NoTPAppId = 10002,
    MRErrorCode_NoMAXAppId = 10003,
    MRErrorCode_MAXSDKInitError = 10004,
    MRErrorCode_UnknownPlatform = 10005,
    MRErrorCode_NoAdSlot = 10006,
    MRErrorCode_NoPlatformConfigure = 10007,
    MRErrorCode_NoAdSlotConfigure = 10008,
    MRErrorCode_IsInitializing = 10010,
    MRErrorCode_DidInitialized = 10011,
    MRErrorCode_NoPlatformSDK = 10012
} MRErrorCode;

@interface MRouterError : NSObject

+ (NSError *)errorWithCode:(MRErrorCode)code;
@end

NS_ASSUME_NONNULL_END
