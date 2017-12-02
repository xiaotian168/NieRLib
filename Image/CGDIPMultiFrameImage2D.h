
#pragma once

#include "IMultiFrameImage2D.h"

#if defined NIER_PLATFORM_WIN32

class CGDIPMultiFrameImage2D : public IMultiFrameImage2D
{
private:

	struct stFrameInfo
	{
		unsigned int uFrameElapse{ 0 };
	};

public:

	friend class CGDIPRenderDevice;

	static CGDIPMultiFrameImage2D * MakeFromFileW(const wchar_t * pszImageFilePath);

	static CGDIPMultiFrameImage2D * MakeFromMemory(const void * pBuffer, const unsigned int uSize);

protected:

	CGDIPMultiFrameImage2D(const wchar_t * pszImageFilePath);

	CGDIPMultiFrameImage2D(const void * pBuffer, const unsigned int uSize);

	~CGDIPMultiFrameImage2D();

public:

	unsigned int GetFrameNum(void) override;

	bool GetFrameElapse(const unsigned int uFrameIndex, unsigned int & uElapse) override;

private:

	bool PrepareImageFrameInfo(void);

	inline Gdiplus::Bitmap * GetGDIPImage(void) const
	{
		return m_pImg;
	}

	inline GUID GetGUIDFirstDimension(void) const
	{
		return m_GUIDFirstDimension;
	}

private:

	Gdiplus::Bitmap * m_pImg{ 0 };
	GUID m_GUIDFirstDimension{ 0 };
	std::vector<stFrameInfo> m_FrameInfoList;
};

#endif
