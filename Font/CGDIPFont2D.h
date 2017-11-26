
#pragma once

#include "IFont2D.h"

#if defined NIER_PLATFORM_WIN32

class CGDIPFont2D : public IFont2D
{
public:

	friend class CGDIPRenderDevice;

	static CGDIPFont2D * MakeW(const wchar_t * pszFaceName, const unsigned int uWidth, const unsigned int uHeight, const unsigned int uWeight);

protected:

	CGDIPFont2D(const wchar_t * pszFaceName, const unsigned int uWidth, const unsigned int uHeight, const unsigned int uWeight);

	~CGDIPFont2D();

public:

	bool GetFontInfoW(FONTINFOW & FontInfo) override;

private:

	inline Gdiplus::Font * GetGDIPFont(void) const
	{
		return m_pFont;
	}

private:

	Gdiplus::Font * m_pFont{ 0 };
	FONTINFOW m_FontInfo;
};

#endif