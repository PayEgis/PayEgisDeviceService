# PayEgisDeviceService
PayEgis设备指纹官方SDK
# 通付盾设备指纹iOS集成手册

><font color=#FF450 size=3 >v5.4.5</font>
>## <font color=#le90ff size=4 >概要介绍</font>
>- 通付盾提供的设备指纹是一种基于网籍库的设备凭证识别技术，通过快速获取上网设备的软件、硬件、网络等多层次指纹信息，经过一定的复杂规则算法，为每一台入网设备生成跨平台的唯一标识设备ID，该设备指纹识别服务简称为DeviceId服务。通付盾设备指纹 SDK 支持多种终端类型，包括：Web、Android、iOS等多种类型。
设备指纹服务接口包括：设备指纹采集接口和设备指纹查询接口。设备指纹的采集可通过WEB端JS集成、iOS SDK集成、Android SDK集成三种方式实现接口调用。具体集成方法可分别参考《通付盾设备指纹前端集成手册--Web》、《通付盾设备指纹前端集成手册--iOS》和《通付盾设备指纹前端集成手册--Android》。
>## <font color=#le90ff size=4 >服务架构</font>

```
graph LR;
  设备指纹采集--传入appid,sessionid获取用户设备信息-->通付盾云服务后台;
  设备指纹查询--传入appid,sessionid获取用户设备信息-->通付盾云服务后台;
  通付盾云服务后台-.返回设备信息.->设备指纹查询;
  通付盾云服务后台-.是否采集成功.->设备指纹采集;
```
>## <font color=#le90ff size=4 >交互流程</font>
1. 用户通过移动端App（已嵌入设备指纹采集接口）访问商户网站，通付盾设备指纹sdk采集用户设备信息；
注：步骤3中，sessionId为设备指纹生成所用的tokenID，后续客户可根据该tokenID查询当次对应设备指纹。tokenID由客户生成，使用sessionId或其他UUID均可。
2. 将采集到的移动设备参数传递给通付盾设备指纹云服务后台。
3. 通付盾设备指纹云服务后台通过算法生成设备唯一的设备号码（设备指纹）。
4. 商户网站向通付盾设备指纹云服务后台发起查询设备指纹的请求。
5. 通付盾设备指纹云服务后台返回设备指纹和设备信誉。

```
sequenceDiagram
　　　客户->>商户app:1.访问商户app
　　　商户app->>商户app:2.采集设备信息
　　　商户app->>通付盾云服务平台:3.传入appid+sessionid采集用户设备信息
　　　通付盾云服务平台->>通付盾云服务平台:4.生成Deviceid
　　　客户->>商户app:5.用户操作应用程序
　　　商户app->>商户服务器:6.提交业务请求
　　　商户服务器->>通付盾云服务平台:7.请求查询Deviceid
　　　通付盾云服务平台-->>商户服务器:8.返回设备指纹和设备信誉
　　　商户服务器->>商户服务器:9.商户后续业务逻辑
```

>## <font color=#le90ff size=4 >接入流程</font>
>- 试用申请，拨打 <font color=#le33ff size=2 >400-831-8116</font> 获取试用信息；通过商务沟通获取试用信息。
>- 开发包获取，由技术支持完成试用审核和需求确认后将AppId、AppKey 和设备指纹开发包发送给客户，开发包中包含引用源文件、Demo 程序和开发使用手册；试用账户信息直接发送至客户注册的企业邮箱。
>- 集成设计，客户在获取开发资料后，需要根据实际业务需求对嵌入设备指纹服务应用流程进行设计，在这之前可以与通付盾技术支持工程师联系，了解产品的集成方法和注意事项。
>- 系统接入，客户在业务系统中接入设备指纹服务。
>## <font color=#le90ff size=4 >集成方式</font>
>> <font color=#le90ff size=3 >自动集成</font>
>- 在 Podfile 文件中加入

```
pod 'PayEgisDeviceService'
```
>- 安装

```
pod install
```
>- 如果无法安装 SDK 最新版本，运行以下命令更新本地的 CocoaPods 仓库列表

```
pod repo update
```


>> <font color=#le90ff size=3 >手动集成</font>
>- 获取zip开发工具包，工具包中包含3部分内容 ：头文件和库文件，资源包
>

类型 | 文件名 | 描述
---|---|---
头文件 | PayegisDID.h| 包含PayegisDID类的定义
静态库 | libPayegisDID.a| 安全SDK库文件
头文件 | PayegisConstant.h| 常量文件
资源包 | PayeigsDID.bundle| 资源文件
>- 为工程文件添加依赖库
libsqlite3.0.tbd、libPayegisDID.a、WebKit.framework。
>- info.plist文件配置 添加 ==Location When In Use Usage Description== 和==Motion Usage Description== 的描述。
>> <font color=#le90ff size=3 >示例</font>

```
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    [PayegisDID initWithAppId:appid AppKey:appkey completionBlock:^(NSError *error) {
        if(!error){
            //初始化成功
        }
    }];
    return YES;
}
```
参数名 | 含义
---|---
---|---
appId | 通付盾分配给商户的唯一应用ID号
appKey | 通付盾分配给商户的Key值

```
- (void)viewDidLoad {
    [PayegisDID serviceWithSessionId:self.sessionStr Scence:PayEgisScencePay completionBlock:^(NSError *error) {
        if(!error){
            //后续业务逻辑
        }
    }];
  }
```
>- 参数说明

参数名 | 含义
---|---
sessionId | 关联Id，用户自行构造，尽可能唯一
scence | 描述埋点场景，枚举值
>- SDK 通过回调（callback）方式通知上层 API 调用结果
>所有调用错误都会以 NSError 的形式暴露。针对不同场景，我们将错误进行分类。

状态码 | 含义（从NSError中userinfo获取的错误信息）
---|---
104 | 服务端返回参数格式非法
103 | TAG输入非法
101 | SDK正在初始化
-1 | 签名校验不通过
-303 | app_type不对
-305 | 参数无法被解码
-306 | sessionId为空
其他负数 | NSURLErrorDomain中对应的网络错误


>## <font color=#le90ff size=4 >Webview设备指纹集成</font>
>- 如需在APP内以Webview形式集成设备指纹，需在webview loadRequest方法之前调用设备指纹SDK如下方法。示例代码如下:

``` 
NSDictionary *context=@{PayegisSecurityContextAppId:appid,PayegisSecurityContextAppKey:appkey};
[PayegisDID setWebView:context view:webView];

```
1. webview所引入的页面需添加设备指纹JS（详情可参见
<font color=#le90ff size=2 >《通付盾设备指纹前端集成手册-Web》</font>）
1. 该种集成方式使用webview内页面JS的sessionId查得设备指纹与iOS SDK方式所得一致。
1. 为提高安全性及数据时效性，建议每次webview loadRequest前均进行调用。

>## <font color=#le90ff size=4>网络监控/断线重发功能</font>
>- 设备指纹SDK默认具有防网络断线两次重发机制，首次-间隔10s-间隔20s，单次成功后停止重发。网络监控持续重发   本功能开启后会持续监控网络情况，监测网络正常时即会重启第1点操作(因需持续监控，考虑耗电量及内存占用，至多重复5次第一点操作仍失败后，停止监控)。调用方法（请在初始化设备指纹之前执行）。

```
[PayegisDID setIsBgTry:YES]; 
// 不调用该方法，或设置为NO为不启用监控功能
```
>## <font color=#le90ff size=4 >常见问题</font>
>- <font color=#FF4500 size=2 >ld: framework not found FileProvider for architecture arm64</font>

>出现这个问题是因为静态库是用Xcode9打包的。如果用xcode8编译的话就会出现这个问题，建议升级xcode最新版本，如果不升级方法如下：

>从Xcode9里把这个库拷贝出来。然后放到Xcode8上面

>/Applications/Xcode-beta.app/Contents/Developer/Platforms/iPhoneOS.platform/Developer/SDKs/iPhoneOS.sdk/System/Library/Frameworks/

>如果加进去了可能还会遇到 framework not found IOSurface for architecture armv7
>那么同样的方法把相关的库从Xcode9的frameworks 目录下找到相关库添加到Xcode8目录下面 





