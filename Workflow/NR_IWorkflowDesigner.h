
#pragma once

class NR_IWorkflow;

/**
** @brief ������������ӿ�
*/
class NR_API NR_IWorkflowDesigner : public NR_IRefCount
{
public:

	/**
	** @brief ����������
	*/
	virtual NR_IWorkflow * BuildWorkflow(void) = 0;
};
