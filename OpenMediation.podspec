Pod::Spec.new do |s|
  s.name         = 'OpenMediation'
  s.version      = '1.3.3'
  s.summary      = 'OpenMediation SDK for iOS'
  s.homepage     = 'https://github.com/AdTiming/OpenMediation-iOS'
  s.description  = <<-DESC
  'OpenMediation offers diversified and competitive monetization solution and supports a variety of Ad formats including Native Ad, Interstitial Ad, Banner Ad, and Rewarded Video Ad. The OpenMediation Platform works with multiple ad networks include AdMob, Facebook, UnityAds, Vungle, AdColony, AppLovin, Tapjoy, Chartboost, TikTok and Mintegral etc..'
  DESC

  s.license      = { :type => 'LGPL-3.0', :file => 'LICENSE' }
  s.authors      = 'AdTiming'

  s.source       = { :git => 'https://github.com/AdTiming/OpenMediation-iOS.git', :tag => s.version }
  s.module_map   = 'OpenMediation/OpenMediation.modulemap'

  s.libraries = [
                  'c++', 
                  'xml2',
                  'z', 
                  'resolv'
                ]
  s.frameworks = [
                  'AdSupport',
                  'AudioToolbox',
                  'AVFoundation', 
                  'CFNetwork', 
                  'CoreGraphics', 
                  'CoreMedia', 
                  'CoreImage', 
                  'CoreMotion', 
                  'CoreTelephony', 
                  'CoreVideo', 
                  'Foundation', 
                  'GLKit', 
                  'JavaScriptCore', 
                  'MediaPlayer', 
                  'MessageUI', 
                  'MobileCoreServices', 
                  'OpenGLES', 
                  'QuartzCore', 
                  'SafariServices', 
                  'Security', 
                  'StoreKit', 
                  'SystemConfiguration', 
                  'UIKit', 
                  'WebKit', 
                  'VideoToolbox'
                ]


  s.requires_arc = true
  s.platform     = :ios, '9.0'
  s.pod_target_xcconfig = { 'OTHER_LDFLAGS' => '-lObjC' }



  s.default_subspecs =  'MediationSDK'
  
  s.subspec 'MediationSDK' do |ss|
    ss.dependency             'OpenMediation/Mediation'
    ss.dependency             'OpenMediation/AdTimingAdapter'
    ss.dependency             'OpenMediation/AdMobAdapter'
    ss.dependency             'OpenMediation/FacebookAdapter'
    ss.dependency             'OpenMediation/UnityAdapter'
    ss.dependency             'OpenMediation/VungleAdapter'
    ss.dependency             'OpenMediation/TencentAdAdapter'
    ss.dependency             'OpenMediation/AdColonyAdapter'
    ss.dependency             'OpenMediation/AppLovinAdapter'
    ss.dependency             'OpenMediation/MoPubAdapter'  
    ss.dependency             'OpenMediation/ChartboostAdapter'
    ss.dependency             'OpenMediation/TapjoyAdapter'
    ss.dependency             'OpenMediation/TikTokAdapter' 
    ss.dependency             'OpenMediation/MintegralAdapter'
    ss.dependency             'OpenMediation/IronSourceAdapter'
    ss.dependency             'OpenMediation/ChartboostBidAdapter'
    ss.dependency             'OpenMediation/FyberAdapter'        
  end


  s.subspec 'Mediation' do |ss|
    ss.source_files = 'OpenMediation/**/*.{h,m}'
    ss.public_header_files = [
                              'OpenMediation/OpenMediationUmbrella.h',
                              'OpenMediation/OpenMediation.h',
                              'OpenMediation/OpenMediationAdFormats.h',
                              'OpenMediation/OpenMediationBanner/OMBanner.h',
                              'OpenMediation/OpenMediationBanner/OMBannerDelegate.h',
                              'OpenMediation/OpenMediationNative/OMNative.h',
                              'OpenMediation/OpenMediationNative/OMNativeAd.h',
                              'OpenMediation/OpenMediationNative/OMNativeView.h',
                              'OpenMediation/OpenMediationNative/OMNativeMediaView.h',
                              'OpenMediation/OpenMediationNative/OMNativeDelegate.h',
                              'OpenMediation/OpenMediationInterstitial/OMInterstitial.h',
                              'OpenMediation/OpenMediationInterstitial/OMInterstitialDelegate.h',
                              'OpenMediation/OpenMediationRewardedVideo/OMRewardedVideo.h',
                              'OpenMediation/OpenMediationRewardedVideo/OMRewardedVideoDelegate.h',
                              'OpenMediation/OpenMediationSplash/OMSplash.h',
                              'OpenMediation/OpenMediationSplash/OMSplashDelegate.h',
                              'OpenMediation/OpenMediaitonSegments/OMAdSingletonInterface.h',
                              'OpenMediation/OpenMediaitonSegments/OMAdbase.h',
                              'OpenMediation/OpenMediationModel/OMScene.h',
                              'OpenMediation/OpenMediationCustomEvent'
                            ]
  end

  s.subspec 'AdTimingAdapter' do |ss|
    ss.dependency             'OpenMediation/Mediation'
    ss.source_files         = 'OpenMediation/OpenMediationCustomEvent', 'Adapters/AdTimingAdapter'
    ss.public_header_files  = ''
  end

  s.subspec 'AdMobAdapter' do |ss|
    ss.dependency             'OpenMediation/Mediation'    
    ss.source_files         = 'OpenMediation/OpenMediationCustomEvent', 'Adapters/AdmobAdapter'
    ss.public_header_files  = ''
  end

  s.subspec 'FacebookAdapter' do |ss|
    ss.dependency             'OpenMediation/Mediation'    
    ss.source_files         = 'OpenMediation/OpenMediationCustomEvent', 'Adapters/FacebookAdapter'
    ss.public_header_files  = ''
  end

  s.subspec 'UnityAdapter' do |ss|
    ss.dependency             'OpenMediation/Mediation'    
    ss.source_files         = 'OpenMediation/OpenMediationCustomEvent', 'Adapters/UnityAdapter'
    ss.public_header_files  = ''
  end

  s.subspec 'VungleAdapter' do |ss|
    ss.dependency             'OpenMediation/Mediation'    
    ss.source_files         = 'OpenMediation/OpenMediationCustomEvent', 'Adapters/VungleAdapter'
    ss.public_header_files  = ''
  end

  s.subspec 'TencentAdAdapter' do |ss|
    ss.dependency             'OpenMediation/Mediation'    
    ss.source_files         = 'OpenMediation/OpenMediationCustomEvent', 'Adapters/TencentAdAdapter'
    ss.public_header_files  = ''
  end

  s.subspec 'AdColonyAdapter' do |ss|
    ss.dependency             'OpenMediation/Mediation'    
    ss.source_files         = 'OpenMediation/OpenMediationCustomEvent', 'Adapters/AdColonyAdapter'
    ss.public_header_files  = ''
  end 

  s.subspec 'AppLovinAdapter' do |ss|
    ss.dependency             'OpenMediation/Mediation'
    ss.source_files         = 'OpenMediation/OpenMediationCustomEvent', 'Adapters/AppLovinAdapter'
    ss.public_header_files  = ''
  end  

  s.subspec 'MoPubAdapter' do |ss|
    ss.dependency             'OpenMediation/Mediation'
    ss.source_files         = 'OpenMediation/OpenMediationCustomEvent', 'Adapters/MoPubAdapter'
    ss.public_header_files  = ''
  end  

  s.subspec 'TapjoyAdapter' do |ss|
    ss.dependency             'OpenMediation/Mediation'    
    ss.source_files         = 'OpenMediation/OpenMediationCustomEvent', 'Adapters/TapjoyAdapter'
    ss.public_header_files  = ''
  end      

  s.subspec 'ChartboostAdapter' do |ss|
    ss.dependency             'OpenMediation/Mediation'    
    ss.source_files         = 'OpenMediation/OpenMediationCustomEvent', 'Adapters/ChartboostAdapter'
    ss.public_header_files  = ''
  end     

  s.subspec 'TikTokAdapter' do |ss|
    ss.dependency             'OpenMediation/Mediation'    
    ss.source_files         = 'OpenMediation/OpenMediationCustomEvent', 'Adapters/TikTokAdapter'
    ss.public_header_files  = ''
  end   

  s.subspec 'MintegralAdapter' do |ss|
    ss.dependency             'OpenMediation/Mediation'    
    ss.source_files         = 'OpenMediation/OpenMediationCustomEvent', 'Adapters/MintegralAdapter'
    ss.public_header_files  = ''
  end 

  s.subspec 'IronSourceAdapter' do |ss|
    ss.dependency             'OpenMediation/Mediation'    
    ss.source_files         = 'OpenMediation/OpenMediationCustomEvent', 'Adapters/IronSourceAdapter'
    ss.public_header_files  = ''
  end

  s.subspec 'ChartboostBidAdapter' do |ss|
    ss.dependency             'OpenMediation/Mediation'    
    ss.source_files         = 'OpenMediation/OpenMediationCustomEvent', 'Adapters/ChartboostBidAdapter'
    ss.public_header_files  = ''
  end

  s.subspec 'FyberAdapter' do |ss|
    ss.dependency             'OpenMediation/Mediation'    
    ss.source_files         = 'OpenMediation/OpenMediationCustomEvent', 'Adapters/FyberAdapter'
    ss.public_header_files  = ''
  end

end
