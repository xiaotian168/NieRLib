
#pragma once

#include "IFileEnumerator.h"

class CWin32FileEnumerator : public IFileEnumerator
{
public:

	static const unsigned int MaxPathSize = 260 * 4;

	static CWin32FileEnumerator * Make(void);

protected:

	CWin32FileEnumerator();

	~CWin32FileEnumerator();

public:

	bool EnumAllFileW(const wchar_t * pszDirectory, const wchar_t * pszFileExt, const bool bEnumSubDir, std::list<IFileEnumResult *> & ResultList) override;

	bool EnumAllDirectoryW(const wchar_t * pszDirectory, const bool bEnumSubDir, std::list<IFileEnumResult *> & ResultList) override;
};
