
#pragma once

#include "IImage2D.h"

#if defined NIER_PLATFORM_WIN32

class CGDIPImage2D : public IImage2D
{
public:

	friend class CGDIPRenderDevice;

	static CGDIPImage2D * MakeFromFileW(const wchar_t * pszImageFilePath);

	static CGDIPImage2D * MakeFromMemory(const void * pBuffer, const unsigned int uSize);

protected:

	CGDIPImage2D(const wchar_t * pszImageFilePath);

	CGDIPImage2D(const void * pBuffer, const unsigned int uSize);

	~CGDIPImage2D();

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
