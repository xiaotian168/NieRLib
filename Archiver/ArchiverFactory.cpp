
#define _NIER_API

#include "ArchiverFactory.h"
#include "Win32ZipArchiverUnpacker/CZipArchiverUnpacker.h"

#if defined NIER_PLATFORM_WIN32

IArchiverUnpacker * MakeWin32ZipArchiverUnpacker(void)
{
	return CZipArchiverUnpacker::Make();
}

#endif
