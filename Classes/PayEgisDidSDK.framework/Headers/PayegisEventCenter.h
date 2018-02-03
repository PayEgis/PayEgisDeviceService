//
//  PayegisEventCenter.h
//  PayegisDID
//
//  Created by superpein on 2018/1/23.
//  Copyright © 2018年 PG. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PayegisConstant.h"

typedef void (^filterEnd)(BOOL isPass);

@interface PayegisEventCenter : NSObject

/**
 文本过滤回调
 */
@property (nonatomic,copy) filterEnd filterEnd;

/**
 事件记录条目
 */
@property (nonatomic,assign) NSInteger eventCount;

/**
 缓存策略为Batch时 触发上报的临界值
 */
@property (nonatomic,assign) NSInteger batchEventCount;

/**
 开启事件上报
 */
+ (void)trackStart;


/**
 事件上报单例

 @return 事件上报单例
 */
+(instancetype)sharedInstance;

#pragma mark - 配置选项


/**
 配置缓存策略
 @param strategy 策略枚举值
 */
+ (void)setUplodStrategy:(PGSUplodStrategy)strategy;


/**
 设置上报临界值

 @param count 触发上报的最小缓存事件数量
 */
+ (void)setBatchEventCount:(NSInteger)count;

#pragma mark - 账号和用户相关

/**
 上报账号对应实时数据中的新增账号数字段
 @param account 账号名
 @param type 账号类型
 */
+ (void)setAccount:(NSString *)account type:(PGSAccountType)type;

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
 
 @param msec 自定义事件的时长
 @param eventID 事件的ID
 @param dictionary 事件的参数
 @return PGSErrorCode错误码
 */
+ (PGSErrorCode)trackEventDuration:(NSInteger)msec eventID:(NSString *)eventID values:(NSDictionary *)dictionary;

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

#pragma mark - 内容过滤



/**
 文本过滤

 @param text 审核的文本
 @param filterEnd 是否成功的回调
 */
+ (void)textFilter:(NSString *)text filter:(filterEnd)filterEnd;

@end
