//
//  MRouterBaseInterstitial.h
//  MRouter
//
//  Created by xuejun on 2022/1/12.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <MRouter/MRouterCommon.h>

@interface MRouterBaseInterstitial : NSObject

+ (void)registeClass;
- (void)callbackWithType:(MRCallBackType)type adInfo:(NSDictionary *)adInfo error:(NSError *)error;
@property (nonatomic,copy)void (^callbackInfo)(NSDictionary *adInfo,NSError *error,MRCallBackType type);

//----- 以下方法需要子类实现 ------
- (NSString *)platformName;
- (void)setUnitID:(NSString *)unitID isAutoLoad:(BOOL)isAutoLoad;
- (void)loadAd;
- (void)entryAdScenario:(NSString *)sceneId;
- (void)showAdFromRootViewController:(UIViewController *)rootViewController sceneId:(NSString *)sceneId;
- (BOOL)isAdReady;
- (void)setDicCustomValue:(NSDictionary *)dicCustomValue;
@end
