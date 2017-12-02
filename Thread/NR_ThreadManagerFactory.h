
#pragma once

#include "../NieRLibConfig.h"

class NR_IThreadManager;

#if defined NR_PLATFORM_WIN32

/**
** @brief ���� Win32 �̹߳�����
** @return Win32 �̹߳�����
*/
NR_CAPI NR_IThreadManager * NR_MakeWin32ThreadManager(void);

#endif

/**
** @brief �Զ����ݵ���������ƽ̨���������̹߳�����
** @return �̹߳�����
*/
NR_CAPI NR_IThreadManager * NR_MakeThreadManagerByOSPlatform(void);
