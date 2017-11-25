
#include "CSimpleWin32Lock.h"

#if defined NIER_PLATFORM_WIN32

CSimpleWin32Lock * CSimpleWin32Lock::Make(void)
{
	return new CSimpleWin32Lock();
}

CSimpleWin32Lock::CSimpleWin32Lock()
{
	memset(&m_CriticalSection, 0, sizeof(m_CriticalSection));
	InitializeCriticalSection(&m_CriticalSection);
}

CSimpleWin32Lock::~CSimpleWin32Lock()
{
	DeleteCriticalSection(&m_CriticalSection);
	memset(&m_CriticalSection, 0, sizeof(m_CriticalSection));
}

bool CSimpleWin32Lock::Lock(void)
{
	EnterCriticalSection(&m_CriticalSection);

	return true;
}

bool CSimpleWin32Lock::Unlock(void)
{
	LeaveCriticalSection(&m_CriticalSection);

	return true;
}

#endif
