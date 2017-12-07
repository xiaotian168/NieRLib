
#pragma once

#include "NR_IApplicationStartupParam.h"

#if defined NR_PLATFORM_WIN32

class NR_CWin32ApplicationStartupParam : public NR_IApplicationStartupParam
{
public:

	static NR_CWin32ApplicationStartupParam * Make(const HINSTANCE hInst, const HINSTANCE hInstPrev, const wchar_t * pszCmdLine, const int nShowCmd);

protected:

	NR_CWin32ApplicationStartupParam(const HINSTANCE hInst, const HINSTANCE hInstPrev, const wchar_t * pszCmdLine, const int nShowCmd);

	~NR_CWin32ApplicationStartupParam();

public:

	void dump(void) override;

public:

	inline HINSTANCE GetApplicationHandle(void) const
	{
		return m_hInst;
	}

	inline const wchar_t * GetCmdLineW(void) const
	{
		return m_strCmdLine.c_str();
	}

	inline int GetCmdShow(void) const
	{
		return m_nShowCmd;
	}

private:

	HINSTANCE m_hInst{ 0 };
	HINSTANCE m_hInstPrev{ 0 };
	std::wstring m_strCmdLine;
	int m_nShowCmd{ 0 };
};

#endif
