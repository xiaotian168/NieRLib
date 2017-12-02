
#define _NR_API

#include "NR_MemoryAllocatorFactory.h"
#include "NR_CDefaultMemoryAllocator.h"

#if defined NR_PLATFORM_WIN32 || defined NR_PLATFORM_LINUX

NR_IMemoryAllocator * NR_MakeDefaultMemoryAllocator(void)
{
	return NR_CDefaultMemoryAllocator::Make();
}

#endif

NR_IMemoryAllocator * NR_MakeMemoryAllocatorByOSPlatform(void)
{
#if defined NR_PLATFORM_WIN32 || defined NR_PLATFORM_LINUX
	return NR_CDefaultMemoryAllocator::Make();
#endif

	return 0;
}
