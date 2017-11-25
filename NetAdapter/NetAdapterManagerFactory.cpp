
#define _NIER_API

#include "NetAdapterManagerFactory.h"
#include "CWin32NetAapterManager.h"

INetAdapterManager * MakeWin32NetAdapterManager(void)
{
#if defined NIER_PLATFORM_WIN32
	return CWin32NetAapterManager::Make();
#endif

	return 0;
}

INetAdapterManager * MakeNetAdapterManagerByOSPlatform(void)
{
#if defined NIER_PLATFORM_WIN32
	return CWin32NetAapterManager::Make();
#endif

	return 0;
}
