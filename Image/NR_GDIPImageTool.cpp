
#define _NR_API

#include "NR_GDIPImageTool.h"
#include "../Base/NR_IRefCount.h"

#if defined NR_PLATFORM_WIN32

Gdiplus::Bitmap * NR_LoadGDIPImageFromBuffer(const void * pBuffer, const unsigned int uSize)
{
	IStream * pIStream = 0;
	Gdiplus::Bitmap * pImg = 0;

	if (pBuffer && uSize)
	{
		auto hGlobal = GlobalAlloc(GMEM_FIXED, uSize);
		if (hGlobal)
		{
			auto pGlobal = GlobalLock(hGlobal);
			if (pGlobal)
			{
				if (SUCCEEDED(CreateStreamOnHGlobal(hGlobal, FALSE, &pIStream)))
				{
					pImg = Gdiplus::Bitmap::FromStream(pIStream);

					NR_SAFE_RELEASE(pIStream);
				}

				GlobalUnlock(hGlobal);
				pGlobal = 0;
			}

			GlobalFree(hGlobal);
			hGlobal = 0;
		}
	}

	return pImg;
}

#endif
