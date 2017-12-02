
#pragma once

#include "../Base/NR_IRefCount.h"

class NR_IProcess;

/**
** @brief 进程管理接口
*/
class NR_IProcessManager : public NR_IRefCount
{
public:

	/**
	** @brief 获取当前进程列表
	*/
	virtual bool QueryProcessList(std::list<NR_IProcess *> & ProcessList) = 0;

	/**
	** @brief 获取当前进程
	*/
	virtual NR_IProcess * GetCurrentProcess(void) = 0;
};
