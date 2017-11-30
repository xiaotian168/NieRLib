
#pragma once

#include "../NieRLibConfig.h"

class ILog;

/**
** @brief 创建基于文件的日志
** @return 基于文件的日志
*/
NIER_CAPI ILog * MakeFileLogW(const wchar_t * pszLogFilePath);
