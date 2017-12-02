
#define _NR_API

#include "NR_FilePathFactory.h"
#include "NR_CWin32FilePath.h"

#if defined NR_PLATFORM_WIN32

NR_IFilePath * MakeWin32FilePath(void)
{
	return NR_CWin32FilePath::Make();
}

#endif

NR_IFilePath * MakeFilePathByOSPlatform(void)
{
#if defined NR_PLATFORM_WIN32
	return NR_CWin32FilePath::Make();
#endif

	return 0;
}
