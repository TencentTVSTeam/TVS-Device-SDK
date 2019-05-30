//
//  GTLogApi.h
//  GTKit
//
//  Created   on 13-2-21.
//  Copyright ©[Insert Year of First Publication] - 2014 Tencent.All Rights Reserved. This software is licensed under the terms in the LICENSE.TXT file that accompanies this software.
//

#ifdef __OBJC__
#import "GTLogApiForOC.h"
#endif

#ifdef GT_DEBUG_DISABLE

//------------------------ DISABLE GT BEGIN ---------------------------

#define GT_LOG_I(tag,...)
#define GT_LOG_D(tag,...)
#define GT_LOG_W(tag,...)
#define GT_LOG_E(tag,...)

#define GT_LOG_CLEAN(...)
#define GT_LOG_START(...)
#define GT_LOG_END(...)

//------------------------ DISABLE GT END ------------------------------

#else
#include <stdbool.h>

//------------------------ FOR C Language BEGIN ------------------------
/**
 * @brief   DEBUG级别日志输出
 * @ingroup GT日志使用说明
 *
 * @param tag [const char *] 日志的分类
 * @param ... [const char *] 日志的信息，支持多参数输入
 * @return
 *
 * Example Usage:
 * @code
 *    //输出日志
 *    GT_LOG_D("tagFun", "%s %u", __FUNCTION__, __LINE__);
 * @endcode
 */
#define GT_LOG_D(tag,...) func_logDebug(tag,__VA_ARGS__)
extern void func_logDebug( const char * tag, const char* format, ... );

/**
 * @brief   INFO级别日志输出
 * @ingroup GT日志使用说明
 *
 * @param tag [const char *] 日志的分类
 * @param ... [const char *] 日志的信息，支持多参数输入
 * @return
 *
 * Example Usage:
 * @code
 *    //输出日志
 *    GT_LOG_I("tagFun", "%s %u", __FUNCTION__, __LINE__);
 * @endcode
 */
#define GT_LOG_I(tag,...) func_logInfo(tag,__VA_ARGS__)
extern void func_logInfo( const char * tag, const char* format, ... );

/**
 * @brief   WARNING级别日志输出
 * @ingroup GT日志使用说明
 *
 * @param tag [const char *] 日志的分类
 * @param ... [const char *] 日志的信息，支持多参数输入
 * @return
 *
 * Example Usage:
 * @code
 *    //输出日志
 *    GT_LOG_W("tagFun", "%s %u", __FUNCTION__, __LINE__);
 * @endcode
 */
#define GT_LOG_W(tag,...) func_logWarning(tag,__VA_ARGS__)
extern void func_logWarning( const char * tag, const char* format, ... );

/**
 * @brief   ERROR级别日志输出
 * @ingroup GT日志使用说明
 *
 * @param tag [const char *] 日志的分类
 * @param ... [const char *] 日志的信息，支持多参数输入
 * @return
 *
 * Example Usage:
 * @code
 *    //输出日志
 *    GT_LOG_E("tagFun", "%s %u", __FUNCTION__, __LINE__);
 * @endcode
 */
#define GT_LOG_E(tag,...) func_logError(tag,__VA_ARGS__)
extern void func_logError( const char * tag, const char* format, ... );

/**
 * @brief   清除日志
 * @details 文件所在的目录对应为../Documents/GT/Log/
 * @ingroup GT日志使用说明
 *
 * @param ... [const char *] 文件名，支持多参数输入
 * @return
 *
 * Example Usage:
 * @code
 *    //清除日志
 *    GT_LOG_CLEAN("file1");
 * @endcode
 */
#define GT_LOG_CLEAN(...) func_logClean(__VA_ARGS__)
extern void func_logClean(const char * format,...);

/**
 * @brief   开始记录日志
 * @details 文件所在的目录对应为../Documents/GT/Log/
 * @ingroup GT日志使用说明
 *
 * @param ... [const char *] 文件名，支持多参数输入
 * @return
 *
 * Example Usage:
 * @code
 *    //开始记录日志
 *    GT_LOG_START("file1");
 * @endcode
 */
#define GT_LOG_START(...) func_logStart(__VA_ARGS__)
extern void func_logStart(const char * format,...);

/**
 * @brief   停止记录日志
 * @details 文件所在的目录对应为../Documents/GT/Log/
 * @ingroup GT日志使用说明
 *
 * @param ... [const char *] 文件名，支持多参数输入
 * @return
 *
 * Example Usage:
 * @code
 *    //开始记录日志
 *    GT_LOG_END("file1");
 * @endcode
 */
#define GT_LOG_END(...)   func_logEnd(__VA_ARGS__)
extern void func_logEnd(const char * format,...);

//------------------------ FOR C Language END ------------------------


#endif

