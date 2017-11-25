
#define _NIER_API

#include "ArchiverFactory.h"
#include "CZipArchiverUnpacker.h"

IArchiverUnpacker * MakeWin32ZipArchiverUnpacker(void)
{
#if defined NIER_PLATFORM_WIN32
	return CZipArchiverUnpacker::Make();
#endif

	return 0;
}
