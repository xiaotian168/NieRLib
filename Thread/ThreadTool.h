
#pragma once

#include "../NieRLibConfig.h"
#include "IThread.h"

/**
** @brief 获取调用者线程 ID
*/
NIER_CAPI IThread::IDType GetCallerThreadID(void);

/**
** @brief 获取调用者线程
*/
NIER_CAPI IThread * GetCallerThread(void);
