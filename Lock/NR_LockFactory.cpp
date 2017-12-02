
#define _NR_API

#include "NR_LockFactory.h"
#include "NR_CSimpleWin32Lock.h"

#if defined NR_PLATFORM_WIN32

NR_ILock * NR_MakeSimpleWin32Lock(void)
{
	return NR_CSimpleWin32Lock::Make();
}

#endif

NR_ILock * NR_MakeLockByOSPlatform(void)
{
#if defined NR_PLATFORM_WIN32
	return NR_CSimpleWin32Lock::Make();
#endif

	return 0;
}
