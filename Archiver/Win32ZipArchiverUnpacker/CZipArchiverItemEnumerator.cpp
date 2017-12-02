
#include "CZipArchiverItemEnumerator.h"
#include "CZipArchiverItem.h"

#if defined NIER_PLATFORM_WIN32

CZipArchiverItemEnumerator * CZipArchiverItemEnumerator::Make(const HZIP hZip)
{
	return new CZipArchiverItemEnumerator(hZip);
}

CZipArchiverItemEnumerator::CZipArchiverItemEnumerator(const HZIP hZip)
{
	m_hZip = hZip;
}

CZipArchiverItemEnumerator::~CZipArchiverItemEnumerator()
{

}

bool CZipArchiverItemEnumerator::BeginEnum(void)
{
	bool bRet = false;
	ZIPENTRY ZEntry = { 0 };

	if (m_hZip)
	{
		if (ZR_OK == GetZipItem(m_hZip, -1, &ZEntry))
		{
			m_nTotalItemNum = ZEntry.index;
			m_nItemIndex = 0;

			bRet = true;
		}
	}

	return bRet;
}

bool CZipArchiverItemEnumerator::EndEnum(void)
{
	bool bRet = false;

	if (m_hZip)
	{
		m_nTotalItemNum = 0;
		m_nItemIndex = 0;

		bRet = true;
	}

	return bRet;
}

bool CZipArchiverItemEnumerator::NextItem(void)
{
	bool bRet = false;

	if (m_hZip && m_nTotalItemNum && m_nItemIndex < m_nTotalItemNum)
	{
		++m_nItemIndex;

		bRet = true;
	}

	return bRet;
}

IArchiverItem * CZipArchiverItemEnumerator::GetCurrentItem(void)
{
	if (m_hZip && m_nTotalItemNum && m_nItemIndex < m_nTotalItemNum)
	{
		return CZipArchiverItem::Make(m_hZip, m_nItemIndex);
	}

	return 0;
}

#endif
