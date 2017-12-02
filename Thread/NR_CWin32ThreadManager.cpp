
#include "NR_CWin32ThreadManager.h"
#include "NR_CWin32Thread.h"

#if defined NR_PLATFORM_WIN32

NR_CWin32ThreadManager * NR_CWin32ThreadManager::Make(void)
{
	return new NR_CWin32ThreadManager();
}

NR_CWin32ThreadManager::NR_CWin32ThreadManager()
{

}

NR_CWin32ThreadManager::~NR_CWin32ThreadManager()
{

}

NR_IThread * NR_CWin32ThreadManager::GetCurrentThread(void)
{
	const auto hThread = ::GetCurrentThread();
	if (hThread)
	{
		return NR_CWin32Thread::Make(hThread);
	}

	return 0;
}

#endif
