
#define _NIER_API

#include "NR_CWin32ProcessManager.h"
#include "NR_CWin32Process.h"

#if defined NIER_PLATFORM_WIN32

NR_CWin32ProcessManager * NR_CWin32ProcessManager::Make(void)
{
	return new NR_CWin32ProcessManager();
}

NR_CWin32ProcessManager::NR_CWin32ProcessManager()
{

}

NR_CWin32ProcessManager::~NR_CWin32ProcessManager()
{

}

bool NR_CWin32ProcessManager::QueryProcessList(std::list<NR_IProcess *> & ProcessList)
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
				auto pProcess = NR_CWin32Process::Make(ProcessEntry32.th32ProcessID);
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

NR_IProcess * NR_CWin32ProcessManager::GetCurrentProcess(void)
{
	return NR_CWin32Process::Make(GetCurrentProcessId());
}

#endif
