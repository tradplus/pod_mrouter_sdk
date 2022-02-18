//
//  MRouterCommon.h
//  MRouter
//
//  Created by xuejun on 2022/1/14.
//

typedef enum : NSUInteger {
    MRMediationPlatformTradPlus = 1,
    MRMediationPlatformMax
} MRMediationPlatform;

typedef enum : NSUInteger {
    MRConsentStatusUnSet = -1,
    MRConsentStatusDenied = 0,
    MRConsentStatusConsented = 1
} MRConsentStatus;

typedef enum
{
    MRLogLevelAll        = 0,
    MRLogLevelTrace      = 10,
    MRLogLevelDebug      = 20,
    MRLogLevelInfo       = 30,
    MRLogLevelWarn       = 40,
    MRLogLevelError      = 50,
    MRLogLevelFatal      = 60,
    MRLogLevelOff        = 70
} MRLogLevel;

typedef enum
{
    MRCallBack_Loaded = 0,
    MRCallBack_LoadFail,
    MRCallBack_Show,
    MRCallBack_ShowFail,
    MRCallBack_Click,
    MRCallBack_Close,
    MRCallBack_BidStart,
    MRCallBack_BidEnd,
    MRCallBack_LoadStart,
    MRCallBack_OneLayerLoaded,
    MRCallBack_AdOneLayerLoadFail,
    MRCallBack_AllLoaded,
    MRCallBack_PlayStart,
    MRCallBack_PlayEnd,
    MRCallBack_Reward,
    MRCallBack_PlayAgainReward
} MRCallBackType;

