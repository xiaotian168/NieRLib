
#pragma once

#include "../Base/NR_IRefCount.h"

/**
** @brief 应用程序启动参数接口
*/
class NR_IApplicationStartupParam : public NR_IRefCount
{
public:

	virtual void dump(void) = 0;
};
