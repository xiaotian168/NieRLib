
#include "NR_CGDIFont.h"

#if defined NR_PLATFORM_WIN32

NR_CGDIFont * NR_CGDIFont::MakeW(const LOGFONTW & LogFont)
{
	return new NR_CGDIFont(LogFont);
}

NR_CGDIFont::NR_CGDIFont(const LOGFONTW & LogFont)
{
	memset(&m_LogFont, 0, sizeof(m_LogFont));

	m_hFont = CreateFontIndirectW(&LogFont);
	if (m_hFont)
	{
		m_LogFont = LogFont;
	}
}

NR_CGDIFont::~NR_CGDIFont()
{
	if (m_hFont)
	{
		DeleteObject(m_hFont);
		m_hFont = 0;
	}

	memset(&m_LogFont, 0, sizeof(m_LogFont));
}

bool NR_CGDIFont::GetFontCreateParamW(NR_FONTCREATEPARAMW & FontInfo)
{
	bool bRet = false;

	if (m_hFont)
	{
		wcscpy_s(FontInfo.szFaceName, _countof(FontInfo.szFaceName), m_LogFont.lfFaceName);
		FontInfo.uWidth = m_LogFont.lfWidth;
		FontInfo.uHeight = m_LogFont.lfHeight;
		FontInfo.uWeight = m_LogFont.lfWeight;
		FontInfo.bItalic = m_LogFont.lfItalic ? true : false;

		bRet = true;
	}

	return bRet;
}

#endif
