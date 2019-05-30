//
//  GTParaDelegate.h
//  GTKit
//
//  Created   on 13-9-23.
//  Copyright ©[Insert Year of First Publication] - 2014 Tencent.All Rights Reserved. This software is licensed under the terms in the LICENSE.TXT file that accompanies this software.
//
#ifndef GT_DEBUG_DISABLE

#import <Foundation/Foundation.h>
#import "GTHistroyValue.h"

@protocol GTParaDelegate <NSObject>

- (void)switchEnable;
- (void)switchDisable;

@optional

- (GTHistroyValue *)objForHistory;
- (NSString *)descriptionForObj;
- (CGFloat)upperBound;
- (CGFloat)lowerBound;
- (NSString *)yDesc;

@end

#endif