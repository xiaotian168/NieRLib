
#pragma once

#include "../NieRLibConfig.h"

class ILibraryManager;

NIER_CAPI ILibraryManager * MakeWin32LibraryManager(void);

NIER_CAPI ILibraryManager * MakeLibraryManagerByOSPlatform(void);
