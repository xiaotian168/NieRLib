
#pragma once

#include "NR_IFont.h"

#if defined NR_PLATFORM_WIN32

class NR_CGDIFont : public NR_IFont
{
public:

	friend class NR_CGDIRenderDevice;

	static NR_CGDIFont * MakeW(const LOGFONTW & LogFont);

protected:

	NR_CGDIFont(const LOGFONTW & LogFont);

	~NR_CGDIFont();

public:

	bool GetFontCreateParamW(NR_FONTCREATEPARAMW & FontInfo) override;

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
