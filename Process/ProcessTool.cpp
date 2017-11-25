
#define _NIER_API

#include "ProcessTool.h"
#include "ProcessManagerFactory.h"
#include "IProcessManager.h"
#include "IProcess.h"
#include "../StringConverter/StringConverterTool.h"
#include <Windows.h>

bool ShutdownProcessByNameW(const wchar_t * pszProcessName, const unsigned int uExitCode)
{
	bool bRet = false;
	std::list<IProcess *> ProcessList;
	wchar_t szProcessNameTemp[MAX_PATH] = { 0 };
	unsigned int uMatchProcessNum = 0;
	unsigned int uSucceededShutdownProcessNum = 0;

	if (pszProcessName && wcslen(pszProcessName))
	{
		auto pProcessMgr = MakeProcessManagerByOSPlatform();
		if (pProcessMgr)
		{
			if (pProcessMgr->QueryProcessList(ProcessList))
			{
				for (auto pProcess : ProcessList)
				{
					if (pProcess)
					{
						if (pProcess->GetProcessNameW(szProcessNameTemp, _countof(szProcessNameTemp)))
						{
							if (0 == _wcsicmp(szProcessNameTemp, pszProcessName))
							{
								if (pProcess->ShutdownProcess(uExitCode))
								{
									++uSucceededShutdownProcessNum;
								}

								++uMatchProcessNum;
							}
						}

						SAFE_RELEASE(pProcess);
					}
				}

				if (uSucceededShutdownProcessNum == uMatchProcessNum)
				{
					bRet = true;
				}
			}

			SAFE_RELEASE(pProcessMgr);
		}
	}

	return bRet;
}

bool ShutdownProcessByNameA(const char * pszProcessName, const unsigned int uExitCode)
{
	bool bRet = false;

	if (pszProcessName)
	{
		auto pszProcessNameW = MultiByte2Unicode(pszProcessName);
		if (pszProcessNameW)
		{
			if (ShutdownProcessByNameW(pszProcessNameW, uExitCode))
			{
				bRet = true;
			}

			FreeUnicodeString(pszProcessNameW);
			pszProcessNameW = 0;
		}
	}

	return bRet;
}
