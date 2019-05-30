//
//  GTPluginApiForOC.h
//  GTKit
//
//  Created   on 13-1-27.
//  Copyright ©[Insert Year of First Publication] - 2014 Tencent.All Rights Reserved. This software is licensed under the terms in the LICENSE.TXT file that accompanies this software.
//


#ifdef GT_DEBUG_DISABLE

#define GT_PLUGIN_REGISTER(obj)

#else
#import <Foundation/Foundation.h>
#import "GTPlugin.h"

/**
 * @brief   注册插件
 * @ingroup GT插件使用说明
 *
 * @param obj [GTPlugin *] 对象要求继承GTPlugin且要实现GTPluginDelegate里描述的插件信息
 * @return
 *
 * Example Usage:
 * @code
 *    //GTSandbox 继承GTPlugin且实现GTPluginDelegate里描述的插件信息
 *    GTSandbox *sandbox = [[[GTSandbox alloc] init] autorelease];
 *    GT_PLUGIN_REGISTER(sandbox);
 * @endcode
 */
#define GT_PLUGIN_REGISTER(obj) func_addPlugin(obj)
FOUNDATION_EXPORT void func_addPlugin(GTPlugin* obj);


#endif
