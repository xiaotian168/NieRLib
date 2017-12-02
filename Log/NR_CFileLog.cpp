
#include "NR_CFileLog.h"
#include "../FileSystem/NR_FileSystemFactory.h"
#include "../FileSystem/NR_IFileSystem.h"
#include "../FileSystem/NR_IFile.h"
#include "../StringConverter/NR_StringConverterTool.h"
#include "../Lock/NR_LockFactory.h"
#include "../Lock/NR_ILock.h"

NR_CFileLog * NR_CFileLog::MakeW(const wchar_t * pszLogFilePath)
{
	return new NR_CFileLog(pszLogFilePath);
}

NR_CFileLog::NR_CFileLog(const wchar_t * pszLogFilePath)
{
	if (pszLogFilePath)
	{
		auto pFileSystem = NR_MakeFileSystemByOSPlatform();
		if (pFileSystem)
		{
			m_pFile = pFileSystem->GetFileForWriteW(pszLogFilePath);

			SAFE_RELEASE(pFileSystem);
		}
	}

	m_pLockFile = NR_MakeLockByOSPlatform();
}

NR_CFileLog::~NR_CFileLog()
{
	if (m_pFile)m_pFile->Close();

	SAFE_RELEASE(m_pFile);
	SAFE_RELEASE(m_pLockFile);
}

bool NR_CFileLog::SetFilterLogLevel(const NR_LogLevel Level)
{
	m_FilterLogLevel = Level;

	return true;
}

NR_ILog::NR_LogLevel NR_CFileLog::GetFilterLogLevel(void) const
{
	return m_FilterLogLevel;
}

bool NR_CFileLog::LogMsgW(const NR_LogLevel Level, const wchar_t * pszMsg)
{
	bool bRet = false;

	if (pszMsg)
	{
		auto pszMsgA = NR_Unicode2MultiByte(pszMsg);
		if (pszMsgA)
		{
			if (LogMsgA(Level, pszMsgA))
			{
				bRet = true;
			}

			NR_FreeMultiByteString(pszMsgA);
			pszMsgA = 0;
		}
	}

	return bRet;
}

bool NR_CFileLog::LogMsgA(const NR_LogLevel Level, const char * pszMsg)
{
	bool bRet = false;

	if (eLogLevel_Slient != m_FilterLogLevel)
	{
		if (m_pFile && Level <= m_FilterLogLevel && pszMsg)
		{
			const auto MsgLen = strlen(pszMsg);
			if (MsgLen)
			{
				if (m_pFile->Write(pszMsg, MsgLen))
				{
					bRet = true;
				}
			}
		}
	}

	return bRet;
}

bool NR_CFileLog::LogFormatMsgW(const NR_LogLevel Level, const wchar_t * pszFmt, ...)
{
	bool bRet = false;
	va_list vl = { 0 };

	if (pszFmt)
	{
		va_start(vl, pszFmt);
		{
			const auto MsgLen = _vscwprintf(pszFmt, vl);
			if (MsgLen)
			{
				auto pszMsg = new wchar_t[MsgLen + 1];
				if (pszMsg)
				{
#if defined NR_PLATFORM_WIN32
					if (vswprintf_s(pszMsg, MsgLen + 1, pszFmt, vl))
#else
					if (vswprintf(pszMsg, pszFmt, vl))
#endif
					{
						pszMsg[MsgLen] = L'\0';

						if (LogMsgW(Level, pszMsg))
						{
							bRet = true;
						}
					}

					delete[] pszMsg;
					pszMsg = 0;
				}
			}
		}
		va_end(vl);
	}

	return bRet;
}

bool NR_CFileLog::LogFormatMsgA(const NR_LogLevel Level, const char * pszFmt, ...)
{
	bool bRet = false;
	va_list vl = { 0 };

	if (eLogLevel_Slient != m_FilterLogLevel)
	{
		if (m_pFile && Level <= m_FilterLogLevel && pszFmt)
		{
			va_start(vl, pszFmt);
			{
				const auto MsgLen = _vscprintf(pszFmt, vl);
				if (MsgLen)
				{
					auto pszMsg = new char[MsgLen + 1];
					if (pszMsg)
					{
#if defined NR_PLATFORM_WIN32
						if (vsprintf_s(pszMsg, MsgLen + 1, pszFmt, vl))
#else
						if (vsprintf(pszMsg, pszFmt, vl))
#endif
						{
							pszMsg[MsgLen] = '\0';

							if (m_pFile->Write(pszMsg, MsgLen))
							{
								bRet = true;
							}
						}

						delete[] pszMsg;
						pszMsg = 0;
					}
				}
			}
			va_end(vl);
		}
	}

	return bRet;
}
