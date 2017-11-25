
#pragma once

#include "../Base/IRefCount.h"

/**
** @brief �������ӿ�
*/
class ILock : public IRefCount
{
public:

	/**
	** @brief ��
	*/
	virtual bool Lock(void) = 0;

	/**
	** @brief ����
	*/
	virtual bool Unlock(void) = 0;
};
