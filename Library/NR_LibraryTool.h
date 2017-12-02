
#pragma once

#include "../NieRLibConfig.h"

class NR_ILibrary;

/**
** @brief 加载库
** @param pszLibraryPath 库文件路径
** @return 库
*/
NIER_CAPI NR_ILibrary * NR_GetLibraryW(const wchar_t * pszLibraryPath);
