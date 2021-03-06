
#define _NR_API

#include "NR_ThreadManagerFactory.h"
#include "NR_CWin32ThreadManager.h"

#if defined NR_PLATFORM_WIN32

NR_IThreadManager * NR_MakeWin32ThreadManager(void)
{
	return NR_CWin32ThreadManager::Make();
}

#endif

NR_IThreadManager * NR_MakeThreadManagerByOSPlatform(void)
{
#if defined NR_PLATFORM_WIN32
	return NR_CWin32ThreadManager::Make();
#endif

	return 0;
}
