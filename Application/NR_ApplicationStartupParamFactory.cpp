
#define _NR_API

#include "NR_ApplicationStartupParamFactory.h"
#include "NR_CWin32ApplicationStartupParam.h"

#if defined NR_PLATFORM_WIN32

NR_IApplicationStartupParam * NR_MakeWin32ApplicationStartupParam(const HINSTANCE hInst, const HINSTANCE hInstPrev, const wchar_t * pszCmdLine, const int nShowCmd)
{
	return NR_CWin32ApplicationStartupParam::Make(hInstPrev, hInstPrev, pszCmdLine, nShowCmd);
}

#endif
