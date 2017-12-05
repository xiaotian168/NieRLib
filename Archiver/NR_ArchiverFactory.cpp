
#define _NR_API

#include "NR_ArchiverFactory.h"
#include "Win32ZipArchiverUnpacker/NR_CZipArchiverUnpacker.h"

#if defined NR_PLATFORM_WIN32

NR_IArchiverUnpacker * NR_MakeWin32ZipArchiverUnpacker(void)
{
	return NR_CZipArchiverUnpacker::Make();
}

#endif

NR_IArchiverUnpacker * NR_MakeZipArchiverUnpackerByOSPlatform(void)
{
#if defined NR_PLATFORM_WIN32
	return NR_CZipArchiverUnpacker::Make();
#endif

	return 0;
}
