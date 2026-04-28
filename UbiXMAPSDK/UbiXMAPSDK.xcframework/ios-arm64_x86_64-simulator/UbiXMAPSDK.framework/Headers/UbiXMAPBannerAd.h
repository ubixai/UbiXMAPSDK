//
//  APBannerAd.h
//  UbiXMAPSDK
//
//  Created by coderqi on 2025/11/13.
//

#import <UIKit/UIKit.h>
#import <UbiXMAPSDK/UbiXMAPBannerSlot.h>
#import <UbiXMAPSDK/UbiXMAPBannerView.h>
#import <UbiXMAPSDK/UbiXMAPBaseAd.h>

NS_ASSUME_NONNULL_BEGIN

@class UbiXMAPBannerSlot;
@class UbiXMAPBannerAd;

@protocol UbiXMAPBannerAdDelegate <NSObject>

/**
 *  广告加载成功
 * @param bannerAd  广告对象
 */
- (void)apu_BannerAdLoadSuccess:(UbiXMAPBannerAd *)bannerAd;

/**
 *  广告加载失败
 * @param bannerAd  广告对象
 * @param error  错误信息
 */
- (void)apu_BannerAdLoadFail:(UbiXMAPBannerAd *)bannerAd withError:(NSError *)error;


/**
 * 广告展示成功
 * @param bannerAd  广告对象
 */
- (void)apu_BannerAdShowSuccess:(UbiXMAPBannerAd *)bannerAd;

/**
 * 广告展示失败
 * @param bannerAd  广告对象
 */
- (void)apu_BannerAdShowFail:(UbiXMAPBannerAd *)bannerAd withError:(NSError *)error;

/**
 * 广告点击
 * @param bannerAd  广告数据
 */
- (void)apu_BannerAdDidClicked:(UbiXMAPBannerAd *)bannerAd;

/**
 * 广告关闭
 * @param bannerAd  广告数据
 */
- (void)apu_BannerAdDidClosed:(UbiXMAPBannerAd *)bannerAd;

/**
 * sdk广告跳转落地页关闭回调
 * @param bannerAd  广告对象
 */
- (void)apu_BannerAdWebPageClose:(UbiXMAPBannerAd *)bannerAd;

@end

@interface UbiXMAPBannerAd : UbiXMAPBaseAd

/// 广告请求参数
@property (nonatomic, strong, readonly) UbiXMAPBannerSlot *adSlot;

@property (nonatomic, weak) id <UbiXMAPBannerAdDelegate> delegate;

/**
 * @brief 初始化view
 */
- (instancetype)initWithSlot:(UbiXMAPBannerSlot *)slot;

/**
 *  加载广告
 */
- (void)loadAd;

/**
 *   获取广告View
 */
- (UbiXMAPBannerView *)getBannerViewError:(NSError **)error;

/**
 * 销毁广告
 */
- (void)destoryAd;

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
