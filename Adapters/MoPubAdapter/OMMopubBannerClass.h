// Copyright 2020 ADTIMING TECHNOLOGY COMPANY LIMITED
// Licensed under the GNU Lesser General Public License Version 3

#ifndef OMMopubBannerClass_h
#define OMMopubBannerClass_h
#import <CoreLocation/CoreLocation.h>

NS_ASSUME_NONNULL_BEGIN

@class MPAdView;

@protocol MPMoPubAdDelegate;

/**
 This protocol defines functionality that is shared between all MoPub ads.
 */
@protocol MPMoPubAd <NSObject>

@required
/**
 All MoPub ads have a delegate to call back when certain events occur.
 */
@property (nonatomic, weak, nullable) id<MPMoPubAdDelegate> delegate;

@end

/**
 * The delegate of an `MPAdView` object must adopt the `MPAdViewDelegate` protocol. It must
 * implement `viewControllerForPresentingModalView` to provide a root view controller from which
 * the ad view should present modal content.
 *
 * Optional methods of this protocol allow the delegate to be notified of banner success or
 * failure, as well as other lifecycle events.
 */

@protocol MPAdViewDelegate <MPMoPubAdDelegate>

@required

/** @name Managing Modal Content Presentation */

/**
 * Asks the delegate for a view controller to use for presenting modal content, such as the in-app
 * browser that can appear when an ad is tapped.
 *
 * @return A view controller that should be used for presenting modal content.
 */
- (UIViewController *)viewControllerForPresentingModalView;

@optional

/** @name Detecting When a Banner Ad is Loaded */

/**
 * Sent when an ad view successfully loads an ad.
 *
 * Your implementation of this method should insert the ad view into the view hierarchy, if you
 * have not already done so.
 *
 * @param view The ad view sending the message.
 */
- (void)adViewDidLoadAd:(MPAdView *)view __attribute__((deprecated("Deprecated; please use adViewDidLoadAd:adSize: instead.")));

/**
 * Sent when an ad view successfully loads an ad.
 *
 * Your implementation of this method should insert the ad view into the view hierarchy, if you
 * have not already done so.
 *
 * @param view The ad view sending the message.
 * @param adSize The size of the ad that was successfully loaded. It is recommended to resize
 * the @c MPAdView frame to match the height of the loaded ad.
 */
- (void)adViewDidLoadAd:(MPAdView *)view adSize:(CGSize)adSize;

/**
 * Sent when an ad view fails to load an ad.
 *
 * To avoid displaying blank ads, you should hide the ad view in response to this message.
 *
 * @param view The ad view sending the message.
 */
- (void)adViewDidFailToLoadAd:(MPAdView *)view __attribute__((deprecated("Deprecated; please use adView:didFailToLoadAdWithError: instead.")));

/**
 * Sent when an ad view fails to load an ad.
 *
 * To avoid displaying blank ads, you should hide the ad view in response to this message.
 *
 * @param view The ad view sending the message.
 * @param error The error
 */
- (void)adView:(MPAdView *)view didFailToLoadAdWithError:(NSError *)error;

/** @name Detecting When a User Interacts With the Ad View */

/**
 * Sent when an ad view is about to present modal content.
 *
 * This method is called when the user taps on the ad view. Your implementation of this method
 * should pause any application activity that requires user interaction.
 *
 * @param view The ad view sending the message.
 * @see `didDismissModalViewForAd:`
 */
- (void)willPresentModalViewForAd:(MPAdView *)view;

/**
 * Sent when an ad view has dismissed its modal content, returning control to your application.
 *
 * Your implementation of this method should resume any application activity that was paused
 * in response to `willPresentModalViewForAd:`.
 *
 * @param view The ad view sending the message.
 * @see `willPresentModalViewForAd:`
 */
- (void)didDismissModalViewForAd:(MPAdView *)view;

/**
 * Sent when a user is about to leave your application as a result of tapping
 * on an ad.
 *
 * Your application will be moved to the background shortly after this method is called.
 *
 * @param view The ad view sending the message.
 */
- (void)willLeaveApplicationFromAd:(MPAdView *)view;

@end


typedef enum
{
    MPNativeAdOrientationAny,
    MPNativeAdOrientationPortrait,
    MPNativeAdOrientationLandscape
} MPNativeAdOrientation;

/**
 * The MPAdView class provides a view that can display banner advertisements.
 */
IB_DESIGNABLE



@class MPImpressionData;

/**
 This protocol defines callback events shared between all MoPub ads.
 */
@protocol MPMoPubAdDelegate <NSObject>

@optional
/**
 Called when an impression is fired on the @c MPMoPubAd instance. Includes information about the impression if applicable.

 @param ad The @c MPMoPubAd instance that fired the impression
 @param impressionData Information about the impression, or @c nil if the server didn't return any information.
 */
- (void)mopubAd:(id<MPMoPubAd>)ad didTrackImpressionWithImpressionData:(MPImpressionData * _Nullable)impressionData;

@end

@interface MPAdView : UIView <MPMoPubAd>

/** @name Initializing a Banner Ad */

/**
 * Initializes an MPAdView with the given ad unit ID.
 *
 * @param adUnitId A string representing a MoPub ad unit ID.
 * @return A newly initialized ad view corresponding to the given ad unit ID and size.
 */
- (id)initWithAdUnitId:(NSString *)adUnitId;

/**
 * Initializes an MPAdView with the given ad unit ID and banner size.
 *
 * @param adUnitId A string representing a MoPub ad unit ID.
 * @param size The desired ad size. A list of standard ad sizes is available in MPConstants.h.
 * @return A newly initialized ad view corresponding to the given ad unit ID and size.
 */
- (id)initWithAdUnitId:(NSString *)adUnitId size:(CGSize)size __attribute__((deprecated("Use initWithAdUnitId: instead")));

/** @name Setting and Getting the Delegate */

/**
 * The delegate (`MPAdViewDelegate`) of the ad view.
 */
@property (nonatomic, weak) id<MPAdViewDelegate> delegate;

/** @name Setting Request Parameters */

/**
 * The MoPub ad unit ID for this ad view.
 *
 * Ad unit IDs are created on the MoPub website. An ad unit is a defined placement in your
 * application set aside for advertising. If no ad unit ID is set, the ad view will use a default
 * ID that only receives test ads.
 */
@property (nonatomic, copy) IBInspectable NSString *adUnitId;

/**
 * The maximum desired ad size. A list of standard ad sizes is available in MPConstants.h.
 */
@property (nonatomic, assign) IBInspectable CGSize maxAdSize;

/**
 * A string representing a set of non-personally identifiable keywords that should be passed to the MoPub ad server to receive
 * more relevant advertising.

 * Note: If a user is in General Data Protection Regulation (GDPR) region and MoPub doesn't obtain consent from the user, "keywords" will still be sent to the server.
 *
 */
@property (nonatomic, copy) NSString *keywords;

/**
 * A string representing a set of personally identifiable keywords that should be passed to the MoPub ad server to receive
 * more relevant advertising.
 *
 * Keywords are typically used to target ad campaigns at specific user segments. They should be
 * formatted as comma-separated key-value pairs (e.g. "marital:single,age:24").
 *
 * On the MoPub website, keyword targeting options can be found under the "Advanced Targeting"
 * section when managing campaigns.

* Note: If a user is in General Data Protection Regulation (GDPR) region and MoPub doesn't obtain consent from the user, "userDataKeywords" will not be sent to the server.
 */
@property (nonatomic, copy) NSString *userDataKeywords;

/**
 * A `CLLocation` object representing a user's location that should be passed to the MoPub ad server
 * to receive more relevant advertising.
 * @deprecated This API is deprecated and will be removed in a future version.
 */
@property (nonatomic, copy) CLLocation *location __attribute__((deprecated("This API is deprecated and will be removed in a future version.")));

/**
 * An optional dictionary containing extra local data.
 */
@property (nonatomic, copy) NSDictionary *localExtras;

/** @name Loading a Banner Ad */

/**
 * Requests a new ad from the MoPub ad server with a maximum desired ad size equal to
 * the size of the current @c bounds of this view.
 *
 * If the ad view is already loading an ad, this call will be ignored. You may use `forceRefreshAd`
 * if you would like cancel any existing ad requests and force a new ad to load.
 */
- (void)loadAd;

/**
 * Requests a new ad from the MoPub ad server with the specified maximum desired ad size.
 *
 * If the ad view is already loading an ad, this call will be ignored. You may use `forceRefreshAd`
 * if you would like cancel any existing ad requests and force a new ad to load.
 *
 * @param size The maximum desired ad size to request. You may specify this value manually,
 * or use one of the presets found in @c MPConstants.h for the most common types of maximum ad sizes.
 * If using @c kMPPresetMaxAdSizeMatchFrame, the frame will be used as the maximum ad size.
 */
- (void)loadAdWithMaxAdSize:(CGSize)size;

/**
 * Cancels any existing ad requests and requests a new ad from the MoPub ad server
 * using the previously loaded maximum desired ad size.
 */
- (void)forceRefreshAd;

/** @name Handling Orientation Changes */

/**
 * Informs the ad view that the device orientation has changed.
 *
 * Banners from some third-party ad networks have orientation-specific behavior. You should call
 * this method when your application's orientation changes if you want mediated ads to acknowledge
 * their new orientation.
 *
 * If your application layout needs to change based on the size of the mediated ad, you may want to
 * check the value of `adContentViewSize` after calling this method, in case the orientation change
 * causes the mediated ad to resize.
 *
 * @param newOrientation The new interface orientation (after orientation changes have occurred).
 */
- (void)rotateToOrientation:(UIInterfaceOrientation)newOrientation;

/**
 * Forces third-party native ad networks to only use ads sized for the specified orientation.
 *
 * Banners from some third-party ad networks have orientation-specific behaviors and/or sizes.
 * You may use this method to lock ads to a certain orientation. For instance,
 * if you call this with MPInterfaceOrientationPortrait, native networks will never
 * return ads sized for the landscape orientation.
 *
 * @param orientation An MPNativeAdOrientation enum value.
 *
 * <pre><code>typedef enum {
 *          MPNativeAdOrientationAny,
 *          MPNativeAdOrientationPortrait,
 *          MPNativeAdOrientationLandscape
 *      } MPNativeAdOrientation;
 * </code></pre>
 *
 * @see unlockNativeAdsOrientation
 * @see allowedNativeAdsOrientation
 */
- (void)lockNativeAdsToOrientation:(MPNativeAdOrientation)orientation;

/**
 * Allows third-party native ad networks to use ads sized for any orientation.
 *
 * You do not need to call this method unless you have previously called
 * `lockNativeAdsToOrientation:`.
 *
 * @see lockNativeAdsToOrientation:
 * @see allowedNativeAdsOrientation
 */
- (void)unlockNativeAdsOrientation;

/**
 * Returns the banner orientations that third-party ad networks are allowed to use.
 *
 * @return An enum value representing an allowed set of orientations.
 *
 * @see lockNativeAdsToOrientation:
 * @see unlockNativeAdsOrientation
 */
- (MPNativeAdOrientation)allowedNativeAdsOrientation;

/** @name Obtaining the Size of the Current Ad */

/**
 * Returns the size of the current ad being displayed in the ad view.
 *
 * Ad sizes may vary between different ad networks. This method returns the actual size of the
 * underlying mediated ad. This size may be different from the original, initialized size of the
 * ad view. You may use this size to determine to adjust the size or positioning of the ad view
 * to avoid clipping or border issues.
 *
 * @returns The size of the underlying mediated ad.
 */
- (CGSize)adContentViewSize;

/** @name Managing the Automatic Refreshing of Ads */

/**
 * Stops the ad view from periodically loading new advertisements.
 *
 * By default, an ad view is allowed to automatically load new advertisements if a refresh interval
 * has been configured on the MoPub website. This method prevents new ads from automatically loading,
 * even if a refresh interval has been specified.
 *
 * As a best practice, you should call this method whenever the ad view will be hidden from the user
 * for any period of time, in order to avoid unnecessary ad requests. You can then call
 * `startAutomaticallyRefreshingContents` to re-enable the refresh behavior when the ad view becomes
 * visible.
 *
 * @see startAutomaticallyRefreshingContents
 */
- (void)stopAutomaticallyRefreshingContents;

/**
 * Causes the ad view to periodically load new advertisements in accordance with user-defined
 * refresh settings on the MoPub website.
 *
 * Calling this method is only necessary if you have previously stopped the ad view's refresh
 * behavior using `stopAutomaticallyRefreshingContents`. By default, an ad view is allowed to
 * automatically load new advertisements if a refresh interval has been configured on the MoPub
 * website. This method has no effect if a refresh interval has not been set.
 *
 * @see stopAutomaticallyRefreshingContents
 */
- (void)startAutomaticallyRefreshingContents;
@end

NS_ASSUME_NONNULL_END

#endif /* OMMoPubBannerClass_h */
