
#include "CGDIRenderDevice.h"
#include "ARGB.h"
#include "../Image/CGDIImage2D.h"
#include "../Font/CGDIFont2D.h"

#if defined NIER_PLATFORM_WIN32

CGDIRenderDevice * CGDIRenderDevice::Make(const HDC hDC)
{
	return new CGDIRenderDevice(hDC);
}

CGDIRenderDevice * CGDIRenderDevice::Make(const HWND hWnd)
{
	return new CGDIRenderDevice(hWnd);
}

CGDIRenderDevice::CGDIRenderDevice(const HDC hDC)
{
	m_hDC = hDC;
}

CGDIRenderDevice::CGDIRenderDevice(const HWND hWnd)
{
	if (IsWindow(hWnd))
	{
		m_hDC = GetDC(hWnd);
		if (m_hDC)
		{
			m_hWnd = hWnd;
		}
	}
}

CGDIRenderDevice::~CGDIRenderDevice()
{
	if (m_hWnd && m_hDC)
	{
		if (IsWindow(m_hWnd))
		{
			ReleaseDC(m_hWnd, m_hDC);
		}
	}

	m_hWnd = 0;
	m_hDC = 0;
}

IImage2D * CGDIRenderDevice::CreateImageFromFileW(const wchar_t * pszFilePath)
{
	return CGDIImage2D::MakeFromFileW(pszFilePath);
}

IImage2D * CGDIRenderDevice::CreateImageFromMemory(const void * pBuffer, const unsigned int uSize)
{
	if (pBuffer && uSize)
	{
		return CGDIImage2D::MakeFromMemory(pBuffer, uSize);
	}

	return 0;
}

IFont2D * CGDIRenderDevice::CreateFontW(const wchar_t * pszFaceName, const unsigned int uWidth, const unsigned int uHeight, const unsigned int uWeight, const bool bItalic)
{
	LOGFONTW LogFontW = { 0 };

	if (pszFaceName)
	{
		wcscpy_s(LogFontW.lfFaceName, _countof(LogFontW.lfFaceName), pszFaceName);
		LogFontW.lfWidth = uWidth;
		LogFontW.lfHeight = uHeight;
		LogFontW.lfWeight = uWeight;
		LogFontW.lfItalic = bItalic ? TRUE : FALSE;

		return CGDIFont2D::MakeW(LogFontW);
	}

	return 0;
}

bool CGDIRenderDevice::RenderImage(IImage2D * pImage, const int nPosX, const int nPosY)
{
	bool bRet = false;
	unsigned int uImageWidth = 0;
	unsigned int uImageHeight = 0;

	if (m_hDC && pImage)
	{
		auto pBmpImage = dynamic_cast<CGDIImage2D *>(pImage);
		if (pBmpImage)
		{
			const auto hBmp = pBmpImage->GetBitmapHandle();
			if (hBmp)
			{
				auto hDCBmp = CreateCompatibleDC(m_hDC);
				if (hDCBmp)
				{
					if (pImage->GetImageSize(uImageWidth, uImageHeight))
					{
						auto hBmpOld = SelectObject(hDCBmp, hBmp);
						{
							if (BitBlt(m_hDC, nPosX, nPosY, uImageWidth, uImageHeight, hDCBmp, 0, 0, SRCCOPY))
							{
								bRet = true;
							}
						}
						SelectObject(hDCBmp, hBmpOld);
					}

					DeleteDC(hDCBmp);
					hDCBmp = 0;
				}
			}
		}
	}

	return bRet;
}

bool CGDIRenderDevice::RenderImage(IImage2D * pImage, const int nDestPosX, const int nDestPosY, const int nDestWidth, const int nDestHeight, const int nSrcX, const int nSrcY, const int nSrcWidth, const int nSrcHeight)
{
	bool bRet = false;

	if (m_hDC && pImage && nDestWidth && nDestHeight && nSrcWidth && nSrcHeight)
	{
		auto pBmpImage = dynamic_cast<CGDIImage2D *>(pImage);
		if (pBmpImage)
		{
			const auto hBmp = pBmpImage->GetBitmapHandle();
			if (hBmp)
			{
				auto hDCBmp = CreateCompatibleDC(m_hDC);
				if (hDCBmp)
				{
					auto hBmpOld = SelectObject(hDCBmp, hBmp);
					{
						if (StretchBlt(m_hDC, nDestPosX, nDestPosY, nDestWidth, nDestHeight, hDCBmp, nSrcX, nSrcY, nSrcWidth, nSrcHeight, SRCCOPY))
						{
							bRet = true;
						}
					}
					SelectObject(hDCBmp, hBmpOld);

					DeleteDC(hDCBmp);
					hDCBmp = 0;
				}
			}
		}
	}

	return bRet;
}

bool CGDIRenderDevice::RenderTextW(IFont2D * pFont, const wchar_t * pszText, const int nLen, const int nPosX, const int nPosY, const unsigned int uWidth, const unsigned int uHeight, const unsigned int uColor, const int nFormat)
{
	bool bRet = false;
	RECT rcText = { (LONG)nPosX, (LONG)nPosY, (LONG)nPosX + (LONG)uWidth, (LONG)nPosY + (LONG)uHeight };
	const COLORREF TextColor = RGB(ARGB::GetR(uColor), ARGB::GetG(uColor), ARGB::GetB(uColor));

	if (m_hDC && pFont && pszText && uWidth && uHeight)
	{
		auto pGDIFont = dynamic_cast<CGDIFont2D *>(pFont);
		if (pGDIFont)
		{
			const auto hFont = pGDIFont->GetGDIFontHandle();
			if (hFont)
			{
				auto hFontOld = SelectObject(m_hDC, hFont);
				{
					const auto dwColorOld = GetTextColor(m_hDC);
					{
						SetTextColor(m_hDC, TextColor);

						const auto BKModeOld = GetBkMode(m_hDC);
						{
							SetBkMode(m_hDC, TRANSPARENT);

							if (DrawTextW(m_hDC, pszText, nLen, &rcText, ConvertTextFormat(nFormat)))
							{
								bRet = true;
							}
						}
						SetBkMode(m_hDC, BKModeOld);
					}
					SetTextColor(m_hDC, dwColorOld);
				}
				SelectObject(m_hDC, hFontOld);
			}
		}
	}

	return bRet;
}

bool CGDIRenderDevice::CalcTextSizeW(IFont2D * pFont, const wchar_t * pszText, const int nLen, const int nFormat, unsigned int & uWidth, unsigned int & uHeight)
{
	bool bRet = false;
	RECT rcText = { 0 };

	if (m_hDC && pFont && pszText)
	{
		auto pGDIFont = dynamic_cast<CGDIFont2D *>(pFont);
		if (pGDIFont)
		{
			const auto hFont = pGDIFont->GetGDIFontHandle();
			if (hFont)
			{
				if (DrawTextW(m_hDC, pszText, nLen, &rcText, ConvertTextFormat(nFormat) | DT_CALCRECT))
				{
					uWidth = rcText.right - rcText.left;
					uHeight = rcText.bottom - rcText.top;

					bRet = true;
				}
			}
		}
	}

	return bRet;
}

bool CGDIRenderDevice::RenderLine(const int nX1, const int nY1, const int nX2, const int nY2, const unsigned int uColor)
{
	bool bRet = false;
	POINT PosOld = { 0 };
	const COLORREF LineColor = RGB(ARGB::GetR(uColor), ARGB::GetG(uColor), ARGB::GetB(uColor));

	if (m_hDC)
	{
		if (MoveToEx(m_hDC, nX1, nX2, &PosOld))
		{
			auto hPen = CreatePen(PS_SOLID, 1, LineColor);
			if (hPen)
			{
				auto hPenOld = SelectObject(m_hDC, hPen);
				{
					if (LineTo(m_hDC, nX2, nY2))
					{
						bRet = true;
					}
				}
				SelectObject(m_hDC, hPenOld);
			}

			MoveToEx(m_hDC, PosOld.x, PosOld.y, 0);
		}
	}

	return bRet;
}

bool CGDIRenderDevice::RenderQuad(const int nX, const int nY, const int nWidth, const int nHeight, const unsigned int uColor)
{
	bool bRet = false;
	const RECT rcFill = { nX, nY, nX + nWidth, nY + nHeight };
	const COLORREF FillColor = RGB(ARGB::GetR(uColor), ARGB::GetG(uColor), ARGB::GetB(uColor));

	if (m_hDC && nWidth && nHeight)
	{
		auto hBrush = CreateSolidBrush(FillColor);
		if (hBrush)
		{
			if (FillRect(m_hDC, &rcFill, hBrush))
			{
				bRet = true;
			}

			DeleteObject(hBrush);
			hBrush = 0;
		}
	}

	return bRet;
}

int CGDIRenderDevice::ConvertTextFormat(const int nFormat) const
{
	int nFmt = 0;

	if (nFormat & eTextFmt_Left) nFmt |= DT_LEFT;
	else if (nFormat & eTextFmt_Right) nFmt |= DT_RIGHT;
	else if (nFormat & eTextFmt_HCenter) nFmt |= DT_CENTER;

	if (nFormat & eTextFmt_Top) nFmt |= DT_TOP;
	else if (nFormat & eTextFmt_Bottom) nFmt |= DT_BOTTOM;
	else if (nFormat & eTextFmt_VCenter) nFmt |= DT_VCENTER;

	if (nFormat & eTextFmt_SingleLine) nFmt |= DT_SINGLELINE;

	if (nFormat & eTextFmt_PathEllipsis) nFmt |= DT_PATH_ELLIPSIS;
	else if (nFormat & eTextFmt_WordEllipsis) nFmt |= DT_WORD_ELLIPSIS;

	if (nFormat & eTextFmt_WordBreak) nFmt |= DT_WORDBREAK;

	return nFmt;
}

#endif
