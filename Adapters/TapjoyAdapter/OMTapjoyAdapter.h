// Copyright 2020 ADTIMING TECHNOLOGY COMPANY LIMITED
// Licensed under the GNU Lesser General Public License Version 3

#import <Foundation/Foundation.h>
#import "OMMediationAdapter.h"
#import "OMTapjoyClass.h"

NS_ASSUME_NONNULL_BEGIN

static NSString * const TapjoyAdapterVersion = @"3.1.1";

@interface OMTapjoyAdapter : NSObject<OMMediationAdapter>
@property (nonatomic, copy, nullable) OMMediationAdapterInitCompletionBlock initBlock;

+ (NSString*)adapterVerison;
+ (void)initSDKWithConfiguration:(NSDictionary *)configuration completionHandler:(OMMediationAdapterInitCompletionBlock)completionHandler;
+ (instancetype)sharedInstance;
+ (void)setConsent:(BOOL)consent;
+ (void)setUSPrivacyLimit:(BOOL)privacyLimit;
@end

NS_ASSUME_NONNULL_END
