
#pragma once

#include "../NieRLibConfig.h"

#if defined UNICODE || defined _UNICODE
#	define NR_DeleteAllShortcutByTargetPath NR_DeleteAllShortcutByTargetPathW
#else
#	define NR_DeleteAllShortcutByTargetPath NR_DeleteAllShortcutByTargetPathA
#endif

/**
** @brief 移除指定目录下所有指向指定目标的快捷方式
*/
NIER_CAPI bool NR_DeleteAllShortcutByTargetPathW(const wchar_t * pszSearchDirectory, const wchar_t * pszTargetPath);
NIER_CAPI bool NR_DeleteAllShortcutByTargetPathA(const char * pszSearchDirectory, const char * pszTargetPath);
