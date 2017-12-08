
#pragma once

#include "NR_ITaskBarInfo.h"

#if defined NR_PLATFORM_WIN32

class NR_CWin32TaskBarInfo : public NR_ITaskBarInfo
{
public:

	static NR_CWin32TaskBarInfo * Make(void);

protected:

	NR_CWin32TaskBarInfo();

	~NR_CWin32TaskBarInfo();

public:

	bool GetBoundBoxRectInDesktop(int & nPosX, int & nPosY, int & nWidth, int & nHeight) override;

	bool GetEdge(NR_TaskBarEdge & Edge) override;
};

#endif
