
#pragma once

#include "NR_IFileEnumResult.h"

#if defined NR_PLATFORM_WIN32

class NR_CWin32FileEnumResult : public NR_IFileEnumResult
{
public:

	static NR_CWin32FileEnumResult * Make(const wchar_t * pszResultPath, const DWORD dwFileAttributes);

protected:

	NR_CWin32FileEnumResult(const wchar_t * pszResultPath, const DWORD dwFileAttributes);

	~NR_CWin32FileEnumResult();

public:

	bool IsDirectory(void) const override;

	bool GetFileExtW(wchar_t * pszExt, const unsigned int uSize) override;

	bool GetResultPathW(wchar_t * pszPath, const unsigned int uSize) const override;

private:

	std::wstring m_strResultPath;
	DWORD m_dwFileAttributes;
};

#endif
