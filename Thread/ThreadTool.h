
#pragma once

#include "../NieRLibConfig.h"
#include "IThread.h"

/**
** @brief ��ȡ�������߳� ID
*/
NIER_CAPI IThread::IDType GetCallerThreadID(void);

/**
** @brief ��ȡ�������߳�
*/
NIER_CAPI IThread * GetCallerThread(void);
