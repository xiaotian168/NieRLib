
#pragma once

#include "../NieRLibConfig.h"

class NR_IArchiverUnpacker;

#if defined NIER_PLATFORM_WIN32

/**
** @brief ���� Win32 Zip �鵵��
** @return Win32 Zip �鵵��
*/
NIER_CAPI NR_IArchiverUnpacker * NR_MakeWin32ZipArchiverUnpacker(void);

#endif
