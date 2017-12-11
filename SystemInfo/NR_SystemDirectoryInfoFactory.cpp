
#define _NR_API

#include "NR_SystemDirectoryInfoFactory.h"
#include "NR_CWin32SystemDirectoryInfo.h"

#if defined NR_PLATFORM_WIN32

NR_ISystemDirectoryInfo * MakeWin32SystemDirectoryInfo(void)
{
	return NR_CWin32SystemDirectoryInfo::Make();
}

#endif

NR_ISystemDirectoryInfo * MakeSystemDirectoryInfoByOSPlatform(void)
{
#if defined NR_PLATFORM_WIN32
	return NR_CWin32SystemDirectoryInfo::Make();
#endif

	return 0;
}
