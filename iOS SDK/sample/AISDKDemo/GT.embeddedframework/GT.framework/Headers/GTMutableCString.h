//
//  GTMutableCString.h
//  GTKit
//
//  Created   on 13-12-16.
//  Copyright ©[Insert Year of First Publication] - 2014 Tencent.All Rights Reserved. This software is licensed under the terms in the LICENSE.TXT file that accompanies this software.
//
#ifndef GT_DEBUG_DISABLE

#import <Foundation/Foundation.h>

@interface GTMutableCString : NSObject
{
    NSUInteger   _allocedLen;   //分配空间的大小
    char        *_bytes;        //分配的内存空间
    NSUInteger   _bytesLen;     //使用的空间大小
}

@property (nonatomic, assign) char *bytes;
@property (nonatomic, assign) NSUInteger bytesLen;
@property (nonatomic, assign) NSUInteger allocedLen;

- (void)appendCString:(const char *)bytes length:(NSUInteger)length;
- (void)appendCStringWithTimeEx:(NSTimeInterval)time;

@end
#endif