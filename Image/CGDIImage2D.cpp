
#include "CGDIImage2D.h"

#if defined NIER_PLATFORM_WIN32

CGDIImage2D * CGDIImage2D::MakeFromFileW(const wchar_t * pszFilePath)
{
	return new CGDIImage2D(pszFilePath);
}

CGDIImage2D::CGDIImage2D(const wchar_t * pszFilePath)
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

CGDIImage2D::~CGDIImage2D()
{
	if (m_hBmp)
	{
		DeleteObject(m_hBmp);
		m_hBmp = 0;
	}

	m_uWidth = 0;
	m_uHeight = 0;
}

bool CGDIImage2D::GetImageSize(unsigned int & uWidth, unsigned int & uHeight)
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
