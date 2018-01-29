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


@interface PayegisDID : NSObject


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
 @param appId APPID
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
 获取SDK上下文
 */
+ (NSDictionary *)context;

/**
 SDK初始化
 @param context:SDK上下文，包括EGISSecurityContextHostURL，EGISSecurityContextLisenceKey，EGISSecurityContextPartnerCodeKey，EGISSecurityContextSDKTestMode
 @param completionBlock:初始化完成后的异步回调
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


#pragma mark - 配置选项


/**
 配置缓存策略
 @param strategy 策略枚举值
 */
+ (void)setUplodStrategy:(PGSUplodStrategy)strategy;
#pragma mark - 账号和用户相关

/**
 上报账号对应实时数据中的新增账号数字段
 @param account 账号名
 */
+ (void)setAccount:(NSString *)account;

#pragma mark - 统计页面时长

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

#pragma mark - NSDictionary为参数的自定义事件
/**
 上报自定义事件
 
 @param eventID 事件的id
 @param dictionary 事件的参数
 @return PGSErrorCode错误码
 */
+ (PGSErrorCode)trackEvent:(NSString *)eventID values:(NSDictionary *)dictionary;

/**
 开始统计自定义时长事件
 此接口需要跟trackEventEnd配对使用
 多次调用以第一次开始时间为准
 
 @param eventID 事件的ID
 @param dictionary 事件的参数
 @return PGSErrorCode错误码
 */
+ (PGSErrorCode)trackEventBegin:(NSString *)eventID values:(NSDictionary *)dictionary;

/**
 结束统计自定义时长事件
 此接口需要跟trackEventBegin配对使用
 多次调用以第一次结束时间为准
 
 @param eventID 事件的ID
 @param dictionary 事件的参数
 参数中的key和value必须跟开始统计时传入的参数一样才能正常配对
 @return PGSErrorCode错误码
 */
+ (PGSErrorCode)trackEventEnd:(NSString *)eventID values:(NSDictionary *)dictionary;

/**
 直接统计自定义时长事件
 这个方法用于上报统计好的时长事件
 
 @param seconds 自定义事件的时长，单位秒
 @param eventID 事件的ID
 @param dictionary 事件的参数
 @return PGSErrorCode错误码
 */
+ (PGSErrorCode)trackEventDuration:(float)seconds eventID:(NSString *)eventID values:(NSDictionary *)dictionary;

#pragma mark - 使用时长

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

@end
