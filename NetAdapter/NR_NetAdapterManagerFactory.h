
#pragma once

#include "../NieRLibConfig.h"

class NR_INetAdapterManager;

#if defined NIER_PLATFORM_WIN32

/**
** @brief 创建 Win32 网络适配器管理器
** @return Win32 网络适配器管理器
*/
NIER_CAPI NR_INetAdapterManager * NR_MakeWin32NetAdapterManager(void);

#endif

/**
** @brief 自动根据调用者所在平台，创建网络适配器管理器
** @return 网络适配器管理器
*/
NIER_CAPI NR_INetAdapterManager * NR_MakeNetAdapterManagerByOSPlatform(void);
