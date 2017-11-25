
#pragma once

#include "../Base/IRefCount.h"

class IArchiverItem;

/**
** @brief 归档文件元素枚举器接口
*/
class IArchiverItemEnumerator : public IRefCount
{
public:

	/**
	** @brief 开始枚举
	*/
	virtual bool BeginEnum(void) = 0;

	/**
	** @brief 停止枚举
	*/
	virtual bool EndEnum(void) = 0;

	/**
	** @brief 下一个元素
	*/
	virtual bool NextItem(void) = 0;

	/**
	** @brief 获取当前元素
	*/
	virtual IArchiverItem * GetCurrentItem(void) = 0;
};
