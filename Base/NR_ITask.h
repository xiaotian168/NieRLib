
#pragma once

#include "../Base/NR_IRefCount.h"

/**
** @brief ����ӿ�
*/
class NR_API NR_ITask : public NR_IRefCount
{
public:

	/**
	** @brief ִ������
	*/
	virtual bool Execute(void) = 0;
};
