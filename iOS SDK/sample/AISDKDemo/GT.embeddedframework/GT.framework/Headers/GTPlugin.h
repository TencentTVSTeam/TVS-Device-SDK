//
//  GTPlugin.h
//  GTKit
//
//  Created   on 13-1-23.
//  Copyright ©[Insert Year of First Publication] - 2014 Tencent.All Rights Reserved. This software is licensed under the terms in the LICENSE.TXT file that accompanies this software.
//
#ifndef GT_DEBUG_DISABLE
#import <Foundation/Foundation.h>

@protocol GTPluginDelegate <NSObject>

@required

- (UIImage *)pluginIcon;
- (NSString *)pluginName;
- (NSString *)pluginInfo;
- (UIViewController *)pluginView;

@end

@interface GTPlugin : NSObject <GTPluginDelegate>
{
    
}

@end

#endif