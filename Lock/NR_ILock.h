
#pragma once

#include "../Base/NR_IRefCount.h"

#ifndef SAFE_LOCK
#	define SAFE_LOCK(_Lock) { if(_Lock) _Lock->Lock() }
#endif

#ifndef SAFE_UNLOCK
#	define SAFE_UNLOCK(_Lock) { if(_Lock) _Lock->Unlock() }
#endif

/**
** @brief �������ӿ�
*/
class NR_ILock : public NR_IRefCount
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
