
#include "NR_LogFactory.h"
#include "NR_CFileLog.h"

NR_ILog * NR_MakeFileLogW(const wchar_t * pszLogFilePath)
{
	return NR_CFileLog::MakeW(pszLogFilePath);
}
