
#pragma once

#include "../NR_IArchiver.h"
#include "../NR_IArchiverUnpacker.h"

#if defined NIER_PLATFORM_WIN32

#include "zip/unzip.h"

class NR_CZipArchiverUnpacker : public NR_IArchiver, public NR_IArchiverUnpacker
{
public:

	static NR_CZipArchiverUnpacker * Make(void);

protected:

	NR_CZipArchiverUnpacker();

	~NR_CZipArchiverUnpacker();

public:

	bool OpenArchiverW(const wchar_t * pszArchiverPath, const char * pszPassword) override;

	bool CloseArchiver(void) override;

	bool SetDecompressPathW(const wchar_t * pszDecompressPath) override;

	bool Decompress(NR_IWorkProgress * pWorkProgress) override;

	bool DecompressItem(NR_IArchiverItem * pItem) override;

	NR_IArchiverItemEnumerator * GetItemEnumerator(void) override;

private:

	HZIP m_hZip{ 0 };
};

#endif
