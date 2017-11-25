
#pragma once

#include "../Base/IRefCount.h"

/**
** @brief 进程接口
*/
class IProcess : public IRefCount
{
public:

	typedef unsigned int IDType;

public:

	/**
	** @brief 获取进程 ID
	*/
	virtual bool GetProcessID(IDType & ID) = 0;

	/**
	** @brief 获取进程名
	*/
	virtual bool GetProcessNameW(wchar_t * pszName, const unsigned int uSize) = 0;

	/**
	** @brief 关闭进程
	*/
	virtual bool ShutdownProcess(const unsigned int uExitCode) = 0;
};
