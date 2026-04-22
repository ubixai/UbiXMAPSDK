//
//  UbiXMAPBannerView.h
//  UbiXMAPSDK
//
//  Created by coderqi on 2025/12/8.
//

#import <UIKit/UIKit.h>

@class UbiXMAPBannerAd;
@class UbiXMAPAdMetaData;

NS_ASSUME_NONNULL_BEGIN

@protocol UbiXMAPBannerViewDelegate <NSObject>

/**
 * 广告展示
 * @param item  广告数据
 */
- (void)onBannerAdShow;

/**
 * 广告点击
 */
- (void)onBannerAdClickedPoint:(CGPoint)point
                      accX:(NSInteger)accX accY:(NSInteger)accY accZ:(NSInteger)accZ
                     size:(CGSize)size;
/**
 * 广告关闭
 */
- (void)onBannerAdClosed;

@end

@interface UbiXMAPBannerView : UIView


@property (nonatomic,   weak) id <UbiXMAPBannerViewDelegate> delegate;

/**
 * @brief 初始化view
 */
- (instancetype)initWithConfigAdObject:(UbiXMAPBannerAd *)bannerAd
                                adData:(UbiXMAPAdMetaData *)adData;

/**
 * @brief 渲染广告内容
 */
- (NSError *)renderViewsUI;

@end

NS_ASSUME_NONNULL_END
