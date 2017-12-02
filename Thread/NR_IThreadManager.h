
#pragma once

#include "../Base/NR_IRefCount.h"

class NR_IThread;

/**
** @brief 线程管理器接口
*/
class NR_IThreadManager : public NR_IRefCount
{
public:

	/**
	** @brief 获取调用者线程接口
	*/
	virtual NR_IThread * GetCurrentThread(void) = 0;
};
