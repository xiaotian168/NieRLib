
#pragma once

#include "IArchiverItem.h"
#include "zip/unzip.h"

class CZipArchiverItem : public IArchiverItem
{
public:

	friend class CZipArchiverUnpacker;

	static CZipArchiverItem * Make(const HZIP hZip, const int nItemIndex);

protected:

	CZipArchiverItem(const HZIP hZip, const int nItemIndex);

	~CZipArchiverItem();

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
