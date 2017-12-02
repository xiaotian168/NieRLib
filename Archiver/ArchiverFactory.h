
#pragma once

#include "../NieRLibConfig.h"

class IArchiverUnpacker;

#if defined NIER_PLATFORM_WIN32

/**
** @brief ´´½¨ Win32 Zip ¹éµµÆ÷
** @return Win32 Zip ¹éµµÆ÷
*/
NIER_CAPI IArchiverUnpacker * MakeWin32ZipArchiverUnpacker(void);

#endif
