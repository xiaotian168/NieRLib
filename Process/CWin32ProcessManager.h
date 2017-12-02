
#pragma once

#include "IProcessManager.h"

#if defined NIER_PLATFORM_WIN32

class CWin32ProcessManager : public IProcessManager
{
public:

	static CWin32ProcessManager * Make(void);

protected:

	CWin32ProcessManager();

	~CWin32ProcessManager();

public:

	bool QueryProcessList(std::list<IProcess *> & ProcessList) override;

	IProcess * GetCurrentProcess(void) override;
};

#endif
