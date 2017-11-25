
#pragma once

#include "../NieRLibConfig.h"

class ILog;

NIER_CAPI ILog * MakeFileLogW(const wchar_t * pszLogFilePath);
