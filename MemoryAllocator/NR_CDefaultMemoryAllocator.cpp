
#define _NR_API

#include "NR_CDefaultMemoryAllocator.h"

NR_CDefaultMemoryAllocator * NR_CDefaultMemoryAllocator::Make(void)
{
	return new NR_CDefaultMemoryAllocator();
}

NR_CDefaultMemoryAllocator::NR_CDefaultMemoryAllocator()
{

}

NR_CDefaultMemoryAllocator::~NR_CDefaultMemoryAllocator()
{

}

void * NR_CDefaultMemoryAllocator::Alloc(const unsigned int uBytes)
{
	return malloc(uBytes);
}

void * NR_CDefaultMemoryAllocator::Realloc(void * pBuffer, const unsigned int uBytes)
{
	return realloc(pBuffer, uBytes);
}

void NR_CDefaultMemoryAllocator::Free(void * pBuffer)
{
	if (pBuffer)
	{
		free(pBuffer);
	}
}
