
#pragma once

#include "../NieRLibConfig.h"

class IThreadManager;

NIER_CAPI IThreadManager * MakeWin32ThreadManager(void);

NIER_CAPI IThreadManager * MakeThreadManagerByOSPlatform(void);
