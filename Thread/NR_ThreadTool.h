
#pragma once

#include "../NieRLibConfig.h"
#include "NR_IThread.h"

/**
** @brief ��ȡ�������߳� ID
*/
NR_CAPI NR_IThread::IDType NR_GetCallerThreadID(void);

/**
** @brief ��ȡ�������߳�
*/
NR_CAPI NR_IThread * NR_GetCallerThread(void);
