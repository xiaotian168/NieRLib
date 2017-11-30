
#pragma once

#include "../NieRLibConfig.h"

class IThreadManager;

/**
** @brief 创建 Win32 线程管理器
** @return Win32 线程管理器
*/
NIER_CAPI IThreadManager * MakeWin32ThreadManager(void);

/**
** @brief 自动根据调用者所在平台，创建字线程管理器
** @return 线程管理器
*/
NIER_CAPI IThreadManager * MakeThreadManagerByOSPlatform(void);
