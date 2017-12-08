
#define _NR_API

#include "NR_TaskBarTool.h"
#include "NR_TaskBarFactory.h"

class NR_CTaskBarInfoHelper
{
public:

	inline NR_CTaskBarInfoHelper()
	{
		if (!pTaskBarInfo)
		{
			pTaskBarInfo = NR_MakeTaskBarInfoByOSPlatform();
		}
	}

	inline ~NR_CTaskBarInfoHelper()
	{
		NR_SAFE_RELEASE(pTaskBarInfo);
	}

public:

	static NR_ITaskBarInfo * pTaskBarInfo;
};

NR_ITaskBarInfo * NR_CTaskBarInfoHelper::pTaskBarInfo = 0;
NR_CTaskBarInfoHelper TaskBarInfoHelper;

bool NR_GetTaskBarRectInDesktop(int & nPosX, int & nPosY, int & nWidth, int & nHeight)
{
	bool bRet = false;

	if (NR_CTaskBarInfoHelper::pTaskBarInfo)
	{
		if (NR_CTaskBarInfoHelper::pTaskBarInfo->GetBoundBoxRectInDesktop(nPosX, nPosY, nWidth, nHeight))
		{
			bRet = true;
		}
	}

	return bRet;
}

bool NR_GetTaskBarEdge(NR_ITaskBarInfo::NR_TaskBarEdge & Edge)
{
	bool bRet = false;

	if (NR_CTaskBarInfoHelper::pTaskBarInfo)
	{
		if (NR_CTaskBarInfoHelper::pTaskBarInfo->GetEdge(Edge))
		{
			bRet = true;
		}
	}

	return bRet;
}
