
#pragma once

#include "../Base/IRefCount.h"

class ITask;

/**
** @brief 工作流接口
*/
class NIER_API IWorkflow : public IRefCount
{
public:

	/**
	** @brief 添加任务到工作流
	*/
	virtual bool AddTask(ITask * pTask) = 0;

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
