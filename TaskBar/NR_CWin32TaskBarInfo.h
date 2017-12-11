
#pragma once

#include "NR_IDockableTaskBarInfo.h"
#include "NR_IHideableTaskBarInfo.h"
#include "NR_IIconSizeableTaskBarInfo.h"

#if defined NR_PLATFORM_WIN32

class NR_CWin32TaskBarInfo : public NR_IDockableTaskBarInfo, public NR_IHideableTaskBarInfo, public NR_IIconSizeableTaskBarInfo
{
public:

	static NR_CWin32TaskBarInfo * Make(void);

protected:

	NR_CWin32TaskBarInfo();

	~NR_CWin32TaskBarInfo();

public:

	bool GetBoundBoxRectInDesktop(int & nPosX, int & nPosY, int & nWidth, int & nHeight) override;

	bool GetEdge(NR_TaskBarEdge & Edge) override;

	bool IsAutoHide(bool & bAutoHide) override;

	bool IsLargeIcon(bool & bIsLargeIcon) override;
};

#endif
