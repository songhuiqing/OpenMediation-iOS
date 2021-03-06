// Copyright 2020 ADTIMING TECHNOLOGY COMPANY LIMITED
// Licensed under the GNU Lesser General Public License Version 3

#import "OMAdTimingRewardedVideo.h"

@implementation OMAdTimingRewardedVideo

- (instancetype)initWithParameter:(NSDictionary*)adParameter {
    if (self = [super init]) {
        _pid = [adParameter objectForKey:@"pid"];
    }
    return self;
    
}

-(void)loadAd {
    Class rewardedVideoClass = NSClassFromString(@"AdTimingAdsRewardedVideo");
    if (rewardedVideoClass && [rewardedVideoClass respondsToSelector:@selector(sharedInstance)] && [rewardedVideoClass instancesRespondToSelector:@selector(loadWithPlacementID:)] && [_pid length]>0) {
        [[rewardedVideoClass sharedInstance]loadWithPlacementID:_pid];
        if (rewardedVideoClass && [rewardedVideoClass respondsToSelector:@selector(sharedInstance)] && [rewardedVideoClass instancesRespondToSelector:@selector(addDelegate:)]) {
            [[rewardedVideoClass sharedInstance]addDelegate:self];
        }
    }
}

- (void)loadAdWithBidPayload:(NSString *)bidPayload {
    Class rewardedVideoClass = NSClassFromString(@"AdTimingAdsRewardedVideo");
    if (rewardedVideoClass && [rewardedVideoClass respondsToSelector:@selector(sharedInstance)] && [rewardedVideoClass instancesRespondToSelector:@selector(loadWithPlacementID:)] && [_pid length]>0) {
        [[rewardedVideoClass sharedInstance]loadWithPlacementID:_pid payLoad:bidPayload];
        if (rewardedVideoClass && [rewardedVideoClass respondsToSelector:@selector(sharedInstance)] && [rewardedVideoClass instancesRespondToSelector:@selector(addDelegate:)]) {
            [[rewardedVideoClass sharedInstance]addDelegate:self];
        }
    }
}

-(BOOL)isReady {
    BOOL isReady = NO;
    Class rewardedVideoClass = NSClassFromString(@"AdTimingAdsRewardedVideo");
    if (rewardedVideoClass && [rewardedVideoClass respondsToSelector:@selector(sharedInstance)] && [rewardedVideoClass instancesRespondToSelector:@selector(isReady:)] && [_pid length]>0) {
        isReady = [[rewardedVideoClass sharedInstance]isReady:_pid];
    }
    return isReady;
}

- (void)show:(UIViewController *)vc {
    Class rewardedVideoClass = NSClassFromString(@"AdTimingAdsRewardedVideo");
    if ([self isReady]) {
        if (rewardedVideoClass && [rewardedVideoClass respondsToSelector:@selector(sharedInstance)] && [rewardedVideoClass instancesRespondToSelector:@selector(showAdFromRootViewController:placementID:)]) {
            [[rewardedVideoClass sharedInstance]showAdFromRootViewController:vc placementID:_pid];
        }
    }
}


- (void)adtimingRewardedVideoDidLoad:(NSString *)placementID {
    if ([placementID isEqualToString:_pid] && _delegate && [_delegate respondsToSelector:@selector(customEvent:didLoadAd:)]) {
        [_delegate customEvent:self didLoadAd:nil];
     }
}

- (void)adtimingRewardedVideoDidFailToLoad:(NSString *)placementID withError:(NSError *)error {
    if ([placementID isEqualToString:_pid] && _delegate && [_delegate respondsToSelector:@selector(customEvent:didFailToLoadWithError:)]) {
        [_delegate customEvent:self didFailToLoadWithError:error];
     }
}


- (void)adtimingRewardedVideoDidOpen:(NSString*)placementID {
    if ([placementID isEqualToString:_pid] && _delegate && [_delegate respondsToSelector:@selector(rewardedVideoCustomEventDidOpen:)]) {
        [_delegate rewardedVideoCustomEventDidOpen:self];
    }
}

- (void)adtimingRewardedVideoPlayStart:(NSString*)placementID {
    if ([placementID isEqualToString:_pid] && _delegate && [_delegate respondsToSelector:@selector(rewardedVideoCustomEventVideoStart:)]) {
        [_delegate rewardedVideoCustomEventVideoStart:self];
    }
}

- (void)adtimingRewardedVideoPlayEnd:(NSString*)placementID {
    if ([placementID isEqualToString:_pid] && _delegate && [_delegate respondsToSelector:@selector(rewardedVideoCustomEventVideoEnd:)]) {
        [_delegate rewardedVideoCustomEventVideoEnd:self];
    }
}

- (void)adtimingRewardedVideoDidClick:(NSString*)placementID {
    if ([placementID isEqualToString:_pid] && _delegate && [_delegate respondsToSelector:@selector(rewardedVideoCustomEventDidClick:)]) {
        [_delegate rewardedVideoCustomEventDidClick:self];
    }
}

- (void)adtimingRewardedVideoDidReceiveReward:(NSString*)placementID {
    if ([placementID isEqualToString:_pid] && _delegate && [_delegate respondsToSelector:@selector(rewardedVideoCustomEventDidReceiveReward:)]) {
        [_delegate rewardedVideoCustomEventDidReceiveReward:self];
    }
}

- (void)adtimingRewardedVideoDidClose:(NSString*)placementID {
    if ([placementID isEqualToString:_pid] && _delegate && [_delegate respondsToSelector:@selector(rewardedVideoCustomEventDidClose:)]) {
        [_delegate rewardedVideoCustomEventDidClose:self];
    }
}

- (void)adtimingRewardedVideoDidFailToShow:(NSString*)placementID withError:(NSError *)error {
    if ([placementID isEqualToString:_pid] && _delegate && [_delegate respondsToSelector:@selector(rewardedVideoCustomEventDidFailToShow:withError:)]) {
        [_delegate rewardedVideoCustomEventDidFailToShow:self withError:error];
    }
}

@end
