
#include "NR_CAsyncQueueWorkflow.h"
#include "../Lock/NR_LockFactory.h"
#include "../Base/NR_ITask.h"

NR_CAsyncQueueWorkflow * NR_CAsyncQueueWorkflow::Make(void)
{
	return new NR_CAsyncQueueWorkflow();
}

NR_CAsyncQueueWorkflow::NR_CAsyncQueueWorkflow()
{
	m_pLockTaskList = NR_MakeLockByOSPlatform();
}

NR_CAsyncQueueWorkflow::~NR_CAsyncQueueWorkflow()
{
	StopWorkflow();

	SAFE_RELEASE(m_pLockTaskList);
}

bool NR_CAsyncQueueWorkflow::AddTask(NR_ITask * pTask)
{
	bool bRet = false;

	if (pTask)
	{
		pTask->AddRef();

		LockTaskList();
		{
			m_TaskList.push_back(pTask);
		}
		UnlockTaskList();

		bRet = true;
	}

	return bRet;
}

bool NR_CAsyncQueueWorkflow::RemoveAllTask(void)
{
	bool bRet = false;

	LockTaskList();
	{
		for (auto pTask : m_TaskList)
		{
			SAFE_RELEASE(pTask);
		}

		m_TaskList.clear();
	}
	UnlockTaskList();

	return bRet;
}

bool NR_CAsyncQueueWorkflow::RunWorkflow(void)
{
	bool bRet = false;

	if (NR_CThread::CreateThread())
	{
		m_bDone = false;
		bRet = true;
	}

	return bRet;
}

bool NR_CAsyncQueueWorkflow::StopWorkflow(void)
{
	m_bDone = true;

	NR_CThread::Wait(NR_CThread::MaxWaitTimeOut);

	return true;
}

void NR_CAsyncQueueWorkflow::Run(void)
{
	NR_ITask * pTask = 0;

	while (!m_bDone)
	{
		LockTaskList();
		{
			if (m_TaskList.size())
			{
				auto iter = m_TaskList.begin();
				pTask = *iter;
				m_TaskList.erase(iter);
			}
		}
		UnlockTaskList();

		if (pTask)
		{
			pTask->Execute();
			pTask->Release();
			pTask = 0;
		}
		else
		{
			Sleep(50);
		}
	}
}
