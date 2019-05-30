//
//  GTStyleDef.h
//  GTKit
//
//  Created   on 13-8-13.
//  Copyright ©[Insert Year of First Publication] - 2014 Tencent.All Rights Reserved. This software is licensed under the terms in the LICENSE.TXT file that accompanies this software.
//


/************************GT样式相关*************************/

#define M_GT_COLOR_WITH_HEX(hex)\
[UIColor colorWithRed:((float)((hex & 0xFF0000) >> 16))/255.0 \
green:((float)((hex & 0xFF00) >> 8))/255.0 \
blue:((float)(hex & 0xFF))/255.0 alpha:1.0]

#define M_GT_BKGD_COLOR [[UIColor blackColor] colorWithAlphaComponent:0.75]

#define M_GT_PLOTS_LINE_COLOR M_GT_COLOR_WITH_HEX(0x26C8D5)
#define M_GT_PLOTS_LINE1_COLOR M_GT_COLOR_WITH_HEX(0xE0A025)
#define M_GT_PLOTS_LINE2_COLOR M_GT_COLOR_WITH_HEX(0xD74882)

#define M_GT_PLOTS_AXIS_TEXT_COLOR M_GT_COLOR_WITH_HEX(0x878C98)
#define M_GT_PLOTS_AXIS_COLOR M_GT_COLOR_WITH_HEX(0x878C98)
#define M_GT_PLOTS_AXIS_SHADOW_COLOR [M_GT_COLOR_WITH_HEX(0x212222) colorWithAlphaComponent:0.75]
#define M_GT_PLOTS_AXIS_AVG_COLOR M_GT_COLOR_WITH_HEX(0x38AD29)

#define M_GT_LABEL_COLOR M_GT_COLOR_WITH_HEX(0x878C98)
#define M_GT_LABEL_VALUE_COLOR M_GT_COLOR_WITH_HEX(0x38AD29)
#define M_GT_LABEL_RED_COLOR M_GT_COLOR_WITH_HEX(0xEC3A3B)

#define M_GT_WARNING_COLOR M_GT_COLOR_WITH_HEX(0xDD843F)

#define M_GT_CELL_BKGD_COLOR M_GT_COLOR_WITH_HEX(0x29292D)
#define M_GT_CELL_BORDER_COLOR M_GT_COLOR_WITH_HEX(0x3C3C42)
#define M_GT_CELL_BORDER_WIDTH 1.0f
#define M_GT_CELL_TEXT_COLOR M_GT_COLOR_WITH_HEX(0xB7BDCF)
#define M_GT_CELL_TEXT_DISABLE_COLOR M_GT_COLOR_WITH_HEX(0x666666)

#define M_GT_SELECTED_COLOR M_GT_COLOR_WITH_HEX(0x3C4A76)

#define M_GT_NAV_BAR_COLOR M_GT_COLOR_WITH_HEX(0x3C3C42)
#define M_GT_NAV_BARLINE_COLOR M_GT_COLOR_WITH_HEX(0x1f1f22)

#define M_GT_BTN_HEIGHT     35.0f
#define M_GT_BTN_WIDTH      54.0f
#define M_GT_BTN_FONTSIZE   14.0f

#define M_GT_BTN_BKGD_COLOR M_GT_COLOR_WITH_HEX(0x35353B)
#define M_GT_BTN_BORDER_COLOR M_GT_COLOR_WITH_HEX(0x1C1C21)
#define M_GT_BTN_BORDER_WIDTH 1.0f

#define M_GT_TXT_FIELD_COLOR M_GT_COLOR_WITH_HEX(0x181818)
/***********************************************************/
