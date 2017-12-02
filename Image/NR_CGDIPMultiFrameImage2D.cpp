
#include "NR_CGDIPMultiFrameImage2D.h"
#include "NR_GDIPImageTool.h"

#if defined NIER_PLATFORM_WIN32

NR_CGDIPMultiFrameImage2D * NR_CGDIPMultiFrameImage2D::MakeFromFileW(const wchar_t * pszImageFilePath)
{
	return new NR_CGDIPMultiFrameImage2D(pszImageFilePath);
}

NR_CGDIPMultiFrameImage2D * NR_CGDIPMultiFrameImage2D::MakeFromMemory(const void * pBuffer, const unsigned int uSize)
{
	return new NR_CGDIPMultiFrameImage2D(pBuffer, uSize);
}

NR_CGDIPMultiFrameImage2D::NR_CGDIPMultiFrameImage2D(const wchar_t * pszImageFilePath)
{
	memset(&m_GUIDFirstDimension, 0, sizeof(m_GUIDFirstDimension));

	if (pszImageFilePath)
	{
		m_pImg = Gdiplus::Bitmap::FromFile(pszImageFilePath);
		if (m_pImg)
		{
			PrepareImageFrameInfo();
		}
	}
}

NR_CGDIPMultiFrameImage2D::NR_CGDIPMultiFrameImage2D(const void * pBuffer, const unsigned int uSize)
{
	memset(&m_GUIDFirstDimension, 0, sizeof(m_GUIDFirstDimension));

	m_pImg = NR_LoadGDIPImageFromBuffer(pBuffer, uSize);
	if (m_pImg)
	{
		PrepareImageFrameInfo();
	}
}

NR_CGDIPMultiFrameImage2D::~NR_CGDIPMultiFrameImage2D()
{

}

unsigned int NR_CGDIPMultiFrameImage2D::GetFrameNum(void)
{
	return m_FrameInfoList.size();
}

bool NR_CGDIPMultiFrameImage2D::GetFrameElapse(const unsigned int uFrameIndex, unsigned int & uElapse)
{
	bool bRet = false;

	if (m_pImg && uFrameIndex < m_FrameInfoList.size())
	{
		uElapse = m_FrameInfoList[uFrameIndex].uFrameElapse;
	}

	return bRet;
}

bool NR_CGDIPMultiFrameImage2D::PrepareImageFrameInfo(void)
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
