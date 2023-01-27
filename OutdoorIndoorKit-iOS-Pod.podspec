Pod::Spec.new do |s|
  s.name             = 'OutdoorIndoorKit-iOS-Pod'
s.version='1.2.0'
  s.summary          = 'The OutdoorIndoorKit-iOS-Pod for the Jibestream iOS SDK.'

  s.description      = 'This CocoaPod provides the release version of the OutdoorIndoorKit for the Jibestream iOS SDK.'

  s.homepage         = 'http://www.jibestream.com/'
  s.author           = { 'louieyuen' => 'lyuen@jibestream.com' }
  s.source           = { :git => 'https://github.com/Jibestream/OutdoorIndoor-iOS-Pod', :tag => "#{s.version}" }

  s.ios.deployment_target = '10.0'
  s.platform = :ios, '10.0'
  s.vendored_frameworks = 'OutdoorIndoorKit-iOS-Pod/Frameworks/*.xcframework'
end
