
#pragma once

#include "../NieRLibConfig.h"

class NR_IArchiverUnpacker;

#if defined NR_PLATFORM_WIN32

/**
** @brief 创建 Win32 Zip 归档器
** @return Win32 Zip 归档器
*/
NR_CAPI NR_IArchiverUnpacker * NR_MakeWin32ZipArchiverUnpacker(void);

#endif

/**
** @brief 自动根据调用者所在平台，创建 Zip 归档器
** @return Zip 归档器
*/
NR_CAPI NR_IArchiverUnpacker * NR_MakeZipArchiverUnpackerByOSPlatform(void);
