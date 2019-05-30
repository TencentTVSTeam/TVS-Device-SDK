//
//  GTHistroyValue.h
//  GTKit
//
//  Created   on 13-11-22.
//  Copyright ©[Insert Year of First Publication] - 2014 Tencent.All Rights Reserved. This software is licensed under the terms in the LICENSE.TXT file that accompanies this software.
//

#ifndef GT_DEBUG_DISABLE
#import <Foundation/Foundation.h>
#import "GTMutableCString.h"

#define M_GT_HISTORY_ROW_HEADER         @",,,"
#define M_GT_HISTORY_ROW_HEADER_CSTR    ",,,"
#define M_GT_HISTORY_ROW_TAIL_CSTR      "\r\n"



@interface GTHistroyValue : NSObject
{
    NSTimeInterval _date;
}

@property (nonatomic, assign) NSTimeInterval date;

- (void)appendRowWithCString:(GTMutableCString *)cString;

//CSV每行的记录和自动保存到磁盘对应的行内容一致
- (NSString *)rowStr;

//保存CSV文件对应行标题和行内容
+ (NSString *)rowTitle;

@end

#endif