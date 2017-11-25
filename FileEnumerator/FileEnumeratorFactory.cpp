
#define _NIER_API

#include "CWin32FileEnumerator.h"

IFileEnumerator * MakeWin32FileEnumerator(void)
{
	return CWin32FileEnumerator::Make();
}

IFileEnumerator * MakeFileEnumeratorByOSPlatform(void)
{
#if defined NIER_PLATFORM_WIN32
	return CWin32FileEnumerator::Make();
#endif

	return 0;
}
