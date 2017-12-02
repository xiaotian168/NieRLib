
#include "NR_CZipArchiverItem.h"

#if defined NR_PLATFORM_WIN32

NR_CZipArchiverItem * NR_CZipArchiverItem::Make(const HZIP hZip, const int nItemIndex)
{
	return new NR_CZipArchiverItem(hZip, nItemIndex);
}

NR_CZipArchiverItem::NR_CZipArchiverItem(const HZIP hZip, const int nItemIndex)
{
	m_hZip = hZip;
	m_nItemIndex = nItemIndex;
}

NR_CZipArchiverItem::~NR_CZipArchiverItem()
{

}

bool NR_CZipArchiverItem::GetItemNameW(wchar_t * pszName, const unsigned int uSize)
{
	bool bRet = false;
	ZIPENTRY ZEntry = { 0 };

	if (m_hZip && pszName && uSize)
	{
		if (ZR_OK == GetZipItem(m_hZip, m_nItemIndex, &ZEntry))
		{
			// ZIPENTRY.name is TCHAR string, so ...

#if defined UNICODE || defined _UNICODE
			wcscpy_s(pszName, uSize, ZEntry.name);
			bRet = true;
#else
			auto pszNameW = NR_MultiByte2Unicode(ZEntry.name);
			if (pszNameW)
			{
				wcscpy_s(pszName, uSize, pszNameW);
				bRet = true;

				NR_FreeUnicodeString(pszNameW);
				pszNameW = 0;
			}
#endif
		}
	}

	return bRet;
}

bool NR_CZipArchiverItem::IsItemDirectory(void)
{
	bool bRet = false;
	ZIPENTRY ZEntry = { 0 };

	if (m_hZip)
	{
		if (ZR_OK == GetZipItem(m_hZip, m_nItemIndex, &ZEntry))
		{
			if (ZEntry.attr & FILE_ATTRIBUTE_DIRECTORY)
			{
				bRet = true;
			}
		}
	}

	return bRet;
}

#endif
