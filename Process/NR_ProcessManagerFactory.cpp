
#define _NR_API

#include "NR_ProcessManagerFactory.h"
#include "NR_CWin32ProcessManager.h"

#if defined NR_PLATFORM_WIN32

NR_IProcessManager * MakeWin32ProcessManager(void)
{
	return NR_CWin32ProcessManager::Make();
}

#endif

NR_IProcessManager * MakeProcessManagerByOSPlatform(void)
{
#if defined NR_PLATFORM_WIN32
	return NR_CWin32ProcessManager::Make();
#endif

	return 0;
}
