
#include "NR_CWin32Application.h"
#include "NR_CWin32ApplicationStartupParam.h"
#include "NR_IApplicationEventReceiver.h"
#include "../Window/NR_CWin32Window.h"

#if defined NR_PLATFORM_WIN32

static const wchar_t * g_pszWndClassName = L"NRWndClassW";

LRESULT CALLBACK NR_WndMsgProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	static NR_CWin32Application * pApp = 0;

	if (WM_CREATE == uMsg)
	{
		auto pCreateStruct = reinterpret_cast<LPCREATESTRUCTW>(lParam);
		if (pCreateStruct)
		{
			pApp = static_cast<NR_CWin32Application *>(pCreateStruct->lpCreateParams);
		}
	}

	if (pApp)
	{
		pApp->OnWndMsgProc(hWnd, uMsg, wParam, lParam);
	}

	return DefWindowProcW(hWnd, uMsg, wParam, lParam);
}

NR_CWin32Application * NR_CWin32Application::Make(void)
{
	return new NR_CWin32Application();
}

NR_CWin32Application::NR_CWin32Application()
{
}

NR_CWin32Application::~NR_CWin32Application()
{

}

bool NR_CWin32Application::Init(NR_IApplicationStartupParam * pStartupParam, NR_IApplicationEventReceiver * pEventReceiver)
{
	bool bRet = false;

	if (pStartupParam)
	{
		m_pStartupParam = pStartupParam;
		NR_SAFE_ADDREF(m_pStartupParam);

		m_pEventReceiver = pEventReceiver;
		NR_SAFE_ADDREF(m_pEventReceiver);

		if (RegisterWindowClassW())
		{
			bRet = true;
		}
	}

	return bRet;
}

void NR_CWin32Application::Uninit(void)
{
	for (auto pWnd : m_WindowList)
	{
		NR_SAFE_RELEASE(pWnd);
	}
	m_WindowList.clear();

	NR_SAFE_RELEASE(m_pStartupParam);
	NR_SAFE_RELEASE(m_pEventReceiver);
}

bool NR_CWin32Application::Run(void)
{
	bool bRet = false;
	MSG WndMsg = { 0 };

	if (m_WindowList.size())
	{
		while (GetMessageW(&WndMsg, 0, 0, 0))
		{
			TranslateMessage(&WndMsg);
			DispatchMessageW(&WndMsg);
		}

		bRet = true;
	}

	return bRet;
}

NR_IWindow * NR_CWin32Application::MakeWindowW(const wchar_t * pszTitle, const int nPosX, const int nPosY, const unsigned int uWidth, const unsigned int uHeight)
{
	auto pWnd = NR_CWin32Window::Make();
	if (pWnd)
	{
		if (pWnd->MakeWindowW(g_pszWndClassName, WS_SYSMENU | WS_CAPTION | WS_MINIMIZEBOX | WS_MAXIMIZEBOX, 0, pszTitle, nPosX, nPosY, uWidth, uHeight, this, m_pStartupParam, m_pEventReceiver))
		{
			m_WindowList.push_back(pWnd);
			NR_SAFE_ADDREF(pWnd);
		}
		else
		{
			NR_SAFE_RELEASE(pWnd);
		}
	}	

	return pWnd;
}

LRESULT NR_CWin32Application::OnWndMsgProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	for (auto pWnd : m_WindowList)
	{
		auto pWin32Wnd = dynamic_cast<NR_CWin32Window *>(pWnd);
		if (pWin32Wnd && hWnd == pWin32Wnd->GetWndHandle())
		{
			pWin32Wnd->OnWndMsgProc(uMsg, wParam, lParam);

			if (WM_DESTROY == uMsg)
			{
				m_WindowList.remove(pWin32Wnd);
				NR_SAFE_RELEASE(pWin32Wnd);

				if (0 == m_WindowList.size())
				{
					PostQuitMessage(0);
				}

				break;
			}
		}
	}

	return 0;
}

bool NR_CWin32Application::RegisterWindowClassW(void)
{
	bool bRet = false;
	WNDCLASSEXW WndCls = { 0 };

	WndCls.cbSize = sizeof(WndCls);
	WndCls.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	WndCls.hCursor = LoadCursor(0, IDC_ARROW);
	WndCls.hIcon = LoadIcon(0, IDI_APPLICATION);
	WndCls.hInstance = GetModuleHandleW(0);
	WndCls.lpfnWndProc = NR_WndMsgProc;
	WndCls.lpszClassName = g_pszWndClassName;
	WndCls.style = CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS;

	if (RegisterClassExW(&WndCls))
	{
		bRet = true;
	}

	return bRet;
}

#endif
