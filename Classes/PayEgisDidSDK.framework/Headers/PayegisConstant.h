//
//  PayegisConstant.h
//  PayegisDID
//
//  Created by he.xu on 2017/8/8.
//  Copyright © 2017年 PG. All rights reserved.
//

/**
 上报账号设置
 */
typedef NS_ENUM(NSUInteger, PGSAccountType) {
    /**
     自有账号
     */
    PgsOwnAcc = 1,
    
    /**
     其他账号
     */
    PgsOthAcc = 2,
};

typedef NS_ENUM(NSInteger, PGSErrorCode) {
    /**
     无错误
     */
    PgsErrorNone = 0,
    
    /**
     DID服务未初始化
     */
    PgsErrorDIDDisable = -1,
    
    /**
     参数格式错误 
     */
    
    PgsErrorArgument = 1000,
    
    /**
     参数过长
     */
    PgsErrorLengthLimit = 1001,
    
    /**
     参数非法
     */
    PgsErrorLengthinvalidate = 1002,
};

/**
 DID服务状态
 */
typedef NS_ENUM(NSInteger, PGSState){
    /**
     未初始化或初始化失败
     */
    PgsStateNninitialized,
    
    /**
     正在初始化
     */
    PgsStateInitializing,
    
    /**
     初始化成功
     */
    PgSStateInitialized,
};

/**
上报策略
 */
typedef NS_ENUM(NSInteger, PGSUplodStrategy) {
    /**
     实时上报
     */
    PGSUplodStrategyRealTime = 1,
    
    /**
     批量上报，达到缓存临界值时触发发送
     */
    PGSUplodStrategyBatch = 2,
    
};

/**
事件类型
 */
typedef NS_ENUM(NSUInteger, PGSEventType) {
    /**
     普通事件
     */
    PgsEventNormal,
    
    /**
     计数事件
     */
    PGSEventCount,
    
    /**
     时长事件
     */
    PGSEventTime,
    
};

/**
 初始化场景
 */
typedef NS_ENUM(NSUInteger, PayEgisScence) {
    PayEgisScenceInit = 0,/*初始化*/
    PayEgisScenceRegister,/*注册*/
    PayEgisScenceLogin,/*登录*/
    PayEgisScenceModifyPwd,/*修改密码*/
    PayEgisScenceIndentify,/*接收验证码*/
    PayEgisScenceCertificate,/*实名认证*/
    PayEgisScenceTieCard,/*绑卡*/
    PayEgisScenceRecharge,/*充值*/
    PayEgisScenceCash,/*提现*/
    PayEgisScenceTransfer,/*转账*/
    PayEgisScenceOrder,/*下单*/
    PayEgisScencePay,/*支付*/
    PayEgisScenceAssess,/*评价*/
    PayEgisScenceActivate,/*激活*/
    PayEgisScencePost,/*发帖*/
    PayEgisScenceCallCar,/*叫车*/
    PayEgisScenceReceiveOrder,/*接单*/
    PayEgisScenceOthers/*其他*/
};
extern NSString *const PayegisSecurityContextAppId;
extern NSString *const PayegisSecurityContextAppKey;
extern NSString *const PayegisSecurityContextHostURL;
extern NSString *const PayegisSecurityContextSession;
extern NSString *const PayegisSecurityContextTag;
extern NSString *const PayegisSecurityContextSDKTypeKey;
extern NSString *const PayegisSecurityTypeKey;
#define enumToString(value)                 @#value

enum
{
    PayegisSecurityErrorCode_Network   = 100,         //网络错误
    PayegisSecurityErrorCode_Common    = 101,         //普通错误
    PayegisSecurityErrorCode_Tag       = 103,         //TAG输入非法
    PayegisSecurityErrorCode_DATATYPE  = 104          //数据格式错误
};

@interface PayegisConstant : NSObject
+(NSString*)version;


@end
