
#pragma once

class IWorkflow;

/**
** @brief 工作流设计器接口
*/
class IWorkflowDesigner : public IRefCount
{
public:

	/**
	** @brief 创建工作流
	*/
	virtual IWorkflow * BuildWorkflow(void) = 0;
};
