
#include "NR_CWin32Application.h"
#include "NR_CWin32ApplicationStartupParam.h"
#include "../Window/NR_CWin32Window.h"

#if defined NR_PLATFORM_WIN32

static const wchar_t * g_pszWndClassName = L"NRWndClassW";

LRESULT CALLBACK NR_WndMsgProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	static NR_CWin32Application * pApp = 0;

	if (WM_CREATE == uMsg)
	{
		auto pCreateStruct = reinterpret_cast<LPCREATESTRUCTW>(wParam);
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

bool NR_CWin32Application::InitApplication(NR_IApplicationStartupParam * pStartupParam)
{
	bool bRet = false;

	if (pStartupParam)
	{
		m_pStartupParam = pStartupParam;
		m_pStartupParam->AddRef();

		if (RegisterWindowClassW())
		{

		}
	}

	return bRet;
}

void NR_CWin32Application::UninitApplication(void)
{
	NR_SAFE_RELEASE(m_pStartupParam);
}

NR_IWindow * NR_CWin32Application::MakeWindowW(const wchar_t * pszTitle, const int nPosX, const int nPosY, const unsigned int uWidth, const unsigned int uHeight)
{
	auto pWnd = NR_CWin32Window::Make();
	if (pWnd)
	{
		m_WindowList.push_back(pWnd);
	}	

	return pWnd;
}

LRESULT NR_CWin32Application::OnWndMsgProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	return 0;
}

bool NR_CWin32Application::RegisterWindowClassW(void)
{
	bool bRet = false;
	WNDCLASSEXW WndCls = { 0 };

	return bRet;
}

#endif
