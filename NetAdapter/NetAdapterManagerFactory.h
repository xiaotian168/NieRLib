
#pragma once

#include "../NieRLibConfig.h"

class INetAdapterManager;

NIER_CAPI INetAdapterManager * MakeWin32NetAdapterManager(void);

NIER_CAPI INetAdapterManager * MakeNetAdapterNanagerByOSPlatform(void);
