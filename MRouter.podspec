Pod::Spec.new do |spec|
  spec.name         = "MRouterAd"
  spec.version      = "1.0.0"
  spec.summary      = "A short description of MRouterAd SDK for iOS."
  spec.description  = <<-DESC
            MRouterAd SDK 
                   DESC
  spec.homepage     = "https://github.com/tradplus/pod_mrouter_sdk"
  spec.license      = "MIT"
  spec.author       = { "tradplus" => "service@tradplus.com" }
  spec.source       = { :git => "https://github.com/tradplus/pod_mrouter_sdk.git", :tag => spec.version }
  spec.platform     = :ios, '9.0'
  spec.ios.deployment_target = '9.0'
  spec.requires_arc = true
  spec.frameworks = 'SystemConfiguration', 'CoreGraphics','Foundation','UIKit'
  spec.user_target_xcconfig =   {'OTHER_LDFLAGS' => ['-lObjC']}
  valid_archs = [ 'armv7', 'arm64']
  spec.vendored_frameworks = 'MRouterAdSDK/MRouter.framework'
end
