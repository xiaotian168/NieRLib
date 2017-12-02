
#pragma once

#include "IFilePath.h"

#if defined NIER_PLATFORM_WIN32

class CWin32FilePath : public IFilePath
{
public:

	static CWin32FilePath * Make(void);

protected:

	CWin32FilePath();

	~CWin32FilePath();

public:

	bool SplitDirectoryW(const wchar_t * pszPathToSplit, wchar_t * pszDirectory, const unsigned int uSize) override;

	bool SplitFileTitleW(const wchar_t * pszPathToSplit, wchar_t * pszFileTitle, const unsigned int uSize) override;

	bool SplitFileTitleWithNoExeW(const wchar_t * pszPathToSplit, wchar_t * pszFileTitle, const unsigned int uSize) override;

	bool SplitFileExtW(const wchar_t * pszPathToSplit, wchar_t * pszFileExt, const unsigned int uSize) override;

	bool AppendBackslashW(wchar_t * pszPath, const unsigned int uSize) override;
};

#endif
