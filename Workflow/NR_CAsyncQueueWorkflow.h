
#pragma once

#include "NR_IWorkflow.h"
#include "../Thread/NR_CThread.h"
#include "../Lock/NR_ILock.h"

class NR_ILock;

/**
** @brief 异步串行工作流
*/
class NR_CAsyncQueueWorkflow : public NR_IWorkflow, public NR_CThread
{
public:

	static NR_CAsyncQueueWorkflow * Make(void);

protected:

	NR_CAsyncQueueWorkflow();

	~NR_CAsyncQueueWorkflow();

public:

	bool AddTask(NR_ITask * pTask) override;

	bool RemoveAllTask(void) override;

	bool RunWorkflow(void) override;

	bool StopWorkflow(void) override;

private:

	void Run(void) override;

	inline void LockTaskList(void)
	{
		if (m_pLockTaskList)
		{
			m_pLockTaskList->Lock();
		}
	}

	inline void UnlockTaskList(void)
	{
		if (m_pLockTaskList)
		{
			m_pLockTaskList->Unlock();
		}
	}

private:

	bool m_bDone{ false };
	NR_ILock * m_pLockTaskList{ 0 };
	std::list<NR_ITask *> m_TaskList;
};
