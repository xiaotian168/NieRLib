
#pragma once

#include "IImage.h"

#if defined NIER_PLATFORM_WIN32

class CGDIImage : public IImage
{
public:

	friend class CGDIRenderDevice;

	static CGDIImage * MakeFromFileW(const wchar_t * pszFilePath);

protected:

	CGDIImage(const wchar_t * pszFilePath);

	~CGDIImage();

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
