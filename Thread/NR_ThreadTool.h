
#pragma once

#include "../NieRLibConfig.h"
#include "NR_IThread.h"

/**
** @brief ��ȡ�������߳� ID
*/
NIER_CAPI NR_IThread::IDType NR_GetCallerThreadID(void);

/**
** @brief ��ȡ�������߳�
*/
NIER_CAPI NR_IThread * NR_GetCallerThread(void);
