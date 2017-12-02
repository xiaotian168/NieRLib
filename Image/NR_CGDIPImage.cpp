
#include "NR_CGDIPImage.h"
#include "NR_GDIPImageTool.h"

#if defined NR_PLATFORM_WIN32

NR_CGDIPImage * NR_CGDIPImage::MakeFromFileW(const wchar_t * pszImageFilePath)
{
	return new NR_CGDIPImage(pszImageFilePath);
}

NR_CGDIPImage * NR_CGDIPImage::MakeFromMemory(const void * pBuffer, const unsigned int uSize)
{
	return new NR_CGDIPImage(pBuffer, uSize);
}

NR_CGDIPImage::NR_CGDIPImage(const wchar_t * pszImageFilePath)
{
	if(pszImageFilePath)
	{
		m_pImg = Gdiplus::Bitmap::FromFile(pszImageFilePath);
	}
}

NR_CGDIPImage::NR_CGDIPImage(const void * pBuffer, const unsigned int uSize)
{
	m_pImg = NR_LoadGDIPImageFromBuffer(pBuffer, uSize);
}

NR_CGDIPImage::~NR_CGDIPImage()
{
	if(m_pImg)
	{
		delete m_pImg;
		m_pImg = 0;
	}
}

bool NR_CGDIPImage::GetImageSize(unsigned int & uWidth, unsigned int & uHeight)
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
