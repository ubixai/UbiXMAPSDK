//
//  UbiXMAPMacro.h
//  UbiXMAPSDK
//
//  Created by coderqi on 2025/11/13.
//

#ifndef UbiXMAPMacro_h
#define UbiXMAPMacro_h

/// 广告类型
typedef NS_OPTIONS(NSUInteger, UbiXMAPAdType) {
    /// 信息流
    UbiXMAPAdTypeNative          = 1,
    /// 开屏
    UbiXMAPAdTypeSplash          = 2,
    /// banner
    UbiXMAPAdTypeBanner          = 3,
    /// 插屏
    UbiXMAPAdTypeInterstitial    = 4,
    /// 激励
    UbiXMAPAdTypeRewardVideo    = 5,
    /// 信息流自渲染
    UbiXMAPAdTypeFeedCustom      = 6,
};

/// 广告渲染类型
typedef NS_OPTIONS(NSInteger, UbiXMAPAdRenderType) {
    /// 默认值
    UbiXMAPAdRenderTypeDefault = -9999,
    /// sdk模版渲染
    UbiXMAPAdRenderTypeTemplate = 1,
    /// 媒体自渲染
    UbiXMAPAdRenderTypeCustom   = 2,
};

/// 广告数据请求回调
typedef void(^UbiXMAPAdDataCallBackHandler)(NSArray * _Nullable array, NSError * _Nullable error);

/**
 * 视频播放器状态枚举
 */
typedef NS_ENUM(NSInteger, UbiXMAPVideoPlayerState) {
    UbiXMAPVideoPlayerStateUnknown = 0,  // 未知状态
    UbiXMAPVideoPlayerStateBuffering,    // 正在缓冲
    UbiXMAPVideoPlayerStatePlaying,      // 正在播放
    UbiXMAPVideoPlayerStatePaused,       // 已暂停
    UbiXMAPVideoPlayerStateStopped,      // 已停止
    UbiXMAPVideoPlayerStateCompleted,    // 播放完成
    UbiXMAPVideoPlayerStateFailed        // 播放失败
};

/**
 * 视频播放状态回调
 * @param state 当前视频播放状态
 * @param error 如果出现错误，包含错误信息
 */
typedef void(^UbiXMAPVideoPlayerStateCallback)(UbiXMAPVideoPlayerState state, NSError * _Nullable error);

/**
 * 视频播放进度回调
 * @param currentTime 当前播放时间（秒）
 * @param duration 视频总时长（秒）
 */
typedef void(^UbiXMAPVideoPlayerProgressCallback)(NSTimeInterval currentTime, NSTimeInterval duration);

/// 广告打开类
typedef NS_OPTIONS(NSUInteger, UbiXMAPAdOpenType) {
    /// push
    UbiXMAPAdOpenTypePush    = 1,
    /// Present
    UbiXMAPAdOpenTypePresent = 2,
};

/// 交互类型
typedef NS_ENUM(NSInteger, UbiXMAPAdInteractionType) {
    UbiXMAPAdInteractionTypeUnknown,        //unknown type
    UbiXMAPAdInteractionTypeApp,            //open download page in-app
    UbiXMAPAdInteractionTypeWeb,            //open webpage in-app
    UbiXMAPAdInteractionTypeDeepLink,       //open deeplink
    UbiXMAPAdInteractionTypeAppStore,       //open appstore
    UbiXMAPAdInteractionTypeSafari,         //open safari
    UbiXMAPAdInteractionTypeError           //can`t open landing page
};

/**以下为C2S bidding上报参数key**/
//竞胜方价格 单位：分
#define kAPAdMediaWinPrice   @"win_price"
//最大竞败方出价 单位：分
#define kAPAdMediaLossPrice  @"sec_price"
//竞败原因 0 未知 100价格低失败 200 超时失败
#define kAPAdMediaLossReason @"loss_reason"

#endif /* UbiXMAPMacro_h */
