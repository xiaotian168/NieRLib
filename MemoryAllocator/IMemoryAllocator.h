
#pragma once

#include "../Base/IRefCount.h"

/**
** @brief 内存分配接口
*/
class IMemoryAllocator : public IRefCount
{
public:

	/**
	** @brief 分配指定大小的内存（单位：字节）
	*/
	virtual void * Alloc(const unsigned int uBytes) = 0;

	/**
	** @brief 重新分配指定大小的内存（单位：字节）
	*/
	virtual void * Realloc(void * pBuffer, const unsigned int uBytes) = 0;

	/**
	** @brief 释放指定内存
	*/
	virtual void Free(void * pBuffer) = 0;
};
