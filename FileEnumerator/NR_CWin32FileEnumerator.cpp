
#define _NIER_API

#include "NR_CWin32FileEnumerator.h"
#include "NR_CWin32FileEnumResult.h"

#if defined NIER_PLATFORM_WIN32

NR_CWin32FileEnumerator * NR_CWin32FileEnumerator::Make(void)
{
	return new NR_CWin32FileEnumerator();
}

NR_CWin32FileEnumerator::NR_CWin32FileEnumerator()
{

}

NR_CWin32FileEnumerator::~NR_CWin32FileEnumerator()
{

}

bool NR_CWin32FileEnumerator::EnumAllFileW(const wchar_t * pszDirectory, const wchar_t * pszFileExt, const bool bEnumSubDir, std::list<NR_IFileEnumResult *> & ResultList)
{
	bool bRet = false;
	WIN32_FIND_DATAW Win32FindData = { 0 };
	wchar_t szFindPath[MaxPathSize] = { 0 };
	wchar_t szResultExt[MaxPathSize] = { 0 };
	wchar_t szNextFindPath[MaxPathSize] = { 0 };
	wchar_t szResultPath[MaxPathSize] = { 0 };

	if (pszDirectory && pszFileExt)
	{
		wcscpy_s(szFindPath, _countof(szFindPath), pszDirectory);
		PathAddBackslashW(szFindPath);
		wcscat_s(szFindPath, _countof(szFindPath), L"*.*");

		auto hFind = FindFirstFileW(szFindPath, &Win32FindData);
		if (hFind)
		{
			do 
			{
				if (Win32FindData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
				{
					if (L'.' != Win32FindData.cFileName[0])
					{
						if (bEnumSubDir)
						{
							wcscpy_s(szNextFindPath, _countof(szNextFindPath), pszDirectory);
							PathAddBackslashW(szNextFindPath);
							wcscat_s(szNextFindPath, _countof(szNextFindPath), Win32FindData.cFileName);

							EnumAllFileW(szNextFindPath, pszFileExt, bEnumSubDir, ResultList);
						}
					}
				}
				else
				{
					memset(szResultExt, 0, sizeof(szResultExt));
					_wsplitpath_s(Win32FindData.cFileName, 0, 0, 0, 0, 0, 0, szResultExt, _countof(szResultExt));

					if (0 == _wcsicmp(L"*.*", pszFileExt) || 0 == _wcsicmp(szResultExt, pszFileExt))
					{
						wcscpy_s(szResultPath, _countof(szResultPath), pszDirectory);
						PathAddBackslashW(szResultPath);
						wcscat_s(szResultPath, _countof(szResultPath), Win32FindData.cFileName);

						auto pFindResult = NR_CWin32FileEnumResult::Make(szResultPath, Win32FindData.dwFileAttributes);
						if (pFindResult)
						{
							ResultList.push_back(pFindResult);
						}
					}
				}

			} while (FindNextFileW(hFind, &Win32FindData));

			FindClose(hFind);
			hFind = 0;

			bRet = true;
		}
	}

	return bRet;
}

bool NR_CWin32FileEnumerator::EnumAllDirectoryW(const wchar_t * pszDirectory, const bool bEnumSubDir, std::list<NR_IFileEnumResult *> & ResultList)
{
	bool bRet = false;
	WIN32_FIND_DATAW Win32FindData = { 0 };
	wchar_t szFindPath[MaxPathSize] = { 0 };
	wchar_t szNextFindPath[MaxPathSize] = { 0 };
	wchar_t szResultPath[MaxPathSize] = { 0 };

	if (pszDirectory)
	{
		wcscpy_s(szFindPath, _countof(szFindPath), pszDirectory);
		PathAddBackslashW(szFindPath);
		wcscat_s(szFindPath, _countof(szFindPath), L"*.*");

		auto hFind = FindFirstFileW(szFindPath, &Win32FindData);
		if (hFind)
		{
			do
			{
				if (Win32FindData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
				{
					if (L'.' != Win32FindData.cFileName[0])
					{
						wcscpy_s(szResultPath, _countof(szResultPath), pszDirectory);
						PathAddBackslashW(szResultPath);
						wcscat_s(szResultPath, _countof(szResultPath), Win32FindData.cFileName);

						auto pFindResult = NR_CWin32FileEnumResult::Make(szResultPath, Win32FindData.dwFileAttributes);
						if (pFindResult)
						{
							ResultList.push_back(pFindResult);
						}

						if (bEnumSubDir)
						{
							wcscpy_s(szNextFindPath, _countof(szNextFindPath), pszDirectory);
							PathAddBackslashW(szNextFindPath);
							wcscat_s(szNextFindPath, _countof(szNextFindPath), Win32FindData.cFileName);

							EnumAllDirectoryW(szNextFindPath, bEnumSubDir, ResultList);
						}
					}
				}

			} while (FindNextFileW(hFind, &Win32FindData));

			FindClose(hFind);
			hFind = 0;

			bRet = true;
		}
	}

	return bRet;
}

#endif
