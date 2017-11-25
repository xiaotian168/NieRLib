
#pragma once

#include "../NieRLibConfig.h"

class IFileSystem;

/**
** @brief 创建 Win32 文件系统
** @return Win32 文件系统
*/
NIER_CAPI IFileSystem * MakeWin32FileSystem(void);

/**
** @brief 自动根据调用者所在平台，创建文件系统
** @return 文件系统
*/
NIER_CAPI IFileSystem * MakeFileSystemByOSPlatform(void);
