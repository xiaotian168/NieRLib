
#pragma once

#include "IMemoryAllocator.h"

class CDefaultMemoryAllocator : public IMemoryAllocator
{
public:

	static CDefaultMemoryAllocator * Make(void);

protected:

	CDefaultMemoryAllocator();

	~CDefaultMemoryAllocator();

public:

	void * Alloc(const unsigned int uBytes) override;

	void * Realloc(void * pBuffer, const unsigned int uBytes) override;

	void Free(void * pBuffer) override;
};
