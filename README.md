# PayEgisDeviceService
PayEgis设备指纹官方SDK


<font color=#FF450 size=3 >v5.4.9</font>
## <font color=#le90ff size=4 >概要介绍</font>
通付盾提供的设备指纹是一种基于网籍库的设备凭证识别技术，通过快速获取上网设备的软件、硬件、网络等多层次指纹信息，经过一定的复杂规则算法，为每一台入网设备生成跨平台的唯一标识设备ID，该设备指纹识别服务简称为DeviceId服务。通付盾设备指纹 SDK 支持多种终端类型，包括：Web、Android、iOS等多种类型。
设备指纹服务接口包括：设备指纹采集接口和设备指纹查询接口。设备指纹的采集可通过WEB端JS集成、iOS SDK集成、Android SDK集成三种方式实现接口调用。具体集成方法可分别参考《通付盾设备指纹前端集成手册--Web》、《通付盾设备指纹前端集成手册--iOS》和《通付盾设备指纹前端集成手册--Android》。
## <font color=#le90ff size=4 >交互流程</font>
1. 用户通过移动端App（已嵌入设备指纹采集接口）访问商户网站，通付盾设备指纹sdk采集用户设备信息；
注：步骤3中，sessionId为设备指纹生成所用的tokenID，后续客户可根据该tokenID查询当次对应设备指纹。tokenID由客户生成，使用sessionId或其他UUID均可。
2. 将采集到的移动设备参数传递给通付盾设备指纹云服务后台。
3. 通付盾设备指纹云服务后台通过算法生成设备唯一的设备号码（设备指纹）。
4. 商户网站向通付盾设备指纹云服务后台发起查询设备指纹的请求。
5. 通付盾设备指纹云服务后台返回设备指纹和设备信誉。

## <font color=#le90ff size=4 >集成方式</font>
在 Podfile 文件中加入

```Ruby
pod 'PayEgisDeviceService'
```
安装

```Ruby
pod install
```
如果无法安装 SDK 最新版本，运行以下命令更新本地的 CocoaPods 仓库列表

```Ruby
pod repo update
```
<font color=#le90ff size=3 >示例</font>

```Objective-C
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

```Objective-C
- (void)viewDidLoad {
    [PayegisDID serviceWithSessionId:self.sessionStr Scence:PayEgisScencePay completionBlock:^(NSError *error) {
        if(!error){
            //后续业务逻辑
        }
    }];
  }
```
参数说明

参数名 | 含义
---|---
sessionId | 关联Id，用户自行构造，尽可能唯一
scence | 描述埋点场景，枚举值

>SDK 通过回调（callback）方式通知上层 API 调用结果
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


## <font color=#le90ff size=4 >Webview设备指纹集成</font>
如需在APP内以Webview形式集成设备指纹，需在webview loadRequest方法之前调用设备指纹SDK如下方法。示例代码如下:

``` Objective-C
NSDictionary *context=@{PayegisSecurityContextAppId:appid,PayegisSecurityContextAppKey:appkey};
[PayegisDID setWebView:context view:webView];

```
1. webview所引入的页面需添加设备指纹JS（详情可参见
<font color=#le90ff size=2 >《通付盾设备指纹前端集成手册-Web》</font>）
1. 该种集成方式使用webview内页面JS的sessionId查得设备指纹与iOS SDK方式所得一致。
1. 为提高安全性及数据时效性，建议每次webview loadRequest前均进行调用。

## <font color=#le90ff size=4>网络监控/断线重发功能</font>
设备指纹SDK默认具有防网络断线两次重发机制，首次-间隔10s-间隔20s，单次成功后停止重发。网络监控持续重发   本功能开启后会持续监控网络情况，监测网络正常时即会重启第1点操作(因需持续监控，考虑耗电量及内存占用，至多重复5次第一点操作仍失败后，停止监控)。调用方法（请在初始化设备指纹之前执行）。

```Objective-C
[PayegisDID setIsBgTry:YES]; 
// 不调用该方法，或设置为NO为不启用监控功能
```
## <font color=#le90ff size=4 >常见问题</font>
<font color=#FF4500 size=2 >ld: framework not found FileProvider for architecture arm64</font>

出现这个问题是因为静态库是用Xcode9打包的。如果用xcode8编译的话就会出现这个问题，建议升级xcode最新版本，如果不升级方法如下：

从Xcode9里把这个库拷贝出来。然后放到Xcode8上面

/Applications/Xcode-beta.app/Contents/Developer/Platforms/iPhoneOS.platform/Developer/SDKs/iPhoneOS.sdk/System/Library/Frameworks/

如果加进去了可能还会遇到 framework not found IOSurface for architecture armv7
那么同样的方法把相关的库从Xcode9的frameworks 目录下找到相关库添加到Xcode8目录下面 

#
# 事件上报<span id= "jump137">


**1.开启事件上报**
* 事件上报类的初始化，在设备指纹初始化之后调用

```
/**
开启事件上报
*/
+ (void)trackStart;

```
* 示例

```Objective-C

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    [PayegisEventCenter trackStart];
    return YES;
}
```
**2.配置缓存策略**
* 在开启事件上报之后调用

```
/**
配置缓存策略
@param strategy 策略枚举值
*/
+ (void)setUplodStrategy:(PGSUplodStrategy)strategy;
```
参数 | 含义
------------- | -------------
PGSUplodStrategyRealTime | 实时上报
PGSUplodStrategyBatch | 批量上报，达到缓存临界值时触发发送

* 示例

```Objective-C
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
...
    [PayegisEventCenter trackStart];
    [PayegisEventCenter setUplodStrategy:PGSUplodStrategyBatch];
    [PayegisEventCenter sharedInstance].batchEventCount = 3;
    return YES;
}
```
**3.账号相关**

* 开启事件上报之后可以配置上报账号相关信息

```
/**
上报账号对应实时数据中的新增账号数字段
@param account 账号名
@param type 账号类型
*/
+ (void)setAccount:(NSString *)account type:(PGSAccountType)type;
```
参数 | 含义
------------- | -------------
PgsOwnAcc | 自有账号
PgsOthAcc | 其他账号（第三方登录生成）
* 示例

```Objective-C
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
...
    [PayegisEventCenter trackStart];
    [PayegisEventCenter setAccount:@"246531" type:PgsOwnAcc];
    return YES;
}
```
**4.统计页面时长**
* 统计页面的使用时间

```
/**
标记一次页面访问的开始
此接口需要跟trackVCEnd配对使用
多次开始以第一次开始的时间为准
@param name 页面名
*/
+ (void)trackVCBegin:(NSString *)name;
/**
标记一次页面访问的结束
此接口需要跟trackVCBegin配对使用
多次结束以第一次结束的时间为准
@param name 页面名字
*/
+ (void)trackVCEnd:(NSString *)name;
```
* 示例

```Objective-C
-(void)viewWillAppear:(BOOL)animated{
    [PayegisEventCenter trackVCBegin:pageName];
}

-(void)viewDidDisappear:(BOOL)animated{
    [PayegisEventCenter trackVCEnd:pageName];
}
```

**5.APP使用时长**
* 统计app在前台的时间

```
/**
开始统计使用时长
建议在App进入前台时调用
*/
+ (void)trackAppBegin;

/**
结束统计使用时长
建议在App离开前台时调用
*/
+ (void)trackAppEnd;
```
* 示例

```Objective-C
- (void)applicationWillResignActive:(UIApplication *)application {
    [PayegisEventCenter trackAppEnd];
}
- (void)applicationDidBecomeActive:(UIApplication *)application {
    [PayegisEventCenter trackAppBegin];
}
```

## 内容过滤<span id= "jump138">

* 过滤敏感，色情内容

```Objective-C
/**
文本过滤

@param text 审核的文本
@param filterEnd 是否成功的回调
*/
+ (void)textFilter:(NSString *)text filter:(filterEnd)filterEnd;
```
* 示例

```Objective-C
[PayegisEventCenter textFilter:self.textView.text filter:^(BOOL isPass) {
    if (isPass) {
      //过滤通过
    }
    else{
    }
}];
```



