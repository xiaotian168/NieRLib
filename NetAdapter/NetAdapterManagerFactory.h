
#pragma once

#include "../NieRLibConfig.h"

class INetAdapterManager;

/**
** @brief 创建 Win32 网络适配器管理器
** @return Win32 网络适配器管理器
*/
NIER_CAPI INetAdapterManager * MakeWin32NetAdapterManager(void);

/**
** @brief 自动根据调用者所在平台，创建网络适配器管理器
** @return 网络适配器管理器
*/
NIER_CAPI INetAdapterManager * MakeNetAdapterManagerByOSPlatform(void);
