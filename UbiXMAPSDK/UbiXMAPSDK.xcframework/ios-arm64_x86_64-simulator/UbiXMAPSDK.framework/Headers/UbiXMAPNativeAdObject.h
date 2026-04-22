//
//  UbiXMAPNativeAdObject.h
//  UbiXMAPSDK
//
//  Created by coderqi on 2025/12/10.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <UbiXMAPSDK/UbiXMAPNativeAdData.h>
#import <UbiXMAPSDK/UbiXMAPNativeExpressView.h>
#import <UbiXMAPSDK/UbiXMAPVideoPlayerView.h>

@class UbiXMAPAdMetaData;
@class UbiXMAPNativeAdObject;
NS_ASSUME_NONNULL_BEGIN

@protocol UbiXMAPNativeAdObjectDelegate <NSObject>

/**
 * 广告展示
 * @param adObject  广告数据
 */
- (void)apu_NativeAdShow:(UbiXMAPNativeAdObject *)adObject;

/**
 * 广告点击
 * @param adObject  广告数据
 */
- (void)apu_NativeAdClicked:(UbiXMAPNativeAdObject *)adObject;
/**
 * 广告关闭
 * @param adObject  广告数据
 */
- (void)apu_NativeAdClosed:(UbiXMAPNativeAdObject *)adObject;

/**
 * 广告关闭
 * @param adObject  广告数据
 */
- (void)apu_NativeAdWebPageClosed:(UbiXMAPNativeAdObject *)adObject;

@end

@interface UbiXMAPNativeAdObject : NSObject

/// 是否是模板广告
@property (nonatomic, assign) BOOL isExpress;

/// 获取广告模板视图
///  非模板广告时，返回空
- (UbiXMAPNativeExpressView *)getExpressView;

/// 获取广告的视频播放器
- (UbiXMAPVideoPlayerView *)getMediaView;

@property (nonatomic, weak) id <UbiXMAPNativeAdObjectDelegate> delegate;

/// 广告的原始数据
@property (nonatomic, strong, readonly) UbiXMAPNativeAdData *adData;

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
