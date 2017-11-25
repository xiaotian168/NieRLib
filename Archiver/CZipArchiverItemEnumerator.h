
#pragma once

#include "IArchiverItemEnumerator.h"
#include "zip/unzip.h"

class CZipArchiverItemEnumerator : public IArchiverItemEnumerator
{
public:

	static CZipArchiverItemEnumerator * Make(const HZIP hZip);

protected:

	CZipArchiverItemEnumerator(const HZIP hZip);

	~CZipArchiverItemEnumerator();

public:

	bool BeginEnum(void) override;

	bool EndEnum(void) override;

	bool NextItem(void) override;

	IArchiverItem * GetCurrentItem(void) override;

private:

	HZIP m_hZip{ 0 };
	int m_nTotalItemNum{ 0 };
	int m_nItemIndex{ 0 };
};
