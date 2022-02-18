//
//  MRouterMediation.h
//  MRouter
//
//  Created by xuejun on 2022/1/12.
//

#import <MRouter/MRouterBaseSDK.h>
#import <MRouter/MRouterBaseInterstitial.h>
#import <MRouter/MRouterBaseRewarded.h>
#import <MRouter/MRouterCommon.h>

@interface MRouterMediation : NSObject

+ (MRouterMediation *)sharedInstance;
- (void)setInitClassName:(NSString *)className platform:(MRMediationPlatform)platform;
- (void)setInterstitialClassName:(NSString *)className platform:(MRMediationPlatform)platform;
- (void)setRewardedClassName:(NSString *)className platform:(MRMediationPlatform)platform;

- (MRouterBaseSDK *)getBaseSDK;
- (MRouterBaseInterstitial *)getInterstitialBase;
- (MRouterBaseRewarded *)getRewardedBase;

- (NSDictionary *)getSDKConfigWithPlatformName:(NSString *)platformName;
- (void)mediationClassList;

@property (nonatomic,assign)MRMediationPlatform mediationPlatform;
@property (nonatomic,copy)NSDictionary *configure;
@end

