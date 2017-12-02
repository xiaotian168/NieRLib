
#include "CGDIPRenderDevice.h"
#include "ARGB.h"
#include "../Image/CGDIPImage2D.h"
#include "../Image/CGDIPMultiFrameImage2D.h"
#include "../Font/CGDIPFont2D.h"

#if defined NIER_PLATFORM_WIN32

CGDIPRenderDevice * CGDIPRenderDevice::Make(const HDC hDC)
{
	return new CGDIPRenderDevice(hDC);
}

CGDIPRenderDevice * CGDIPRenderDevice::Make(const HWND hWnd)
{
	return new CGDIPRenderDevice(hWnd);
}

CGDIPRenderDevice::CGDIPRenderDevice(const HDC hDC)
{
	m_pGraph = Gdiplus::Graphics::FromHDC(hDC);
}

CGDIPRenderDevice::CGDIPRenderDevice(const HWND hWnd)
{
	if (IsWindow(hWnd))
	{
		m_pGraph = Gdiplus::Graphics::FromHWND(hWnd);
	}
}

CGDIPRenderDevice::~CGDIPRenderDevice()
{
	if (m_pGraph)
	{
		delete m_pGraph;
		m_pGraph = 0;
	}
}

bool CGDIPRenderDevice::SetClipRect(const int nX, const int nY, const int nWidth, const int nHeight)
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

bool CGDIPRenderDevice::GetClipRect(int & nX, int & nY, int & nWidth, int & nHeight)
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

IImage2D * CGDIPRenderDevice::CreateImageFromFileW(const wchar_t * pszFilePath)
{
	if (pszFilePath)
	{
		return CGDIPImage2D::MakeFromFileW(pszFilePath);
	}

	return 0;
}

IImage2D * CGDIPRenderDevice::CreateImageFromMemory(const void * pBuffer, const unsigned int uSize)
{
	if (pBuffer && uSize)
	{
		return CGDIPImage2D::MakeFromMemory(pBuffer, uSize);
	}

	return 0;
}

IFont2D * CGDIPRenderDevice::CreateFontW(const wchar_t * pszFaceName, const unsigned int uWidth, const unsigned int uHeight, const unsigned int uWeight, const bool bItalic)
{
	if (pszFaceName)
	{
		return CGDIPFont2D::MakeW(pszFaceName, uWidth, uHeight, uWeight, bItalic);
	}

	return 0;
}

bool CGDIPRenderDevice::RenderImage(IImage2D * pImage, const int nPosX, const int nPosY)
{
	bool bRet = false;

	if (m_pGraph && pImage)
	{
		auto pGDIPImage2D = dynamic_cast<CGDIPImage2D *>(pImage);
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

bool CGDIPRenderDevice::RenderImage(IImage2D * pImage, const int nDestPosX, const int nDestPosY, const int nDestWidth, const int nDestHeight, const int nSrcX, const int nSrcY, const int nSrcWidth, const int nSrcHeight)
{
	bool bRet = false;
	const Gdiplus::Rect rcDest(nDestPosX, nDestPosY, nDestWidth, nDestHeight);

	if (m_pGraph && pImage && nDestWidth && nDestHeight && nSrcWidth && nSrcHeight)
	{
		auto pGDIPImage2D = dynamic_cast<CGDIPImage2D *>(pImage);
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

bool CGDIPRenderDevice::RenderTextW(IFont2D * pFont, const wchar_t * pszText, const int nLen, const int nPosX, const int nPosY, const unsigned int uWidth, const unsigned int uHeight, const unsigned int uColor, const int nFormat)
{
	bool bRet = false;
	Gdiplus::RectF rcLayout((Gdiplus::REAL)nPosX, (Gdiplus::REAL)nPosY, (Gdiplus::REAL)uWidth, (Gdiplus::REAL)uHeight);
	Gdiplus::Color TextColor;

	if (m_pGraph && pFont && pszText && uWidth && uHeight)
	{
		auto pGDIPFont = dynamic_cast<CGDIPFont2D *>(pFont);
		if (pGDIPFont)
		{
			auto pStringFmt = ConvertTextFormat(nFormat);
			{
				TextColor.MakeARGB(ARGB::GetA(uColor), ARGB::GetR(uColor), ARGB::GetG(uColor), ARGB::GetB(uColor));

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

bool CGDIPRenderDevice::CalcTextSizeW(IFont2D * pFont, const wchar_t * pszText, const int nLen, const int nFormat, unsigned int & uWidth, unsigned int & uHeight)
{
	bool bRet = false;
	Gdiplus::PointF ptOrigin;
	Gdiplus::RectF rcText;

	if (m_pGraph && pFont && pszText)
	{
		auto pGDIPFont2D = dynamic_cast<CGDIPFont2D *>(pFont);
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

bool CGDIPRenderDevice::RenderLine(const int nX1, const int nY1, const int nX2, const int nY2, const unsigned int uColor)
{
	bool bRet = false;
	Gdiplus::Color LineColor;

	if (m_pGraph)
	{
		auto pPen = new Gdiplus::Pen(LineColor, 1);
		if (pPen)
		{
			LineColor.MakeARGB(ARGB::GetA(uColor), ARGB::GetR(uColor), ARGB::GetG(uColor), ARGB::GetB(uColor));

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

bool CGDIPRenderDevice::RenderQuad(const int nX, const int nY, const int nWidth, const int nHeight, const unsigned int uColor)
{
	bool bRet = false;
	Gdiplus::Color FillColor;
	const Gdiplus::Rect rcFill(nX, nY, nX + nWidth, nY + nHeight);

	if (m_pGraph && nWidth && nHeight)
	{
		FillColor.MakeARGB(ARGB::GetA(uColor), ARGB::GetR(uColor), ARGB::GetG(uColor), ARGB::GetB(uColor));

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

IMultiFrameImage2D * CGDIPRenderDevice::CreateMultiFrameImageFromFileW(const wchar_t * pszFile)
{
	return CGDIPMultiFrameImage2D::MakeFromFileW(pszFile);
}

IMultiFrameImage2D * CGDIPRenderDevice::CreateMultiFrameImageFromMemory(const void * pBuffer, const unsigned uSize)
{
	return CGDIPMultiFrameImage2D::MakeFromMemory(pBuffer, uSize);
}

bool CGDIPRenderDevice::RenderMultiFrameImage(IMultiFrameImage2D * pImage, const unsigned int uFrameIndex, const int nPosX, const int nPosY)
{
	bool bRet = false;

	if (m_pGraph && pImage)
	{
		auto pMultiFrameImage = dynamic_cast<CGDIPMultiFrameImage2D *>(pImage);
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

Gdiplus::StringFormat * CGDIPRenderDevice::ConvertTextFormat(const int nFormat) const
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
