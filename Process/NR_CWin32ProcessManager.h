
#pragma once

#include "NR_IProcessManager.h"

#if defined NIER_PLATFORM_WIN32

class NR_CWin32ProcessManager : public NR_IProcessManager
{
public:

	static NR_CWin32ProcessManager * Make(void);

protected:

	NR_CWin32ProcessManager();

	~NR_CWin32ProcessManager();

public:

	bool QueryProcessList(std::list<NR_IProcess *> & ProcessList) override;

	NR_IProcess * GetCurrentProcess(void) override;
};

#endif
