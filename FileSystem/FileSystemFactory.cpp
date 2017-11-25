
#define _NIER_API

#include "FileSystemFactory.h"
#include "CWin32FileSystem.h"

IFileSystem * MakeWin32FileSystem(void)
{
#if defined NIER_PLATFORM_WIN32
	return CWin32FileSystem::Make();
#endif

	return 0;
}

IFileSystem * MakeFileSystemByOSPlatform(void)
{
#if defined NIER_PLATFORM_WIN32
	return CWin32FileSystem::Make();
#endif

	return 0;
}
