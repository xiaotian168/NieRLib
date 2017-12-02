
#pragma once

#include "../NieRLibConfig.h"

class NR_ILock;

#if defined NIER_PLATFORM_WIN32

/**
** @brief 创建简单 Win32 互斥锁
** @return 简单 Win32 互斥锁
*/
NIER_CAPI NR_ILock * NR_MakeSimpleWin32Lock(void);

#endif

/**
** @brief 自动根据调用者所在平台，创建互斥锁
** @return 互斥锁
*/
NIER_CAPI NR_ILock * NR_MakeLockByOSPlatform(void);
