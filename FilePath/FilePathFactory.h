
#pragma once

#include "../NieRLibConfig.h"

class IFilePath;

#if defined NIER_PLATFORM_WIN32

NIER_CAPI IFilePath * MakeWin32FilePath(void);

#endif
