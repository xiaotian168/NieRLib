
#pragma once

#include "../Base/IRefCount.h"

/**
** @brief 文件枚举结果接口
*/
class IFileEnumResult : public IRefCount
{
public:

	/**
	** @brief 判断是否目录
	*/
	virtual bool IsDirectory(void) const = 0;

	/**
	** @brief 获取后缀名
	*/
	virtual bool GetFileExtW(wchar_t * pszExt, const unsigned int uSize) = 0;

	/**
	** @brief 获取路径
	*/
	virtual bool GetResultPathW(wchar_t * pszPath, const unsigned int uSize) const = 0;
};
