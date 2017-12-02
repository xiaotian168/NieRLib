
#pragma once

#include "NR_ILog.h"

class NR_IFile;
class NR_ILock;

class NR_CFileLog : public NR_ILog
{
public:

	static NR_CFileLog * MakeW(const wchar_t * pszLogFilePath);

protected:

	NR_CFileLog(const wchar_t * pszLogFilePath);

	~NR_CFileLog();

public:

	bool SetFilterLogLevel(const NR_LogLevel Level) override;

	NR_LogLevel GetFilterLogLevel(void) const override;

	bool LogMsgW(const NR_LogLevel Level, const wchar_t * pszMsg) override;

	bool LogMsgA(const NR_LogLevel Level, const char * pszMsg) override;

	bool LogFormatMsgW(const NR_LogLevel Level, const wchar_t * pszFmt, ...) override;

	bool LogFormatMsgA(const NR_LogLevel Level, const char * pszFmt, ...) override;

private:

	NR_IFile * m_pFile{ 0 };
	NR_ILog::NR_LogLevel m_FilterLogLevel{ NR_ILog::eLogLevel_All };
	NR_ILock * m_pLockFile{ 0 };
};
