
#define _NR_API

#include "NR_ApplicationFactory.h"
#include "NR_CWin32Application.h"

#if defined NR_PLATFORM_WIN32

NR_IApplication * NR_MakeWin32Application(void)
{
	return NR_CWin32Application::Make();
}

#endif
