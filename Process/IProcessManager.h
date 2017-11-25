
#pragma once

#include "../Base/IRefCount.h"

class IProcess;

/**
** @brief 进程管理接口
*/
class IProcessManager : public IRefCount
{
public:

	/**
	** @brief 获取当前进程列表
	*/
	virtual bool QueryProcessList(std::list<IProcess *> & ProcessList) = 0;
};
