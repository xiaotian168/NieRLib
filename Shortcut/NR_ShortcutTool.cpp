
#define _NR_API

#include "NR_ShortcutTool.h"
#include "NR_IShortcut.h"
#include "NR_IShortcutManager.h"
#include "NR_ShortcutManagerFactory.h"
#include "../StringConverter/NR_StringConverterTool.h"

bool NR_DeleteAllShortcutByTargetPathW(const wchar_t * pszSearchDirectory, const wchar_t * pszTargetPath)
{
	bool bRet = false;
	std::list<NR_IShortcut *> ShortcutList;
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

bool NR_DeleteAllShortcutByTargetPathA(const char * pszSearchDirectory, const char * pszTargetPath)
{
	bool bRet = false;

	if (pszSearchDirectory && pszTargetPath)
	{
		auto pszSearchDirectoryW = NR_MultiByte2Unicode(pszSearchDirectory);
		if (pszSearchDirectoryW)
		{
			auto pszTargetPathW = NR_MultiByte2Unicode(pszTargetPath);
			if (pszTargetPathW)
			{
				if (NR_DeleteAllShortcutByTargetPathW(pszSearchDirectoryW, pszTargetPathW))
				{
					bRet = true;
				}

				NR_FreeMultiByteString(pszTargetPath);
				pszTargetPath = 0;
			}

			NR_FreeUnicodeString(pszSearchDirectoryW);
			pszSearchDirectoryW = 0;
		}
	}

	return bRet;
}
