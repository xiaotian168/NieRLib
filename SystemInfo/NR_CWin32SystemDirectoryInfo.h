
#pragma once

#include "NR_ISystemDirectoryInfo.h"

#if defined NR_PLATFORM_WIN32

class NR_CWin32SystemDirectoryInfo : public NR_ISystemDirectoryInfo
{
public:

	static NR_CWin32SystemDirectoryInfo * Make(void);

protected:

	NR_CWin32SystemDirectoryInfo();

	~NR_CWin32SystemDirectoryInfo();

public:

	bool GetTempDirectoryW(wchar_t * pszDirectory, const unsigned int uSize) override;

	bool GetSystemDirectoryW(wchar_t * pszDirectory, const unsigned int uSize) override;
};

#endif
