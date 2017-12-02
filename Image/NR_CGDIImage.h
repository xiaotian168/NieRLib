
#pragma once

#include "NR_IImage.h"

#if defined NR_PLATFORM_WIN32

class NR_CGDIImage : public NR_IImage
{
public:

	friend class NR_CGDIRenderDevice;

	static NR_CGDIImage * MakeFromFileW(const wchar_t * pszFilePath);

	static NR_CGDIImage * MakeFromMemory(const void * pBuffer, const unsigned int uSize);

protected:

	NR_CGDIImage(const wchar_t * pszFilePath);

	NR_CGDIImage(const void * pBuffer, const unsigned int uSize);

	~NR_CGDIImage();

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
