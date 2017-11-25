
#define _NIER_API

#include "FileEnumeratorFactory.h"
#include "CWin32FileEnumerator.h"

IFileEnumerator * MakeWin32FileEnumerator(void)
{
#if defined NIER_PLATFORM_WIN32
	return CWin32FileEnumerator::Make();
#endif

	return 0;
}

IFileEnumerator * MakeFileEnumeratorByOSPlatform(void)
{
#if defined NIER_PLATFORM_WIN32
	return CWin32FileEnumerator::Make();
#endif

	return 0;
}
