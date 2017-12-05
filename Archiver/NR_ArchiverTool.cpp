
#define _NR_API

#include "NR_ArchiverTool.h"
#include "NR_IArchiver.h"
#include "NR_IArchiverUnpacker.h"
#include "NR_IArchiverItem.h"
#include "NR_IArchiverItemEnumerator.h"
#include "NR_ArchiverFactory.h"

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

					NR_SAFE_RELEASE(pItem);
				}
				else
				{
					break;
				}
			}

			pItemEnumerator->EndEnum();
		}

		NR_SAFE_RELEASE(pItemEnumerator);
	}

	return bRet;
}

bool NR_UnpackZipArchiverW(const wchar_t * pszArchiverPath, const char * pszPassword, const wchar_t * pszUnpackDirectory)
{
	bool bRet = false;

	if (pszArchiverPath && pszUnpackDirectory)
	{
		auto pArchiverUnpacker = NR_MakeZipArchiverUnpackerByOSPlatform();
		if (pArchiverUnpacker)
		{
			auto pArchiver = dynamic_cast<NR_IArchiver *>(pArchiverUnpacker);
			if (pArchiver)
			{
				if (pArchiver->OpenArchiverW(pszArchiverPath, pszPassword))
				{
					if (pArchiverUnpacker->SetDecompressPathW(pszUnpackDirectory))
					{
						if (pArchiverUnpacker->Decompress(0))
						{
							bRet = true;
						}
					}

					pArchiver->CloseArchiver();
				}
			}

			NR_SAFE_RELEASE(pArchiverUnpacker);
		}
	}

	return bRet;
}
