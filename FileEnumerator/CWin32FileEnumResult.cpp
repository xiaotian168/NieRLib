
#define _NIER_API

#include "CWin32FileEnumResult.h"

CWin32FileEnumResult * CWin32FileEnumResult::Make(const wchar_t * pszResultPath, const DWORD dwFileAttributes)
{
	return new CWin32FileEnumResult(pszResultPath, dwFileAttributes);
}

CWin32FileEnumResult::CWin32FileEnumResult(const wchar_t * pszResultPath, const DWORD dwFileAttributes)
{
	if (pszResultPath)
	{
		m_strResultPath = pszResultPath;
	}

	m_dwFileAttributes = dwFileAttributes;
}

CWin32FileEnumResult::~CWin32FileEnumResult()
{
	m_strResultPath.clear();
	m_dwFileAttributes = 0;
}

bool CWin32FileEnumResult::IsDirectory(void) const
{
	bool bRet = false;

	if (m_strResultPath.c_str() && m_dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
	{
		bRet = true;
	}

	return bRet;
}

bool CWin32FileEnumResult::GetFileExtW(wchar_t * pszExt, const unsigned int uSize)
{
	bool bRet = false;

	if (m_strResultPath.c_str() && pszExt && uSize)
	{
		_wsplitpath_s(m_strResultPath.c_str(), 0, 0, 0, 0, 0, 0, pszExt, uSize);

		bRet = true;
	}

	return bRet;
}

bool CWin32FileEnumResult::GetResultPathW(wchar_t * pszPath, const unsigned int uSize) const
{
	bool bRet = false;

	if (m_strResultPath.c_str() && pszPath && uSize)
	{
		wcscpy_s(pszPath, uSize, m_strResultPath.c_str());

		bRet = true;
	}

	return bRet;
}
