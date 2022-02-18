//
//  MRouterRewarded.h
//  MRouter
//
//  Created by xuejun on 2022/1/12.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN
@protocol MRRewardedDelegate;
@interface MRouterRewarded : NSObject

/// 设置slot id
/// @param adSlot adslot id
/// @param delegate 回调delegate
- (void)setAdSlot:(NSString *)adSlot delegate:(id<MRRewardedDelegate>)delegate;


/// 设置slot id
/// @param adSlot adslot id
/// @param delegate 回调delegate
/// @param isAutoLoad 是否使用自动加载模式
- (void)setAdSlot:(NSString *)adSlot delegate:(id<MRRewardedDelegate>)delegate isAutoLoad:(BOOL)isAutoLoad;

/// 设置服务器端奖励验证用户数据 load前设置
/// @param userID 用户唯一识别码 必填
/// @param customData 附加信息 根据平台要求填写
- (void)setServerSideVerificationOptionsWithUserID:(NSString *)userID customData:(NSString *)customData;

///加载广告
- (void)loadAd;

/// 进入广告场景
/// @param sceneId 场景ID 没有则设置为nil
- (void)entryAdScenario:(NSString *)sceneId;

/// 显示广告
/// @param rootViewController rootViewController
/// @param sceneId 广告位ID
- (void)showAdFromRootViewController:(UIViewController *)rootViewController sceneId:(NSString *)sceneId;

///是否可用
@property (nonatomic, readonly) BOOL isAdReady;

///用户信息自定义 key:{user_id, user_age, user_gender...}
@property (nonatomic, strong) NSDictionary *dicCustomValue;

@property (nonatomic,readonly)NSString *adSlot;
@property (nonatomic,readonly)BOOL isAutoLoad;

@end

@protocol MRRewardedDelegate <NSObject>

///初始化错误
- (void)MRRewardedAdInitFail:(NSDictionary *)adInfo error:(NSError *)error;

///AD加载完成 首个广告源加载成功时回调 一次加载流程只会回调一次
- (void)MRRewardedAdLoaded:(NSDictionary *)adInfo;
///AD加载失败
///MRRewardedAdOneLayerLoad:didFailWithError：返回三方源的错误信息(TradPlus)
- (void)MRRewardedAdLoadFail:(NSDictionary *)adInfo error:(NSError *)error;
///AD展现
- (void)MRRewardedAdImpression:(NSDictionary *)adInfo;
///AD展现失败
- (void)MRRewardedAdShow:(NSDictionary *)adInfo didFailWithError:(NSError *)error;
///AD被点击
- (void)MRRewardedAdClicked:(NSDictionary *)adInfo;
///AD关闭
- (void)MRRewardedAdDismissed:(NSDictionary *)adInfo;
///完成奖励
- (void)MRRewardedAdReward:(NSDictionary *)adInfo;
@optional
///再看一个的完成奖励 （快手）
- (void)MRRewardedAdPlayAgainReward:(NSDictionary *)adInfo;
///bidding开始
- (void)MRRewardedAdBidStart:(NSDictionary *)adInfo;
///bidding结束 error = nil 表示成功
- (void)MRRewardedAdBidEnd:(NSDictionary *)adInfo error:(NSError *)error;
///开始加载
- (void)MRRewardedAdLoadStart:(NSDictionary *)adInfo;
///当每个广告源加载成功后会都会回调一次。
- (void)MRRewardedAdOneLayerLoaded:(NSDictionary *)adInfo;
///当每个广告源加载失败后会都会回调一次，返回三方源的错误信息
- (void)MRRewardedAdOneLayerLoad:(NSDictionary *)adInfo didFailWithError:(NSError *)error;
///加载流程全部结束
- (void)MRRewardedAdAllLoaded:(NSDictionary *)adInfo success:(BOOL)success;
///开始播放
- (void)MRRewardedAdPlayStart:(NSDictionary *)adInfo;
///播放结束
- (void)MRRewardedAdPlayEnd:(NSDictionary *)adInfo;

@end

NS_ASSUME_NONNULL_END
