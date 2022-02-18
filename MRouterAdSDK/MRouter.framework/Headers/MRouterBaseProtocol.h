//
//  MRouterBaseProtocol.h
//  MRouter
//
//  Created by xuejun on 2022/1/12.
//

#import <Foundation/Foundation.h>
#import <MRouter/MRouterMediation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol MRouterBaseProtocol <NSObject>

+ (MRMediationPlatform)platform;

@end

NS_ASSUME_NONNULL_END
