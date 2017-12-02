
#pragma once

#include "NR_INetAdapterManager.h"

#if defined NIER_PLATFORM_WIN32

class NR_CWin32NetAapterManager : public NR_INetAdapterManager
{
public:

	static NR_CWin32NetAapterManager * Make(void);

protected:

	NR_CWin32NetAapterManager();

public:

	~NR_CWin32NetAapterManager();

public:

	bool QueryAdapterList(std::list<NR_INetAdapter *> & AdapterList) override;

private:

	bool Startup(void);

	void Shutdown(void);

private:

	INetConnectionManager * m_pConnectionManager;
};

#endif
