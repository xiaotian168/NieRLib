
#define _NIER_API

#include "GDIPImageTool.h"
#include "../Base/IRefCount.h"

#if defined NIER_PLATFORM_WIN32

Gdiplus::Bitmap * LoadGDIPImageFromBuffer(const void * pBuffer, const unsigned int uSize)
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

					SAFE_RELEASE(pIStream);
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
