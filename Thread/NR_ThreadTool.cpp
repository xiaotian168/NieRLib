
#define _NIER_API

#include "NR_ThreadTool.h"
#include "NR_ThreadManagerFactory.h"
#include "NR_IThreadManager.h"
#include "NR_IThread.h"

class CThreadHelper
{
public:

	inline CThreadHelper()
	{
		pThreadManager = NR_MakeThreadManagerByOSPlatform();
	}

	inline ~CThreadHelper()
	{
		SAFE_RELEASE(pThreadManager);
	}

public:

	static NR_IThreadManager * pThreadManager;
};

NR_IThreadManager * CThreadHelper::pThreadManager = 0;
CThreadHelper ThreadHelper;

NR_IThread::IDType NR_GetCallerThreadID(void)
{
	NR_IThread::IDType ID = 0;
	NR_IThread::IDType IDTemp = 0;

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

NR_IThread * NR_GetCallerThread(void)
{
	if (CThreadHelper::pThreadManager)
	{
		return CThreadHelper::pThreadManager->GetCurrentThread();
	}

	return 0;
}
