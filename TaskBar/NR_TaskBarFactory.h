
#pragma once

#include "../NieRLibConfig.h"

class NR_IDockableTaskBarInfo;

#if defined NR_PLATFORM_WIN32

/**
** @brief ���� Win32 ��������Ϣ�ӿ�
** @return Win32 ��������Ϣ�ӿ�
*/
NR_CAPI NR_IDockableTaskBarInfo * NR_MakeWin32TaskBarInfo(void);

#endif

/**
** @brief �Զ����ݵ���������ƽ̨��������������Ϣ�ӿ�
** @return ��������Ϣ�ӿ�
*/
NR_CAPI NR_IDockableTaskBarInfo * NR_MakeTaskBarInfoByOSPlatform(void);
