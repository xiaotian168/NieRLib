
#pragma once

#include "../NieRLibConfig.h"

class IThreadManager;

/**
** @brief ���� Win32 �̹߳�����
** @return Win32 �̹߳�����
*/
NIER_CAPI IThreadManager * MakeWin32ThreadManager(void);

/**
** @brief �Զ����ݵ���������ƽ̨���������̹߳�����
** @return �̹߳�����
*/
NIER_CAPI IThreadManager * MakeThreadManagerByOSPlatform(void);
