
#include "NR_LibraryManagerFactory.h"
#include "NR_CWin32LibraryManager.h"

#if defined NR_PLATFORM_WIN32

NR_ILibraryManager * NR_MakeWin32LibraryManager(void)
{
	return NR_CWin32LibraryManager::Make();
}

#endif

NR_ILibraryManager * NR_MakeLibraryManagerByOSPlatform(void)
{
#if defined NR_PLATFORM_WIN32
	return NR_CWin32LibraryManager::Make();
#endif

	return 0;
}
