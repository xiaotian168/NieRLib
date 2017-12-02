
#pragma once

class NR_IWorkflow;

/**
** @brief 工作流设计器接口
*/
class NR_API NR_IWorkflowDesigner : public NR_IRefCount
{
public:

	/**
	** @brief 创建工作流
	*/
	virtual NR_IWorkflow * BuildWorkflow(void) = 0;
};
