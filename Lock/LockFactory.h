
#pragma once

#include "../NieRLibConfig.h"

class ILock;

/**
** @brief 创建简单 Win32 互斥锁
** @return 简单 Win32 互斥锁
*/
NIER_CAPI ILock * MakeSimpleWin32Lock(void);

/**
** @brief 自动根据调用者所在平台，创建互斥锁
** @return 互斥锁
*/
NIER_CAPI ILock * MakeLockByOSPlatform(void);
