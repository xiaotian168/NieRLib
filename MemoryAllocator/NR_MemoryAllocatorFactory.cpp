
#define _NIER_API

#include "NR_MemoryAllocatorFactory.h"
#include "NR_CDefaultMemoryAllocator.h"

#if defined NIER_PLATFORM_WIN32 || defined NIER_PLATFORM_LINUX

NR_IMemoryAllocator * NR_MakeDefaultMemoryAllocator(void)
{
	return NR_CDefaultMemoryAllocator::Make();
}

#endif

NR_IMemoryAllocator * NR_MakeMemoryAllocatorByOSPlatform(void)
{
#if defined NIER_PLATFORM_WIN32 || defined NIER_PLATFORM_LINUX
	return NR_CDefaultMemoryAllocator::Make();
#endif

	return 0;
}
