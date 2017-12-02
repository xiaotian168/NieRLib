
#pragma once

#include "../NR_IArchiverItemEnumerator.h"

#if defined NR_PLATFORM_WIN32

#include "zip/unzip.h"

class NR_CZipArchiverItemEnumerator : public NR_IArchiverItemEnumerator
{
public:

	static NR_CZipArchiverItemEnumerator * Make(const HZIP hZip);

protected:

	NR_CZipArchiverItemEnumerator(const HZIP hZip);

	~NR_CZipArchiverItemEnumerator();

public:

	bool BeginEnum(void) override;

	bool EndEnum(void) override;

	bool NextItem(void) override;

	NR_IArchiverItem * GetCurrentItem(void) override;

private:

	HZIP m_hZip{ 0 };
	int m_nTotalItemNum{ 0 };
	int m_nItemIndex{ 0 };
};

#endif
