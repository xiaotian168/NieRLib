
#pragma once

#include "../NieRLibConfig.h"

class NR_IShortcutManager;

#if defined NR_PLATFORM_WIN32

/**
** @brief 创建 Win32 快捷方式管理器
** @return Win32 快捷方式管理器
*/
NR_CAPI NR_IShortcutManager * MakeWin32ShortcutManager(void);

#endif

/**
** @brief 自动根据调用者所在平台，创建快捷方式管理器
** @return 快捷方式管理器
*/
NR_CAPI NR_IShortcutManager * MakeShortcutManagerByOSPlatform(void);
