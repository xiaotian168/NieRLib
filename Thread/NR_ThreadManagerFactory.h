
#pragma once

#include "../NieRLibConfig.h"

class NR_IThreadManager;

#if defined NR_PLATFORM_WIN32

/**
** @brief 创建 Win32 线程管理器
** @return Win32 线程管理器
*/
NR_CAPI NR_IThreadManager * NR_MakeWin32ThreadManager(void);

#endif

/**
** @brief 自动根据调用者所在平台，创建字线程管理器
** @return 线程管理器
*/
NR_CAPI NR_IThreadManager * NR_MakeThreadManagerByOSPlatform(void);
