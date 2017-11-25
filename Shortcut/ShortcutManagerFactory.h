
#pragma once

#include "../NieRLibConfig.h"

class IShortcutManager;

/**
** @brief 创建 Win32 快捷方式管理器
** @return Win32 快捷方式管理器
*/
NIER_CAPI IShortcutManager * MakeWin32ShortcutManager(void);

/**
** @brief 自动根据调用者所在平台，创建快捷方式管理器
** @return 快捷方式管理器
*/
NIER_CAPI IShortcutManager * MakeShortcutManagerByOSPlatform(void);
