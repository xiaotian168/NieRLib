
#pragma once

#include "NR_IFileEnumerator.h"

#if defined NR_PLATFORM_WIN32

class NR_CWin32FileEnumerator : public NR_IFileEnumerator
{
public:

	static const unsigned int MaxPathSize = 260 * 4;

	static NR_CWin32FileEnumerator * Make(void);

protected:

	NR_CWin32FileEnumerator();

	~NR_CWin32FileEnumerator();

public:

	bool EnumAllFileW(const wchar_t * pszDirectory, const wchar_t * pszFileExt, const bool bEnumSubDir, std::list<NR_IFileEnumResult *> & ResultList) override;

	bool EnumAllDirectoryW(const wchar_t * pszDirectory, const bool bEnumSubDir, std::list<NR_IFileEnumResult *> & ResultList) override;
};

#endif
