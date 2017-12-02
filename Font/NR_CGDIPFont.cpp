
#include "NR_CGDIPFont.h"

#if defined NIER_PLATFORM_WIN32

NR_CGDIPFont * NR_CGDIPFont::MakeW(const wchar_t * pszFaceName, const unsigned int uWidth, const unsigned int uHeight, const unsigned int uWeight, const bool bItalic)
{
	return new NR_CGDIPFont(pszFaceName, uWidth, uHeight, uWeight, bItalic);
}

NR_CGDIPFont::NR_CGDIPFont(const wchar_t * pszFaceName, const unsigned int uWidth, const unsigned int uHeight, const unsigned int uWeight, const bool bItalic)
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

NR_CGDIPFont::~NR_CGDIPFont()
{
	if (m_pFont)
	{
		delete m_pFont;
		m_pFont = 0;
	}

	memset(&m_FontInfo, 0, sizeof(m_FontInfo));
}

bool NR_CGDIPFont::GetFontCreateParamW(NR_FONTCREATEPARAMW & FontInfo)
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
