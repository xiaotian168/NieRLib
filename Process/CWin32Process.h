
#pragma once

#include "IProcess.h"
#include <Windows.h>

class CWin32Process : public IProcess
{
public:

	static CWin32Process * Make(const DWORD dwProcessID);

protected:

	CWin32Process(const DWORD dwProcessID);

	~CWin32Process();

public:

	bool GetProcessID(IDType & ID) override;

	bool GetProcessNameW(wchar_t * pszName, const unsigned int uSize) override;

	bool ShutdownProcess(const unsigned int uExitCode) override;

private:

	DWORD m_dwProcessID;
};
