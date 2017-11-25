
#define _NIER_API

#include "ShortcutManagerFactory.h"
#include "CWin32ShortcutManager.h"

IShortcutManager * MakeWin32ShortcutManager(void)
{
#if defined NIER_PLATFORM_WIN32
	return CWin32ShortcutManager::Make();
#endif

	return 0;
}

IShortcutManager * MakeShortcutManagerByOSPlatform(void)
{
#if defined NIER_PLATFORM_WIN32
	return CWin32ShortcutManager::Make();
#endif

	return 0;
}
