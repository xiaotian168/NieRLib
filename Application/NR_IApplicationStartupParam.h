
#pragma once

#include "../Base/NR_IRefCount.h"

/**
** @brief Ӧ�ó������������ӿ�
*/
class NR_IApplicationStartupParam : public NR_IRefCount
{
public:

	virtual void dump(void) = 0;
};
