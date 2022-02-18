//
//  MRouterInterstitial.h
//  MRouter
//
//  Created by xuejun on 2022/1/12.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@protocol MRInterstitialDelegate;

@interface MRouterInterstitial : NSObject

/// 设置slot id
/// @param adSlot adslot id
/// @param delegate 回调delegate
- (void)setAdSlot:(NSString *)adSlot delegate:(id<MRInterstitialDelegate>)delegate;


/// 设置slot id
/// @param adSlot adslot id
/// @param delegate 回调delegate
/// @param isAutoLoad 是否使用自动加载模式
- (void)setAdSlot:(NSString *)adSlot delegate:(id<MRInterstitialDelegate>)delegate isAutoLoad:(BOOL)isAutoLoad;

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

@protocol MRInterstitialDelegate <NSObject>

///初始化错误
- (void)MRInterstitialAdInitFail:(NSDictionary *)adInfo error:(NSError *)error;

///AD加载完成 首个广告源加载成功时回调 一次加载流程只会回调一次
- (void)MRInterstitialAdLoaded:(NSDictionary *)adInfo;
///AD加载失败
//////MRInterstitialAdOneLayerLoad:didFailWithError：返回三方源的错误信息(TradPlus)
- (void)MRInterstitialAdLoadFail:(NSDictionary *)adInfo error:(NSError *)error;
///AD展现
- (void)MRInterstitialAdImpression:(NSDictionary *)adInfo;
///AD展现失败
- (void)MRInterstitialAdShow:(NSDictionary *)adInfo didFailWithError:(NSError *)error;
///AD被点击
- (void)MRInterstitialAdClicked:(NSDictionary *)adInfo;
///AD关闭
- (void)MRInterstitialAdDismissed:(NSDictionary *)adInfo;

@optional
///bidding开始
- (void)MRInterstitialAdBidStart:(NSDictionary *)adInfo;
///bidding结束 error = nil 表示成功
- (void)MRInterstitialAdBidEnd:(NSDictionary *)adInfo error:(NSError *)error;
///开始加载
- (void)MRInterstitialAdLoadStart:(NSDictionary *)adInfo;
///当每个广告源加载成功后会都会回调一次。
- (void)MRInterstitialAdOneLayerLoaded:(NSDictionary *)adInfo;
///当每个广告源加载失败后会都会回调一次，返回三方源的错误信息
- (void)MRInterstitialAdOneLayerLoad:(NSDictionary *)adInfo didFailWithError:(NSError *)error;
///加载流程全部结束
- (void)MRInterstitialAdAllLoaded:(NSDictionary *)adInfo success:(BOOL)success;
///开始播放
- (void)MRInterstitialAdPlayStart:(NSDictionary *)adInfo;
///播放结束
- (void)MRInterstitialAdPlayEnd:(NSDictionary *)adInfo;

@end
