
#define _NR_API

#include "NR_CWin32Process.h"

#if defined NR_PLATFORM_WIN32

NR_CWin32Process * NR_CWin32Process::Make(const DWORD dwProcessID)
{
	return new NR_CWin32Process(dwProcessID);
}

NR_CWin32Process::NR_CWin32Process(const DWORD dwProcessID)
{
	m_dwProcessID = dwProcessID;
}

NR_CWin32Process::~NR_CWin32Process()
{
	m_dwProcessID = 0;
}

bool NR_CWin32Process::GetProcessID(IDType & ID)
{
	bool bRet = false;

	if (m_dwProcessID)
	{
		ID = static_cast<IDType>(m_dwProcessID);

		bRet = true;
	}

	return bRet;
}

bool NR_CWin32Process::GetProcessFileNameW(wchar_t * pszName, const unsigned int uSize)
{
	bool bRet = false;

	if (m_dwProcessID && pszName && uSize)
	{
		auto hProcess = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, m_dwProcessID);
		if (hProcess)
		{
			if (GetModuleFileNameExW(hProcess, 0, pszName, uSize))
			{
				bRet = true;
			}

			CloseHandle(hProcess);
			hProcess = 0;
		}

		bRet = true;
	}

	return bRet;
}

bool NR_CWin32Process::ShutdownProcess(const unsigned int uExitCode)
{
	bool bRet = false;

	if (m_dwProcessID)
	{
		auto hProcess = OpenProcess(PROCESS_TERMINATE, FALSE, m_dwProcessID);
		if (hProcess)
		{
			if (TerminateProcess(hProcess, uExitCode))
			{
				m_dwProcessID = 0;
				bRet = true;
			}

			CloseHandle(hProcess);
			hProcess = 0;
		}
	}

	return bRet;
}

#endif
