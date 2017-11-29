
#pragma once

#include "IArchiver.h"
#include "IArchiverUnpacker.h"
#include "zip/unzip.h"

class CZipArchiverUnpacker : public IArchiver, public IArchiverUnpacker
{
public:

	static CZipArchiverUnpacker * Make(void);

protected:

	CZipArchiverUnpacker();

	~CZipArchiverUnpacker();

public:

	bool OpenArchiverW(const wchar_t * pszArchiverPath, const char * pszPassword) override;

	bool CloseArchiver(void) override;

	bool SetDecompressPathW(const wchar_t * pszDecompressPath) override;

	bool Decompress(IWorkProgress * pWorkProgress) override;

	bool DecompressItem(IArchiverItem * pItem) override;

	IArchiverItemEnumerator * GetItemEnumerator(void) override;

private:

	HZIP m_hZip{ 0 };
};
