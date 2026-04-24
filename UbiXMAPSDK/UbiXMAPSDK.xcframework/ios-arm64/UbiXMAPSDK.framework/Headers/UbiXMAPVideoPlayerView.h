//
//  UbiXMAPVideoPlayerView.h
//  UbiXMAPSDK
//
//  Created by coderqi on 2025/12/9.
//

#import <UIKit/UIKit.h>
#import <UbiXMAPSDK/UbiXMAPMacro.h>

NS_ASSUME_NONNULL_BEGIN

@interface UbiXMAPVideoPlayerView : UIView

/**
 * 是否在滚动导致可见面积不足时自动暂停，再次露出时恢复播放（适用于列表/信息流等）。
 * 依据裁剪可见比：离屏为「<30% 且较上拍面积减小」；回屏为「上拍<30% 且本拍>=30% 且较上拍增大」
 * 或原「<50% -> >=50%」。默认 NO。
 */
@property (nonatomic, assign) BOOL pausesWhenOffscreen;

/**
 * 设置视频播放状态回调
 * @param callback 状态变化时的回调
 */
- (void)setStateCallback:(nullable UbiXMAPVideoPlayerStateCallback)callback;

/**
 * 设置视频播放进度回调
 * @param callback 进度变化时的回调，间隔（1秒）
 */
- (void)setProgressCallback:(nullable UbiXMAPVideoPlayerProgressCallback)callback;

/**
 * 开始播放视频
 */
- (void)play;

/**
 * 暂停播放
 */
- (void)pause;

/**
 * 重新播放视频
 */
- (void)replay;

/**
 * 静音/取消静音
 * @param mute YES表示静音，NO表示取消静音
 */
- (void)setMute:(BOOL)mute;

/**
 * 播放器状态
 * @return SYVideoPlayerState
 */
- (UbiXMAPVideoPlayerState)playerState;

/**
 * 释放资源
 */
- (void)releasePlayer;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;


@end

NS_ASSUME_NONNULL_END
