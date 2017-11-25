
#pragma once

#include "IProcessManager.h"

class CWin32ProcessManager : public IProcessManager
{
public:

	static CWin32ProcessManager * Make(void);

protected:

	CWin32ProcessManager();

	~CWin32ProcessManager();

public:

	bool QueryProcessList(std::list<IProcess *> & ProcessList) override;
};
