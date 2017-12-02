
#define _NIER_API

#include "NR_NetAdapterManagerFactory.h"
#include "NR_CWin32NetAapterManager.h"

#if defined NIER_PLATFORM_WIN32

NR_INetAdapterManager * NR_MakeWin32NetAdapterManager(void)
{
	return NR_CWin32NetAapterManager::Make();
}

#endif

NR_INetAdapterManager * NR_MakeNetAdapterManagerByOSPlatform(void)
{
#if defined NIER_PLATFORM_WIN32
	return NR_CWin32NetAapterManager::Make();
#endif

	return 0;
}
