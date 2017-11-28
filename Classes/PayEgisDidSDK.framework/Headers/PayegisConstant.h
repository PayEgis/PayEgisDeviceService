//
//  PayegisConstant.h
//  PayegisDID
//
//  Created by he.xu on 2017/8/8.
//  Copyright © 2017年 PG. All rights reserved.
//

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

enum
{
    INIT,
    REGISTER,
    LOGIN,
    MODIFY_PWD,
    IDENTIFY_CODE,
    CAERTIFICATE,
    TIE_CARD,
    RECHARGE,
    CASH,
    TRANSFER,
    ORDER,
    PAY,
    ASSESS,
    ACTIVATE,
    POST,
    CALL_CAR,
    RECEIVE_ORDER,
    OTHERS
};
@interface PayegisConstant : NSObject
+(NSString*)version;
@end
