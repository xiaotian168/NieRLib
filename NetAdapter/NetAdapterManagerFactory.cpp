
#define _NIER_API

#include "NetAdapterManagerFactory.h"
#include "CWin32NetAapterManager.h"

INetAdapterManager * MakeWin32NetAdapterManager(void)
{
	return CWin32NetAapterManager::Make();
}

INetAdapterManager * MakeNetAdapterNanagerByOSPlatform(void)
{
#if defined NIER_PLATFORM_WIN32
	return CWin32NetAapterManager::Make();
#endif

	return 0;
}
