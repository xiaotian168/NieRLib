
#include "NR_CWin32ApplicationStartupParam.h"

#if defined NR_PLATFORM_WIN32

NR_CWin32ApplicationStartupParam * NR_CWin32ApplicationStartupParam::Make(const HINSTANCE hInst, const HINSTANCE hInstPrev, const wchar_t * pszCmdLine, const int nShowCmd)
{
	return new NR_CWin32ApplicationStartupParam(hInst, hInstPrev, pszCmdLine, nShowCmd);
}

NR_CWin32ApplicationStartupParam::NR_CWin32ApplicationStartupParam(const HINSTANCE hInst, const HINSTANCE hInstPrev, const wchar_t * pszCmdLine, const int nShowCmd)
{
	m_hInst = hInst;
	m_hInstPrev = hInstPrev;
	m_strCmdLine = pszCmdLine;
	m_nShowCmd = nShowCmd;
}

NR_CWin32ApplicationStartupParam::~NR_CWin32ApplicationStartupParam()
{

}

void NR_CWin32ApplicationStartupParam::dump(void)
{

}

#endif
