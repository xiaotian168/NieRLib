
#pragma once

#include "../NieRLibConfig.h"

class NR_ILog;

/**
** @brief ���������ļ�����־
** @return �����ļ�����־
*/
NIER_CAPI NR_ILog * NR_MakeFileLogW(const wchar_t * pszLogFilePath);
