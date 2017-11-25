
#pragma once

#include "../Base/IRefCount.h"

class IFile : public IRefCount
{
public:

	virtual bool Close(void) = 0;

	virtual bool SeekTo(const long nPos) = 0;

	virtual bool SeekToBegin(void) = 0;

	virtual bool SeekToEnd(void) = 0;

	virtual bool SeekOffset(const long nOffset) = 0;

	virtual long Tell(void) = 0;

	virtual bool Read(void * pBuffer, const unsigned int uBytes) = 0;

	virtual bool Write(const void * pBuffer, const unsigned int uBytes) = 0;
};
