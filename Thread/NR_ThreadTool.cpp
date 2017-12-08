
#define _NR_API

#include "NR_ThreadTool.h"
#include "NR_ThreadManagerFactory.h"
#include "NR_IThreadManager.h"
#include "NR_IThread.h"

class NR_CThreadHelper
{
public:

	inline NR_CThreadHelper()
	{
		pThreadManager = NR_MakeThreadManagerByOSPlatform();
	}

	inline ~NR_CThreadHelper()
	{
		NR_SAFE_RELEASE(pThreadManager);
	}

public:

	static NR_IThreadManager * pThreadManager;
};

NR_IThreadManager * NR_CThreadHelper::pThreadManager = 0;
NR_CThreadHelper ThreadHelper;

NR_IThread::IDType NR_GetCallerThreadID(void)
{
	NR_IThread::IDType ID = 0;
	NR_IThread::IDType IDTemp = 0;

	if (NR_CThreadHelper::pThreadManager)
	{
		auto pThread = NR_CThreadHelper::pThreadManager->GetCurrentThread();
		if (pThread)
		{
			if (pThread->GetThreadID(IDTemp))
			{
				ID = IDTemp;
			}

			NR_SAFE_RELEASE(pThread);
		}
	}

	return ID;
}

NR_IThread * NR_GetCallerThread(void)
{
	if (NR_CThreadHelper::pThreadManager)
	{
		return NR_CThreadHelper::pThreadManager->GetCurrentThread();
	}

	return 0;
}
