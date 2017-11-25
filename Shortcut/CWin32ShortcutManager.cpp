
#define _NIER_API

#include "CWin32ShortcutManager.h"
#include "CWin32Shortcut.h"
#include <shobjidl.h>
#include <string>
#include <shlwapi.h>

#pragma comment(lib, "shlwapi.lib")

CWin32ShortcutManager * CWin32ShortcutManager::Make(void)
{
	return new CWin32ShortcutManager();
}

CWin32ShortcutManager::CWin32ShortcutManager()
{

}

CWin32ShortcutManager::~CWin32ShortcutManager()
{

}

bool CWin32ShortcutManager::SearchShortcutW(const wchar_t * pszSearchDirectory, std::list<IShortcut *> & ShortcutList)
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

				auto pShortcut = CWin32Shortcut::Make(szShortcutFilePath);
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
