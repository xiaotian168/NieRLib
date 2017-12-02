
#include "CZipArchiverItem.h"

#if defined NIER_PLATFORM_WIN32

CZipArchiverItem * CZipArchiverItem::Make(const HZIP hZip, const int nItemIndex)
{
	return new CZipArchiverItem(hZip, nItemIndex);
}

CZipArchiverItem::CZipArchiverItem(const HZIP hZip, const int nItemIndex)
{
	m_hZip = hZip;
	m_nItemIndex = nItemIndex;
}

CZipArchiverItem::~CZipArchiverItem()
{

}

bool CZipArchiverItem::GetItemNameW(wchar_t * pszName, const unsigned int uSize)
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
			auto pszNameW = MultiByte2Unicode(ZEntry.name);
			if (pszNameW)
			{
				wcscpy_s(pszName, uSize, pszNameW);
				bRet = true;

				FreeUnicodeString(pszNameW);
				pszNameW = 0;
			}
#endif
		}
	}

	return bRet;
}

bool CZipArchiverItem::IsItemDirectory(void)
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
