
#pragma once

#include "../NieRLibConfig.h"
#include "NR_IThread.h"

/**
** @brief 获取调用者线程 ID
*/
NIER_CAPI NR_IThread::IDType NR_GetCallerThreadID(void);

/**
** @brief 获取调用者线程
*/
NIER_CAPI NR_IThread * NR_GetCallerThread(void);
