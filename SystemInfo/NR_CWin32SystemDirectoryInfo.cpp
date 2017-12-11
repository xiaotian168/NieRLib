
#include "NR_CWin32SystemDirectoryInfo.h"

#if defined NR_PLATFORM_WIN32

NR_CWin32SystemDirectoryInfo * NR_CWin32SystemDirectoryInfo::Make(void)
{
	return new NR_CWin32SystemDirectoryInfo();
}

NR_CWin32SystemDirectoryInfo::NR_CWin32SystemDirectoryInfo()
{

}

NR_CWin32SystemDirectoryInfo::~NR_CWin32SystemDirectoryInfo()
{

}

bool NR_CWin32SystemDirectoryInfo::GetTempDirectoryW(wchar_t * pszDirectory, const unsigned int uSize)
{
	bool bRet = false;

	if (pszDirectory && uSize)
	{
		if (GetTempPathW(uSize, pszDirectory))
		{
			bRet = true;
		}
	}

	return bRet;
}

bool NR_CWin32SystemDirectoryInfo::GetSystemDirectoryW(wchar_t * pszDirectory, const unsigned int uSize)
{
	bool bRet = false;

	if (pszDirectory && uSize)
	{
		if (GetWindowsDirectoryW(pszDirectory, uSize))
		{
			bRet = true;
		}
	}

	return bRet;
}

#endif
