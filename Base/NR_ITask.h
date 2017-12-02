
#pragma once

#include "../Base/NR_IRefCount.h"

/**
** @brief 任务接口
*/
class NR_API NR_ITask : public NR_IRefCount
{
public:

	/**
	** @brief 执行任务
	*/
	virtual bool Execute(void) = 0;
};
