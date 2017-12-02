
#define _NIER_API

#include "ProcessTool.h"
#include "ProcessManagerFactory.h"
#include "IProcessManager.h"
#include "IProcess.h"
#include "../StringConverter/StringConverterTool.h"

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

	static IProcessManager * pProcessManager;
};

IProcessManager * CProcessToolHelper::pProcessManager = 0;
CProcessToolHelper g_ProcessToolHelper;

bool ShutdownProcessByNameW(const wchar_t * pszProcessName, const unsigned int uExitCode)
{
	bool bRet = false;
	std::list<IProcess *> ProcessList;
	wchar_t szProcessNameTemp[MAX_PATH] = { 0 };
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

bool GetCurrentModuleNameW(wchar_t * pszName, const unsigned int uSize)
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

bool GetCurrentModuleNameA(char * pszName, const unsigned int uSize)
{
	bool bRet = false;

	if (pszName && uSize)
	{
		auto pszNameW = new wchar_t[uSize];
		if (pszNameW)
		{
			if (GetCurrentModuleNameW(pszNameW, uSize))
			{
				auto pszNameA = Unicode2MultiByte(pszNameW);
				if (pszNameA)
				{
					strcpy_s(pszName, uSize, pszNameA);
					bRet = true;

					FreeMultiByteString(pszNameA);
					pszNameA = 0;
				}
			}

			delete[] pszNameW;
			pszNameW = 0;
		}
	}

	return bRet;
}
