
#define _NIER_API

#include "NR_FilePathTool.h"
#include "NR_FilePathFactory.h"
#include "NR_IFilePath.h"

class NR_CFilePathToolHelper
{
public:

	inline NR_CFilePathToolHelper()
	{
		pFilePath = MakeFilePathByOSPlatform();
	}

	inline ~NR_CFilePathToolHelper()
	{
		SAFE_RELEASE(pFilePath);
	}

public:

	static NR_IFilePath * pFilePath;
};

NR_IFilePath * NR_CFilePathToolHelper::pFilePath = 0;
NR_CFilePathToolHelper g_FilePathToolHelper;

bool NR_SplitDirectoryW(const wchar_t * pszPathToSplit, wchar_t * pszDirectory, const unsigned int uSize)
{
	bool bRet = false;

	if (NR_CFilePathToolHelper::pFilePath && pszPathToSplit && pszDirectory && uSize)
	{
		if (NR_CFilePathToolHelper::pFilePath->SplitDirectoryW(pszPathToSplit, pszDirectory, uSize))
		{
			bRet = true;
		}
	}

	return bRet;
}
