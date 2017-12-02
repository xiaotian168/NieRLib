
#pragma once

#include "../Base/NR_IRefCount.h"

class NR_IArchiverItem;

/**
** @brief 归档文件元素枚举器接口
*/
class NR_IArchiverItemEnumerator : public NR_IRefCount
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
	virtual NR_IArchiverItem * GetCurrentItem(void) = 0;
};
