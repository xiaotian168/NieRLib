
#pragma once

class IWorkflow;

/**
** @brief ������������ӿ�
*/
class NIER_API IWorkflowDesigner : public IRefCount
{
public:

	/**
	** @brief ����������
	*/
	virtual IWorkflow * BuildWorkflow(void) = 0;
};
