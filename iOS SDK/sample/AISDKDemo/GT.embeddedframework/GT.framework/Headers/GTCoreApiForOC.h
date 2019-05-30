//
//  GTCoreApiForOC.h
//  GTKit
//
//  Created   on 13-10-12.
//  Copyright ©[Insert Year of First Publication] - 2014 Tencent.All Rights Reserved. This software is licensed under the terms in the LICENSE.TXT file that accompanies this software.
//

#ifdef GT_DEBUG_DISABLE

//------------------------ DISABLE GT BEGIN -----------------------------

#define GT_OC_UTIL_CAPTURE_START(fileName, para)
#define GT_OC_UTIL_CAPTURE_STATUS
#define GT_OC_UTIL_CAPTURE_STOP

//------------------------ DISABLE GT END -------------------------------

#else

//------------------------ FOR OC Language BEGIN ------------------------

/**
 * @brief   启动抓包(支持OC语法)
 * @details 文件所在的目录对应为../Documents/GT/Plugin/pcap/,且一次仅支持一路抓包
 * @ingroup GT工具能力使用说明
 *
 * @param fileName [NSStringr*] 抓包文件名
 * @param para [NSStringr*] tcpdump抓包命令对应的参数
 * @return
 *
 * Example Usage:
 * @code
 *    GT_UTIL_CAPTURE_START(@"test1", @"-s 00 -vv");
 * @endcode
 */

#define GT_OC_UTIL_CAPTURE_START(fileName, para) func_captureStartForOC(fileName, para)
FOUNDATION_EXPORT void func_captureStartForOC( NSString* fileName, NSString* para );

/**
 * @brief   获取抓包状态(支持OC语法)
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
#define GT_OC_UTIL_CAPTURE_STATUS GT_UTIL_CAPTURE_STATUS

/**
 * @brief   停止抓包(支持OC语法)
 * @details 文件所在的目录对应为../Documents/GT/Plugin/pcap/
 * @ingroup GT工具能力使用说明
 *
 * @return
 *
 * Example Usage:
 * @code
 *    GT_OC_UTIL_CAPTURE_STOP;
 * @endcode
 */
#define GT_OC_UTIL_CAPTURE_STOP GT_UTIL_CAPTURE_STOP

//------------------------ FOR OC Language END ------------------------

#endif
