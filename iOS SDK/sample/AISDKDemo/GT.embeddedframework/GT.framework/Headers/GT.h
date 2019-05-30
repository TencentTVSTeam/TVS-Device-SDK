//
//  GT.h
//  GTKit
//
//  Created by  on 13-11-15.
//  Copyright ©[Insert Year of First Publication] - 2014 Tencent.All Rights Reserved. This software is licensed under the terms in the LICENSE.TXT file that accompanies this software.
//

#include <GT/GTInitApi.h>
#include <GT/GTParaOutApi.h>
#include <GT/GTParaInApi.h>
#include <GT/GTLogApi.h>
#include <GT/GTProfilerApi.h>
#include <GT/GTCoreApi.h>
#include <GT/GTStyleDef.h>

#ifdef __OBJC__
#import <GT/GTPluginApiForOC.h>
#import <GT/GTPluginViewController.h>
#endif


/**
 * @addtogroup GT启动使用说明
 * @addtogroup GT日志使用说明
 * @addtogroup GTprofiler使用说明
 * @addtogroup GT输入参数使用说明
 * @addtogroup GT输出参数使用说明
 * @addtogroup GT工具能力使用说明
 * @addtogroup GT插件使用说明
 */


/*------------------------------------------------------------------------------
 Introduction - ADD GT
 
 1. drag GT.embeddedframework to project.
 
 2. include GT.h in file which want to use GT Kit and init GT.
 a1. if .m or .c file, use as follow:
 #include <GT/GT.h>
 
 a2. if .mm or .cpp file, use as follow:
 extern "C"
 {
 #include <GT/GT.h>
 }
 
 b. init GT as follow:
 GT_DEBUG_INIT;
 
 ------------------------------------------------------------------------------*/