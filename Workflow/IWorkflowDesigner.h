
#pragma once

class IWorkflow;

/**
** @brief ������������ӿ�
*/
class IWorkflowDesigner : public IRefCount
{
public:

	/**
	** @brief ����������
	*/
	virtual IWorkflow * BuildWorkflow(void) = 0;
};
