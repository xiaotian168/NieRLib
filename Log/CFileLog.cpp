
#include "CFileLog.h"
#include "../FileSystem/FileSystemFactory.h"
#include "../FileSystem/IFileSystem.h"
#include "../FileSystem/IFile.h"
#include "../StringConverter/StringConverterTool.h"
#include "../Lock/LockFactory.h"
#include "../Lock/ILock.h"

CFileLog * CFileLog::MakeW(const wchar_t * pszLogFilePath)
{
	return new CFileLog(pszLogFilePath);
}

CFileLog::CFileLog(const wchar_t * pszLogFilePath)
{
	if (pszLogFilePath)
	{
		auto pFileSystem = MakeFileSystemByOSPlatform();
		if (pFileSystem)
		{
			m_pFile = pFileSystem->GetFileForWriteW(pszLogFilePath);

			SAFE_RELEASE(pFileSystem);
		}
	}

	m_pLockFile = MakeLockByOSPlatform();
}

CFileLog::~CFileLog()
{
	if (m_pFile)m_pFile->Close();

	SAFE_RELEASE(m_pFile);
	SAFE_RELEASE(m_pLockFile);
}

bool CFileLog::SetFilterLogLevel(const emLogLevel Level)
{
	m_FilterLogLevel = Level;

	return true;
}

ILog::emLogLevel CFileLog::GetFilterLogLevel(void) const
{
	return m_FilterLogLevel;
}

bool CFileLog::LogMsgW(const emLogLevel Level, const wchar_t * pszMsg)
{
	bool bRet = false;

	if (pszMsg)
	{
		auto pszMsgA = Unicode2MultiByte(pszMsg);
		if (pszMsgA)
		{
			if (LogMsgA(Level, pszMsgA))
			{
				bRet = true;
			}

			FreeMultiByteString(pszMsgA);
			pszMsgA = 0;
		}
	}

	return bRet;
}

bool CFileLog::LogMsgA(const emLogLevel Level, const char * pszMsg)
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

bool CFileLog::LogFormatMsgW(const emLogLevel Level, const wchar_t * pszFmt, ...)
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
#if defined NIER_PLATFORM_WIN32
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

bool CFileLog::LogFormatMsgA(const emLogLevel Level, const char * pszFmt, ...)
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
#if defined NIER_PLATFORM_WIN32
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
