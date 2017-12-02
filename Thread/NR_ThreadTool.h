
#pragma once

#include "../NieRLibConfig.h"
#include "NR_IThread.h"

/**
** @brief 获取调用者线程 ID
*/
NR_CAPI NR_IThread::IDType NR_GetCallerThreadID(void);

/**
** @brief 获取调用者线程
*/
NR_CAPI NR_IThread * NR_GetCallerThread(void);
