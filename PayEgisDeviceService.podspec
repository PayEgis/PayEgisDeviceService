
Pod::Spec.new do |s|
  s.name         = "PayEgisDeviceService"
  s.version      = "5.6.5.2"
  s.summary      = "PayEgis设备指纹"
  s.description  = <<-DESC
  通过获取上网设备的软件、硬件、行为等多层次指纹信息生成全球唯一的设备ID，为每一个入网设备提供虚拟空间的“身份证”。
  精准分析设备用户的操作轨迹，对设备进行标识、评估欺诈风险。
                   DESC
  s.homepage     = "https://github.com/PayEgis/PayEgisDeviceService"
  s.license      = "MIT"
  s.author       = { "superrepublic" => "superrepublic@163.com" }
  s.platform     = :ios, '8.0'
  s.source       = { :git => "https://github.com/PayEgis/PayEgisDeviceService.git", :tag => "5.6.5.2"  }
  # s.source_files  = "Classes/*.framework"
  s.vendored_frameworks   = 'Classes/*.framework'
  s.resources = "resource/PayegisDID.bundle"
  s.ios.frameworks        = 'CoreLocation', 'CFNetwork', 'SystemConfiguration',  'CoreTelephony'
  s.requires_arc = true
end
