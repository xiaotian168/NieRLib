
#define _NIER_API

#include "ProcessManagerFactory.h"
#include "CWin32ProcessManager.h"

IProcessManager * MakeWin32ProcessManager(void)
{
#if defined NIER_PLATFORM_WIN32
	return CWin32ProcessManager::Make();
#endif

	return 0;
}

IProcessManager * MakeProcessManagerByOSPlatform(void)
{
#if defined NIER_PLATFORM_WIN32
	return CWin32ProcessManager::Make();
#endif

	return 0;
}
