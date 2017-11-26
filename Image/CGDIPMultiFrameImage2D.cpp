
#include "CGDIPMultiFrameImage2D.h"

#if defined NIER_PLATFORM_WIN32

CGDIPMultiFrameImage2D * CGDIPMultiFrameImage2D::MakeFromFileW(const wchar_t * pszImageFilePath)
{
	return new CGDIPMultiFrameImage2D(pszImageFilePath);
}

CGDIPMultiFrameImage2D::CGDIPMultiFrameImage2D(const wchar_t * pszImageFilePath)
{
	if (pszImageFilePath)
	{

	}
}

CGDIPMultiFrameImage2D::~CGDIPMultiFrameImage2D()
{

}

unsigned int CGDIPMultiFrameImage2D::GetFrameNum(void)
{
	return m_FrameInfoList.size();
}

IImage2D * CGDIPMultiFrameImage2D::GetFrameImage(const unsigned int uFrameIndex)
{
	if (m_pImg && uFrameIndex < m_FrameInfoList.size())
	{
		return m_FrameInfoList[uFrameIndex].pImg;
	}

	return 0;
}

unsigned int CGDIPMultiFrameImage2D::GetFrameElapse(const unsigned int uFrameIndex)
{
	if (m_pImg && uFrameIndex < m_FrameInfoList.size())
	{
		return m_FrameInfoList[uFrameIndex].uFrameElapse;
	}

	return 0;
}

#endif
