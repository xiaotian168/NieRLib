
#pragma once

#include "../NieRLibConfig.h"

class ILog;

/**
** @brief ���������ļ�����־
** @return �����ļ�����־
*/
NIER_CAPI ILog * MakeFileLogW(const wchar_t * pszLogFilePath);
