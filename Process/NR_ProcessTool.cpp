
#define _NIER_API

#include "NR_ProcessTool.h"
#include "NR_ProcessManagerFactory.h"
#include "NR_IProcessManager.h"
#include "NR_IProcess.h"
#include "../StringConverter/NR_StringConverterTool.h"

class CProcessToolHelper
{
public:

	inline CProcessToolHelper()
	{
		pProcessManager = MakeProcessManagerByOSPlatform();
	}

	inline ~CProcessToolHelper()
	{
		SAFE_RELEASE(pProcessManager);
	}

public:

	static NR_IProcessManager * pProcessManager;
};

NR_IProcessManager * CProcessToolHelper::pProcessManager = 0;
CProcessToolHelper g_ProcessToolHelper;

bool NR_ShutdownProcessByNameW(const wchar_t * pszProcessName, const unsigned int uExitCode)
{
	bool bRet = false;
	std::list<NR_IProcess *> ProcessList;
	wchar_t szProcessNameTemp[260] = { 0 };
	unsigned int uMatchProcessNum = 0;
	unsigned int uSucceededShutdownProcessNum = 0;

	if (CProcessToolHelper::pProcessManager && pszProcessName && wcslen(pszProcessName))
	{
		if (CProcessToolHelper::pProcessManager->QueryProcessList(ProcessList))
		{
			for (auto pProcess : ProcessList)
			{
				if (pProcess)
				{
					if (pProcess->GetProcessFileNameW(szProcessNameTemp, _countof(szProcessNameTemp)))
					{
						PathStripPathW(szProcessNameTemp);
						
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
	}

	return bRet;
}

bool NR_ShutdownProcessByNameA(const char * pszProcessName, const unsigned int uExitCode)
{
	bool bRet = false;

	if (pszProcessName)
	{
		auto pszProcessNameW = NR_MultiByte2Unicode(pszProcessName);
		if (pszProcessNameW)
		{
			if (NR_ShutdownProcessByNameW(pszProcessNameW, uExitCode))
			{
				bRet = true;
			}

			NR_FreeUnicodeString(pszProcessNameW);
			pszProcessNameW = 0;
		}
	}

	return bRet;
}

bool NR_GetCurrentModuleFileNameW(wchar_t * pszName, const unsigned int uSize)
{
	bool bRet = false;

	if (CProcessToolHelper::pProcessManager && pszName && uSize)
	{
		auto pProcess = CProcessToolHelper::pProcessManager->GetCurrentProcess();
		if (pProcess)
		{
			if (pProcess->GetProcessFileNameW(pszName, uSize))
			{
				bRet = true;
			}

			SAFE_RELEASE(pProcess);
		}
	}

	return bRet;
}

bool NR_GetCurrentModuleFileNameA(char * pszName, const unsigned int uSize)
{
	bool bRet = false;

	if (pszName && uSize)
	{
		auto pszNameW = new wchar_t[uSize];
		if (pszNameW)
		{
			if (NR_GetCurrentModuleFileNameW(pszNameW, uSize))
			{
				auto pszNameA = NR_Unicode2MultiByte(pszNameW);
				if (pszNameA)
				{
					strcpy_s(pszName, uSize, pszNameA);
					bRet = true;

					NR_FreeMultiByteString(pszNameA);
					pszNameA = 0;
				}
			}

			delete[] pszNameW;
			pszNameW = 0;
		}
	}

	return bRet;
}
