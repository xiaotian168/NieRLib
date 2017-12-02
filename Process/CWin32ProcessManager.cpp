
#define _NIER_API

#include "CWin32ProcessManager.h"
#include "CWin32Process.h"

#if defined NIER_PLATFORM_WIN32

CWin32ProcessManager * CWin32ProcessManager::Make(void)
{
	return new CWin32ProcessManager();
}

CWin32ProcessManager::CWin32ProcessManager()
{

}

CWin32ProcessManager::~CWin32ProcessManager()
{

}

bool CWin32ProcessManager::QueryProcessList(std::list<IProcess *> & ProcessList)
{
	bool bRet = false;
	PROCESSENTRY32W ProcessEntry32 = { 0 };

	auto hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	if (hSnap)
	{
		ProcessEntry32.dwSize = sizeof(ProcessEntry32);

		if (Process32FirstW(hSnap, &ProcessEntry32))
		{
			do 
			{
				auto pProcess = CWin32Process::Make(ProcessEntry32.th32ProcessID);
				if (pProcess)
				{
					ProcessList.push_back(pProcess);
					bRet = true;
				}

			} while (Process32NextW(hSnap, &ProcessEntry32));
		}

		CloseHandle(hSnap);
		hSnap = 0;
	}

	return bRet;
}

IProcess * CWin32ProcessManager::GetCurrentProcess(void)
{
	return CWin32Process::Make(GetCurrentProcessId());
}

#endif
