
#include "CGDIFont2D.h"

#if defined NIER_PLATFORM_WIN32

CGDIFont2D * CGDIFont2D::MakeW(const LOGFONTW & LogFont)
{
	return new CGDIFont2D(LogFont);
}

CGDIFont2D::CGDIFont2D(const LOGFONTW & LogFont)
{
	memset(&m_LogFont, 0, sizeof(m_LogFont));

	m_hFont = CreateFontIndirectW(&LogFont);
	if (m_hFont)
	{
		m_LogFont = LogFont;
	}
}

CGDIFont2D::~CGDIFont2D()
{
	if (m_hFont)
	{
		DeleteObject(m_hFont);
		m_hFont = 0;
	}

	memset(&m_LogFont, 0, sizeof(m_LogFont));
}

bool CGDIFont2D::GetFontInfoW(FONTINFOW & FontInfo)
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
