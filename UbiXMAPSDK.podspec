
Pod::Spec.new do |s|
  s.name             = 'UbiXMAPSDK'
  s.version          = '2.0.7.1.0'
  s.summary          = 'UBiX聚合广告变现SDK AdProf Adapter'
  s.homepage         = 'https://www.ubixai.com/product/md'
  # s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'zhugq' => 'guoqiang.zhu@ubixai.com' }
  s.source           = { :git => 'https://github.com/ubixai/UbiXMAPSDK.git', :tag => s.version.to_s }
  s.ios.deployment_target = '12.0'

  s.static_framework = true
  s.pod_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64',
    'OTHER_LINK_FLAG' => '$(inherited) -ObjC' }

  s.vendored_frameworks = 'UbiXMAPSDK/UbiXMAPSDK.xcframework'
  

   

end
