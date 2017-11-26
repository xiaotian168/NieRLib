
#include "CGDIPRenderDevice.h"
#include "../Image/CGDIPImage2D.h"
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

IImage2D * CGDIPRenderDevice::CreateImageFromFileW(const wchar_t * pszFilePath)
{
	if (pszFilePath)
	{
		return CGDIPImage2D::MakeFromFileW(pszFilePath);
	}

	return 0;
}

IFont2D * CGDIPRenderDevice::CreateFontW(const wchar_t * pszFaceName, const unsigned int uWidth, const unsigned int uHeight, const unsigned int uWeight)
{
	if (pszFaceName)
	{
		return CGDIPFont2D::MakeW(pszFaceName, uWidth, uHeight, uWeight);
	}

	return 0;
}

bool CGDIPRenderDevice::RenderImage(IImage2D * pImage, const int nPosX, const int nPosY)
{
	bool bRet = false;

	if (m_pGraph && pImage)
	{
		auto pGDIPImage = dynamic_cast<CGDIPImage2D *>(pImage);
		if (pGDIPImage)
		{
			if (Gdiplus::Ok == m_pGraph->DrawImage(pGDIPImage->GetGDIPImage(), nPosX, nPosY))
			{
				bRet = true;
			}
		}
	}

	return bRet;
}

bool CGDIPRenderDevice::RenderTextW(IFont2D * pFont, const wchar_t * pszText, const int nLen, const int nPosX, const int nPosY, const unsigned int uWidth, const unsigned int uHeight, const unsigned int uColor, const int nFormat)
{
	bool bRet = false;
	Gdiplus::RectF rcLayout((Gdiplus::REAL)nPosX, (Gdiplus::REAL)nPosY, (Gdiplus::REAL)uWidth, (Gdiplus::REAL)uHeight);
	Gdiplus::ARGB TextColor(uColor);

	if (m_pGraph && pFont && pszText && uWidth && uHeight)
	{
		auto pGDIPFont = dynamic_cast<CGDIPFont2D *>(pFont);
		if (pGDIPFont)
		{
			auto pStringFmt = ConvertTextFormat(nFormat);
			{
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

bool CGDIPRenderDevice::RenderLine(const int nX1, const int nY1, const int nX2, const int nY2, const unsigned int uColor)
{
	bool bRet = false;
	Gdiplus::ARGB LineColor(uColor);

	if (m_pGraph)
	{
		auto pPen = new Gdiplus::Pen(LineColor, 1);
		if (pPen)
		{
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
