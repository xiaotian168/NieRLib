
#pragma once

#include "../Base/IRefCount.h"

class ITask;

/**
** @brief �������ӿ�
*/
class NIER_API IWorkflow : public IRefCount
{
public:

	/**
	** @brief ������񵽹�����
	*/
	virtual bool AddTask(ITask * pTask) = 0;

	/**
	** @brief �ӹ������Ƴ���������
	*/
	virtual bool RemoveAllTask(void) = 0;

	/**
	** @brief ִ�й�����
	*/
	virtual bool RunWorkflow(void) = 0;

	/**
	** @brief ֹͣ������
	*/
	virtual bool StopWorkflow(void) = 0;
};
