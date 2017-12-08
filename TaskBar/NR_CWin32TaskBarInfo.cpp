
#include "NR_CWin32TaskBarInfo.h"

#if defined NR_PLATFORM_WIN32

NR_CWin32TaskBarInfo * NR_CWin32TaskBarInfo::Make(void)
{
	return new NR_CWin32TaskBarInfo();
}

NR_CWin32TaskBarInfo::NR_CWin32TaskBarInfo()
{

}

NR_CWin32TaskBarInfo::~NR_CWin32TaskBarInfo()
{

}

bool NR_CWin32TaskBarInfo::GetBoundBoxRectInDesktop(int & nPosX, int & nPosY, int & nWidth, int & nHeight)
{
	bool bRet = false;
	RECT rcWndShell_TrayWnd = { 0 };
	
	const auto hWndDesktop = GetDesktopWindow();
	if (IsWindow(hWndDesktop))
	{
		const auto hWndShell_TrayWnd = FindWindowExW(hWndDesktop, 0, L"Shell_TrayWnd", 0);
		if (IsWindow(hWndShell_TrayWnd))
		{
			if (GetWindowRect(hWndShell_TrayWnd, &rcWndShell_TrayWnd))
			{
				nPosX = rcWndShell_TrayWnd.left;
				nPosY = rcWndShell_TrayWnd.top;
				nWidth = rcWndShell_TrayWnd.right - rcWndShell_TrayWnd.left;
				nHeight = rcWndShell_TrayWnd.bottom - rcWndShell_TrayWnd.top;

				bRet = true;
			}
		}
	}

	return bRet;
}

bool NR_CWin32TaskBarInfo::GetEdge(NR_TaskBarEdge & Edge)
{
	bool bRet = false;
	APPBARDATA AppBarData = { 0 };

	AppBarData.cbSize = sizeof(AppBarData);

	if (SHAppBarMessage(ABM_GETTASKBARPOS, &AppBarData))
	{
		if (ABE_TOP == AppBarData.uEdge)
		{
			Edge = eTaskBarEdge_Top;
		}
		else if (ABE_BOTTOM == AppBarData.uEdge)
		{
			Edge = eTaskBarEdge_Bottom;
		}
		else if (ABE_LEFT == AppBarData.uEdge)
		{
			Edge = eTaskBarEdge_Left;
		}
		else if (ABE_RIGHT == AppBarData.uEdge)
		{
			Edge = eTaskBarEdge_Right;
		}

		bRet = true;
	}

	return bRet;
}

#endif
