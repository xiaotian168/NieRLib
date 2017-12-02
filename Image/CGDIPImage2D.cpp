
#include "CGDIPImage2D.h"
#include "GDIPImageTool.h"

#if defined NIER_PLATFORM_WIN32

CGDIPImage2D * CGDIPImage2D::MakeFromFileW(const wchar_t * pszImageFilePath)
{
	return new CGDIPImage2D(pszImageFilePath);
}

CGDIPImage2D * CGDIPImage2D::MakeFromMemory(const void * pBuffer, const unsigned int uSize)
{
	return new CGDIPImage2D(pBuffer, uSize);
}

CGDIPImage2D::CGDIPImage2D(const wchar_t * pszImageFilePath)
{
	if(pszImageFilePath)
	{
		m_pImg = Gdiplus::Bitmap::FromFile(pszImageFilePath);
	}
}

CGDIPImage2D::CGDIPImage2D(const void * pBuffer, const unsigned int uSize)
{
	m_pImg = LoadGDIPImageFromBuffer(pBuffer, uSize);
}

CGDIPImage2D::~CGDIPImage2D()
{
	if(m_pImg)
	{
		delete m_pImg;
		m_pImg = 0;
	}
}

bool CGDIPImage2D::GetImageSize(unsigned int & uWidth, unsigned int & uHeight)
{
	bool bRet = false;

	if (m_pImg)
	{
		uWidth = static_cast<unsigned int>(m_pImg->GetWidth());
		uHeight = static_cast<unsigned int>(m_pImg->GetHeight());

		bRet = true;
	}

	return bRet;
}

#endif
