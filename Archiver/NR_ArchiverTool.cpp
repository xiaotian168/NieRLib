
#define _NR_API

#include "NR_ArchiverTool.h"
#include "NR_IArchiver.h"
#include "NR_IArchiverItem.h"
#include "NR_IArchiverItemEnumerator.h"

bool NR_UnpackAllArchiverItemW(NR_IArchiver * pArchiver, std::list<std::wstring> & ItemPathList)
{
	bool bRet = false;
	wchar_t szItemName[MAX_PATH * 4] = { 0 };

	auto pItemEnumerator = pArchiver->GetItemEnumerator();
	if (pItemEnumerator)
	{
		if (pItemEnumerator->BeginEnum())
		{
			while (true)
			{
				auto pItem = pItemEnumerator->GetCurrentItem();
				if (pItem)
				{
					if (pItem->GetItemNameW(szItemName, _countof(szItemName)))
					{
						ItemPathList.push_back(szItemName);

						bRet = true;
					}

					if (!pItemEnumerator->NextItem())
					{
						break;
					}

					SAFE_RELEASE(pItem);
				}
				else
				{
					break;
				}
			}

			pItemEnumerator->EndEnum();
		}

		SAFE_RELEASE(pItemEnumerator);
	}

	return bRet;
}
