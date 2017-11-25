
#pragma once

#include "../NieRLibConfig.h"

#if defined UNICODE || defined _UNICODE
#	define DeleteAllShortcutByTargetPath DeleteAllShortcutByTargetPathW
#else
#	define DeleteAllShortcutByTargetPath DeleteAllShortcutByTargetPathA
#endif

/**
** @brief �Ƴ�ָ��Ŀ¼������ָ��ָ��Ŀ��Ŀ�ݷ�ʽ
*/
NIER_CAPI bool DeleteAllShortcutByTargetPathW(const wchar_t * pszSearchDirectory, const wchar_t * pszTargetPath);
NIER_CAPI bool DeleteAllShortcutByTargetPathA(const char * pszSearchDirectory, const char * pszTargetPath);
