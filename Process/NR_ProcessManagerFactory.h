
#pragma once

#include "../NieRLibConfig.h"

class NR_IProcessManager;

#if defined NIER_PLATFORM_WIN32

/**
** @brief ���� Win32 ���̹�����
** @return Win32 ���̹�����
*/
NIER_CAPI NR_IProcessManager * MakeWin32ProcessManager(void);

#endif

/**
** @brief �Զ����ݵ���������ƽ̨���������̹�����
** @return ���̹�����
*/
NIER_CAPI NR_IProcessManager * MakeProcessManagerByOSPlatform(void);
