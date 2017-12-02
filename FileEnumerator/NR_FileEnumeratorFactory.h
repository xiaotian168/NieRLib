
#pragma once

#include "../NieRLibConfig.h"

class NR_IFileEnumerator;

#if defined NIER_PLATFORM_WIN32

/**
** @brief 创建 Win32 文件枚举器
** @return Win32 文件枚举器
*/
NIER_CAPI NR_IFileEnumerator * NR_MakeWin32FileEnumerator(void);

#endif

/**
** @brief 自动根据调用者所在平台，创建文件枚举器
** @return 文件枚举器
*/
NIER_CAPI NR_IFileEnumerator * NR_MakeFileEnumeratorByOSPlatform(void);
