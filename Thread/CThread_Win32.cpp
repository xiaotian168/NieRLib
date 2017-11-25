
#define _NIER_API

#include "CThread.h"

#if defined NIER_PLATFORM_WIN32

DWORD GlobalThread(LPVOID pParam)
{
	CThread * pThread = static_cast<CThread *>(pParam);
	if (pThread)
	{
		pThread->Run();
	}

	return 0;
}

class CWin32ThreadContent : public CThread::CThreadContent
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

CThread::CThread()
{
	m_pThreadContent = new CWin32ThreadContent();
}

CThread::~CThread()
{
	if (m_pThreadContent)
	{
		delete m_pThreadContent;
		m_pThreadContent = 0;
	}
}

bool CThread::CreateThread(void)
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

bool CThread::TerminateThread(void)
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

bool CThread::PauseThread(void)
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

bool CThread::ResumeThread(void)
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

bool CThread::Wait(const unsigned int uTimeOut)
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
