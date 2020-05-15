//
//  PayegisCrashHandler.h
//  PayegisDID
//
//  Created by superpein on 2018/4/17.
//  Copyright © 2018年 PG. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIDevice.h>

@interface PayegisCrashHandler : NSObject
+ (void)InstallPGSUncaughtExceptionHandler;
@end
