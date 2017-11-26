
#pragma once

#include "IImage2D.h"

#if defined NIER_PLATFORM_WIN32

class CGDIImage2D : public IImage2D
{
public:

	friend class CGDIRenderDevice;

	static CGDIImage2D * MakeFromFileW(const wchar_t * pszFilePath);

protected:

	CGDIImage2D(const wchar_t * pszFilePath);

	~CGDIImage2D();

public:

	bool GetImageSize(unsigned int & uWidth, unsigned int & uHeight) override;

private:

	inline HBITMAP GetBitmapHandle(void) const
	{
		return m_hBmp;
	}

private:

	HBITMAP m_hBmp{ 0 };
	unsigned int m_uWidth{ 0 };
	unsigned int m_uHeight{ 0 };
};

#endif
