
#pragma once

#include "../NieRLibConfig.h"

class NR_ILibraryManager;

#if defined NIER_PLATFORM_WIN32

/**
** @brief 创建 Win32 库管理器
** @return Win32 库管理器
*/
NIER_CAPI NR_ILibraryManager * NR_MakeWin32LibraryManager(void);

#endif

/**
** @brief 自动根据调用者所在平台，创建库管理器
** @return 库管理器
*/
NIER_CAPI NR_ILibraryManager * NR_MakeLibraryManagerByOSPlatform(void);
