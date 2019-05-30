//
//  GTPluginViewController.h
//  GTKit
//
//  Created   on 13-7-9.
//  Copyright ©[Insert Year of First Publication] - 2014 Tencent.All Rights Reserved. This software is licensed under the terms in the LICENSE.TXT file that accompanies this software.
//

#ifndef GT_DEBUG_DISABLE
#import "GTUIViewController.h"

#define M_GT_PLUGIN_SCREEN_WIDTH ([[UIScreen mainScreen] applicationFrame].size.width)
#define M_GT_PLUGIN_SCREEN_HEIGHT ([[UIScreen mainScreen] applicationFrame].size.height)
#define M_GT_PLUGIN_HEADER_HEIGHT 44
#define M_GT_PLUGIN_BOARD_HEIGHT (M_GT_SCREEN_HEIGHT - M_GT_HEADER_HEIGHT)

#define M_GT_PLUGIN_BOARD_FRAME CGRectMake(0, M_GT_HEADER_HEIGHT, M_GT_SCREEN_WIDTH, M_GT_BOARD_HEIGHT)

@interface GTPluginViewController : GTUIViewController

@end

#endif
