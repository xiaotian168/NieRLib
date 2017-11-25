
#define _NIER_API

#include "ArchiverFactory.h"
#include "CZipArchiverUnpacker.h"

IArchiverUnpacker * MakeWin32ZipArchiverUnpacker(void)
{
	return CZipArchiverUnpacker::Make();
}
