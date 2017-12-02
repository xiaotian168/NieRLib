
#pragma once

#include "../NieRLibConfig.h"

class NR_ILog;

/**
** @brief 创建基于文件的日志
** @return 基于文件的日志
*/
NIER_CAPI NR_ILog * NR_MakeFileLogW(const wchar_t * pszLogFilePath);
