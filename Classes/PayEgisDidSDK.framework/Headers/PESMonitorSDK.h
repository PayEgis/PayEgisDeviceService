//
//  PESMonitorSDK.h
//  PESMonitorSDK
//
//  Created by PAYEGIS DEV on 2017/5/13.
//  Copyright © PAYEGIS. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PayegisDID.h"

typedef void (^PESMonitorRiskCompletionBlock)(NSError *error);

@interface PESMonitorSDK : NSObject


/**
 单例

 @return PESMonitorSDK 对象
 */
+ (PESMonitorSDK*)sharedInstance;


/**
 开启威胁感知

 @param completionBlock 回调
 */
+ (void)registerWithCompletionBlock:(PESMonitorRiskCompletionBlock)completionBlock;


/**
 获取相关信息

 @return
 */
+ (NSString*)getDesc;



/**
 攻击监测接口

 @param dic 参数
 */
- (void)attactInfoRequest:(NSDictionary *)dic;


/**
 运行状态接口

 @param dic 参数
 */
- (void)runStateInfoRequest:(NSDictionary *)dic;

/**
 回调方法
 
 @param securityMonitorBlock 参数
 */
//- (void)setSecurityMonitorBlock:(PayegisSecurityMonitorBlock *)securityMonitorBlock;
+ (void)setSecurityMonitorBlock:(PayegisSecurityMonitorBlock *)securityMonitorBlock;
//setSecurityMonitorBlock
@end
