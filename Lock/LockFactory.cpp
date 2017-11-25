
#define _NIER_API

#include "LockFactory.h"
#include "CSimpleWin32Lock.h"

ILock * MakeSimpleWin32Lock(void)
{
#if defined NIER_PLATFORM_WIN32
	return CSimpleWin32Lock::Make();
#endif

	return 0;
}

ILock * MakeLockByOSPlatform(void)
{
#if defined NIER_PLATFORM_WIN32
	return CSimpleWin32Lock::Make();
#endif

	return 0;
}
