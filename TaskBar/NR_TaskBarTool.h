
#pragma once

#include "../NieRLibConfig.h"
#include "NR_IDockableTaskBarInfo.h"

/**
** @brief ��ȡ�������������еľ�������
*/
NR_CAPI bool NR_GetTaskBarRectInDesktop(int & nPosX, int & nPosY, int & nWidth, int & nHeight);

/**
** @brief ��ȡ�������������еı�Եλ��
*/
NR_CAPI bool NR_GetTaskBarEdge(NR_IDockableTaskBarInfo::NR_TaskBarEdge & Edge);
