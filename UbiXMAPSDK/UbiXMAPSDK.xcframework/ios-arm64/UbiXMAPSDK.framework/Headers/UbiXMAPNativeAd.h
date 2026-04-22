//
//  UbiXMAPNativeAd.h
//  UbiXMAPSDK
//
//  Created by coderqi on 2025/11/14.
//

#import <Foundation/Foundation.h>
#import <UbiXMAPSDK/UbiXMAPNativeAdObject.h>
#import <UbiXMAPSDK/UbiXMAPNativeAdSlot.h>
#import <UbiXMAPSDK/UbiXMAPBaseAd.h>

NS_ASSUME_NONNULL_BEGIN

@class UbiXMAPNativeAdSlot;
@class UbiXMAPNativeAd;

@protocol UbiXMAPNativeAdDelegate <NSObject>

- (void)apu_nativeAdLoadSuccess:(UbiXMAPNativeAd *)nativeAd;

- (void)apu_nativeAdLoadFail:(UbiXMAPNativeAd *)nativeAd withError:(NSError *)error;



@end

@interface UbiXMAPNativeAd : UbiXMAPBaseAd
/// 广告请求参数
@property (nonatomic, strong, readonly) UbiXMAPNativeAdSlot *adSlot;

@property (nonatomic, weak) id <UbiXMAPNativeAdDelegate> delegate;

/// 广告对象，在apu_nativeAdLoadSuccess回调后有值
@property (nonatomic, strong, readonly, nullable) NSArray <UbiXMAPNativeAdObject *> *nativeAdObjects;

/**
 * @brief 初始化view
 */
- (instancetype)initWithSlot:(UbiXMAPNativeAdSlot *)slot;

/**
 *  加载广告
 */
- (void)loadAd;

/**
 *  注册自渲染view
 *  @param containerView     广告渲染容器
 *  @param clickableViews   广告可点击的views，不传：默认整个广告可响应点击
 *  @return 返回错误，检查adItem、containerView、clickableViews是否存在问题
 */
- (NSError *)registerWithAdObject:(UbiXMAPNativeAdObject *)adObject
                       containerView:(UIView *)containerView
                      clickableViews:(NSArray<UIView *> *_Nullable)clickableViews
                        closeView:(NSArray<UIView *> *_Nullable)closeableViews;

/**
 *  销毁广告
 */
- (void)destory;

@end

NS_ASSUME_NONNULL_END
