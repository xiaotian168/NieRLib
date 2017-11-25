
#include "LogFactory.h"
#include "CFileLog.h"

ILog * MakeFileLogW(const wchar_t * pszLogFilePath)
{
	return CFileLog::MakeW(pszLogFilePath);
}
