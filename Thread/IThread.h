
#pragma once

#include "../Base/IRefCount.h"

/**
** @brief 线程接口
*/
class IThread : public IRefCount
{
public:

	typedef unsigned long IDType;

public:

	/**
	** @brief 获取线程 ID
	*/
	virtual bool GetThreadID(IDType & ID) = 0;

	/**
	** @brief 关闭线程
	*/
	virtual bool ShutdownThread(const unsigned int uExitCode) = 0;
};
