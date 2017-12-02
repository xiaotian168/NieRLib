
#define _NIER_API

#include "NR_ArchiverFactory.h"
#include "Win32ZipArchiverUnpacker/NR_CZipArchiverUnpacker.h"

#if defined NIER_PLATFORM_WIN32

NR_IArchiverUnpacker * NR_MakeWin32ZipArchiverUnpacker(void)
{
	return NR_CZipArchiverUnpacker::Make();
}

#endif
