
#pragma once

#include "NR_IThreadManager.h"

#if defined NIER_PLATFORM_WIN32

class NR_CWin32ThreadManager : public NR_IThreadManager
{
public:

	static NR_CWin32ThreadManager * Make(void);

protected:

	NR_CWin32ThreadManager();

	~NR_CWin32ThreadManager();

public:

	NR_IThread * GetCurrentThread(void) override;
};

#endif
