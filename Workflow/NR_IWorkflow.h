
#pragma once

#include "../Base/NR_IRefCount.h"

class NR_ITask;

/**
** @brief �������ӿ�
*/
class NR_API NR_IWorkflow : public NR_IRefCount
{
public:

	/**
	** @brief ������񵽹�����
	*/
	virtual bool AddTask(NR_ITask * pTask) = 0;

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
