
#pragma once

#include "../NieRLibConfig.h"

class NR_IApplicationStartupParam;

#if defined NR_PLATFORM_WIN32

NR_CAPI NR_IApplicationStartupParam * NR_MakeWin32ApplicationStartupParam(const HINSTANCE hInst, const HINSTANCE hInstPrev, const wchar_t * pszCmdLine, const int nShowCmd);

#endif
