
#pragma once

#include "../Base/NR_IRefCount.h"

class NR_ITask;

/**
** @brief 工作流接口
*/
class NR_API NR_IWorkflow : public NR_IRefCount
{
public:

	/**
	** @brief 添加任务到工作流
	*/
	virtual bool AddTask(NR_ITask * pTask) = 0;

	/**
	** @brief 从工作流移除所有任务
	*/
	virtual bool RemoveAllTask(void) = 0;

	/**
	** @brief 执行工作流
	*/
	virtual bool RunWorkflow(void) = 0;

	/**
	** @brief 停止工作流
	*/
	virtual bool StopWorkflow(void) = 0;
};
