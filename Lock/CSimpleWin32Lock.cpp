
#include "CSimpleWin32Lock.h"

CSimpleWin32Lock * CSimpleWin32Lock::Make(void)
{
	return new CSimpleWin32Lock();
}

CSimpleWin32Lock::CSimpleWin32Lock()
{
	InitializeCriticalSection(&m_CriticalSection);
}

CSimpleWin32Lock::~CSimpleWin32Lock()
{
	DeleteCriticalSection(&m_CriticalSection);
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
