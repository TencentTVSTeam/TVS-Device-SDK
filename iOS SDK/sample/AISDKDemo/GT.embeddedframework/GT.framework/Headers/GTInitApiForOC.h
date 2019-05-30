//
//  GTInitApiForOC.h
//  GTKit
//
//  Created   on 13-10-12.
//  Copyright ©[Insert Year of First Publication] - 2014 Tencent.All Rights Reserved. This software is licensed under the terms in the LICENSE.TXT file that accompanies this software.
//

#ifdef GT_DEBUG_DISABLE

//------------------------ DISABLE GT BEGIN ---------------------------

#ifdef __OBJC__
#define GT_DEBUG_SET_AUTOROTATE(autorotate)
#define GT_DEBUG_SET_SUPPORT_ORIENTATIONS(interfaceOrientation)
#endif

//------------------------ DISABLE GT END -------------------------------

#else

//------------------------ FOR OC Language BEGIN ------------------------

/**
 * @brief   设置logo是否旋转，在iOS6上使用
 * @ingroup GT启动使用说明
 *
 * @param autorotate [BOOL] 默认为true true:可旋转 false:不可旋转
 * @return
 *
 * Example Usage:
 * @code
 *    //设置logo是否旋转(iOS6使用)
 *    GT_DEBUG_SET_AUTOROTATE(false);
 * @endcode
 */
#define GT_DEBUG_SET_AUTOROTATE(autorotate) func_setGTAutorotate(autorotate)
FOUNDATION_EXPORT void func_setGTAutorotate(BOOL autorotate);

/**
 * @brief   设置logo支持的方向
 * @ingroup GT启动使用说明
 *
 * @param interfaceOrientation [NSUInteger] logo支持的方向，默认为UIInterfaceOrientationMaskAll
 * @return
 *
 * Example Usage:
 * @code
 *    //设置logo仅支持竖屏
 *    GT_DEBUG_SET_SUPPORT_ORIENTATIONS(UIInterfaceOrientationMaskPortrait);
 * @endcode
 */
#define GT_DEBUG_SET_SUPPORT_ORIENTATIONS(interfaceOrientation) func_setGTSupportedOrientations(interfaceOrientation)
FOUNDATION_EXPORT void func_setGTSupportedOrientations(NSUInteger interfaceOrientation);

//------------------------ FOR OC Language END ------------------------

#endif
