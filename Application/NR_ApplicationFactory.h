
#pragma once

#include "../NieRLibConfig.h"

class NR_IApplication;

#if defined NR_PLATFORM_WIN32

NR_CAPI NR_IApplication * NR_MakeWin32Application(void);

#endif
