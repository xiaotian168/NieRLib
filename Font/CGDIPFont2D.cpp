
#include "CGDIPFont2D.h"

#if defined NIER_PLATFORM_WIN32

CGDIPFont2D * CGDIPFont2D::MakeW(const wchar_t * pszFaceName, const unsigned int uWidth, const unsigned int uHeight, const unsigned int uWeight, const bool bItalic)
{
	return new CGDIPFont2D(pszFaceName, uWidth, uHeight, uWeight, bItalic);
}

CGDIPFont2D::CGDIPFont2D(const wchar_t * pszFaceName, const unsigned int uWidth, const unsigned int uHeight, const unsigned int uWeight, const bool bItalic)
{
	INT nFontStyle = 0;

	memset(&m_FontInfo, 0, sizeof(m_FontInfo));

	if (pszFaceName)
	{
		auto pFontFamily = new Gdiplus::FontFamily(pszFaceName);
		if (pFontFamily)
		{
			nFontStyle = (400 == uWeight ? Gdiplus::FontStyleRegular : Gdiplus::FontStyleBold);
			if (bItalic) nFontStyle |= Gdiplus::FontStyleItalic;

			m_pFont = new Gdiplus::Font(pFontFamily, (Gdiplus::REAL)uHeight, nFontStyle, Gdiplus::UnitPoint);
			if (m_pFont)
			{
				wcscpy_s(m_FontInfo.szFaceName, _countof(m_FontInfo.szFaceName), pszFaceName);
				m_FontInfo.uHeight = uHeight;
			}

			delete pFontFamily;
			pFontFamily = 0;
		}
	}
}

CGDIPFont2D::~CGDIPFont2D()
{
	if (m_pFont)
	{
		delete m_pFont;
		m_pFont = 0;
	}

	memset(&m_FontInfo, 0, sizeof(m_FontInfo));
}

bool CGDIPFont2D::GetFontInfoW(FONTINFOW & FontInfo)
{
	bool bRet = false;

	if (m_pFont)
	{
		FontInfo = m_FontInfo;

		bRet = true;
	}

	return bRet;
}

#endif
