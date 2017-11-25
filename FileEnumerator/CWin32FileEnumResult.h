
#pragma once

#include "IFileEnumResult.h"

#if defined NIER_PLATFORM_WIN32

class CWin32FileEnumResult : public IFileEnumResult
{
public:

	static CWin32FileEnumResult * Make(const wchar_t * pszResultPath, const DWORD dwFileAttributes);

protected:

	CWin32FileEnumResult(const wchar_t * pszResultPath, const DWORD dwFileAttributes);

	~CWin32FileEnumResult();

public:

	bool IsDirectory(void) const override;

	bool GetFileExtW(wchar_t * pszExt, const unsigned int uSize) override;

	bool GetResultPathW(wchar_t * pszPath, const unsigned int uSize) const override;

private:

	std::wstring m_strResultPath;
	DWORD m_dwFileAttributes;
};

#endif
