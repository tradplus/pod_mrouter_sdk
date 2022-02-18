//
//  MRouter.h
//  MRouter
//
//  Created by xuejun on 2022/1/12.
//

#import <Foundation/Foundation.h>
#import <MRouter/MRouterInterstitial.h>
#import <MRouter/MRouterRewarded.h>
#import <MRouter/MRouterMediation.h>
#import <MRouter/MRouterError.h>

#import <MRouter/MRouterBaseProtocol.h>

#import <MRouter/MRouterBaseSDK.h>
#import <MRouter/MRouterBaseInterstitial.h>
#import <MRouter/MRouterBaseRewarded.h>

#import <MRouter/TPSDKMediation.h>
#import <MRouter/TPSDKMediationRewarded.h>
#import <MRouter/TPSDKMediationInterstitial.h>

#import <MRouter/MaxSDKMediation.h>
#import <MRouter/MaxSDKMediationInterstitial.h>
#import <MRouter/MaxSDKMediationRewarded.h>

#import <MRouter/MRouterCommon.h>

NS_ASSUME_NONNULL_BEGIN

@interface MRouter : NSObject

+ (NSString *)getVersion;
+ (MRouter *)sharedInstance;

///本地设置使用的中介平台，需在传入配置初始化之前设置
- (void)setMediationPlatform:(MRMediationPlatform)platform;

///传入配置初始化
- (void)setupWithConfigure:(NSDictionary *)configure channel:(NSString *)channel completionBlock:(void (^)(NSError *error))completionBlock;

///GDPR
- (void)setGDPRDataCollection:(BOOL)canDataCollection;
- (MRConsentStatus)getGDPRDataCollection;
- (BOOL)isGDPRApplicable;

///CCPA
- (void)setCCPADoNotSell:(BOOL)doNotSell;
- (MRConsentStatus)getCCPADoNotSell;

///COPPA
- (void)setCOPPAIsAgeRestrictedUser:(BOOL)isAgeRestrictedUser;
- (MRConsentStatus)getCOPPAIsAgeRestrictedUser;

///设置日志等级 默认 MRLogLevelOff
- (void)setLogLevel:(MRLogLevel)level;

///用户信息自定义 key:{user_id, user_age, user_gender...}
@property (nonatomic, strong) NSDictionary *dicCustomValue;

///默认使用平台，当网络存在问题时使用此指定平台，默认值：MRMediationPlatformTradPlus
@property (nonatomic,assign)MRMediationPlatform defaultPlatform;

////渠道名称
@property (nonatomic,readonly)NSString *channel;
@property (nonatomic,readonly)MRMediationPlatform mediationPlatform;
@property (nonatomic,readonly)NSString *mediationPlatformName;
@property (nonatomic,readonly)NSString *mediationAppId;
@property (nonatomic,readonly)NSString *mediationSDKVersion;
@property (nonatomic,readonly)BOOL initialized;

@end

NS_ASSUME_NONNULL_END
