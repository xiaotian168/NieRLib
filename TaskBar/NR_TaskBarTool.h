
#pragma once

#include "../NieRLibConfig.h"
#include "NR_ITaskBarInfo.h"

/**
** @brief 获取任务栏在桌面中的矩形区域
*/
NR_CAPI bool NR_GetTaskBarRectInDesktop(int & nPosX, int & nPosY, int & nWidth, int & nHeight);

/**
** @brief 获取任务栏在桌面中的边缘位置
*/
NR_CAPI bool NR_GetTaskBarEdge(NR_ITaskBarInfo::NR_TaskBarEdge & Edge);
