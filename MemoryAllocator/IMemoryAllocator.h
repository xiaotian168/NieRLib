
#pragma once

#include "../Base/IRefCount.h"

/**
** @brief �ڴ����ӿ�
*/
class IMemoryAllocator : public IRefCount
{
public:

	/**
	** @brief ����ָ����С���ڴ棨��λ���ֽڣ�
	*/
	virtual void * Alloc(const unsigned int uBytes) = 0;

	/**
	** @brief ���·���ָ����С���ڴ棨��λ���ֽڣ�
	*/
	virtual void * Realloc(void * pBuffer, const unsigned int uBytes) = 0;

	/**
	** @brief �ͷ�ָ���ڴ�
	*/
	virtual void Free(void * pBuffer) = 0;
};
