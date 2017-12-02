
#pragma once

#include "NR_IImage.h"

#if defined NR_PLATFORM_WIN32

class NR_CGDIPImage : public NR_IImage
{
public:

	friend class NR_CGDIPRenderDevice;

	static NR_CGDIPImage * MakeFromFileW(const wchar_t * pszImageFilePath);

	static NR_CGDIPImage * MakeFromMemory(const void * pBuffer, const unsigned int uSize);

protected:

	NR_CGDIPImage(const wchar_t * pszImageFilePath);

	NR_CGDIPImage(const void * pBuffer, const unsigned int uSize);

	~NR_CGDIPImage();

public:

	bool GetImageSize(unsigned int & uWidth, unsigned int & uHeight) override;

private:

	inline Gdiplus::Bitmap * GetGDIPImage(void) const
	{
		return m_pImg;
	}

private:

	Gdiplus::Bitmap * m_pImg{ 0 };
};

#endif
