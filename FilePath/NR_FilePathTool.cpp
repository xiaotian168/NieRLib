
#define _NR_API

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
		NR_SAFE_RELEASE(pFilePath);
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

bool NR_SplitFileTitleW(const wchar_t * pszPathToSplit, wchar_t * pszFileTitle, const unsigned int uSize)
{
	bool bRet = false;

	if (NR_CFilePathToolHelper::pFilePath && pszPathToSplit && pszFileTitle && uSize)
	{
		if (NR_CFilePathToolHelper::pFilePath->SplitFileTitleW(pszPathToSplit, pszFileTitle, uSize))
		{
			bRet = true;
		}
	}

	return bRet;
}

bool NR_RemoveFileSpecW(wchar_t * pszPath)
{
	bool bRet = false;

	if (NR_CFilePathToolHelper::pFilePath && pszPath)
	{
		if (NR_CFilePathToolHelper::pFilePath->RemoveFileSpecW(pszPath))
		{
			bRet = true;
		}
	}

	return bRet;
}

bool NR_AppendBackslashW(wchar_t * pszPath, const unsigned int uSize)
{
	bool bRet = false;

	if (NR_CFilePathToolHelper::pFilePath && pszPath && uSize)
	{
		if (NR_CFilePathToolHelper::pFilePath->AppendBackslashW(pszPath, uSize))
		{
			bRet = true;
		}
	}

	return bRet;
}
