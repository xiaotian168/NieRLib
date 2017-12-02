
#pragma once

#include "NR_IProcess.h"

#if defined NIER_PLATFORM_WIN32

class NR_CWin32Process : public NR_IProcess
{
public:

	static NR_CWin32Process * Make(const DWORD dwProcessID);

protected:

	NR_CWin32Process(const DWORD dwProcessID);

	~NR_CWin32Process();

public:

	bool GetProcessID(IDType & ID) override;

	bool GetProcessFileNameW(wchar_t * pszName, const unsigned int uSize) override;

	bool ShutdownProcess(const unsigned int uExitCode) override;

private:

	DWORD m_dwProcessID;
};

#endif
