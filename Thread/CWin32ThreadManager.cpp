
#include "CWin32ThreadManager.h"
#include "CWin32Thread.h"

#if defined NIER_PLATFORM_WIN32

CWin32ThreadManager * CWin32ThreadManager::Make(void)
{
	return new CWin32ThreadManager();
}

CWin32ThreadManager::CWin32ThreadManager()
{

}

CWin32ThreadManager::~CWin32ThreadManager()
{

}

IThread * CWin32ThreadManager::GetCurrentThread(void)
{
	const auto hThread = ::GetCurrentThread();
	if (hThread)
	{
		return CWin32Thread::Make(hThread);
	}

	return 0;
}

#endif
