
#define _NR_API

#include "NR_SystemDirectoryInfoTool.h"
#include "NR_SystemDirectoryInfoFactory.h"
#include "NR_ISystemDirectoryInfo.h"
#include "../FileSystem/NR_FileSystemTool.h"
#include "../FilePath/NR_FilePathTool.h"

class NR_CSystemDirectoryInfoHelper
{
public:

	inline NR_CSystemDirectoryInfoHelper()
	{
		if (!pSystemDirectoryInfo)
		{
			pSystemDirectoryInfo = MakeSystemDirectoryInfoByOSPlatform();
		}
	}

	inline ~NR_CSystemDirectoryInfoHelper()
	{
		NR_SAFE_RELEASE(pSystemDirectoryInfo);
	}

public:

	static NR_ISystemDirectoryInfo * pSystemDirectoryInfo;
};

NR_ISystemDirectoryInfo * NR_CSystemDirectoryInfoHelper::pSystemDirectoryInfo = 0;
NR_CSystemDirectoryInfoHelper SystemDirectoryInfoHelper;

bool NR_GetTempDirectoryW(wchar_t * pszDirectory, const unsigned int uSize)
{
	bool bRet = false;

	if (NR_CSystemDirectoryInfoHelper::pSystemDirectoryInfo && pszDirectory && uSize)
	{
		if (NR_CSystemDirectoryInfoHelper::pSystemDirectoryInfo->GetTempDirectoryW(pszDirectory, uSize))
		{
			bRet = true;
		}
	}

	return bRet;
}

bool NR_GetSystemDirectoryW(wchar_t * pszDirectory, const unsigned int uSize)
{
	bool bRet = false;

	if (NR_CSystemDirectoryInfoHelper::pSystemDirectoryInfo && pszDirectory && uSize)
	{
		if (NR_CSystemDirectoryInfoHelper::pSystemDirectoryInfo->GetSystemDirectoryW(pszDirectory, uSize))
		{
			bRet = true;
		}
	}

	return bRet;
}

bool NR_MakeTempFilePathW(wchar_t * pszFilePath, const unsigned int uSize)
{
	bool bRet = false;
	wchar_t szTempDir[260] = { 0 };
	unsigned long long uMagic = 0;

	if (pszFilePath && uSize)
	{
		if (NR_GetTempDirectoryW(szTempDir, _countof(szTempDir)))
		{
			NR_AppendBackslashW(szTempDir, _countof(szTempDir));

			while (uMagic < 0xFFFFFFFF)
			{
				swprintf_s(pszFilePath, uSize, L"%s%d.tmp", szTempDir, uMagic);
				++uMagic;

				if (NR_IsFileExistW(pszFilePath))
				{
					bRet = true;
					break;
				}
			}
		}
	}

	return bRet;
}
