//
//  UbiXMAPRewardVideoAd.h
//  UbiXMAPSDK
//
//  Created by coderqi on 2025/11/14.
//

#import <Foundation/Foundation.h>
#import <UbiXMAPSDK/UbiXMAPRewardVideoSlot.h>
#import <UbiXMAPSDK/UbiXMAPBaseAd.h>

NS_ASSUME_NONNULL_BEGIN

@class UbiXMAPRewardVideoAd;
@class UbiXMAPRewardVideoSlot;

@protocol UbiXMAPRewardVideoAdDelegate <NSObject>

@optional
/**
 *  广告加载成功
 * @param rewardAd  广告对象
 */
- (void)apu_RewardAdLoadSuccess:(UbiXMAPRewardVideoAd *)rewardAd;

/**
 *  广告加载失败
 * @param rewardAd  广告对象
 * @param error  错误信息
 */
- (void)apu_RewardAdLoadFail:(UbiXMAPRewardVideoAd *)rewardAd withError:(NSError *)error;


/**
 * 广告展示成功
 * @param rewardAd  广告对象
 */
- (void)apu_RewardAdShowSuccess:(UbiXMAPRewardVideoAd *)rewardAd;

/**
 * 广告展示失败
 * @param rewardAd  广告对象
 */
- (void)apu_RewardAdShowFail:(UbiXMAPRewardVideoAd *)rewardAd withError:(NSError *)error;

/**
 * 广告播放开始
 * @param rewardAd  广告对象
 */
- (void)apu_RewardAdPlayStart:(UbiXMAPRewardVideoAd *)rewardAd;

/**
 * 广告播放结束
 * @param rewardAd  广告对象
 */
- (void)apu_RewardAdPlayFinished:(UbiXMAPRewardVideoAd *)rewardAd;

/**·
 * 广告点击
 * @param rewardAd  广告对象
 */
- (void)apu_RewardAdDidClicked:(UbiXMAPRewardVideoAd *)rewardAd;

/**
 * 广告关闭
 * @param rewardAd  广告对象
 */
- (void)apu_RewardAdDidClosed:(UbiXMAPRewardVideoAd *)rewardAd;

/**
 * 广告点击跳过
 * @param rewardAd  广告对象
 */
- (void)apu_RewardAdDidSkiped:(UbiXMAPRewardVideoAd *)rewardAd;

/**
 * sdk广告跳转落地页关闭回调
 * @param rewardAd  广告对象
 */
- (void)apu_RewardAdWebPageClose:(UbiXMAPRewardVideoAd *)rewardAd;

/**
 *  广告任务完成
 *  @param rewardAd  广告对象
 */
- (void)apu_RewardAdTaskCompleted:(UbiXMAPRewardVideoAd *)rewardAd;

@end

@interface UbiXMAPRewardVideoAd : UbiXMAPBaseAd

/// 广告请求参数
@property (nonatomic, strong, readonly) UbiXMAPRewardVideoSlot *adSlot;

@property (nonatomic, weak) id <UbiXMAPRewardVideoAdDelegate> delegate;

/**
 * @brief 初始化view
 */
- (instancetype)initWithSlot:(UbiXMAPRewardVideoSlot *)slot;

/**
 *  加载广告
 */
- (void)loadAd;

/**
 *  展示开屏广告
 *  @param rootViewController 展示开屏广告的UIViewController
 *  曝光时，请确保rootViewController无presentedVC，否则影响广告展示、点击、落地页打开
 */
- (void)showAdFromRootViewController:(UIViewController *)rootViewController;

/**
 * 获取广告出价
 * 广告加载成功之后，才会有值
 *  单位：分
 */
- (NSInteger)getBidPrice;

/**
 * 聚合竞价结果回传
 */
- (void)sendBidResultNotificationWithInfo:(NSDictionary *)infoDic andResut:(BOOL)isSucc;

@end

NS_ASSUME_NONNULL_END
