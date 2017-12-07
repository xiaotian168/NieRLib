
#include "NR_CWin32Window.h"

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
	if (IsWindow(m_hWnd))
	{
		ShowWindow(m_hWnd, SW_SHOW);

		return true;
	}

	return false;
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

bool NR_CWin32Window::MakeWindowW(const wchar_t * pszClassName, const unsigned int uWndStyle, const unsigned int uWndStyleEx, const wchar_t * pszTitle, const int nPosX, const int nPosY, const unsigned int uWidth, const unsigned int uHeight, void * pCreateParam)
{
	bool bRet = false;

	if (0 == IsWindow(m_hWnd))
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
			bRet = true;
		}
	}

	return bRet;
}

#endif
