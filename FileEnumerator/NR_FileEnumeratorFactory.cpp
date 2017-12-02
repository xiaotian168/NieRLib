
#define _NR_API

#include "NR_FileEnumeratorFactory.h"
#include "NR_CWin32FileEnumerator.h"

#if defined NR_PLATFORM_WIN32

NR_IFileEnumerator * NR_MakeWin32FileEnumerator(void)
{
	return NR_CWin32FileEnumerator::Make();
}

#endif

NR_IFileEnumerator * NR_MakeFileEnumeratorByOSPlatform(void)
{
#if defined NR_PLATFORM_WIN32
	return NR_CWin32FileEnumerator::Make();
#endif

	return 0;
}
