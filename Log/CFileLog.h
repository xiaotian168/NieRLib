
#pragma once

#include "ILog.h"

class IFile;
class ILock;

class CFileLog : public ILog
{
public:

	static CFileLog * MakeW(const wchar_t * pszLogFilePath);

protected:

	CFileLog(const wchar_t * pszLogFilePath);

	~CFileLog();

public:

	bool SetFilterLogLevel(const emLogLevel Level) override;

	emLogLevel GetFilterLogLevel(void) const override;

	bool LogMsgW(const emLogLevel Level, const wchar_t * pszMsg) override;

	bool LogMsgA(const emLogLevel Level, const char * pszMsg) override;

	bool LogFormatMsgW(const emLogLevel Level, const wchar_t * pszFmt, ...) override;

	bool LogFormatMsgA(const emLogLevel Level, const char * pszFmt, ...) override;

private:

	IFile * m_pFile{ 0 };
	ILog::emLogLevel m_FilterLogLevel{ ILog::eLogLevel_All };
	ILock * m_pLockFile{ 0 };
};
