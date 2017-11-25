
#define _NIER_API

#include "MemoryAllocatorFactory.h"
#include "CDefaultMemoryAllocator.h"

IMemoryAllocator * MakeDefaultMemoryAllocator(void)
{
#if defined NIER_PLATFORM_WIN32 || defined NIER_PLATFORM_LINUX
	return CDefaultMemoryAllocator::Make();
#endif

	return 0;
}

IMemoryAllocator * MakeMemoryAllocatorByOSPlatform(void)
{
#if defined NIER_PLATFORM_WIN32 || defined NIER_PLATFORM_LINUX
	return CDefaultMemoryAllocator::Make();
#endif

	return 0;
}
