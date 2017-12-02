
#pragma once

#include "../NieRLibConfig.h"

class NR_IArchiverUnpacker;

#if defined NIER_PLATFORM_WIN32

/**
** @brief ´´½¨ Win32 Zip ¹éµµÆ÷
** @return Win32 Zip ¹éµµÆ÷
*/
NIER_CAPI NR_IArchiverUnpacker * NR_MakeWin32ZipArchiverUnpacker(void);

#endif
