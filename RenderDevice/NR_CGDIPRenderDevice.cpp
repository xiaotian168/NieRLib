
#include "NR_CGDIPRenderDevice.h"
#include "NR_ARGB.h"
#include "../Image/NR_CGDIPImage.h"
#include "../Image/NR_CGDIPMultiFrameImage2D.h"
#include "../Font/NR_CGDIPFont.h"

#if defined NIER_PLATFORM_WIN32

NR_CGDIPRenderDevice * NR_CGDIPRenderDevice::Make(const HDC hDC)
{
	return new NR_CGDIPRenderDevice(hDC);
}

NR_CGDIPRenderDevice * NR_CGDIPRenderDevice::Make(const HWND hWnd)
{
	return new NR_CGDIPRenderDevice(hWnd);
}

NR_CGDIPRenderDevice::NR_CGDIPRenderDevice(const HDC hDC)
{
	m_pGraph = Gdiplus::Graphics::FromHDC(hDC);
}

NR_CGDIPRenderDevice::NR_CGDIPRenderDevice(const HWND hWnd)
{
	if (IsWindow(hWnd))
	{
		m_pGraph = Gdiplus::Graphics::FromHWND(hWnd);
	}
}

NR_CGDIPRenderDevice::~NR_CGDIPRenderDevice()
{
	if (m_pGraph)
	{
		delete m_pGraph;
		m_pGraph = 0;
	}
}

bool NR_CGDIPRenderDevice::SetClipRect(const int nX, const int nY, const int nWidth, const int nHeight)
{
	bool bRet = false;
	const Gdiplus::Rect rcClip(nX, nY, nX + nWidth, nY + nHeight);

	if(m_pGraph)
	{
		if (Gdiplus::Ok == m_pGraph->SetClip(rcClip))
		{
			bRet = true;
		}
	}

	return bRet;
}

bool NR_CGDIPRenderDevice::GetClipRect(int & nX, int & nY, int & nWidth, int & nHeight)
{
	bool bRet = false;
	Gdiplus::Rect rcClip;

	if (m_pGraph)
	{
		if (Gdiplus::Ok == m_pGraph->GetClipBounds(&rcClip))
		{
			nX = rcClip.X;
			nY = rcClip.Y;
			nWidth = rcClip.Width;
			nHeight = rcClip.Height;

			bRet = true;
		}
	}

	return bRet;
}

NR_IImage * NR_CGDIPRenderDevice::CreateImageFromFileW(const wchar_t * pszFilePath)
{
	if (pszFilePath)
	{
		return NR_CGDIPImage::MakeFromFileW(pszFilePath);
	}

	return 0;
}

NR_IImage * NR_CGDIPRenderDevice::CreateImageFromMemory(const void * pBuffer, const unsigned int uSize)
{
	if (pBuffer && uSize)
	{
		return NR_CGDIPImage::MakeFromMemory(pBuffer, uSize);
	}

	return 0;
}

NR_IFont * NR_CGDIPRenderDevice::CreateFontW(const wchar_t * pszFaceName, const unsigned int uWidth, const unsigned int uHeight, const unsigned int uWeight, const bool bItalic)
{
	if (pszFaceName)
	{
		return NR_CGDIPFont::MakeW(pszFaceName, uWidth, uHeight, uWeight, bItalic);
	}

	return 0;
}

bool NR_CGDIPRenderDevice::RenderImage(NR_IImage * pImage, const int nPosX, const int nPosY)
{
	bool bRet = false;

	if (m_pGraph && pImage)
	{
		auto pGDIPImage2D = dynamic_cast<NR_CGDIPImage *>(pImage);
		if (pGDIPImage2D)
		{
			auto pGDIPImage = pGDIPImage2D->GetGDIPImage();
			if (pGDIPImage)
			{
				if (Gdiplus::Ok == m_pGraph->DrawImage(pGDIPImage, nPosX, nPosY))
				{
					bRet = true;
				}
			}
		}
	}

	return bRet;
}

bool NR_CGDIPRenderDevice::RenderImage(NR_IImage * pImage, const int nDestPosX, const int nDestPosY, const int nDestWidth, const int nDestHeight, const int nSrcX, const int nSrcY, const int nSrcWidth, const int nSrcHeight)
{
	bool bRet = false;
	const Gdiplus::Rect rcDest(nDestPosX, nDestPosY, nDestWidth, nDestHeight);

	if (m_pGraph && pImage && nDestWidth && nDestHeight && nSrcWidth && nSrcHeight)
	{
		auto pGDIPImage2D = dynamic_cast<NR_CGDIPImage *>(pImage);
		if (pGDIPImage2D)
		{
			auto pGDIPImage = pGDIPImage2D->GetGDIPImage();
			if (pGDIPImage)
			{
				if (Gdiplus::Ok == m_pGraph->DrawImage(pGDIPImage, rcDest, nSrcX, nSrcY, nSrcWidth, nSrcHeight, Gdiplus::UnitPixel))
				{
					bRet = true;
				}
			}
		}
	}

	return bRet;
}

bool NR_CGDIPRenderDevice::RenderTextW(NR_IFont * pFont, const wchar_t * pszText, const int nLen, const int nPosX, const int nPosY, const unsigned int uWidth, const unsigned int uHeight, const unsigned int uColor, const int nFormat)
{
	bool bRet = false;
	Gdiplus::RectF rcLayout((Gdiplus::REAL)nPosX, (Gdiplus::REAL)nPosY, (Gdiplus::REAL)uWidth, (Gdiplus::REAL)uHeight);
	Gdiplus::Color TextColor;

	if (m_pGraph && pFont && pszText && uWidth && uHeight)
	{
		auto pGDIPFont = dynamic_cast<NR_CGDIPFont *>(pFont);
		if (pGDIPFont)
		{
			auto pStringFmt = ConvertTextFormat(nFormat);
			{
				TextColor.MakeARGB(NR_ARGB::GetA(uColor), NR_ARGB::GetR(uColor), NR_ARGB::GetG(uColor), NR_ARGB::GetB(uColor));

				auto pBrush = new Gdiplus::SolidBrush(TextColor);
				if (pBrush)
				{
					if (Gdiplus::Ok == m_pGraph->DrawString(pszText, nLen, pGDIPFont->GetGDIPFont(), rcLayout, pStringFmt, pBrush))
					{
						bRet = true;
					}

					delete pBrush;
					pBrush = 0;
				}

				if (pStringFmt)
				{
					delete pStringFmt;
					pStringFmt = 0;
				}
			}
		}
	}

	return bRet;
}

bool NR_CGDIPRenderDevice::CalcTextSizeW(NR_IFont * pFont, const wchar_t * pszText, const int nLen, const int nFormat, unsigned int & uWidth, unsigned int & uHeight)
{
	bool bRet = false;
	Gdiplus::PointF ptOrigin;
	Gdiplus::RectF rcText;

	if (m_pGraph && pFont && pszText)
	{
		auto pGDIPFont2D = dynamic_cast<NR_CGDIPFont *>(pFont);
		if (pGDIPFont2D)
		{
			auto pGDIPFont = pGDIPFont2D->GetGDIPFont();
			if (pGDIPFont)
			{
				auto pStringFmt = ConvertTextFormat(nFormat);
				{
					if (Gdiplus::Ok == m_pGraph->MeasureString(pszText, nLen, pGDIPFont, ptOrigin, pStringFmt, &rcText))
					{
						bRet = true;
					}

					if (pStringFmt)
					{
						delete pStringFmt;
						pStringFmt = 0;
					}
				}
			}
		}
	}

	return bRet;
}

bool NR_CGDIPRenderDevice::RenderLine(const int nX1, const int nY1, const int nX2, const int nY2, const unsigned int uColor)
{
	bool bRet = false;
	Gdiplus::Color LineColor;

	if (m_pGraph)
	{
		auto pPen = new Gdiplus::Pen(LineColor, 1);
		if (pPen)
		{
			LineColor.MakeARGB(NR_ARGB::GetA(uColor), NR_ARGB::GetR(uColor), NR_ARGB::GetG(uColor), NR_ARGB::GetB(uColor));

			if (Gdiplus::Ok == m_pGraph->DrawLine(pPen, Gdiplus::Point(nX1, nY1), Gdiplus::Point(nX2, nY2)))
			{
				bRet = true;
			}
				
			delete pPen;
			pPen = 0;
		}
	}

	return bRet;
}

bool NR_CGDIPRenderDevice::RenderQuad(const int nX, const int nY, const int nWidth, const int nHeight, const unsigned int uColor)
{
	bool bRet = false;
	Gdiplus::Color FillColor;
	const Gdiplus::Rect rcFill(nX, nY, nX + nWidth, nY + nHeight);

	if (m_pGraph && nWidth && nHeight)
	{
		FillColor.MakeARGB(NR_ARGB::GetA(uColor), NR_ARGB::GetR(uColor), NR_ARGB::GetG(uColor), NR_ARGB::GetB(uColor));

		auto pBrush = new Gdiplus::SolidBrush(FillColor);
		if (pBrush)
		{
			if (Gdiplus::Ok == m_pGraph->FillRectangle(pBrush, rcFill))
			{
				bRet = true;
			}

			delete pBrush;
			pBrush = 0;
		}
	}

	return bRet;
}

NR_IMultiFrameImage2D * NR_CGDIPRenderDevice::CreateMultiFrameImageFromFileW(const wchar_t * pszFile)
{
	return NR_CGDIPMultiFrameImage2D::MakeFromFileW(pszFile);
}

NR_IMultiFrameImage2D * NR_CGDIPRenderDevice::CreateMultiFrameImageFromMemory(const void * pBuffer, const unsigned uSize)
{
	return NR_CGDIPMultiFrameImage2D::MakeFromMemory(pBuffer, uSize);
}

bool NR_CGDIPRenderDevice::RenderMultiFrameImage(NR_IMultiFrameImage2D * pImage, const unsigned int uFrameIndex, const int nPosX, const int nPosY)
{
	bool bRet = false;

	if (m_pGraph && pImage)
	{
		auto pMultiFrameImage = dynamic_cast<NR_CGDIPMultiFrameImage2D *>(pImage);
		if (pMultiFrameImage)
		{
			auto pGDIPImage = pMultiFrameImage->GetGDIPImage();
			if (pGDIPImage)
			{
				const auto GuidFirstDim = pMultiFrameImage->GetGUIDFirstDimension();

				if (Gdiplus::Ok == pGDIPImage->SelectActiveFrame(&GuidFirstDim, uFrameIndex))
				{
					if (Gdiplus::Ok == m_pGraph->DrawImage(pGDIPImage, nPosX, nPosY))
					{
						bRet = true;
					}
				}
			}
		}
	}

	return bRet;
}

Gdiplus::StringFormat * NR_CGDIPRenderDevice::ConvertTextFormat(const int nFormat) const
{
	if (nFormat)
	{
		auto pFmt = new Gdiplus::StringFormat();
		if (pFmt)
		{
			if (nFormat & eTextFmt_Left) pFmt->SetAlignment(Gdiplus::StringAlignmentNear);
			else if (nFormat & eTextFmt_Right) pFmt->SetAlignment(Gdiplus::StringAlignmentFar);
			else if (nFormat & eTextFmt_HCenter) pFmt->SetAlignment(Gdiplus::StringAlignmentCenter);

			if (nFormat & eTextFmt_Top) pFmt->SetLineAlignment(Gdiplus::StringAlignmentNear);
			else if (nFormat & eTextFmt_Bottom) pFmt->SetLineAlignment(Gdiplus::StringAlignmentFar);
			else if (nFormat & eTextFmt_VCenter) pFmt->SetLineAlignment(Gdiplus::StringAlignmentCenter);			

			if (nFormat & eTextFmt_PathEllipsis) pFmt->SetTrimming(Gdiplus::StringTrimmingEllipsisPath);
			else if (nFormat & eTextFmt_WordEllipsis) pFmt->SetTrimming(Gdiplus::StringTrimmingEllipsisWord);

			return pFmt;
		}
	}

	return 0;
}

#endif
