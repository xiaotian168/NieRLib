
#pragma once

#include "../Base/IRefCount.h"

/**
** @brief ����ӿ�
*/
class NIER_API ITask : public IRefCount
{
public:

	/**
	** @brief ִ������
	*/
	virtual bool Execute(void) = 0;
};
