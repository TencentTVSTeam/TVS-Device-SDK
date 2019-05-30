//
//  GTCoreApi.h
//  GTKit
//
//  Created   on 13-2-28.
//  Copyright ©[Insert Year of First Publication] - 2014 Tencent.All Rights Reserved. This software is licensed under the terms in the LICENSE.TXT file that accompanies this software.
//

#ifdef __OBJC__
#import "GTCoreApiForOC.h"
#endif

#ifdef GT_DEBUG_DISABLE

//------------------------ DISABLE GT BEGIN ---------------------------

#define GT_UTIL_GET_CPU_USAGE
#define GT_UTIL_GET_USED_MEM
#define GT_UTIL_GET_FREE_MEM
#define GT_UTIL_GET_APP_MEM
#define GT_UTIL_RESET_NET_DATA

#define GT_UTIL_CAPTURE_START(fileName, para)
#define GT_UTIL_CAPTURE_STATUS
#define GT_UTIL_CAPTURE_STOP
#define GT_UTIL_CURRENT_CAPACITY


//------------------------ DISABLE GT END -----------------------------


#else


#import <sys/types.h>

typedef enum {
    GTCaptureStatusPreparing = 0,
	GTCaptureStatusError,
    GTCaptureStatusing
} GTCaptureStatus;

//------------------------ FOR C Language BEGIN ------------------------

/**
 * @brief   获取当前CPU值
 * @ingroup GT工具能力使用说明
 *
 * @return 返回CPU占用值(<1) 返回0.45表示CPU占用45%
 *
 * Example Usage:
 * @code
 *    GT_LOG_D("UTIL","cpuUsage:%f", GT_UTIL_GET_CPU_USAGE);
 * @endcode
 */
#define GT_UTIL_GET_CPU_USAGE func_cpuUsage()
extern double func_cpuUsage();

/**
 * @brief   获取当前memory占用情况
 * @ingroup GT工具能力使用说明
 *
 * @return 返回memory占用值，单位为Byte
 *
 * Example Usage:
 * @code
 *    GT_LOG_D("UTIL","usedMemory:%u", GT_UTIL_GET_USED_MEM);
 * @endcode
 */
#define GT_UTIL_GET_USED_MEM func_getUsedMemory()
extern int64_t func_getUsedMemory();

/**
 * @brief   获取当前App memory占用情况
 * @ingroup GT工具能力使用说明
 *
 * @return 返回App memory占用值，单位为Byte
 *
 * Example Usage:
 * @code
 *    GT_LOG_D("UTIL","AppUsedMemory:%u", GT_UTIL_GET_APP_MEM);
 * @endcode
 */
#define GT_UTIL_GET_APP_MEM func_getAppMemory()
extern int64_t func_getAppMemory();

/**
 * @brief   获取当前memory空闲情况
 * @ingroup GT工具能力使用说明
 *
 * @return 返回memory空闲值，单位为Byte
 *
 * Example Usage:
 * @code
 *    GT_LOG_D("UTIL","freeMemory:%u", GT_UTIL_GET_FREE_MEM);
 * @endcode
 */
#define GT_UTIL_GET_FREE_MEM func_getFreeMemory()
extern int64_t func_getFreeMemory();


/**
 * @brief   清除网络数据
 * @ingroup GT工具能力使用说明
 * @return
*
 * Example Usage:
 * @code
 *    GT_UTIL_RESET_NET_DATA;
 * @endcode
 */
#define GT_UTIL_RESET_NET_DATA func_resetNetData()
extern void func_resetNetData();


/**
 * @brief   启动抓包
 * @details 文件所在的目录对应为../Documents/GT/Plugin/pcap/,且一次仅支持一路抓包
 * @ingroup GT工具能力使用说明
 *
 * @param fileName [const char*] 抓包文件名
 * @param para [const char*] tcpdump抓包命令对应的参数
 * @return
 *
 * Example Usage:
 * @code
 *    GT_UTIL_CAPTURE_START("test1", "-s 00 -vv");
 * @endcode
 */
#define GT_UTIL_CAPTURE_START(fileName, para) func_captureStart(fileName, para)
extern void func_captureStart( const char* fileName, const char* para );


/**
 * @brief   获取抓包状态
 * @details 文件所在的目录对应为../Documents/GT/Plugin/pcap/
 * @ingroup GT工具能力使用说明
 *
 * @retval GTCaptureStatusPreparing 准备中
 * @retval GTCaptureStatusError 抓包出错
 * @retval GTCaptureStatusing 正在抓包中
 *
 * Example Usage:
 * @code
 *    GTCaptureStatus status = GT_UTIL_CAPTURE_STATUS;
 * @endcode
 */
#define GT_UTIL_CAPTURE_STATUS func_captureStatus()
extern int func_captureStatus();

/**
 * @brief   停止抓包
 * @details 文件所在的目录对应为../Documents/GT/Plugin/pcap/
 * @ingroup GT工具能力使用说明
 *
 * @return
 *
 * Example Usage:
 * @code
 *    GT_UTIL_CAPTURE_STOP;
 * @endcode
 */
#define GT_UTIL_CAPTURE_STOP func_captureStop()
extern void func_captureStop();

/**
 * @brief   获取当前电量信息
 * @ingroup GT工具能力使用说明
 *
 * @return 返回currentCapacity,单位mAh
 *
 * Example Usage:
 * @code
 *    int currentCapacity = GT_UTIL_CURRENT_CAPACITY;
 * @endcode
 */
#define GT_UTIL_CURRENT_CAPACITY func_currentCapacity()
extern int func_currentCapacity();


//------------------------ FOR C Language END ------------------------


#endif

