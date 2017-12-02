
#include "NR_CSimpleWin32Lock.h"

#if defined NIER_PLATFORM_WIN32

NR_CSimpleWin32Lock * NR_CSimpleWin32Lock::Make(void)
{
	return new NR_CSimpleWin32Lock();
}

NR_CSimpleWin32Lock::NR_CSimpleWin32Lock()
{
	memset(&m_CriticalSection, 0, sizeof(m_CriticalSection));
	InitializeCriticalSection(&m_CriticalSection);
}

NR_CSimpleWin32Lock::~NR_CSimpleWin32Lock()
{
	DeleteCriticalSection(&m_CriticalSection);
	memset(&m_CriticalSection, 0, sizeof(m_CriticalSection));
}

bool NR_CSimpleWin32Lock::Lock(void)
{
	EnterCriticalSection(&m_CriticalSection);

	return true;
}

bool NR_CSimpleWin32Lock::Unlock(void)
{
	LeaveCriticalSection(&m_CriticalSection);

	return true;
}

#endif
