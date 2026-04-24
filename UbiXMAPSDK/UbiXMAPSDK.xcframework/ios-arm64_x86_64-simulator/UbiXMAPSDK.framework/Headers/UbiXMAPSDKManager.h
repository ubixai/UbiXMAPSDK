//
//  UbiXMAPSDKManager.h
//  UbiXMAPSDK
//
//  Created by coderqi on 2025/11/14.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef void (^UbiXMAPInitResultBlock)(BOOL isSucc, NSError * _Nullable error);

@interface UbiXMAPSDKManager : NSObject

/**
 * SDK 初始化接口，请在 app 初始化时调用。
 * @param clientId - UbiXMAP开发者后台创建的clientId
 * @param clientSecret - UbiXMAP开发者后台创建的clientSecret
 */
+ (NSError *)initWithClientId:(NSString *)clientId andClientSecret:(NSString *)clientSecret;

/**
 * SDK 初始化接口，请在 app 初始化时调用。
 * @param clientId - UbiXMAP开发者后台创建的clientId
 * @param clientSecret - UbiXMAP开发者后台创建的clientSecret
 * @param resultBlock - UbiXMAP SDK初始化结果
 */
+ (NSError *)initWithClientId:(NSString *)clientId andClientSecret:(NSString *)clientSecret andInitResult:(UbiXMAPInitResultBlock)resultBlock;

/**
 * 获取 SDK 版本
 */
+ (NSString *)SDKVersion;

/**
 *  是否允许sdk 获取当前设备经纬度信息
 *  @param canGetLBSBySDK    默认NO，不允许
 */
+ (void)getDeviceLBSBySDK:(BOOL)canGetLBSBySDK;

/**
 *  是否在控制台打印Log
 *  @param isOpen    默认NO，不允许
 */
+ (void)setOpenLog:(BOOL)isOpen;

/**
 *  接入方透传经纬度信息
 *  @param lon  经度信息
 *  @param lat  纬度信息
 */
 + (void)updateLocalLBSLon:(nullable NSString *)lon
                       lat:(nullable NSString *)lat;

/**
 *  是否打开个性化广告开关
 *  @param isOpen  是否打开
 */
+ (void)setPersonalInfo:(BOOL)isOpen;


@end

NS_ASSUME_NONNULL_END
