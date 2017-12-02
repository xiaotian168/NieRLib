
#define _NIER_API

#include "FilePathFactory.h"
#include "CWin32FilePath.h"

#if defined NIER_PLATFORM_WIN32

IFilePath * MakeWin32FilePath(void)
{
	return CWin32FilePath::Make();
}

#endif
