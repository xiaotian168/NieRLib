
#pragma once

#include "../Base/IRefCount.h"

class IThread;

/**
** @brief 线程管理器接口
*/
class IThreadManager : public IRefCount
{
public:

	/**
	** @brief 获取调用者线程接口
	*/
	virtual IThread * GetCurrentThread(void) = 0;
};
