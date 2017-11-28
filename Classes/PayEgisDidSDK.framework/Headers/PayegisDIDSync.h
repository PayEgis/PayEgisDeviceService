//
//  PayegisDID.h
//  PayegisDID
//
//  Created by ivan on 16/4/22.
//  Copyright © 2016年 PG. All rights reserved.
//

#import <Foundation/Foundation.h>


typedef void (^PayegisSecurityInitCompletionBlockSync)(NSError *error);
typedef void (^PayegisSecurityUninitCompletionBlockSync)(NSError *error);




@interface PayegisDIDSync : NSObject
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
 completionBlock:初始化完成后的异步回调
 contenxt为nil时，不改变原有的值
 */
+ (void)init:(NSDictionary *)context completionBlock:(PayegisSecurityInitCompletionBlockSync)completionBlock;

/**
 SDK去初始化
 不再需要使用SDK时调用
 */
+ (void)uninit:(PayegisSecurityUninitCompletionBlockSync)completionBlock;
/**
 获取deviceid
 */
+ (NSString *)deviceId;
/**
 获取信誉分值
 */
+ (NSString *)repScore;
@end
