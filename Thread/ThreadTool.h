
#pragma once

#include "../NieRLibConfig.h"
#include "IThread.h"

NIER_CAPI IThread::IDType GetCallerThreadID(void);

NIER_CAPI IThread * GetCallerThread(void);
