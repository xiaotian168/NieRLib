
#define _NR_API

#include "NR_ProcessTool.h"
#include "NR_ProcessManagerFactory.h"
#include "NR_IProcessManager.h"
#include "../StringConverter/NR_StringConverterTool.h"
#include "../FilePath/NR_FilePathTool.h"

class NR_CProcessToolHelper
{
public:

	inline NR_CProcessToolHelper()
	{
		pProcessManager = MakeProcessManagerByOSPlatform();
	}

	inline ~NR_CProcessToolHelper()
	{
		NR_SAFE_RELEASE(pProcessManager);
	}

public:

	static NR_IProcessManager * pProcessManager;
};

NR_IProcessManager * NR_CProcessToolHelper::pProcessManager = 0;
NR_CProcessToolHelper g_ProcessToolHelper;

bool NR_ShutdownProcessByNameW(const wchar_t * pszProcessName, const unsigned int uExitCode)
{
	bool bRet = false;
	std::list<NR_IProcess *> ProcessList;
	wchar_t szProcessFileName[260] = { 0 };
	wchar_t szProcessNameTemp[260] = { 0 };
	unsigned int uMatchProcessNum = 0;
	unsigned int uSucceededShutdownProcessNum = 0;

	if (NR_CProcessToolHelper::pProcessManager && pszProcessName && wcslen(pszProcessName))
	{
		if (NR_CProcessToolHelper::pProcessManager->QueryProcessList(ProcessList))
		{
			for (auto pProcess : ProcessList)
			{
				if (pProcess)
				{
					if (pProcess->GetProcessFileNameW(szProcessFileName, _countof(szProcessFileName)))
					{
						if (NR_SplitFileTitleW(szProcessFileName, szProcessNameTemp, _countof(szProcessNameTemp)))
						{
							if (0 == _wcsicmp(pszProcessName, szProcessNameTemp))
							{
								if (pProcess->ShutdownProcess(uExitCode))
								{
									++uSucceededShutdownProcessNum;
								}

								++uMatchProcessNum;
							}
						}
					}

					NR_SAFE_RELEASE(pProcess);
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

	if (NR_CProcessToolHelper::pProcessManager && pszName && uSize)
	{
		auto pProcess = NR_CProcessToolHelper::pProcessManager->GetCurrentProcess();
		if (pProcess)
		{
			if (pProcess->GetProcessFileNameW(pszName, uSize))
			{
				bRet = true;
			}

			NR_SAFE_RELEASE(pProcess);
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

bool NR_GetProcessIDByProcessNameW(const wchar_t * pszProcessName, std::list<NR_IProcess::IDType> & IDList)
{
	bool bRet = false;
	std::list<NR_IProcess *> ProcessList;
	wchar_t szProcessFileName[260] = { 0 };
	wchar_t szProcessNameTemp[260] = { 0 };
	NR_IProcess::IDType ProcessID = 0;

	if (NR_CProcessToolHelper::pProcessManager && pszProcessName)
	{
		if (NR_CProcessToolHelper::pProcessManager->QueryProcessList(ProcessList))
		{
			for (auto pProcess : ProcessList)
			{
				if (pProcess)
				{
					if (pProcess->GetProcessFileNameW(szProcessFileName, _countof(szProcessFileName)))
					{
						if (NR_SplitFileTitleW(szProcessFileName, szProcessNameTemp, _countof(szProcessNameTemp)))
						{
							if (0 == _wcsicmp(pszProcessName, szProcessNameTemp))
							{
								if (pProcess->GetProcessID(ProcessID))
								{
									IDList.push_back(ProcessID);

									bRet = true;
								}
							}
						}
					}

					NR_SAFE_RELEASE(pProcess);
				}
			}
		}
	}

	return bRet;
}
