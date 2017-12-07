
#pragma once

#include "NR_IApplication.h"

#if defined NR_PLATFORM_WIN32

class NR_CWin32Application : public NR_IApplication
{
public:

	static NR_CWin32Application * Make(void);

protected:

	NR_CWin32Application();

	~NR_CWin32Application();

public:

	bool Init(NR_IApplicationStartupParam * pStartupParam, NR_IApplicationEventReceiver * pEventReceiver) override;

	void Uninit(void) override;

	bool Run(void) override;

	NR_IWindow * MakeWindowW(const wchar_t * pszTitle, const int nPosX, const int nPosY, const unsigned int uWidth, const unsigned int uHeight) override;

public:

	LRESULT OnWndMsgProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

private:

	bool RegisterWindowClassW(void);

private:

	NR_IApplicationStartupParam * m_pStartupParam{ 0 };
	NR_IApplicationEventReceiver * m_pEventReceiver{ 0 };
	std::list<NR_IWindow *> m_WindowList;
};

#endif
