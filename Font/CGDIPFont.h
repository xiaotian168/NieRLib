
#pragma once

#include "IFont2D.h"

#if defined NIER_PLATFORM_WIN32

class CGDIPFont : public IFont2D
{
public:

	friend class CGDIPRenderDevice;

	static CGDIPFont * Make(void);

protected:

	CGDIPFont();

	~CGDIPFont();

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
