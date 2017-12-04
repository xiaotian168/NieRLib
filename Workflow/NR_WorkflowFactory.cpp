
#define _NR_API

#include "NR_WorkflowFactory.h"
#include "NR_CAsyncQueueWorkflow.h"

NR_IWorkflow * NR_MakeAsyncQueueWorkflow(void)
{
	return NR_CAsyncQueueWorkflow::Make();
}
