
#pragma once

#include "../NieRLibConfig.h"

class IProcessManager;

/**
** @brief ���� Win32 ���̹�����
** @return Win32 ���̹�����
*/
NIER_CAPI IProcessManager * MakeWin32ProcessManager(void);

/**
** @brief �Զ����ݵ���������ƽ̨���������̹�����
** @return ���̹�����
*/
NIER_CAPI IProcessManager * MakeProcessManagerByOSPlatform(void);
