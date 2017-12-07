
#pragma once

#include "NR_IWindow.h"

#if defined NR_PLATFORM_WIN32

class NR_CWin32Window : public NR_IWindow
{
public:

	friend class NR_CWin32Application;

	static NR_CWin32Window * Make(void);

protected:

	NR_CWin32Window();

	~NR_CWin32Window();

public:

	bool Hide(void) override;

	bool Show(void) override;

	bool SetTitleW(const wchar_t * pszTitle) override;

private:

	bool MakeWindowW(const wchar_t * pszClassName, const unsigned int uWndStyle, const unsigned int uWndStyleEx, const wchar_t * pszTitle, const int nPosX, const int nPosY, const unsigned int uWidth, const unsigned int uHeight, void * pCreateParam);

private:

	HWND m_hWnd{ 0 };
};

#endif
