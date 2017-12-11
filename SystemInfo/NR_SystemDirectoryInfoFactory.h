
#pragma once

#include "../NieRLibConfig.h"

class NR_ISystemDirectoryInfo;

#if defined NR_PLATFORM_WIN32

/**
** @brief 创建 Win32 系统目录信息
** @return Win32 系统目录信息
*/
NR_CAPI NR_ISystemDirectoryInfo * MakeWin32SystemDirectoryInfo(void);

#endif

/**
** @brief 自动根据调用者所在平台，创建系统目录信息
** @return 系统目录信息
*/
NR_CAPI NR_ISystemDirectoryInfo * MakeSystemDirectoryInfoByOSPlatform(void);
