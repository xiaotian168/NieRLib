
#define _NIER_API

#include "CDefaultMemoryAllocator.h"
#include <malloc.h>

CDefaultMemoryAllocator * CDefaultMemoryAllocator::Make(void)
{
	return new CDefaultMemoryAllocator();
}

CDefaultMemoryAllocator::CDefaultMemoryAllocator()
{

}

CDefaultMemoryAllocator::~CDefaultMemoryAllocator()
{

}

void * CDefaultMemoryAllocator::Alloc(const unsigned int uBytes)
{
	return malloc(uBytes);
}

void * CDefaultMemoryAllocator::Realloc(void * pBuffer, const unsigned int uBytes)
{
	return realloc(pBuffer, uBytes);
}

void CDefaultMemoryAllocator::Free(void * pBuffer)
{
	if (pBuffer)
	{
		free(pBuffer);
	}
}
