
#pragma once

#include "../NieRLibConfig.h"

class NR_IThreadManager;

#if defined NIER_PLATFORM_WIN32

/**
** @brief ���� Win32 �̹߳�����
** @return Win32 �̹߳�����
*/
NIER_CAPI NR_IThreadManager * NR_MakeWin32ThreadManager(void);

#endif

/**
** @brief �Զ����ݵ���������ƽ̨���������̹߳�����
** @return �̹߳�����
*/
NIER_CAPI NR_IThreadManager * NR_MakeThreadManagerByOSPlatform(void);
