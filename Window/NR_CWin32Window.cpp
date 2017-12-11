
#include "NR_CWin32Window.h"
#include "../Application/NR_CWin32ApplicationStartupParam.h"
#include "../Application/NR_IApplicationEventReceiver.h"
#include "../Application/NR_ApplicationEvent.h"

#if defined NR_PLATFORM_WIN32

NR_CWin32Window * NR_CWin32Window::Make(void)
{
	return new NR_CWin32Window();
}

NR_CWin32Window::NR_CWin32Window()
{

}

NR_CWin32Window::~NR_CWin32Window()
{
	NR_SAFE_RELEASE(m_pStartupParam);
	NR_SAFE_RELEASE(m_pEventReceiver);
}

bool NR_CWin32Window::Hide(void)
{
	if (IsWindow(m_hWnd))
	{
		ShowWindow(m_hWnd, SW_HIDE);

		return true;
	}

	return false;
}

bool NR_CWin32Window::Show(void)
{
	bool bRet = false;

	if (IsWindow(m_hWnd))
	{
		if (m_bFirstTimeShow)
		{
			if (m_pStartupParam)
			{
				auto pWin32StartupParam = dynamic_cast<NR_CWin32ApplicationStartupParam *>(m_pStartupParam);
				if (pWin32StartupParam)
				{
					ShowWindow(m_hWnd, pWin32StartupParam->GetCmdShow());
					bRet = true;
				}
			}
		}
		else
		{
			ShowWindow(m_hWnd, SW_SHOWNORMAL);
			m_bFirstTimeShow = false;
			bRet = true;
		}
	}

	return bRet;
}

bool NR_CWin32Window::SetTitleW(const wchar_t * pszTitle)
{
	if (IsWindow(m_hWnd) && pszTitle)
	{
		if (SetWindowTextW(m_hWnd, pszTitle))
		{
			return true;
		}
	}

	return false;
}

bool NR_CWin32Window::MakeWindowW(const wchar_t * pszClassName, const unsigned int uWndStyle, const unsigned int uWndStyleEx, const wchar_t * pszTitle, const int nPosX, const int nPosY, const unsigned int uWidth, const unsigned int uHeight, void * pCreateParam, NR_IApplicationStartupParam * pStartupParam, NR_IApplicationEventReceiver * pEventReceiver)
{
	bool bRet = false;

	if (0 == IsWindow(m_hWnd) && pStartupParam)
	{
		m_hWnd = CreateWindowExW(
			uWndStyleEx,
			pszClassName,
			pszTitle,
			uWndStyle,
			nPosX,
			nPosY,
			uWidth,
			uHeight,
			0,
			0,
			0,
			pCreateParam);

		if (IsWindow(m_hWnd))
		{
			m_pStartupParam = pStartupParam;
			NR_SAFE_ADDREF(m_pStartupParam);

			m_pEventReceiver = pEventReceiver;
			NR_SAFE_ADDREF(m_pEventReceiver);

			bRet = true;
		}
	}

	return bRet;
}

LRESULT NR_CWin32Window::OnWndMsgProc(UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	NR_CWindowEvent Event;

	if (m_pEventReceiver)
	{
		if (WM_MOUSEMOVE == uMsg)
		{
			Event.EventType = eWindowEvent_MouseMove;
			Event.nCursorX = LOWORD(lParam);
			Event.nCursorY = HIWORD(lParam);

			m_pEventReceiver->OnWindowEvent(this, &Event);
		}
		else if (WM_MOUSEWHEEL == uMsg)
		{
			Event.EventType = eWindowEvent_MouseWheel;
			Event.nCursorX = LOWORD(lParam);
			Event.nCursorY = HIWORD(lParam);
			Event.bWheelForward = (short)HIWORD(wParam) > 0 ? true : false;

			m_pEventReceiver->OnWindowEvent(this, &Event);
		}
		else if (WM_KEYUP == uMsg)
		{

		}
		else if (WM_KEYDOWN == uMsg)
		{

		}
	}

	return 0;
}

#endif
