
#pragma once

#include "../NieRLibConfig.h"

#define SAFE_RELEASE(_Ref) { \
	if(_Ref) { \
		_Ref->Release(); \
		_Ref = 0; \
	} \
}

#define SAFE_ADDREF(_Ref) { \
	if(_Ref) { \
		_Ref->AddRef(); \
	} \
}

class NIER_API IRefCount
{
public:

	inline IRefCount() : m_nRefCount(1)
	{

	}

	inline virtual ~IRefCount()
	{

	}

public:

	inline void AddRef(void)
	{
		++m_nRefCount;
	}

	inline bool Release(void)
	{
		--m_nRefCount;

		if (0 == m_nRefCount)
		{
			delete this;
			return true;
		}

		return false;
	}

	inline int GetRefCount(void) const
	{
		return m_nRefCount;
	}

private:

	int m_nRefCount;
};
