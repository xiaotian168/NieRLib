
#define _NIER_API

#include "NR_ShortcutManagerFactory.h"
#include "NR_CWin32ShortcutManager.h"

#if defined NIER_PLATFORM_WIN32

NR_IShortcutManager * MakeWin32ShortcutManager(void)
{
	return NR_CWin32ShortcutManager::Make();
}

#endif

NR_IShortcutManager * MakeShortcutManagerByOSPlatform(void)
{
#if defined NIER_PLATFORM_WIN32
	return NR_CWin32ShortcutManager::Make();
#endif

	return 0;
}
