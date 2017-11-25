
#pragma once

#include "INetAdapterManager.h"

#if defined NIER_PLATFORM_WIN32

class CWin32NetAapterManager : public INetAdapterManager
{
public:

	static CWin32NetAapterManager * Make(void);

protected:

	CWin32NetAapterManager();

public:

	~CWin32NetAapterManager();

public:

	bool QueryAdapterList(std::list<INetAdapter *> & AdapterList) override;

private:

	bool Startup(void);

	void Shutdown(void);

private:

	INetConnectionManager * m_pConnectionManager;
};

#endif
