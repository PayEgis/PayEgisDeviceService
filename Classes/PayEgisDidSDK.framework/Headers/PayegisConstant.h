//
//  PayegisConstant.h
//  PayegisDID
//
//  Created by he.xu on 2017/8/8.
//  Copyright © 2017年 PG. All rights reserved.
//

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
    PayEgisScenceOthers/**/
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
