
#pragma once

#include "../NieRLibConfig.h"

class IArchiverUnpacker;

/**
** @brief ´´½¨ Win32 Zip ¹éµµÆ÷
** @return Win32 Zip ¹éµµÆ÷
*/
NIER_CAPI IArchiverUnpacker * MakeWin32ZipArchiverUnpacker(void);
