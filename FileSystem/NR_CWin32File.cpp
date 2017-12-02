
#include "NR_CWin32File.h"

#if defined NIER_PLATFORM_WIN32

NR_CWin32File * NR_CWin32File::MakeW(const wchar_t * pszFilePath, const wchar_t * pszMode)
{
	return new NR_CWin32File(pszFilePath, pszMode);
}

NR_CWin32File::NR_CWin32File(const wchar_t * pszFilePath, const wchar_t * pszMode)
{
	if (pszFilePath && pszMode)
	{
		_wfopen_s(&m_pFile, pszFilePath, pszMode);
	}
}

NR_CWin32File::~NR_CWin32File()
{
	Close();
}

bool NR_CWin32File::Close(void)
{
	bool bRet = false;

	if (m_pFile)
	{
		fclose(m_pFile);
		m_pFile = 0;

		bRet = true;
	}

	return bRet;
}

bool NR_CWin32File::SeekTo(const long nPos)
{
	bool bRet = false;

	if (m_pFile)
	{
		if (0 == fseek(m_pFile, nPos, SEEK_SET))
		{
			bRet = true;
		}
	}

	return bRet;
}

bool NR_CWin32File::SeekToBegin(void)
{
	bool bRet = false;

	if (m_pFile)
	{
		if (0 == fseek(m_pFile, 0, SEEK_SET))
		{
			bRet = true;
		}
	}

	return bRet;
}

bool NR_CWin32File::SeekToEnd(void)
{
	bool bRet = false;

	if (m_pFile)
	{
		if (0 == fseek(m_pFile, 0, SEEK_END))
		{
			bRet = true;
		}
	}

	return bRet;
}

bool NR_CWin32File::SeekOffset(const long nOffset)
{
	bool bRet = false;

	if (m_pFile)
	{
		if (0 == fseek(m_pFile, nOffset, SEEK_CUR))
		{
			bRet = true;
		}
	}

	return bRet;
}

long NR_CWin32File::Tell(void)
{
	if (m_pFile)
	{
		return ftell(m_pFile);
	}

	return 0;
}

bool NR_CWin32File::Read(void * pBuffer, const unsigned int uBytes)
{
	bool bRet = false;

	if (m_pFile && pBuffer && uBytes)
	{
		if (uBytes == fread(pBuffer, 1, uBytes, m_pFile))
		{
			bRet = true;
		}
	}

	return bRet;
}

bool NR_CWin32File::Write(const void * pBuffer, const unsigned int uBytes)
{
	bool bRet = false;

	if (m_pFile && pBuffer && uBytes)
	{
		if (uBytes == fwrite(pBuffer, 1, uBytes, m_pFile))
		{
			bRet = true;
		}
	}

	return bRet;
}

#endif
