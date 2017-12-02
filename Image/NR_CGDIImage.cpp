
#include "NR_CGDIImage.h"

#if defined NR_PLATFORM_WIN32

NR_CGDIImage * NR_CGDIImage::MakeFromFileW(const wchar_t * pszFilePath)
{
	return new NR_CGDIImage(pszFilePath);
}

NR_CGDIImage * NR_CGDIImage::MakeFromMemory(const void * pBuffer, const unsigned int uSize)
{
	return new NR_CGDIImage(pBuffer, uSize);
}

NR_CGDIImage::NR_CGDIImage(const wchar_t * pszFilePath)
{
	BITMAP Bmp = { 0 };

	if (pszFilePath)
	{
		m_hBmp = (HBITMAP)LoadImageW(0, pszFilePath, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_DEFAULTSIZE);
		if (m_hBmp)
		{
			if (GetObjectW(m_hBmp, sizeof(Bmp), &Bmp))
			{
				m_uWidth = Bmp.bmWidth;
				m_uHeight = Bmp.bmHeight < 0 ? -Bmp.bmHeight : Bmp.bmHeight;
			}
		}
	}
}

NR_CGDIImage::NR_CGDIImage(const void * pBuffer, const unsigned int uSize)
{
	if (pBuffer && uSize)
	{

	}
}

NR_CGDIImage::~NR_CGDIImage()
{
	if (m_hBmp)
	{
		DeleteObject(m_hBmp);
		m_hBmp = 0;
	}

	m_uWidth = 0;
	m_uHeight = 0;
}

bool NR_CGDIImage::GetImageSize(unsigned int & uWidth, unsigned int & uHeight)
{
	bool bRet = false;

	if (m_hBmp && m_uWidth && m_uHeight)
	{
		uWidth = m_uWidth;
		uHeight = m_uHeight;

		bRet = true;
	}

	return bRet;
}

#endif
