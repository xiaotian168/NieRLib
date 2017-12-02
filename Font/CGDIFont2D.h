
#pragma once

#include "IFont2D.h"

#if defined NIER_PLATFORM_WIN32

class CGDIFont2D : public IFont2D
{
public:

	friend class CGDIRenderDevice;

	static CGDIFont2D * MakeW(const LOGFONTW & LogFont);

protected:

	CGDIFont2D(const LOGFONTW & LogFont);

	~CGDIFont2D();

public:

	bool GetFontCreateParamW(FONTCREATEPARAMW & FontInfo) override;

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
