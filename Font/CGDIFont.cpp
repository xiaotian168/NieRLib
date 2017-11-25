
#include "CGDIFont.h"

#if defined NIER_PLATFORM_WIN32

CGDIFont * CGDIFont::MakeW(const LOGFONTW & LogFont)
{
	return new CGDIFont(LogFont);
}

CGDIFont::CGDIFont(const LOGFONTW & LogFont)
{
	memset(&m_LogFont, 0, sizeof(m_LogFont));

	m_hFont = CreateFontIndirectW(&LogFont);
	if (m_hFont)
	{
		m_LogFont = LogFont;
	}
}

CGDIFont::~CGDIFont()
{
	if (m_hFont)
	{
		DeleteObject(m_hFont);
		m_hFont = 0;
	}

	memset(&m_LogFont, 0, sizeof(m_LogFont));
}

bool CGDIFont::GetFontInfoW(FONTINFOW & FontInfo)
{
	bool bRet = false;

	if (m_hFont)
	{
		wcscpy_s(FontInfo.szFaceName, _countof(FontInfo.szFaceName), m_LogFont.lfFaceName);
		FontInfo.uWidth = m_LogFont.lfWidth;
		FontInfo.uHeight = m_LogFont.lfHeight;
		FontInfo.uWeight = m_LogFont.lfWeight;

		bRet = true;
	}

	return bRet;
}

#endif