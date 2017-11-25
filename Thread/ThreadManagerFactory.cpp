
#define _NIER_API

#include "ThreadManagerFactory.h"
#include "CWin32ThreadManager.h"

IThreadManager * MakeWin32ThreadManager(void)
{
#if defined NIER_PLATFORM_WIN32
	return CWin32ThreadManager::Make();
#endif

	return 0;
}

IThreadManager * MakeThreadManagerByOSPlatform(void)
{
#if defined NIER_PLATFORM_WIN32
	return CWin32ThreadManager::Make();
#endif

	return 0;
}
