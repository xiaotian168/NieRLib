
#pragma once

#include "../Base/IRefCount.h"

/**
** @brief »¥³âËø½Ó¿Ú
*/
class ILock : public IRefCount
{
public:

	/**
	** @brief Ëø
	*/
	virtual bool Lock(void) = 0;

	/**
	** @brief ½âËø
	*/
	virtual bool Unlock(void) = 0;
};
