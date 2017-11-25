
#pragma once

#include "IThreadManager.h"

#if defined NIER_PLATFORM_WIN32

class CWin32ThreadManager : public IThreadManager
{
public:

	static CWin32ThreadManager * Make(void);

protected:

	CWin32ThreadManager();

	~CWin32ThreadManager();

public:

	IThread * GetCurrentThread(void) override;
};

#endif
