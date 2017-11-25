
#include "CGDIRenderDevice.h"
#include "../Image/CGDIImage.h"
#include "../Font/CGDIFont.h"

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
		ReleaseDC(m_hWnd, m_hDC);
	}

	m_hWnd = 0;
	m_hDC = 0;
}

IImage * CGDIRenderDevice::CreateImageFromFileW(const wchar_t * pszFilePath)
{
	return CGDIImage::MakeFromFileW(pszFilePath);
}

IFont2D * CGDIRenderDevice::CreateFontW(const wchar_t * pszFaceName, const unsigned int uWidth, const unsigned int uHeight, const unsigned int uWeight)
{
	LOGFONTW LogFontW = { 0 };

	if (pszFaceName)
	{
		wcscpy_s(LogFontW.lfFaceName, _countof(LogFontW.lfFaceName), pszFaceName);
		LogFontW.lfWidth = uWidth;
		LogFontW.lfHeight = uHeight;
		LogFontW.lfWeight = uWeight;

		return CGDIFont::MakeW(LogFontW);
	}

	return 0;
}

bool CGDIRenderDevice::RenderImage(IImage * pImage, const int nPosX, const int nPosY)
{
	bool bRet = false;
	unsigned int uImageWidth = 0;
	unsigned int uImageHeight = 0;

	if (m_hDC && pImage)
	{
		auto pBmpImage = dynamic_cast<CGDIImage *>(pImage);
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

						if (BitBlt(m_hDC, nPosX, nPosY, uImageWidth, uImageHeight, hDCBmp, 0, 0, SRCCOPY))
						{
							bRet = true;
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

bool CGDIRenderDevice::RenderTextW(IFont2D * pFont, const wchar_t * pszText, const int nLen, const int nPosX, const int nPosY, const unsigned int uWidth, const unsigned int uHeight, const unsigned int uColor, const int nFormat)
{
	bool bRet = false;
	RECT rcText = { nPosX, nPosY, nPosX + uWidth, nPosY + uHeight };

	if (m_hDC && pFont && pszText && uWidth && uHeight)
	{
		auto pGDIFont = dynamic_cast<CGDIFont *>(pFont);
		if (pGDIFont)
		{
			const auto hFont = pGDIFont->GetGDIFontHandle();
			if (hFont)
			{
				auto hFontOld = SelectObject(m_hDC, hFont);
				{
					const auto dwColorOld = GetTextColor(m_hDC);
					{
						SetTextColor(m_hDC, uColor);

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

int CGDIRenderDevice::ConvertTextFormat(const int nFormat) const
{
	int nFmt = 0;

	if (nFormat & eTextFmt_Left) nFmt |= DT_LEFT;
	if (nFormat & eTextFmt_Right) nFmt |= DT_RIGHT;
	if (nFormat & eTextFmt_Top) nFmt |= DT_TOP;
	if (nFormat & eTextFmt_Bottom) nFmt |= DT_BOTTOM;
	if (nFormat & eTextFmt_HCenter) nFmt |= DT_CENTER;
	if (nFormat & eTextFmt_VCenter) nFmt |= DT_VCENTER;
	if (nFormat & eTextFmt_SingleLine) nFmt |= DT_SINGLELINE;
	if (nFormat & eTextFmt_PathEllipsis) nFmt |= DT_PATH_ELLIPSIS;
	if (nFormat & eTextFmt_WordEllipsis) nFmt |= DT_WORD_ELLIPSIS;
	if (nFormat & eTextFmt_WordBreak) nFmt |= DT_WORDBREAK;

	return nFmt;
}

#endif
