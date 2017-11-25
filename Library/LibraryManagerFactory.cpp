
#include "LibraryManagerFactory.h"
#include "CWin32LibraryManager.h"

ILibraryManager * MakeWin32LibraryManager(void)
{
#if defined NIER_PLATFORM_WIN32
	return CWin32LibraryManager::Make();
#endif

	return 0;
}

ILibraryManager * MakeLibraryManagerByOSPlatform(void)
{
#if defined NIER_PLATFORM_WIN32
	return CWin32LibraryManager::Make();
#endif

	return 0;
}
