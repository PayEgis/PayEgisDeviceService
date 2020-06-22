//
//  PayegisDID.h
//  PayegisDID
//
//  Created by ivan on 16/4/22.
//  Copyright © 2016年 PG. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "WebKit/WebKit.h"
#import "PayegisConstant.h"

typedef void (^PayegisSecurityInitCompletionBlock)(NSError *error);
typedef void (^PayegisSecurityUninitCompletionBlock)(NSError *error);
typedef void (^PayegisSecurityMonitorBlock)(NSDictionary *error);

@interface PayegisDID : NSObject
@property(nonatomic, assign) BOOL makeFinished;
@property(nonatomic, assign) BOOL isForeground;

/**
 实例变量
 @return PayegisDID单例
 */
+(instancetype)sharedInstance;

/**
 SDK本地服务初始化方法
 @param appId APPID
 @param appKey APPKEY
 @param hostUrl 本地服务地址
 @param completionBlock 服务器响应的回调
 */
+(void)initWithAppId:(NSString *)appId AppKey:(NSString *)appKey HostUrl:(NSString *)hostUrl completionBlock:(PayegisSecurityInitCompletionBlock)completionBlock;

/**
 SDK云服务初始化方法
 @param appid APPID
 @param appKey APPKEY
 @param completionBlock 服务器响应的回调
 */
+(void)initWithAppId:(NSString *)appId AppKey:(NSString *)appKey completionBlock:(PayegisSecurityInitCompletionBlock)completionBlock;

/**
 SDK设备指纹业务埋点方法
 @param sessionId 关联ID，由用户构造
 @param scence 业务场景
 */
+(void)serviceWithSessionId:(NSString *)sessionId Scence:(PayEgisScence)scence completionBlock:(PayegisSecurityInitCompletionBlock)completionBlock;

/**
 设置SDK上下文环境
 */
+ (void)setContext:(NSDictionary *)context;

/**
 获取客户自定义参数
 */
+ (NSDictionary *)customContext;

/**
 设置客户自定义参数
 */
+ (void)setCustomContext:(NSDictionary *)context;

/**
 获取SDK上下文
 */
+ (NSDictionary *)context;


/**
 是否开启威胁感知
 
 需要在initWithAppId方法之前调用
 
 @param isOpen Yes 开启 No 关闭
 */
+(void) setOpenMonitor:(BOOL) isOpen securityMonitorBlock:(PayegisSecurityMonitorBlock)securityMonitorBlock;
//+(void) setSecurityMonitorBlock:(PayegisSecurityMonitorBlock)completionBlock;
-(PayegisSecurityMonitorBlock) getSecurityMonitorBlock;

/**
 SDK初始化
 @param context:SDK上下文，包括PayegisSecurityContextAppId，PayegisSecurityContextAppKey，PayegisSecurityContextHostURL，PayegisSecurityContextSession，PayegisSecurityContextTag
 completionBlock:初始化完成后的异步回调
 context为nil时，不改变原有的值
 */
+ (void)init:(NSDictionary *)context completionBlock:(PayegisSecurityInitCompletionBlock)completionBlock;
/**
 关联webview
 
 @param view weview
 */
+ (void)setWebView:(UIView*)view;

/**
 SDK去初始化
 不再需要使用SDK时调用
 */
+ (void)uninit:(PayegisSecurityUninitCompletionBlock)completionBlock;

+ (void)setIsBgTry:(BOOL)bgTry;
+ (BOOL)getBgTry;

+ (void)uploadsdkInfo:(NSDictionary *)dic;

@end
