
#pragma once

#include "../Base/IRefCount.h"

/**
** @brief ����ӿ�
*/
class ITask : public IRefCount
{
public:

	/**
	** @brief ִ������
	*/
	virtual bool Execute(void) = 0;
};
