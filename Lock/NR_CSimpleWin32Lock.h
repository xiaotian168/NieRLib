
#pragma once

#include "NR_ILock.h"

#if defined NIER_PLATFORM_WIN32

class NR_CSimpleWin32Lock : public NR_ILock
{
public:

	static NR_CSimpleWin32Lock * Make(void);

protected:

	NR_CSimpleWin32Lock();

	~NR_CSimpleWin32Lock();

public:

	bool Lock(void) override;

	bool Unlock(void) override;

private:

	CRITICAL_SECTION m_CriticalSection;
};

#endif
