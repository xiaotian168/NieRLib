
#pragma once

#include "../NieRLibConfig.h"

class NR_IProcessManager;

#if defined NR_PLATFORM_WIN32

/**
** @brief ���� Win32 ���̹�����
** @return Win32 ���̹�����
*/
NR_CAPI NR_IProcessManager * MakeWin32ProcessManager(void);

#endif

/**
** @brief �Զ����ݵ���������ƽ̨���������̹�����
** @return ���̹�����
*/
NR_CAPI NR_IProcessManager * MakeProcessManagerByOSPlatform(void);
