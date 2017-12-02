
#include "CGDIPMultiFrameImage2D.h"
#include "GDIPImageTool.h"

#if defined NIER_PLATFORM_WIN32

CGDIPMultiFrameImage2D * CGDIPMultiFrameImage2D::MakeFromFileW(const wchar_t * pszImageFilePath)
{
	return new CGDIPMultiFrameImage2D(pszImageFilePath);
}

CGDIPMultiFrameImage2D * CGDIPMultiFrameImage2D::MakeFromMemory(const void * pBuffer, const unsigned int uSize)
{
	return new CGDIPMultiFrameImage2D(pBuffer, uSize);
}

CGDIPMultiFrameImage2D::CGDIPMultiFrameImage2D(const wchar_t * pszImageFilePath)
{
	if (pszImageFilePath)
	{
		m_pImg = Gdiplus::Bitmap::FromFile(pszImageFilePath);
		if (m_pImg)
		{
			PrepareImageFrameInfo();
		}
	}
}

CGDIPMultiFrameImage2D::CGDIPMultiFrameImage2D(const void * pBuffer, const unsigned int uSize)
{
	m_pImg = LoadGDIPImageFromBuffer(pBuffer, uSize);
	if (m_pImg)
	{
		PrepareImageFrameInfo();
	}
}

CGDIPMultiFrameImage2D::~CGDIPMultiFrameImage2D()
{

}

unsigned int CGDIPMultiFrameImage2D::GetFrameNum(void)
{
	return m_FrameInfoList.size();
}

bool CGDIPMultiFrameImage2D::GetFrameElapse(const unsigned int uFrameIndex, unsigned int & uElapse)
{
	bool bRet = false;

	if (m_pImg && uFrameIndex < m_FrameInfoList.size())
	{
		uElapse = m_FrameInfoList[uFrameIndex].uFrameElapse;
	}

	return bRet;
}

bool CGDIPMultiFrameImage2D::PrepareImageFrameInfo(void)
{
	bool bRet = false;

	m_FrameInfoList.clear();
	m_GUIDFirstDimension = GUID();

	if (m_pImg)
	{
		if (Gdiplus::Ok == m_pImg->GetFrameDimensionsList(&m_GUIDFirstDimension, 1))
		{
			m_FrameInfoList.resize(m_pImg->GetFrameCount(&m_GUIDFirstDimension));
			if (m_FrameInfoList.size())
			{
				const unsigned int uPropertyItemSize = m_pImg->GetPropertyItemSize(PropertyTagFrameDelay);
				if (uPropertyItemSize)
				{
					auto pPrppertyList = static_cast<Gdiplus::PropertyItem *>(malloc(uPropertyItemSize));
					if (pPrppertyList)
					{
						if (Gdiplus::Ok == m_pImg->GetPropertyItem(PropertyTagFrameDelay, uPropertyItemSize, pPrppertyList))
						{
							if (PropertyTagTypeLong == pPrppertyList->type)
							{
								long * pLongValueList = static_cast<long *>(pPrppertyList->value);
								if (pLongValueList)
								{
									for (unsigned int i = 0; i < m_FrameInfoList.size(); ++i)
									{
										m_FrameInfoList[i].uFrameElapse = pLongValueList[i] * 10;
									}

									bRet = true;
								}
							}
						}

						free(pPrppertyList);
						pPrppertyList = 0;
					}
				}
			}
		}
	}

	return bRet;
}

#endif
