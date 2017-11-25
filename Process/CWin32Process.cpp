
#define _NIER_API

#include "CWin32Process.h"

#if defined NIER_PLATFORM_WIN32

CWin32Process * CWin32Process::Make(const DWORD dwProcessID)
{
	return new CWin32Process(dwProcessID);
}

CWin32Process::CWin32Process(const DWORD dwProcessID)
{
	m_dwProcessID = dwProcessID;
}

CWin32Process::~CWin32Process()
{
	m_dwProcessID = 0;
}

bool CWin32Process::GetProcessID(IDType & ID)
{
	bool bRet = false;

	if (m_dwProcessID)
	{
		ID = static_cast<IDType>(m_dwProcessID);

		bRet = true;
	}

	return bRet;
}

bool CWin32Process::GetProcessNameW(wchar_t * pszName, const unsigned int uSize)
{
	bool bRet = false;

	if (m_dwProcessID && pszName && uSize)
	{
		auto hProcess = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, m_dwProcessID);
		if (hProcess)
		{
			if (GetModuleFileNameExW(hProcess, 0, pszName, uSize))
			{
				PathStripPathW(pszName);

				bRet = true;
			}

			CloseHandle(hProcess);
			hProcess = 0;
		}

		bRet = true;
	}

	return bRet;
}

bool CWin32Process::ShutdownProcess(const unsigned int uExitCode)
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
