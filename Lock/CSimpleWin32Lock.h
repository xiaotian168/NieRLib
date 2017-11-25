
#pragma once

#include "ILock.h"

#if defined NIER_PLATFORM_WIN32

class CSimpleWin32Lock : public ILock
{
public:

	static CSimpleWin32Lock * Make(void);

protected:

	CSimpleWin32Lock();

	~CSimpleWin32Lock();

public:

	bool Lock(void) override;

	bool Unlock(void) override;

private:

	CRITICAL_SECTION m_CriticalSection;
};

#endif
