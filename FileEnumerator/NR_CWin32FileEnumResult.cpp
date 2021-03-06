
#define _NR_API

#include "NR_CWin32FileEnumResult.h"

#if defined NR_PLATFORM_WIN32

NR_CWin32FileEnumResult * NR_CWin32FileEnumResult::Make(const wchar_t * pszResultPath, const DWORD dwFileAttributes)
{
	return new NR_CWin32FileEnumResult(pszResultPath, dwFileAttributes);
}

NR_CWin32FileEnumResult::NR_CWin32FileEnumResult(const wchar_t * pszResultPath, const DWORD dwFileAttributes)
{
	if (pszResultPath)
	{
		m_strResultPath = pszResultPath;
	}

	m_dwFileAttributes = dwFileAttributes;
}

NR_CWin32FileEnumResult::~NR_CWin32FileEnumResult()
{
	m_strResultPath.clear();
	m_dwFileAttributes = 0;
}

bool NR_CWin32FileEnumResult::IsDirectory(void) const
{
	bool bRet = false;

	if (m_strResultPath.c_str() && m_dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
	{
		bRet = true;
	}

	return bRet;
}

bool NR_CWin32FileEnumResult::GetFileExtW(wchar_t * pszExt, const unsigned int uSize)
{
	bool bRet = false;

	if (m_strResultPath.c_str() && pszExt && uSize)
	{
		_wsplitpath_s(m_strResultPath.c_str(), 0, 0, 0, 0, 0, 0, pszExt, uSize);

		bRet = true;
	}

	return bRet;
}

bool NR_CWin32FileEnumResult::GetResultPathW(wchar_t * pszPath, const unsigned int uSize) const
{
	bool bRet = false;

	if (m_strResultPath.c_str() && pszPath && uSize)
	{
		wcscpy_s(pszPath, uSize, m_strResultPath.c_str());

		bRet = true;
	}

	return bRet;
}

#endif
