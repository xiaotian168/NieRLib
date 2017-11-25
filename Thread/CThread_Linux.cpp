
#define _NIER_API

#include "CThread.h"

#if defined NIER_PLATFORM_LINUX

#include <assert.h>
#include <unistd.h>
#include <pthread.h>

void * GlobalThread(void * pParam)
{
	CThread * pThread = static_cast<CThread *>(pParam);
	if (pThread)
	{
		pThread->Run();
	}

	return 0;
}

class CLinuxThreadContent : public CThread::CThreadContent
{
public:

	inline CLinuxThreadContent()
	{

	}

public:

	void dummy(void) override
	{

	}

public:

};

CThread::CThread()
{
	m_pThreadContent = new CLinuxThreadContent();
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

	auto pLinuxThreadContent = dynamic_cast<CLinuxThreadContent *>(m_pThreadContent);
	if (pLinuxThreadContent)
	{
		assert(false);
	}

	return bRet;
}

bool CThread::TerminateThread(void)
{
	bool bRet = false;

	auto pLinuxThreadContent = dynamic_cast<CLinuxThreadContent *>(m_pThreadContent);
	if (pLinuxThreadContent)
	{
		assert(false);
	}

	return bRet;
}

bool CThread::PauseThread(void)
{
	bool bRet = false;

	auto pLinuxThreadContent = dynamic_cast<CLinuxThreadContent *>(m_pThreadContent);
	if (pLinuxThreadContent)
	{
		assert(false);
	}

	return bRet;
}

bool CThread::ResumeThread(void)
{
	bool bRet = false;

	auto pLinuxThreadContent = dynamic_cast<CLinuxThreadContent *>(m_pThreadContent);
	if (pLinuxThreadContent)
	{
		assert(false);
	}

	return bRet;
}

bool CThread::Wait(const unsigned int uTimeOut)
{
	bool bRet = false;

	auto pLinuxThreadContent = dynamic_cast<CLinuxThreadContent *>(m_pThreadContent);
	if (pLinuxThreadContent)
	{
		assert(false);
	}

	return bRet;
}

#endif
