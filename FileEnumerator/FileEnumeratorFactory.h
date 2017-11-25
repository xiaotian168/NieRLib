
#pragma once

#include "../NieRLibConfig.h"

class IFileEnumerator;

/**
** @brief 创建 Win32 文件枚举器
** @return Win32 文件枚举器
*/
NIER_CAPI IFileEnumerator * MakeWin32FileEnumerator(void);

/**
** @brief 自动根据调用者所在平台，创建文件枚举器
** @return 文件枚举器
*/
NIER_CAPI IFileEnumerator * MakeFileEnumeratorByOSPlatform(void);
