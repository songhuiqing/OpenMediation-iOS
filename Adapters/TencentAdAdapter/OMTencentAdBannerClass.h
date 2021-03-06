// Copyright 2020 ADTIMING TECHNOLOGY COMPANY LIMITED
// Licensed under the GNU Lesser General Public License Version 3

#ifndef OMTencentBannerClass_h
#define OMTencentBannerClass_h

@class GDTUnifiedBannerView;

@protocol GDTUnifiedBannerViewDelegate <NSObject>
@optional
/**
 *  请求广告条数据成功后调用
 *  当接收服务器返回的广告数据成功后调用该函数
 */
- (void)unifiedBannerViewDidLoad:(GDTUnifiedBannerView *)unifiedBannerView;

/**
 *  请求广告条数据失败后调用
 *  当接收服务器返回的广告数据失败后调用该函数
 */
- (void)unifiedBannerViewFailedToLoad:(GDTUnifiedBannerView *)unifiedBannerView error:(NSError *)error;

/**
 *  banner2.0曝光回调
 */
- (void)unifiedBannerViewWillExpose:(GDTUnifiedBannerView *)unifiedBannerView;

/**
 *  banner2.0点击回调
 */
- (void)unifiedBannerViewClicked:(GDTUnifiedBannerView *)unifiedBannerView;

/**
 *  banner2.0广告点击以后即将弹出全屏广告页
 */
- (void)unifiedBannerViewWillPresentFullScreenModal:(GDTUnifiedBannerView *)unifiedBannerView;

/**
 *  banner2.0广告点击以后弹出全屏广告页完毕
 */
- (void)unifiedBannerViewDidPresentFullScreenModal:(GDTUnifiedBannerView *)unifiedBannerView;

/**
 *  全屏广告页即将被关闭
 */
- (void)unifiedBannerViewWillDismissFullScreenModal:(GDTUnifiedBannerView *)unifiedBannerView;

/**
 *  全屏广告页已经被关闭
 */
- (void)unifiedBannerViewDidDismissFullScreenModal:(GDTUnifiedBannerView *)unifiedBannerView;

/**
 *  当点击应用下载或者广告调用系统程序打开
 */
- (void)unifiedBannerViewWillLeaveApplication:(GDTUnifiedBannerView *)unifiedBannerView;

/**
 *  banner2.0被用户关闭时调用
 */
- (void)unifiedBannerViewWillClose:(GDTUnifiedBannerView *)unifiedBannerView;

@end

@interface GDTUnifiedBannerView : UIView
/**
 *  委托 [可选]
 */
@property (nonatomic, weak) id<GDTUnifiedBannerViewDelegate> delegate;

/**
 *  Banner展现和轮播时的动画效果开关，默认打开
 */
@property (nonatomic) BOOL animated;

/**
 *  广告刷新间隔，范围 [30, 120] 秒，默认值 30 秒。设 0 则不刷新。 [可选]
 */
@property (nonatomic) int autoSwitchInterval;
/**
 *  构造方法
 *  详解：placementId - 广告位 ID
 *       viewController - 视图控制器
 */
- (instancetype)initWithPlacementId:(NSString *)placementId
                     viewController:(UIViewController *)viewController;

/**
 *  构造方法
 *  详解：frame - banner 展示的位置和大小
 *       placementId - 广告位 ID
 *       viewController - 视图控制器
 */
- (instancetype)initWithFrame:(CGRect)frame
                  placementId:(NSString *)placementId
               viewController:(UIViewController *)viewController;

/**
 *  拉取并展示广告
 */
- (void)loadAdAndShow;

@end

#endif /* OMTencentBannerClass_h */
