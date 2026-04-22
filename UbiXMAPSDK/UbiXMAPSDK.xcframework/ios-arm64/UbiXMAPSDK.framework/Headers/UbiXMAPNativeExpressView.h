//
//  UbiXMAPNativeExpressView.h
//  UbiXMAPSDK
//
//  Created by coderqi on 2025/12/10.
//

#import <UIKit/UIKit.h>
#import <UbiXMAPSDK/UbiXMAPNativeAdData.h>


NS_ASSUME_NONNULL_BEGIN

@interface UbiXMAPNativeExpressView : UIView

/// 根据广告数据源创建广告View
- (instancetype)initWithAdData:(UbiXMAPNativeAdData *)adData;

/**
 * 释放广告
 */
- (void)destory;

@end

NS_ASSUME_NONNULL_END
