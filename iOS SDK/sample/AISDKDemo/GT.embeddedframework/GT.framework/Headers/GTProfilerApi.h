//
//  GTProfilerApi.h
//  GTKit
//
//  Created   on 13-6-17.
//  Copyright ©[Insert Year of First Publication] - 2014 Tencent.All Rights Reserved. This software is licensed under the terms in the LICENSE.TXT file that accompanies this software.
//

#ifdef __OBJC__
#import "GTProfilerApiForOC.h"
#endif

#ifdef GT_DEBUG_DISABLE

//------------------------ DISABLE GT BEGIN ---------------------------

#define GT_TIME_SWITCH_SET(on)

#define GT_TIME_START(key, ...)
#define GT_TIME_END(key, ...) 0
#define GT_TIME_GET(key,...) 0

#define GT_TIME_START_IN_THREAD(key, ...)
#define GT_TIME_END_IN_THREAD(key, ...) 0

//------------------------ DISABLE GT END ------------------------------

#else

#include <stdbool.h>

//------------------------ FOR C Language BEGIN ------------------------
/**
 * @brief   profile功能开关设置
 * @ingroup GTprofiler使用说明
 *
 * @param on [bool] 默认为false, false:关闭profile功能 true:打开profile功能
 * @return
 *
 * Example Usage:
 * @code
 *    //打开profile功能
 *    GT_TIME_SWITCH_SET(true);
 * @endcode
 */
#define GT_TIME_SWITCH_SET(on) func_setTimeSwitch(on)
extern void func_setTimeSwitch(bool on);

/**
 * @brief   开始时间统计
 * @ingroup GTprofiler使用说明
 *
 * @param group [const char *] 时间统计项的分组
 * @param ... [const char *] 时间统计项的描述信息key，支持多参数输入
 * @return
 *
 * Example Usage:
 * @code
 *    //时间统计的开始时刻调用
 *    GT_TIME_START("URL", "www.qq.com");
 * @endcode
 */
#define GT_TIME_START(group, ...) func_startRecTime(group, __VA_ARGS__)
extern void func_startRecTime(const char * logKey, const char * format,...);

/**
 * @brief   结束时间统计
 * @ingroup GTprofiler使用说明
 *
 * @param group [const char *] 时间统计项的分组
 * @param ... [const char *] 时间统计项的描述信息key，支持多参数输入
 * @return 返回从开始到结束的时间间隔，单位为秒
 *
 * Example Usage:
 * @code
 *    //时间统计的结束时刻调用, interval为从开始到结束的时间间隔，单位为秒
 *    double interval = GT_TIME_END("URL", "www.qq.com");
 * @endcode
 */
#define GT_TIME_END(group, ...) func_endRecTime(group, __VA_ARGS__)
extern double func_endRecTime(const char * logKey, const char * format,...);

/**
 * @brief   获取某时间统计项最新时间间隔值
 * @ingroup GTprofiler使用说明
 *
 * @param group [const char *] 时间统计项的分组
 * @param ... [const char *] 时间统计项的描述信息key，支持多参数输入
 * @return 返回从开始到结束的时间间隔，单位为秒
 *
 * Example Usage:
 * @code
 *    //interval为统计项里最新时间间隔值，单位为秒
 *    double interval = GT_TIME_GET("URL", "www.qq.com");
 * @endcode
 */
#define GT_TIME_GET(group, ...) func_getRecTime(group, __VA_ARGS__)
extern double func_getRecTime(const char * logKey, const char * format,...);

/**
 * @brief   开始时间统计(区分线程)
 * @ingroup GTprofiler使用说明
 *
 * @param group [const char *] 时间统计项的分组
 * @param ... [const char *] 时间统计项的描述信息key，支持多参数输入
 * @return
 *
 * Example Usage:
 * @code
 *    //时间统计的开始时刻调用
 *    GT_TIME_START_IN_THREAD("URL", "www.qq.com");
 * @endcode
 */
#define GT_TIME_START_IN_THREAD(group, ...) func_startRecTimeInThread(group, __VA_ARGS__)
extern void func_startRecTimeInThread(const char * logKey, const char * format,...);

/**
 * @brief   结束时间统计(区分线程)
 * @ingroup GTprofiler使用说明
 *
 * @param group [const char *] 时间统计项的分组
 * @param ... [const char *] 时间统计项的描述信息key，支持多参数输入
 * @return 返回从开始到结束的时间间隔，单位为秒
 *
 * Example Usage:
 * @code
 *    //时间统计的结束时刻调用, interval为从开始到结束的时间间隔，单位为秒
 *    double interval = GT_TIME_END_IN_THREAD("URL", "www.qq.com");
 * @endcode
 */
#define GT_TIME_END_IN_THREAD(group, ...) func_endRecTimeInThread(group, __VA_ARGS__)
extern double func_endRecTimeInThread(const char * logKey, const char * format,...);

//------------------------ FOR C Language END ------------------------


#endif


