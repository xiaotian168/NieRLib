
#include "CGDIPFont.h"

#if defined NIER_PLATFORM_WIN32

CGDIPFont * CGDIPFont::Make(void)
{
	return new CGDIPFont();
}

CGDIPFont::CGDIPFont()
{
	memset(&m_FontInfo, 0, sizeof(m_FontInfo));
}

CGDIPFont::~CGDIPFont()
{
	memset(&m_FontInfo, 0, sizeof(m_FontInfo));
}

bool CGDIPFont::GetFontInfoW(FONTINFOW & FontInfo)
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
