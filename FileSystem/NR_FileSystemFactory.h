
#pragma once

#include "../NieRLibConfig.h"

class NR_IFileSystem;

#if defined NIER_PLATFORM_WIN32

/**
** @brief 创建 Win32 文件系统
** @return Win32 文件系统
*/
NIER_CAPI NR_IFileSystem * NR_MakeWin32FileSystem(void);

#endif

/**
** @brief 自动根据调用者所在平台，创建文件系统
** @return 文件系统
*/
NIER_CAPI NR_IFileSystem * NR_MakeFileSystemByOSPlatform(void);
