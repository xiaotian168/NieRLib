
#define _NIER_API

#include "ShortcutTool.h"
#include "IShortcut.h"
#include "IShortcutManager.h"
#include "ShortcutManagerFactory.h"
#include "../StringConverter/StringConverterTool.h"
#include <Windows.h>

bool DeleteAllShortcutByTargetPathW(const wchar_t * pszSearchDirectory, const wchar_t * pszTargetPath)
{
	bool bRet = false;
	std::list<IShortcut *> ShortcutList;
	wchar_t szShortcutTargetPath[MAX_PATH] = { 0 };

	if (pszSearchDirectory && pszTargetPath)
	{
		auto pShortcutMgr = MakeShortcutManagerByOSPlatform();
		if (pShortcutMgr)
		{
			if (pShortcutMgr->SearchShortcutW(pszSearchDirectory, ShortcutList))
			{
				for (auto pShortcut : ShortcutList)
				{
					if (pShortcut)
					{
						if (pShortcut->GetTargetPathW(szShortcutTargetPath, _countof(szShortcutTargetPath)))
						{
							if (0 == _wcsicmp(pszTargetPath, szShortcutTargetPath))
							{
								pShortcut->Delete();

								bRet = true;
							}
						}

						SAFE_RELEASE(pShortcut);
					}
				}
			}

			SAFE_RELEASE(pShortcutMgr);
		}
	}

	return bRet;
}

bool DeleteAllShortcutByTargetPathA(const char * pszSearchDirectory, const char * pszTargetPath)
{
	bool bRet = false;

	if (pszSearchDirectory && pszTargetPath)
	{
		auto pszSearchDirectoryW = MultiByte2Unicode(pszSearchDirectory);
		if (pszSearchDirectoryW)
		{
			auto pszTargetPathW = MultiByte2Unicode(pszTargetPath);
			if (pszTargetPathW)
			{
				if (DeleteAllShortcutByTargetPathW(pszSearchDirectoryW, pszTargetPathW))
				{
					bRet = true;
				}

				FreeMultiByteString(pszTargetPath);
				pszTargetPath = 0;
			}

			FreeUnicodeString(pszSearchDirectoryW);
			pszSearchDirectoryW = 0;
		}
	}

	return bRet;
}
