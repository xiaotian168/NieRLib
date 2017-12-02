
#pragma once

#include "NR_IFont.h"

#if defined NIER_PLATFORM_WIN32

class NR_CGDIPFont : public NR_IFont
{
public:

	friend class NR_CGDIPRenderDevice;

	static NR_CGDIPFont * MakeW(const wchar_t * pszFaceName, const unsigned int uWidth, const unsigned int uHeight, const unsigned int uWeight, const bool bItalic);

protected:

	NR_CGDIPFont(const wchar_t * pszFaceName, const unsigned int uWidth, const unsigned int uHeight, const unsigned int uWeight, const bool bItalic);

	~NR_CGDIPFont();

public:

	bool GetFontCreateParamW(NR_FONTCREATEPARAMW & FontInfo) override;

private:

	inline Gdiplus::Font * GetGDIPFont(void) const
	{
		return m_pFont;
	}

private:

	Gdiplus::Font * m_pFont{ 0 };
	NR_FONTCREATEPARAMW m_FontInfo;
};

#endif
