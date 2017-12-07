
#pragma once

#include "NR_IApplicationStartupParam.h"

#if defined NR_PLATFORM_WIN32

class NR_CWin32ApplicationStartupParam : public NR_IApplicationStartupParam
{
public:

	void dump(void) override;

public:

	inline HINSTANCE GetApplicationHandle(void) const
	{
		return m_hInstApp;
	}

	inline const wchar_t * GetCmdLineW(void) const
	{
		return m_strCmdLine.c_str();
	}

	inline int GetCmdShow(void) const
	{
		return m_nCmdShow;
	}

private:

	HINSTANCE m_hInstApp{ 0 };
	HINSTANCE m_hInstPrev{ 0 };
	std::wstring m_strCmdLine;
	int m_nCmdShow{ 0 };
};

#endif
