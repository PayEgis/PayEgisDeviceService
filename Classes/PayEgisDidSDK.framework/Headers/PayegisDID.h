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

typedef void (^PayegisSecurityInitCompletionBlock)(NSError *error);
typedef void (^PayegisSecurityUninitCompletionBlock)(NSError *error);


@interface PayegisDID : NSObject

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
+ (void)init:(NSDictionary *)context completionBlock:(PayegisSecurityInitCompletionBlock)completionBlock;
/**
 webview关联SDK
 @param context:SDK上下文，设置appid\appkey即可
 webview需要设置的wbview实例
 */
+ (void)setWebView:(NSDictionary *)context view:(UIView*)webview;

/**
 SDK去初始化
 不再需要使用SDK时调用
 */
+ (void)uninit:(PayegisSecurityUninitCompletionBlock)completionBlock;

+ (void)setIsBgTry:(BOOL)bgTry;
+ (BOOL)getBgTry;

@end
