
#pragma once

#include "../NieRLibConfig.h"

#if defined UNICODE || defined _UNICODE
#	define DeleteAllShortcutByTargetPath DeleteAllShortcutByTargetPathW
#else
#	define DeleteAllShortcutByTargetPath DeleteAllShortcutByTargetPathA
#endif

/**
** @brief 移除指定目录下所有指向指定目标的快捷方式
*/
NIER_CAPI bool DeleteAllShortcutByTargetPathW(const wchar_t * pszSearchDirectory, const wchar_t * pszTargetPath);
NIER_CAPI bool DeleteAllShortcutByTargetPathA(const char * pszSearchDirectory, const char * pszTargetPath);
