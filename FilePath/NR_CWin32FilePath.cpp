
#include "NR_CWin32FilePath.h"

#if defined NR_PLATFORM_WIN32

NR_CWin32FilePath * NR_CWin32FilePath::Make(void)
{
	return new NR_CWin32FilePath();
}

NR_CWin32FilePath::NR_CWin32FilePath()
{

}

NR_CWin32FilePath::~NR_CWin32FilePath()
{

}

bool NR_CWin32FilePath::SplitDirectoryW(const wchar_t * pszPathToSplit, wchar_t * pszDirectory, const unsigned int uSize)
{
	bool bRet = false;

	if (pszPathToSplit && pszDirectory && uSize)
	{
		if (0 == _wsplitpath_s(pszPathToSplit, 0, 0, pszDirectory, uSize, 0, 0, 0, 0))
		{
			bRet = true;
		}
	}

	return bRet;
}

bool NR_CWin32FilePath::SplitFileTitleW(const wchar_t * pszPathToSplit, wchar_t * pszFileTitle, const unsigned int uSize)
{
	bool bRet = false;
	wchar_t szFileExt[260] = { 0 };

	if (pszPathToSplit && pszFileTitle && uSize)
	{
		const auto uPathToSplitLen = wcslen(pszPathToSplit);
		if (uPathToSplitLen)
		{
			auto pszFileName = new wchar_t[uPathToSplitLen];
			if (pszFileName)
			{
				if (0 == _wsplitpath_s(pszPathToSplit, 0, 0, 0, 0, pszFileName, uPathToSplitLen, szFileExt, _countof(szFileExt)))
				{
					wcscpy_s(pszFileTitle, uSize, pszFileName);
					wcscat_s(pszFileTitle, uSize, szFileExt);

					bRet = true;
				}

				delete[] pszFileName;
				pszFileName = 0;
			}
		}
	}

	return bRet;
}

bool NR_CWin32FilePath::SplitFileTitleWithNoExeW(const wchar_t * pszPathToSplit, wchar_t * pszFileTitle, const unsigned int uSize)
{
	bool bRet = false;

	if (pszPathToSplit && pszFileTitle && uSize)
	{
		const auto uPathToSplitLen = wcslen(pszPathToSplit);
		if (uPathToSplitLen)
		{
			auto pszFileName = new wchar_t[uPathToSplitLen];
			if (pszFileName)
			{
				if (0 == _wsplitpath_s(pszPathToSplit, 0, 0, 0, 0, pszFileName, uPathToSplitLen, 0, 0))
				{
					wcscpy_s(pszFileTitle, uSize, pszFileName);

					bRet = true;
				}

				delete[] pszFileName;
				pszFileName = 0;
			}
		}
	}

	return bRet;
}

bool NR_CWin32FilePath::SplitFileExtW(const wchar_t * pszPathToSplit, wchar_t * pszFileExt, const unsigned int uSize)
{
	bool bRet = false;

	if (pszPathToSplit && pszFileExt && uSize)
	{
		if (0 == _wsplitpath_s(pszPathToSplit, 0, 0, 0, 0, 0, 0, pszFileExt, uSize))
		{
			bRet = true;
		}
	}

	return bRet;
}

bool NR_CWin32FilePath::AppendBackslashW(wchar_t * pszPath, const unsigned int uSize)
{
	bool bRet = false;

	if (pszPath && uSize)
	{
		PathAddBackslashW(pszPath);

		bRet = true;
	}

	return bRet;
}

bool NR_CWin32FilePath::RemoveFileSpecW(wchar_t * pszPath)
{
	bool bRet = false;

	if (pszPath)
	{
		::PathRemoveFileSpecW(pszPath);

		bRet = true;
	}

	return bRet;
}

#endif
