
#define _NIER_API

#include "NR_FileSystemFactory.h"
#include "NR_CWin32FileSystem.h"

#if defined NIER_PLATFORM_WIN32

NR_IFileSystem * NR_MakeWin32FileSystem(void)
{
	return NR_CWin32FileSystem::Make();
}

#endif

NR_IFileSystem * NR_MakeFileSystemByOSPlatform(void)
{
#if defined NIER_PLATFORM_WIN32
	return NR_CWin32FileSystem::Make();
#endif

	return 0;
}
