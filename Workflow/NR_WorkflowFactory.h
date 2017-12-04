
#pragma once

#include "../NieRLibConfig.h"

class NR_IWorkflow;

/**
** @brief 创建异步串行工作流
** @return 异步串行工作流
*/
NR_CAPI NR_IWorkflow * NR_MakeAsyncQueueWorkflow(void);
