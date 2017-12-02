
#pragma once

#include "NR_IMemoryAllocator.h"

class NR_CDefaultMemoryAllocator : public NR_IMemoryAllocator
{
public:

	static NR_CDefaultMemoryAllocator * Make(void);

protected:

	NR_CDefaultMemoryAllocator();

	~NR_CDefaultMemoryAllocator();

public:

	void * Alloc(const unsigned int uBytes) override;

	void * Realloc(void * pBuffer, const unsigned int uBytes) override;

	void Free(void * pBuffer) override;
};
