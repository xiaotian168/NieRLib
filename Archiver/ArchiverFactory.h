
#pragma once

#include "../NieRLibConfig.h"

class IArchiverUnpacker;

/**
** @brief ���� Win32 Zip �鵵��
** @return Win32 Zip �鵵��
*/
NIER_CAPI IArchiverUnpacker * MakeWin32ZipArchiverUnpacker(void);
