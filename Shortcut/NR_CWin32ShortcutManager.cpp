
#define _NR_API

#include "NR_CWin32ShortcutManager.h"
#include "NR_CWin32Shortcut.h"

#if defined NR_PLATFORM_WIN32

NR_CWin32ShortcutManager * NR_CWin32ShortcutManager::Make(void)
{
	return new NR_CWin32ShortcutManager();
}

NR_CWin32ShortcutManager::NR_CWin32ShortcutManager()
{

}

NR_CWin32ShortcutManager::~NR_CWin32ShortcutManager()
{

}

bool NR_CWin32ShortcutManager::SearchShortcutW(const wchar_t * pszSearchDirectory, std::list<NR_IShortcut *> & ShortcutList)
{
	bool bRet = false;
	WIN32_FIND_DATAW Win32FindData = { 0 };
	wchar_t szSearchDirectoryTemp[MAX_PATH] = { 0 };
	wchar_t szShortcutFilePath[MAX_PATH] = { 0 };

	if (pszSearchDirectory)
	{
		wcscpy_s(szSearchDirectoryTemp, _countof(szSearchDirectoryTemp), pszSearchDirectory);
		PathAddBackslashW(szSearchDirectoryTemp);
		wcscat_s(szSearchDirectoryTemp, _countof(szSearchDirectoryTemp), L"*.lnk");

		auto hFind = FindFirstFileW(szSearchDirectoryTemp, &Win32FindData);
		if (hFind)
		{
			do 
			{
				wcscpy_s(szShortcutFilePath, _countof(szShortcutFilePath), pszSearchDirectory);
				PathAddBackslashW(szShortcutFilePath);
				wcscat_s(szShortcutFilePath, _countof(szShortcutFilePath), Win32FindData.cFileName);

				auto pShortcut = NR_CWin32Shortcut::Make(szShortcutFilePath);
				if (pShortcut)
				{
					ShortcutList.push_back(pShortcut);
					bRet = true;
				}

			} while (FindNextFileW(hFind, &Win32FindData));

			FindClose(hFind);
			hFind = 0;
		}
	}

	return bRet;
}

#endif
