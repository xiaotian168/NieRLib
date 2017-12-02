
#include "NR_CWin32Thread.h"

#if defined NR_PLATFORM_WIN32

NR_CWin32Thread * NR_CWin32Thread::Make(const HANDLE hThread)
{
	return new NR_CWin32Thread(hThread);
}

NR_CWin32Thread::NR_CWin32Thread(const HANDLE hThread)
{
	m_hThread = hThread;
}

NR_CWin32Thread::~NR_CWin32Thread()
{
	m_hThread = 0;
}

bool NR_CWin32Thread::GetThreadID(IDType & ID)
{
	bool bRet = false;

	if (m_hThread)
	{
		ID = static_cast<IDType>(GetThreadId(m_hThread));

		bRet = true;
	}

	return bRet;
}

bool NR_CWin32Thread::ShutdownThread(const unsigned int uExitCode)
{
	bool bRet = false;

	if (m_hThread)
	{
		if (TerminateThread(m_hThread, uExitCode))
		{
			m_hThread = 0;

			bRet = true;
		}
	}

	return bRet;
}

#endif
