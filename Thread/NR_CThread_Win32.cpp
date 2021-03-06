
#define _NR_API

#include "NR_CThread.h"

#if defined NR_PLATFORM_WIN32

DWORD GlobalThread(LPVOID pParam)
{
	NR_CThread * pThread = static_cast<NR_CThread *>(pParam);
	if (pThread)
	{
		pThread->Run();
	}

	return 0;
}

class CWin32ThreadContent : public NR_CThread::CThreadContent
{
public:

	inline CWin32ThreadContent()
	{

	}

public:

	void dummy(void) override
	{

	}

public:

	HANDLE hThread{ 0 };
};

NR_CThread::NR_CThread()
{
	m_pThreadContent = new CWin32ThreadContent();
}

NR_CThread::~NR_CThread()
{
	if (m_pThreadContent)
	{
		delete m_pThreadContent;
		m_pThreadContent = 0;
	}
}

bool NR_CThread::CreateThread(void)
{
	bool bRet = false;

	auto pWin32ThreadContent = dynamic_cast<CWin32ThreadContent *>(m_pThreadContent);
	if (pWin32ThreadContent)
	{
		if (!pWin32ThreadContent->hThread)
		{
			pWin32ThreadContent->hThread = ::CreateThread(0, 0, (LPTHREAD_START_ROUTINE)GlobalThread, this, 0, 0);
			if (pWin32ThreadContent->hThread)
			{
				bRet = true;
			}
		}
	}

	return bRet;
}

bool NR_CThread::TerminateThread(void)
{
	bool bRet = false;

	auto pWin32ThreadContent = dynamic_cast<CWin32ThreadContent *>(m_pThreadContent);
	if (pWin32ThreadContent)
	{
		if (pWin32ThreadContent->hThread)
		{
			if (::TerminateThread(pWin32ThreadContent->hThread, 0))
			{
				CloseHandle(pWin32ThreadContent->hThread);

				delete m_pThreadContent;
				m_pThreadContent = 0;

				bRet = true;
			}
		}
	}

	return bRet;
}

bool NR_CThread::PauseThread(void)
{
	bool bRet = false;

	auto pWin32ThreadContent = dynamic_cast<CWin32ThreadContent *>(m_pThreadContent);
	if (pWin32ThreadContent)
	{
		if (pWin32ThreadContent->hThread)
		{
			if (-1 != ::SuspendThread(pWin32ThreadContent->hThread))
			{
				bRet = true;
			}
		}
	}

	return bRet;
}

bool NR_CThread::ResumeThread(void)
{
	bool bRet = false;

	auto pWin32ThreadContent = dynamic_cast<CWin32ThreadContent *>(m_pThreadContent);
	if (pWin32ThreadContent)
	{
		if (pWin32ThreadContent->hThread)
		{
			if (-1 != ::ResumeThread(pWin32ThreadContent->hThread))
			{
				bRet = true;
			}
		}
	}

	return bRet;
}

bool NR_CThread::Wait(const unsigned int uTimeOut)
{
	bool bRet = false;

	auto pWin32ThreadContent = dynamic_cast<CWin32ThreadContent *>(m_pThreadContent);
	if (pWin32ThreadContent)
	{
		if (pWin32ThreadContent->hThread)
		{
			if (WAIT_OBJECT_0 == WaitForSingleObject(pWin32ThreadContent->hThread, uTimeOut))
			{
				bRet = true;
			}
		}
	}

	return bRet;
}

#endif
