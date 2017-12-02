
#pragma once

#include "../NieRLibConfig.h"

class NR_INetAdapterManager;

#if defined NIER_PLATFORM_WIN32

/**
** @brief ���� Win32 ����������������
** @return Win32 ����������������
*/
NIER_CAPI NR_INetAdapterManager * NR_MakeWin32NetAdapterManager(void);

#endif

/**
** @brief �Զ����ݵ���������ƽ̨����������������������
** @return ����������������
*/
NIER_CAPI NR_INetAdapterManager * NR_MakeNetAdapterManagerByOSPlatform(void);
