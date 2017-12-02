
#pragma once

#include "../NieRLibConfig.h"

class NR_IProcessManager;

#if defined NIER_PLATFORM_WIN32

/**
** @brief 创建 Win32 进程管理器
** @return Win32 进程管理器
*/
NIER_CAPI NR_IProcessManager * MakeWin32ProcessManager(void);

#endif

/**
** @brief 自动根据调用者所在平台，创建进程管理器
** @return 进程管理器
*/
NIER_CAPI NR_IProcessManager * MakeProcessManagerByOSPlatform(void);
