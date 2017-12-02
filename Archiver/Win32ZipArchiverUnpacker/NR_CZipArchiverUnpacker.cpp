
#include "NR_CZipArchiverUnpacker.h"
#include "NR_CZipArchiverItemEnumerator.h"
#include "NR_CZipArchiverItem.h"
#include "../../Base/NR_IWorkProgress.h"

#if defined NR_PLATFORM_WIN32

NR_CZipArchiverUnpacker * NR_CZipArchiverUnpacker::Make(void)
{
	return new NR_CZipArchiverUnpacker();
}

NR_CZipArchiverUnpacker::NR_CZipArchiverUnpacker()
{

}

NR_CZipArchiverUnpacker::~NR_CZipArchiverUnpacker()
{

}

bool NR_CZipArchiverUnpacker::OpenArchiverW(const wchar_t * pszArchiverPath, const char * pszPassword)
{
	bool bRet = false;
	if (!m_hZip && pszArchiverPath)
	{
#if defined UNICODE || defined _UNICODE
		m_hZip = OpenZip(pszArchiverPath, pszPassword);
#else
		auto pszArchiverPathA = NR_Unicode2MultiByte(pszArchiverPath);
		if (pszArchiverPathA)
		{
			m_hZip = OpenZip(pszArchiverPathA, pszPassword);

			NR_FreeMultiByteString(pszArchiverPathA);
			pszArchiverPathA = 0;
		}
#endif

		if (m_hZip)
		{
			bRet = true;
		}
	}

	return bRet;
}

bool NR_CZipArchiverUnpacker::CloseArchiver(void)
{
	bool bRet = false;

	if (m_hZip)
	{
		if (ZR_OK == CloseZip(m_hZip))
		{
			m_hZip = 0;
		}
	}

	return bRet;
}

bool NR_CZipArchiverUnpacker::SetDecompressPathW(const wchar_t * pszDecompressPath)
{
	bool bRet = false;
	ZRESULT zRet = ZR_OK;

	if (m_hZip && pszDecompressPath)
	{
		// god dammit TCHAR ...

#if defined UNICODE || defined _UNICODE
		zRet = SetUnzipBaseDir(m_hZip, pszDecompressPath);
#else
		auto pszDecompressPathA = NR_Unicode2MultiByte(pszDecompressPath);
		if (pszDecompressPathA)
		{
			zRet = SetUnzipBaseDir(m_hZip, pszDecompressPathA);

			NR_FreeMultiByteString(pszDecompressPath);
			pszDecompressPath = 0;
		}
#endif

		if (ZR_OK == zRet)
		{
			bRet = true;
		}
	}

	return bRet;
}

bool NR_CZipArchiverUnpacker::Decompress(NR_IWorkProgress * pWorkProgress)
{
	bool bRet = false;
	ZIPENTRY ZEntry = { 0 };
	int nItemIndex = 0;
	int nTotalItemNum = 0;

	if (m_hZip)
	{
		if (ZR_OK == GetZipItem(m_hZip, -1, &ZEntry))
		{
			nTotalItemNum = ZEntry.index;

			if (pWorkProgress)
			{
				pWorkProgress->SetMaxProgress(static_cast<NR_IWorkProgress::ProgressType>(nTotalItemNum));
				pWorkProgress->SetProgress(0);
			}

			while (ZR_OK == GetZipItem(m_hZip, nItemIndex, &ZEntry))
			{
				if (ZR_OK == UnzipItem(m_hZip, nItemIndex, ZEntry.name))
				{
					++nItemIndex;

					if (pWorkProgress)
					{
						pWorkProgress->SetProgress(static_cast<NR_IWorkProgress::ProgressType>(nItemIndex));
						pWorkProgress->OnProgress();
					}
				}
				else
				{
					break;
				}
			}

			if (nItemIndex == nTotalItemNum)
			{
				bRet = true;
			}
		}
	}

	return bRet;
}

bool NR_CZipArchiverUnpacker::DecompressItem(NR_IArchiverItem * pItem)
{
	bool bRet = false;
	ZIPENTRY ZEntry = { 0 };

	if (m_hZip && pItem)
	{
		auto pZipItem = dynamic_cast<NR_CZipArchiverItem *>(pItem);
		if (pZipItem && m_hZip == pZipItem->GetZipHandle())
		{
			if (ZR_OK == GetZipItem(m_hZip, pZipItem->GetItemIndex(), &ZEntry))
			{
				if (ZR_OK == UnzipItem(m_hZip, pZipItem->GetItemIndex(), ZEntry.name))
				{
					bRet = true;
				}
			}
		}
	}

	return bRet;
}

NR_IArchiverItemEnumerator * NR_CZipArchiverUnpacker::GetItemEnumerator(void)
{
	return NR_CZipArchiverItemEnumerator::Make(m_hZip);
}

#endif
