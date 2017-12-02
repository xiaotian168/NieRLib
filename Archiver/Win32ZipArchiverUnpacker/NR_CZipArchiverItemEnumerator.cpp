
#include "NR_CZipArchiverItemEnumerator.h"
#include "NR_CZipArchiverItem.h"

#if defined NR_PLATFORM_WIN32

NR_CZipArchiverItemEnumerator * NR_CZipArchiverItemEnumerator::Make(const HZIP hZip)
{
	return new NR_CZipArchiverItemEnumerator(hZip);
}

NR_CZipArchiverItemEnumerator::NR_CZipArchiverItemEnumerator(const HZIP hZip)
{
	m_hZip = hZip;
}

NR_CZipArchiverItemEnumerator::~NR_CZipArchiverItemEnumerator()
{

}

bool NR_CZipArchiverItemEnumerator::BeginEnum(void)
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

bool NR_CZipArchiverItemEnumerator::EndEnum(void)
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

bool NR_CZipArchiverItemEnumerator::NextItem(void)
{
	bool bRet = false;

	if (m_hZip && m_nTotalItemNum && m_nItemIndex < m_nTotalItemNum)
	{
		++m_nItemIndex;

		bRet = true;
	}

	return bRet;
}

NR_IArchiverItem * NR_CZipArchiverItemEnumerator::GetCurrentItem(void)
{
	if (m_hZip && m_nTotalItemNum && m_nItemIndex < m_nTotalItemNum)
	{
		return NR_CZipArchiverItem::Make(m_hZip, m_nItemIndex);
	}

	return 0;
}

#endif
