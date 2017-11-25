
#define _NIER_API

#include "ThreadTool.h"
#include "ThreadManagerFactory.h"
#include "IThreadManager.h"
#include "IThread.h"

class CThreadHelper
{
public:

	inline CThreadHelper()
	{
		pThreadManager = MakeThreadManagerByOSPlatform();
	}

	inline ~CThreadHelper()
	{
		SAFE_RELEASE(pThreadManager);
	}

public:

	static IThreadManager * pThreadManager;
};

IThreadManager * CThreadHelper::pThreadManager = 0;
CThreadHelper ThreadHelper;

IThread::IDType GetCallerThreadID(void)
{
	IThread::IDType ID = 0;
	IThread::IDType IDTemp = 0;

	if (CThreadHelper::pThreadManager)
	{
		auto pThread = CThreadHelper::pThreadManager->GetCurrentThread();
		if (pThread)
		{
			if (pThread->GetThreadID(IDTemp))
			{
				ID = IDTemp;
			}

			SAFE_RELEASE(pThread);
		}
	}

	return ID;
}

IThread * GetCallerThread(void)
{
	if (CThreadHelper::pThreadManager)
	{
		return CThreadHelper::pThreadManager->GetCurrentThread();
	}

	return 0;
}
