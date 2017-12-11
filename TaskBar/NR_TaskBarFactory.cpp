
#define _NR_API

#include "NR_TaskBarFactory.h"
#include "NR_CWin32TaskBarInfo.h"

#if defined NR_PLATFORM_WIN32

NR_IDockableTaskBarInfo * NR_MakeWin32TaskBarInfo(void)
{
	return NR_CWin32TaskBarInfo::Make();
}

#endif

NR_IDockableTaskBarInfo * NR_MakeTaskBarInfoByOSPlatform(void)
{
#if defined NR_PLATFORM_WIN32
	return NR_MakeWin32TaskBarInfo();
#endif

	return 0;
}
