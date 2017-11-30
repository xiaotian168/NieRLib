
#pragma once

#include "../NieRLibConfig.h"

class ILibraryManager;

/**
** @brief 创建 Win32 库管理器
** @return Win32 库管理器
*/
NIER_CAPI ILibraryManager * MakeWin32LibraryManager(void);

/**
** @brief 自动根据调用者所在平台，创建库管理器
** @return 库管理器
*/
NIER_CAPI ILibraryManager * MakeLibraryManagerByOSPlatform(void);
