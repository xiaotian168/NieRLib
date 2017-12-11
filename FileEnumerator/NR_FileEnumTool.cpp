
#define _NR_API

#include "NR_FileEnumTool.h"
#include "NR_FileEnumeratorFactory.h"
#include "NR_IFileEnumerator.h"
#include "NR_IFileEnumResult.h"
#include "../StringConverter/NR_StringConverterTool.h"

class NR_CFileEnumToolHelper
{
public:

	inline NR_CFileEnumToolHelper()
	{
		if (!pFileEnumerator)
		{
			pFileEnumerator = NR_MakeFileEnumeratorByOSPlatform();
		}
	}

	inline ~NR_CFileEnumToolHelper()
	{
		NR_SAFE_RELEASE(pFileEnumerator);
	}

public:

	static NR_IFileEnumerator * pFileEnumerator;
};

NR_IFileEnumerator * NR_CFileEnumToolHelper::pFileEnumerator = 0;
NR_CFileEnumToolHelper FileEnumToolHelper;

bool NR_EnumAllFileW(const wchar_t * pszDirectory, const wchar_t * pszFileExt, const bool bEnumSubDir, std::list<NR_IFileEnumResult *> & ResultList)
{
	bool bRet = false;

	if (NR_CFileEnumToolHelper::pFileEnumerator && pszDirectory && pszFileExt)
	{
		if (NR_CFileEnumToolHelper::pFileEnumerator->EnumAllFileW(pszDirectory, pszFileExt, bEnumSubDir, ResultList))
		{
			bRet = true;
		}
	}

	return bRet;
}

bool NR_EnumAllFileA(const char * pszDirectory, const char * pszFileExt, const bool bEnumSubDir, std::list<NR_IFileEnumResult *> & ResultList)
{
	bool bRet = false;

	if (pszDirectory && pszFileExt)
	{
		auto pszDirectoryW = NR_MultiByte2Unicode(pszDirectory);
		if (pszDirectoryW)
		{
			auto pszFileExtW = NR_MultiByte2Unicode(pszFileExt);
			if (pszFileExtW)
			{
				if (NR_EnumAllFileW(pszDirectoryW, pszFileExtW, bEnumSubDir, ResultList))
				{
					bRet = true;
				}

				NR_FreeUnicodeString(pszFileExtW);
				pszFileExtW = 0;
			}

			NR_FreeUnicodeString(pszDirectoryW);
			pszDirectoryW = 0;
		}
	}

	return bRet;
}

bool NR_EnumAllDirectoryW(const wchar_t * pszDirectory, const bool bEnumSubDir, std::list<NR_IFileEnumResult *> & ResultList)
{
	bool bRet = false;

	if (NR_CFileEnumToolHelper::pFileEnumerator && pszDirectory)
	{
		if (NR_CFileEnumToolHelper::pFileEnumerator->EnumAllDirectoryW(pszDirectory, bEnumSubDir, ResultList))
		{
			bRet = true;
		}
	}

	return bRet;
}

bool NR_EnumAllDirectoryA(const char * pszDirectory, const bool bEnumSubDir, std::list<NR_IFileEnumResult *> & ResultList)
{
	bool bRet = false;

	if (pszDirectory)
	{
		auto pszDirectoryW = NR_MultiByte2Unicode(pszDirectory);
		if (pszDirectoryW)
		{
			if (NR_EnumAllDirectoryW(pszDirectoryW, bEnumSubDir, ResultList))
			{
				bRet = true;
			}

			NR_FreeUnicodeString(pszDirectoryW);
			pszDirectoryW = 0;
		}
	}

	return bRet;
}
