
#pragma once

#include "../NieRLibConfig.h"

class NR_IFilePath;

#if defined NIER_PLATFORM_WIN32

/**
** @brief 创建 Win32 文件路径对象
** @return Win32 文件路径对象
*/
NIER_CAPI NR_IFilePath * MakeWin32FilePath(void);

#endif

/**
** @brief 自动根据调用者所在平台，创建文件路径对象
** @return 文件路径对象
*/
NIER_CAPI NR_IFilePath * MakeFilePathByOSPlatform(void);
