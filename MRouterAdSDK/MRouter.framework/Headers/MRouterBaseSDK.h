//
//  MRouterBaseSDK.h
//  MRouter
//
//  Created by xuejun on 2022/1/12.
//

#import <Foundation/Foundation.h>
#import <MRouter/MRouterCommon.h>


@interface MRouterBaseSDK : NSObject

+ (void)registeClass;

@property (nonatomic,copy)NSString *appId;
@property (nonatomic, strong)NSDictionary *dicCustomValue;

//----- 以下方法需要子类实现 ------
//平台名称
- (NSString *)platformName;
//初始化
- (void)setupWithConfigure:(NSDictionary *)configure completionBlock:(void (^)(NSError *error))completionBlock;
///GDPR
- (void)setGDPRDataCollection:(MRConsentStatus)consentStatus;
- (MRConsentStatus)getGDPRDataCollection;
- (BOOL)isGDPRApplicable;
///CCPA
- (void)setCCPADoNotSell:(MRConsentStatus)doNotSell;
- (MRConsentStatus)getCCPADoNotSell;
///COPPA
- (void)setCOPPAIsAgeRestrictedUser:(MRConsentStatus)isAgeRestrictedUser;
- (MRConsentStatus)getCOPPAIsAgeRestrictedUser;
//日志等级设置
- (void)setLogLevel:(MRLogLevel)level;
//SDK版本号
- (NSString *)SDKVersion;
//自定义参数
- (void)setDicCustomValue:(NSDictionary *)dicCustomValue;
@end
