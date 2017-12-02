
#pragma once

#include "../NieRLibConfig.h"

class NR_IArchiverUnpacker;

#if defined NR_PLATFORM_WIN32

/**
** @brief ´´½¨ Win32 Zip ¹éµµÆ÷
** @return Win32 Zip ¹éµµÆ÷
*/
NR_CAPI NR_IArchiverUnpacker * NR_MakeWin32ZipArchiverUnpacker(void);

#endif
