
#pragma once

#include "../NieRLibConfig.h"

class NR_IArchiverUnpacker;

#if defined NR_PLATFORM_WIN32

/**
** @brief ���� Win32 Zip �鵵��
** @return Win32 Zip �鵵��
*/
NR_CAPI NR_IArchiverUnpacker * NR_MakeWin32ZipArchiverUnpacker(void);

#endif

/**
** @brief �Զ����ݵ���������ƽ̨������ Zip �鵵��
** @return Zip �鵵��
*/
NR_CAPI NR_IArchiverUnpacker * NR_MakeZipArchiverUnpackerByOSPlatform(void);
