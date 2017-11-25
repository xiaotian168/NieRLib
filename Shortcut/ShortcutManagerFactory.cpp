
#define _NIER_API

#include "ShortcutManagerFactory.h"
#include "CWin32ShortcutManager.h"

IShortcutManager * MakeWin32ShortcutManager(void)
{
	return CWin32ShortcutManager::Make();
}

IShortcutManager * MakeShortcutManagerByOSPlatform(void)
{
#if defined NIER_PLATFORM_WIN32 || defined NIER_PLATFORM_LINUX
	return CWin32ShortcutManager::Make();
#endif

	return 0;
}
