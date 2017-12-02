
#pragma once

#include "../NR_IArchiverItem.h"

#if defined NR_PLATFORM_WIN32

#include "zip/unzip.h"

class NR_CZipArchiverItem : public NR_IArchiverItem
{
public:

	friend class NR_CZipArchiverUnpacker;

	static NR_CZipArchiverItem * Make(const HZIP hZip, const int nItemIndex);

protected:

	NR_CZipArchiverItem(const HZIP hZip, const int nItemIndex);

	~NR_CZipArchiverItem();

public:

	bool GetItemNameW(wchar_t * pszName, const unsigned int uSize) override;

	bool IsItemDirectory(void) override;

private:

	inline HZIP GetZipHandle(void) const
	{
		return m_hZip;
	}

	inline int GetItemIndex(void) const
	{
		return m_nItemIndex;
	}

private:

	HZIP m_hZip{ 0 };
	int m_nItemIndex{ 0 };
};

#endif
