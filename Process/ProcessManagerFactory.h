
#pragma once

#include "../NieRLibConfig.h"

class IProcessManager;

/**
** @brief 创建 Win32 进程管理器
** @return Win32 进程管理器
*/
NIER_CAPI IProcessManager * MakeWin32ProcessManager(void);

/**
** @brief 自动根据调用者所在平台，创建进程管理器
** @return 进程管理器
*/
NIER_CAPI IProcessManager * MakeProcessManagerByOSPlatform(void);
