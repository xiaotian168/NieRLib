
#define _NIER_API

#include "FileEnumTool.h"
#include "FileEnumeratorFactory.h"
#include "IFileEnumerator.h"
#include "IFileEnumResult.h"
#include "../StringConverter/StringConverterTool.h"

bool EnumAllFileW(const wchar_t * pszDirectory, const wchar_t * pszFileExt, const bool bEnumSubDir, std::list<IFileEnumResult *> & ResultList)
{
	bool bRet = false;

	if (pszDirectory && pszFileExt)
	{
		auto pFileEnumerator = MakeFileEnumeratorByOSPlatform();
		if (pFileEnumerator)
		{
			if (pFileEnumerator->EnumAllFileW(pszDirectory, pszFileExt, bEnumSubDir, ResultList))
			{
				bRet = true;
			}

			SAFE_RELEASE(pFileEnumerator);
		}
	}

	return bRet;
}

bool EnumAllFileA(const char * pszDirectory, const char * pszFileExt, const bool bEnumSubDir, std::list<IFileEnumResult *> & ResultList)
{
	bool bRet = false;

	if (pszDirectory && pszFileExt)
	{
		auto pszDirectoryW = MultiByte2Unicode(pszDirectory);
		if (pszDirectoryW)
		{
			auto pszFileExtW = MultiByte2Unicode(pszFileExt);
			if (pszFileExtW)
			{
				if (EnumAllFileW(pszDirectoryW, pszFileExtW, bEnumSubDir, ResultList))
				{
					bRet = true;
				}

				FreeUnicodeString(pszFileExtW);
				pszFileExtW = 0;
			}

			FreeUnicodeString(pszDirectoryW);
			pszDirectoryW = 0;
		}
	}

	return bRet;
}

bool EnumAllDirectoryW(const wchar_t * pszDirectory, const bool bEnumSubDir, std::list<IFileEnumResult *> & ResultList)
{
	bool bRet = false;

	if (pszDirectory)
	{
		auto pFileEnumerator = MakeFileEnumeratorByOSPlatform();
		if (pFileEnumerator)
		{
			if (pFileEnumerator->EnumAllDirectoryW(pszDirectory, bEnumSubDir, ResultList))
			{
				bRet = true;
			}

			SAFE_RELEASE(pFileEnumerator);
		}
	}

	return bRet;
}

bool EnumAllDirectoryA(const char * pszDirectory, const bool bEnumSubDir, std::list<IFileEnumResult *> & ResultList)
{
	bool bRet = false;

	if (pszDirectory)
	{
		auto pszDirectoryW = MultiByte2Unicode(pszDirectory);
		if (pszDirectoryW)
		{
			if (EnumAllDirectoryW(pszDirectoryW, bEnumSubDir, ResultList))
			{
				bRet = true;
			}

			FreeUnicodeString(pszDirectoryW);
			pszDirectoryW = 0;
		}
	}

	return bRet;
}
