
#pragma once

#include "../NieRLibConfig.h"

class NR_ILog;

/**
** @brief ���������ļ�����־
** @return �����ļ�����־
*/
NR_CAPI NR_ILog * NR_MakeFileLogW(const wchar_t * pszLogFilePath);
