
#define _NIER_API

#include "NR_CThread.h"

#if defined NIER_PLATFORM_LINUX

void * GlobalThread(void * pParam)
{
	NR_CThread * pThread = static_cast<NR_CThread *>(pParam);
	if (pThread)
	{
		pThread->Run();
	}

	return 0;
}

class CLinuxThreadContent : public NR_CThread::CThreadContent
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

NR_CThread::NR_CThread()
{
	m_pThreadContent = new CLinuxThreadContent();
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

	auto pLinuxThreadContent = dynamic_cast<CLinuxThreadContent *>(m_pThreadContent);
	if (pLinuxThreadContent)
	{
		assert(false);
	}

	return bRet;
}

bool NR_CThread::TerminateThread(void)
{
	bool bRet = false;

	auto pLinuxThreadContent = dynamic_cast<CLinuxThreadContent *>(m_pThreadContent);
	if (pLinuxThreadContent)
	{
		assert(false);
	}

	return bRet;
}

bool NR_CThread::PauseThread(void)
{
	bool bRet = false;

	auto pLinuxThreadContent = dynamic_cast<CLinuxThreadContent *>(m_pThreadContent);
	if (pLinuxThreadContent)
	{
		assert(false);
	}

	return bRet;
}

bool NR_CThread::ResumeThread(void)
{
	bool bRet = false;

	auto pLinuxThreadContent = dynamic_cast<CLinuxThreadContent *>(m_pThreadContent);
	if (pLinuxThreadContent)
	{
		assert(false);
	}

	return bRet;
}

bool NR_CThread::Wait(const unsigned int uTimeOut)
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
