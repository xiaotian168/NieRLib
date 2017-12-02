
#pragma once

#include "../NieRLibConfig.h"

class NR_ILock;

#if defined NIER_PLATFORM_WIN32

/**
** @brief ������ Win32 ������
** @return �� Win32 ������
*/
NIER_CAPI NR_ILock * NR_MakeSimpleWin32Lock(void);

#endif

/**
** @brief �Զ����ݵ���������ƽ̨������������
** @return ������
*/
NIER_CAPI NR_ILock * NR_MakeLockByOSPlatform(void);
