
#pragma once

#include "../Base/NR_IRefCount.h"

/**
** @brief 系统目录相关信息接口
*/
class NR_ISystemDirectoryInfo : public NR_IRefCount
{
public:

	/**
	** @brief 获取系统临时目录路径
	*/
	virtual bool GetTempDirectoryW(wchar_t * pszDirectory, const unsigned int uSize) = 0;

	/**
	** @brief 获取系统目录路径
	*/
	virtual bool GetSystemDirectoryW(wchar_t * pszDirectory, const unsigned int uSize) = 0;
};
