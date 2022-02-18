//
//  MaxSDKMediation.h
//  MRouter
//
//  Created by xuejun on 2022/1/12.
//

#import <MRouter/MRouterBaseSDK.h>
#import <AppLovinSDK/AppLovinSDK.h>

NS_ASSUME_NONNULL_BEGIN

@interface MaxSDKMediation : MRouterBaseSDK

+(MaxSDKMediation *)sharedInstance;
@property (nonatomic,strong)ALSdk *sdk;
@end

NS_ASSUME_NONNULL_END
