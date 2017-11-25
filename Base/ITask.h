
#pragma once

#include "../Base/IRefCount.h"

/**
** @brief 任务接口
*/
class NIER_API ITask : public IRefCount
{
public:

	/**
	** @brief 执行任务
	*/
	virtual bool Execute(void) = 0;
};
