
#pragma once

#include "../Base/NR_IRefCount.h"

/**
** @brief 归档文件元素接口
*/
class NR_IArchiverItem : public NR_IRefCount
{
public:

	/**
	** @brief 获取元素名称
	*/
	virtual bool GetItemNameW(wchar_t * pszName, const unsigned int uSize) = 0;

	/**
	** @brief 获取元素是否目录
	*/
	virtual bool IsItemDirectory(void) = 0;
};
