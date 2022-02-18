Pod::Spec.new do |spec|
  spec.name         = "MRouterAdSDK"
  spec.version      = "1.0.0.2"
  spec.summary      = "MRouterAd SDK"
  spec.description  = <<-DESC
            MRouterAd SDK for iOS
                   DESC
  spec.homepage     = "https://github.com/tradplus/pod_mrouter_sdk"
  spec.license      = { :type => "MIT", :file => "LICENSE" }
  spec.author       = { "tradplus" => "service@tradplus.com" }
  spec.source       = { :git => "https://github.com/tradplus/pod_mrouter_sdk.git", :tag => spec.version }
  spec.platform     = :ios, '9.0'
  spec.ios.deployment_target = '9.0'
  spec.requires_arc = true
  spec.frameworks = 'SystemConfiguration', 'CoreGraphics','Foundation','UIKit'
  spec.user_target_xcconfig =   {'OTHER_LDFLAGS' => ['-lObjC']}
  spec.default_subspecs = 'MRouter'

  spec.subspec 'MRouter' do |ss|
     ss.ios.deployment_target = '9.0'
     ss.vendored_frameworks = 'MRouterAdSDK/MRouter.framework'
  end
end
