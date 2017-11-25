
#pragma once

#include "../NieRLibConfig.h"

class ILibrary;

/**
** @brief 加载库
** @param pszLibraryPath 库文件路径
** @return 库
*/
NIER_CAPI ILibrary * GetLibraryW(const wchar_t * pszLibraryPath);
