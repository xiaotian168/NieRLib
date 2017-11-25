
#include "CWin32Thread.h"

#if defined NIER_PLATFORM_WIN32

CWin32Thread * CWin32Thread::Make(const HANDLE hThread)
{
	return new CWin32Thread(hThread);
}

CWin32Thread::CWin32Thread(const HANDLE hThread)
{
	m_hThread = hThread;
}

CWin32Thread::~CWin32Thread()
{
	m_hThread = 0;
}

bool CWin32Thread::GetThreadID(IDType & ID)
{
	bool bRet = false;

	if (m_hThread)
	{
		ID = static_cast<IDType>(GetThreadId(m_hThread));

		bRet = true;
	}

	return bRet;
}

bool CWin32Thread::ShutdownThread(const unsigned int uExitCode)
{
	bool bRet = false;

	if (m_hThread)
	{
		if (TerminateThread(m_hThread, uExitCode))
		{
			bRet = true;
		}
	}

	return bRet;
}

#endif
