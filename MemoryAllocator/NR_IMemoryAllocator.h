
#pragma once

#include "../Base/NR_IRefCount.h"

/**
** @brief �ڴ����ӿ�
*/
class NR_IMemoryAllocator : public NR_IRefCount
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
