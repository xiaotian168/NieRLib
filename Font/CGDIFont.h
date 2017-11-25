
#pragma once

#include "IFont2D.h"

#if defined NIER_PLATFORM_WIN32

class CGDIFont : public IFont2D
{
public:

	friend class CGDIRenderDevice;

	static CGDIFont * MakeW(const LOGFONTW & LogFont);

protected:

	CGDIFont(const LOGFONTW & LogFont);

	~CGDIFont();

public:

	bool GetFontInfoW(FONTINFOW & FontInfo) override;

private:

	inline HFONT GetGDIFontHandle(void) const
	{
		return m_hFont;
	}

private:

	HFONT m_hFont{ 0 };
	LOGFONTW m_LogFont;
};

#endif
