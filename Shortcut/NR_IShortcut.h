
#pragma once

#include "../Base/NR_IRefCount.h"

/**
** @brief 快捷方式接口
*/
class NR_IShortcut : public NR_IRefCount
{
public:

	/**
	** @brief 获取快捷方式目标路径
	*/
	virtual bool GetTargetPathW(wchar_t * pszTargetPath, const unsigned int uSize) = 0;

	/**
	** @brief 获取快捷方式路径
	*/
	virtual bool GetPathW(wchar_t * pszPath, const unsigned int uSize) = 0;

	/**
	** @brief 删除快捷方式
	*/
	virtual bool Delete(void) = 0;
};
