//
//  GTProfilerApiForOC.h
//  GTKit
//
//  Created   on 13-10-12.
//  Copyright ©[Insert Year of First Publication] - 2014 Tencent.All Rights Reserved. This software is licensed under the terms in the LICENSE.TXT file that accompanies this software.
//

#ifdef GT_DEBUG_DISABLE

//------------------------ DISABLE GT BEGIN ----------------------------

#define GT_OC_TIME_START(group, ...)
#define GT_OC_TIME_END(group, ...) 0
#define GT_OC_TIME_GET(group, ...) 0

#define GT_OC_TIME_START_IN_THREAD(group, ...)
#define GT_OC_TIME_END_IN_THREAD(group, ...) 0

//------------------------ DISABLE GT END -------------------------------

#else


//------------------------ FOR OC Language BEGIN ------------------------

/**
 * @brief   开始时间统计(支持OC语法)
 * @ingroup GTprofiler使用说明
 *
 * @param group [NSString *] 时间统计项的分组
 * @param ... [NSString *] 时间统计项的描述信息key，支持多参数输入
 * @return
 *
 * Example Usage:
 * @code
 *    //时间统计的开始时刻调用
 *    GT_OC_TIME_START(@"URL", @"www.qq.com");
 * @endcode
 */
#define GT_OC_TIME_START(group, ...) func_startRecTimeForOC(group, __VA_ARGS__)
FOUNDATION_EXPORT void func_startRecTimeForOC(NSString * logKey, NSString * format,...);

/**
 * @brief   结束时间统计(支持OC语法)
 * @ingroup GTprofiler使用说明
 *
 * @param group [NSString *] 时间统计项的分组
 * @param ... [NSString *] 时间统计项的描述信息key，支持多参数输入
 * @return 返回从开始到结束的时间间隔，单位为秒
 *
 * Example Usage:
 * @code
 *    //时间统计的结束时刻调用, interval为从开始到结束的时间间隔，单位为秒
 *    NSTimeInterval interval = GT_OC_TIME_END(@"URL", @"www.qq.com");
 * @endcode
 */
#define GT_OC_TIME_END(group, ...) func_endRecTimeForOC(group, __VA_ARGS__)
FOUNDATION_EXPORT NSTimeInterval func_endRecTimeForOC(NSString * logKey, NSString * format,...);

/**
 * @brief   获取某时间统计项最新时间间隔值(支持OC语法)
 * @ingroup GTprofiler使用说明
 *
 * @param group [NSString *] 时间统计项的分组
 * @param ... [NSString *] 时间统计项的描述信息key，支持多参数输入
 * @return
 *
 * Example Usage:
 * @code
 *    //interval为统计项里最新时间间隔值，单位为秒
 *    NSTimeInterval interval = GT_OC_TIME_GET(@"URL", @"www.qq.com");
 * @endcode
 */
#define GT_OC_TIME_GET(group, ...) func_getRecTimeForOC(group, __VA_ARGS__)
FOUNDATION_EXPORT NSTimeInterval func_getRecTimeForOC(NSString* logKey, NSString* format,...);

/**
 * @brief   开始时间统计(区分线程)(支持OC语法)
 * @ingroup GTprofiler使用说明
 *
 * @param group [NSString *] 时间统计项的分组
 * @param ... [NSString *] 时间统计项的描述信息key，支持多参数输入
 * @return
 *
 * Example Usage:
 * @code
 *    //时间统计的开始时刻调用
 *    GT_OC_TIME_START_IN_THREAD(@"URL", @"www.qq.com");
 * @endcode
 */
#define GT_OC_TIME_START_IN_THREAD(group, ...) func_startRecTimeInThreadForOC(group, __VA_ARGS__)
FOUNDATION_EXPORT void func_startRecTimeInThreadForOC(NSString* logKey, NSString* format,...);

/**
 * @brief   结束时间统计(区分线程)(支持OC语法)
 * @ingroup GTprofiler使用说明
 *
 * @param group [NSString *] 时间统计项的分组
 * @param ... [NSString *] 时间统计项的描述信息key，支持多参数输入
 * @return 返回从开始到结束的时间间隔，单位为秒
 *
 * Example Usage:
 * @code
 *    //时间统计的结束时刻调用, interval为从开始到结束的时间间隔，单位为秒
 *    NSTimeInterval interval = GT_OC_TIME_END_IN_THREAD(@"URL", @"www.qq.com");
 * @endcode
 */
#define GT_OC_TIME_END_IN_THREAD(group, ...) func_endRecTimeInThreadForOC(group, __VA_ARGS__)
FOUNDATION_EXPORT NSTimeInterval func_endRecTimeInThreadForOC(NSString* logKey, NSString* format,...);

//------------------------ FOR OC Language END ------------------------



#endif
